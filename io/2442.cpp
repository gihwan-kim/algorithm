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
		cout << setw(n - idx + 1) ;
		for(int i = 1; i <= 2*idx - 1; i++)
			cout << right << '*';
		cout << '\n';
	}
	return (0);
}