#include <iostream>
using namespace std;

// Nodo genérico
template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T val) : data(val), next(nullptr) {}
};

// Lista enlazada genérica
template<typename T>
class List {
private:
    Node<T>* head;

public:
    List() : head(nullptr) {}
    ~List();

    // Funciones principales
    void push_front(T val);
    void push_back(T val);
    T front() const;  // Retorna el primer elemento
    T back() const;   // Retorna el último elemento
    T pop_front();
    T pop_back();
    bool isEmpty() const;
    void display() const;
};

template<typename T>
List<T>::~List() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
bool List<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
void List<T>::push_front(T val) {
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void List<T>::push_back(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (isEmpty()) {
        head = newNode;
        return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

template<typename T>
T List<T>::front() const {
    if (isEmpty()) {
        throw runtime_error("Lista vacía: no se puede obtener el primer elemento.");
    }
    return head->data;
}

template<typename T>
T List<T>::back() const {
    if (isEmpty()) {
        throw runtime_error("Lista vacía: no se puede obtener el último elemento.");
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->data;
}

//verificar
template<typename T>
T List<T>::pop_front() {
    Node<T>* temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
}
//verificar
template<typename T>
T List<T>::pop_back() {
    Node<T>* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    auto temp2 = temp->next;
    temp->next = nullptr;
    delete temp2;
}
template<typename T>
//retorna el valor de la posicion indicada del nodo
T operator [] (int i) {

}

template<typename T>
void List<T>::display() const {
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//main prueba
int main() {
    List<int> lista;
    lista.push_front(10);
    lista.push_back(20);
    lista.push_back(30);

    lista.display();  // 10 -> 20 -> 30 -> NULL

    cout << "Front: " << lista.front() << endl;  // 10
    cout << "Back: " << lista.back() << endl;    // 30

    return 0;
}
