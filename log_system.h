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
 * Pasa un tipo enum Tag a string.
 * Devuelve un std::string.
 */
std::string tag_to_string(Tag level);

/*
 * Escribe el mensaje al final de la ruta pasada, con una etiqueta.
 * Devuelve false si no pudo escribir el mensaje y true si lo pudo hacer.
 */
bool write_message(std::string message, Tag label, std::string rute);

/*
 * En un archivo log.txt, escribe el mensaje con write_message(). 
 * Si no se puede escribir el mensaje, lanza una excepción std::runtime_error.
 */
void logMessage(std::string message, Tag label);

/*
 * En un archivo log.txt, escribe el mensaje de error con write_message() 
 * indicando el archivo y la linea. Si no se puede escribir el mensaje, lanza una 
 * excepción std::runtime_error.
 */
void logMessage(std::string error_message, std::string file, int line);

/*
 * En un archivo log.txt, escribe el mensaje de acceso con write_message(). 
 * Si no se puede escribir el mensaje, lanza una excepción std::runtime_error.
 */
void logMessage(std::string access_message, std::string username);

/*
 * Tira un error en runtime y lo agarra con catch para luego 
*/
void test_log_message();

/*
 * Prueba todos los tipos de mensajes de log
*/
void test_runtime_error();