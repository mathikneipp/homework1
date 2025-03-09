#include "log_system.hpp"
#include <iostream>
#include <fstream>

std::string tag_to_string(Tag label) {
    if (Tag::DEBUG == label) return (std::string) "DEBUG";
    if (Tag::INFO == label) return (std::string) "INFO";
    if (Tag::WARNING == label) return (std::string) "WARNING";
    if (Tag::ERROR == label) return (std::string) "ERROR";
    if (Tag::CRITICAL == label) return (std::string) "CRITICAL";
    if (Tag::SECURITY == label) return (std::string) "SECURITY";
    return (std::string) "UNKNOWN";
}

bool write_message(std::string message, Tag label, std::string rute) {
    std::ofstream log_file(rute, std::ios::app);
    if (!log_file.is_open()) return false;
    log_file << '[' << tag_to_string(label) << "] " << message << '\n';
    return true;
}

std::string get_rute(bool input_rute) {
    std::string rute = "";
    if (input_rute) {
        std::cout << "Ingrese la ruta: ";
        std::cin >> rute;
    }
    if (rute == "") {
        rute = "log.txt";
    }
    return rute;
}

void logMessage(std::string message, Tag label) {
    std::string rute = get_rute(false);
    if (!write_message(message, label, rute)) {
        throw std::runtime_error("No se pudo escribir el mensaje.");
    }
}

void logMessage(std::string error_message, std::string file, int line) {
    std::string rute = get_rute(false);
    std::string message = "Archivo: " + file + ", Línea: " + std::to_string(line) + " - " + error_message;
    if (!write_message(message, Tag::ERROR, rute)) {
        throw std::runtime_error("No se pudo escribir el mensaje.");
    }
}

void logMessage(std::string access_message, std::string username) {
    if (access_message != "Access Granted" && access_message != "Access Denied") {
        throw std::runtime_error("Mensaje de acceso incorrecto.");
    }
    std::string rute = get_rute(false);
    std::string message = username + " - " + access_message;
    if (!write_message(message, Tag::SECURITY, rute)) {
        throw std::runtime_error("No se pudo escribir el mensaje.");
    }
}

void test_log_message() {
    logMessage("Esto es un test!", Tag::DEBUG);
    logMessage("Esto es un test!", Tag::INFO);
    logMessage("Esto es un test!", Tag::WARNING);
    logMessage("Esto es un test!", Tag::ERROR);
    logMessage("Esto es un test!", Tag::CRITICAL);
    logMessage("Mensaje de Error", "archivo.cpp", 42);
    logMessage("Access Granted", "usuario123");
    logMessage("Access Denied", "usuario124");
}

void test_runtime_error() {
    try {
        throw std::runtime_error("Error en runtime.");
    } catch (const std::exception& e) {
        logMessage(e.what(), Tag::ERROR);
        exit(1);
    }
}

int main() {
    test_log_message();
    test_runtime_error();
    std::cout << "Finalizo la ejecución." << std::endl; // No termina el programa porque sale con codigo de error.
    return 0;
}
