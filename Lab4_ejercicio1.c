#include<stdio.h>

int main( ){
	char *str1;
	{
	char a1 = 'A';
	str1 = &a1;
	}
printf("%c", *str1);
}
