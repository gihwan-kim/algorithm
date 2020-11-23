#include <iostream>

using namespace std;
int main()
{
	int n;
	int *arry = nullptr;
	int *table = nullptr;
	int ret;

	cin >> n;
	arry = new int[n+1];
	table = new int[n+1];
	for (int idx = 1; idx <= n; idx++)
	{
		cin >> arry[idx];
		table[idx] = arry[idx];
	}
	table[0] = 0;
	// 5 인경우
	// 5 + 0
	// 4 + 1  -> (4 일떄의 값 + 1 일떄의 값) 과 이전의 값(5 + 1 일 경우) 비교
	// 3 + 2
	// ...

	for (int i = 1; i <= n; i++)
	{
		ret = arry[i];
		for (int j = 1; j <= i; j++)
		{
			ret = max(ret, table[i-j] + table[j]);
			table[i] = ret;
		}
	}
	cout << table[n];
}