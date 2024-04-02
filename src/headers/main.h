#ifndef MAIN_H
#define MAIN_H

/* ACCESS FOR WINDOWS  */
#ifdef _WIN32
#include <io.h>
#define F_OK 0
#define R_OK 1
#define access _access
#endif

/* HEADER FILE FOR UNIX  */
#ifdef __unix__
#include <unistd.h>
#endif

/* Include required standard library headers. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <search.h>

/* Define system constants. */
#define MAX_LINE_BUFFER_SIZE 512

/* Include subsystem headers. */
#include "file_exist_readable.h"
#include "count_vowel.h"
#include "qsortcomp.h"

#endif
