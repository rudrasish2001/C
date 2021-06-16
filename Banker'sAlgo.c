#include<stdio.h>
int main()
{
 int n,m,i,j,k;
 n=5;
 m=3;		      //P1       P1     P2      P3       P4
 
 int allocated[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};

                //P1       P1     P2      P3       P4
 int max[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}}

 int available[3]={3,2,2};

 int f[n],seq[n],index=0;
 for(k=0;k<n;k++)
 {
  f[k]=0;
 }
 int reqd[n][m];
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   reqd[i][j]=max[i][j]-allocated[i][j];
  }
 }
 int y=0;
 for(k=0;k<5;k++)
 {
  for(i=0;i<n;i++)
  {
   if(f[i]==0)
   {
    int flag=0;
    for(j=0;j<m;j++)
    {
     if(reqd
