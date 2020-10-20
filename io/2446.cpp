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
		cout << setw(idx) ;
		for(int i = idx; i <= n; i++)
			cout <<  '*';
		for(int i = idx; i < n; i++)
			cout <<  '*';
		cout << '\n' ;
	}
	for(int idx = 1; idx < n; idx++)
	{
		cout << setw(n - idx) ;
		for(int i = 1; i <= idx + 1; i++)
			cout <<'*';
		for(int i = 1; i <= idx; i++)
			cout <<'*';
		cout <<'\n' ;
	}
	return (0);
}