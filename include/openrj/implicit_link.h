/* /////////////////////////////////////////////////////////////////////////
 * File:    openrj/implicit_link.h (formerly openrj/openrj_implicit_link.h)
 *
 * Purpose: Implicit linking for the Open-RJ API
 *
 * Created: 8th April 2005
 * Updated: 23rd August 2026
 *
 * Home:    http://openrj.org/
 *
 * Copyright (c) 2019-2026, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file openrj/implicit_link.h Implicit linking for the Open-RJ API
 */

#ifndef OPENRJ_INCL_OPENRJ_H_IMPLICIT_LINK
#define OPENRJ_INCL_OPENRJ_H_IMPLICIT_LINK


/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_H_IMPLICIT_LINK_MAJOR    2
# define OPENRJ_VER_OPENRJ_H_IMPLICIT_LINK_MINOR    1
# define OPENRJ_VER_OPENRJ_H_IMPLICIT_LINK_REVISION 3
# define OPENRJ_VER_OPENRJ_H_IMPLICIT_LINK_EDIT     9
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef OPENRJ_INCL_OPENRJ_H_OPENRJ
# include <openrj/openrj.h>
#endif /* !OPENRJ_INCL_OPENRJ_H_OPENRJ */


/* /////////////////////////////////////////////////////////////////////////
 * architecture discrimination
 */

#if defined(__amd64__) || \
    defined(__amd64) || \
    defined(_AMD64_) || \
    defined(_M_AMD64) || \
    defined(_M_X64)
# define OPENRJ_ARCH_IS_X64
#elif defined(__ia64__) || \
      defined(__ia64) || \
      defined(_IA64_) || \
      defined(_M_IA64)
# define OPENRJ_ARCH_IS_IA64
#elif defined(__i386__) || \
      defined(__i386) || \
      defined(_X86_) || \
      defined(_M_IX86)
# define OPENRJ_ARCH_IS_X86
#endif /* _M_?? */


/* /////////////////////////////////////////////////////////////////////////
 * implicit linking
 */

#if defined(_WIN32) || \
    defined(_WIN64)

# if defined(__BORLANDC__) || \
     /* defined(__DMC__) || */ \
     defined(__INTEL_COMPILER) || \
     defined(__MWERKS__) || \
     defined(_MSC_VER)
#  define OPENRJ_IMPLICIT_LINK_SUPPORT
# endif /* compiler */

# if defined(OPENRJ_IMPLICIT_LINK_SUPPORT) && \
     defined(OPENRJ_NO_IMPLICIT_LINK)
#  undef OPENRJ_IMPLICIT_LINK_SUPPORT
# endif /* OPENRJ_IMPLICIT_LINK_SUPPORT && OPENRJ_NO_IMPLICIT_LINK */

# if defined(OPENRJ_IMPLICIT_LINK_SUPPORT)

#  if defined(__BORLANDC__)
#   if __BORLANDC__ == 0x0550
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "bc55"
#   elif (__BORLANDC__ == 0x0551)
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "bc551"
#   elif (__BORLANDC__ == 0x0560)
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "bc56"
#   elif (__BORLANDC__ == 0x0564)
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "bc564"
#   elif (__BORLANDC__ == 0x0582)
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "bc582"
#   else /* ? __BORLANDC__ */
#    error Unrecognised value of __BORLANDC__
#   endif /* __BORLANDC__ */

/*
#  elif defined(__DMC__)
#   define OPENRJ_IMPL_LINK_COMPILER_NAME           "dm"
 */

#  elif defined(__INTEL_COMPILER)
#   if __INTEL_COMPILER == 600
#    define   OPENRJ_IMPL_LINK_COMPILER_NAME  "icl6"
#   elif __INTEL_COMPILER == 700
#    define   OPENRJ_IMPL_LINK_COMPILER_NAME  "icl7"
#   elif __INTEL_COMPILER == 800
#    define   OPENRJ_IMPL_LINK_COMPILER_NAME  "icl8"
#   else
#    error Intel C/C++ version not supported
#   endif /* _MSC_VER */

