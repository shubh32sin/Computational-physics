#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int i,j,k,e;
	double z[10][10],zt[10][10],a1,a0,s,m[6][6],det,temp,d[10],ztd[10],a0s,a1s,x[6]={0,0.25,0.75,1.25,1.75,2.25},y[6]={0,0.28,0.57,0.68,0.74,0.79},f[6],sr;
	a0=1;
	a1=1;
	do{
		e=0;
		for(i=1;i<=5;i++){
			z[i][1] = 1-exp(-1*a1*x[i]);
			z[i][2] = a0*x[i]*exp(-1*a1*x[i]);
			zt[1][i] = z[i][1];
			zt[2][i] = z[i][2];
		}
		for(i=1;i<=2;i++){
			for(j=1;j<=2;j++){
				s=0;
				for(k=1;k<=5;k++){
					s = s+(zt[i][k]*z[k][j]);
				}
				m[i][j]=s;
			}
		}
		det=(m[1][1]*m[2][2])-(m[1][2]*m[2][1]);
		temp=m[1][1];
		m[1][1]=m[2][2]/det;
		m[2][2]=temp/det;
		temp=m[1][2];
		m[1][2]=(-1*m[2][1])/det;
		m[2][1]=(-1*temp)/det;
		for(i=1;i<=5;i++){
			d[i]=y[i]-(a0*(1-exp(-1*a1*x[i])));
		}
		ztd[1]=0;
		ztd[2]=0;
		for(i=1;i<=5;i++){
			ztd[1]=ztd[1]+(zt[1][i]*d[i]);
			ztd[2]=ztd[2]+(zt[2][i]*d[i]);
		}
		a0s=m[1][1]*ztd[1]+m[1][2]*ztd[2];
		a1s=m[2][1]*ztd[1]+m[2][2]*ztd[2];
		a0=a0+a0s;
		a1=a1+a1s;
		//printf("a0= %lf\ta1= %lf\n",a0,a1);
		if(a0s<0.000001 && a1s<0.000001){
			e=1;
		}
	}
	while(e==0);
	for(i=1;i<=5;i++){
		f[i]=a0*(1-exp(-1*a1*x[i]));
        sr+=(y[i]-f[i])*(y[i]-f[i]);
		printf("%lf\t%lf\t%lf\n",x[i],y[i],f[i]);
	}
    printf("%lf",sr);
	return 0;
}
