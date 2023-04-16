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
    void preOrder();
    void inOrder();
    void postOrder();

protected:
    void recursiveAddNote(node<T>* &current, T data);
    void recursivePreOrder(node<T>* &current, void(*function)(T data));
    void recursiveInOrder(node<T>* &current, void (*function)(T data));
    void recursivePostOrder(node<T>* &current, void (*function)(T data));
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

template<typename T>
void BinaryTree<T>::preOrder()
{
    recursivePreOrder(root, [](T data) {std::cout << data << std::endl; });
}

template<typename T>
void BinaryTree<T>::recursivePreOrder(node<T>* &current, void(*funtion)(T data))
{
    if(current == nullptr)
    {
        return;
    }
    funtion(current->data);
    recursivePreOrder(current->left, [](T data) {std::cout << data << std::endl; });
    recursivePreOrder(current->right, [](T data) {std::cout << data << std::endl; });

}


template<typename T>
void BinaryTree<T>::inOrder()
{
    recursiveInOrder(root, [](T data){std::cout << data << std::endl;});
}

template<typename T> 
void BinaryTree<T>::recursiveInOrder(node<T>* &current, void (*function)(T data))
{
    if(current == nullptr)
    {
        return;
    }
    recursiveInOrder(current->left, [](T data) {std::cout << data << std::endl;});
    function(current->data);
    recursiveInOrder(current->right, [](T data) {std::cout << data << std::endl;});
}

template<typename T>
void BinaryTree<T>::postOrder()
{
    recursivePostOrder(root, [](T data){std::cout << data << std::endl;});
}

template<typename T>
void BinaryTree<T>::recursivePostOrder(node<T>* &current, void(*function)(T data))
{
    if(current == nullptr)
    {
        return;
    }

    recursivePostOrder(current->left, [](T data){std::cout << data << std::endl;});
    recursivePostOrder(current->right, [](T data){std::cout << data << std::endl;});
    function(current->data);
}



#endif