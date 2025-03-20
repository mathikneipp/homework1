CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Ejecutables individuales
TARGET_MATRIX = matrix_exec
TARGET_COMPILE_TIME = compile_time_exec
TARGET_LOG_SYSTEM = log_system_exec
TARGET_LIST = list_exec

# Reglas para compilar y ejecutar cada archivo individualmente
run_matrix: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -o $(TARGET_MATRIX) matrix.cpp
	./$(TARGET_MATRIX)

run_compile_time: compile_time.cpp compile_time.h
	$(CXX) $(CXXFLAGS) -o $(TARGET_COMPILE_TIME) compile_time.cpp
	./$(TARGET_COMPILE_TIME)

run_log_system: log_system.cpp log_system.h
	$(CXX) $(CXXFLAGS) -o $(TARGET_LOG_SYSTEM) log_system.cpp
	./$(TARGET_LOG_SYSTEM)

run_list: list.cpp list.h
	$(CXX) $(CXXFLAGS) -o $(TARGET_LIST) list.cpp
	./$(TARGET_LIST)

# Regla para limpiar todos los ejecutables generados
clean:
	rm -f $(TARGET_MATRIX) $(TARGET_COMPILE_TIME) $(TARGET_LOG_SYSTEM) $(TARGET_LIST)