#include<stdio.h>
#include<math.h>
double f(double x,double y){
double fn;
fn=2*x*y+2*x-x*x-2*y*y+72;
return fn;
}
void main(){
double x,y,fn,t,fm[10000],onepx,onepy,ans=0,a,b,c=0,d=0,iy0,iy1,iy2,iy3,err,exans;
int input,n,i,j;
scanf("%d",&input);
exans=2816/48;
if(input==1){
        scanf("%d",&n);
        for(j=0;j<=n;j++){
     for(i=0;i<=n-1;i++){
            onepx=8.0/n;
            onepy=6.0/n;
        t+=8*(f(i*onepx,j*onepy)+f((i+1)*onepx,j*onepy))/(2*n);
     }
   fm[j]=t;
   t=0;
        }
for(j=0;j<=n-1;j++){
        ans+=6*(fm[j]+fm[j+1])/(2*n);}
        printf("The answer for trapezoidal rule is %lf\n",ans/48);
        printf("The error in trapezoidal rule is :- %lf",(ans-2816)/48);}


        if(input==2){
           n=2;
             for(j=0;j<=n;j++){
     onepx=8/n;
     onepy=6/n;
     a=0;
     b=0;
     for(i=1;i<=n-1;){
        a+=f(onepx*i,j*onepy);
        i=i+2;
     }
     for(i=2;i<=n-2;){
        b+=f(onepx*i,j*onepy);
        i=i+2;
     }
     fm[j]=8*(f(0,j*onepy)+f(8,j*onepy)+4*a+b)/(3*n);
     }
for(i=1;i<=n-1;){
        c+=fm[i];
        i=i+2;
     }
     for(i=2;i<=n-2;){
        d+=fm[i];
        i=i+2;
     }
ans=6*(fm[0]+4*c+d+fm[n])/(3*n);
        printf("The answer for simpson 1/3rd rule is %lf\n",ans/48);
        printf("The error in simpson 1/3rd rule is :- %lf",(ans-2816)/48);}
        if(input==3){
            iy0=(f(0,0)+3*f(2.6666667,0)+3*f(5.333333,0)+f(8,0));
            iy1=(f(0,2)+3*f(2.6666667,2)+3*f(5.333333,2)+f(8,2));
            iy2=(f(0,4)+3*f(2.6666667,4)+3*f(5.333333,4)+f(8,4));
            iy3=(f(0,6)+3*f(2.6666667,6)+3*f(5.333333,6)+f(8,6));
            ans=6*(iy0+3*iy1+3*iy2+iy3)/8;
            printf("The answer for simpson 3/8th rule is %lf\n",ans/48);
            printf("The error in simpson 3/8th rule is :- %lf",(ans-2816)/48);
        }

}

