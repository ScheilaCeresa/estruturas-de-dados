#include "../include/vector_list.hpp"
using namespace std;

int main(int argc, char const* argv[]) {

VectorList<int> lista(20);

cout << "Criando lista" << endl;

lista.push_back(5);
lista.print();

lista.push_back(2);
lista.print();

lista.push_back(9);
lista.print();

cout << "Tamanho da lista: " << lista.size() << endl;
cout << "Capacidade da lista: " << lista.capacity() << endl;

cout << "Removendo último elemento." << endl;
lista.pop_back();
lista.print();

cout << "Inserindo na posição 1 (física)." << endl;
lista.insert(1, 99);
lista.print();

cout << "Removendo da posição 0 (física)." << endl;
lista.remove(0);
lista.print();

cout << "Verificando se contém 99: " << (lista.contains(99) ? "Sim" : "Não") << endl;

lista.~VectorList();


  return 0;
}