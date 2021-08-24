#include <vector>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

class Data
{
public:
	int a;
	int b;
	Data(int &_a, int &_b)
	: a(_a), b(_b)
	{}
	Data(){}
};


bool compare(const Data &obj_a, const Data &obj_b)
{
	int res_b = obj_a.b - obj_b.b;
	int res_a = obj_a.a - obj_b.a;
	if (res_b < 0)
		return (true);
	else if (res_b == 0)
		return (obj_a.a < obj_b.a);
	else
		return (false);
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	vector<Data> vec;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		Data data;
		cin >> data.a >> data.b;
		vec.push_back(data);
	}

	sort(vec.begin(), vec.end(), compare);
	for (const auto &iter : vec)
	{
		cout << iter.a << " " << iter.b << '\n';
	}

}