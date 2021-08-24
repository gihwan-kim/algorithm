#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool compare(int &a, int &b)
{
	return (a > b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	vector<int> vec;
	vector<int> sorted_vec;
	for (int i = 0; i < n; ++i)
	{
		int data ;
		cin >> data;
		sorted_vec.push_back(data);
		vec.push_back(data);
	}

	sort(sorted_vec.begin(), sorted_vec.end());
	auto last = unique(sorted_vec.begin(), sorted_vec.end());
	// sorted_vec.erase(last, sorted_vec.end());
	sorted_vec.resize(last - sorted_vec.begin());
	for (int i : vec)
	{
		cout << lower_bound(sorted_vec.begin(), sorted_vec.end(), i) - sorted_vec.begin() << " ";
		// cout << *lower_bound(sorted_vec.begin(), sorted_vec.end(), vec[i]) << '\n';
	}

}