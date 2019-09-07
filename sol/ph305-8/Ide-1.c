#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
    int i,q;
    float a,b,x,v,f,h,t,k,x1,x2,x3,x4,v1,v2,v3,v4,z;
    //printf("\nEnter t0,x0,v0,h,xn: ");
    //scanf("%f%f%f%f%f",&t,&a,&b,&h,&f);
    /*t=0;
    a=1;
    b=0;
    h=0.02;
    f=50;
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
    }*/
    t=0;
    a=1;
    b=0;
    h=0.02;
    f=5;
    x=a;
    v=b;
    //printf("\nRK4 method\n");
    while(t<f)
    {
        z=x;
        x1=v;
        v1=-x;
        x2=v+h*v1/2;
        v2=-(x+h*x1/2);
        x3=v+h*v2/2;
        v3=-(x+h*x2/2);
        x4=v+h*v3;
        v4=-(x+h*x3);
        x=x+(h*(x1+2*x2+2*x3+x4)/6);
        v=v+(h*(v1+2*v2+2*v3+v4)/6);
        printf("%f\t%f\n",x,v);
        t=t+h;
    }
}

