#include <iostream>
#include "chap2.h"

using namespace std;

int main(void)
{
    //dummy node to call the node functions for the first time
    node dummyNode(99);
#if 0
    //single linked list test
    auto headPtr = dummyNode.insert_sorted(nullptr,20);
    headPtr = headPtr->insert_sorted(headPtr,30);
    headPtr = headPtr->insert_sorted(headPtr,40);
    headPtr = headPtr->insert_sorted(headPtr,15);
    auto findNode = headPtr->find(headPtr, 30);
    if (findNode)
         cout << findNode->data << endl;
    else
        cout << "value not found" << endl;
    headPtr = headPtr->remove(headPtr,findNode);
    headPtr->print(headPtr); // 15->20->40->null
#endif

#if 0
    auto headPtr = dummyNode.circular_insert(nullptr,10);
    headPtr = headPtr->circular_insert(headPtr, 5); //5
    headPtr = headPtr->circular_insert(headPtr, 50);//
    headPtr = headPtr->circular_insert(headPtr, 23);//23->50>5->
    cout << ((headPtr->circular_find(headPtr,10) == nullptr) ? "element Not Found" : "element found") << endl;
    auto findNode = headPtr->circular_find(headPtr,23);
    headPtr->circular_remove(headPtr,findNode);
    headPtr->print(headPtr);
#endif

#if 0
    dll_node dll_node(99);
    auto dllHeadPtr = dll_node.insert(nullptr, 20);
    dllHeadPtr->insert(dllHeadPtr,15);
    dllHeadPtr->insert(dllHeadPtr,55);
    auto findNode = dllHeadPtr->find(dllHeadPtr,55);
    dllHeadPtr = dllHeadPtr->remove(dllHeadPtr,findNode);
    dllHeadPtr->print(dllHeadPtr);
#endif

#if 0
    //selection
    auto headPtr = dummyNode.insert_sorted(nullptr,20);
    for (auto i =0; i<35; i+=7)
        headPtr = headPtr->insert_sorted(headPtr,i);

    auto midNode = headPtr->mid(headPtr);
    cout << "Mid Node value " << midNode->data << endl;
    headPtr->print(headPtr); // 15->20->40->null

    auto kNode = headPtr->findKth(headPtr,1);
    cout << "5 the element from last is " << kNode->data << endl;
#endif
    //modifications


    auto headPtr = dummyNode.insert(nullptr,7);
    headPtr = headPtr->insert(headPtr,7);
    headPtr = headPtr->insert(headPtr,6);
    headPtr = headPtr->insert(headPtr,7);
    headPtr = headPtr->insert(headPtr,7);
    headPtr = headPtr->insert(headPtr,5);
    headPtr = headPtr->insert(headPtr,7);
    headPtr->print(headPtr);
    headPtr = headPtr->remove_values(headPtr, 7);
    headPtr->print(headPtr);
}
