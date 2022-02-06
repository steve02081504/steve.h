nesebg
#if !defined(STEST_OFF)
	_ste struct stest_eventer{
		_ste stest_eventer(const wchar_t*eventname)nexc{stest_entryevent(eventname);}
		_ste ~stest_eventer()nexc{stest_exitevent();}
	};
#else
	_ste struct stest_eventer{
		_ste stest_eventer(const wchar_t*eventname)nexc;
	};
#endif
neseed
//
