#include <iostream>

/*
 * Compara recursivamente 2 strings
 */
bool recursive_comparation(const char *string1, const char *string2, int i);

/*
 * Compara recursivamente 2 strings en tiempo de compilacion
 */
constexpr bool recursive_comparation_constexpr(const char *string1, const char *string2, int i);

/*
 * Mide el tiempo (nanosegundos) que le toma a ambas funciones (comparacion en tiempo de compilacion y de ejecucion),
 * las compara con 2 strings, primero iguales (1), y despues distintos (0).
 */
void high_resolution_clock();
