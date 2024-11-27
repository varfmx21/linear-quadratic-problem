#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>
#include <cmath>

enum CollisionMethod {
    LINEAR_PROBING,
    QUADRATIC_PROBING
};

class HashTable {
private:
    std::vector<int> table;
    int tableSize;
    int numElements;
    CollisionMethod collisionResolutionMethod;

    // Función de hash simple
    int hashFunction(int key) const;

    // Método para manejar colisiones con Linear Probing
    int linearProbe(int hash, int i) const;

    // Método para manejar colisiones con Quadratic Probing
    int quadraticProbe(int hash, int i) const;

    // Redimensiona la tabla y rehace el hash
    void rehash();

public:
    // Constructor
    HashTable(int size, CollisionMethod method);

    // Inserta un elemento
    void insert(int key);

    // Busca un elemento
    bool search(int key) const;

    // Elimina un elemento
    void remove(int key);

    // Muestra el contenido de la tabla
    void display() const;
};

#endif