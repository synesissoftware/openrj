# Open-RJ - FAQ <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [What is a Record-JAR?](#what-is-a-record-jar)
- [Does the C core depend on STLSoft?](#does-the-c-core-depend-on-stlsoft)
- [Where are the C++ / STL mappings?](#where-are-the-c--stl-mappings)


## What is a Record-JAR?

A Record-JAR is a simple text database: records separated by `%%` lines, each
containing `name: value` fields. **Open-RJ** parses such databases from files
or memory into a navigable C API.


## Does the C core depend on STLSoft?

No. The C library is standalone. **STLSoft** (and **xTests**) are required
only when building the unit-tests.


## Where are the C++ / STL mappings?

They existed in the historical Open-RJ distribution and are planned as a
follow-on freelibs recovery (not part of this C base tree). See
[GitHub Issues](https://github.com/synesissoftware/openrj/issues).



<!-- ########################### end of file ########################### -->
