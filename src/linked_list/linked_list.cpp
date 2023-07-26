#include <linked_list/linked_list.hpp>
#include <stdexcept>

Node::Node(int val)
{
    this->val = val;
    this->next = nullptr;
}

// constructor
LinkedList::LinkedList()
{
    head = nullptr;
    cur_node = nullptr;
}

LinkedList::~LinkedList()
{
    Node *current = this->head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

LinkedList::LinkedList(const LinkedList &other)
{
    this->head = nullptr;
    this->cur_node = nullptr;
    Node* temp = other.get_head();
    while(temp != nullptr){
        this->push_front(temp->val);
        temp = temp->next;
    }
}

LinkedList &LinkedList::operator=(const LinkedList& other){
    if(this == &other){
        return *this;
    }

    while(this->head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    head = nullptr;
    cur_node = nullptr;
    Node* temp = other.get_head();
    while(temp != nullptr){
        this->push_front(temp->val);
        temp = temp->next;
    }

    return *this;
}

Node *LinkedList::get_next()
{
    if (cur_node == nullptr)
    {
        return nullptr;
    }
    this->cur_node = this->cur_node->next;
    return this->cur_node;
}

int LinkedList::get_value()
{
    if (cur_node == nullptr)
    {
        throw std::runtime_error("Linked List is empty");
    }
    return this->cur_node->val;
}

void LinkedList::push_front(int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    this->head = new_node;
    this->cur_node = this->head;
}

Node *LinkedList::get_head() const
{
    return this->head;
}

void LinkedList::reset_head()
{
    this->cur_node = this->head;
}
