#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void get_poly(double coeff[],int* degree);
double eval_poly(const double coeff[],int degree,double z);

int main()
{

int deg;
double res,base,coeff[8];

printf("Insert a degree [ less than 8 ] for the polynomial please :\n");
scanf("%d",&deg);

printf("Insert the %d coefficients of the polynomial please : \n",deg+1);
get_poly(coeff,&deg);

printf("Insert the value of the base x please : \n");
scanf("%lf",&base);
res=eval_poly(coeff,deg,base);

printf("the result is %f",res);

return 0;
}
void get_poly(double coeff[],int* degree)
{
int i;

for(i=0;i<*++degree;i++)
  scanf("%lf",&coeff[i]);
}
double eval_poly(const double coeff[],int degree,double x)
{
int i;
double res=0.0;

for(i=0;i<=degree;i++)
res=res+coeff[i]*pow(x,i);

return res;
}
