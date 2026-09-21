/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/versions/main.c
 *
 * Purpose: Prints openrj composite version.
 *
 * Created: 17th September 2026
 * Updated: 17th September 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <openrj/openrj.h>

#include <stdio.h>
#include <stdlib.h>


#define PROGRAM_NAME                                        "versions"


static void
version(
    FILE*       stm
,   char const* prefix
,   char const* libname
,   char const* macroname
,   unsigned    libver
)
{
    fprintf(
        stm
    ,   "%s%s: v%u.%u.%u.%u (%s = 0x%08x)\n"
    ,   prefix
    ,   libname
    ,   (libver >> 24) & 0xff
    ,   (libver >> 16) & 0xff
    ,   (libver >> 8) & 0xff
    ,   (libver >> 0) & 0xff
    ,   macroname
    ,   libver
    );
}


int main(int argc, char* argv[])
{
    ((void)&argc);
    ((void)&argv);

    {
        unsigned const libver = (unsigned)OPENRJ_VER;

        version(stdout, "", "openrj", "OPENRJ_VER", libver);
    }

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */
