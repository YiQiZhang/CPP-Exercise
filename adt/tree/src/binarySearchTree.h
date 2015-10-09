//
//  binarySearchTree.h
//
//  Created by Jerry on 10/1/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <string>

using std::ostream;
using std::endl;
using std::string;
using std::shared_ptr;

template <typename> class BinarySearchTree;
template <typename T> ostream &operator<<(ostream &, const BinarySearchTree<T> &);

template <typename T>
class BinarySearchTree
{
	friend ostream &operator<<<T>(ostream &, const BinarySearchTree<T> &);
public:
	struct TreeNode;
	typedef shared_ptr<TreeNode> position;
	struct TreeNode{
		T element;
		position left;
		position right;
		int count;
		int height;
	};
	typedef T valueType;

	BinarySearchTree(const T &ele) : root(makeNewNode(ele))
	{

	}

	virtual ~BinarySearchTree()
	{

	}

	position find(const T &ele) const
	{
		return findRecursively(root, ele);
	}

	virtual void insert(const T &ele)
	{
		root = insertRecursively(root, ele);
	}

	virtual void softDelete(const T &ele)
	{
		position p = find(ele);
		if (p != nullptr) {
			p->count = 0;
		}
	}

	virtual void hardDelete(const T &ele)
	{
		root = hardDeleteRecursively(ele, root);
	}
protected:
	position root;

	position makeNewNode(const T &ele)
	{
		position p(new TreeNode);
		p->element = ele;
		p->left = p->right = nullptr;
		p->count = 1;
		p->height = 0;

		return p;
	}

	void printRecursively(ostream &os, position node, int deep) const
	{
		if (deep > 0) {
			string space(deep * 2, '-');
			os << space << node->element << "(count: " << node->count << "; height: "  << node->height << ")" << endl;
		} else {
			os << node->element << "(count: " << node->count << "; height: "  << node->height << ")" << endl;
		}

		if (node->left != nullptr) {
			printRecursively(os, node->left, deep + 1);
		}
		if (node->right != nullptr) {
			printRecursively(os, node->right, deep + 1);
		}
	}

	position findRecursively(position p, const T &ele) const
	{
		if (ele == p->element) {
			if (p->count > 0){
				return p;
			} else {
				return nullptr;
			}
		} else  if (ele < p->element) {
			if (p->left != nullptr) {
				return findRecursively(p->left, ele);
			} else {
				return nullptr;
			}
		} else {
			if (p->right != nullptr) {
				return findRecursively(p->right, ele);
			} else {
				return nullptr;
			}
		}
	}

	virtual position insertRecursively(position p, const T &ele)
	{
		if (p == nullptr) {
			p = makeNewNode(ele);
		} else if (p->element == ele) {
			++p->count;
		} else if (p->element < ele) {
			p->right = insertRecursively(p->right, ele);
		} else {
			p->left = insertRecursively(p->left, ele);
		}

		return p;
	}

	virtual position hardDeleteRecursively(const T &ele, position p)
	{
		if (p == nullptr) {
			
		} else if (ele < p->element) {
			p->left = hardDeleteRecursively(ele, p->left);
		} else if (ele > p->element) {
			p->right = hardDeleteRecursively(ele, p->right);
		} else if (p->left != nullptr && p->right != nullptr) {
			position min = findMin(p->right);
			p->element = min->element;
			p->count = min->count;
			p->right = hardDeleteRecursively(p->element, p->right);
		} else {
			position tmp = p;
			if (p->left != nullptr) {
				p = p->left;
			} else if (p->right != nullptr) {
				p = p->right;
			}
		}

		return p;
	}

	position findMin(position p)
	{
		position res = p;
		while (res->left != nullptr)
			res = res->left;
		return res;
	}
};

template <typename T>
ostream &operator<<(ostream &os, const BinarySearchTree<T> &tree)
{
	typename BinarySearchTree<T>::position node = tree.root;
	tree.printRecursively(os, node, 0);

	return os;
}

#endif