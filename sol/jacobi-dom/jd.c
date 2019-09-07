#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i,j,k,n,w,a,c=0,m=1,check = 1,l;
    double A[20][20],b[20],x[20] = {1},s,d,e,sum,dom[20],xa[20];
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
    //making matrix fucking dominant
    for(i=1;i<=n;i++)
    {   sum = 0;
        for(j=1;j<=n;j++)
        {   if(i == j)
            {   continue;
            }
            else sum = sum + abs(A[i][j]);
        }
        if(abs(A[i][i] >= sum))
        {   //printf("row%d is dd\n",i);
            check = check*1;
            dom[m]=i;
            m++;
        }
        else
        {   printf("matrix is not dd");
        check=check*0;
        }
    }
    if(check == 0)
    {   for(i=1;i<=n;i++)
        {   sum = 0;
            for(j=1;j<=n;j++)
            {   if(i == j)
                {   continue;
                }
                else sum = sum + abs(A[i][j]);
            }
            if(abs(A[i][i] >= sum))
            {   //printf("row%d is dd\n",i);
                check=check*1;
            }
            else
            {   c = abs(A[i][1]);
                l = i;
                for(k=2;k<=n;k++)
                {   if(c < abs(A[i][k]))
                    {   c = abs(A[i][k]);
                        l=k;
                    }
                }
                for(k=1;k<=n;k++)
                {   if(l == dom[k])
                    {   printf("impossible");
                        return 0;
                    }
                }
                if(c == A[i][i])
                {   printf("impossible");
                    return 0;
                }
                else
                {   for(k=1;k<=n;k++)
                    {   c = A[i][k];
                        w = b[i];
                        A[i][k] = A[l][k];
                        b[i] = b[l];
                        A[l][k] = c;
                        b[l] = w;
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("%lf ",A[i][j]);
        }
        printf("\n");
    }
    //applying jacobi
    for(a=0;a<=50;a++)
    {   c=0;
        for(i=1;i<=n;i++)
        {   x[i] = xa[i];
            s=0;
            for(j=1;j<=n;j++)
            {   s = s + A[i][j] * x[j];
            }
            s = s - A[i][i] * x[i];
            xa[i] = (b[i] - s)/A[i][i];
            printf("x[%d]%d= %lf\n",i,a,xa[i]);
        }
        printf("\n");
        for(k=1;k<=n;k++)
        {   d = (xa[k] - x[k]);
            if(d > 0.000001 || d < -0.000001)
            {   c = 1;
            }
            //printf("c%d=%d\n",k,c);
            
        }
        if(c == 0)
            break;
    }
    printf("%d\n",a);
    for(i=1;i<=n;i++)
    {   printf("x[%d]= %lf\n",i,xa[i]);
    }
    return 0;
}    