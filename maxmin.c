
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int A[10],n,max,min;
float comp;
void minmax(int,int);
int main()
  {
int i;
printf("enter list size:-");
scanf("%d",&n);
for( i=0;i<n;i++)
      {
printf("\n Enter Element %d:",i);
scanf("%d",&A[i]);
      }

max=A[0];
min=A[0];
minmax(0,n-1);

printf("\n\n Maximum Number:- %d",max);
printf("\n\n Minimun Number:- %d\n",min);
comp=((3*n)/2)-2;
printf("Time complexity of the given algorithm is=%f\n",ceil(comp)); 
return 0;
   }
void minmax(int i, int j)
   {
int max1, min1, mid;

if (i==j)   
  {
max = A[i];
min = A[i];
  }
else if(i == j-1)  
  {
if (A[i] < A[j])
    {
min = A[i];
max = A[j];
    }
else
    {
min = A[j];
max = A[i];
    }
 }
else    
 {
mid = (i + j)/2;
minmax(i,mid);    
max1 = max;
min1 = min;
minmax(mid + 1, j);   
if (max < max1)
   {
max = max1;
   }
if (min > min1)
   {
min = min1;
   }
  }
 }

