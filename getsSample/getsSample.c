#include <stdio.h>

int main(void) {
	char szName[32] = { 0 }; // 배열 선언 및 정의 // 32개 모두를 0으로 채움 → 배열 관련 문법은 추후 볼 것
	// (cf.) sz는 string zero의 의미

	printf("이름을 입력하세요: ");

	gets(szName); // gets()는 보안 결함 문제 있으므로, 실제로는 사용 금지

	printf("당신의 이름은 ");
	puts(szName); // puts()는 개행 입력
	puts("입니다.");

	return 0;
}
