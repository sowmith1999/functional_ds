#include <linked_list/linked_list.hpp>

Node::Node(int val)
{
    this->val = val;
    this->next = nullptr;
}
Node::~Node()
{
    // delete this->next;
}

// constructor
LinkedList::LinkedList()
{
    head = nullptr;
    cur_node = this->head;
}

LinkedList::~LinkedList()
{
    Node* current = this->head;
    while(current!=nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

Node* LinkedList::get_next()
{
    this->cur_node = this->cur_node->next;
    Node* next_temp = this->cur_node;
    return next_temp;
}

int LinkedList::get_value()
{
    return this->cur_node->val;
}

void LinkedList::push_front(int val)
{
    // takes the value and pushes it at the front of this.
    Node* new_node = new Node(val);
    new_node->next = head;
    this->head = new_node;
    this->cur_node = this->head;
}

Node* LinkedList::get_head()
{
    return this->head;
}

void LinkedList::reset_head()
{
    this->cur_node = this->head;
}
