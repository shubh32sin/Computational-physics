#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i,j,k,n;
    float A[20][20],L[20][20] = {0},l[20][20],M[20][20],c,s;
    printf("Enter order of matrix- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {  for(j=1;j<=i;j++)
        {printf("Enter A[%d][%d]: ",i,j);
         scanf("%f",&A[i][j]);
         A[j][i] = A[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("%f ",A[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   s=0;
            if(i == j)
            {   for(k=1;k<=j-1;k++)
                {   s += L[j][k]*L[j][k];
                }
                L[i][j]=sqrt(A[i][j]-s);
            }
            if(i > j)
            {   for(k=1;k<=j-1;k++)
                {   s += L[j][k]*L[i][k];
                }
                L[i][j]=(A[i][j]-s)/L[j][j];
            }
            if(i < j)
            {   L[i][j] = 0;
            }
        }
    }
    printf("Matrix L is\n");
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("%f ",L[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   l[i][j]=L[j][i];
        }
    }
    printf("Matrix L transpose is\n");
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("%f ",l[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   c=0;
            for(k=1;k<=n;k++)
            {   c += L[i][k]*l[k][j];
            }
            M[i][j]=c;
        }
    }
    printf("Matrix multiplication is\n");
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("%f ",M[i][j]);
        }
        printf("\n");
    }
    return(0);
}    
    

