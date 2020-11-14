//ststsignal.h
//
#if !defined(STEVE_H_TEST)
	#line 1 "????"
#endif
//
#if defined(SIGHUP)
	st_signal(SIGHUP)
#endif
#if defined(SIGXCPU)
	st_signal(SIGXCPU)
#endif
#if defined(SIGXFSZ)
	st_signal(SIGXFSZ)
#endif
#if defined(SIGINT)
	st_signal(SIGINT)
#endif
#if defined(SIGPIPE)
	st_signal(SIGPIPE)
#endif
#if defined(SIGALRM)
	st_signal(SIGALRM)
#endif
#if defined(SIGTERM)
	st_signal(SIGTERM)
#endif
#if defined(SIGUSR1)
	st_signal(SIGUSR1)
#endif
#if defined(SIGUSR2)
	st_signal(SIGUSR2)
#endif
#if defined(SIGPOLL) && (!defined(SIGIO)||SIGIO!=SIGPOLL)
	st_signal(SIGPOLL)
#endif
#if defined(SIGPROF)
	st_signal(SIGPROF)
#endif
#if defined(SIGVTALRM)
	st_signal(SIGVTALRM)
#endif
#if defined(SIGSTKFLT)
	st_signal(SIGSTKFLT)
#endif
#if defined(SIGIO)
	st_signal(SIGIO)
#endif
#if defined(SIGCLD)
	st_signal(SIGCLD)
#endif
#if defined(SIGPWR)
	st_signal(SIGPWR)
#endif
#if defined(SIGINFO)
	st_signal(SIGINFO)
#endif
#if defined(SIGLOST) && (!defined(SIGPWR)||SIGPWR!=SIGLOST)
	st_signal(SIGLOST)
#endif
#if defined(SIGUNUSED)
	st_signal(SIGUNUSED)
#endif
#if defined(SIGQUIT)
	st_signal(SIGQUIT)
#endif
#if defined(SIGILL)
	st_signal(SIGILL)
#endif
#if defined(SIGTRAP)
	st_signal(SIGTRAP)
#endif
#if defined(SIGARRT)
	st_signal(SIGARRT)
#endif
#if defined(SIGBUS)
	st_signal(SIGBUS)
#endif
#if defined(SIGFPE)
	st_signal(SIGFPE)
#endif
#if defined(SIGSEGV)
	st_signal(SIGSEGV)
#endif
//
