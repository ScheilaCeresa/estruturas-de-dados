#include "../include/linked_list.hpp"

using namespace std;

int main(int argc, char const* argv[]) {
LinkedList<int> lista;

  try {

  cout << "Inserindo 20 no inicio...\n";

  lista.push_front(20);

  lista.print();

  cout << endl;

  cout << "Inserindo 11 no indice 1...\n";

  lista.insert(1, 11);

  lista.print();

  cout << endl;

  cout << "Removendo do inicio...\n";

  lista.pop_front();

  lista.print();

  cout << endl;

  cout << "Removendo no indice 0...\n";

  lista.remove(0);

  lista.print();

  cout << endl;

} catch (const std::out_of_range& e) {

  cerr << "Erro: " << e.what() << endl;

} catch (const char* e) {

  cerr << "Erro: " << e << endl;

} catch (...) {

  cerr << "Erro desconhecido." << endl;

}

return 0;
}

