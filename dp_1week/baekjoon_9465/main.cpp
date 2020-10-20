#include <iostream>

using namespace std;
int main()
{
	int n;
	int col;
	int **arry = nullptr;
	int **result = nullptr;
	int *print = nullptr;

	cin >> n;
	print = new int[n];
	for (int loop = 0; loop < n; loop++)
	{
		cin >> col;
		arry = new int*[2];
		result = new int*[2];
		for (int idx = 0; idx < 2; idx++)
		{
			arry[idx] = new int[col];
			result[idx] = new int[col];
			for (int idx2 = 0; idx2 < col; idx2++)
				cin >> arry[idx][idx2];
		}
		result[0][0] = arry[0][0];
		result[1][0] = arry[1][0];
		result[0][1] = arry[0][1] + arry[1][0];
		result[1][1] = arry[1][1] + arry[0][0];
		for (int i = 2; i < col; i++)
		{
			result[0][i] = arry[0][i] + max(result[1][i - 1], result[1][i - 2]);
			result[1][i] = arry[1][i] + max(result[0][i - 1], result[0][i - 2]);
		}
		cout <<  max(result[0][col-1], result[1][col-1]) << endl;
	}
	return 0;
}