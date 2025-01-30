# Создаём переменную TEST_FILES и инициализируем её путями к файлам,
# которые в последствии при сборке проекта будут скомпилированы и соединены
# в единый исполняемый файл.
set(TEST_FILES test_shortest_path.cpp ../src/HeapDijkstra.cpp ../src/file_reader.cpp)
# Эта строка создает исполняемый файл с именем ShortestPathTests, 
# который будет скомпилирован из исходных файлов, указанных в переменной TEST_FILES.
add_executable(ShortestPathTests ${TEST_FILES})
# Эта строка указывает компилятору, где искать заголовочные файлы (.h),
# необходимые для компиляции ShortestPathTests.
target_include_directories(ShortestPathTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../includes) 
# Команда определяет с какими библиотеками нужно связать результирующий исполняемый файл.
target_link_libraries(ShortestPathTests GTest::gtest GTest::gtest_main)
# Указываем наличие тестов в данной дирректории.
add_test(runUnitTests ShortestPathTests)
# Активируем поддержку проведения тестирования.
enable_testing()
