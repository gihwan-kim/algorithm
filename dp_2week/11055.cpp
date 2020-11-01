#include <iostream>

using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL);
	int n;
	int *arry = nullptr;
	int *table = nullptr;
	int sum;
	int max_t;

	cin >> n;
	arry = new int[n];
	table = new int[n];
	for (int idx = 0; idx < n; idx++)
	{
		cin >> arry[idx];
		table[idx] = arry[idx];
	}
	sum = 0;
	for (int idx1 = 0; idx1 < n; idx1++)
	{
		max_t = 0;
		for (int idx2 = 0; idx2 <= idx1; idx2++)
		{
			if (arry[idx2] < arry[idx1])
			{
				if (table[idx2] > max_t)
				{
					table[idx1] = arry[idx1] +  table[idx2];
					max_t = table[idx2];
				}
			}
		}
		sum = max(table[idx1], sum);
	}
	cout << sum;
}