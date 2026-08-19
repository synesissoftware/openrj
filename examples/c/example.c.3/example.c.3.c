/* /////////////////////////////////////////////////////////////////////////
 * File:    example_c_3.c
 *
 * Purpose: C example program for the Open-RJ core library. Demonstrates
 *          searching for fields in records.
 *
 * Created: 12th May 2006
 * Updated: 23rd August 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Open-RJ Header Files */
#include <openrj/openrj.h>

/* Standard C Library Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Sample database */
static const char   contents[] =

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
    "%%\n";

/* ////////////////////////////////////////////////////////////////////// */

int main(void)
{
    unsigned            flags   =   ORJ_FLAG_ELIDEBLANKRECORDS | ORJ_FLAG_IGNORECASEONLOOKUP;
    ORJDatabase const   *db;
    ORJError            error;
    ORJRC               rc;

    /* 1. Create a database instance on memory, so use memory_database */
    rc = ORJ_CreateDatabaseFromMemory(contents, sizeof(contents), NULL, flags, &db, &error);

    if(0 != rc)
    {
        printf("Error at line %ld, column %ld: %s\n", (long)error.invalidLine, (long)error.invalidColumn, ORJ_GetErrorStringA(rc));

        return EXIT_FAILURE;
    }
    else
    {
        size_t  iRecord;

        printf( "Database has %ld lines in %ld fields in %ld records\n"
            ,   (long)ORJ_Database_GetNumLinesA(db)
            ,   (long)ORJ_Database_GetNumFieldsA(db)
            ,   (long)ORJ_Database_GetNumRecordsA(db));

        printf("Enumerating all records in the database, and displaying the \"Breed\" fields:\n");

        for(iRecord = 0; iRecord < ORJ_Database_GetNumRecordsA(db); ++iRecord)
        {
            ORJRecordA const    *record;
            ORJFieldA const     *breed;

            ORJ_Database_GetRecordA(db, iRecord, &record);

            breed   =   ORJ_Record_FindFieldByNameA(record, "BREED", NULL);

            if(NULL == breed)
            {
                printf("record does not contain a field called \"Breed\"\n");
            }
            else
            {
                ORJFieldA const     *name       =   ORJ_Record_FindFieldByNameA(record, "NAME", NULL);
                ORJFieldA const     *species    =   ORJ_Record_FindFieldByNameA(record, "SPECIES", NULL);
                ORJStringA const    *comment;

                ORJ_Record_GetCommentA(record, &comment);

                printf("record-#%ld; %.*s (%ld fields)\n", (long)iRecord, (int)comment->len, comment->ptr, (long)ORJ_Record_GetNumFieldsA(record));
                printf("  %.*s=%.*s\n", (int)name->name.len, name->name.ptr, (int)name->value.len, name->value.ptr);
                printf("  %.*s=%.*s\n", (int)species->name.len, species->name.ptr, (int)species->value.len, species->value.ptr);
                printf("  %.*s=%.*s\n", (int)breed->name.len, breed->name.ptr, (int)breed->value.len, breed->value.ptr);
            }
        }

        /* Finally, free the database */
        ORJ_FreeDatabase(db);
    }

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

