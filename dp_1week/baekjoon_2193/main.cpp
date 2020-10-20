#include <iostream>

using namespace std;
int main()
{
	int n;
	long long *arry = nullptr;

	cin >> n;
	arry = new long long[n];

	arry[0] = 1;
	if (n >= 2)
	{
		arry[1] = 1;
		for(int idx = 2; idx < n; idx++)
			arry[idx] = arry[idx-2] + arry[idx-1];
	}
	cout << arry[n-1];
	return 0;
}