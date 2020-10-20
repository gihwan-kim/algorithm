#include <iostream>

using namespace std;

int main()
{
	int n;
	int a;
	int b;

	cin >> n;
	while (n--)
	{
		cin >> a;
		cin.clear();
		cin.get();
		cin >> b;
		cout << a + b << endl;
	}
	return (0);
}