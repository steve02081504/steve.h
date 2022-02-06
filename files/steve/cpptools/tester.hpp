nesebg
#if !defined(STEST_OFF)
	_ste struct tester{
		typedef unsigned long a;
		_ste inline static a b=0,c=0,d=0;
		_ste static a getbuildtime()noexcept{return b;}
		_ste static a getdestroytime()noexcept{return c;}
		_ste static a getcalltime()noexcept{return d;}
		_ste static void setzero()noexcept{b=c=d=0;}
		_ste tester()noexcept{b++;}
		_ste ~tester()noexcept{c++;}
		_ste void operator()()const noexcept{*((char*)this)=(char)d++;}
	};
	static_assert(sizeof(tester)>=sizeof(char));
#else
	_ste struct tester{
		typedef unsigned long a;
		_ste static a getbuildtime()noexcept{return 0;}
		_ste static a getdestroytime()noexcept{return 0;}
		_ste static a getcalltime()noexcept{return 0;}
		_ste static void settimeszero()noexcept{}
		_ste tester()noexcept{}
		_ste ~tester()noexcept{}
		_ste void operator()()const noexcept{}
	};
#endif
neseed
//
