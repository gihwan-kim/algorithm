#include <iostream>

using namespace std;

int main()
{
	int n;
	int idx;
	int a, b;

	idx = 0;
	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		cout << "Case #" << ++idx << ": " << a + b << endl;
	}
	return(0);
}