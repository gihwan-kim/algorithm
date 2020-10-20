#include <iostream>

using namespace std;
int main()
{
	int n;
	int row_1[10] = {1,1,1,1,1,1,1,1,1,1};
	int **table = nullptr;
	int result = 0;

	cin >> n;
	table = new int*[n];
	table[0] = row_1;
	for (int idx = 1; idx < n; idx++)
	{
		table[idx] = new int[10]{0};
		for (int r_idx = 0; r_idx < 10; r_idx++)
		{
			for (int r_idx_1 = 0; r_idx_1 <= r_idx; r_idx_1++)
				table[idx][r_idx] = (table[idx][r_idx] + table[idx-1][r_idx_1] % 10007);
		}
	}
	for (int idx = 0; idx < 10; idx++)
		result = (result + table[n-1][idx]) % 10007;
	cout << result << endl;
	for (int idx = 1; idx < n; idx++)
		delete(table[idx]);
	delete table;
}