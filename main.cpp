#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}
    ~List();

    // Declaración de funciones (puedes implementarlas luego)

};

int main()
{

    return 0;
}
