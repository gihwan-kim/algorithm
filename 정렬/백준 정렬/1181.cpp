#include <algorithm>
// #include <vector>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
** [방법 1]
** map 을 사용해서 데이터의 중복을 방지
** 데이터들을 정렬하기 위해 vector 에 데이터를 옮겨 sort 정렬 사용
*/

/*
bool comp(const pair<string, int> & a, const pair<string, int> & b)
{
	string str_a = a.first;
	string str_b = b.first;
	int re = str_a.length() - str_b.length();
	if (re > 0)
		return (false);
	else if (re == 0)
	{
		if (str_a < str_b)
			return (true);
		else
			return (false);
	}
	else
		return (true);

}
*/

/*

int main()
{
	ios_base::sync_with_stdio(false);
	int n = 0;
	vector<pair<string, int>> vec;
	map<string, int> my_map;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		// vec.push_back(str);
		my_map.insert({str, 0});
	}

	vec.assign(my_map.begin(), my_map.end());
	sort(vec.begin(), vec.end(), comp);
	for (const auto &iter : vec)
	{
		cout << iter.first << '\n';
	}
}
*/

/*
** [방법2]
**
** 비교 함수 객체를 만들어 map 의 key 값 정렬 기준을 바꿔
** 데이터를 넣자마자 정렬이 되도록 구현
** map 에 담긴 데이터를 다시 vector 에 옮길 필요가 없어졌다.
*/

struct classcomp {
	bool operator()(const string & a, const string & b) const
	{
		int re = a.length() - b.length();
		if (re > 0)
			return (false);
		else if (re == 0)
			if (a < b)
				return (true);
		return (true);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	int n = 0;
	map<string, int, classcomp> my_map;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		my_map.insert({str, 0});
	}

	for (const auto &iter : my_map)
	{
		cout << iter.first << '\n';
	}
}