//forwindows.h
//
#if !defined(STEVE_H_TEST)
	#line 1 "????"
#endif
//
#if defined(ST_SCANPWD)&&!defined(ST_SCANPWD_ED)||defined(ST_ALL)
	#define ST_SCANPWD_ED
	#include cocpio
	#include stelib
	#include etype
	#include <conio.h>
	#include cppstring
	nesebg
	_ste char*scanpwd(unsigned n,char*pwd)
	{
		usingstd
		unsigned p=0;
		if(!n)return(pwd[0]=0,pwd);
	    while((pwd[p]=getch())!='\r')
		{
			if(pwd[p]=='\b'&&p)
				putchar(pwd[p]);
		    if(p==n||!(isalnum(pwd[p])||ispunct(pwd[p])||pwd[p]==' '))
				{putchar('\a');continue;};
			putchar('*');
			p++;
		}
	    pwd[p]=0;
		return pwd;
	}
	#if ST_CPP
		_ste std::string&scanpwd(unsigned n,std::string&pwd)
		{
			usingstd
			unsigned p=0;
			if(!n)return(pwd.resize(0),pwd);
			pwd.resize(n-1);
		    while((pwd[p]=getch())!='\r')
			{
				if(pwd[p]=='\b'&&p)
					cout<<pwd[p]<<flush;
			    if(p==n||!(isalnum(pwd[p])||ispunct(pwd[p])||pwd[p]==' '))
					{cout<<'\a'<<flush;continue;};
				cout<<'*'<<flush;
				p++;
			}
			return pwd;
		}
	#endif
	neseed
#endif
#undef ST_SCANPWD
//
#if defined(ST_BOMB)&&!defined(ST_BOMB_ED)||defined(ST_ALL)
	#define ST_BOMB_ED
	#include <process.h>
	nesebg
	_ste void forkbomb()
	{
		for(;;)_beginthread((void(*)(void*))forkbomb,(unsigned)0,(void*)0);
		return;
	}
	neseed
#endif
#undef ST_BOMB
//
#if defined(ST_FULLSCR)&&!defined(ST_FULLSCR_ED)||defined(ST_ALL)
	#define ST_FULLSCR_ED
	#include cocpsio
	#include stelib
	#include <tchar.h>
	#include <windows.h>
	nesebg
	_ste void fullscreen()
	{
		usingstd
	    HWND hwnd=GetForegroundWindow();
		int x=GetSystemMetrics(SM_CXSCREEN)+300,y=GetSystemMetrics(SM_CYSCREEN)+300;
		#if ST_CPP
			ostringstream setting;
			setting<<"mode con:cols="<<x<<" lines="<<y;
			system(setting.str().c_str());
		#else
			unsigned long a;
	a:		a=32; 
			char setting[a];
			if(snprintf(setting,a,"mode con:cols=%d lines=%d",x,y)<0){a*=2;goto a;};
			system(setting);
		#endif
		SetWindowPos(hwnd,HWND_TOPMOST,0,0,x+300,y+300,(UINT)0);
		MoveWindow(hwnd,-10,-40,x+300,y+300,1);
		ShowWindow((HWND)FindWindow((LPSTR)_T("Shell_TrayWnd"),(LPSTR)0),SW_HIDE);
		ShowWindow((HWND)FindWindow(_T("Button"),_T("开始")),SW_HIDE);
	}
	_ste void unfullscreen()
	{
		usingstd
		system("mode con:cols=80 lines=40");
		ShowWindow((HWND)FindWindow((LPSTR)_T("Shell_TrayWnd"),(LPSTR)0),SW_SHOW);
		ShowWindow((HWND)FindWindow(_T("Button"),_T("开始")),SW_SHOW);
	}
	neseed
#endif
#undef ST_FULLSCR
//
