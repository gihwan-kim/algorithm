#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	unsigned long *arry = nullptr;

	cin >> n;
	arry = new unsigned long[n];
	if (n >= 1)
		arry[0] = 1;
	if (n >= 2)
		arry[1] = 2;
	if (n >= 3)
		arry[2] = 3;
	if (n > 3)
	{
		for (int idx = 3; idx < n; idx++)
			arry[idx] = (arry[idx-1] + arry[idx-2]) % 10007;
	}
	cout << arry[n-1];
}