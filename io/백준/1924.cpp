#include <iostream>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int m;
	int d;
	int _m;
	int _d_sum;
	string boundary[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

	cin >> m >> d;

	_d_sum = 0;
	for (int _m = 1; _m < m; _m++)
	{
		if (_m == 4 || _m == 6 || _m == 9 || _m == 11)
			_d_sum += 30;
		else if (_m == 2)
			_d_sum += 28;
		else
			_d_sum += 31;
	}
	_d_sum += d;

	cout << boundary[_d_sum % 7];
}