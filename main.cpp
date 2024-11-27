#include "HashTable.h"

int main() {
    HashTable ht(10, LINEAR_PROBING); // Crea una tabla de tamaño 10 con Linear Probing

    ht.insert(12);
    ht.insert(22);
    ht.insert(32);

    std::cout << "Busqueda de 22: " << (ht.search(22) ? "Encontrado" : "No encontrado") << std::endl;
    ht.remove(22);
    std::cout << "Busqueda de 22 despues de eliminar: " << (ht.search(22) ? "Encontrado" : "No encontrado") << std::endl;

    ht.display();

    return 0;
};  