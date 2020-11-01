#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	int *table = nullptr;
	int count;
	int N;

	cin >> n;
	table = new int[n];

	table[0] = 1;
	if (n > 1)
		table[1] = 2;
	for (int idx = 2; idx < n; idx++)
	{
		if (sqrt(idx + 1) * sqrt(idx + 1) == idx + 1 && idx != 10)
		{
			table[n-1] = 1;
			continue;
		}
		// else
		// 	count = table[0] + table[idx-1];

		// if (idx % 2)
		// 	N = (idx+1)/2;
		// else
		// 	N = idx / 2;
		// for (int idx1 = 0; idx1 < N; idx1++)
		// {
		// 	// table[idx] = min(count, table[idx1] + table[idx - idx1 - 1]);
		// 	// count = table[idx];
		// }
		table[idx] = table[0] + table[idx-1];
		cout << table[idx] << endl;
	}
	cout << table[n-1];
}