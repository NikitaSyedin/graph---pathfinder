**Дана** сеть дорог в виде ненаправленного разреженного связного графа с числом вершин N (2 <= N <= 1000) и числом рёбер E (1 <= E <= 10000). На рёбрах графа указано время t (1 <= t <= 100), за которое можно проехать участок дороги. На некоторых дорогах также стоят светофоры, которые не позволяют заехать на дорогу, пока горит красный свет (ехать по дороге и выехать с дороги они не мешают). Для каждого светофора известны 2 значения: g (0 <= g <= 10) - длительность зелёного света, r (0 <= r <= 10) - длительность красного света. В каждом периоде длины g+r сначала горит зелёный свет, затем красный. 

Предполагается, что для всех светофоров первый период начинается в момент начала поиска пути. Все значения времени указываются в одной величине.

**Требуется** найти кратчайший по времени путь между 2 предложенными точками.

В рамках задачи подразумевается с использованием языка C++:
1. Выбрать и реализовать некоторую структуру графа с учётом характеристик графа и поставленной задачи поиска пути.
2. Реализовать быстрый алгоритм поиска кратчайшего пути между 2 точками.

**Входные данные** представлены в виде файла следующей структуры:
Первая строка: число вершин N и число рёбер графа E

E строк вида: u v g r (начальная вершина ребра, конечная вершина ребра, длительность зелёного света, длительность красного света, если светофора нет, то g = r = 0).

Последняя строка: начальная точка start и конечная точка end для поиска пути.

**Пример**

Входные данные:
```
4 3
0 3 33 0 0
1 3 94 0 0
2 1 43 4 6
0 2
```
Ожидаемый результат:
```
173
```

**Дополнительные требования**:
- Решение должно быть представлено в виде cmake проекта;
- Ожидаются тесты алгоритма, запускаемые через отдельный исполняемый файл. Разрешается использовать сторонние библиотеки тестирования: googletest, Catch2.