//_body.h
//
#if !defined(STEVE_H_TEST)
	#line 1 "????"
#endif
//
#if ST_SYSTYPE==windows
	#include "forwindows.h"
#elif ST_SYSTYPE==linux
	#include "forlinux.h"
#endif
//
#include "common.h"
//
#include "stest.h"
#include "stst/_body.h"
//
#if ST_CPP
	#include "cpptools/_body.hpp"
#endif
//
