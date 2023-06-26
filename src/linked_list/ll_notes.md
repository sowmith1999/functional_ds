# Linked List

## Standard Linked List
- Is a linear data structure, which is not contigous in memory, each node of a linked list will hold some data along with a pointer to the next element.
- Based on how the links work there are three different types of linked lists.
    * Singly linked list - only pointer to the next item is stored.
    * Doubly linked list - pointers to both prev and next item are stored.
    * Circular linked list - singly linked list but last item points back to the first item.
- Operations Supported
    * Insertion - add a new node anywhere in the list.
    * Deletion - delete a node anywhere in the list.
    * Searching - Traverse the list from head to tail looking for an element.

### std::forward_list
- forward_list is the singly linked list int std:: in cpp.
```c
std::forward_list<int> my_list;
```
- This provides a bunch of functions, for accessing different elements and changing them as required.


# Dev Notes
## Standard Implementation'
- Using normal class wiht integer as the type, have to implement templates to allow the type of the linked_list to be passed during its initialization.

### TO DO:


### To think about:
- Making it const and how to make the fields const and how the const works in general.

