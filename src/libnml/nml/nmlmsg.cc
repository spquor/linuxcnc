/********************************************************************
* Description: nmlmsg.cc
*
*   Derived from a work by Fred Proctor & Will Shackleford
*
* Author:
* License: LGPL Version 2
* System: Linux
*    
* Copyright (c) 2004 All rights reserved.
*
* Last change: 
********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
#include <string.h>		// memset

#ifdef __cplusplus
}
#endif
#include "cms.hh"
#include "nmlmsg.hh"
#include "rcs_print.hh"		/* rcs_error_print() */
/* NMLmsg Functions. */ int NMLmsg::automatically_clear = 1;

/* Constructor */
NMLmsg::NMLmsg(NMLTYPE t, long s)
{
    _type = t;
    size = s;
    if (automatically_clear) {
	clear();
    }
    if (size < ((long) sizeof(NMLmsg))) {
	rcs_print_error("NMLmsg: size(=%ld) must be atleast %zu\n", size,
	    sizeof(NMLmsg));
	size = sizeof(NMLmsg);
    }
    if (_type <= 0) {
	rcs_print_error("NMLmsg: type(=%d) should be greater than zero.\n",
	    (int)_type);
    }
};

NMLmsg::NMLmsg(NMLTYPE t, size_t s)
{
    _type = t;
    size = s;
    if (automatically_clear) {
	clear();
    }
    if (size < ((long) sizeof(NMLmsg))) {
	rcs_print_error("NMLmsg: size(=%ld) must be atleast %zu\n", size,
	    sizeof(NMLmsg));
	size = sizeof(NMLmsg);
    }
    if (_type <= 0) {
	rcs_print_error("NMLmsg: type(=%d) should be greater than zero.\n",
	    (int)_type);
    }
}

NMLmsg::NMLmsg(NMLTYPE t, long s, int noclear)
{
    if (automatically_clear && !noclear) {
	clear();
    }
    _type = t;
    size = s;
    if (size < ((long) sizeof(NMLmsg))) {
	rcs_print_error("NMLmsg: size(=%ld) must be atleast %zu\n", size,
	    sizeof(NMLmsg));
	size = sizeof(NMLmsg);
    }
    if (_type <= 0) {
	rcs_print_error("NMLmsg: type(=%d) should be greater than zero.\n",
	    (int)_type);
    }
};

void NMLmsg::clear()
{
    long temp_size;
    NMLTYPE temp_type;
    temp_size = size;
    temp_type = _type;
    memset((void *) this, 0, size);
    size = temp_size;
    _type = temp_type;
    if (size < ((long) sizeof(NMLmsg))) {
	rcs_print_error("NMLmsg: size(=%ld) must be atleast %zu\n", size,
	    sizeof(NMLmsg));
	size = sizeof(NMLmsg);
    }
}
