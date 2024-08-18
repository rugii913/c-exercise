# keywords
- 인프런 강의 - 독하게 시작하는 C 프로그래밍 - 키워드만 정리
- 강의 소개
  - (개발 환경) Visual Studio 2022 Community + Windows 11 환경
  - C언어 프로그래밍 입문 강의
- C언어 공부 얼마나 해야 하나?
  - (적정 학습 기간) 1일 3시간 수업 + 3시간 실습 조건 C언어 2개월, 자료구조 2개월 이상

---

## part 1. C를 배우기 전에 알아야 할 것들

### section 1. 디지털 세계

#### 컴퓨터와 2진법
- 1bit = 전기 스위치 1개
  - 경우의 수 따지기
- 4bit → 16가지 경우의 수

#### 디지털 게이트 회로
- 게이트 회로 - AND, OR, XOR, NOT(inverter)
- 디지털 회로, IC(직접 회로)
- 가산기 → AND와 XOR

#### 가산기와 수제 CPU
- 자리 올림(carry)
- 전가산기(full adder)
- cf. RAM은 JK flip-flop

### section 2. 진법 변환

#### 이미 아는 10진법
- 10진수 → 2진수 → 16진수, 8진수

#### 2진수 16진수 변환
- 2진수를 쓰는 이유
- 4bit와 16진수 한 자리 숫자
- 16진수 숫자 리터럴 0x..
- 64bit → 0x0000_0000_0000_0000

#### 16진수 표기가 사용되는 예
- 색상 표현(RGB - 24bit)
- 컴퓨터 하드웨어 주소 표현
- 메모리에 저장된 값 표현
  - 1byte는 8bit(16진수 2개로 표시 가능) → ASCII 1개

### section 3. C를 배우기 전 알아야 할 컴퓨터 구조

#### CPU와 메모리
- CPU(연산), 메모리(데이터 저장) - 컴퓨터의 핵심 장치
- 메모리 주소
- CPU register
- CPU ALU(arithmetic logical unit)
- 프로그램은 결국 연산과 자료 저장에 대한 이야기
- 변수: 메모리를 사용하는 방법
- C에서 생각할 메모리는 두 가지
  - RAM, file system memory
- 주 기억장치 공간은 일련번호로 관리
  - 1byte 공간을 관리하기 위해 64bit(혹은 32bit) 번호를 부여
    - 32bit로 표현할 수 있는 최대 메모리 크기는 4GB
  - 물리 메모리를 논리적인 형태로 관리
- 자료: 저장된 정보
- 자료형: 저장된 정보의 형식

#### 실행과 참조의 개념
- 실행: 단순하게 말하면 그 실체는 CPU 연산
  - 정보를 메모리로부터 CPU 레지스터로 전달
  - 연산 결과가 저장된 레지스터의 값을 메모리로 보내는 과정을 반복
- 변수: 메모리를 쓸 수 있는 방법
- 프로세스: 설치된 프로그램이 실행된 형태
  - 프로그램을 프로세스화하는 것이 실행 - 명령어를 이용해 CPU가 연산하도록 하는 것
- 참조(reference) - pointer와 관련
  - 참조의 대상이 먼저 존재
  - 참조 대상에 접근할 수 있는 근거 자료가 참조자(참조)
  - (비유) 엑셀에서 D7 셀에 =C3이라 입력했다면, D7이 참조자 C3이 참조 대상

#### CPU의 다른 이름 Machine
- 컴퓨터의 구성은 HW와 SW로 나눌 수 있고, SW는 system SW(주로 OS)와 application으로 나눌 수 있음
  - HW는 physical
  - SW는 logical = virtual
    - 가상화 기술: HW를 SW로 구현
- (cf.) C언어는 UNIX 운영 체제를 개발하기 위해 만들어짐 → 하드웨어 친화적
- machine: 컴퓨터에서 실행(연산)의 주체인 CPU의 또 다른 이름
  - machine code(기계어): CPU를 작동시키기 위한 코드 - 기계어가 있어야 연산이 가능(고급어를 번역해줘야 함)
    - machine code에 직접 의존하면 native code라 부름

### section 4. CPU 수준 자료형

#### 자료형에 대한 이해
- 자료형(data type): 계산할 대상인 자료의 형식
  - C언어에서는 일정 길이의 메모리에 저장된 2진수 정보를 해석하는 방법 정도로 생각해볼 수 있을 것
  - 자료(계산 대상 숫자)는 두 종류 - 변수와 상수
    - 다른 관점으로, HW 수준에서 인식할 수 있는 자료(숫자)는 두 종류 - 정수, 실수
