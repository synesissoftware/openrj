# Open-RJ <!-- omit in toc -->

**Open-RJ** is a small C library for reading Record-JAR databases.

The public API is provided by **openrj/openrj.h**. It supports loading
Record-JAR data from files or memory, inspecting records and fields, and
reporting parse errors.

## API overview

* `ORJ_ReadDatabaseA()` loads a database from a file;
* `ORJ_CreateDatabaseFromMemoryA()` loads a database from memory;
* `ORJ_Database_GetRecordA()` retrieves a record;
* `ORJ_Record_GetFieldA()` retrieves a field;
* `ORJ_FreeDatabaseA()` releases a database;
* `ORJ_GetErrorStringA()` and `ORJ_GetParseErrorStringA()` describe errors.

## Building

Open-RJ is built with **CMake**. The project has no non-standard runtime
dependencies. Unit tests additionally use **STLSoft** and **xTests**.


<!-- ########################### end of file ########################### -->

