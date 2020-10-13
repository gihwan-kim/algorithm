#include <iostream>
#include <math.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int c;
    int count = 1;
	int *arry = nullptr;

    cin >> c;
	arry = (int*)calloc(c, sizeof(int));

	while (++count <= c)
	{
		arry[count] = arry[count-1] + 1;
		if (!(count % 2))
			arry[count] = fmin(arry[count], arry[count/2] + 1);
		if (!(count % 3))
			arry[count] = fmin(arry[count], arry[count/3] + 1);
	}
	cout << arry[count-1];
    return 0;
}