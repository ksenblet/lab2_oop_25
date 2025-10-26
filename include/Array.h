#pragma once

#include <iostream>
#include <string>

class Array {
public:
    //конструкторы как в усл
    Array();
    Array(const size_t& arraySize, unsigned char defaultValue = 0);
    Array(const std::initializer_list<unsigned char>& initialValues);
    Array(const std::string& sourceString);
    Array(Array&& other) noexcept;
    Array(const Array& other); 

    // сравнения
    bool equals(const Array& other) const; 
    bool moreThan(const Array& other) const;
    bool lessThan(const Array& other) const;

    // вспомогательные метод для bitstring
    void insertIndex(size_t index, const char toInsert);
    std::ostream& print(std::ostream& outputStream);

    // геттеры (только чтение)
    size_t getSize() const;
    unsigned char* getData() const;

    // сеттеры
    void setData(size_t newSize, unsigned char* newData);
    void setSize(size_t newSize);

    // деструктор
    virtual ~Array() noexcept;

private:
    size_t size;           
    unsigned char* data;   
};