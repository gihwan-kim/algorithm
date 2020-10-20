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
		printf("Case #%d: %d + %d = %d\n", ++idx, a, b, a + b);
	}
	return(0);
}