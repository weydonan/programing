#include <iostream>
#include <limits>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    // Задание 1
    int x[11];
    for (int i = 0; i < 11; ++i) {
        cout << "Введите элемент массива: "<< i+1 <<endl;
        cin >> x[i];
    }
    cout << "Условие 1:" << endl;
    int suma3 = x[0] + x[1] + x[2];
    if (suma3 > 100) {
        for (int i3 = 0; i3 < 11-1; ++i3) {
            for (int j = i3 + 1; j < 11; ++j) {
                if (x[i3] > x[j]) {
                    swap(x[i3], x[j]);
                }
            }
        }
    }
    else {
        cout << "Сумма первых 3-х чисел меньше 100" << endl;
    }
    cout << "Упорядоченный массив: ";
    for (int i4 = 0; i4 < 11; ++i4) {
        cout<< x[i4] <<", ";
    }
    cout << endl;
    cout << "Сумма 3-х масивов: " << suma3 << endl;
    // Задание 2

    const int rows = 3, cols = 4;
    int matrix[rows][cols];

    cout << "Введите 12 элементов матрицы 3x4:"<< endl;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            std::cin >> matrix[i][j];

    int columnValues[cols];        
    int sumNegatives[cols];           
    bool hasNegative[cols] = { false };

    for (int j = 0; j < cols; ++j) {
        sumNegatives[j] = 0;
        columnValues[j] = 0; 
    }

    for (int j = 0; j < cols; ++j) {
        bool foundNegative = false;
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] < 0) {
                if (!foundNegative) {
                    columnValues[j] = matrix[i][j];
                    foundNegative = true;
                }
                sumNegatives[j] += matrix[i][j];
            }
        }
        hasNegative[j] = foundNegative;
    }

    int maxSum = std::numeric_limits<int>::min();
    int columnToZero = -1;

    for (int j = 0; j < cols; ++j) {
        if (hasNegative[j]) {
            if (sumNegatives[j] > maxSum) {
                maxSum = sumNegatives[j];
                columnToZero = j;
            }
        }
    }
    if (columnToZero != -1) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][columnToZero] = 0;
        }
    }
    else {
        cout << "Нет отрицательных чисел в матрице или не требуется обнуление."<< endl;
    }

    std::cout << "Итоговая матрица:"<< endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    //Доп
    int arr[11];

    cout << "Введите " << 11 << " чисел:" << endl;
    for (int i = 0; i < 11; ++i) {
        std::cin >> arr[i];
    }

    int sumFirstThree = 0;
    for (int i = 0; i < 3; ++i) {
        sumFirstThree += arr[i];
    }

    if (sumFirstThree > 100) {
        for (int i = 0; i < 11 - 1; ++i) {
            for (int j = 0; j < 11 - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Массив отсортирован по возрастанию, так как сумма первых трех больше 100." << endl;
    }

   
    for (int i = 0; i < 11 - 1; ++i) {
        for (int j = 0; j < 11 - i - 1; ++j) {
            int sumDigitsJ = 0;
            int tempJ = arr[j];
            while (tempJ != 0) {
                sumDigitsJ += abs(tempJ % 10);
                tempJ /= 10;
            }
            int sumDigitsJPlus1 = 0;
            int tempJ1 = arr[j + 1];
            while (tempJ1 != 0) {
                sumDigitsJPlus1 += abs(tempJ1 % 10);
                tempJ1 /= 10;
            }
            if (sumDigitsJ > sumDigitsJPlus1) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

   
    bool foundTriplet = false;
    for (int i = 0; i < 11 - 2; ++i) {
        int sumDigitsI = 0;
        int temp = arr[i];
        while (temp != 0) {
            sumDigitsI += abs(temp % 10);
            temp /= 10;
        }

        int count = 1; 
        for (int j = i + 1; j < 11; ++j) {
            int sumDigitsJ = 0;
            int tempJ = arr[j];
            while (tempJ != 0) {
                sumDigitsJ += abs(tempJ % 10);
                tempJ /= 10;
            }
            if (sumDigitsJ == sumDigitsI) {
                count++;
            }
        }

        if (count >= 3) {
            foundTriplet = true;
            int printed = 0;
            cout << "Три числа с одинаковой суммой цифр (" << sumDigitsI << "): ";
            for (int k = 0; k < 11 && printed < 3; ++k) {
                int sumDigitsK = 0;
                int tempK = arr[k];
                while (tempK != 0) {
                    sumDigitsK += abs(tempK % 10);
                    tempK /= 10;
                }
                if (sumDigitsK == sumDigitsI) {
                    cout << arr[k] << " ";
                    int absNum = abs(arr[k]);
                    if (absNum < 2) {
                        cout << "(не простое)" <<endl;
                    }
                    else {
                        bool isPrime = true;
                        for (int d = 2; d <= sqrt(absNum); ++d) {
                            if (absNum % d == 0) {
                                isPrime = false;
                                break;
                            }
                        }
                        if (isPrime) {
                            cout << "(простое)"<< endl;
                        }
                        else {
                            cout << "(непростое, делители: ";
                            for (int d = 1; d <= absNum; ++d) {
                                if (absNum % d == 0) {
                                    cout << d << " ";
                                }
                            }
                            cout << ")" << endl;
                        }
                    }
                    printed++;
                }
            }
        }
    }

    if (!foundTriplet) {
        cout << "Нет трех чисел с одинаковой суммой цифр.";
    }
    cout << "Итоговый массив: ";
    for (int i = 0; i < 11; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}