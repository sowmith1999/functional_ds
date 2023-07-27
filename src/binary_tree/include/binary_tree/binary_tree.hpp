#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *parent;
    Node<T> *right_child;
    Node<T> *left_child;

    Node<T>(T val)
    {
        this->data = val;
        this->parent = nullptr;
        this->right_child = nullptr;
        this->left_child = nullptr;
    }
};

template <typename BinaryTree>
class BinaryTreeIterator
{
public:
    using ValueType = typename BinaryTree::ValueType;
    using PointerType = ValueType *;
    using ReferenceType = ValueType &;

public:
    BinaryTreeIterator(PointerType ptr)
        : m_ptr(ptr) {}

    BinaryTreeIterator &operator++()
    {

    }

private:
    PointerType m_ptr;
    PointerType
};

template <typename T>
class BinaryTree
{
public:
    using ValueType = T;
    using Iterator = BinaryTreeIterator<BinaryTree<T>>;

public:
    Node<T> *head;
    int count;
    int height;
    BinaryTree()
    {
        this->head = nullptr;
        this->count = 0;
        this->height = 0;
    }

    void insert(T val)
    {
        Node<T> *new_node = new Node<T>(val);
        this->count = this->count + 1;
        if (this->head == nullptr)
        {
            this->head = new_node;
            this->height = 1;
            return;
        }
        Node<T> *cur_node = this->head;
        Node<T> *temp_node = nullptr;
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
    void InOrderTraversal(Node<T> *root)
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

    Iterator begin()
    {
        return Iterator(this->head);
    }

    // the idea, I think is that when begin becomes end we stop
    // it could the address after the last element or null ptr if incrementing returns
    // nullptr when we are done with the last element, that should work as well.
    Iterator end()
    {
        return Iterator(nullptr);
    }
};

#endif // BINARY_TREE_H