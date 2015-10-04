//
//  binarySearchTree.h
//  normaltree
//
//  Created by Jerry on 10/1/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <string>

using std::ostream;
using std::endl;
using std::string;

template <typename> class BinarySearchTree;
template <typename T> ostream &operator<<(ostream &, const BinarySearchTree<T> &);

template <typename T>
class BinarySearchTree
{
	friend ostream &operator<<<T>(ostream &, const BinarySearchTree<T> &);
public:
	struct TreeNode;
	typedef TreeNode *position;
	struct TreeNode{
		T element;
		position left;
		position right;
		int count;
	};
	typedef T valueType;

	BinarySearchTree(const T &ele) : root(makeNewNode(ele))
	{

	}

	virtual ~BinarySearchTree()
	{

	}

	void insert(const T &ele)
	{
		bool isInserted = false;
		position target = root;
		while (!isInserted) {
			if (ele == target->element) {
				++target->count;
				isInserted = true;
			} else if (ele < target->element) {
				if (target->left == NULL) {
					target->left = makeNewNode(ele);
					isInserted = true;
				} else {
					target = target->left;
				}
			} else {
				if (target->right == NULL) {
					target->right = makeNewNode(ele);
					isInserted = true;
				} else {
					target = target->right;
				}
			}
		}
	}

	position find(const T &ele) const
	{
		return findRecursively(root, ele);
	}

	void softDelete(const T &ele)
	{
		position p = find(ele);
		if (p != NULL) {
			p->count = 0;
		}
	}

	void hardDelete(const T &ele)
	{
		root = hardDeleteRecursively(ele, root);
	}
private:
	position root;

	position makeNewNode(const T &ele)
	{
		position p = new TreeNode;
		p->element = ele;
		p->left = p->right = NULL;
		p->count = 1;

		return p;
	}

	void printRecursively(ostream &os, position node, int deep) const
	{
		if (deep > 0) {
			string space(deep * 2, '-');
			os << space << node->element << '(' << node->count << ')' << endl;
		} else {
			os << node->element << '(' << node->count << ')' << endl;
		}

		if (node->left != NULL) {
			printRecursively(os, node->left, deep + 1);
		}
		if (node->right != NULL) {
			printRecursively(os, node->right, deep + 1);
		}
	}

	position findRecursively(position p, const T &ele) const
	{
		if (ele == p->element) {
			if (p->count > 0){
				return p;
			} else {
				return NULL;
			}
		} else  if (ele < p->element) {
			if (p->left != NULL) {
				return findRecursively(p->left, ele);
			} else {
				return NULL;
			}
		} else {
			if (p->right != NULL) {
				return findRecursively(p->right, ele);
			} else {
				return NULL;
			}
		}
	}

	position hardDeleteRecursively(const T &ele, position p)
	{
		if (p == NULL) {
			
		} else if (ele < p->element) {
			p->left = hardDeleteRecursively(ele, p->left);
		} else if (ele > p->element) {
			p->right = hardDeleteRecursively(ele, p->right);
		} else if (p->left != NULL && p->right != NULL) {
			position min = findMin(p->right);
			p->element = min->element;
			p->count = min->count;
			p->right = hardDeleteRecursively(p->element, p->right);
		} else {
			position tmp = p;
			if (p->left != NULL) {
				p = p->left;
			} else if (p->right != NULL) {
				p = p->right;
			}
			delete tmp;
		}

		return p;
	}

	position findMin(position p)
	{
		position res = p;
		while (res->left != NULL)
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