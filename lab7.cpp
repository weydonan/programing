#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
using Vector = std::vector<int>;
using Array = std::array<int, 10>;

// Пункт 1 

void sort1(Array arr) {
int n = 10;
for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
        if (arr[i] > arr[j]) {
            swap(arr[i], arr[j]);
        }

}

void sort2(Array& arr) {
int n = 10;
for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
        if (arr[i] > arr[j]) {
            swap(arr[i], arr[j]);
        }
}

void sort3(Array* arr) {
int n = 10;
for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
        if ((*arr)[i] > (*arr)[j]) {
            swap((*arr)[i], (*arr)[j]);
        }
}

void null() {
cout << "Конец" << endl;
}

void first(const Vector& vec) {
cout << "Вектор: [ ";
for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
}
cout << "]" << endl;
}

void second(Vector& vec) {
int x;
cout << "Введите элемент вектора: " << endl;
cin >> x;
vec.insert(vec.begin(), x);
}

void third(Vector& vec) {
int x;
cout << "Введите элемент вектора: " << endl;
cin >> x;
vec.push_back(x);
}

void fourth(Vector& vec) {
vec.clear();
}

void fifth(const Vector& arr, int target) {
    Vector tmas;

    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            tmas.push_back(i);
        }
    }
    if (tmas.empty()) {
        std::cout << "Число " << target << " не найдено" << std::endl;
    }
    else {
        std::cout << "Число " << target << " найдено на индексах: [";
        for (size_t i = 0; i < tmas.size(); i++) {
            std::cout << tmas[i];
            if (i != tmas.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}

void sixth(Vector& vec) {
int K;
cout << "Введите положительное число K: ";
cin >> K;

cout << "До: ";
first(vec);


int n = 0;
int sum = 0;
while (sum < K) {
    n++;
    sum += n;
}

if (sum == K) {

    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
    }
    cout << "Добавлены числа от 1 до " << n << " в конец" << endl;
}
else {

    Vector result;
    for (size_t i = 0; i < vec.size(); i++) {
        result.push_back(vec[i]);
        if (i % 2 == 0) {
            result.push_back(vec[i]);
        }
    }
    vec = result;
    cout << "Продублированы элементы на четных позициях" << endl;
}

cout << "После: ";
first(vec);

}

int main() {
setlocale(LC_ALL, "Russian");
int num;
Vector vec;
vec.reserve(100'000);

do {
    cout << "Меню" << endl;
    cout << "0 - Выход" << endl;
    cout << "1 - Показать вектор" << endl;
    cout << "2 - Добавить элемент в начало вектора" << endl;
    cout << "3 - Добавить элемент в конец вектора" << endl;
    cout << "4 - Очистить вектор" << endl;
    cout << "5 - Найти элемент" << endl;
    cout << "6 - Задание варианта" << endl;
    cout << "Номер: " << endl;
    cin >> num;

    switch (num) {
    case 0:
        break;
    case 1:
        int i;
        first(vec);
        break;
    case 2:
        second(vec);
        break;
    case 3:
        third(vec);
        break;
    case 4:
        fourth(vec);
        break;
    case 5:
        cout << "Введите число" << endl;
        int target;
        cin >> target;
        fifth(vec, target);
        break;
    case 6:
        sixth(vec);
        break;
    default:
        std::cout << "Неверная команда" << std::endl;
    }
} while (num != 0);

null();

// Пункт 2

Array arr = { 0, 3, 5, 9, 4, 1, 6, 8, 7, 2 };

cout << "Массив:" << endl;
for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
}
cout << endl;


sort1(arr);
cout << "Отсортированный массив по значению:" << endl;
for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
}
cout << endl;

arr = { 0, 3, 5, 9, 4, 1, 6, 8, 7, 2 };

cout << "Массив:" << endl;
for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
}
cout << endl;


sort2(arr);
cout << "Отсортированный массив по ссылке:" << endl;
for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
}
cout <<endl;

arr = { 0, 3, 5, 9, 4, 1, 6, 8, 7, 2 };

cout << "Массив:" << endl;
for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
}
cout << endl;

sort3(&arr);
cout << "Отсортированный массив по указателю:" <<endl;
for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
}
cout << endl;

return 0;
}
// 3 Пункт
/*
ЗНАЧЕНИЕ
Создается копия массива
Изменения применяются только к копии
Используется дополнительная память для копии
Медленнее для больших масивов
ССЫЛКА
Передается оригинальынй массив
Изменения напрямую применяются к оригиналу
Копия не создается, память экономится
Быстрее для больших объектов
УКАЗАТЕЛЬ
Передается адрес памяти массива
Изменения напрямую применяются к оригиналу, можно передать nullptr
Копия не создается, память экономится
Быстрее для больших объектов, но более громоздкий в сравнении с ссылками

В первой задаче был выбран std::vector, поскольку требовалась возможность
изменения размера массива во время выполнения программы.
Во второй задаче использовался std::array, так как размер массива был
известен заранее и оставался постоянным. Оба контейнера работают схожим образом при чтении и записи элементов,
но std::array обеспечивает лучшую производительность для массивов
фиксированного размера, так как не требует динамического выделения памяти.
*/