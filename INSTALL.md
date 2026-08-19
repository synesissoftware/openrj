# Open-RJ - Installation and Use <!-- omit in toc -->

**Open-RJ** is a classic-form C library, insofar as it has implementation files
in its **src** directory and header files in its **include/openrj** directory.
Thus, once "installed", one must simply include **openrj/openrj.h** and
compile-in or link-in the implementation.

The **C API** has no non-standard dependencies. Building the project's tests
additionally requires **STLSoft** and **xTests** (and optionally recognises
**shwild**).


## Table of Contents <!-- omit in toc -->

- [CMake](#cmake)
- [Bundled](#bundled)


## CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **Open-RJ**, from
   https://github.com/synesissoftware/openrj/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/openrj/
   ```

2. Prepare the CMake configuration, via the **prepare_cmake.sh** script.

   For a library-only build (no tests — no **STLSoft** / **xTests**
   required):

   ```bash
   $ cd ~/open-source/openrj
   $ ./prepare_cmake.sh --disable-testing -v
   ```

   For a full build including examples and tests, install **STLSoft** 1.11
   and **xTests** via their own **CMake** scripts first, then:

   ```bash
   $ cd ~/open-source/openrj
   $ ./prepare_cmake.sh -v
   ```

   If **STLSoft** is available as a source tree rather than an installed
   **CMake** package, pass its root with `--stlsoft-root-dir` / `-s`.

   (**Hint**: execute `$ ./prepare_cmake.sh --help` for more information.)

3. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

   ```bash
   $ ./build_cmake.sh
   ```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 2 then
   you do not need this step.)

4. As a check (when testing was not disabled), execute the built unit-test
   programs via **run_all_unit_tests.sh**, as in:

   ```bash
   $ ./run_all_unit_tests.sh
   ```

5. Install the library on the host, via `cmake`, as in:

   ```bash
   $ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
   ```

6. Then to use the library, it is a simple matter as follows:

   ```cmake
   find_package(openrj REQUIRED)
   target_link_libraries(your_target PRIVATE openrj::core)
   ```

   and in your sources:

   ```c
   #include <openrj/openrj.h>
   ```


## Bundled

**Open-RJ** may also be used by bundling its **include/** and **src/** trees
into a consuming project and compiling **orjapi.c**, **orjmem.c**, and
**orjstr.c** alongside the rest of the build.



<!-- ########################### end of file ########################### -->
