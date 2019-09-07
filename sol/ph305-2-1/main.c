#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i=1,j=1,k,n;
    double A[20][20],x[20],B[20],a,b,c,s=0.0,I[20][20];
  /*FILE *fp;
    fp = fopen("a1.txt","r");
    char e;
    while(e!=EOF)
    {   e= getc(fp);
        if(e == '\n')
        {   i++;
            j=1;
        }
        fscanf(fp,"%lf",&A[i][j]);
        j++;
    }
    fclose(fp);
    n=i;*/
    printf("Enter order of matrix- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {  for(j=1;j<=n+1;j++)
       {printf("Enter A[%d][%d]: ",i,j);
       scanf("%f",&A[i][j]);
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
                for(k=1;k<=n+1;k++)
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
                for(k=1;k<=n+1;k++)
                {   A[i][k]=A[i][k]-c*A[j][k];
                    I[i][k]=I[i][k]-c*I[j][k];
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {   b=A[i][i];
        A[i][n+1]=A[i][n+1]/b;
        A[i][i]=1;
        for(j=1;j<=n;j++)
        {   I[i][j]=I[i][j]/b;
        }
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   printf("%lf ",I[i][j]);
        }   
        printf("\n");
    }  
    for(i=n;i>=1;i--)
    {   x[i]=A[i][n+1]/A[i][i];
        printf("x%d = %lf\n",i,x[i]);
    }    
    return (0);
}



