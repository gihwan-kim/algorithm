#include <iostream>

using namespace std;
int main()
{
	int n;
	int *arry = nullptr;
	int *table1 = nullptr;
	int *table2 = nullptr;
	int max_t;
	int sum;
	int ret;

	cin >> n;
	arry =  new int[n];
	table1 = new int[n];
	table2 = new int[n];
	for (int idx = 0; idx < n; idx++)
	{
		cin >> arry[idx];
		table1[idx] = 1;
		table2[idx] = 1;
	}

	for (int idx1 = 0; idx1 < n; idx1++)
	{
		max_t = 0;
		for (int idx2 = 0; idx2 <= idx1; idx2++)
		{
			if (arry[idx1] > arry[idx2])
			{
				if (max_t < table1[idx2])
				{
					table1[idx1] = table1[idx2] + 1;
					max_t = table1[idx2];
				}
			}
		}
	}
	ret = 0;
	for (int idx1 = n - 1; idx1 >= 0; idx1--)
	{
		max_t = 0;
		for (int idx2 = n - 1 ; idx2 >= idx1; idx2--)
		{
			if (arry[idx1] > arry[idx2])
			{
				if (max_t < table2[idx2])
				{
					table2[idx1] = table2[idx2] + 1;
					max_t = table2[idx2];
				}
			}
		}
		sum = table1[idx1] + table2[idx1];
		ret = max(ret, sum);
	}
	cout << ret - 1;
}