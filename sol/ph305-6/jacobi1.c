#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n,i,j,k,p=1,q=2,x=0;
    float d[20][20],a[20][20],max,theta,sign,t,c,s,o[4][4],r[4][4],rt[4][4],m[4][4],M[4][4],b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%f",&d[i][j]);
        }
    }
     for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                
                o[i][j] = d[i][j];
            }
        }
    do{
        x++;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                a[i][j] = d[i][j];
                
            }
        }
        p=1;
        q=2;
        max=fabs(a[1][2]);
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(fabs(a[i][j])>max){
                    max=fabs(a[i][j]);
                    p=i;
                    q=j;
                }
            }
        }
        if(a[p][q] != 0){
            theta = (a[q][q] - a[p][p])/(2*a[p][q]);
            if(theta<0){
                sign = -1;
            }
            else{
                sign = 1;
            }
            t = sign/(fabs(theta)+sqrt((theta*theta)+1));
            c = 1/(sqrt((t*t)+1));
            s = c*t;
            d[p][q] = 0;
            d[q][p] = 0;
            d[p][p] = (c*c*a[p][p])+(s*s*a[q][q])-(2*c*s*a[p][q]);
            d[q][q] = (s*s*a[p][p])+(c*c*a[q][q])+(2*c*s*a[p][q]);
            for(j=1;j<=n;j++){
                if(j!=p && j!=q){
                                    d[j][p] = (c*a[j][p])-(s*a[j][q]);
                                    d[p][j] = d[j][p];
                                    d[j][q] = (c*a[j][q])+(s*a[j][p]);
                                    d[q][j] = d[j][q];
                }
            }
        }
    }
    while(x<2);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f  ",d[i][j]);
        }
        printf("\n");
    }
    
    r[1][1]=c;
    r[1][2]=s;
    r[2][1]= -1*s;
    r[2][2]=c;
    rt[1][1]=c;
    rt[1][2]= -1*s;
    rt[2][1]=s;
    rt[2][2]=c;
    printf("%f\n",s);
    printf("%f\n",c);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f  ",o[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   b=0;
            for(k=1;k<=n;k++)
            {   b += rt[i][k]*o[k][j];
            }
            m[i][j]=b;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f  ",m[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
        {   b=0;
            for(k=1;k<=n;k++)
            {   b += m[i][k]*r[k][j];
            }
            M[i][j]=b;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f  ",M[i][j]);
        }
        printf("\n");
    }
    return(0);
}
