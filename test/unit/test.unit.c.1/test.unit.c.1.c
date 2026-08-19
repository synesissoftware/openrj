/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.c.1.c
 *
 * Purpose: Unit-tests for the Open-RJ C API (memory databases and parse
 *          errors).
 *
 * Created: 14th August 2026
 * Updated: 23rd August 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <openrj/openrj.h>

#include <xtests/xtests.h>

#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_create_from_memory_counts(void);
static void test_invalid_field_name_parse_error(void);
static void test_elide_blank_records(void);
static void test_field_lookup_by_name(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.c.1", verbosity))
    {
        XTESTS_RUN_CASE(test_create_from_memory_counts);
        XTESTS_RUN_CASE(test_invalid_field_name_parse_error);
        XTESTS_RUN_CASE(test_elide_blank_records);
        XTESTS_RUN_CASE(test_field_lookup_by_name);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_create_from_memory_counts(void)
{
    static char const contents[] =
        "%% Sample Open-RJ database - Cats and Dogs\n"
        "%% Created:   28th September 2004\n"
        "%% Updated:   29th September 2004\n"
        "Name:      Barney\n"
        "Species:   Dog\n"
        "Breed:     Bijon \\\n"
        "           Frieze\n"
        "%%\n"
        "Name:      Elsa\n"
        "Species:   Dog\n"
        "Breed:     Mixed\n"
        "%%\n"
        "Name:      Fluffy Kitten\n"
        "Species:   Cat\n"
        "%%\n"
        "Name:      Moet\n"
        "Species:   Dog\n"
        "Breed:     Boxer\n"
        "%%\n"
        "Name:      Rebel\n"
        "Species:   Dog\n"
        "Breed:     German \\\n"
        "           Shepherd\n"
        "%%\n"
        "Name:      Sparky\n"
        "Species:   Cat\n"
        "%%\n"
        ;

    ORJDatabase const* database = NULL;
    ORJError error;
    ORJRC const rc = ORJ_CreateDatabaseFromMemoryA(
        &contents[0],
        sizeof(contents),
        NULL,
        0,
        &database,
        &error
    );

    XTESTS_TEST_ENUM_EQUAL(ORJ_RC_SUCCESS, rc);
    XTESTS_REQUIRE(NULL != database);
    XTESTS_TEST_INTEGER_EQUAL(9u, ORJ_Database_GetNumRecordsA(database));
    XTESTS_TEST_INTEGER_EQUAL(16u, ORJ_Database_GetNumFieldsA(database));

    ORJ_FreeDatabaseA(database);
}

static void test_invalid_field_name_parse_error(void)
{
    static char const contents[] =
        "%% Sample Open-RJ database - Cats and Dogs\n"
        "%% Created:   28th September 2004\n"
        "%% Updated:   29th September 2004\n"
        "Name:      Barney\n"
        "Species:   Dog\n"
        "Breed:     Bijon \\\n"
        "           Frieze\n"
        "%%\n"
        "  : \n"
        "Species:   Cat\n"
        "    :\n"
        "    : \n"
        "%%\n"
        "Name:      Moet\n"
        "Species:   Dog\n"
        "Breed:     Boxer\n"
        "%%\n"
        ;

    ORJDatabase const* database = NULL;
    ORJError error;
    ORJRC const rc = ORJ_CreateDatabaseFromMemoryA(
        &contents[0],
        sizeof(contents),
        NULL,
        0,
        &database,
        &error
    );

    XTESTS_TEST_ENUM_EQUAL(ORJ_RC_PARSEERROR, rc);
    XTESTS_TEST_ENUM_EQUAL(ORJ_PARSE_INVALIDFIELDNAME, error.parseError);
    XTESTS_TEST_INTEGER_EQUAL(8u, error.invalidLine);
}

static void test_elide_blank_records(void)
{
    static char const contents[] =
        "Name: A\n"
        "%%\n"
        "%%\n"
        "Name: B\n"
        "%%\n"
        ;

    ORJDatabase const* database = NULL;
    ORJError error;
    ORJRC const rc = ORJ_CreateDatabaseFromMemoryA(
        &contents[0],
        sizeof(contents),
        NULL,
        ORJ_FLAG_ELIDEBLANKRECORDS,
        &database,
        &error
    );

    XTESTS_TEST_ENUM_EQUAL(ORJ_RC_SUCCESS, rc);
    XTESTS_REQUIRE(NULL != database);
    XTESTS_TEST_INTEGER_EQUAL(2u, ORJ_Database_GetNumRecordsA(database));

    ORJ_FreeDatabaseA(database);
}

static void test_field_lookup_by_name(void)
{
    static char const contents[] =
        "Name: Barney\n"
        "Species: Dog\n"
        "%%\n"
        ;

    ORJDatabase const* database = NULL;
    ORJError error;
    ORJRecordA const* record = NULL;
    ORJFieldA const* field = NULL;
    ORJRC const rc = ORJ_CreateDatabaseFromMemoryA(
        &contents[0],
        sizeof(contents),
        NULL,
        ORJ_FLAG_ELIDEBLANKRECORDS,
        &database,
        &error
    );

    XTESTS_TEST_ENUM_EQUAL(ORJ_RC_SUCCESS, rc);
    XTESTS_REQUIRE(NULL != database);

    ORJ_Database_GetRecordA(database, 0, &record);
    XTESTS_REQUIRE(NULL != record);

    field = ORJ_Record_FindFieldByNameA(record, "Species", NULL);
    XTESTS_REQUIRE(NULL != field);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("Dog", field->value.ptr, field->value.len);

    ORJ_FreeDatabaseA(database);
}


/* ///////////////////////////// end of file //////////////////////////// */
