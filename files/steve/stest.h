//stest.h
//
#if !defined(STEVE_H_TEST)
	#line 1 "????"
#endif
//
#if defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4474)//过时wprintf警告diss
	#pragma warning(disable:6031)//getchar返回值忽略警告diss
	#pragma warning(disable:4996)//strerror警告diss
#endif
//
#if !defined(UN_STEST)&&!defined(STEST_ED)
	#if !defined(STEST_OFF)
		#include steio//io
		#include stearg//vswprintf
		#include stelib//many
		#include sterrno//errno
		#include estring//strerror
		#include ewchar//wprintf
		nesebg
		#if ST_CPP
			_ste inline bool stestout=1,stestser=0,instest=1;
		#elif defined(ST_NOTMAINPART)
			_ste extern _Bool stestout,stestser,instest;
		#else
			_ste _Bool stestout=1,stestser=0,instest=1;
		#endif
		_ste inline const wchar_t*stest_s_h()nexc
		{
			if(!stestout&&stestser)return L"<特殊测试信息、无视stestout设置>\n";
			return 
			#if defined(ST_STESTMG_OFF)
				L""
			#else
				L"<测试信息>\n"
			#endif
			;
		}
		_ste inline void stest1(const wchar_t*a)nexc
		{
			usingstd
			if(!stestout)return;
			wprintf(L"%ls尝试将\"%ls\"解释为整数值\n",stest_s_h(),a);
			fflush(stdout);
			return;
		}
		_ste inline long long stest2(long long b)nexc
		{
			usingstd
			if(!stestout)return b;
			wprintf(L"其值为%lld\n",b);
			fflush(stdout);
			return b;
		}
		#define stest(...) (instest?stest2((stest1(L"" #__VA_ARGS__),(long long)(__VA_ARGS__))):(long long)(__VA_ARGS__))
		_ste inline void stestp1(const wchar_t*a)nexc
		{
			usingstd
			if(!stestout)return;
			wprintf(L"%ls尝试将\"%ls\"解释为指针\n",stest_s_h(),a);
			fflush(stdout);
			return;
		}
		_ste inline void*stestp2(void*b)nexc
		{
			usingstd
			if(!stestout)return b;
			wprintf(L"其值为%p\n",b);
			fflush(stdout);
			return b;
		}
		#define stestp(...) (instest?stestp2((stestp1(L"" #__VA_ARGS__),(void*)(__VA_ARGS__))):(void*)(__VA_ARGS__))
		_ste inline void stestb1(const wchar_t*a)nexc
		{
			usingstd
			if(!stestout)return;
			wprintf(L"%ls尝试将\"%ls\"解释为bool\n",stest_s_h(),a);
			fflush(stdout);
			return;
		}
		_ste inline stbool stestb2(stbool b)nexc
		{
			usingstd
			if(!stestout)return b;
			wprintf(L"其值为%hs\n",b?"true":"false");
			fflush(stdout);
			return b;
		}
		#define stestb(...) (instest?stestb2((stestb1(L"" #__VA_ARGS__),(stbool)(__VA_ARGS__))):(stbool)(__VA_ARGS__))
		_ste inline int stest_ddit_(const wchar_t*a)nexc
		{
			usingstd
			if(!stestout)return 0;
			wprintf(L"%ls此处本应执行\"%ls\",但并不会这样做\n",stest_s_h(),a);
			fflush(stdout);
			return 0;
		}
		#define stest_ddit(...) (instest?stest_ddit_(L"" #__VA_ARGS__):(__VA_ARGS__))
		_ste inline void stest_odit_(const wchar_t*a)nexc
		{
			usingstd
			if(!stestout)return;
			wprintf(L"%ls此处将执行\"%ls\",但也只会在测试情况下执行\n",stest_s_h(),a);
			fflush(stdout);
			return;
		}
		#define stest_odit(...) (instest?(stest_odit_(L"" #__VA_ARGS__),(__VA_ARGS__)):0)
		_ste inline void stest_wait()nexc
		{
			usingstd
			if(!(stestser||stestout))return;
			wprintf(L"%ls这里有两个getchar调用\n",stest_s_h());
			getchar();
			getchar();
		}
		_ste inline void*stest_alloc(size_t a)nexc{
			usingstd
			void*tmp=malloc(a);
			if(tmp)
				return tmp;
			wprintf(L"%ls内存分配失败，准备结束执行\n",stest_s_h());
			stest_wait();
			fflush(0);
			exit(-1);
		}
		_ste inline void*stest_realloc(void*p,size_t a)nexc{
			usingstd
			void*tmp=realloc(p,a);
			if(tmp)
				return tmp;
			wprintf(L"%ls内存分配失败，准备结束执行\n",stest_s_h());
			stest_wait();
			fflush(0);
			exit(-1);
		}
		_ste inline void stest_puts(const wchar_t*message)nexc
		{
			usingstd
			if(!stestout)return;
			wprintf(L"%ls%ls\n",stest_s_h(),message);
			fflush(stdout);
		}
		#if defined(__GNUC__)
		_ste inline int stest_putsf(const wchar_t*message,...)nexc __attribute__((format(wprintf,1,2)));
		#elif defined(_MSC_VER)
		_ste inline int stest_putsf(_Printf_format_string_ const wchar_t*message,...)nexc;
		#endif
		_ste inline int stest_putsf(const wchar_t*message,...)nexc
		{
			usingstd
			if(!instest||!stestout)return 0;
			wchar_t*a=(wchar_t*)0;
			unsigned long b=ST_TBUFSIZE/2;
			#if defined(_MSC_VER)
				#pragma warning(push)
				#pragma warning(disable:26494)//未初始化警告diss
			#endif
			int c;
			#if defined(_MSC_VER)
				#pragma warning(pop)
			#endif
	a:		b*=2;
			a=(wchar_t*)stest_realloc(a,b*sizeof(wchar_t));
			#if defined(_MSC_VER)
				#pragma warning(push)
				#pragma warning(disable:26826)//c变参警告diss
			#endif
			va_list argptr;
			va_start(argptr,message);
			c=vswprintf(a,b,message,argptr);
			va_end(argptr);
			#if defined(_MSC_VER)
				#pragma warning(pop)
			#endif
			if(c<0)goto a;
			stest_puts(a);
			free(a);
			return 0;
		}
		_ste inline int stest_now_(unsigned long a,const wchar_t*b
		#if ST_CPP
			,const char*c
		#endif
		)nexc
		{
			usingstd
			if(!stestout)return 0;
			wprintf(L"%ls当前执行至文件\"%ls\"的%lu行",stest_s_h(),b,a);
			#if ST_CPP
				wprintf(L"，即函数\"%hs\"\n",c);
			#else
				wprintf(L"\n");
			#endif
			fflush(stdout);
			return 0;
		}
		#if ST_CPP
			#define stest_now() (instest&&stest_now_(__LINE__,L"" __FILE__,__func__))
		#else
			#define stest_now() (instest&&stest_now_(__LINE__,L"" __FILE__))
		#endif
		#if defined(ST_ST_END)&&!defined(UN_ST_ST)
			_ste void theststend();
		#endif 
		_ste inline int stest_accert_(stbool a,const wchar_t*b,unsigned long c,const wchar_t*d
		#if ST_CPP
			,const char*e
		#endif
		)nexc
		{
			usingstd
			if(!a){stestser=1;goto a;}
			if(!(stestout&&stestser))return a;
a:			wprintf(L"%ls当前执行至文件\"%ls\"的%lu行",stest_s_h(),d,c);
			#if ST_CPP
				wprintf(L"，即函数\"%hs\"\n",e);
			#else
				wprintf(L"\n");
			#endif
			wprintf(L"%ls的bool值为%ls\n",b,a?L"true":L"flase,将调用theststend()");
			fflush(stdout);
			if(!a)
			{
				fwprintf(stderr,L"errno值：%d（%hs）\n",errno,strerror(errno));
				//fwprintf(stderr,L"errno值：%d\n",errno);
				#if defined(ST_ST_END)&&!defined(UN_ST_ST)
					theststend();
				#else
					fwprintf(stderr,L"错误：未使用theststend模块\n");
				#endif
				fwprintf(stderr,L"%ls调用完毕",stest_s_h());
				fflush(0);
				_Exit(-1);
			}
			return a;
		}
		#if ST_CPP
			#define stest_accert(...) (instest&&stest_accert_((bool)(__VA_ARGS__),L"" #__VA_ARGS__,__LINE__,L"" __FILE__,__func__))
		#else
			#define stest_accert(...) (instest&&stest_accert_((_Bool)(__VA_ARGS__),L"" #__VA_ARGS__,__LINE__,L"" __FILE__))
		#endif
		_ste inline void stestouton()nexc	{stestout=1;}
		_ste inline void stestoutoff()nexc	{stestout=0;}
		_ste inline void steston()nexc		{instest=1;}
		_ste inline void stestoff()nexc		{instest=0;}
		#if !defined(UN_ST_ST)&&!defined(ST_ST_END)
			#define ST_ST_END
			_ste inline void theststend()nexc{if(stestout)fwprintf(stderr,L"%lstheststend为空\n",stest_s_h());fflush(stderr);}
		#endif
		typedef struct steventlist_{
			const wchar_t*name;
			struct steventlist_*next;
		}steventlist;
		typedef struct steventloglist_{
			const void*to;
			steventlist*with;
			struct steventloglist_*next;
		}steventloglist;
		#if ST_CPP
			_ste inline steventlist*stesteventlistinfo=0;
			_ste inline steventloglist*stesteventloginfo=0;
		#elif defined(ST_NOTMAINPART)
			_ste extern steventlist*stesteventlistinfo;
			_ste extern steventloglist*stesteventloginfo;
		#else
			_ste steventlist*stesteventlistinfo=0;
			_ste steventloglist*stesteventloginfo=0;
		#endif
		_ste inline void stest_entryevent(const wchar_t*name)nexc
		{
			usingstd
			steventlist a={name,stesteventlistinfo};
			(*(stesteventlistinfo=(steventlist*)stest_alloc(sizeof(steventlist))))=a;
		}
		_ste inline void stest_exitevent()nexc{
			usingstd
			if(!stesteventlistinfo)return;
			steventlist*tmp=stesteventlistinfo->next;
			free(stesteventlistinfo);
			stesteventlistinfo=tmp;
		}
		_ste inline steventlist*stest_copyeventlist(const steventlist*a)nexc
		{
			usingstd
			steventlist*aret=0,**tmp=&aret;
			while(a){
				(*(*tmp=(steventlist*)stest_alloc(sizeof(steventlist))))=*a;
				tmp=&(*tmp)->next;
				a=a->next;
			}
			return aret;
		}
		_ste inline steventlist*stest_geteventlist()nexc
		{
			return stest_copyeventlist(stesteventlistinfo);
		}
		_ste inline void stest_deleteevent(steventlist*a)nexc{
			usingstd
			#if defined(_MSC_VER)
				#pragma warning(push)
				#pragma warning(disable:26494)//未初始化警告diss
			#endif
			steventlist*tmp;
			#if defined(_MSC_VER)
				#pragma warning(pop)
			#endif
			while(a){
				tmp=a->next;
				free(a);
				a=tmp;
			}
		}
		_ste inline void stest_printeventlist(FILE*fp,steventlist*a)nexc{
			usingstd
			#if defined(_MSC_VER)
				#pragma warning(push)
				#pragma warning(disable:26494)//未初始化警告diss
			#endif
			steventlist*tmp;
			#if defined(_MSC_VER)
				#pragma warning(pop)
			#endif
			if(!stestout){stest_deleteevent(a);return;}
			fputws(stest_s_h(),fp);
			if(!a)fputws(L"空事件记录\n",fp);
			while(a){
				tmp=a->next;
				fwprintf(fp,L"事件\"%ls\"",a->name);
				free(a);
				a=tmp;
				if(a)fputws(L"于此之后：\n",fp);
			}
			fputc('\n',fp); 
			fflush(fp);
		}
		_ste inline void stest_uneventlog(const void*p)nexc{
			usingstd
			steventloglist**tmp=&stesteventloginfo;
			while(*tmp){
				if(p==(*tmp)->to){
					steventloglist*tmp_=(*tmp)->next;
					stest_deleteevent((*tmp)->with); 
					free(*tmp);
					*tmp=tmp_;
					return;
				}
				tmp=&(*tmp)->next;
			}
		} 
		_ste inline void stest_eventlog(const void*p)nexc{
			usingstd
			stest_uneventlog(p);
			steventloglist a={p,stest_geteventlist(),stesteventloginfo};
			(*(stesteventloginfo=(steventloglist*)stest_alloc(sizeof(steventloglist))))=a;
		}
		_ste inline steventlist*stest_geteventlistfromlog(const void*p)nexc{
			steventloglist*tmp=stesteventloginfo;
			while(tmp)
				if(p==tmp->to)
					return stest_copyeventlist(tmp->with); 
				else
					tmp=tmp->next;
			return 0;
		}
		_ste inline void stest_eventclear()nexc{
			stest_deleteevent(stesteventlistinfo);
		}
		_ste inline void stest_eventlogclear()nexc{
			usingstd
			#if defined(_MSC_VER)
				#pragma warning(push)
				#pragma warning(disable:26494)//未初始化警告diss
			#endif
			steventloglist*tmp=stesteventloginfo,*tmp_;
			#if defined(_MSC_VER)
				#pragma warning(pop)
			#endif
			while(tmp){
				tmp_=tmp->next;
				stest_deleteevent(tmp->with); 
				free(tmp);
				tmp=tmp_;
			}
			stesteventloginfo=0;
		}
		_ste inline void stest_mapeventlogwith(void(*m)(const void*,steventlist*))nexc{
			usingstd
			#if defined(_MSC_VER)
				#pragma warning(push)
				#pragma warning(disable:26494)//未初始化警告diss
			#endif
			steventloglist*tmp=stesteventloginfo,*tmp_;
			#if defined(_MSC_VER)
				#pragma warning(pop)
			#endif
			while(tmp){
				tmp_=tmp->next;
				m(tmp->to,tmp->with);
				tmp=tmp_;
			}
		}
		neseed
	#else
		#include steio
		#include stelib//malloc
		#define stest(...) ((long long)(__VA_ARGS__))
		#define stestp(...) ((void*)(__VA_ARGS__))
		#define stestb(...) ((stbool)(__VA_ARGS__))
		#define stest_ddit(...) (__VA_ARGS__)
		#define stest_wait() ((int)0)
		#define stest_puts(...) ((int)0)
		#define stest_putsf(...) ((int)0)
		#define stest_odit(...) 0
		#define stest_accert(...) ((int)(__VA_ARGS__))
		#define stest_now() ((int)0)
		#define instest 0
		nesebg
		_ste inline void stestouton()nexc{}
		_ste inline void stestoutoff()nexc{}
		_ste inline void steston()nexc{}
		_ste inline void stestoff()nexc{}
		typedef void steventlist;
		_ste inline void stest_entryevent(const wchar_t*name)nexc{}
		_ste inline void stest_exitevent()nexc{} 
		_ste inline steventlist*stest_copyeventlist(const steventlist*a)nexc{return 0;}
		_ste inline steventlist*stest_geteventlist()nexc{return 0;}
		_ste inline void stest_deleteevent(steventlist*a)nexc{}
		_ste inline void stest_printeventlist(FILE*fp,steventlist*a)nexc{}
		_ste inline void stest_uneventlog(const void*p)nexc{} 
		_ste inline void stest_eventlog(const void*p)nexc{}
		_ste inline steventlist*stest_geteventlistfromlog(const void*p)nexc{return 0;}
		_ste inline void stest_eventclear()nexc{}
		_ste inline void stest_eventlogclear()nexc{}
		_ste inline void stest_mapeventlogwith(void(*m)(const void*,steventlist*))nexc{}
		_ste inline void*stest_alloc(size_t a)nexc{
			usingstd
			return malloc(a);
		}
		_ste inline void*stest_realloc(void*p,size_t a)nexc{
			usingstd
			return realloc(p,a);
		}
		neseed
	#endif
	#define STEST_ED
#endif
//
#if defined(_MSC_VER)
	#pragma warning(pop)
#endif
//
