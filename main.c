#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void main (void)
{
   const char*str1 = "i'm doing a test.";
   char*str2 = (char*)malloc(strlen(str1)+1);
   char*s1 = str1;
   char*s2 = str2;
   if(!str2)
   {
      printf("malloc fail\r\n");
      return;
   }
   memset(str2,0,strlen(str1)+1);
   while(*s1)
   {
      *s2 = *s1;
      s1++;
      s2++;
   }
   printf("str1:%s\n",str1);
   printf("str2:%s\n",str2);
   free(str2);
   return;
}