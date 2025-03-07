#include <iostream>
#include <fstream>
#include <cassert>

enum class Tag {
    DEBUG,   // 0
    INFO,    // 1
    WARNING, // 2
    ERROR,   // 3
    CRITICAL // 4
};

std::string tag_to_string(Tag level) {
    if (Tag::DEBUG == level) return (std::string) "DEBUG";
    if (Tag::INFO == level) return (std::string) "INFO";
    if (Tag::WARNING == level) return (std::string) "WARNING";
    if (Tag::ERROR == level) return (std::string) "ERROR";
    if (Tag::CRITICAL == level) return (std::string) "CRITICAL";
    return (std::string) "UNKNOWN";
}

bool write_message(std::string message, std::string error_message, std::string rute) {
    std::ofstream log_file(rute, std::ios::app);
    if (!log_file.is_open()) return false;
    log_file << '[' << error_message << "] " << message << '\n';
    return true;
}

bool write_message(std::string message, std::string error_message, std::string rute, int line) {
    std::ofstream log_file(rute, std::ios::app);
    if (!log_file.is_open()) return false;
    log_file << rute << ", line: " << line << ' [' << error_message << "] " << message << '\n';
    return true;
}

void logMessage(std::string message, Tag level) {
    std::string rute;
    std::cout << "Ingrese la ruta: ";
    std::cin >> rute;
    if (!write_message(message, tag_to_string(level), rute)) {
        throw std::runtime_error("No se pudo escribir el mensaje.");
    }
}

void logMessage(std::string error_message, std::string rute, int line) {
    if (!write_message(error_message, tag_to_string(Tag::ERROR), rute, line)) {
        throw std::runtime_error("No se pudo escribir el mensaje.");
    }
}

void logMessage(std::string access_message, std::string username) {
    
}

