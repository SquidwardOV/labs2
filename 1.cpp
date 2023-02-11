#include <iostream>
using namespace std;
 
int main()
{
    setlocale(LC_ALL, "Russian");
    int i, j, k, n, m, itmp;
    double tmp;
    cout << "Введите число строк матрицы: " << endl;
    cin >> n;
    cout << "Введите число столбцов матрицы: " << endl;
    cin >> m;
    int *imin = new int [n];            //номера столбцов минимальных элементов в каждой строке
    double** arr = new double*[n];      //двумерный массив! Сначала получаем массив адресов строк. Кроме того, матрица из double, а не int
    cout << "элементы: " << endl;
    for (i = 0; i < n; ++i)
    {
        arr[i] = new double[m];         //строка
        for (j = 0; j < m; ++j)         //вводим строку
        {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }
    cout << endl;
    cout << "исходная матрица: " << endl;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
            cout << arr[i][j] << '\t';
        cout << endl;
    }
    for (i = 0; i < n; ++i)             //найдем минимальные элементы в каждой строке
    {
        imin[i] = 0;                    //сначала номер столбца пусть = 0
        for (j = 1; j < m; ++j)         //с 1 до конца строки
        {
            if (arr[i][j] < arr[i][imin[i]])
                imin[i] = j;            //новый номер столбца с минимальным элементом
        }
    }
 
    for (i = 0; i < n - 1; ++i)         //сортируем полученный массив
    {
        for (j = i +1; j < n; ++j)
        {
            if (arr[i][imin[i]] > arr[j][imin[j]])  //в строках сравниваем только элементы в столбцах с минимальным элементом
            {
                for (k = 0; k < m; ++k)             //меняем местами две строки
                {
                    tmp = arr[i][k];
                    arr[i][k] = arr[j][k];
                    arr[j][k] = tmp;
                }
                itmp = imin[i];                 //и номера столбцов с минимальным элементом, т.к. строки поменены местами
                imin[i] = imin[j];
                imin[j] = itmp;
            }
        }
    }
    cout << "конечная матрица:" << endl;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
            cout << arr[i][j] << '\t';
        cout << endl;
    }
    for (i = 0; i < n; ++i)             //удаляем запрошенную память
        delete[] arr[i];                //сначала строки
    delete[] arr;                       // затем и массив адресов строк
    delete[] imin;
 
    system("pause");
    return 0;
}
