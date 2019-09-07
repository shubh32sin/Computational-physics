#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float slope(float x,float y)
{
    float f;
    f=(4*exp(0.8*x))-(0.5*y);
    return f;
}
main()
{
    int i;
    float a,b,x,y,h,t,k,x1,y1,ye[100],ym[100],yh[100],yr[100],k1,k2,xm[100];
    printf("\nEnter x0,y0,h,xn: ");
    scanf("%f%f%f%f",&a,&b,&h,&t);
    x=a;
    y=b;
    printf("\nEuler's method\n");
    printf("\n  x\t  y\n");
    i=0;
    while(x<=t)
    {
        i++;
        k=h*slope(x,y);
        y=y+k;
        x=x+h;
        ye[i]=y;
        xm[i]=x;
        printf("%0.3f\t%0.3f\n",x,y);
    }
    x=a;
    y=b;
    printf("\nMidpoint method\n");
    printf("\n  x\t  y\n");
    i=0;
    while(x<=t)
    {
        i++;
        k=(h/2)*slope(x,y);
        y1=y+k;
        x1=x+(h/2);
        k=h*slope(x1,y1);
        y=y+k;
        x=x+h;
        ym[i]=y;
        printf("%0.3f\t%0.3f\n",x,y);
    }
    x=a;
    y=b;
    printf("\nHuen's method\n");
    printf("\n  x\t  y\n");
    i=0;
    while(x<=t)
    {
        i++;
        k1=slope(x,y);
        y1=y+(k1*h);
        x1=x+h;
        k2=slope(x1,y1);
        k=(k1+k2)/2;
        y=y+(k*h);
        x=x+h;
        yh[i]=y;
        printf("%0.3f\t%0.3f\n",x,y);
    }
    x=a;
    y=b;
    printf("\nReal solutions\n");
    printf("\n  x\t  y\n");
    i=0;
    while(x<=t)
    {
        i++;
        x=x+h;
        y=((4/1.3)*(exp(0.8*x)-exp(-0.5*x)))+(2*exp(-0.5*x));
        yr[i]=y;
        printf("%0.3f\t%0.3f\n",x,y);
    }
    printf("\nx\t\t    Euler\t\tMidpoint\tHuen\t\tReal\n");
    for(i=1;i<=(t/h);i++)
    {
        printf("%f\t%f\t%f\t%f\t%f\n",xm[i],ye[i],ym[i],yh[i],yr[i]);
    }
}
