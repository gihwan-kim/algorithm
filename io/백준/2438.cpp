#include <iostream>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int i;

	cin >> n;
	for(int idx = 1; idx <= n; idx++)
	{
		for(int i = 0; i < idx; i++)
			cout << right << '*';
		cout << '\n';
	}
	return (0);
}