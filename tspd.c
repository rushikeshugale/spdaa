#include<stdio.h>

int DistMat[10][10],visitedcity[10],n,cost=0,
initialvertex=0;
void getDistMat();

int main()
 {
   getDistMat();
   printf("\n\nOptimal path is:->:\n");
   mincost(initialvertex);
   printf("\n\nMinimumcost is %d\n",cost);
   return 0;
  }

  void getDistMat()
   {
    int i,j;
     printf("Enter no of cities:->");
     scanf("%d",&n);
     printf("enter distnce matrix->\n");
     for(i=0;i<n;i++)
     {
      for(j=0;j<n;j++)
        {
         scanf("%d",&DistMat[i][j]);
        }
        visitedcity[i]=0;
      }

  printf("\n\ncost matrix:->");
   for(i=0;i<n;i++)
       {
         printf("\n");
        for(j=0;j<n;j++)
           {
             printf("\t%d",DistMat[i][j]);
           }
        }
    }

int mincost(int city)
  {
    int i,ncity;
    visitedcity[city]=1;
    printf("%d-->",city+1);
    ncity=least(city);
    if(ncity==999)
     {
      ncity=0;
      printf("%d",ncity+1);
       cost+=DistMat[city][ncity];
       return;
     }
  mincost(ncity);
  }

 int least(int c)
  {
   int i,nc=999;
   int min=999,kmin;
    for(i=0;i<n;i++)
      {
        if((DistMat[c][i]!=0)&&(visitedcity[i]==0))
            if(DistMat[c][i]+DistMat[c][i]<min)
             {
               min=DistMat[i][0]+DistMat[c][i];
     kmin=DistMat[c][i];
     nc=i;
           }
       }

   if(min!=999)
       cost+=kmin;

    return nc;
    
  }
              
