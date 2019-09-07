#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
    int i,q;
    float a,b,x,v,f,h,t,k,x1,y1,z,v1,xn,vn,tf[q],E,xm[1],xh[2000],xr[2000];
    //printf("\nEnter t0,x0,v0,h,xn: ");
    //scanf("%f%f%f%f%f",&t,&a,&b,&h,&f);
    t=0;
    a=1;
    b=0;
    h=0.02;
    f=30;
    x=a;
    v=b;
    q=f/h;
    //printf("\nEuler method\n");
    //printf("\n  t\t  \tx\n");
    i=0;
    while(t<f)
    {
        i++;
        z=x;
        x=x+h*v;
        v=v-h*z;
        t=t+h;
        E=((v*v)+(x*x))/2;
        //tf[i]=t;
        printf("%f\t%f\t%f\n",t,x,v);
    }
    /*for(i=1;i<=(t/h);i++)
    {
        printf("%f\t%f\n",tf[i],E[i]);
    }*/
}

