# Open-RJ <!-- omit in toc -->

Small C library for reading Record-JAR (**openrj**) databases.


![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/openrj.svg)](https://github.com/synesissoftware/openrj/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/openrj)](https://github.com/synesissoftware/openrj/commits/master)
[![CI](https://github.com/synesissoftware/openrj/actions/workflows/ci.yml/badge.svg)](https://github.com/synesissoftware/openrj/actions/workflows/ci.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
  - [Dependencies](#dependencies)
- [Installation](#installation)
- [Components](#components)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies-1)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**Open-RJ** reads Record-JAR databases: text files (or in-memory buffers) of records separated by `%%` lines, each record holding `name: value` fields. Continuation lines, comments, field aliases, and ordered/case-insensitive lookup are supported by the C API.

This tree is the **C** base of the Open-RJ family (recovered from the historical Open-RJ 1.6.4 line). C++ / STL mappings and language bindings are separate follow-on work.


### Dependencies

| Component    | Implemented in | Use in                         | Dependencies                                                 |
| ------------ | -------------- | ------------------------------ | ------------------------------------------------------------ |
| Core library | C              | C — via **openrj/openrj.h**    | \<none\>                                                     |
| Examples     | C              | -                              | \<none\>                                                     |
| Unit tests   | C              | -                              | [**STLSoft**](https://github.com/synesissoftware/STLSoft), [**xTests**](https://github.com/synesissoftware/xTests) |


## Installation

Detailed instructions — via **CMake** or bundling — are provided in [**INSTALL.md**](./INSTALL.md).


## Components

The public C API is declared in [`openrj/openrj.h`](./include/openrj/openrj.h):

| API | Purpose |
| --- | ------- |
| `ORJ_ReadDatabaseA()` | Load a Record-JAR from a file path |
| `ORJ_CreateDatabaseFromMemoryA()` | Load a Record-JAR from a memory buffer |
| `ORJ_FreeDatabaseA()` | Release a database |
| `ORJ_Database_GetNumRecordsA()` / `…FieldsA()` / `…LinesA()` | Database metrics |
| `ORJ_Database_GetRecordA()` | Obtain a record by index |
| `ORJ_Record_GetFieldA()` / `ORJ_Record_FindFieldByNameA()` | Field access |
| `ORJ_GetErrorStringA()` / `ORJ_GetParseErrorStringA()` | Error messaging |


## Examples

Eight C examples under **examples/c/** exercise memory databases, field enumeration, flags, and lookups. Build them with **CMake** (`BUILD_EXAMPLES=ON`, the default) and run via **run_all_examples.sh**.


## Project Information


### Where to get help

[GitHub Issues](https://github.com/synesissoftware/openrj/issues)


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/openrj.


### Dependencies

The **Open-RJ** C core has no non-standard dependencies.

Unit-tests depend on [**STLSoft**](https://github.com/synesissoftware/STLSoft) (≥ 1.11) and [**xTests**](https://github.com/synesissoftware/xTests) (≥ 0.26), and optionally [**shwild**](https://github.com/synesissoftware/shwild).


### Related projects

* [**FastFormat**](https://github.com/synesissoftware/FastFormat) — includes an Open-RJ bundle inserter historically;
* Planned: Open-RJ C++ / STL mappings, and a Rust record-jar crate;


### License

**Open-RJ** is released under the [BSD 3-Clause license](./LICENSE).



<!-- ########################### end of file ########################### -->
