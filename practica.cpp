#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

void leerArchivo(const std::string& archivo, std::vector<int>& numeros);
void clasificarNumeros(const std::vector<int>& numeros, std::vector<int>& pares, std::vector<int>& impares);
void ordenarNumeros(std::vector<int>& numeros);
void mostrarArchivo(const std::string& nombreArchivo);

int main() {
    const std::string nombreArchivoEntrada = "datos.txt";
    std::vector<int> numeros, pares, impares;

    std::ofstream archivoSalidaEjemplo(nombreArchivoEntrada);
    if (archivoSalidaEjemplo.is_open()) {
        archivoSalidaEjemplo << "15\n20\n7\n33\n42\n1\n10";
        archivoSalidaEjemplo.close();
        std::cout << "Archivo 'datos.txt' creado con datos de ejemplo." << std::endl;
    } else {
        std::cerr << "Error al crear el archivo de ejemplo." << std::endl;
        return 1;
    }

    leerArchivo(nombreArchivoEntrada, numeros);
    std::cout << "\n--- Contenido del archivo original ---" << std::endl;
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    clasificarNumeros(numeros, pares, impares);

    std::cout << "\n--- Numeros pares (antes de ordenar) ---" << std::endl;
    for (int num : pares) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "\n--- Numeros impares (antes de ordenar) ---" << std::endl;
    for (int num : impares) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    ordenarNumeros(pares);
    ordenarNumeros(impares);

    std::ofstream archivoPares("pares.txt");
    for (int num : pares) {
        archivoPares << num << "\n";
    }
    archivoPares.close();

    std::ofstream archivoImpares("impares.txt");
    for (int num : impares) {
        archivoImpares << num << "\n";
    }
    archivoImpares.close();

    std::cout << "\n--- Contenido del archivo 'pares.txt' (ordenado) ---" << std::endl;
    mostrarArchivo("pares.txt");

    std::cout << "\n--- Contenido del archivo 'impares.txt' (ordenado) ---" << std::endl;
    mostrarArchivo("impares.txt");

    return 0;
}

void leerArchivo(const std::string& nombreArchivo, std::vector<int>& numeros) {
    std::ifstream in(nombreArchivo);
    if (!in) {
        std::cerr << "No se pudo abrir: " << nombreArchivo << '\n';
        return;
    }
    int n;
    while (in >> n) numeros.push_back(n);
}

void clasificarNumeros(const std::vector<int>& numeros, std::vector<int>& pares, std::vector<int>& impares) {
    for (int num : numeros) {
        if (num % 2 == 0) {
            pares.push_back(num);
        } else {
            impares.push_back(num);
        }
    }
}

void ordenarNumeros(std::vector<int>& numeros) {
    bool swapped;
    size_t n = numeros.size();
    for (size_t i = 0; i < n; ++i) {
        swapped = false;
        for (size_t j = 0; j + 1 < n - i; ++j) {
            if (numeros[j] > numeros[j + 1]) {
                std::swap(numeros[j], numeros[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void mostrarArchivo(const std::string& nombreArchivo) {
    std::ifstream in(nombreArchivo);
    if (!in) {
        std::cerr << "No se pudo abrir: " << nombreArchivo << '\n';
        return;
    }
    int n;
    while (in >> n) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}


