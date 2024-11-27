# linear-quadratic-problem

Este proyecto implementa una clase `HashTable` en C++ que permite almacenar, buscar y eliminar claves utilizando dos estrategias de resolución de colisiones: `linear probing` y `quadratic probing`.

## Descripción

La clase `HashTable` proporciona las siguientes funcionalidades:

- **Constructor**: Inicializa una tabla hash de un tamaño especificado y elige el método de resolución de colisiones (`linear probing` o `quadratic probing`).
- **Métodos Privados**:
  - `hashFunction(int key)`: Calcula el índice hash para una clave dada.
  - `linearProbe(int hash, int i)`: Calcula el nuevo índice en caso de colisión usando `linear probing`.
  - `quadraticProbe(int hash, int i)`: Calcula el nuevo índice en caso de colisión usando `quadratic probing`.
  - `rehash()`: Redimensiona la tabla hash y reubica todos los elementos cuando el factor de carga alcanza el 70%.
- **Métodos Públicos**:
  - `insert(int key)`: Inserta una clave en la tabla hash.
  - `search(int key)`: Busca una clave en la tabla hash y devuelve `true` si se encuentra, `false` en caso contrario.
  - `remove(int key)`: Elimina una clave de la tabla hash.
  - `display()`: Muestra el contenido de la tabla hash.

## Pruebas

En el archivo `main.cpp`, se realizan las siguientes pruebas para verificar el correcto funcionamiento de la clase `HashTable`:

1. **Creación de la Tabla Hash**:
   - Se crea una tabla hash de tamaño 10 utilizando `linear probing`.

2. **Inserción de Claves**:
   - Se insertan las claves `12`, `22` y `32`.

3. **Búsqueda de Claves**:
   - Se busca la clave `22` y se muestra el resultado (encontrado/no encontrado).
   - Se elimina la clave `22` y se vuelve a buscar para verificar su eliminación.

4. **Visualización de la Tabla**:
   - Se muestra el contenido de la tabla hash después de las operaciones de inserción y eliminación.

## Compilación

Para compilar el programa, utiliza el siguiente comando:

```sh
g++ -o main [main.cpp](http://_vscodecontentref_/0) [HashTable.cpp](http://_vscodecontentref_/1)