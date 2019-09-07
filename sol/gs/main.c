#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i,j,k,n,w,a,mi,c=0;
    double A[20][20],b[20],x[20] = {1},s,d,e;
    //printf("Enter order of matrix- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n+1;j++)
        {   //printf("Enter A[%d][%d]: ",i,j);
            if(j <= n)
            {   scanf("%lf",&A[i][j]);
            }
            if(j > n)
            {   scanf("%lf",&b[i]);
            }
        }
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("%lf ",A[i][j]);
        }
        printf("\n");
    }
    for(a=0;a<=50;a++)
    {   c=0;
        for(i=1;i<=n;i++)
        {   s=0;
            for(j=1;j<=n;j++)
            {   s = s + A[i][j] * x[j];
            }
            s = s - A[i][i] * x[i];
            e = x[i];
            x[i] = (b[i] - s)/A[i][i];
            printf("x[%d]%d= %lf\n",i,a,x[i]);
            d = x[i] - e;
            if(d > 0.000001 || d < -0.000001)
            {   c = 1;
            }
            printf("c%d=%d\n",i,c);
        }
        if(c == 0)
            break;
    }
    printf("%d\n",a);
    for(i=1;i<=n;i++)
    {   printf("x[%d]= %lf\n",i,x[i]);
    }
    return(0);
}