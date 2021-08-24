#include <iostream>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int sum = 0;
	string str;

	cin >> n >> str;
	while (n--)
		sum += (str[n] - '0');
	cout << sum;
}