#include <iostream>

using namespace std;

void change(int arry1, int arry2, int last, int *arry, int *table)
{
	int tmp;
	int idx_t;
	idx_t = 0;
	for (int idx = arry1; idx <= arry2-1; idx++)
	{
			for (int idx1 = arry2; idx1 <= last; idx1++)
			{
				if (arry[idx] > arry[idx1])
				{
					table[idx_t] = arry[idx1];
					arry2 = idx1;
					idx_t++;
				}
				else
				{
					table[idx_t] = arry[idx];
					idx_t++;
				}
			}
	}
	if (arry2 < last)
	{
		for(int idx = arry2; idx <= last; idx++)
		{
			table[idx_t] = arry[idx];
			idx_t++;
		}
	}
}
void recursive(int start, int last, int *arry, int *table)
{
	if ((last == start))
		return ;
	recursive(start, (start+last)/2, arry, table);
	recursive((start+last)/2 + 1, last, arry, table);
	change(start, (start+last)/2 + 1, last, arry, table);
}

int main()
{
	int n;
	int *arry = nullptr;
	int *table = nullptr;

	cin >> n;
	arry = new int[n];
	table = new int[n];
	for (int idx = 0; idx < n; idx++)
	{
		cin >> arry[idx];
	}
	recursive(0, n-1, arry, table);
	for (int idx = 0; idx < n; idx++)
	{
		cout << table[idx] << endl;
	}
}
