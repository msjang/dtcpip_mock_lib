// COPYRIGHT_BEGIN
//  DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
//
//  Copyright (C) 2008-2009, Cable Television Laboratories, Inc.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, version 2. This program is distributed
//  in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
//  even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE. See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program.  If not, see  <http://www.gnu.org/licenses/>.
//
//  Please contact CableLabs if you need additional information or
//  have any questions.
//
//      CableLabs
//      858 Coal Creek Cir
//      Louisville, CO 80027-9750
//      303 661-9100
//      oc-mail@cablelabs.com
//
//  If you or the company you represent has a separate agreement with CableLabs
//  concerning the use of this code, your rights and obligations with respect
//  to this code shall be as set forth therein. No license is granted hereunder
//  for any other purpose.
// COPYRIGHT_END

#if !defined(_OS_TYPES_H)
#define _OS_TYPES_H

#include <time.h>
#include <pthread.h>
#include <stdarg.h>

#include <stdint.h> /* uint32_t etc. */

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
#define OS_LIBEXPORT(type, symbol) extern "C" type symbol
#else
#define OS_LIBEXPORT(type, symbol) extern type symbol
#endif

/*
 * Define macro for calculating the offset of a field in a struct:
 *
 * @param Struc is the structure pointer type
 * @param field is the field of interest in the struct
 */
#define OFFSET(Struc, field) ((uint32_t) &((Struc *)0)->field)

/*
 * Define macro for construction of a fake list head pointer:
 *
 * @param Struc is the structure pointer type
 * @param head is the address location to offset from (usually the first fake link)
 * @param link is the link field name within the struct
 */
#define FAKEHEAD(Struc, head, link) ((Struc *)((char *)&head - OFFSET(Struc, link)))

/* The printf format specifiers for 64-bit integers */
#define FMT64 "%lld"
#define FMTU64 "%llu"

#ifdef __cplusplus
}
#endif

#endif /* _OS_TYPES_H */
