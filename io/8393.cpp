#include <iostream>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int sum = 0;

	cin >> n;
	while (n)
		sum += n--;
	cout << sum;
	return (0);
}