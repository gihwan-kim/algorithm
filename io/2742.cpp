#include <iostream>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;

	cin >> n;
	while (n)
		cout << n-- << '\n';
	return (0);
}