#pragma once
#include <string>
#include <iostream>

class Array {
public:
    //конструкторы как в усл
    Array();
    Array(const size_t& arraySize, unsigned char defaultValue = 0);
    Array(const std::initializer_list<unsigned char>& initialValues);
    Array(const std::string& sourceString);
    
    //перемещение по образцу
    Array(Array&& other) noexcept;

    // ар. опер
    Array add(const Array& other); // как метод
    Array remove(const Array& other); // как метод
    Array(const Array& other); // копирование

    // сравнения
    bool equals(const Array& other) const; // равно(сравнивает размеры)
    bool moreThan(const Array& other) const;
    bool lessThan(const Array& other) const;

    // вспомогательные метод для bitstring
    void insertIndex(size_t index, const char toInsert);
    std::ostream& print(std::ostream& outputStream);
    // геттеры (только чтение)
    size_t getSize() const;
    unsigned char* getData() const;

    // сеттеры нарушают иммутабельность(можно изменить после создания)

    // деструктор
    virtual ~Array() noexcept;

private:
    size_t size;           
    unsigned char* data;   
};