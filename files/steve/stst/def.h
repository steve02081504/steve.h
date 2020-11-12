//def.h
//
#if !defined(STEVE_H_TEST)
	#line 1 "????"
#endif
//
#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4474)//过时printf警告diss
	#pragma warning(disable:4100)//未用形参警告diss
	#pragma warning(disable:4189)//未用局部变量警告diss
	#pragma warning(disable:28251)//未使用sal批注の警告diss
#endif
//
#if (!defined(UN_ST_ST))&&!defined(ST_ST_ED)
	#if !(defined(ST_ST_SCARG)&&defined(ST_ST_FARG))&&(defined(ST_ST_SCARG)||defined(ST_ST_FARG))
		#error "Make sure you're defined ST_ST_SCARG and ST_ST_FARG at same time."
	#endif
	#if defined(ST_ST_WARG)&&ST_SYSTYPE!=windows
		#error "Can't find something like 'HINSTANCE' or 'ST_ST_WARG'."
	#endif
	#if defined(ST_ST_ECARG)&&ST_SYSTYPE==windows
		#error "Are you sure you can use execve in windows?"
	#endif
	#if defined(ST_ST_DONTUSEWINMAIN)&&defined(ST_ST_WARG)
		#error "Can't define ST_ST_DONTUSEWINMAIN and ST_ST_WARG at same time."
	#endif
	//
	#if defined(ST_ST_WARG)||defined(ST_ST_ECARG)
		#undef ST_ST_CARG
		#define ST_ST_CARG
	#endif
	#if defined(ST_ST_FARG)
	#elif defined(ST_ST_WARG)
		#define ST_ST_SCARG (HINSTANCE,HINSTANCE,LPSTR,int)
	#elif defined(ST_ST_ECARG)
		#define ST_ST_SCARG (int,char**,char**)
	#elif defined(ST_ST_CARG)
		#define ST_ST_SCARG (int,char**)
	#else
		#define ST_ST_SCARG (void)
		#define ST_ST_FARG ()
	#endif
	//
	#if !defined(ST_ST_TYPE)
		#define ST_ST_TYPE void
		#define _isVOID
	#endif
	#if !defined(ST_ST_NOSETLC)
		#include elocale
	#endif
	#if !defined(STEST_OFF)
		#include steio
		#if ST_CPP
			#include <exception>
		#endif
	#endif
	#if defined(ST_ST_END)
		//#define st_signal(sl) case(sl):fwprintf(stderr,L"%lsstest错误:截获%ls(%ls)信号,将调用theststend()\n",stest_s_h(),L"" #sl,strsignal(sl));goto a;
		#define st_signal(sl) case(sl):fwprintf(stderr,L"%lsstest错误:截获%ls信号,将调用theststend()\n",stest_s_h(),L"" #sl);goto a;
		#include steio
		#include stelib
		#include esignal
		nesebg
		_ste void theststend();
		_ste inline void theststend_(int a)
		{
			usingstd
			#if !defined(UN_STEST)
				stestser=1;
			#endif
			#if !defined(STEST_OFF)
				switch(a)
				{
					#include "ststsignal.h"
					default:
 						//fwprintf(stderr,L"%lsstest错误:截获%ls信号(%hs),%ls",stest_s_h(),L"未知",strsignal(a),L"将调用theststend()\n");goto a;
 						fwprintf(stderr,L"%lsstest错误:截获%ls信号,将调用theststend()\n",stest_s_h(),L"未知");goto a;
				}
				a:
			#endif
			theststend();
			#if !defined(STEST_OFF)
				fwprintf(stderr,L"%ls调用完毕",stest_s_h());
			#endif
			fflush(0);
			_Exit(a);
		}
		neseed
		#undef st_signal
	#endif
	nesebg
	_ste ST_ST_TYPE stst ST_ST_SCARG;
	neseed
	#if ST_SYSTYPE==windows&&!defined(ST_ST_DONTUSEWINMAIN)&&!defined(ST_NOTMAINPART)
		#include <windows.h>
		int WINAPI WinMain
		#
		(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
		{
			usingstd
			usingste
			#if defined(ST_ST_CARG)||defined(ST_ST_FARG)||defined(ST_ST_ECARG)
				int argc=0;
				while(((char**)lpCmdLine)[argc])argc++;
				char**argv=(char**)lpCmdLine,**envp=(char**)0;
			#endif
			//
			#include"callstst.h"
		}
		#define x4d61696e _don_t_do_next__
		#define _WinMain x4d61696e
		#define WinMain _WinMain
	#endif
	#if !defined(ST_NOTMAINPART)
		int main
		#
		(
		#if defined(ST_ST_WARG)||defined(ST_ST_CARG)||defined(ST_ST_FARG)||defined(ST_ST_ECARG)
		int argc,char**argv
		#endif
		#if defined(ST_ST_ECARG)
		,char**envp
		#endif
		)
		#
		{
			usingstd
			usingste
			#if (defined(ST_ST_WARG)||defined(ST_ST_FARG))&&ST_SYSTYPE==windows
				HINSTANCE hInstance=GetModuleHandle((LPCTSTR)((void*)0)),hPrevInstance=(HINSTANCE)0;
				LPSTR lpCmdLine=(LPSTR)argv;
				int nShowCmd=0;
			#endif
			//
			#include"callstst.h"
		}
		#define x6d61696e _don_t_do_next_
		#define _main x6d61696e
		#define main _main
	#endif
	#define ST_ST_ED
	//
	#undef ST_ST_END
	#undef ST_ST_TYPE
	#undef ST_ST_SARG
	#undef ST_ST_WARG
	#undef ST_ST_FARG
	#undef ST_ST_CARG
	#undef ST_ST_ECARG
	#undef ST_ST_SCARG
#endif
#undef _isVOID
//
#if defined(_MSC_VER)
	#pragma warning(pop)
#endif
//
