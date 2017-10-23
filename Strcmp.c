#include<stdio.h>
#include <string.h>
int main(){
char s[50];
char s2[50];
strcpy(s,"a");
strcpy(s2,"b");
int f=strcmp(s,s2);

printf("strcmp: %d",f);
}
