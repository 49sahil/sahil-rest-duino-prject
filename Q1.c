#include <stdio.h>

int main()
{
	char st[50];
	printf("What is your name?\n");
	scanf("%s",st);
	int y;
	printf("Hello, %s!\nWhat year were you born?\n",st);
	scanf("%d",&y);
	y=2021-y;
	printf("Congratulations, you are %d years old\n",y);
	return 0;
}
