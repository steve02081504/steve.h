//common.h
//
#if !defined(STEVE_H_TEST)
	#line 1 "????"
#endif
//
#if defined(ST_FOPENF)&&!defined(ST_FOPENF_ED)||defined(ST_ALL)
	#define ST_FOPENF_ED
	#include stearg
	#include stelib
	#include steio
	nesebg
	#if defined(__GNUC__)
	_ste FILE*fopenf(const char*mmod,const char*filename,...)__attribute__((format(printf,2,3)));
	#endif
	_ste FILE*fopenf(const char*mmod,const char*filename,...)
	{
		usingstd
		char*a=(char*)0;
		unsigned long b=ST_TBUFSIZE/2;
		int c;
a:		b*=2;
		a=(char*)realloc(a,b*sizeof(char));
		va_list argptr;
		va_start(argptr,filename);
		c=vsnprintf(a,b,filename,argptr);
		va_end(argptr);
		if(c<0)goto a;
		FILE*d=fopen(a,mmod);
		free(a);
		return d;
	} 
	neseed
#endif
#undef ST_FOPENF
//
#if defined(ST_FOPENF)&&!defined(ST_SYSTEMF_ED)||defined(ST_ALL)
	#define ST_SYSTEMF_ED
	#include stelib
	#include stearg
	#include steio
	nesebg
	#if defined(__GNUC__)
	_ste int systemf(const char*commd,...)__attribute__((format(printf,1,2)));
	#endif
	_ste int systemf(const char*commd,...)
	{
		usingstd
		char*a=(char*)0;
		unsigned long b=ST_TBUFSIZE/2;
		int c;
a:		b*=2;
		a=(char*)realloc(a,b*sizeof(char));
		va_list argptr;
		va_start(argptr,commd);
		c=vsnprintf(a,b,commd,argptr);
		va_end(argptr);
		if(c<0)goto a;
		c=system(a);
		free(a);
		return c; 
	}
	neseed
#endif
#undef ST_SYSTEMF
//
#if defined(ST_COPY)&&!defined(ST_COPY_ED)||defined(ST_ALL)
	#define ST_COPY_ED
	#include steio
	#include cocpfio
	nesebg
	_ste stbool stcopy(const char*form,const char*to)
	{
		#if ST_CPP
			using namespace std;
			ifstream a(to,ios_base::in|ios_base::binary);
			ofstream b(form,ios_base::out|ios_base::trunc|ios_base::binary);
			if(a||b)
				return true;
			b<<a.rdbuf(); 
			a.close();
			b.close();
			return false;
		#else
			FILE *a,*b;  
			a=fopen(to,"wb");
			b=fopen(form,"rb");
			if((!a)||(!b))
				return 1;
			char buf[1024];
			unsigned c;
			while((c=fread(buf,sizeof(unsigned char),1024,b))!=0)
				fwrite(buf,sizeof(unsigned char),c,a);
			if((!fclose(a))||(!fclose(b)))
				return 0;
			return 1;
		#endif
	}
	neseed
#endif
#undef ST_COPY
//
#if defined(ST_FILEPART)&&!defined(ST_FILEPART_ED)||defined(ST_ALL)
	#define ST_FILEPART_ED
	#include cocpio
	#include estring
	#include cppstring
	nesebg
	_ste unsigned long fpartfound(stcocp_(FILE*fp,std::istream&is),const char*flag)
	{
		usingstd
		unsigned a=strlen(flag),b=0;
		char c;
		unsigned long d=0;
		while(b!=a&&stcocp((c=getc(fp))!=EOF,is.get(c)))
		{
			if(c!=flag[b++])
				b=0;
			d++;
		}
		return d;
	}
	_ste unsigned long fpartfree(stcocp_(FILE*,std::istream&)part,stcocp_(FILE*,std::ostream&)to,const char*end)
	{
		usingstd
		unsigned a=strlen(end),b=0;
		char c;
		unsigned long d=0;
		while(b!=a&&stcocp((c=getc(part))!=EOF,part.get(c)))
		{
			if(c!=end[b])
			{
				if(b)
				{
					stcocp(fwrite(end,sizeof(char),b,to),to.write(end,sizeof(char)*b));
					b=0;
				}
				stcocp(putc((int)c,to),to.put(c));
			}
			else
				b++;
			d++;
		}
		return d;
	}
	_ste inline char**geneflag(unsigned n,unsigned flaglong,const int*seeds,char**flags,int(*rand_)(int))
	{
		usingstd
		unsigned a=n;
		int*b[2]=
		{
			stcocp((int*)malloc(n*sizeof(int)),new int[n]),
			stcocp((int*)malloc(n*sizeof(int)),new int[n])
		};
		stbool c;
		while(a--)
		{
			flags[a][flaglong]='\0';
			b[c][a]=rand_(seeds[a]);
		}
		while(flaglong--)
		{
			a=n;
			while(a--)
				flags[a][flaglong]=(char)(b[!c][(a?a:n)-1]=rand_(b[c][a]));
			c=!c;
		}
		stcocp(free((void*)b[0]),delete [] b[0]);
		stcocp(free((void*)b[1]),delete [] b[1]);
		return flags;
	}
	#if ST_CPP
		_ste inline std::string*geneflag(unsigned n,unsigned flaglong,const int*seeds,std::string*flags,int(*rand_)(int))
		{
			usingstd
			unsigned a=n;
			int*b[2]=
			{
				new int[n],
				new int[n]
			};
			bool c;
			while(a--)
			{
				flags[a].resize(flaglong-1);
				b[c][a]=rand_(seeds[a]);
			}
			while(flaglong--)
			{
				a=n;
				while(a--)
					flags[a][flaglong]=(char)(b[!c][(a?a:n)-1]=rand_(b[c][a]));
				c=!c;
			}
			delete [] b[0];
			delete [] b[1];
			return flags;
		}
	#endif
	neseed
