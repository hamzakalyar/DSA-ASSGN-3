#include "DoublyLinkedList.h"

// Constructor to initialize the list
DoublyLinkedList::DoublyLinkedList() {
    List = NULL;
}

// Insert at start
void DoublyLinkedList::iAS(int x) {
    Nodeptr p = new Node;
    p->info = x;
    p->next = List;
    p->prev = NULL;

    if (List != NULL)
        List->prev = p;

    List = p;
}

// Delete at start
int DoublyLinkedList::dAS() {
    if (List == NULL)
        return -999;

    Nodeptr p = List;
    int x = List->info;
    List = List->next;

    if (List != NULL)
        List->prev = NULL;

    delete p;
    return x;
}

// Traverse the list
void DoublyLinkedList::traverse() {
    for (Nodeptr p = List; p != NULL; p = p->next) {
        std::cout << p->info << " ";
    }
    std::cout << std::endl;
}

// Insert at end
void DoublyLinkedList::iAE(int x) {
    if (List == NULL) {
        iAS(x);
    }
    else {
        Nodeptr p = List;
        while (p->next != NULL) {
            p = p->next;
        }

        Nodeptr q = new Node;
        q->info = x;
        q->next = NULL;
        q->prev = p;
        p->next = q;
    }
}

// Delete at end
int DoublyLinkedList::dAE() {
    if (List == NULL)
        return -999;

    if (List->next == NULL)
        return dAS();

    Nodeptr p = List;
    while (p->next != NULL) {
        p = p->next;
    }

    int x = p->info;
    p->prev->next = NULL;
    delete p;
    return x;
}

// Find a node with the given value
Nodeptr DoublyLinkedList::find(int x) {
    for (Nodeptr p = List; p != NULL; p = p->next) {
        if (p->info == x) {
            return p;
        }
    }
    return NULL;
}

// Insert after a given value
void DoublyLinkedList::iAM(int value, int newValue) {
    Nodeptr p = find(value);
    if (p == NULL) {
        iAE(newValue);
    }
    else {
        Nodeptr q = new Node;
        q->info = newValue;
        q->next = p->next;
        q->prev = p;

        if (p->next != NULL)
            p->next->prev = q;

        p->next = q;
    }
}

// Delete a node with a specific value
int DoublyLinkedList::dAM(int x) {
    Nodeptr p = find(x);
    if (p == NULL)
        return -999;

    if (p->prev != NULL)
        p->prev->next = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;

    if (p == List)
        List = p->next;

    int deletedValue = p->info;
    delete p;
    return deletedValue;
}
