#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i,j,k,n;
    float A[20][20],L[20][20],U[20][20],x[20],B[20],y[20],c,s=0.0;
    printf("Enter order of matrix- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {  for(j=1;j<=n;j++)
        {    printf("Enter A[%d][%d]: ",i,j);
            scanf("%f",&A[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {   printf("Enter B[%d]: ",i);
        scanf("%f",&B[i]);
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   if(i=j)
            {   L[i][j]=1;
            }
            else L[i][j]=0;
        }
    }    
    for(j=1;j<=n;j++)
    {   for(i=1;i<=n;i++)
        {   if(i>j)
            {   c=A[i][j]/A[j][j];
                L[i][j]=c;
                for(k=1;k<=n+1;k++)
                {   A[i][k]=A[i][k]-c*A[j][k];
                }
            } 
        }
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("%f\n",A[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   U[i][j]=A[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("U%f ",U[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("L%f ",L[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {   s=0;
        for(j=1;j<=i;j++)
        {   s=s+y[j]*L[i][j];
        }
        y[i]=(B[i]-s);
    }
    for(i=1;i<=n;i++)
    {   printf("y[%d]=%f\n",i,y[i]);
    }
    for(i=n;i>=1;i--)
    {   s=0;
        for(j=i;j<=n;j++)
        {   s=s+x[j]*U[i][j];
        }
        x[i]=(y[i]-s)/U[i][i];
        printf("x[i]=%f\n",x[i]);
    }
    
    return (0);
}


