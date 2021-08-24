#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	string str;
	vector<char> vec;

	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		vec.push_back(str[i]);
	}

	sort(vec.begin(), vec.end());

	for (int i = vec.size() - 1; i != -1; --i)
	{
		cout << vec[i];
	}

}