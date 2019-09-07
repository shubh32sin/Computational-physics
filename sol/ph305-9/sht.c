#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double euler(double p){
	double x=0;
	double t=40,l;
	while(x<10){
		x=x+0.5;
		l=t;
		t=t+(p*0.5);
		p=p+(0.01*(l-20)*0.5);
		printf("%lf\t%lf\n",x,t);
	}
	return t;
}
int main(){
	double x=0;
	double p,t,t1,t2,p2,p1,l; 
	p1=10;
	t1=euler(p1);
	printf("%lf\n",t1);
	p2=20;
	t2=euler(p2);
	printf("%lf\n",t2);
	p=p1+((p2-p1)*(200-t1)/(t2-t1));
	printf("%lf\n\n\n",p);
	t=euler(p);
	printf("%lf\n",t);
	t=40;
	while(x<10){
		x=x+0.5;
		l=t;
		t=t+(p*0.5);
		p=p+(0.01*(l-20)*0.5);
		printf("%lf\t%lf\n",x,t);
	}
	return (0);
}