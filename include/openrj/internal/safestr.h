/* /////////////////////////////////////////////////////////////////////////
 * File:    openrj/internal/safestr.h
 *
 * Purpose: Internal utility header for the Open-RJ API.
 *
 * Created: 8th February 2008
 * Updated: 23rd August 2026
 *
 * Home:    http://synesis.com.au/software/
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


/** \file openrj/internal/safestr.h Internal utility header for the Open-RJ API
 */

#ifndef OPENRJ_INCL_OPENRJ_INTERNAL_H_SAFESTR
#define OPENRJ_INCL_OPENRJ_INTERNAL_H_SAFESTR


/* /////////////////////////////////////////////////////////////////////////
 * version
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_INTERNAL_H_SAFESTR_MAJOR     1
# define OPENRJ_VER_OPENRJ_INTERNAL_H_SAFESTR_MINOR     0
# define OPENRJ_VER_OPENRJ_INTERNAL_H_SAFESTR_REVISION  1
# define OPENRJ_VER_OPENRJ_INTERNAL_H_SAFESTR_EDIT      2
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <openrj/openrj.h>

#ifdef OPENRJ_SAFE_STR_USE_crtdefs_h_
# undef OPENRJ_SAFE_STR_USE_crtdefs_h_
#endif /* OPENRJ_SAFE_STR_USE_crtdefs_h_ */

#if defined(__BORLANDC__)
#elif defined(__DMC__)
#elif defined(__GNUC__)
#elif defined(__INTEL_COMPILER)
# if defined(_MSC_VER) && \
     _MSC_VER >= 1400
#  define OPENRJ_SAFE_STR_USE_crtdefs_h_
# endif /* _MSC_VER >= 1400 */
#elif defined(__MWERKS__)
#elif defined(__WATCOMC__)
#elif defined(_MSC_VER)
# if _MSC_VER >= 1400
#  define OPENRJ_SAFE_STR_USE_crtdefs_h_
# endif /* _MSC_VER >= 1400 */
#elif defined(__COMO__)
#else
#endif /* compiler */

#ifdef OPENRJ_SAFE_STR_USE_crtdefs_h_
# include <crtdefs.h>
#endif /* OPENRJ_SAFE_STR_USE_crtdefs_h_ */


/* /////////////////////////////////////////////////////////////////////////
 * feature detection
 */

#ifdef __STDC_SECURE_LIB__
# if defined(__STDC_WANT_SECURE_LIB__) && \
     __STDC_WANT_SECURE_LIB__ == 1
#  define OPENRJ_USING_SAFE_STR_FUNCTIONS
# endif /* __STDC_WANT_SECURE_LIB__ == 1 */
#endif /* __STDC_SECURE_LIB__ */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* OPENRJ_INCL_OPENRJ_INTERNAL_H_SAFESTR */

/* ////////////////////////////////////////////////////////////////////// */
