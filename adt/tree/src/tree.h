//
//  tree.h
//  normaltree
//
//  Created by Jerry on 9/27/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#ifndef normaltree_tree_h
#define normaltree_tree_h

// tree.h
#include <iostream>
#include <memory>
#include <string>

using std::endl;
using std::ostream;
using std::shared_ptr;
using std::string;

template <typename> struct TreeNode;
template <typename T>
struct TreeNode
{
    typedef shared_ptr<TreeNode<T>> position;
    T element;
    position firstChild;
    position nextSibling;
};

template <typename T> void showRecursively(ostream &, typename TreeNode<T>::position, int);
template <typename> class Tree;
template <typename T> ostream &operator<<(ostream &, const Tree<T> &);

template <typename T>
class Tree
{
    friend void showRecursively<T>(ostream &,typename TreeNode<T>::position, int);
    friend ostream &operator<<<T>(ostream &, const Tree<T> &);
public:
    typedef typename TreeNode<T>::position position;
    
    Tree(const T &ele)
    {
        position r(new TreeNode<T>);
        r->element = ele;
        
        root = r;
    }
    
    void insertAsChild(const T &ele, position parent)
    {
        position node(new TreeNode<T>);
        node->element = ele;
        
        if (parent->firstChild.get() == NULL) {
            parent->firstChild = node;
        } else {
            position p = parent->firstChild;
            while(p->nextSibling.get() != NULL) {
                p = p->nextSibling;
            }
            
            p->nextSibling = node;
        }
    }
    
    void insertAsSibling(const T &ele, position sil)
    {
        position node(new TreeNode<T>);
        node->element = ele;
        
        node->firstChild = sil->firstChild;
        sil->firstChild = node;
    }
    
    position getRoot() const
    {
        return root;
    }
    
    position find(const T &ele) const
    {
        if (ele == T())
        {
            return NULL;
        }
        
        position p = root;
        return findRecursively(ele, root);
    }
private:
    position root;
    
    position findRecursively(const T &ele, position p) const
    {
        if (p->element == ele) {
            return p;
        } else {
            if (p->firstChild.get() != NULL) {
                position child = p->firstChild;
                do {
                    position res = findRecursively(ele, child);
                    if (res != NULL) {
                        return res;
                    }
                    child = child->nextSibling;
                } while(child.get() != NULL);
            }
            
            return NULL;
        }
    }
};

template <typename T>
void showRecursively(ostream &os, typename TreeNode<T>::position p, int deep)
{
    if (deep > 0) {
        string space(deep * 2, '-');
        os << space << p->element << endl;
    } else {
        os << p->element << endl;
    }
    
    if (p->firstChild.get() != NULL) {
        typename TreeNode<T>::position child = p->firstChild;
        do {
            showRecursively<T>(os, child, deep + 1);
            child = child->nextSibling;
        } while(child.get() != NULL);
    }
}

template <typename T>
ostream &operator<<(ostream &os, const Tree<T> &tree)
{
    typename TreeNode<T>::position p = tree.root;
    showRecursively<T>(os, p, 0);
    return os;
}

#endif
