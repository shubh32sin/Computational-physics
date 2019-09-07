#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
    int i;
    float a,b,x,v,f,h,t,k,x1,y1,z,v1,xn,vn,tf[2000],xe[2000],xm[2000],xh[2000],xr[2000];
    //printf("\nEnter t0,x0,v0,h,xn: ");
    scanf("%f%f%f%f%f",&t,&a,&b,&h,&f);
    x=a;
    v=b;
    printf("\nEuler method\n");
    printf("\n  t\t  \tx\n");
    i=0;
    while(t<f)
    {
        i++;
        z=x;
        x=x+h*v;
        v=v-h*z;
        t=t+h;
        xe[i]=x;
        tf[i]=t;
        //printf("%f\t%f\n",t,x);
    }
    printf("\nReal solutions\n");
    printf("\n  t\t  \tx\n");
    t=0;
    i=0;
    while(t<f)
    {
        i++;
        t=t+h;
        x=cos(t);
        xr[i]=x;
        //printf("%f\t%f\n",t,x);
    }
    x=a;
    v=b;
    t=0;
    printf("\nMidpoint method\n");
    printf("\n  t\t  \tx\n");
    i=0;
    while(t<f)
    {
        i++;
        z=x;
        x1=x+((h/2)*v);
        v1=v-((h/2)*z);
        x=x+h*v1;
        v=v-h*x1;
        t=t+h;
        xm[i]=x;
        //printf("%f\t%f\n",t,x);
    }
    x=a;
    v=b;
    t=0;
    printf("\nHuen's method\n");
    printf("\n  t\t  \tx\n");
    i=0;
    while(t<f)
    {
        i++;
        z=x;
        x1=x+((h)*v);
        v1=v-((h)*z);
        xn=(x1+x)/2;
        vn=(v1+v)/2;
        x=x+h*vn;
        v=v-h*xn;
        t=t+h;
        xh[i]=x;
        //printf("%f\t%f\n",t,x);
    }
    printf("\nx\t\t  Euler\t\tMidpoint\t   Huen\t\t   Real\n");
    for(i=1;i<=(t/h);i++)
    {
        printf("%f\t%f\t%f\t%f\t%f\n",tf[i],xe[i],xm[i],xh[i],xr[i]);
    }
}

