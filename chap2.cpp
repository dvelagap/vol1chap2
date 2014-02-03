#include <iostream>
#include <chap2.h>


node* node::insert(node* head, int data)
{
    return new node(head,data);
}

node* node::insert_sorted(node* head, int value)
{
    if(head == nullptr || head->data > value)
        return new node(head,value);

    auto current = head;

    while(current->next != nullptr
          && current->next->data < value)
    {
        current = current->next;
    }

    if(current->next == nullptr)
        current->next = new node(value);
    else
        current->next = new node(current->next,value);

    return head;
}

node* node::find(node* head, int value)
{
    while(head != nullptr && head->data != value)
        head = head->next;
    return head;
}

node* node::remove(node* head, node*target)
{
    if(head == target)
    {
        head = head->next;
        delete target;
        return head;
    }

    auto temp=head;
    while(temp->next != nullptr && temp->next != target)
        temp = temp->next;

    if (temp->next == target)
    {
        temp->next = temp->next->next;
        delete target;
    }
    return head;
}

void node::print(node* head)
{
    using namespace std;
    while(head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
