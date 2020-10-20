#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int i;

	cin >> n;
	for(int idx = 1; idx <= n; idx++)
	{
		for(int i = 1; i <= idx; i++)
			cout << left << '*';
		cout << setw(2 *(n - idx) + 1) ;
		for(int i = 1; i <= idx; i++)
			cout << right << '*';
		cout << '\n' ;
	}
	for(int idx = 1; idx < n; idx++)
	{
		for(int i = idx; i < n; i++)
			cout << left << '*';
		cout << setw(2 *idx + 1) ;
		for(int i = idx; i < n; i++)
			cout << right << '*';
		cout << '\n' ;
	}
	return (0);
}