#include "../include/doubly_linked_list.hpp"

int main(int argc, char const* argv[]) {

  DoublyLinkedList<int> lista;
  
    lista.push_back(10);
    auto it = lista.begin();
    lista.erase(it, it + 1);

    (lista.size(), 0); // List should be empty now

  return 0;

}
