#include <iostream>
#include <cmath>
using namespace std;

// Функція для введення матриці
void InputMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
}

// Функція для підрахунку локальних мінімумів
void CountLocalMinima(int** matrix, int size, int& count) {
    count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int element = matrix[i][j];
            bool isLocalMin = true;

            // Перевірка всіх сусідніх елементів
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < size && l >= 0 && l < size && (k != i || l != j)) {
                        if (matrix[k][l] <= element) {
                            isLocalMin = false;
                            break;
                        }
                    }
                }
                if (!isLocalMin) break;
            }
            if (isLocalMin) count++;
        }
    }
}

// Функція для обчислення суми модулів елементів вище головної діагоналі
int SumAboveMainDiagonal(int** matrix, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            sum += abs(matrix[i][j]);
    return sum;
}

int main() {
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;

    int** matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];

    InputMatrix(matrix, size);

    int localMinimaCount;
    CountLocalMinima(matrix, size, localMinimaCount);
    cout << "Number of local minima: " << localMinimaCount << endl;

    int sumAboveDiagonal = SumAboveMainDiagonal(matrix, size);
    cout << "Sum of absolute values above main diagonal: " << sumAboveDiagonal << endl;

    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
