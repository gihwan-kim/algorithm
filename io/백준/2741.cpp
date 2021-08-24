#include <iostream>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	int _n;

	_n = 0;
	cin >> n;
	while (n--)
		cout << ++_n << '\n';
	return (0);
}