- C언어의 자료형 → 변수이든 상수이든 적용됨
  - 정수형(부호 유무, 크기에 따른 여러 정수형 존재)
  - 실수형(크기에 따라 단정도, 배정도)
  - 유도형(*, [], 구조체, 공용체)
  - 함수형
  - 무치형(void)

#### 상수와 변수 그리고 복잡성
- 상수: 값이 확정되어 앞으로 변할 가능성이 없는 수
  - 종류 → 리터럴 상수(일반적으로 상수라 하면 리터럴 상수) / 심볼릭 상수(별도로 다룸)
  - 리터럴 상수의 종류 → 문자 상수(ASCII 코드) / 문자열 상수 / 정수 상수 / 실수 상수
    - (cf.) 컴퓨터는 문자의 개념 자체를 이해하는 것이 아니므로, 부호 체계(코드 체계 → section 5)를 이용하여 정수를 문자로 매핑
- 변수: C언어에서는 메모리라고 생각하면 됨 → 구체화하지 않았거나 앞으로 변경될 가능성이 있는 수 혹은 미지의 수
  - 메모리를 사용하는 가장 일반적인 방법
  - 메모리가 가지는 특성을 가짐 → 주소(위치 정보), 공간의 크기
  - (cf.) 변수는 경우의 수(범위)와 연관되고, 이는 복잡성과 관련이 있음

#### 정수형
- (cf.) 1byte → 관리의 최소 단위
- unsigned
  - unsigned가 아닌 경우 → 부호 bit(1bit)를 제외한 나머지 전체를 data bit로 해석
  - unsigned인 경우 → 모두를 data bit로 해석
- 크기에 따른 자료형
  - char 1byte / short 2byte / int 4byte / long 4byte / long long int 8byte
  - (cf.) compiler spec, 언어 표준에 따라 조금씩 차이는 있으나, C99 표준 기준 위와 같음

#### 2진수 덧셈과 뺄셈
- 컴퓨터가 뺄셈하는 방법
  - 1의 보수 → 2진수에 bit 연산 NOT을 한 것
  - 2의 보수 → 1의 보수 + 1
  - 2의 보수를 더하고 자리올림을 절사 → 가산기(adder)와 NOT gate만 있으면 간단한 방식의 -, *, /도 구현 가능
    - (ex.) 1010 - 0101 = 1010 - 0101 + 10000 - 10000 = 1010 + 1011 - 10000 = 0101
  - (cf.) 10진수에서도 비슷한 방식으로 뺄셈 가능 → 13 - 6 = 13 - 6 + 10 - 10 = 13 + 4 - 10 = 7
