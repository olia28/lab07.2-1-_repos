#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int**& matrix, const int rows, const int cols, const int low, const int high)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = (rand() % 100) - 49;
}

void Print(int** matrix, const int rows, const int cols)
{
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << matrix[i][j];

        cout << endl;
    }
}

int FindMaxInMatrix(int** matrix, const int rows, const int cols)
{
    int maxNumber = matrix[0][cols];

    for (int i = 1; i < rows; i++)
    {
        if (maxNumber < matrix[i][cols])
        {
            maxNumber = matrix[i][cols];
        }
    }
    return maxNumber;
}

int FindSumOfMaxElementsInEvenCols(int** matrix, const int rows, const int cols)
{
    int sum = 0;

    for (int j = 0; j < cols; j++)
        if (j % 2 == 0)
        {
            int max = FindMaxInMatrix(matrix, rows, j);
            sum += max;
        }

    return sum;
}

int main()
{
    srand(time(NULL));

    int rows, cols;

    cout << "Enter rows count: "; cin >> rows;
    cout << "Enter columns count: "; cin >> cols;

    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    Create(matrix, rows, cols, -50, 50);

    cout << "Created matrix:\n";

    Print(matrix, rows, cols);

    cout << endl;

    cout << "Sum max number in even column : " << FindSumOfMaxElementsInEvenCols(matrix, rows, cols) << endl;

}