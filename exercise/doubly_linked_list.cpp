#include "../include/doubly_linked_list.hpp"

int main(int argc, char const* argv[]) {

  DoublyLinkedList<int> lista;
  lista.push_front(10); 
  lista.push_front(20);
  lista.push_front(30);
  lista.push_front(40);
  lista.push_front(50);
  lista.print();

  lista.push_back(6);
  lista.push_back(3);
  lista.print();
  lista.erase(1, 2);

  auto pos = lista.begin();

  return 0;

}
