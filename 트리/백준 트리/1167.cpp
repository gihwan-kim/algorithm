// 정점의 개수
// 정점번호 (정점번호 거리) (정점번호 거리) (정점번호 거리) ... -1
#include <vector>
#include <cstring>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>


// https://donggoolosori.github.io/2020/10/12/boj-1167/
using namespace std;

class Data
{
public:
	int idx;
	int len;
};

class Node
{
public:
	vector<Data> vec;
};
int max_len = 0;

void search(Node *array, bool *checker, int cur_idx, int cur_len)
{
	if (checker[cur_idx]) // 방문한적 있음
		return ;
	checker[cur_idx] = true;
	if (max_len < cur_len)
		max_len = cur_len;
	for (Data &data : array[cur_idx].vec)
	{
		search(array, checker, data.idx, cur_len + data.len);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v = 0;
	cin >> v;
	Node array[v];
	string a;
	getline(cin, a);
	for (int i = 0; i < v; ++i)
	{
		string str;
		getline(cin, str);
		stringstream ss(str);
		int cur_idx;
		ss >> cur_idx;
		int val = 0;
		while (ss >> val && val != -1)
		{
			Data data;
			data.idx = val - 1;
			ss >> val;
			data.len = val;
			array[cur_idx - 1].vec.push_back(data);
		}
	}

	for (int i = 0; i < v; ++i)
	{
		bool checker[v] = {false};
		search(array, checker, i, 0);
	}
	cout << max_len;
	return (0);
}


// 5
// array
// --------
// 1 		vec|3
// 2 		vec|4
// 3 		vec|1 4
// 4 		vec|2 3 5
// 5 		vec|4

// 방법 1. brute  : 완전 탐색

// 각각의 노드들이 시작위치일때 루프 돌리기
// 모든 노드들에대해 조사해야함
// 	긱 노드들이 시작위치가 될때마다 방문했는지 확인하는 배열을 초기화해주어야한다?
// 	for 문이 중첩되며 재귀함수가 작동하게됨 ( 매우 느려짐 )


// 방법 2.
// 	예를 들어 0 에서 시작하는 경우에서
// 		0 을 통해 다른 노드들에 도착을 한다.
// 		0 일 떄 최대 길이를 구한다.
// 	0 이 도착하지 않은 노드들 중에서 구하면 되지 않을 까?
// 	0 이 자나가는 노드들이 시작노드일때 최대 길이는 0 일 때 최대길이를 구하는 과정에서 구했었기 때문에 또 계산하지 않아도됨
// => 불가능함
//		찾는 과정에서 연결된 모든 노드에 접근하기 때문에 도착하지 않을 수가 없다.

// 방법 3.
// 모든 노드들을 조사하지 않고 구하는 방법이 필요하다.


// 조사할때 이전에 방문한 노드는 다시 방문하지 않도록 해야한다.
