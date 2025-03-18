CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Archivos fuente y sus objetos
SRCS = matrix.cpp compile_time.cpp log_system.cpp list.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = matrix.hpp compile_time.hpp log_system.hpp list.hpp

# Ejecutable
TARGET = main

all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Reglas individuales para cada archivo fuente
matrix.o: matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp -o matrix.o

compile_time.o: compile_time.cpp compile_time.hpp
	$(CXX) $(CXXFLAGS) -c compile_time.cpp -o compile_time.o

log_system.o: log_system.cpp log_system.hpp
	$(CXX) $(CXXFLAGS) -c log_system.cpp -o log_system.o

list.o: list.cpp list.hpp
	$(CXX) $(CXXFLAGS) -c list.cpp -o list.o

# Regla para limpiar archivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)
	