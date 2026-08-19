#! /bin/bash

ScriptPath=$0
Dir=$(cd "$(dirname "$ScriptPath")" && pwd)
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")
Doxygen=${DOXYGEN:-doxygen}
OutputDir=${SIS_DOXYGEN_OUTPUT_DIR:-$Dir/_build/doxygen}
ConfigFile="$OutputDir/Doxyfile"


if [[ "$1" == "--help" ]]; then
    cat << EOF
Generates the Doxygen documentation for ${ProjectName}.

$ScriptPath

The generated documentation is written to:
    $OutputDir/html/

Set DOXYGEN to select the Doxygen executable and
SIS_DOXYGEN_OUTPUT_DIR to select the output directory.
EOF
    exit 0
fi

if [[ $# -gt 0 ]]; then
    >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"
    exit 1
fi

if ! command -v "$Doxygen" >/dev/null 2>&1; then
    >&2 echo "$ScriptPath: Doxygen executable not found: $Doxygen"
    exit 1
fi

mkdir -p "$OutputDir" || exit 1

cat > "$ConfigFile" << EOF
PROJECT_NAME           = Open-RJ
PROJECT_NUMBER         = 1.6.5-alpha1
PROJECT_BRIEF          = "A C library for reading Record-JAR databases"
OUTPUT_DIRECTORY       = "$OutputDir"
INPUT                  = "$Dir/include" "$Dir/doc/mainpage.md"
RECURSIVE              = YES
USE_MDFILE_AS_MAINPAGE = "$Dir/doc/mainpage.md"
FILE_PATTERNS          = *.h *.c *.md
EXCLUDE_PATTERNS       = */_build/*
FULL_PATH_NAMES        = NO
STRIP_FROM_PATH        = "$Dir"
OPTIMIZE_OUTPUT_FOR_C  = YES
EXTRACT_ALL            = YES
EXTRACT_STATIC         = YES
JAVADOC_AUTOBRIEF      = YES
WARN_IF_UNDOCUMENTED   = NO
WARN_IF_DOC_ERROR      = YES
WARN_LOGFILE           = "$OutputDir/doxygen-warnings.log"
GENERATE_HTML          = YES
GENERATE_TREEVIEW      = YES
GENERATE_LATEX         = NO
HAVE_DOT               = NO
QUIET                  = NO
EOF

echo "Generating Doxygen documentation for ${ProjectName} in ${OutputDir}"
"$Doxygen" "$ConfigFile"
