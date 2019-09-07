#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i=1,j=1,k,n,cnt=0;
    double A[20][20],x[20],z[20],a,b,c,s=0.0,I[20][20],t[20],f,tol;
    printf("Enter order of matrix- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {  for(j=1;j<=n;j++)
       {printf("Enter A[%d][%d]: ",i,j);
       scanf("%lf",&A[i][j]);
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
    for (j=3;j>=1;j--)
    {   for(i=3;i>=1;i--)
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
        printf("\n\n\n");
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
    return (0);
}



