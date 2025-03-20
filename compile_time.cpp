#include "compile_time.h"
#include <iostream>
#include <chrono>

bool recursive_comparation(const char *string1, const char *string2, int i = 0) {
    if (string1[i] == '\0' && string2[i] == '\0') return true; // Si ambos caracteres son \0 (ultimo caracter de todos los strings), devuelve true, son iguales.
    if (string1[i] != string2[i]) return false; // En caso de que difieran en algun caracter, devuelve false.
    return recursive_comparation(string1, string2, ++i); // Llamo recursivamente a la funcion y le sumo 1 al indice i para que avance al siguiente caracter.
}

constexpr bool recursive_comparation_constexpr(const char *string1, const char *string2, int i = 0) {
    if (string1[i] == '\0' && string2[i] == '\0') return true; // Si ambos caracteres son \0 (ultimo caracter de todos los strings), devuelve true, son iguales.
    if (string1[i] != string2[i]) return false; // En caso de que difieran en algun caracter, devuelve false.
    return recursive_comparation_constexpr(string1, string2, ++i); // Llamo recursivamente a la funcion y le sumo 1 al indice i para que avance al siguiente caracter.
}

void high_resolution_clock() {
    // Tiempo de ejecucion
    constexpr const char *string1 = "Este es un string de mas de 64 caracteres de largo para comparar las cadenas.";
    constexpr const char *string2 = "Este es un string distinto de mas de 64 caracteres de largo para comparar las cadenas. ";
    std::cout << "Tiempo de ejecucion: " << std::endl;
    auto startTime_ex = std::chrono::high_resolution_clock::now();

    bool result1_ex = recursive_comparation(string1, string1, 0); // Comparacion strings iguales
    bool result2_ex = recursive_comparation(string1, string2, 0); // Comparacion strings distintos

    auto endTime_ex = std::chrono::high_resolution_clock::now();
    auto elapsedTime_ex = std::chrono::duration_cast<std::chrono::nanoseconds>(
    endTime_ex - startTime_ex);
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime_ex.count() << " nanosegundos" << std::endl;

    std::cout << "La comparacion de strings iguales es: " << result1_ex << std::endl;
    std::cout << "La comparacion de strings distintos es: " << result2_ex << std::endl;
    
    // Tiempo de compilacion
    std::cout << std::endl << "Tiempo de compilacion: " << std::endl;
    auto startTime_comp = std::chrono::high_resolution_clock::now();

    constexpr bool result1_comp = recursive_comparation_constexpr(string1, string1); // Comparacion strings iguales
    constexpr bool result2_comp = recursive_comparation_constexpr(string1, string2); // Comparacion strings distintos

    auto endTime_comp = std::chrono::high_resolution_clock::now();
    auto elapsedTime_comp = std::chrono::duration_cast<std::chrono::nanoseconds>(
    endTime_comp - startTime_comp);
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime_comp.count() << " nanosegundos" << std::endl;
    
    std::cout << "La comparacion de strings iguales es: " << result1_comp << std::endl;
    std::cout << "La comparacion de strings distintos es: " << result2_comp << std::endl;
}

// Compilar y ejecutar con make run_compile_time
int main() {
    high_resolution_clock();
    return 0;
}

/*
 * La comparacion en tiempo de compilación es instantanea, a diferencia de la comparacion en tiempo de ejecucion, 
 * porque el compilador ya tiene el resultado preguardado.
 * Use const char porque permite la evaluacion en tiempo de compilacion con constexpr,
 * mientras que string usa memoria dinamica y funciona en tiempo de ejecucion.
 */
