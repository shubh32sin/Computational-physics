#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i,j,n,c=0,a;
    float A[40][40],x[40] = {1,1,1,1},z[40],t[40],f,tol;
    printf("\nEnter the order of matrix:");
    scanf("%d",&n);
    printf("\nEnter matrix elements row-wise\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("A[%d][%d]=",i,j);
            scanf("%f",&A[i][j]);
        }
    }
    do
    {   c++;
        for(i=1; i<=n; i++)
        {
            z[i]=0;
            for(j=1; j<=n; j++)
            {
                z[i]=z[i]+A[i][j]*x[j];
            }
        }
        a=1;
        f=fabs(z[1]);
        for(i=2; i<=n; i++)
        {
            if((fabs(z[i]))>f)
                f=fabs(z[i]);
                a=i;
        }
        f=z[a];
        for(i=1; i<=n; i++)
        {
            z[i]=z[i]/f;
        }
        printf("\niter %d = %f",c,f);
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
    printf("\n Eigen value is %f",f);
    printf("\n\nEigen vector is :\n");
    for(i=1; i<=n; i++)
    {
        printf("%f\t",z[i]);
    }
    return 0;
}    
