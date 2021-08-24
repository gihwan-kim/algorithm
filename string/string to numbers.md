# string 을 숫자로 바꾸는 방법들



### (1) stringstream


표준 입력을 받는 것처럼 변환할 데이터형으로 >> 연산자를 넣어주면 된다.

```
stringstream ss(str);

int integer;

ss >> integer;

```




### (2) stoi(), atoi() ...


1. atoi()
> c 스타일 함수
> c 스타일 문자열에서만 작동한다.

2. stoi()
>C++11 함수
> c 스타일, c++ 스타일 모두 작동
