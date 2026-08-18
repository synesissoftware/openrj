/* /////////////////////////////////////////////////////////////////////////
 * File:    example_c_4.c
 *
 * Purpose: C example program for the Open-RJ core library. Demonstrates
 *          handling of parsing errors.
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
    "           Shepherd"       /* The error is here (the \n has been removed) */
    "%%\n"
    "Name:      Sparky\n"
    "Species:   Cat\n"
    "%%\n";

/* ////////////////////////////////////////////////////////////////////// */

int main(void)
{
    unsigned            flags       =   0; /* Could try ORJ_FLAG_ORDERFIELDS and/or ORJ_FLAG_ELIDEBLANKRECORDS */
    ORJDatabase const   *db;
    ORJError            error;
    ORJRC               rc;

    /* 1. Create a database instance on memory, so use memory_database */
    rc = ORJ_CreateDatabaseFromMemory(contents, sizeof(contents), NULL, flags, &db, &error);

    if(0 != rc)
    {
        char    message[1001];

        fprintf(stdout, "Display the error manually:\n");
        fprintf(stderr, "  Error at line %ld, column %ld: %s\n", (long)error.invalidLine, (long)error.invalidColumn, ORJ_GetErrorStringA(rc));

        fprintf(stdout, "Display the error using ORJ_FormatErrorA():\n");
        ORJ_FormatErrorA(&message[0], sizeof(message) / sizeof(0[message]), rc, &error, "  Error code %d means: %E\n", (int)rc);
        fprintf(stderr, "%s", message);

        return EXIT_FAILURE;
    }
    else
    {
        /* Finally, free the database */
        ORJ_FreeDatabase(db);
    }

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

