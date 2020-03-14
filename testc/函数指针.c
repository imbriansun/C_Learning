/* 实现对用户输入的字符串进行处理再输出 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char * s_gets (char * st, int n);
char showmenu (void);
void eatline (void);		// 清理行输入
void show (void (*fp)(char*), char * str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);		//大小写转置
void Dummy(char *);		//不更改字符串

int main(void)
{
	/* 声明变量 */

	char line[LEN];
	char copy[LEN];
	char choice;
	void (*str_func)(char *);	//str_func指针将会指向一个处理字符串的函数，这个函数的形参是char*，返回值为void


	/* 主功能 */

	puts("Enter a string or enter a empty line to quit.");
	while( s_gets(line, LEN) != NULL && line[0] != '\0')
	{

		while((choice = showmenu()) != 'n')
		{
			switch(choice)
			{
				case 'u': str_func = ToUpper;	break;
				case 'l': str_func = ToLower;	break;
				case 't': str_func = Transpose;	break;
				case 'o': str_func = Dummy;	break;
			}

			strcpy(copy, line);

			show(str_func, copy);

		}

		puts("Enter a string or enter a empty line to quit.");

	}

	puts("Bye~");

	return 0;
}


char * s_gets (char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if(find)
			*find='\0';
		else
			while(getchar() != '\n')
				continue;
	}

	return ret_val;
}


char showmenu (void)
{
	char ans;
	puts("Enter menu choice:");
	puts("u) uppercase	l) lowercase");
	puts("t) transposed case	o) origin case");
	puts("n) next string");
	ans=getchar();
	ans=tolower(ans);
	eatline();
	while(strchr("ulton",ans) == NULL)
	{
		puts("Please enter u l t o n:");
		ans=tolower(getchar());
		eatline();
	}

	return ans;
}	


void eatline (void)
{
	while(getchar() != '\n')
		continue;
}


void show (void (*fp)(char*), char * str)
{
	(*fp)(str);
	puts(str);
}


void ToUpper(char * str)
{
	while(*str)
	{
		*str=toupper(*str);
		str++;
	}
}


void ToLower(char * str)
{
	while(*str)
	{
		*str = tolower(*str);
		str++;
	}
}


void Transpose(char * str)
{
	while (*str)
	{
		if(isupper(*str))
		{
			*str = tolower(*str);
			str++;
		}
		else
		{
			*str = toupper(*str);
			str++;
		}
	}
}


void Dummy(char * str) {	}

