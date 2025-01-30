#include "../includes/HeapDijkstra.h"
#include "../includes/file_reader.h"
#include <unistd.h>

int main(int argc, char **argv) 
{

    int rez;
    string filename;
    bool flag = false;

    if(argc == 1) 
    { 
        cout << "\033[34mShortestPath\033[0m - программа для поиска кратчайшего пути в графе." << endl;
        cout << "Использование:" << endl;
        cout << "\033[35m  ./ShortestPath [OPTIONS] -f <path/to/graph/file>\033[0m" << endl;
        cout << endl;
        cout << "Где [OPTIONS] могут быть:" << endl;
        cout << "\033[31m  -f\033[0m \033[34m<path/to/graph/file>\033[0m: Указывает путь к файлу с данными о графе." << endl;
        cout << "\033[31m  -t\033[0m: Выводит время выполнения программы." << endl;
        cout << endl;
        cout << "Примеры:" << endl;
        cout << "\033[35m  ./ShortestPath -f ../src/examples/basic_example_1.txt\033[0m" << endl;
        cout << "\033[35m  ./ShortestPath -t -f ../src/examples/basic_example_1.txt\033[0m" << endl;
        return 0;
    }

    while ( (rez = getopt(argc, argv, ":f:t")) != -1)
    {
		switch (rez) 
        {
            case 'f':
            {   
                filename = optarg;
            }
            break;

            case 't': 
            {
                flag = true;
            }
            break;

            case ':':
            {
                cerr << "Option needs a value" << endl;
                return 1;
            }
            case '?':
            {
                cerr << "Unrecognized option" << endl;
                return 1;
            }
        }
    }

    try
    {
        auto myGraph = readGraphFromFile(filename);
        if (!flag)
        {
            int result = shortestPath(myGraph);
            if (result != -1)
            {
                cout << "Кратчайший путь в " << myGraph.endNode << ": " << result << endl;
            }
            else
            {
                cout << "Путь в " << myGraph.endNode << " не существует" << endl;
            }
        }
        else
        {
            auto start = chrono::high_resolution_clock::now();
            int result = shortestPath(myGraph);
            auto end = chrono::high_resolution_clock::now();
            if (result != -1)
            {
                chrono::duration<double> duration = end - start;
                cout << "Кратчайший путь в " << myGraph.endNode << ": " << result << endl;
                cout << "Время выполнения: " << duration.count() << " секунд" << endl;
            }
            else
            {
                chrono::duration<double> duration = end - start;
                cout << "Путь в " << myGraph.endNode << " не существует" << endl;
                cout << "Время выполнения: " << duration.count() << " секунд" << endl;
            }
        }
        }
    catch (const FileFormatError& e) 
    {
        cerr << "File format error: " << e.what() << endl;
        return 1;
    }
    catch (const InvalidVertexError& e) 
    {
        cerr << "Invalid vertex error: " << e.what() << endl;
        return 1;
    }
    catch (const PathPointsError& e) 
    {
        cerr << "Path points error: " << e.what() << endl;
        return 1;
    }
    catch (const runtime_error& e) 
    {
        cerr << "Runtime error: " << e.what() << endl;
        return 1;
    }
    catch (const invalid_argument& e) 
    {
        cerr << "Invalid argument error: " << e.what() << endl;
        return 1;
    }
    catch (const exception& e) 
    {
        cerr << "An unexpected error occurred: " << e.what() << endl;
        return 1;
    }
    return 0;
}