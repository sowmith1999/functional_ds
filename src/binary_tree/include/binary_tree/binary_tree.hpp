#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class Node
{
public:
    int data;
    Node *right_child;
    Node *left_child;

    Node(int val)
    {
        this->data = val;
        this->right_child = nullptr;
        this->left_child = nullptr;
    }
};

class BinaryTree
{
private:
    Node *head;
    int count;
    int height;

public:
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
            if ((val > cur_node->data) || (val == cur_node->data))
            {
                if (cur_node->right_child == nullptr)
                {
                    cur_node->right_child = new_node;
                    return;
                }
                cur_node = cur_node->right_child;
            }
            else
            {
                if (cur_node->left_child == nullptr)
                {
                    cur_node->left_child = new_node;
                    return;
                }
                cur_node = cur_node->left_child;
            }
            temp_height++;
        }
        if(temp_height > this->height){
            this->height = temp_height;
        }
    }

    Node* find(int val){
        
    }
}

#endif // BINARY_TREE_H