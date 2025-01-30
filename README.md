# ShortestPath

`ShortestPath` - это программа для поиска кратчайшего пути в графе.

## Использование

```bash
./ShortestPath [OPTIONS] -f <path/to/graph/file>
```

## Опции
* ```-f <path/to/graph/file>```: Указывает путь к файлу с данными о графе.
* ```-t```: Выводит время выполнения программы.
## Примеры

```bash
  ./ShortestPath -f ../src/examples/basic_example_1.txt
  ./ShortestPath -t -f ../src/examples/basic_example_1.txt
```  
## Установка

Для корректной установки необходимо склонировать репозиторий:

```bash
git clone <URL_вашего_репозитория>
cd <название_папки_репозитория>
```

## Сборка с помощью CMake

Для сборки проекта необходимо использовать CMake. Убедитесь, что CMake установлен на вашей системе.

