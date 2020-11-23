#include <iostream>
/**
 *
 * 내가 생각한 dp 풀이 방법들을 정리해보았다.
 *
 * dp 문제 접근 전락
 * 1. 낮은 값 -> 높은 값으로
 * 2. 높은 값 -> 낮은 값으로
 *
 * 데이터 표현법
 * 1. 가지치기
 * 2. 표
 *
 * 현재 문제는 1 번 접근 전략으로 진행했다.
 * 정수가 1 개일때부터 k 개일때까지 N 이 되는 데이터들을
 * 표로 표시해보니 규칙을 쉽게 찾을 수 있었다.
**/
using namespace std;
int main()
{
	int n;
	int k;
	int **table = nullptr;
	cin >> n;
	cin >> k;
	table = new int *[k];
	for (int idx = 0; idx < k; idx++)
		table[idx] = new int[n];
	for (int idx = 0; idx < n; idx++)
		table[0][idx] = 1;
	for (int idx1 = 1; idx1 < k; idx1++)
	{
		table[idx1][0] = idx1 + 1;
		for (int idx2 = 1; idx2 < n; idx2++)
			table[idx1][idx2] = (table[idx1-1][idx2] + table[idx1][idx2-1]) % 1000000000;
	}
	cout << table[k-1][n-1];
}