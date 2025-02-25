#include "../include/doubly_linked_list.hpp"

int main(int argc, char const* argv[]) {

  DoublyLinkedList<int> lista;
  lista.push_front(10); 
  lista.push_front(20);
  lista.print();

  lista.push_back(6);
  lista.push_back(3);
  lista.print();

  auto pos = lista.begin();

  return 0;

}
