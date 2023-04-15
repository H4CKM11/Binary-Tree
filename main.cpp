#include <iostream>
#include "binary_search_tree.h"

int main()
{
    BinaryTree<int> tree;

    tree.addNode(15);
    tree.addNode(7);
    tree.addNode(20);

    tree.preOrder();

    return 0;
}