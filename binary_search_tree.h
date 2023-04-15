#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include "node.h"

template<typename T>
class BinaryTree
{
private:
    node<T>* root;

public:
    BinaryTree();
    ~BinaryTree();

    void addNode(T data);

protected:
    void recursiveAddNote(node<T>* &current, T data);

};



template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{

}

template<typename T>
void BinaryTree<T>::addNode(T data)
{
    recursiveAddNote(root, data);
}

template<typename T>
void BinaryTree<T>::recursiveAddNote(node<T>* &current, T data)
{
    if(current == nullptr)
    {
        current = new node(data);

        return;
    }

    if(data < current->data)
    {
        recursiveAddNote(current->left, data);
        
        return;
    }
    else
    {
        recursiveAddNote(current->right, data);

        return;
    }

}

#endif