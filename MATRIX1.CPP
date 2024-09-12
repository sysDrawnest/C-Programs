#include<stdio.h>
#include<conio.h>
void main() {
int r,c,a[100][100],b[100][100],sum[100][100],i,j;
clrscr();
printf("Enter the size of the matrix 1 :\n");
scanf("%d",&r);
printf("Enter the size of the matrix 2 :\n");
scanf("%d",&c);
 printf("\nEnter elements of matrix 1:\n");
 for(i=0;i<r;++i)
 for(j=0;j,c;++j)
{
 printf("Enter element a%d%d:\n",i+1,j+1);
 scanf("%d",&a[i][j]);
}
 printf("\nEnter elements of matrix 2:\n");
 for(i=0;i<r;++i)
 for(j=0;j<c;++j)
{
 printf("Enter element b%d%d:",i+1,j+1);

