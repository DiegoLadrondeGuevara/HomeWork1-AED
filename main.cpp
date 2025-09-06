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
    T front() const;
    T back() const;
    T pop_front();
    T pop_back();
    bool empty() const;
    void display() const;
    void sort();
    T operator[](int);
    //DANI
    int size();
    void clear();
    void reverse();
};


template<typename T>
int List<T>:: size(){
    Node<T>* curr = head;
    Node<T>* nextt = curr->next;
    if (head == nullptr) return 0; //Manejo de caso en que la lista está vacía

    int tamanho = 1;
    while (nextt != nullptr) {
        curr = nextt;
        nextt = curr->next;
        tamanho++;
    }
    return tamanho;
}

template<typename T>
void List<T>:: clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void List<T> :: reverse() {
    Node<T> * prev = nullptr; //comenzamos con un prev que obviamente comenzará siendo nulo
    Node<T> * curr = head;
    while (curr!= nullptr) { //Manejo de caso en que la lista está vacía
        Node<T> * nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}

template<typename T>
List<T>::~List() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
bool List<T>::empty() const {
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
    if (empty()) {
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
    if (empty()) {
        throw runtime_error("Lista vacia: no se puede obtener el primer elemento.");
    }
    return head->data;
}

template<typename T>
T List<T>::back() const {
    if (empty()) {
        throw runtime_error("Lista vacia: no se puede obtener el ultimo elemento.");
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->data;
}

template<typename T>
T List<T>::pop_front() {
    if (head == nullptr) {
        throw std::out_of_range("La lista esta vacia");
    }

    Node<T>* temp = head;
    T value = temp->data;
    head = head->next;
    delete temp;
    return value;
}

template<typename T>
T List<T>::pop_back() {
    if (head == nullptr) {
        throw std::out_of_range("La lista esta vacia");
    }

    // Si solo hay un elemento
    if (head->next == nullptr) {
        T value = head->data;
        delete head;
        head = nullptr;
        return value;
    }

    Node<T>* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    Node<T>* last = temp->next;
    T value = last->data;
    delete last;
    temp->next = nullptr;
    return value;
}

template<typename T>
T List<T>::operator[](int i) {
    if (i < 0) {
        throw std::out_of_range("El indice no puede ser negativo");
    }

    Node<T>* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count == i) {
            return current->data;
        }
        current = current->next;
        count++;
    }

    throw std::out_of_range("Indice fuera de rango");
}

template<typename T>
void List<T>::sort() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    bool cambiar;
    do {
        cambiar = false;
        Node<T>* current = head;

        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                // Intercambiar datos
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                cambiar = true;
            }
            current = current->next;
        }
    } while (cambiar);
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
    lista.push_front(9);

    lista.display();  // 10 -> 20 -> 30 -> NULL


    cout << "Front: " << lista.front() << endl;  // 10
    cout << "Back: " << lista.back() << endl;    // 30
    cout << "Size: " << lista.size() << endl;
    lista.reverse();
    cout << "Display después de reverse:\n"; lista.display();
    return 0;
}