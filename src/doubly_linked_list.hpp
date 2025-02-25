#include <iostream>
#include <iostream>

#include "../include/doubly_linked_list.hpp"

using namespace std;

template<class T>
DoublyLinkedList<T>::Node::Node(const T& value) : value {value}, next{nullptr}, prev{nullptr} {}

template<class T>
DoublyLinkedList<T>::Node::~Node() {
    if(next != nullptr) {
        delete next;
    }
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() : head{nullptr}, tail{nullptr}, _size(0) {}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {

    if(head != nullptr) {
        delete head;
    }
}

template<class T>
void DoublyLinkedList<T>::push_front(const T& value) {

    auto new_node = new Node(value);

    if (empty() ) {

        tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
    }

    head = new_node;

    _size++;
}

template<class T>
size_t DoublyLinkedList<T>::size() const {

    return _size;
} 

template<class T>
bool DoublyLinkedList<T>::empty() const {

    return size() == 0;
} 

template<class T>
void DoublyLinkedList<T>::print() const {
//for (auto& v : *this) {}

    auto pos = head;

    while (pos != nullptr) {

        cout << pos->value << " -> ";
        pos = pos->next;
    }
    
    cout << "Null " << endl;
} 

template<class T>
void DoublyLinkedList<T>::push_back(const T& value) {

    auto new_node = new Node(value);

    if (empty()) {
        head = new_node;
    } else {

        new_node->prev = tail;
        tail->next = new_node;
    }
    tail = new_node;
     _size++;
}

template<class T>  
void DoublyLinkedList<T>::pop_front() {
    if(empty() ) {
        throw std::out_of_range("Lista vazia - Não é possível remover o último elemento.");
    }

    auto tmp = head;
    head = head->next;

    if (head != nullptr) {

        head->prev = nullptr;
    } else {

        tail = nullptr;
    }

    tmp->next = nullptr;
    delete tmp;
    _size--;
}

template<class T>
void DoublyLinkedList<T>::pop_back() {

    if (empty() ) {
        throw std::out_of_range("Lista vazia - Não é possível remover o último elemento.");
    } else {

        if (size() == 1) {

            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {

            auto temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }
    _size--;
} 

template<class T>
template<class U>
DoublyLinkedList<T>::Iterator<U>::Iterator(U* ptr, bool end) : node{ptr}, end{end} {}
  
template<class T>
template<class U>
auto& DoublyLinkedList<T>::Iterator<U>::operator*() const {
    return node->value;
}

template<class T>
template<class U>
DoublyLinkedList<T>::Iterator<U>&DoublyLinkedList<T>::Iterator<U>::operator++() {

    if (node->next == nullptr) {

        end = true;
    } else {

        node = node->next;

    }
    return *this;
}

template<class T>
template<class U>
DoublyLinkedList<T>::Iterator<U>&DoublyLinkedList<T>::Iterator<U>::operator--() {

    if (end) {

        end = false;
    } else {

        node = node->prev;
    }
    return *this;
}

template<class T>
template<class U>
bool DoublyLinkedList<T>::Iterator<U>::operator==(const Iterator<U>& other) const {

    return node == other.node and end == other.end;
} 
  
template<class T>
template<class U>
bool DoublyLinkedList<T>::Iterator<U>::operator!=(const Iterator<U>& other) const {

    return not(*this == other);
} 

template<class T>
//const DoublyLinkedList<T>::begin() const -> const_iterator {}
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::begin() const {
    return const_iterator(head, empty());
}
  
template<class T>
auto DoublyLinkedList<T>::begin() -> iterator {
    return iterator(head, empty());
}

template<class T>
auto DoublyLinkedList<T>::end() -> iterator {
    return iterator(tail, true);
} 

template<class T>
//auto DoublyLinkedList<T>::end() const -> const_iterator {
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::end() const {
    return const_iterator(tail, true);
}

template<class T>
void DoublyLinkedList<T>::insert(iterator pos, const T& value) {

    if (pos == begin() ) {
        push_front(value);
        return;
    } else {

        if (pos == end() ) {
            push_back(value);
            return;
        }
    }

    auto node_pos = pos.node;
    auto node_prev = (--pos).node;
    auto new_node = new Node(value);

    new_node->prev = node_prev;
    new_node->next = node_pos;
    node_prev->next = new_node;
    node_pos->prev = new_node; 

    _size++;
} 

template<class T>
void DoublyLinkedList<T>::erase(iterator first, iterator last) {

    if (first == last) return;
    
    size_t num_elementos_removidos = last - first;

    auto first_node = first.node;
    auto last_node = last.node;
    auto first_prev_node = (--first).node;
    
    if (first_node == head && last_node == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
        _size = 0;
        return;
    }

    if (first_node == head) {
        head = last_node;
        head->prev = nullptr;
        first_node->next = nullptr;
        delete first_node;
        _size -= num_elementos_removidos;
        return;
    }

    if (last_node == nullptr) {
        first_prev_node->next = nullptr;
        tail = first_prev_node;
        delete first_node;
        _size -= num_elementos_removidos;
        return;
    }

    first_prev_node->next = last_node;
    last_node->prev = first_prev_node;
    first_node->next = nullptr;
    delete first_node;
    _size -= num_elementos_removidos;
}

  
template<class T>
template<class U>
size_t DoublyLinkedList<T>::Iterator<U>::operator-(const Iterator<U> other) const {
    auto pos = other;
    size_t count = 0;

    while (pos != *this) {
        count++;
        ++pos;  
    }
    return count;
}

template<class T>
template<class U>
DoublyLinkedList<T>::Iterator<U> DoublyLinkedList<T>::Iterator<U>::operator+(size_t offset) const {
    auto it = *this;
    for (size_t i = 0; i < offset; i++) {
        ++it;
    }
    return it;
}

template<class T>
template<class U>
DoublyLinkedList<T>::Iterator<U> DoublyLinkedList<T>::Iterator<U>::operator-(size_t offset) const {
    auto it = *this;
    for (size_t i = 0; i < offset; i++) {
        --it;  
    }
    return it;
}

template<class T>
//typename DoublyLinkedList<T>::iterator
auto DoublyLinkedList<T>::find(const T& item) -> iterator {

    auto it = begin();

    while(it != end() ) {

        if (*it == item) {

            break;

        }
    ++it;
    }
    return it;
}

template<class T>
//typename DoublyLinkedList<T>::iterator
auto DoublyLinkedList<T>::find(const T& item) const -> const_iterator {

    auto it = begin();

    while(it != end()) {

        if (*it == item) {

            break;
        }
        ++it;
    }
    return it;
} 

template<class T>
bool DoublyLinkedList<T>::contains(const T& item) const {
    return (find(item) != this->end());
}
  
template<class T>
T& DoublyLinkedList<T>::operator[](size_t index) {

    if(index >= size()) {
        throw std::out_of_range("Indice invalido");
    }
    return *(begin() + index);
}

template<class T>
const T& DoublyLinkedList<T>::operator[](size_t index) const {

    if (index >= size()) {

        throw std::out_of_range("Indice invalido");
    }
    return *(begin() + index);
} 

template<class T>
void DoublyLinkedList<T>::clear() {

    erase(begin(), end());
}
  
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& list) : head{nullptr}, tail{nullptr}, _size(0) {

    for(auto & i : list) {
        push_back(i);
    }
} 

template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& list) {

    clear();

    for(auto& i : list) {
        push_back(i);
    }
}