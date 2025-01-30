# Указываем минимальную поддерживаемую версию CMake.
cmake_minimum_required(VERSION 3.17) 
# Даём имя будущему исполняемому файлу.
project(ShortestPath)

# 
find_package(GTest REQUIRED)

# Создаём переменную SOURCE_FILES и инициализируем её путями к файлам,
# которые в последствии при сборке проекта будут скомпилированы и соединены
# в единый исполняемый файл.
set(SOURCE_FILES src/main.cpp src/file_reader.cpp src/HeapDijkstra.cpp)
# Эта строка создает исполняемый файл с именем ShortestPath, 
# который будет скомпилирован из исходных файлов, указанных в переменной SOURCE_FILES.
add_executable(ShortestPath ${SOURCE_FILES})
# Эта строка указывает компилятору, где искать заголовочные файлы (.h),
# необходимые для компиляции ShortestPath.
target_include_directories(ShortestPath PUBLIC includes)

# Просто добавляете подкаталог, и CMake автоматически обрабатывает CMakeLists.txt 
# в этой папке. Позволяет разделить сборку основной программы и тестов в разные папки.
add_subdirectory(test)

# Перемещает все исполняемые файлы в каталог сборки.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
