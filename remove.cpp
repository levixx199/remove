
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T data, Node* next = nullptr) : data(data), next(next) {}
};

template <typename T>
class SingleLinkedList {
    Node<T>* head;

public:
    SingleLinkedList() : head(nullptr) {}

    
    void addNodeAtFront(T data) {
        Node<T>* newNode = new Node<T>(data, head);
        head = newNode;
    }

    
    void addNodeAtEnd(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    
    void print() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    
    void removeFromFront() {
        if (head == nullptr) {
            std::cout << "List is empty - cannot remove element\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    

    
    void removeFromEnd() {
        if (head == nullptr) {
            std::cout << "List is empty - cannot remove element\n";
            return;
        }
        
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;   
        temp->next = nullptr; 
    }

    
    int size() {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

   
    Node<T>* find(T value) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return temp;  
            }
            temp = temp->next;
        }
        return nullptr; 
    }

    
    ~SingleLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};