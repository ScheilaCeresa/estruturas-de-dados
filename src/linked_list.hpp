#include <iostream>
#include <stdexcept>
#include <utility>

#include "../include/linked_list.hpp"

using namespace std;

template<class T>

LinkedList<T>::LinkedList() : head{nullptr}, _size(0) {}

template<class T>
LinkedList<T>::~LinkedList() {

    if (head != nullptr) {
        delete head;
    }
}

template<class T>
LinkedList<T>::Node::Node(const T& value) : value{value}, next{nullptr} {}

template<class T>
LinkedList<T>::Node::~Node() {
    if(next != nullptr) {
        delete next;
    }
}

template<class T>
bool LinkedList<T>::empty() const {
    return size() == 0;
}

template<class T>
size_t LinkedList<T>::size() const{
    return _size;
}

template<class T>
void LinkedList<T>::push_front(const T& value) {

    auto new_node = new Node(value);

    new_node->next = head;

    head = new_node;
    _size++;
}

template<class T>
void LinkedList<T>::insert(size_t index, const T& value) {

    if (index> size()) {

        throw std::out_of_range("Índice inválido para inserção");
    }

    if (index == 0) {

        return push_front(value);
    }

    auto pos = head;

    Node* prev = nullptr;

    for (size_t i = 0; i < index; i++) {

        prev = pos;
        pos = pos->next;
    }

    auto new_node = new Node(value);
    new_node-> next = pos;
    prev->next = new_node;

    _size++;
}

template<class T>
void LinkedList<T>::print() const {

    auto atual = head;

    while (atual != nullptr) {

        cout << atual->value << " - ";
        atual = atual->next;
    }
    cout << "NULL";
}

template<class T>
void LinkedList<T>::pop_front() {

    if (empty() ) {
        throw std::out_of_range("A lista está vazia");
    }

    auto old_head = head;
    head = head->next;
    old_head->next = nullptr;
    delete old_head;
    _size--;
}

template<class T>
void LinkedList<T>::remove(size_t index) {

    if (index >= size()) {

        throw std::out_of_range("Índice inválido para remoção");
    }

    if (index == 0) {

        return pop_front();
    }

    auto pos = head;

    Node* prev = nullptr;

    for (size_t i = 0; i < index; i++) {

        prev = pos;
        pos = pos->next;
    }

    prev->next = pos->next;
    pos->next = nullptr;
    delete pos;

    _size--;
}

template<class T>
T & LinkedList<T>::operator[](size_t index) {

    if (index >= size()) {

        throw std::out_of_range("Índice inválido");
    }

    auto pos = head;

    for (size_t i = 0; i < index; i++) {

        pos = pos->next;
    }

    return pos->value;
}

template<class T>
const T & LinkedList<T>::operator[](size_t index) const {

    if (index >= size()) {
        throw std::out_of_range("Índice inválido");
    }

    auto pos = head;

    for (size_t i = 0; i < index; i++) {

        pos = pos->next;
    }

    return pos->value;
}

template<class T>
const T& LinkedList<T>::find(const T& item) const {

    auto pos = head;

    while (pos != nullptr) {

        if (pos->value == item) {
            return pos->value;
        }
        pos = pos->next;
    }

    throw std::out_of_range("Elemento não encontrado");
}

template <class T>
T& LinkedList<T>::find(const T& item) {

    auto pos = head;

    while (pos != nullptr) {
        if (pos->value == item) {
            return pos->value;
        }
        pos = pos->next;
    }
    throw std::out_of_range("Elemento não encontrado");
}

template<class T>
bool LinkedList<T>::contains(const T& item) const {

    auto pos = head;

    while (pos != nullptr) {
        if (pos->value == item) {
            return true;
        }
        pos = pos->next;
    }
    return false;
}

template<class T>
void LinkedList<T>::clear() {

    if (not empty()) {
        delete head;
        _size = 0;
        head = nullptr;
    }
}

//função de copia;
template<class T>
LinkedList<T>::LinkedList(const LinkedList& other) : head{nullptr}, _size(other.size()) {

    if(not other.empty()) {

        head = new Node(other.head->value);

        auto other_pos = other.head->next;

        auto pos = head;

        while(other_pos != nullptr) {
            pos->next = new Node(other_pos->value);
            pos = pos->next;
            other_pos = other_pos->next;
        }
    }
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {

    clear();

    if(not other.empty()) {

        head = new Node(other.head->value);

        auto other_pos = other.head->next;

        auto pos = head;

        while(other_pos != nullptr) {

            pos->next = new Node(other_pos->value);

            pos = pos->next;

            other_pos = other_pos->next;
        }
    }
    _size = other.size();
    return *this;
}
