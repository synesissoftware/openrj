# Open-RJ - Changes <!-- omit in toc -->


## 1.6.5 - 23rd August 2026

T.B.C.


## 1.6.4 - 30th April 2007

* Compatible with **STLSoft** 1.9.1 (C++ / STL mappings; C core unchanged in this release);
* C++: `ReadDatabase()`, `CreateDatabaseFromMemory()`, and related;


## 1.6.3 - 27th September 2006

* Distribution rooted under **openrj-X.Y**;


## 1.6.2 - 26th September 2006

* Visual C++ 8.0 makefile fixes;
* Added **ORJ_PARSE_INVALIDFIELDNAME**; empty field names are now a parse error;
* .NET: `Database.ParseErrorCode.InvalidFieldName`;
* STL: field-iterator updates for Digital Mars;


## 1.6.1 - 20th September 2006

* Visual C++ 8.0 makefile support;
* Added **ORJ_FLAG_FORCEALLFIELDSINTO1RECORD**;
* String handling avoids runtime cost for length evaluation;
* Language bindings updated for the force-all-fields flag;


## 1.5.3 - 9th August 2006

* .NET Database / FileDatabase / MemoryDatabase fixes and constructors;


## 1.5.2 - 26th July 2006

* C++ / STL adjustments for **STLSoft** directory layout changes;
* .NET `Record.GetFieldValue()` overloads;
* Ruby `Database.records` / `Database.fields`;


## 1.5.1 - 28th May 2006

* Field name aliases;
* Case-insensitive field lookups;
* Added **ORJ_Database_GetFieldA()**;
* C++ `Lookup()`; STL `field_assoc_insert_iterator`;
* Expanded .NET / Python / Ruby APIs;
* Eight C examples; six C++ examples; seven STL examples;


## 1.4.1 - 8th August 2005

* Added **ORJ_FormatErrorA()**;
* Added **ORJ_Record_FindNextFieldA()**;


## 1.3.4 - 15th July 2005

* Handles CR+LF irrespective of operating system;


## 1.3.3 - 28th June 2005

* Fixed assert firing on record markers with trailing whitespace;
* Mac OS X compatibility;
* Added `c_str_ptr_null` and `c_str_data` string access shims;


## 1.3.2 - 26th May 2005

* C++ / STL Record types return const Field instances;
* C++ Record subscript operators enhanced;


## 1.3.1 - 23rd May 2005

* Record comments available through the API;
* Implicit link header;
* C++ / STL / Python / Ruby comment accessors and related API expansions;


## 1.2.1 - 4th March 2005

* Added **ORJ_CreateDatabaseFromMemoryA()**;
* Added **ORJ_GetErrorStringA()** / **ORJ_GetParseErrorStringA()**;
* C++ FileDatabase / MemoryDatabase;
* STL classes split into individual headers;


## 1.0.1 - 29th September 2004

* Initial release;



<!-- ########################### end of file ########################### -->
