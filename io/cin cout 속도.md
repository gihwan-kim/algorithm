- [참고 사이트](https://www.geeksforgeeks.org/fast-io-for-competitive-programming/)

```
#include <bits/stdc++.h>
```

scanf/print 가 cin/cout 보다 입 출력 속도가 빠르다.


# sync_with_stdio

```
 ios_base::sync_with_stdio(false);
 defalut 값 : true
```

- 모든 c++ 표준 스트림(표준 C 스트림에 상응)의 동기화를 끄거나 켜는 기능
- 처음 입력이나 출력이 실행되기전에 호출됨


# tie
- std::cin 이 입력을 받아들이기 전에 std::cout 을 비우는 것을 보장한다.

```
 cin.tie(NULL);
```