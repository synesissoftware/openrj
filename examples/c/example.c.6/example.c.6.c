/* /////////////////////////////////////////////////////////////////////////
 * File:    example_c_6.c
 *
 * Purpose: C example program for the Open-RJ core library. Demonstrates
 *          processing of all database fields via API functions.
 *
 * Created: 12th May 2006
 * Updated: 23rd August 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Open-RJ Header Files */
#include <openrj/openrj.h>

/* Standard C Library Files */
#include <assert.h>
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
    unsigned            flags   =   0;
    ORJDatabase const   *db;
    ORJError            error;
    ORJRC               rc;

    /* 1. Create a database instance on memory */
    rc = ORJ_CreateDatabaseFromMemory(contents, sizeof(contents), NULL, flags, &db, &error);

    if(0 != rc)
    {
        printf("Error at line %ld, column %ld: %s\n", (long)error.invalidLine, (long)error.invalidColumn, ORJ_GetErrorStringA(rc));

        return EXIT_FAILURE;
    }
    else
    {
        size_t  i;

        printf("Enumerating all fields in the database:\n");

        for(i = 0; i < db->numFields; ++i)
        {
            ORJField const  *field;

            rc = ORJ_Database_GetFieldA(db, i, &field);

            /* Asserting on a runtime condition is an absolute no-no. In this case it
             * is legitimate because we're working on a memory database whose contents
             * are fixed.
             */
            assert(ORJ_RC_SUCCESS == rc);

            printf("  %.*s=%.*s\n", (int)field->name.len, field->name.ptr, (int)field->value.len, field->value.ptr);
        }

        /* Free the database */
        ORJ_FreeDatabase(db);
    }

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

