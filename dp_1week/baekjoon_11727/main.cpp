#include <iostream>

using namespace std;
int main()
{
	int n = 0;
	int *arry = nullptr;

	cin >> n;
	arry = new int[n];

	arry[0] = 1;
	if (n >=2)
	{
		arry[1] = 3;
		for (int idx = 2; idx < n; idx++)
			arry[idx] = (arry[idx-1] + 2 * arry[idx-2]) % 10007;
	}
	cout << arry[n-1];
}