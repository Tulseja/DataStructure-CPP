#include<stdio.h>
 void main()
{
int i=-3,j=2,k=-1,m;
m=++i||++j&&k;
printf("%d %d %d %d",i,j,k,m);
}
