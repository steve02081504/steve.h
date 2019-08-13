//steve.h
//
#if !defined(STEVE_H_TEST)
	#line 1 "????"
#endif
//
#if !defined(ST_EVE_ST_ED)
	#include "evest.h"
#endif
//
#if defined(ST_ST_TYPE)&&(ST_ST_TYPE==void)
	#define _isVOID
#endif
#undef void
//
#if !defined(ST_TBUFSIZE)
	#define ST_TBUFSIZE 2048
#endif
//
#if !defined(ST_SYSTYPE)
	#if defined(WIN32)||defined(_WIN32)||defined(_WIN64)||defined(WIN64)||defined(_WIN128)||defined(WIN128)||defined(_WIN256)||defined(WIN256)//wdnmd
		#define ST_SYSTYPE windows
	#elif defined(__linux)||defined(__linux__)||defined(__gnu_linux__)
		#define ST_SYSTYPE linux
	#else
		#define ST_SYSTYPE other
	#endif
#endif
//
#if ST_SYSTYPE==linux
	#define stworl(winline,linline) (linline)
	#define stworl_(winline,linline) linline
#elif ST_SYSTYPE==windows
	#define stworl(winline,linline) (winline)
	#define stworl_(winline,linline) winline
#endif
//
#if ST_SYSTYPE==linux||ST_SYSTYPE==windows||ST_SYSTYPE==other
	#undef other
	#include "steve/_body.h"
#else
	#error "Unable OS,check whether your spelling of the ST_SYSTYPE macro is all lowercase or contact steve.h's producers."
#endif
//
#if !defined(ST_UN_DEFS)

	#undef max
	#undef min
	//fucking shit windows.h

    #undef floop
    #undef ret
    #define floop for(;;)
    #define nul ((char)0)
    #define ret return
    #include stebool
    #include elimits
    #include efolat
    #include emath
    #if (!ST_CPP)
        #include <stdalign.h>// defined(__STDC__VERSION__)&&__STDC_VERSION__>=201112L   need
		#define null ((void*)0)
	#else
		#define null nullptr
    #endif
#endif
//
#include "steve/undefs.h"
//
#if defined(__linux)
	#define linux
#endif
//
//#define DEFVARG(name,defval) ((#name[0])?name:defval)//参数默认值宏,大概是没什么用233.
//
