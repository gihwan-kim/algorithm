#include <iostream>

using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL);
	int n;
	int *arry = nullptr;
	int *table = nullptr;
	int max_t;
	int ret = 0;

	cin >> n;
	arry = new int[n];
	table = new int[n];
	for (int idx = 0; idx < n; idx++)
	{
		cin>> arry[idx];
		table[idx] = 1;
	}
	for (int idx1 = n-1; idx1 >= 0; idx1--)
	{
		max_t = 0;
		for (int idx2 = n-1; idx2 >= idx1; idx2--)
		{
			if (arry[idx1] > arry[idx2])
			{
				if (max_t < table[idx2])
				{
					table[idx1] = table[idx2] + 1;
					max_t = table[idx2];
				}
			}
		}
		ret = max(ret, table[idx1]);
	}
	cout << ret;
}