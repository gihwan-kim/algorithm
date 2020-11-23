#include <iostream>

using namespace std;

void merge(int a_s, int mid, int end, int **table)
{
	int **tmp;
	int size;
	int tmp_idx;
	int idx_a = a_s;
	int idx_b = mid;

	size = end - a_s + 1;
	tmp = new int*[size];
	tmp_idx = 0;
	cout << idx_a << " " << idx_b << " " << end << endl;
	while (idx_a <= mid-1 && idx_b <= end)
	{
		if(table[idx_a][1] > table[idx_b][1])
		{
			cout << 'b';
			tmp[tmp_idx++] = table[idx_b++];
		}
		else if(table[idx_a][1] == table[idx_b][1])
		{
			if (table[idx_a][0] > table[idx_b][0])
			{
			cout << 'b';
				tmp[tmp_idx++] = table[idx_b++];
			}
			else
			{

			cout << 'a';
				tmp[tmp_idx++] = table[idx_a++];
			}
		}
		else
			tmp[tmp_idx++] = table[idx_a++];
	}
	for (int idx = 0; idx < tmp_idx; idx++)
		cout << tmp[idx][0] << ' '<< tmp[idx][1] << '\n';
	while (idx_a <= mid - 1)
		tmp[tmp_idx++] = table[idx_a++];
	while (idx_b <= end)
		tmp[tmp_idx++] = table[idx_b++];
	int i = 0;
	// cout << endl;
	// cout << endl;
	// cout << endl;
	// cout << endl;
	for (int idx = a_s; idx < size; idx++)
		table[idx] = tmp[i++];
	return;
}

void recursive(int start, int end, int **table)
{
	int mid;
	if (start == end)
		return;
	mid = (start + end)/2;
	recursive(start, mid, table);
	recursive(mid + 1, end, table);
	merge(start, mid + 1, end, table);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int **table = nullptr;

	cin >> n;
	table = new int*[n];
	for (int idx = 0; idx < n; idx++)
	{
		table[idx] = new int[2];
		cin >> table[idx][0] >> table[idx][1];
	}
	recursive(0, n-1, table);
	cout << endl;
	for (int idx = 0; idx < n; idx++)
		cout << table[idx][0] << ' '<< table[idx][1] << '\n';
	return 0;
}