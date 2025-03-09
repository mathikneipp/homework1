#include <iostream>
#include <chrono>

bool recursive_comparation(const char *string1, const char *string2, int i = 0) {
    if (string1[i] == '\0' && string2[i] == '\0') return true;
    if (string1[i] != string2[i]) return false;
    return recursive_comparation(string1, string2, ++i);
}

constexpr bool recursive_comparation_constexpr(const char *string1, const char *string2, int i = 0) {
    if (string1[i] == '\0' && string2[i] == '\0') return true;
    if (string1[i] != string2[i]) return false;
    return recursive_comparation_constexpr(string1, string2, ++i);
}

void proceso_compilacion() {
    constexpr const char *string1 = "Este es un string de mas de 64 caracteres de largo para comparar las cadenas.";
    constexpr const char *string2 = "Este es un string de mas de 64 caracteres de largo para comparar las cadenas. 0";
    constexpr bool result1 = recursive_comparation_constexpr(string1, string1);
    constexpr bool result2 = recursive_comparation_constexpr(string1, string2);
    std::cout << "La comparacion de strings iguales es: " << result1 << std::endl;
    std::cout << "La comparacion de strings distintos es: " << result2 << std::endl;
}
void proceso() {
    const char *string1 = "Este es un string de mas de 64 caracteres de largo para comparar las cadenas.";
    const char *string2 = "Este es un string de mas de 64 caracteres de largo para comparar las cadenas. 0";
    /*
    Elegi char* ...
    */
    bool result1 = recursive_comparation(string1, string1, 0);
    bool result2 = recursive_comparation(string1, string2, 0);
    std::cout << "La comparacion de strings iguales es: " << result1 << std::endl;
    std::cout << "La comparacion de strings distintos es: " << result2 << std::endl;
}

void high_resolution_clock(void (*miProcesoAMedir)()) {
    auto startTime = std::chrono::high_resolution_clock::now();
    miProcesoAMedir();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
    endTime - startTime);
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << " nanosegundos" << std::endl;
}

int main() {
    std::cout << "Tiempo de ejecucion: " << std::endl;
    high_resolution_clock(proceso);
    std::cout << std::endl;
    std::cout << "Tiempo de compilacion: " << std::endl;
    high_resolution_clock(proceso_compilacion);
    return 0;
}

/*
 * La comparacion en tiempo de compilación es instantanea, a diferencia de la comparacion en tiempo de ejecucion, 
 * porque el compilador ya tiene el resultado preguardado.
*/
