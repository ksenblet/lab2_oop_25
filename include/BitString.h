#pragma once
#include <iostream>
#include "Array.h"  

class BitString {
public:
    //конструкторы
    BitString();
    BitString(const size_t& arraySize, unsigned char defaultValue = '0');
    BitString(const std::initializer_list<unsigned char>& initialValues);   
    BitString(const std::string& sourceString);

    BitString(const BitString& other); 
    BitString(BitString&& other) noexcept;

    // операции: and, or, xor, not
    BitString bitAnd(const BitString& other);   
    BitString bitOr(const BitString& other);    
    BitString bitXor(const BitString& other);    
    BitString bitNot();                         

    // вспомог методы
    void print() const; // вывод бит стр
    std::string toString() const; // преобраз в стр

    // деструктор
    ~BitString() noexcept;

private:
    Array bitArray;  // хранилище
    bool validChar(char c); // допустимый бит
    BitString addingZeroes(size_t length) const; // дополняет до нужной длины
};