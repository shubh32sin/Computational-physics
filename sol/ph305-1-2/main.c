#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int i,j,k,n,a,b,c,p;
    float A[20][20],x[20],z,max,temp,s=0.0;
    
    printf("Enter order of matrix- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {  for(j=1;j<=n+1;j++)
       {printf("Enter A[%d][%d]: ",i,j);
       scanf("%f",&A[i][j]);
       }
    }
    find_p(A);
           for(k=1;k<=n+1;k++)
           {  temp = A[p][k];
              A[p][k] = A[j][k];
              A[j][k] = temp;
           }
           
        for(b=1;b<=n;b++)
        {  for(a=1;a<=n;a++)
           {  if(a>b)
              {  z=A[a][b]/A[b][b];
                 for(c=1;c<=n+1;c++)
                 {  A[a][c]=A[a][c]-z*A[b][c];
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
