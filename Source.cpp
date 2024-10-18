#include "DoublyLinkedList.h"


int main() {
    DoublyLinkedList list;

    list.iAS(10);
    list.iAS(20);
    list.iAE(30);
    list.iAE(40);

    std::cout << "List after inserting 20, 10 at start and 30, 40 at end: ";
    list.traverse();

    list.dAS();
    std::cout << "List after deleting from start: ";
    list.traverse();

    list.dAE();
    std::cout << "List after deleting from end: ";
    list.traverse();

    list.iAM(10, 25);
    std::cout << "List after inserting 25 after 10: ";
    list.traverse();

    list.dAM(25);
    std::cout << "List after deleting 25: ";
    list.traverse();

    return 0;
}
