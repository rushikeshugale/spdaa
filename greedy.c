// Write a program to solve Optimal Storage on Tapes Problem using Greedy Approach
#include<stdio.h>
int i, l[10],rt[10], n, sum=0;
void optimalstorageschedule();
void sortprogs();
int main()
{
printf ("\nEnter the total number of programs : ");
scanf ("%d",&n);
printf ("Enter the program with Length : \n");
 for(i=0;i<=n-1;i++)
            {
               printf("\nProgram %d:",i+1);
               scanf("%d",&l[i]);
                            
            }
optimalstorageschedule();
return 0;
}
void optimalstorageschedule()
{
int j;
printf("original program length: ");
for(i=0;i<=n-1;i++)
	{
printf("%d\t",l[i]);
	}
sortprogs();
printf("\nsorted program length:");
for(i=0;i<=n-1;i++)
		{
printf("\t%d",l[i]);
		}

for(i=0; i<n; i++)
		{
		   for(j=0; j<=i; j++)
			{
      			sum = sum+ l[j];
 			}
		}

printf("\n\n Total Retrival Time: %d", sum);
printf("\n\nMean Retrival Time: %f\n", sum/(float)n);
}


void sortprogs()
{
int temp , j;
for(i=0;i<n-1;i++)
{
for(j=0;j<(n-i-1);j++)
{
if(l[j+1] < l[j])
{
temp = l[j];
l[j] = l[j+1];
l[j+1] = temp;
}
}
}
}

