#include <iostream>
#include <cstring>

using namespace std;
int main()
{
	string n;
	string tmp;
	int tmp_i;
	int *table = nullptr;
	int len;

	cin >> n;
	len = n.size();
	table = new int [len];
	// if (n[0] > '2')
		table[0] = 1;
	// else
	// 	table[0] = 0;
	for (int idx = 1; idx < len; idx++)
	{
		tmp = n.substr(idx-1, 2);
		tmp_i = stoi(tmp);
		if (tmp_i <= 26)
		{
			if (idx > 2)
				table[idx] = (table[idx-1] +  2)%1000000;
			else
				table[idx] = (table[idx-1] +  1)%1000000;
		}
		else
			table[idx] = (table[idx-1])%1000000;
	}
	cout << table[len-1];
}