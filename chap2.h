#ifndef CHAP2_H
#define CHAP2_H

struct node{
    node* next;
    int data;
    explicit node (int data):node(nullptr,data){}
    node (node* head, int data):next(head),data(data){}
    node* insert(node* , int);
    node* insert_sorted(node* head, int value);
    node* find(node* head, int value);
    node* remove(node* head, node* target);
    node* mid(node* head);
    node* findKth(node* head, size_t k);
    node* remove_values(node* head, int value);
    node* reverse(node *head);
    bool  equals(node* x, node* y);
    //circular linked list functions
    node* circular_insert(node* head, int value);
    node* circular_find(node* head, int value);
    node* circular_remove(node* head, node* target);

    //TODO
    //bool is_plaindrome(node* head);
    //bool detect_loop(node* head);
    //node* merge(node* h1, node* h2);

    void print(node*);
};

struct dll_node{
    dll_node* prev;
    dll_node* next;
    int  data;
    explicit dll_node(int data):dll_node(this,this,data){}
    dll_node(dll_node* _prev, dll_node* _next, int _data):prev(_prev),next(_next),data(_data){}
    dll_node* insert(dll_node*, int);
    dll_node* find(dll_node* head, int value);
    dll_node* remove(dll_node*, dll_node*);
    dll_node* reverse(dll_node* head);
    bool is_palindrome(dll_node* head);
    void print(dll_node*);
};

#endif // CHAP2_H
