#pragma once
#include <vector>
#include <string>
#include "..\inc\Ingredient.hpp"

using str = std::string;
using vec = std::vector<str>;

class Product {
private:
    str product_name_;
    int date_;
    vec sostav_;
    int price_;

public:
    Product();
    Product(str product_name, int date, int price, vec sostav);
    Product(const Product& p);
    Product& operator=(const Product& other);
    ~Product();
    Product operator+(const Product& other) const;
    Product operator-(const Product& other) const;
    Product operator-=(const Product& other);
    void setname_(str newname);
    void set_price_(int newprice);
    void set_date_(int newdate);
    void short_date_(int days);
    void add_to_sostav_(const str& new_element);
    str get_product_name_() const;
    int get_price_() const;
    int get_date_() const;
    vec get_sostav_() const;
    void print_info() const;
};