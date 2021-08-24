#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node *parent;
	Node *left;
	Node *right;
	Node(int _data)
	: left(nullptr), right(nullptr), parent(nullptr) {}

	Node(int _data, Node *_left, Node *_right, Node *_parent)
	: data(_data), left(_left), right(_right), parent(_parent) {}
};

class BinaryTree
{
public:
	Node *root;


	Node *add(Node *curNode, Node *newNode)
	{
		if (curNode == nullptr)
			return (newNode);
		if (curNode->left == nullptr)
			curNode->left = add(curNode->left, newNode);
		else
			curNode->right = add(curNode->right, newNode);
		return (curNode);
	}

	// 부모 먼저 탐색
	void preorder(Node *node, int search)
	{
		if (node == nullptr)
			return ;
		if (node->data == search)
			cout << node->parent->data << '\n';
		preorder(node->left, search);
		preorder(node->right, search);
	}

	void postorder(Node *node, int search)
	{
		postorder(node->left, search);
		postorder(node->right, search);
		if (node == nullptr)
			return ;
		if (node->data == search)
			cout << node->parent->data << '\n';
	}

	void inorder(Node *node, int search)
	{
		inorder(node->left, search);
		if (node == nullptr)
			return ;
		if (node->data == search)
			cout << node->parent->data << '\n';
		inorder(node->right, search);
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<int, Node*> my_map;
	BinaryTree bt;
	int n = 0;

	my_map.insert({1, new Node(1)});
	bt.root = my_map[1];
	for (int i = 0; i < n; ++i)
	{
		Node *a;
		Node *b;
		int key_a;
		int key_b;
		cin >> key_a >> key_b;
		if (my_map.insert({key_a, new Node(key_a)}).second)
			;
		if (my_map.insert({key_b, new Node(key_b)}).second)
			;
		a = my_map[key_a];
		b = my_map[key_b];

		bt.add()
	}

}