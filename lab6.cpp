#include <iostream>
#include <string>
using namespace std;

// Пункт 1
int* findZeroes(int** matrix, int Rows, int Cols, int* zeroRowsCount) {
    int* temp = (int*)malloc(Rows * sizeof(int));
    *zeroRowsCount = 0;
    if (temp == NULL) {
        return NULL;
    }
    for (int i = 0; i < Rows; i++) {
        int isZero = 0;
        for (int j = 0; j < Cols; j++) {
            if (matrix[i][j] == 0) {
                isZero = 1;
                break;
            }
        }
        if (isZero) {
            temp[(*zeroRowsCount)++] = i;
        }
    }


    int* zeroRows = (int*)malloc((*zeroRowsCount) * sizeof(int));
    if (zeroRows == NULL) {
        free(temp);
        *zeroRowsCount = 0;
        return NULL;
    }

    for (int i = 0; i < *zeroRowsCount; i++) {
        zeroRows[i] = temp[i];
        std::cout << zeroRows[i] << std::endl;
    }

    free(temp);
    return zeroRows;
}


int* deleteRows(int** matrix, int rows, int cols, int* zeroRows, int zeroRowsCount, int* newRows) {
    *newRows = rows - zeroRowsCount;


    int* newMatrix = (int*)malloc((*newRows) * cols * sizeof(int));
    if (newMatrix == NULL) {
        *newRows = 0;
        return NULL;
    }

    int newRow = 0;
    for (int i = 0; i < rows; i++) {

        bool skip = false;
        for (int j = 0; j < zeroRowsCount; j++) {
            if (i == zeroRows[j]) {
                skip = true;
                break;
            }
        }

        if (skip == false) {

            for (int k = 0; k < cols; k++) {
                int newIndex = newRow * cols + k;
                newMatrix[newIndex] = matrix[i][k];
            }
            newRow++;
        }
    }

    return newMatrix;
}

int main(void) {
    setlocale(LC_ALL, "Russian");
    int a, b, c, d;

    cout << "Введите A:" << endl;
    cin >> a;
    if (a < 0) {
        cout << "Некоректное число" << endl;
        cout << "Введите A:" << endl;
        cin >> a;
    }
    cout << "ВВедите B:" << endl;
    cin >> b;
    if (b < 0) {
        cout << "Некоректное число" << endl;
        cout << "Введите B:" << endl;
        cin >> b;
    }
    cout << "Введите C:" << endl;
    cin >> c;
    cout << "Введите D:" << endl;
    cin >> d;


    int** matrix = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        matrix[i] = (int*)malloc(2 * sizeof(int));
    }

    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;

    cout << "Начальная матрица:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

  
    int newRows = 2 + a;
    int newCols = 2 + b;

    int** newMatrix = (int**)malloc(newRows * sizeof(int*));
    for (int i = 0; i < newRows; i++) {
        newMatrix[i] = (int*)malloc(newCols * sizeof(int));
    }

    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            if (i >= a && j >= b) {
                newMatrix[i][j] = matrix[i - a][j - b];
            }
            else {
                newMatrix[i][j] = i * c + j * d;
            }
        }
    }


    for (int i = 0; i < 2; i++) {
        free(matrix[i]);
    }
    free(matrix);

    cout << "Новая матрица:" << endl;
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }


    int zeroRowsCount;
    int* zeroRows = findZeroes(newMatrix, newRows, newCols, &zeroRowsCount);


    int finalRows;
    int* finalMatrix = deleteRows(newMatrix, newRows, newCols, zeroRows, zeroRowsCount, &finalRows);
    for (int i = 0; i < newRows; i++) {
        free(newMatrix[i]);
    }
    free(newMatrix);
    cout << "Новая матрица без 0: " << endl;
    if (finalMatrix != NULL) {
        for (int i = 0; i < finalRows; i++) {
            for (int j = 0; j < newCols; j++) {
                int index = i * newCols + j;
                cout << finalMatrix[index] << " ";
            }
            cout << endl;
        }
        free(finalMatrix);
    }
    if (zeroRows != NULL) {
        free(zeroRows);
    }

    return 0;

    
    // 2задание2
    int A,B;
    cout << "Введите a и b:" << endl;
    cin >> A;
    cin >> B;

    int* pA = new int(A);
    int* pB = new int(B);

    *pA = *pA * 2;
    cout << "Увелеченное значение а в 2 раза: " << *pA << endl;

    int junk = *pA;;
    *pA = *pB;
    *pB = junk;
    cout << "Теперь b: " << *pB << " Теперь a: " << *pA;
    delete pA;
    delete pB;
    
}