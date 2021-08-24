// 입력
// 트리를 전위 순회한 결과가 주어진다. 노드에 들어있는 키의 값은 106보다 작은 양의 정수이다.
// 모든 값은 한 줄에 하나씩 주어지며, 노드의 수는 10,000개 이하이다. 같은 키를 가지는 노드는 없다.


// 전위 순회
// 부모 노드 -> 왼쪽 -> 오른쪽


// 입력의 첫번째 : 루트노드


// 출력
// 후위 순회 (postorder)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;



class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int _data)
	: data(_data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
	Node *root;

	BinarySearchTree(Node *_root)
	: root(_root) {}

	void postorder(Node *node)
	{
		if (node == nullptr)
			return ;
		postorder(node->left);
		postorder(node->right);
		cout << node->data << endl;;
	}


};

int num = 0;
vector<int> vec_data;
vector<Node*> vec_node;

Node *insert(Node *root , Node *node)
{
	if (root == nullptr)
		return (node);
	if (root->data > node->data)
		root->left = insert(root->left, node);
	else
		root->right = insert(root->right, node);
	return (root);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		int data;
		cin >> data;
		if (cin.eof() == 1) break;
		num++;
		vec_data.push_back(data);
		vec_node.push_back(new Node(data));
	}
	for (int i = 1; i < num; i++)
		insert(vec_node[0], vec_node[i]);

	BinarySearchTree bst(vec_node[0]);

	bst.postorder(bst.root);
}
