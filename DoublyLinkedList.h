#include <iostream>

typedef struct Node* Nodeptr;

struct Node {
    int info;
    Nodeptr next;
    Nodeptr prev;
};

class DoublyLinkedList {
private:
    Nodeptr List;
public:
    DoublyLinkedList();
    void traverse();
    Nodeptr find(int);
    void iAS(int);
    int dAS();
    void iAE(int);
    int dAE();
    void iAM(int, int);
    int dAM(int);
};