- (cf.) 추가 검색 자료 - [영문 Wikipedia - Method of complements](https://en.wikipedia.org/wiki/Method_of_complements)

#### 곱셈, 나눗셈, 시프트 그리고 하드웨어 손상
- shift: 컴퓨터가 빠르게 연산하는 방법 → HW 수준에서 가능하도록 processor 제조사에서 회로 설계
  - padding: 빈 자리 채워넣기
  - left shift 할 경우 곱셈, right shift 할 경우 나눗셈
    - (ex.) a * 21은 left shift를 4번(*16) 후 a를 5번 더함
- divide by 0는 통상적으로 HW 자체에서 막아둠

#### 실수형 - 단정도, 배정도
- floating point ↔ fixed point
  - floating point는 IEEE 754 표준
  - 일정 수준의 부동소수점 오차를 인정
  - 부호 bit, 지수, 가수 세 부분으로 구성, 지수 값과 가수 값을 연산해 값을 표현
- 크기에 따른 자료형 및 그 표현 범위
  - float 4byte → 1.17 * 10 ^ -38 ~ 3.4 * 10 ^ 38 (유효 자릿수: 소수점 이하 6자리) / IEEE 754 single format
    - 거의 사용하지 않음
  - double 8byte → 2.22 * 10 ^ -308 ~ 1.79 * 10 ^ 308 (유효 자릿수: 소수점 이하 15자리) / IEEE 754 double format
    - 통상적으로 이 자료형을 사용한다고 보면 될 것
  - long double 8byte 이상
    - compiler마다 차이가 있음, 지원하지 않을 수 있음
- float.h에서 DBL_MIN, DBL_MAX로 double 자료형의 최솟값, 최댓값 확인 가능

#### 부동소수점 오차
- 부동소수점 오차 발생 이유: 근사값 사용
  - 일정 구간의 실수를 대표하는 실수 표현
- (cf.) double을 쓰더라도 유효 자릿수가 소수점 이하 15자리이므로 이로 인해 사고가 발생할 수 있음
  - [기타 블로그 - \[C 공부\] 4강 — C프로그래밍 입문](https://flyingsquirrel.medium.com/c-%EA%B3%B5%EB%B6%80-4%EA%B0%95-c%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D-%EC%9E%85%EB%AC%B8-beaba7d79623)

### section 5. 코드 체계

#### 컴퓨터가 글자를 말하는 방법(feat . ASCII)
- 컴퓨터가 다룰 수 있는 자료는 숫자 뿐
  - 숫자에 문자를 매핑하여 글자를 다룸
- ASCII(American Standard Code for Information Interchange) → 가장 유명한 매핑(미국 표준 코드체계) 중 하나
  - 기본적으로 7bit(128 경우의 수) 코드 체계
  - 특수 문자 등으로 확장하기 위해 7bit를 추가하여 총 8bit → 1byte
  - 10진수 65가 영문 대문자 'A', 16진수로 0x41
  - 구글에서 ASCII code table 검색하면 확인해볼 수 있음
- (cf.) 어떤 데이터에 있는 정보가 글자들만 있다면 이를 text라 함
  - 숫자와 글자를 구별하지 않고 정보를 말할 때는 binary → text는 binary의 하위 범주라고 말할 수 있음

#### 문자열에 대한 이해
- 문자열은 문자의 배열
  - 문자열을 정확히 이해하려면 배열, 주소, 포인터 개념까지 알아야할 것

#### 가볍게 살피는 유니코드
- 참고 [YouTube 널널한 개발자 TV - 문자를 다루는 인코딩 규칙에 대한 모든 것!](https://youtu.be/6hvJr0-adtg?si=KL613eR6sg903NT9)
- C언어의 문자열 구분: MBCS(Multi-bytes Character Sets) vs. Unicode
  - Unicode는 한글 영문 모두 한 글자가 2byte - 강의에서 깊게 다루지는 않겠으나 업무 중 알 필요가 있는 경우가 있을 것

### section 6. 프로그래밍 언어 분류

#### 저급어와 고급어
- machine code: 연산을 하기 위한 코드 체계 - 저급어
  - 실행할 구체적인 내용은 C와 같은 언어로 작성 - 고급어
- 기계어 코드, 디스어셈블 코드, 리버싱
- 번역기: compiler vs. interpreter

#### 컴파일러 언어와 인터프리터 언어
- compiler vs. interpreter - 번역 시점, 번역 분량 등 기준에서의 차이
  - source code의 필요 여부에서도 차이
  - 성능 최적화 - compiler 방식에서 용이

---

## part 2. C 프로그래밍의 시작

### section 7. 개발환경 구축

#### Win11기반 Visual Studio Community 2022 개발환경 설정
- (실습 환경) Windows 11, 64bit CPU, Visual Studio 2022 Community
- Visual Studio 2022 환경설정
  - 도구 → 설정 가져오기 및 내보내기 마법사 → 모두 다시 설정 → 기본설정 모음 선택에서 Visual C++ 선택'
  - 도구 → 옵션  → 환경 → 글꼴 및 색에서 개발자용 글꼴로 설정(ex. consolas) - 1, l, I가 정확히 구분되어야 함

#### 주요 단축키와 첫 번째 예제 작성 (feat. Hello world!)
- Visual Studio 2022 주요 단축키
  - F4: 오류 발생 지점으로 이동
  - **F5: 디버그 모드 실행** → 중단점에서 일시 정지하고 메모리 윈도우 등 확인을 위함
  - shift + F5: 디버그 모드 강제 중단
  - F7: 프로젝트 빌드(cf. compile + link를 함께 묶어 build라 부름)
  - F9: 중단점 설정
  - F10: 디버그 모드에서 한 행 실행
  - F11: 디버그 모드에서 함수 추적
  - ctrl + F5: 실행
- 새 프로젝트 만들기(파일 → 새로 만들기 → 프로젝트 → C++ 빈 프로젝트로 생성)
  - 보기 → 클래스 뷰 추가(ctrl + shift + c)
  - 프로젝트 → 새 항목 추가(ctrl + shift + a)
    - Visual C++ 클릭 후 C++ 파일(.cpp)로 추가 후 확장자를 cpp에서 c로 변경
- (cf.) F7로 빌드하면, 변경 내용 자동 저장됨

#### 컴파일, 링크, 실행
- 중요한 세 가지 시점 - compile time, link time(, build time), runtime
  - compile time: .c 소스코드를 object file(.obj 확장자, 목적 파일)로 번역
    - 번역, 문법 검사 등
    - (cf.) object file부터 이미 기계어가 들어감, 다만 완벽한 실행 파일은 아니고 조립을 위한 형태
  - link time: object file과 라이브러리를 실행 파일로 합성
    - 합성(조립)하는 시점
      - link time error는 주로 "있다고 한 것이 없을 때" 발생함, 해결하는 데에 오래 걸릴 수 있음
    - (cf.) compile은 compiler가 link는 linker가 수행, 각각이 SW
  - build time: compile time + link time
    - compile, link 과정을 거치면 실행 가능한 파일(.exe)이 결과로 나옴
    - (cf.) Windows 환경에서 .obj, .exe 파일은 PE(portable executable) format(binary file이라고도 지칭)
  - runtime: 실행
    - (cf.) 에러 중 가장 좋지 않은 에러는 runtime error
- source code와 object file
  - source code file 확장명 .c
  - 목적 파일 확장명 .obj
  - 외부 라이브러리 파일 확장명 .lib
  - .obj와 .lib를 합성해 실행파일(.exe) 생성

#### VS 프로젝트 파일들에 대한 해설
- Visual Studio IDE
  - editor, compiler, linker 등을 포함
- 솔루션 파일과 프로젝트 - VS만의 독특한 특징
  - solution: 여러 project를 한 solution으로 묶어서 관리
    - solution 파일 확장자 .sln
    - solution 하위 x64 디렉토리 하위 Debug 디렉토리 등에 빌드 결과 .exe 파일
    - Debug로 빌드했을 경우 .pdb(디버깅에 필요한 program database 파일)
    - 각 project 디렉토리에 각종 세팅 파일과 .vcxproj(visual c extended project) 파일
    - 각 project 디렉토리의 하위 x64 디렉토리 하위 Debug 디렉토리 등에 .obj 파일
  - project: 여러 C언어 source code 파일을 하나로 묶어서 관리
  - F7를 눌러 빌드할 때는 solution 전체를 단위로 빌드
  - ctrl + F5를 눌러 실행할 때는 시작 프로젝트로 설정된 프로젝트를 실행
    - 솔루션 탐색기 창에서 실행시킬 프로젝트를 마우스 우클릭 후 시작 프로젝트로 설정

### section 8. C언어 기초 문법

#### 사용 가능한 문자와 예약어
- 사용 가능한 문자 - ASCII 코드 문자 중 일부
  - a\~z, A\~Z, 0~9
  - 특수 문자
  - white space(공백 문자) - 스페이스바, 탭, 엔터 - 눈에 보이지 않아도 값으로 존재
  - escape sequence
- 예약어: compiler가 특수한 의미를 부여해서 해석하는 어휘

#### 변수 이름(식별자) 작성 규칙
- 변수 이름 = 식별자 identifier - 변수를 식별하는 근거가 되므로 식별자라 함
  - 영문 대/소문자, 숫자, 특수문자 중 '_' 가능
    - 이름 중간에 공백 문자 사용 불가
  - 첫 글자는 숫자 사용 불가
  - 예약어 사용 불가
  - 의미를 알 수 없는 이름 금지(공동 작업에서도 문제이지만, 본인이 작성한 코드도 알아보지 못함)
  - 너무 긴 이름은 권장하지 않음(효율성, 오타 등 문제)

#### 항, 식, 구문, 함수
- 항 → 식 → 구문 → 실행 가능한 함수(실행 가능한 코드 덩어리)
- 항: 문자(피연산자, 변수, 상수)로 항 기술 - 소괄호를 이용해 여러 항은 한 항으로 묶을 수 있음
- 식: 항과 연산자가 모인 것
  - 평가: 연산한다는 의미 - 식에는 항상 평가라는 개념이 딸려옴
- 구문: 식이 모여 구문 완성 - 구문 끝에는 세미콜론
  - 여러 구문을 중괄호로 묶을 수 있음
- 함수: 여러 줄의 구문을 연속 실행하는 것

#### 첫 예제 해설
- 전처리기(preprocessor) - compile 전 특정한 작업을 처리
  - (ex.) #include <studio.h>에서 #include
  - 전처리기는 대체로 파일의 가장 위에 둠
- (cf.) 선언과 정의
  - 선언 → 무엇이 있다
  - 정의 → 있는 무엇이 구체적으로 어떠하다
  - 헤더 파일(.h)에서 여러 변수 등에 대해 선언 혹은 정의를 해둠
- main 함수, 함수 이름, 매개변수, 반환 타입, 함수 body, 구문, 문자열, char의 배열, 배열의 첫 element의 주소, ... 등 간단한 예제에서도 확인할 키워드가 많음

#### 주석문
- 주석 지정 방법
  - // 한 행 전체
  - /* */ 구간 전체, 여러 행 가능
  - VS 단축키 - ctrl + k + c(주석 지정), ctrl + k + u(주석 해제)
- (cf.) 유지보수성 → 읽기 좋은 코드
  - 최상은 주석이 없더라도 많은 사람들이 코드의 의미를 이해할 수 있는 코드
  - 하지만 그 정도의 코드 작성은 어려우므로, 코드란 것이 공용 문서임을 고려하여(혹은 미래의 자신을 위해서라도) 적절히 주석을 작성
