#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int i,j,n;
    double f,a[40][40],b[40],l[40][40],u[40][40],y[40]={0},t[40]={0},x,o;
    scanf("%d",&n);
    o=n;
    f = 10/(o+1);
    printf("%lf\n",f);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                a[i][j]=2+(0.01*f*f);
            }
            else if(abs(i-j)==1){
                a[i][j]=-1;
            }
            else{
                a[i][j]=0;
            }
        }
    }
    printf("matrix is\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%lf ",a[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++){
        b[i]=(0.01*f*f*20);
    }
    b[1]+=40;
    b[n]+=200;
    /*printf("\narray is\n");
    for(i=1;i<=n;i++){
        //printf("%lf\n",b[i]);
    }*/
    for(i=2;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i-j==1){
                a[i][j]=a[i][j]/a[j][j];
            }
            if(i==j){
                a[i][j]=a[i][j]-(a[i][j-1]*a[i-1][j]);
            }
        }
    }
    /*printf("\na matrix is\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            //printf("%lf ",a[i][j]);
        }
        //printf("\n");
    }*/
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i-j==1){
                l[i][j]=a[i][j];
            }
            else if(i==j){
                l[i][j]=1;
            }
            else{
                l[i][j]=0;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                u[i][j]=a[i][j];
            }
            else if(i-j==-1){
                u[i][j]=a[i][j];
            }
            else{
                u[i][j]=0;
            }
        }
    }
    /*printf("\nl matrix is\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            //printf("%lf  ",l[i][j]);
        }
        //printf("\n");
    }
    //printf("\nu matrix is\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            //printf("%lf  ",u[i][j]);
        }
        //printf("\n");
    }*/
    for(i=1;i<=n;i++){
        y[i]=b[i]-(l[i][i-1]*y[i-1]);
    }
    /*for(i=1;i<=n;i++){
        printf("%lf  ",y[i]);
    }*/
    for(i=n;i>=1;i--){
        t[i]=(y[i]+t[i+1])/u[i][i];
    }
    //printf("final soln. \n");
    x=0;
    for(i=1;i<=n;i++){
        x=x+f;
        printf("%lf\t%lf\n",x,t[i]);
    }
    return (0);
}
