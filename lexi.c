#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char identifier[100][50],keyword[100][50],operator_list[6];
int i_count=0, k_count=0,o_count=0,i_flag=0,opera[6];
int isKeyword(char buffer[]){
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int i, flag = 0;
    
    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    
    return flag;
}
 
int main(){
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;
    int i,j=0;
    
    fp = fopen("program.txt","r");
    
    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }
    
    while((ch = fgetc(fp)) != EOF){
           for(i = 0; i < 6; ++i){
               if(ch == operators[i])
               {
                   opera[o_count]=ch;
                   o_count++;
               }
           }
           
           if(isalnum(ch)){
               buffer[j++] = ch;
           }
           else if((ch == ' ' || ch == '\n') && (j != 0)){
                   buffer[j] = '\0';
                   j = 0;
                                      
           if(isKeyword(buffer) == 1)
           {
		    strcpy(keyword[k_count],buffer);
		    k_count++;
	     }
	     else
           {
	 		for(i=0;i<i_count;i++)
			{
                       if(strcmp(identifier[i],buffer)==0)
                        {                              				      					i_flag=1;                         
                        }
                   }
                   if(i_flag==0)
                   {
                                                            
                       strcpy(identifier[i_count],buffer);
			     i_count++;
                                                
                   }
			
		}
        }
           
    }
	printf("\n__________________________\n");
	printf("           Keywords          ");
	printf("\n__________________________\n");
	for(i=0;i<k_count;i++)
	{
		printf("\t%d\t%s\n",i,keyword[i]);
	}
	
	
	printf("\n__________________________\n");
	printf("           Identifiers          ");
	printf("\n__________________________\n");
	for(i=0;i<i_count;i++)
	{
		printf("\t%d\t%s\n",i,identifier[i]);
	}
		printf("\n__________________________\n");
	printf("           Operator          ");
	printf("\n__________________________\n");
	for(i=0;i<o_count;i++)
	{
		printf("\t%d\t%c\n",i,opera[i]);
	}
	
    
    fclose(fp);
    
    return 0;
}

/* ######################   OUTPUT   ########################
program.txt
________________________________

void main()
{
int a, b, c;
c= a+ b+ c;
}

____________________________________


amrut@amrut-HP-Pro-3330-SFF:~/vish$ gcc lexi.c
amrut@amrut-HP-Pro-3330-SFF:~/vish$ ./a.out

__________________________
           Keywords          
__________________________
	0	void
	1	int

__________________________
           Identifiers          
__________________________
	0	main
	1	a
	2	b
	3	c

__________________________
           Operator          
__________________________
	0	=
	1	+
	2	+
amrut@amrut-HP-Pro-3330-SFF:~/vish$ 

*/
