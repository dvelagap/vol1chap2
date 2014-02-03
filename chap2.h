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
    node* remove(node* head, node*target);
    void print(node*);
};

#endif // CHAP2_H
