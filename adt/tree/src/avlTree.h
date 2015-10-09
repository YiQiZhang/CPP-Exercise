//
//  avlTree.h
//
//  Created by Jerry on 10/6/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "binarySearchTree.h"

using std::cout;
using std::endl;

template<typename T>
class AvlTree : public BinarySearchTree<T>
{
public:
	typedef typename BinarySearchTree<T>::position position;
	AvlTree(const T &ele) : BinarySearchTree<T>(ele)
	{
		;
	}

	virtual ~AvlTree()
	{

	}

	virtual void insert(const T &ele)
	{
		this->root = insertRecursively(this->root, ele);
	}


protected:
	virtual position insertRecursively(position p, const T &ele)
	{
		if (p == nullptr) {
			p = this->makeNewNode(ele);
		} else if(ele < p->element){
			p->left = insertRecursively(p->left, ele);
			if (height(p->left) - height(p->right) > 1) {
				if (ele < p->left->element) {
					p = rightRotateWithLeft(p);
				} else {
					p = doubleRotateWithLeft(p);
				}
			}
		} else if(ele > p->element) {
			p->right = insertRecursively(p->right, ele);
			if (height(p->right) - height(p->left) > 1) {
				if (ele > p->right->element) {
					p = leftRotateWithRight(p);
				} else {
					p = doubleRotateWithRight(p);
				}
			}
		} else {
			++p->count;
		}

		p->height = max(height(p->left), height(p->right)) + 1;

		return p;
	}

private:
	int max(int a, int b)
	{
		return a >= b ? a : b;
	}

	int height(position p)
	{
		if (p == nullptr) {
			return -1;
		} else {
			return p->height;
		}
	}

	position rightRotateWithLeft(position p)
	{
		position tmp = p->left;
		p->left = tmp->right;
		tmp->right = p;

		p->height = max(height(p->left), height(p->right)) + 1;
		tmp->height = max(height(tmp->left), p->height) + 1;

		return tmp;
	}

	position leftRotateWithRight(position p)
	{
		position tmp = p->right;
		p->right = tmp->left;
		tmp->left = p;

		p->height = max(height(p->left), height(p->right)) + 1;
		tmp->height = max(p->height, height(tmp->right)) + 1;

		return tmp;
	}

	position doubleRotateWithLeft(position p)
	{
		p->left = leftRotateWithRight(p->left);

		return rightRotateWithLeft(p);
	}

	position doubleRotateWithRight(position p)
	{
		p->right = rightRotateWithLeft(p->right);

		return leftRotateWithRight(p);
	}
};

#endif