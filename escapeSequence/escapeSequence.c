#include <stdio.h>

int main(void)
{
	int x = 10;

	putchar('B');
	putchar('\n'); // escape sequence
	printf("%c\n", 'A'); // format character
	printf("%c\n", 65); // 'A'와 같음

	printf("x는 %d입니다.\n", x);

	printf("%s\n", "Hello, world!");
	return 0;
}
