#include <map>
#include <cstring>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>


// 개수
// 노드 왼 오
// ...

// A : 루트노드

using namespace std;

class Node
{
public:
	char data;
	Node *left;
	Node *right;

	Node(char _data)
	: data(_data), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
	Node *root;

	BinaryTree(Node *_root)
	: root(_root) {}

	void preorder(Node *node)
	{
		if (node == nullptr)
			return;
		cout << node->data;
		preorder(node->left);
		preorder(node->right);
	}

	void inorder(Node *node)
	{
		if (node == nullptr)
			return;
		inorder(node->left);
		cout << node->data;
		inorder(node->right);

	}

	void postorder(Node *node)
	{
		if (node == nullptr)
			return;
		postorder(node->left);
		postorder(node->right);
		cout << node->data;
	}
};

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int n;
	map<char, Node*> my_map;

		// cout << "wow";
	cin >> n;
	string a;
		// cout << "wow";
	getline(cin, a);
		// cout << "wow";
	for (int i = 0; i < n; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;
		my_map.insert({parent, new Node(parent)});
		if (left != '.')
		{
			my_map.insert({left, new Node(left)});
			my_map[parent]->left = my_map[left];

		}
		if (right != '.')
		{
			my_map.insert({right, new Node(right)});
			my_map[parent]->right = my_map[right];
		}
		// cout << parent <<  my_map[parent] << endl;
		// cout << "left" <<  my_map[left] << endl;
		// cout << "right" <<  my_map[right] << endl;
	}

	BinaryTree bt(my_map['A']);

	bt.preorder(bt.root);
	cout << '\n';
	bt.inorder(bt.root);
	cout << '\n';
	bt.postorder(bt.root);
	cout << '\n';
}