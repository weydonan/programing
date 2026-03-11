#include "product.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

using str = std::string;
using vec = std::vector<str>;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    vec sostavA = { "овес","овес","овес", "вода", "сушенные фрукты" };
    Product productA("Каша", 90, 30, sostavA);

    vec sostavB = { "кофеин","кофеин","кофеин","кофеин", "таурин", "вода" };
    Product productB("Энергетик", 180, 90, sostavB);

    Product productPlus = productA + productB;
    Product productMinus = productA - productB;

    int n;
    do {
        std::cout << " МЕНЮ " << std::endl;
        std::cout << "0) Выход" << std::endl;
        std::cout << "1) Информация о товаре А" << std::endl;
        std::cout << "2) Информация о товаре Б" << std::endl;
        std::cout << "3) Показать результат A + B" << std::endl;
        std::cout << "4) Показать результат A - B" << std::endl;
        std::cout << "5) Применить A -= B" << std::endl;
        std::cout << "6) Изменить название товара А" << std::endl;
        std::cout << "7) Изменить цену товара А" << std::endl;
        std::cout << "8) Изменить срок годности товара А" << std::endl;
        std::cout << "9) Уменьшить срок годности товара А" << std::endl;
        std::cout << "10) Добавить ингредиент в состав товара А" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> n;

        str input_str;
        int input_int;

        switch (n) {
        case 0:
            std::cout << "Выход из программы..." << std::endl;
            break;

        case 1:
            productA.print_info();
            break;

        case 2:
            productB.print_info();
            break;

        case 3:
            std::cout << productA.get_product_name_() << " + " << productB.get_product_name_() << " = " << std::endl;
            productPlus.print_info();
            break;

        case 4:
            std::cout << productA.get_product_name_() << " - " << productB.get_product_name_() << " = " << std::endl;
            productMinus.print_info();
            break;

        case 5:
            productA -= productB;
            std::cout << "После A -= B:" << std::endl;
            productA.print_info();
            productPlus = productA + productB;
            productMinus = productA - productB;
            break;

        case 6: {
            std::cout << "Введите новое название для товара А: ";
            std::cin.ignore();
            std::getline(std::cin, input_str);
            productA.setname_(input_str);
            break;
        }

        case 7: {
            std::cout << "Введите новую цену для товара А: ";
            std::cin >> input_int;
            productA.set_price_(input_int);
            break;
        }

        case 8: {
            std::cout << "Введите новый срок годности для товара А (в днях): ";
            std::cin >> input_int;
            productA.set_date_(input_int);
            break;
        }

        case 9: {
            std::cout << "На сколько дней уменьшить срок годности: ";
            std::cin >> input_int;
            productA.short_date_(input_int);
            break;
        }

        case 10: {
            std::cout << "Введите элемент для добавления в состав: ";
            std::cin.ignore();
            std::getline(std::cin, input_str);
            productA.add_to_sostav_(input_str);
            productPlus = productA + productB;
            productMinus = productA - productB;
            break;
        }
        default:
            std::cout << "Ошибка: отсутствует такая команда!" << std::endl;
            break;
        }
    } while (n != 0);

    return 0;
}