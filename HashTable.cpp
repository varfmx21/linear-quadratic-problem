#include "HashTable.h"

HashTable::HashTable(int size, CollisionMethod method) 
    : tableSize(size), collisionResolutionMethod(method), numElements(0) {
    table.resize(tableSize, -1);  // Inicializa la tabla con -1 (indicando vacío)
}

int HashTable::hashFunction(int key) const {
    return key % tableSize;
}

int HashTable::linearProbe(int hash, int i) const {
    return (hash + i) % tableSize;
}

int HashTable::quadraticProbe(int hash, int i) const {
    return (hash + i * i) % tableSize;
}

void HashTable::rehash() {
    int newSize = tableSize * 2;
    std::vector<int> newTable(newSize, -1); // Nueva tabla con tamaño doble

    // Reinsertar los elementos existentes en la nueva tabla
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != -1) { // Si el índice no está vacío
            int key = table[i];
            int hash = hashFunction(key) % newSize;
            int j = 0;
            while (newTable[hash] != -1) {  // Buscar un espacio vacío
                if (collisionResolutionMethod == LINEAR_PROBING) {
                    hash = linearProbe(hash, ++j);
                } else {
                    hash = quadraticProbe(hash, ++j);
                }
            }
            newTable[hash] = key;
        }
    }

    table = newTable;
    tableSize = newSize;
}

void HashTable::insert(int key) {
    if ((float)numElements / tableSize >= 0.7) {
        rehash(); // Redimensiona la tabla si el factor de carga es >= 70%
    }

    int hash = hashFunction(key);
    int i = 0;
    while (table[hash] != -1) {
        if (table[hash] == key) {
            return; // El elemento ya está en la tabla
        }

        // Manejo de colisiones
        if (collisionResolutionMethod == LINEAR_PROBING) {
            hash = linearProbe(hash, ++i);
        } else {
            hash = quadraticProbe(hash, ++i);
        }
    }

    table[hash] = key;
    numElements++;
}

bool HashTable::search(int key) const {
    int hash = hashFunction(key);
    int i = 0;
    while (table[hash] != -1) {
        if (table[hash] == key) {
            return true;
        }

        // Manejo de colisiones
        if (collisionResolutionMethod == LINEAR_PROBING) {
            hash = linearProbe(hash, ++i);
        } else {
            hash = quadraticProbe(hash, ++i);
        }
    }
    return false;
}

void HashTable::remove(int key) {
    int hash = hashFunction(key);
    int i = 0;
    while (table[hash] != -1) {
        if (table[hash] == key) {
            table[hash] = -1; // Marca el lugar como vacío
            numElements--;
            return;
        }

        // Manejo de colisiones
        if (collisionResolutionMethod == LINEAR_PROBING) {
            hash = linearProbe(hash, ++i);
        } else {
            hash = quadraticProbe(hash, ++i);
        }
    }
}

void HashTable::display() const {
    for (int i = 0; i < tableSize; ++i) {
        std::cout << "Indice " << i << ": ";
        if (table[i] != -1) {
            std::cout << table[i] << " -> ";
        }
        std::cout << "nullptr\n";
    }
}
