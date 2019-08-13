//callstst.h
//
#if !defined(STEVE_H_TEST)
#line 1 "????"
#endif
//
#if defined(ST_ST_END)
	#define st_signal(a) signal(a,theststend_);
	#include "ststsignal.h"
	#undef st_signal
#endif
#if !defined(ST_ST_NOSETLC)
	setlocale(LC_ALL,"");
#endif
#if defined(ST_ST_END)
	atexit(theststend);
#endif
#if defined(STEST_ED)&&defined(STEST_ON)
	stest_entryevent(L"stst");
#endif
#if ST_CPP
	try{
#endif
#if defined(_isVOID)
	stst
#else
	return(int)stst
#endif
//
#if defined(ST_ST_WARG)
	(hInstance,hPrevInstance,lpCmdLine,nShowCmd)
#elif defined(ST_ST_CARG)
	(argc,argv)
#elif defined(ST_ST_ECARG)
	(argc,argv,envp)
#else
	ST_ST_FARG
#endif
;
//
#if defined(_isVOID)
	return 0;
#endif
#if ST_CPP
	}
	#if defined(STEST_ED)&&defined(STEST_ON)
		catch(exception&a)
		{
			stestser=1;
			fwprintf(stderr,L"%lsstest错误：stst\n截获%hs类型throw，地址为%p\n其内容为：",stest_s_h(),"exception",(void*)&a);
			fprintf(stderr,"\n%hs\n",a.what());
			#include"cated.h"
		}
		catch(int a)
		{
			stestser=1;
			fwprintf(stderr,L"%lsstest错误：stst\n截获%hs类型throw，地址为%p\n其内容为：",stest_s_h(),"int",(void*)&a);
			fprintf(stderr,"\n%d\n",a);
			#include"cated.h"
		}
		catch(char const*a)
		{
			stestser=1;
			fwprintf(stderr,L"%lsstest错误：stst\n截获%hs类型throw，地址为%p\n其内容为：",stest_s_h(),"char*",(void*)&a);
			fprintf(stderr,"\n%s\n",a);
			#include"cated.h"
		}
		catch(...)
		{
			stestser=1;
			fwprintf(stderr,L"%lsstest错误：stst\n截获%hs类型throw，地址为%p\n其内容为：",stest_s_h(),"unknow",((void*)0));
			fprintf(stderr,"\nunknow\n");
			#include"cated.h"
		}
	#else
		catch(...){return 0;}
	#endif
#endif
//
