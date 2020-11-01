#include <iostream>
/**
 * 방법 1)
 * 처음에는 연속된 수가 0 ~ n 개일때의 모든 경우를 구한뒤
 * table 의 idx 의 값과 연속된 수의 개수 와 대응시켜
 * 연속된 수의 개수 별로 최대 값을 구하여 비교하는 식으로 구현하려고
 * 했다.
 * 이렇게 할 경우 for 문을 총 3가지를 사용하게 되는데
 * 시간복잡도가 엄청나게 증가하는 문제가 있었고 코드 또한 복잡하게 될것 같았다.
 *
 *
 * 방법 2)
 * 대신에 이전의 결과값과 현재 값을 더한 결과를 현재 값과 비교해본다면
 * 만약 이전의 결과값 + 현재 index 값이 더 크다면 계속 연속해서 수를 더해도 되는 것이고
 * 만약 더 작다면 시작하는 값을 바꿔야함을 의미하기 때문에
 * 굳이 처음 생각한 방법대로 모든 연속하는 수의 개수 별로의 최대 값을 일일이 구하지 않아도
 * 되게 되었다.
 */
using namespace std;
int main()
{
	int n;
	int *arry = nullptr;
	int *table = nullptr;
	int ret;

	cin >> n;
	arry = new int[n];
	table = new int[n];
	for (int idx = 0; idx < n; idx++)
	{
		cin >> arry[idx];
	}

	table[0] = arry[0];
	ret = table[0];
	for (int idx = 0; idx < n; idx++)
	{
		table[idx] = max(table[idx-1] + arry[idx], arry[idx]);
		ret = max(table[idx], ret);
	}
	cout << ret;
}