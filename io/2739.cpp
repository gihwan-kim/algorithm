#include <iostream>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;
	for (int loop = 1; loop <= 9; loop++)
		cout << n << " * " << loop << " = " << n * loop << '\n';
	return (0);
}