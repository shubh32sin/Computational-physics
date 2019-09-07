#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,x,x1,y,y1,z,z1,i,c1,c2;
    float pi,circle=0.0,j,pi1,circle1=0.0;
    a=1;
    b=2;
    x=1;
    y=1;
    c1=2;
    c2=1;
    j=0;
     for(i=0;i<=5000;i++){
        x=(a*x + c1)%1000;
        x1=rand()%1000;

        y=(b*y + c2)%1000;
        y1=rand()%1000;

        z=((x-500)*(x-500))+((y-500)*(y-500));
        z1=((x1-500)*(x1-500))+((y1-500)*(y1-500));

        if(z<=250000){
            circle=circle+1.0;
        }
        if(z1<=250000){
            circle1=circle1+1.0;
        }

        j=j+1.0;
     }

     pi=((circle/j)*4.0);
     pi1=((circle1/j)*4.0);
     printf("\n Value of pi using user-defined random function is: %lf\n",pi);
     printf("\n Value of pi using default random function is: %lf\n",pi1);

    return 0;
}
