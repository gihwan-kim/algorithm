#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int i;
	int j;

	cin >> n;
	for(int idx = 1; idx <= n; idx++)
	{
		if (idx == n)
		{
			for (int idx = 1; idx <= 2 * n -1 ; idx++)
				cout << '*';
		}
		else
		{
			cout << setw(n - idx + 1);
			cout << '*';
			if (idx >= 2)
			{
				j = idx;
				for (int idx = 1; idx <= 2* (j - 1) -1; idx++)
					cout << ' ';
				cout << '*';
			}
		}
		cout << '\n';
	}
	return (0);
}