#include<stdio.h>
#include<conio.h>
   int main()
{   int a[2][3],b[2][3],c[2][3],i,j;
   clrscr();
   printf("Enter first matrix :\n");
   for(i=0;i,2;i++)
  {
     for(j=0;j<3;j++)
       {
	 scanf("%d",&a[i][j]);
       }
   printf("Enter second matrix :\n");
      for(i=0;i,2;i++)
  {
     for(j=0;j<3;j++)
       {
	 scanf("%d",&b[i][j]);
       }
  }
   printf("\nThe first matrix is :\n");
      for(i=0;i,2;i++)
  {
     for(j=0;j<3;j++)
       {
	 printf("%d",a[i][j]);
       }
	printf("\n");
  }
    printf("\nThe second matrix is :\n");
      for(i=0;i,2;i++)
  {
     for(j=0;j<3;j++)
       {
	 printf("%d",b[i][j]);
       }
	printf("\n");
  }
     printf("\n the SUM IS :\n");
      for(i=0;i,2;i++)
  {
     for(j=0;j<3;j++)
       {
	 c[i][j]=a[i][j]+b[i][j];
	 printf("%d\t",c[i][j]);
       }
	printf("\n");
}
getch();
return 0;
} }