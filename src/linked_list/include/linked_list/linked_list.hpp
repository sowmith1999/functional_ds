#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node {
public:
    int val;
    Node* next;
    Node(int val);
    ~Node();

};

class LinkedList {
private:
    Node* head;
    Node* cur_node;

public:
    LinkedList();
    ~LinkedList();
    Node* get_head();
    void reset_head();
    int get_value();
    Node* get_next();
    void push_front(int val);
};

#endif // LINKED_LIST_H