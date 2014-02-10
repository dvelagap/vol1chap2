#include <iostream>
#include <chap2.h>

using namespace std;

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

//circular linked list
 node* node::circular_insert(node* head, int value)
 {
     auto insertion = new node(value);
     if (head == nullptr)
     {
         insertion->next = insertion;
         return insertion;
     }

     if (head == head->next)
     {
         insertion->next = head;
         head->next = insertion;
         return insertion;
     }

     std::swap(head->data, insertion->data);
     insertion->next = head->next;
     head->next = insertion;
     return head;
 }

 node* node::circular_find(node* head, int value)
 {
     auto current = head;
     while(current != nullptr && current->data != value)
     {
         current = current->next;
         if(current->next == head)
             return nullptr;
     }
     return current;
 }

 node* node::circular_remove(node* head, node* target)
 {
     if(head == head->next && head == target)
     {
         delete head;
         return nullptr;
     }
     auto next=target->next;
     target->data = next->data;
     target->next = next->next;
     delete next;
     return head;
 }

 node* node::mid(node* head)
 {
     auto trailing = head;
     while (head != nullptr)
     {
         head = head->next;
         if(head != nullptr)
         {
             head = head->next;
             cout << trailing->data << " ";
             trailing = trailing->next;
         }
     }
     return trailing;
 }

 node* node::findKth(node* head, size_t k)
 {
     auto trailing = head;
     while(k-- && head != nullptr)
     {
         head=head->next;
     }

     while(head != nullptr)
     {
         head = head->next;
         trailing = trailing->next;
     }
     return trailing;

 }

 node* node::remove_values(node* head, int value)
 {
    //delte the first elements that match from head.
    // value is 7 , 7->7->6->7->5->7->7->8
     while(head != nullptr && head->data == value)
     {
         auto temp = head;
         head = head->next;
         delete temp;
     }
     //6->7->7->5->7->8
     auto target = head;
     //outer loop starts with a non value
     while(target != nullptr)
     {
          //inner loop deletes all nodes until next element is not a value
         while(target->next != nullptr && target->next->data == value)
         {
             auto temp = target->next;
             target->next = target->next->next;
             delete temp;
         }
         target = target->next;
     }
     return head;
 }

 node* node::reverse(node *head)
 {
     node* prev = nullptr;
     while(head != nullptr)
     {
         auto temp = head->next;
         head->next = prev;
         prev = head;
         head = temp;
     }
     return prev;
 }

 bool node::equals(node* x, node* y)
 {
     while(x != nullptr && y == nullptr)
     {
         if (x->data != y->data) return false;
         x = x->next;
         y = y->next;
     }

     if(x == nullptr && y == nullptr)
         return true;
     return false;
 }

void node::print(node* head)
{

    auto temp = head;
    while(head != nullptr && temp != head->next)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//============================================
//circular double linked list impl
//============================================
dll_node* dll_node::insert(dll_node* head, int data)
{

    if(head == nullptr)
        return new dll_node(data);

    auto insertion = new dll_node(head->prev, head, data);
    insertion->prev->next = insertion;
    insertion->next->prev = insertion;
    return insertion;
}

dll_node* dll_node::find(dll_node* head, int value)
{
    auto current = head;
    while(current != nullptr && current->data != value)
    {
        current = current->next;
        if (current == head)
            return nullptr;
    }
    return current;
}

dll_node* dll_node::remove(dll_node* head, dll_node* target)
{
    if (head == head->next)
    {
        delete head;
        return nullptr;
    }

    target->prev->next = target->next;
    target->next->prev = target->prev;
    if (target == head)
        head = target->next;
    delete target;
    return head;
}

dll_node* dll_node::reverse(dll_node* head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == head->prev)
        return head;

    auto tail = head; // 20 15 23 45 55
    do
    {
        auto temp = tail->next;
        tail->next = tail->prev;
        tail->prev = temp;
        tail = temp;
    }while (tail != head);

    return tail->next;
    //return head->prev; -- doesn't work investigate


}

bool dll_node::is_palindrome(dll_node* head)
{
    if (head == nullptr)
        return false;
    if (head == head->next)
        return true;

    auto tail = head->prev;

    //auto current = head;
   // while(current->next != head)
    do
    {
        if(head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }while(head != tail && head->prev != tail);

    return true;
}

void dll_node::print(dll_node* head)
{
    auto current = head;
    while(current != nullptr)
    {
        cout << current->data << " ";
        if (current->next == head)
        {
            cout << endl;
            return;
        }
        current = current->next;
    }
}
