// #include "SinglyLinkedList.h"
//#include "DoublyLinkedList.h"
#include "doublyliststack.h"

int main() {
    /*
    cout << "--------------------- SinglyLinkedList ------------------------\n";
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    cout << "Initial List: ";
    list.printList();

    list.insertAtPosition(25, 2);
    cout << "After Inserting 25 at Position 2: ";
    list.printList();

    list.reverse();
    cout << "After Reversing: ";
    list.printList();

    list.deleteNode(25);
    cout << "After Deleting 25: ";
    list.printList();

    list.sort();
    cout << "Sorted List: ";
    list.printList();
*/

    /*
        cout << "--------------------- DoublyLinkedList ------------------------\n";
        DoublyLinkedList dlist;

        dlist.insertAtHead(10);
        dlist.insertAtHead(20);

        dlist.insertAtTail(30);
        dlist.insertAtTail(40);

        cout << "Initial List: ";
        dlist.printList();

        dlist.deleteNode(20);
        cout << "After Deleting 20: ";
        dlist.printList();

        dlist.reverse();
        cout << "After Reversing: ";
        dlist.printList();

        cout << "Reverse Print List: ";
        dlist.printListReverse();
    */
    DoublyListStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack after pushes: ";
    stack.printDoublyListStack();

    cout << "Top element: " << stack.top() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Stack after pop: ";
    stack.printDoublyListStack();

    cout << "Top element: " << stack.top() << endl;

    return 0;
}