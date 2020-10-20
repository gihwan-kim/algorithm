#include <iostream>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int new_n;
	int max = 0;
	int min = 0;

	cin >> n;
	cin >> new_n;
	max = min = new_n;
	while (--n)
	{
		cin >> new_n;
		if (max <= new_n)
			max = new_n;
		if (min >= new_n)
			min = new_n;
	}
	cout << min << " " << max;
	return (0);
}