#endif
#undef ST_FILEPART
//
#if defined(ST_INTPSF)&&!defined(ST_INTPSF_ED)||defined(ST_ALL)
	#define ST_INTPSF_ED
	#include estring
	#include cppstring
	#include emlc
	#include emath
	nesebg
	_ste char*intpf(long long aint,unsigned long long n,char*str,const char*table)
	{
		usingstd
		long long a=strlen(table)-2;
		const char*b=table+2;
		stbool c=0;
		char*d=stcocp((char*)malloc(n*sizeof(char)),new char[n]);
		char*e=d+n-1;
		if(a<0||!n||!d||a>((unsigned char)-1))
			goto a;
		*(e--)=0;
		if(aint<0)
		{
			c=1;
			aint=-aint;
		}
		do
		{
			*(e--)=b[aint%a];
			if(d==e)
			{
	a:			stcocp(free((void*)d),delete[]d);
				return((*str=0),str);
			}
			aint/=a;
		}
		while(aint);
		*e=table[c];
		a=0;
		while(*e)
			str[a++]=*(e++);
		stcocp(free((void*)d),delete[]d);
		return((str[a]=0),str);
	}
	#if ST_CPP
		_ste std::string&intpf(long long aint,unsigned long long n,std::string&str,const char*table)
		{
			usingstd
			long long a=strlen(table)-2;
			const char*b=table+2;
			bool c=0;
			char*d=new char[n];
			char*e=d+n-1;
			if(a<0||!n||!d||a>((unsigned char)-1))
				goto a;
			*(e--)=0;
			str.resize(0);
			if(aint<0)
			{
				c=1;
				aint=-aint;
			}
			do
			{
				*(e--)=b[aint%a];
				if(d==e)
				{
		a:			delete[]d;
					return str;
				}
				aint/=a;
			}
			while(aint);
			*e=table[c];
			a=0;
			str.resize(d+n-e-1);
			while(*e)
				str[a++]=*(e++);
			delete[]d;
			return str;
		}
	#endif
	double intsf(const char*scanthis,const char*table)
	{
		usingstd
		double a=0;
		const char*b=table+2;
		long long c;
		const char*d=scanthis+1;
		long long e=0;
		if(((c=strlen(table)-2)<1)||strlen(scanthis)<2)a:return NAN;
		while(*d)
		{
			a*=c;
			while(*d!=b[e++])if(!b[e-1])goto a;
			e--;
			a+=e;
			e=0;
			d++;
		};
		if(*scanthis==table[0])return a;
		else if(*scanthis==table[1])return -a;
		goto a;
	}
	neseed
#endif
#undef ST_INTPSF
//
#if defined(ST_MLC)&&!defined(ST_MLC_ED)||defined(ST_ALL)
	#define ST_MLC_ED
	#include emlc
	#if ST_CPP
		#define stmlc(n,type) (((type)*)malloc((n)*sizeof(type)))
		#define stfre(ptr) tree((void*)(ptr))
	#else
		#define stmlc(n,type) (new type[n])
		#define stfre(ptr) (delete[]ptr)
	#endif
#endif
#undef ST_MLC
//