#  elif defined(__MWERKS__)
#   if ((__MWERKS__ & 0xFF00) == 0x2400)
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "cw7"
#   elif ((__MWERKS__ & 0xFF00) == 0x3000)
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "cw8"
#   elif ((__MWERKS__ & 0xFF00) == 0x3200)
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "cw9"
#   else /* ? __MWERKS__ */
#    error Unrecognised value of __MWERKS__
#   endif /* __MWERKS__ */

#  elif defined(_MSC_VER)
#   if _MSC_VER == 1000
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "vc4"
#   elif _MSC_VER == 1020
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "vc42"
#   elif _MSC_VER == 1100
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "vc5"
#   elif _MSC_VER == 1200
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "vc6"
#   elif _MSC_VER == 1300
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "vc7"
#   elif _MSC_VER == 1310
#    define OPENRJ_IMPL_LINK_COMPILER_NAME          "vc71"
#   elif _MSC_VER == 1400
#    if defined(_M_IX86)
#     define OPENRJ_IMPL_LINK_COMPILER_NAME         "vc8"
#    elif defined(_M_X64) || \
          defined(_M_AMD64)
#     define OPENRJ_IMPL_LINK_COMPILER_NAME         "vc8_x64"
#    elif defined(_M_IA64)
#     define OPENRJ_IMPL_LINK_COMPILER_NAME         "vc8_ia64"
#    else /* ? arch */
#     error Unrecognised architecture
#    endif /* arch */
#   elif _MSC_VER == 1500
#    if defined(_M_IX86)
#     define OPENRJ_IMPL_LINK_COMPILER_NAME         "vc9"
#    elif defined(_M_X64) || \
          defined(_M_AMD64)
#     define OPENRJ_IMPL_LINK_COMPILER_NAME         "vc9_x64"
#    elif defined(_M_IA64)
#     define OPENRJ_IMPL_LINK_COMPILER_NAME         "vc9_ia64"
#    else /* ? arch */
#     error Unrecognised architecture
#    endif /* arch */
#   else /* ? _MSC_VER */
#    error Visual C++ version not supported
#   endif /* _MSC_VER */

#  else /* ? compiler */
#   error Unrecognised compiler
#  endif /* compiler */


#  if defined(__MT__) || \
      defined(_REENTRANT) || \
      defined(_MT)
#   if defined(_DLL) || \
       defined(__DLL)
#    define OPENRJ_IMPL_LINK_THREADING_TYPE         ".dll"
#   else /* ? dll */
#    define OPENRJ_IMPL_LINK_THREADING_TYPE         ".mt"
#   endif /* dll */
#  else /* ? mt */
#    define OPENRJ_IMPL_LINK_THREADING_TYPE         ""
#  endif /* mt */


#  if !defined(NDEBUG) && \
      defined(_DEBUG)
#   define OPENRJ_IMPL_LINK_DEBUG_TYPE              ".debug"
#  else /* ? _DEBUG */
#   define OPENRJ_IMPL_LINK_DEBUG_TYPE              ""
#  endif /* _DEBUG */


#  define OPENRJ_IMPL_LINK_LIBRARY_BASENAME_s_(x)    #x
#  define OPENRJ_IMPL_LINK_LIBRARY_BASENAME_s(x)     OPENRJ_IMPL_LINK_LIBRARY_BASENAME_s_(x)
#  define OPENRJ_IMPL_LINK_LIBRARY_BASENAME          "openrj." OPENRJ_IMPL_LINK_LIBRARY_BASENAME_s(OPENRJ_VER_MAJOR) "."

#  define OPENRJ_IMPL_LINK_LIBRARY_NAME              OPENRJ_IMPL_LINK_LIBRARY_BASENAME OPENRJ_IMPL_LINK_COMPILER_NAME OPENRJ_IMPL_LINK_THREADING_TYPE OPENRJ_IMPL_LINK_DEBUG_TYPE ".lib"

#  pragma message("lib: " OPENRJ_IMPL_LINK_LIBRARY_NAME)

#  pragma comment(lib, OPENRJ_IMPL_LINK_LIBRARY_NAME)

# endif /* OPENRJ_IMPLICIT_LINK_SUPPORT */

#endif /* Win32 */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_H_IMPLICIT_LINK */

/* ////////////////////////////////////////////////////////////////////// */
