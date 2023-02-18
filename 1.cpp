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
    int* imin = new int[n];            //номера столбцов минимальных элементов в каждой строке
    double** arr = new double* [n];     
    cout << "элементы: " << endl;
    for (i = 0; i < n; ++i)
    {
        arr[i] = new double[m];         
        for (j = 0; j < m; ++j)         
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
            cout << *( *(arr+i) +j) << '\t';
        cout << endl;
    }
    for (i = 0; i < n; ++i)             //поиск минимального элемента в каждой строке
    {
        imin[i] = 0;                  
        for (j = 1; j < m; ++j)         
        {
            if (*(*(arr+i)+j) < *( *(arr+i)+ imin[i]))
                imin[i] = j;            
        }
    }

    for (i = 0; i < n - 1; ++i)         //сортировка полученного массива
    {
        for (j = i + 1; j < n; ++j)
        {
            if ( *(*(arr+i) + imin[i]) > *(*(arr+j)+imin[j]))  
            {
                for (k = 0; k < m; ++k)             //замена мест строк
                {
                    tmp = *(*(arr+i)+k);
                    *(*(arr+i)+k) = *(*(arr + j) + k);
                    *(*(arr + j) + k) = tmp;
                }
                itmp = imin[i];                 //замена номера столбцов с минимальным элементом
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
    for (i = 0; i < n; ++i)             
        delete[] arr[i];                
    delete[] arr;                       
    delete[] imin;

    system("pause");
    return 0;
}
