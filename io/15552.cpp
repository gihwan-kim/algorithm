#include <iostream>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	int idx;
	int a, b;

	idx = 0;
	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		cout << a+b  <<'\n';
	}
	return(0);
}