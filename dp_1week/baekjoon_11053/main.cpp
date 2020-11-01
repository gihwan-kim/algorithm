#include <iostream>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    int *arry = nullptr;
    int *table = nullptr;
    int count = 0;
    int a;

    cin >> n;
    arry = new int[n];
    table = new int[n];
    for (int idx = 0; idx < n; idx++)
    {
        cin >> arry[idx];
		table[idx] = 1;
    }
	count = table[0];
	for (int idx = 0; idx < n; idx++)
	{
		a = 0;
		for (int idx1 = 0; idx1 <= idx; idx1++)
		{
			// 기준 값보다 작은 경우 순열에 포함된다.
			if (arry[idx] > arry[idx1])
			{
				// a 는 기준값 arry[idx] 보다 작은 값들 중에서 순열의 길이가 가장긴 값이다.
				if (a < table[idx1])
					a = table[idx1];
			}
			table[idx] = a + 1;
		}
		count = max(count, table[idx]);
	}
	cout << count;
    return (0);
}