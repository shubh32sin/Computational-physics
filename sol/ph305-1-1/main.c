/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i,j,k,n;
    float A[20][20],x[20],c,s=0.0;
    printf("Enter order of matrix- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {  for(j=1;j<=n+1;j++)
       {printf("Enter A[%d][%d]: ",i,j);
       scanf("%f",&A[i][j]);
       }
    }
    for(j=1;j<=n;j++)
    {  for(i=1;i<=n;i++)
       {  if(i>j)
          {c=A[i][j]/A[j][j];
          for(k=1;k<=n+1;k++)
             {A[i][k]=A[i][k]-c*A[j][k];
             }
          } 
       }
    }
    for(i=n;i>=1;i--)
    {  s=0; 
       for(j=i+1;j<=n;j++)
       {  s=s+x[j]*A[i][j];
       }
       x[i]=(A[i][n+1]-s)/A[i][i];
       printf("x%d = %f",i,x[i]);
    }
    return (0);
}

