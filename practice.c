#include<stdio.h>
//#include<iostream>
//using namespace std;
#include<stdbool.h>
void my_strcat(char *dest, char *src)
{
  (*dest)? my_strcat(++dest, src): (*dest++ = *src++)? my_strcat(dest, src): 0 ;
}

/* driver function to test above function */
int main()
{
  char dest[100] = "geeks for ";
  char *src = "geeks";
  my_strcat(dest, src);
  printf(" %s ", dest);
  getchar();
}
