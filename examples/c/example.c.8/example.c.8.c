/* /////////////////////////////////////////////////////////////////////////
 * File:    example_c_8.c
 *
 * Purpose: C example program for the Open-RJ core library. Demonstrates use
 *          of processing instructions for field-name aliases.
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
    "_OpenRJ.Field.Alias:   1:Name\n"
    "_OpenRJ.Field.Alias:   2:Species\n"
    "_OpenRJ.Field.Alias:   3:Breed\n"
    "%%\n"
    "1:  Barney\n"
    "2:  Dog\n"
    "3:  Bijon \\\n"
    "    Frieze\n"
    "%%\n"
    "1:  Elsa\n"
    "2:  Dog\n"
    "3:  Mixed\n"
    "%%\n"
    "1:  Fluffy Kitten\n"
    "2:  Cat\n"
    "%%\n"
    "1:  Moet\n"
    "2:  Dog\n"
    "3:  Boxer\n"
    "%%\n"
    "1:  Rebel\n"
    "2:  Dog\n"
    "3:  German \\\n"
    "    Shepherd\n"
    "%%\n"
    "1:  Sparky\n"
    "2:  Cat\n"
    "%%\n";

/* ////////////////////////////////////////////////////////////////////// */

int main(void)
{
    unsigned            flags   =   ORJ_FLAG_ELIDEBLANKRECORDS;
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
            ,   (long)db->numLines
            ,   (long)db->numFields
            ,   (long)db->numRecords);

        printf("Enumerating all fields in the database:\n");

        for(iRecord = 0; iRecord < db->numRecords; ++iRecord)
        {
            size_t              iField;
            ORJRecordA const    *record;
            ORJStringA const    *comment;

            record  =   &db->records[iRecord];
            comment =   &record->comment;

            if(0 != comment->len)
            {
                printf("record-#%ld; %.*s (%ld fields)\n", (long)iRecord, (int)comment->len, comment->ptr, (long)record->numFields);
            }
            else
            {
                printf("record-#%ld (%ld fields)\n", (long)iRecord, (long)record->numFields);
            }

            for(iField = 0; iField < record->numFields; ++iField)
            {
                ORJFieldA const     *field;
                ORJStringA const    *name;
                ORJStringA const    *value;

                field   =   &record->fields[iField];
                name    =   &field->name;
                value   =   &field->value;

                printf("  field-#%ld %.*s=%.*s\n", (long)iField, (int)name->len, name->ptr, (int)value->len, value->ptr);
            }
        }

        /* Finally, free the database */
        ORJ_FreeDatabase(db);
    }

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

