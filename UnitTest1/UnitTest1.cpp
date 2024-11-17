#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3 іт/Source.cpp"  // Шлях до вашого вихідного файлу з функціями

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // Тест для CountLocalMinima
        TEST_METHOD(TestCountLocalMinima)
        {
            const int size = 3;
            int** matrix = new int* [size];
            for (int i = 0; i < size; i++)
                matrix[i] = new int[size];

            // Ініціалізуємо тестову матрицю
            int testData[size][size] = {
                { 10, 20, 30 },
                { 40,  5, 60 },
                { 70, 80, 90 }
            };
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    matrix[i][j] = testData[i][j];

            int localMinimaCount = 0;
            CountLocalMinima(matrix, size, localMinimaCount);

            Assert::AreEqual(1, localMinimaCount, L"Кількість локальних мінімумів повинна дорівнювати 1.");

            for (int i = 0; i < size; i++)
                delete[] matrix[i];
            delete[] matrix;
        }

        // Тест для SumAboveMainDiagonal
        TEST_METHOD(TestSumAboveMainDiagonal)
        {
            const int size = 3;
            int** matrix = new int* [size];
            for (int i = 0; i < size; i++)
                matrix[i] = new int[size];

            // Ініціалізуємо тестову матрицю
            int testData[size][size] = {
                {  1,  2,  3 },
                {  4,  5,  6 },
                {  7,  8,  9 }
            };
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    matrix[i][j] = testData[i][j];

            int sumAboveDiagonal = SumAboveMainDiagonal(matrix, size);

            Assert::AreEqual(11, sumAboveDiagonal, L"Сума модулів над головною діагоналлю повинна дорівнювати 11.");

            for (int i = 0; i < size; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
    };
}
