#include <iostream>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int clear;
	int arry[10000] = {0};
	int num;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arry[num-1] += 1;
	}
	// 처음에 10000 d이 아닌 n 을 했었는데
	// n 일 경우 숫자들 중에 n 보다 같거나 크고 10000 보다 작거나 같은
	// 값이 올수 있기 때문에 n 까지의 값의 개수들만 출력이 되는 문제가 발생한다.
	for (int i = 0; i < 10000; i++)
	{
		while (arry[i]--)
			cout << i+1 << '\n';
	}
	return 0;
}