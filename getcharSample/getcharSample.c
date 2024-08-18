#include <stdio.h>

int main(void)
{
	char ch = 0; // 변수 선언 + 정의 // 변수는 메모리를 사용하기 위한 방법 // 자료형, C에서 char는 정수 자료형

	ch = getchar(); // I/O buffer에서 한 글자 가져오기
	putchar(ch); // I/O buffer에 한 글자 입력
	putchar('Z');

	return 0;
}
