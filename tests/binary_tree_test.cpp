#include <chrono>
#include <forward_list>
#include <iostream>
#include <random>
#include <binary_tree/binary_tree.hpp>

int main()
{
    BinaryTree bt = BinaryTree();
    bt.insert(6);
    bt.insert(7);
    bt.insert(3);
    bt.insert(5);
    bt.insert(4);
    bt.insert(1);
    bt.insert(2);
    bt.insert(10);
    bt.insert(8);
    bt.insert(9);
    bt.insert(11);
    std::cout << bt.count << std::endl;
    std::cout << bt.height << std::endl;
    bt.InOrderTraversal(bt.head);
}