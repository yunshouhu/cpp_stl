#include <stdio.h>
#include <string.h>
#include <stdlib.h>


////////////////////memcpy/////////////////////////
void * __cdecl my_memcpy(void * dst,const void * src,size_t count)
{
	void * ret = dst;

	while (count--) {
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}
	return(ret);
}
/////////////////////memset/////////////////
void * __cdecl my_memset(void *dst,int val,size_t count)
{
	void *start = dst;
	while (count--) {
		*(char *)dst = (char)val;
		dst = (char *)dst + 1;
	}
	return(start);
}
///////////////////////strcat//////////////////
char * __cdecl my_strcat2(char * dst,const char * src)
{
	char * cp = dst;
	while (*cp)
		cp++;                   /* find end of dst */
	while (*cp++ = *src++);       /* Copy src to end of dst */
	return(dst);                  /* return dst */
}
///////////////////////strcpy//////////////////////
char * __cdecl my_strcpy2(char * dst, const char * src)
{
	char * cp = dst;

	while (*cp++ = *src++)
		;               /* Copy src over dst */
	return(dst);
}
/////////////////////////strchr////////////////////////////
char * __cdecl my_strchr(const char * string,int ch)
{
	while (*string && *string != (char)ch)
		string++;
	if (*string == (char)ch)
		return((char *)string);
	return(NULL);
}
///////////////////////strcmp//////////////////////////
int __cdecl my_strcmp(const char * src,const char * dst)
{
	int ret = 0;

	while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
		++src, ++dst;

	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;

	return(ret);
}
///////////////////////strlen/////////////////////////
size_t __cdecl my_strlen2(const char * str)
{
	const char *eos = str;
	while (*eos++);
	return((int)(eos - str - 1));
}
//////////////////////strncat//////////////////////////
char * __cdecl my_strncat(char * front,const char * back,size_t count)
{
	char *start = front;
	while (*front++);
	front--;
	while (count--)
		if (!(*front++ = *back++))
			return(start);

	*front = '\0';
	return(start);
}
/////////////////////////strncmp//////////////////////////
int __cdecl my_strncmp(const char * first,const char * last,size_t count)
{
	if (!count)
		return(0);

	while (--count && *first && *first == *last)
	{
		first++;
		last++;
	}

	return(*(unsigned char *)first - *(unsigned char *)last);
}
//////////////////////////strncpy/////////////////////////////
char * __cdecl my_strncpy(char * dest,const char * source,size_t count)
{
	char *start = dest;

	while (count && (*dest++ = *source++))    /* copy string */
		count--;

	if (count)                              /* pad out with zeroes */
		while (--count)
			*dest++ = '\0';

	return(start);
}
////////////////////////////strnset//////////////////////////////
char * __cdecl my_strnset(char * string,int val,size_t count)
{
	char *start = string;

	while (count-- && *string)
		*string++ = (char)val;

	return(start);
}
///////////////////////////strset//////////////////////
char * __cdecl my_strset(char * string,int val)
{
	char *start = string;

	while (*string)
		*string++ = (char)val;

	return(start);
}
////////////////////////strrchr///////////////////////
char * __cdecl my_strrchr(const char * string,int ch)
{
	char *start = (char *)string;

	while (*string++)                       /* find end of string */
		;
	/* search towards front */
	while (--string != start && *string != (char)ch)
		;
	if (*string == (char)ch)                /* char found ? */
		return((char *)string);

	return(NULL);
}
//////////////////////////strrev////////////////////////
char * __cdecl my_strrev(char * string)
{
	char *start = string;
	char *left = string;
	char ch;
	while (*string++)                 /* find end of string */
		;
	string -= 2;

	while (left < string)
	{
		ch = *left;
		*left++ = *string;
		*string-- = ch;
	}
	return(start);
}
////////////////////////////strstr////////////////////////////
char * __cdecl my_strstr(const char * str1,const char * str2)
{
	char *cp = (char *)str1;
	char *s1, *s2;

	if (!*str2)
		return((char *)str1);

	while (*cp)
	{
		s1 = cp;
		s2 = (char *)str2;

		while (*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;

		if (!*s2)
			return(cp);

		cp++;
	}
	return(NULL);
}

//参考glibc源码glibc-2.0.6\sysdeps\generic
char* __cdecl my_strcpy(char *dest, const char *src)
{
	char c;
	char *s = (char *)src;
	const int off = dest - src - 1;
	do
	{
		c = *s++;
		s[off] = c;
	} while (c != '\0');

	return dest;
}

/* Append SRC on the end of DEST.  */
char* __cdecl my_strcat(char *dest, const char *src)
{
	register char *s1 = dest;
	register const char *s2 = src;
	char c;
	do
		c = *s1++;
	while (c != '\0');

	s1 -= 2;
	do
	{
		c = *s2++;
		*++s1 = c;
	} while (c != '\0');
	return dest;
}
#define PTR  char*

//由src所指内存区域复制不多于count个字节到dest所指内存区域，如果遇到字符c则停止复制。
//返回值：如果c没有被复制，则返回NULL，否则，返回字符c 后面紧挨一个字符位置的指针。
PTR __cdecl my_memccpy(PTR dest, const PTR src, int c, size_t n)
{
	register const char *s = src;
	register char *d = dest;
	register const int x = (unsigned char)c;
	register size_t i = n;

	while (i-- > 0)
		if ((*d++ = *s++) == x)
			return d;
	return NULL;
}

size_t __cdecl my_strlen(const  char *str)
{
	const char *cp = str;
	while (*cp++)
	{
		
	};
	return (cp - str - 1);
}



static char *olds = NULL;

/* Parse S into tokens separated by characters in DELIM.
If S is NULL, the last string strtok() was called with isused.
*/
//查找指定字符之前的子串 
char* __cdecl my_strtok(char *s,const char *delim)
{
	char *token;
	if (s == NULL)
		s = olds;
	/* Scan leading delimiters.  */
	s += strspn(s, delim);
	if (*s == '\0')
		return NULL;

	/* Find the end of the token.  */
	token = s;
	s = strpbrk(token, delim);
	if (s == NULL)
		/* This token finishes the string.  */
		olds = strchr(token, '\0');
	else
	{
		/* Terminate the token and make OLDS point past it.  */
		*s = '\0';
		olds = s + 1;
	}
	return token;
}

/* 将字符串转换成浮点数 */
double __cdecl my_atof(const char *nptr)
{
	return strtod(nptr, (char **)NULL);
}
/* 将字符串转换成整数   */
int __cdecl my_atoi(const char *nptr)
{
	return (int)strtol(nptr, (char **)NULL, 10);
}
/*将字符串转换成长整型数 */
long __cdecl my_atol(const char *nptr)
{
	return strtol(nptr, (char **)NULL, 10);
}
/*比较内存内容 */





//android bionic glibc
int main()
{
	char data[1024];
	my_strcpy(data, "hehe");
	printf("%s\n", data);
	my_strcat(data, "来自中国1024");
	printf("%s\n", data);
	char hehe[1024];
	my_memset(hehe, 0, sizeof(hehe));
	my_memccpy(hehe, data, '1', my_strlen(data));
	printf("%s\n", hehe);
	printf("%d\n", my_strlen(hehe));

	char s[] = "-abc-=-def";
	char *x = my_strtok(s, "-");		// x = "abc"
	printf("%s\n", x);
	x = my_strtok(NULL, "-=");		// x = "def"
	printf("%s\n", x);
	x = my_strtok(NULL, "=");		// x = NULL
	printf("%s\n", x);

	printf("%f %d %ld\n", my_atof("1.245"), my_atoi("1024"), my_atol("152.63"));

	return 0;
}





