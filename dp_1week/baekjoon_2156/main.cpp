#include <iostream>
using namespace std;
int main()
{
	int n;
	int *arry = nullptr;
	int *table = nullptr;

	cin >> n;
	arry = new int[n];
	table = new int[n];
	for (int idx = 0; idx < n; idx++)
		cin >> arry[idx];
	table [0] = arry[0];
	if (n >= 2)
		table[1] = arry[0] + arry[1];
	for (int idx = 2; idx < n; idx++)
	{
		table[idx] = max(table[idx - 2] + arry[idx], table[idx - 1]);
		table[idx] = max(table[idx], table[idx - 3] + arry[idx - 1] + arry[idx]);
	}
	cout << table[n - 1];
}