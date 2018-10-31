/* Write A C Program to Implement Recursive Dscent Parser  for given grammar
E->TE1
E1->+TE1/epislon
T->FT1
T1->*FT1/epislon
F->id
F->(E)
Reference Book:- Aho, Ulman Sethi Page No-
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int lookahead=0,stlen;
char str[10];
int flag;
void E();
void E1();
void T();
void T1();
void F();
void matchid();


int main()
{
	flag=0;
	printf("\n Enter the string");
	scanf("%s",str);
	E();
	stlen=strlen(str);
	if(stlen==lookahead && flag==0)
		printf("\n Valid String for Given Grammer");
	else
		printf("\n INValid String for Given Grammer");
}
void E()
{
	T();
	E1();
}
void T()
{
	F();
	T1();
}
void F()
{
	matchid();
}
void matchid()
{
	if(isalnum(str[lookahead]))
	{
		lookahead++;
	}
	else if(str[lookahead]=='(')
	{
		E();

		if(str[lookahead]==')')
			lookahead++;
		else
			flag=1;
	}
	else
	{
		flag=1;
	}
}

void T1()
{
	if(str[lookahead]=='*')
	{
		lookahead++;
		F();
		T1();
	}
}
void E1()
{
	if(str[lookahead]=='+')
	{
		lookahead++;
		T();
		E1();
	}
}
/***************************************

exam@sai-M52AD-M12AD-A-F-K31AD:~$ gcc rdp.c
exam@sai-M52AD-M12AD-A-F-K31AD:~$ ./a.out

 Enter the string a+b+c+d

 Valid String for Given Grammerexam@sai-M52AD-M12AD-A-F-K31AD:~$ ./a.out

 Enter the stringa*b*+c

 INValid String for Given Grammerexam@sai-M52AD-M12AD-A-F-K31AD:~$ ./a.out

 Enter the stringa*b*c

 Valid String for Given Grammerexam@sai-M52AD-M12AD-A-F-K31AD:~$ ./a.out

 Enter the stringa-b*c

 INValid String for Given Grammerexam@sai-M52AD-M12AD-A-F-K31AD:~$ 



****************************************/

