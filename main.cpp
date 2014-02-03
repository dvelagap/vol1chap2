#include <iostream>
#include "chap2.h"

using namespace std;

int main(void)
{
    auto x = "Durga ";
    cout << "Hello World ! Hi There !" << x << endl;
    auto headPtr = new node(20);
    headPtr = headPtr->insert_sorted(headPtr,30);
    headPtr = headPtr->insert_sorted(headPtr,40);
    headPtr = headPtr->insert_sorted(headPtr,15);
    auto findNode = headPtr->find(headPtr, 30);
    if (findNode)
         cout << findNode->data << endl;
    else
        cout << "value not found" << endl;
    headPtr = headPtr->remove(headPtr,findNode);
    headPtr->print(headPtr);

}
