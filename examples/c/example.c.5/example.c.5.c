/* /////////////////////////////////////////////////////////////////////////
 * File:    example_c_5.c
 *
 * Purpose: C example program for the Open-RJ core library. Demonstrates
 *          handling of a "failure to open file" error.
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

/* ////////////////////////////////////////////////////////////////////// */

int main(void)
{
    unsigned            flags   =   0;
    ORJDatabase const   *db;
    ORJError            error;
    ORJRC               rc;

    /* 1. Create a database instance on memory, so use memory_database */
    rc = ORJ_ReadDatabase("|i|n|v|a|l|i|d|n|a|m|e|", NULL, flags, &db, &error);

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

