//sio--unfinsished
typedef stworl_(HANDLE,int)fp;
typedef struct
{
	fp fptr;//描述符
	char*buf;//缓冲区
	char bp;//bool 位移，以及属性
	size_t cp;//char 位移 
	void(*frebuf)(void*);
}sfile;
inline sfile*sbopen(fp a);
inline fp sbbopen(const char*a,int cfg);
inline void sbbclose(fp a);
inline size_t sbread(sfile*file,void*buf,size_t size);
#define UD_SIZE 2048//默认缓冲区大小 
sfile*sopen(const char*name,int cfg)
{
	sfile*a=sbopen(sbbopen(name,cfg));
	if(a){
		a->buf=malloc(UD_SIZE);
		a->frebuf=free;
	}
};
sfile*sclose(sfile*afp)
{
	sbbclose(afp->fptr);
	free(afp->buf);
	free(afp);
};
size_t sread(sfile*afp,size_t asize,size_t num);
size_t swrite(sfile*afp,size_t asize,size_t num);
bool sreadbool(sfile*afp);
void swritebool(sfile*afp,bool a);
//
