#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i=1,j=1,k,n,cnt=0;
    double A[20][20],x[20],z[20],a,b,c,s=0.0,I[20][20],t[20],f,tol;
    /*printf("\nEnter the order of matrix:");
    scanf("%d",&n);
    printf("\nEnter matrix elements row-wise\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("A[%d][%d]=",i,j);
            scanf("%f",&A[i][j]);
        }
    }*/
    n = 10;
    for(i=1; i<=n; i++)
    {   
        for(j=1; j<=n; j++)
        {
            if(i == j)
            {   A[i][j] = 4;
            }
            if(j == i+1 || j == i-1)
            {   A[i][j] = 2;
            }
            if(j == i+2 || j == i-2)
            {   A[i][j] = 1;
            }
        }
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   if(i==j)
            {   I[i][j]=1;
            }
            else I[i][j]=0;
        }
    }
    for (j=1;j<=n;j++)
    {   for(i=1;i<=n;i++)
        {   if(i>j)
            {   a=A[i][j]/A[j][j];
                for(k=1;k<=n;k++)
                {   A[i][k]=A[i][k]-a*A[j][k];
                    I[i][k]=I[i][k]-a*I[j][k];
                }
            }
        }
    }
    for (j=n;j>=1;j--)
    {   for(i=n;i>=1;i--)
        {   if(i<j)
            {   c=A[i][j]/A[j][j];
                for(k=1;k<=n;k++)
                {   A[i][k]=A[i][k]-c*A[j][k];
                    I[i][k]=I[i][k]-c*I[j][k];
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {   b=A[i][i];
        //A[i][n+1]=A[i][n+1]/b;
        A[i][i]=1;
        for(j=1;j<=n;j++)
        {   I[i][j]=I[i][j]/b;
        }
    }
    printf("\n\n");
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("%lf ",I[i][j]);
        }   
        printf("\n");
    }
    for(i=1; i<=n; i++)
    {
        x[i] = 1;
    }
    do
    {   cnt++;
        for(i=1; i<=n; i++)
        {
            z[i]=0;
            for(j=1; j<=n; j++)
            {
                z[i]=z[i]+I[i][j]*x[j];
            }
        }
        k=1;
        f=fabs(z[1]);
        for(i=2; i<=n; i++)
        {
            if((fabs(z[i]))>f)
                f=fabs(z[i]);
                k=i;
        }
        f=z[k];
        for(i=1; i<=n; i++)
        {
            z[i]=z[i]/f;
        }
        printf("\niter %d = %f",cnt,f);
        for(i=1; i<=n; i++)
        {
            t[i]=0;
            t[i]=fabs((fabs(z[i]))-(fabs(x[i])));
        }
        tol=t[1];
        for(i=2; i<=n; i++)
        {
            if(t[i]>tol)
                tol=t[i];
        }
        for(i=1; i<=n; i++)
        {
            x[i]=z[i];
        }
    }
    while(tol>0.0000001);
    printf("\n Eigen value is %f",1/f);
    printf("\n\nEigen vector is :\n");
    for(i=1; i<=n; i++)
    {
        printf("%f\t",z[i]);
    }

    return 0;
}    
