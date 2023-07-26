#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
// #include <string.h>

class Node
{
public:
    int data;
    Node *parent;
    Node *right_child;
    Node *left_child;

    Node(int val)
    {
        this->data = val;
        this->parent = nullptr;
        this->right_child = nullptr;
        this->left_child = nullptr;
    }
};

class BinaryTree
{
public:
    Node *head;
    int count;
    int height;
    BinaryTree()
    {
        this->head = nullptr;
        this->count = 0;
        this->height = 0;
    }

    void insert(int val)
    {
        Node *new_node = new Node(val);
        this->count = this->count + 1;
        if (this->head == nullptr)
        {
            this->head = new_node;
            this->height = 1;
            return;
        }
        Node *cur_node = this->head;
        Node *temp_node = nullptr;
        int temp_height = 1;
        while (true)
        {
            ++temp_height;
            if ((val >= cur_node->data))
            {
                if (cur_node->right_child == nullptr)
                {
                    cur_node->right_child = new_node;
                    new_node->parent = cur_node;
                    break;
                }
                cur_node = cur_node->right_child;
            }
            else
            {
                if (cur_node->left_child == nullptr)
                {
                    cur_node->left_child = new_node;
                    new_node->parent = cur_node;
                    break;
                }
                cur_node = cur_node->left_child;
            }
        }
        if (temp_height > this->height)
        {
            this->height = temp_height;
        }
        // std::cout << "temp height is : " << temp_height << std::endl;
        return;
    }

    // In Order traversal -> left-root-right
    // and print the element
    void InOrderTraversal(Node *root)
    {
        if (root->left_child != nullptr)
        {
            InOrderTraversal(root->left_child);
        }
        std::cout << root->data << " ";
        if (root->right_child != nullptr)
        {
            InOrderTraversal(root->right_child);
        }
        return;
    }
};

#endif // BINARY_TREE_H