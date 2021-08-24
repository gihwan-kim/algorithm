
// 그래프 :

// 트리 : 사이클이 없는 연결 요소
// 	정점 n	 개
// 	간선 n-1 개
// 	임의의 두 정점에 대해서 경로가 유일하다. (사이클이 없다)

// n	정점의 개수
// m	간선의 개수

// n <= 500
// m < n(n-1)/

#include <iostream>
#include <set>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


// check_only_foward_val : 노드를 탐색하면서 이동할때 아래로만 내려가도록
//
bool search(vector<int> *array, int idx, bool *checker, int check_only_foward_val)
{
	// cout << idx << " ";
	checker[idx] = true;
 	for (int &data : array[idx])
	{
		if (data == check_only_foward_val)
			continue ;
		if (checker[data])
			return (false); // 순환
		if (!search(array, data, checker, idx))
			return (false);
	}
	return (true);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num = 0;
	while (1)
	{
		int n, m;

		num++;
		int cnt = 0;
		cin >> n >> m;
		vector<int> array[n+1];
		bool checker[n+1] = {false};
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= m; ++i)
		{
			int v_a, v_b;

			cin >> v_a >> v_b;
			array[v_a].push_back(v_b);
			array[v_b].push_back(v_a);
		}
		int idx = 1;

		for (int i = 1; i <= n; ++i)
		{
			if (!checker[i])
				if (search(array, i, checker, 0))
					cnt++;
		}


		cout << "Case " << num << ": ";
		if (cnt > 1)
			cout << "A forest of " << cnt << " trees.\n";
		else if (cnt == 1)
			cout << "There is one tree.\n";
		else
			cout << "No trees.\n";
	}
}