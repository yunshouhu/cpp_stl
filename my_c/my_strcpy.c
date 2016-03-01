#include <stdio.h>
#include <string.h>

//参考glibc源码glibc-2.0.6\sysdeps\generic
char * my_strcpy (char *dest,const char *src)
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
char * my_strcat( char *dest , const char *src)
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


int main()
{	
	char data[1024];
	my_strcpy(data, "hehe");
	printf("%s\n", data);
	my_strcat(data, "来自中国1024");
	printf("%s\n", data);
	return 0;
}





