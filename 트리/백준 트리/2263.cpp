#include <iostream>
#include <bits/stdc++.h>

int inorder[100001];
int inorder_idx_position[100001];
int postorder[100001];
using namespace std;

/*
** 후위 순회의 성질 때문에 제일 마지막으로 방문한 노드가 루트노드이다.
** 후위 순회를 통해 부모 노드를 확인하면 중위 노드의 성질을 사용한다.
**
** 중위 노드의 경우 왼쪽 노드를 먼저 방문하고 부모노드, 오른쪽 노드를 방문하기 때문에
** 부모노드의 값을 알면 부모노드를 기준으로 왼쪽, 오른쪽으로 나누어줄수 있다.
**
**
** 왼쪽, 오른쪽으로 분할하여 풀기 : 분할정복
*/

void mergesort(int parent, int in_start, int in_end, int po_start, int po_end)
{
	if (in_start > in_end || po_start > po_end)
		return ;
	cout << postorder[parent] << " ";

	int inorder_idx_of_postorder_parent_value = inorder_idx_position[postorder[parent]];

	int l_i_s = in_start;
	int l_i_e = inorder_idx_of_postorder_parent_value - 1;
	int l_p_s = po_start;
	int l_p_e = po_start + (l_i_e - l_i_s);

	int r_i_s = inorder_idx_of_postorder_parent_value + 1;
	int r_i_e = in_end;
	int r_p_s = l_p_e + 1;
	int r_p_e = parent - 1;

	int left_parent = r_p_s - 1;
	int right_parent = parent - 1;

	mergesort(left_parent, l_i_s, l_i_e, l_p_s, l_p_e);
	mergesort(right_parent, r_i_s, r_i_e, r_p_s, r_p_e);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> inorder[i];
		inorder_idx_position[inorder[i]] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> postorder[i];
	}

	mergesort(n, 1, n, 1, n);
}