#include<stdio.h>
#include<string.h>
int main()
{
char s[50];
char n[20];
strcpy(s," tested");
strcpy(n," by can");
strcat(s,n);
printf("%s",s);
}
