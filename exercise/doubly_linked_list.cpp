#include "../include/doubly_linked_list.hpp"

int main(int argc, char const* argv[]) {

  DoublyLinkedList<int> lista;
  lista.push_front(10); 
  lista.push_front(20);
  lista.push_front(30);
  lista.print();
  lista.pop_front();
  lista.print();
  lista.push_front(40);
  lista.push_front(50);
  lista.print();

  auto it = lista.begin();
  cout << "Adicionando 80 na posição 1. "; cout << endl;
  ++it; 
  lista.insert(it, 80);
  lista.print();

  cout << "A lista está vazia? " << (lista.empty() ? "Sim" : "Não") << endl;
  lista.print();

  cout << "Procurando o item 50: ";
  auto itFind = lista.find(50);
  if (itFind != lista.end()) {
    cout << "Item 50 encontrado." << endl;
  } else {
    cout << "Item 50 não encontrado." << endl;
  }

  cout << "A lista contém 77? " << (lista.contains(77) ? "Sim" : "Não") << endl;

  lista.push_back(6);
  lista.push_back(3);
  lista.print();

  auto it1 = lista.begin();
  ++it1;
  auto it2 = it1;
  ++it2;
  lista.erase(it1, it2);
  lista.pop_back();

  auto pos = lista.begin();

  lista.~DoublyLinkedList();

  return 0;

}
