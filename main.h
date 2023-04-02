/******************************************************************************
 * main.h
 *
 * pdfresurrect - PDF history extraction tool
 * https://github.com/enferex/pdfresurrect
 *
 * See https://github.com/enferex/pdfresurrect/blob/master/LICENSE for license
 * information.
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Special thanks to all of the contributors:  See AUTHORS.
 * Special thanks to 757labs (757 crew), they are a great group
 * of people to hack on projects and brainstorm with.
 *****************************************************************************/

#ifndef MAIN_H_INCLUDE
#define MAIN_H_INCLUDE

#include <stdio.h>


#define EXEC_NAME "pdfresurrect"
#define VER_MAJOR "0"
#define VER_MINOR "25"
#define VER       VER_MAJOR"."VER_MINOR

/* Compiler */
#if defined(_MSC_VER)
#   define COMPILER "MSC"
#elif defined(__llvm__)
#   define COMPILER "llvm"
#elif defined(__GNUC__)
#   define COMPILER "GNU-C"
#else
#   define COMPILER "<other compiler>"
#endif

/* Platform */
#if defined(_WIN64)
#   define PLATFORM "x64"
#elif defined(_WIN32)
#   define PLATFORM "x86"
#elif defined(__linux__)
#   define PLATFORM "linux"
#elif defined(__APPLE__)
#   define PLATFORM "mac"
#else
#   define PLATFORM "<unknown platform>"
#endif

/* Debug vs release */
#if defined(DEBUG) || defined(_DEBUG)
#   define CONFIG "debug"
#else
#   define CONFIG "release"
#endif

/* Experimental or not */
#ifdef PDFRESURRECT_EXPERIMENTAL
#    define EXPERIMENTAL "experimental"
#else
#    define EXPERIMENTAL 
#endif

#define TAG "[pdfresurrect]"
#define ERR(...) {fprintf(stderr, TAG" -- Error -- " __VA_ARGS__);}

/* Returns a zero'd buffer of 'size' bytes or exits in failure. */
extern void *safe_calloc(size_t bytes);

#endif /* MAIN_H_INCLUDE */
