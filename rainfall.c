
#include<stdio.h>
#include<stdlib.h>
using name space std;
void main()

{

int A[12][3];
float totalrainthisyear=35.4 ,totalrainpreviousyear=42.8,averagerainthisyear=3.6,averagerainpreviousyear4.0;
int i,j,k;
for(k=0;k<12;k++)

{

printf("Enter the rainfall for this year and previous year:%d"k+1);
scanf(%d %d,& A[k][0],&A[k][1]);

}

for(i=0;i<1;i++)

{

 totalrainthisyear+=A[i][0];
 totalrainpreviousyear+=[i][1];


}
 averagerainthisyear=totalrainthisyear/12.0;
 averagerainpreviousyear=totalrainpreviousyear/12.0;


printf("\t\t\tTable of monthly Rainfall\t\n");
for(int a=0;a<12;a++)
printf("\t\tMonth%d",a+1);
printf("\n");
printf("This Year\t");
for(i=0;i<12;i++)
printf("%d\t",A[i][0]);
printf("\n");
printf("Previous Year\t");
for(j=0;j<12;j++)
printf("%d\t",A[i][1]);
printf("\n\n\n");
print("Total Rainfall This Year %f\n",totalrainfallthisyear);
print("Total Rainfall Previous Year %f\n",totalrainfallpreviousyear);
print("Total Rainfall This Year %f\n",averagerainfallthisyear);
print("Total Rainfall Previous Year %f\n",averagerainfallpreviousyear);


}






















}
