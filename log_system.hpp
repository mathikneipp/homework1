#include <iostream>

enum class Tag {
    DEBUG,   // 0
    INFO,    // 1
    WARNING, // 2
    ERROR,   // 3
    CRITICAL,// 4
    SECURITY // 5
};

/*
 * Pasa un tipo Tag a string.
 * Devuelve un std::string.
 */
std::string tag_to_string(Tag level);

/*
 * Escribe el mensaje al final de la ruta pasada, con una etiqueta.
 * Devuelve false si no pudo escribir el mensaje y true si lo pudo hacer.
 */
bool write_message(std::string message, Tag label, std::string rute);

/*
 * Le pide al usuario la ruta para escribir el log.
 * Devuelve un std::string.
 */
std::string get_rute();

/*
 * Obtiene una ruta utilizando get_rute(), escribe el mensaje con write_message(). 
 * Si no se puede escribir el mensaje, lanza una excepción std::runtime_error.
 */
void logMessage(std::string message, Tag label);

/*
 * Obtiene una ruta utilizando get_rute(), escribe el mensaje de error con write_message() 
 * indicando el archivo y la linea. Si no se puede escribir el mensaje, lanza una 
 * excepción std::runtime_error.
 */
void logMessage(std::string error_message, std::string file, int line);

/*
 * Obtiene una ruta utilizando get_rute(), escribe el mensaje de acceso con write_message(). 
 * Si no se puede escribir el mensaje, lanza una excepción std::runtime_error.
 */
void logMessage(std::string access_message, std::string username);
