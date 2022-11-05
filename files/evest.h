//evest.h
//
#if !defined(STEVE_H_TEST)
	#line 1 "????"
#endif
//
#if defined(linux)
	#define __linux
#endif
//
#include "steve/undefs.h"
#define void 1
#define linux 2
#define windows 3
#define other 4
//#define ST_CPP defined(__cplusplus)//[Warning] this use of "defined" may not be portable [-Wexpansion-to-defined]
#if defined(__cplusplus)
	#define ST_CPP 1
#else
	#define ST_CPP 0
#endif
#define ST_BLOCKNOTENESTABLE (/*/*/0*/**/1)
#define ST_EVE_ST_ED
//
#include "steve/setting.txt"
//
#if ST_CPP
	inline namespace ste{}
	#define nesebg namespace ste{
	#define neseed }
	#define nexc noexcept

	#define stcocp(cline,cppline) (cppline)
	#define stcocp_(cline,cppline) cppline 
	#define usingstd using namespace std;
	#define usingste using namespace ste;

	#define stelib <cstdlib>
	#define stearg <cstdarg>
	#define efolat <cfloat>
	#define elimits <climits>
	#define stebool <voidfile>//<cstdbool> :废弃于c++17
	#define estring <cstring>
	#define esignal <csignal>
	#define steio <cstdio>
	#define cocpio <iostream>
	#define sterrno <cerrno>
	#define etype <cctype>
	#define cocpfio <fstream>
	#define cppstring <string>
	#define cocpsio <sstream>
	#define emlc <voidfile>
	#define emath <cmath>
	#define elocale <clocale>
	#define ewchar <cwchar>
#else
	#define nesebg
	#define neseed
	#define nexc

	#define stcocp(cline,cppline) (cline)
	#define stcocp_(cline,cppline) cline 
	#define usingstd
	#define usingste

	#define stelib <stdlib.h>
	#define stearg <stdarg.h>
	#define efolat <float.h>
	#define elimits <limits.h>
	#define stebool <stdbool.h>
	#define estring <string.h>
	#define esignal <signal.h>
	#define steio <stdio.h>
	#define cocpio <stdio.h>
	#if defined(errno)
		#define sterrno <voidfile>
	#else
		#define sterrno <errno.h>
	#endif
	#define etype <ctype.h>
	#define cocpfio <stdio.h>
	#define cppstring <voidfile>
	#define cocpsio <stdio.h>
	#define emlc <stdlib.h>
	#define emath <math.h>
	#define elocale <locale.h>
	#define ewchar <wchar.h>
#endif
//
#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4099)//class与struct混用警告diss
	#pragma warning(disable:26812)//enum class安利diss.
	#pragma warning(disable:4584)//重复子类警告diss
	#pragma warning(disable:4250)//域控制继承警告diss
	#pragma warning(disable:26432)//不完全默认方法警告diss
	#pragma warning(disable:26435)//virtual override方法警告diss
	#pragma warning(disable:26481)//容器安利diss
	#pragma warning(disable:26446)//gsl::at安利diss
	#pragma warning(disable:26434)//方法覆盖警告diss
	#pragma warning(disable:26429)//gsl::not_null安利diss
	#pragma warning(disable:26471)//对void*进行static_cast安利diss
	#pragma warning(disable:26493)//c风格cast警告diss
	#pragma warning(disable:26438)//goto警告diss
	#pragma warning(disable:26408)//new\delete安利diss
	#pragma warning(disable:26492)//const_cast警告diss
	#pragma warning(disable:26462)//非const分配警告diss
	#pragma warning(disable:26496)//const标记警告diss
#endif
//
#if defined(_MSC_VER)
	#include <sal.h>
#endif
//
#define _ste
#define _al
//
nesebg
typedef stcocp_(_Bool,bool) stbool;
neseed
//
