#include "BitString.h"

#include <iostream>
#include <stdexcept>
#include <string>

#include "Array.h"

// Конструктор по умолчанию
BitString::BitString() : bitArray() {}

// Конструктор с заполнением
BitString::BitString(const size_t& arraySize, unsigned char defaultValue) : bitArray(arraySize, defaultValue) {  
    if (!validChar(defaultValue)) {
        throw std::invalid_argument("defaultValue incorrect");
    } 
}

// Конструктор из списка инициализации
BitString::BitString(const std::initializer_list<unsigned char>& initialValues) : bitArray(initialValues) {
    for (const auto& c : initialValues) {
        if (!validChar(c)) {
            throw std::invalid_argument("Incorrect input: you can enter 0 or 1");
        } 
    }
}  

// Конструктор из строки
BitString::BitString(const std::string& sourceString) : bitArray(sourceString) { 
    if (sourceString.empty()) {
        throw std::invalid_argument("Empty string");
    }
    for (char c : sourceString) {
        if (!validChar(c)) {
            throw std::invalid_argument("Incorrect input: you can enter 0 or 1");
        } 
    } 
}
 
// Копирующий конструктор
BitString::BitString(const BitString& other) 
    : bitArray(other.bitArray) {
}
    
// Перемещающий конструктор
BitString::BitString(BitString&& other) noexcept 
    : bitArray(std::move(other.bitArray)) {  
}

// AND операция
BitString BitString::bitAnd(const BitString& other) {
    size_t maxLength = std::max(bitArray.getSize(), other.bitArray.getSize());
    BitString padded1 = addingZeroes(maxLength);
    BitString padded2 = other.addingZeroes(maxLength);
    BitString result(maxLength, '0');

    for (size_t i = 0; i < maxLength; i++) {
        if (padded1.bitArray.getData()[i] == '1' && padded2.bitArray.getData()[i] == '1') {
            result.bitArray.insertIndex(i, '1');
        } else {
            result.bitArray.insertIndex(i, '0');
        }
    }
    return result;    
}

// OR операция
BitString BitString::bitOr(const BitString& other) {
    size_t maxLength = std::max(bitArray.getSize(), other.bitArray.getSize());
    BitString padded1 = addingZeroes(maxLength);
    BitString padded2 = other.addingZeroes(maxLength);
    BitString result(maxLength, '0');

    for (size_t i = 0; i < maxLength; i++) {
        if (padded1.bitArray.getData()[i] == '1' || padded2.bitArray.getData()[i] == '1') {
            result.bitArray.insertIndex(i, '1');
        } else {
            result.bitArray.insertIndex(i, '0');
        }
    }
    return result;    
}

// XOR операция
BitString BitString::bitXor(const BitString& other) {
    size_t maxLength = std::max(bitArray.getSize(), other.bitArray.getSize());
    BitString padded1 = addingZeroes(maxLength);
    BitString padded2 = other.addingZeroes(maxLength);
    BitString result(maxLength, '0');

    for (size_t i = 0; i < maxLength; i++) {
        if (padded1.bitArray.getData()[i] != padded2.bitArray.getData()[i]) {
            result.bitArray.insertIndex(i, '1');
        } else {
            result.bitArray.insertIndex(i, '0');
        }
    }
    return result;
}

// NOT операция
BitString BitString::bitNot() {
    BitString result(bitArray.getSize(), '0');

    for (size_t i = 0; i < bitArray.getSize(); i++) {
        if (bitArray.getData()[i] == '0') {
            result.bitArray.insertIndex(i, '1');
        } else {
            result.bitArray.insertIndex(i, '0');
        }
    }
    return result;
}

// вспомогательные методыы

// вывод бит стр
void BitString::print() const {
    for (size_t i = 0; i < bitArray.getSize(); i++) {
        std::cout << bitArray.getData()[i];
    }
    std::cout << std::endl;
}

// преобразование в стр
std::string BitString::toString() const {
    if (bitArray.getData() == nullptr) {
        return "";
    }
    return std::string(bitArray.getData(), bitArray.getData() + bitArray.getSize());
}

// проверка допустимого бита
bool BitString::validChar(char c) {
    return (c == '0' || c == '1');
}

// дополнение бит стр до нужной длины
BitString BitString::addingZeroes(size_t length) const {
    if (bitArray.getSize() >= length) {
        return *this;
    }
    BitString result(length, '0'); 

    size_t offset = length - bitArray.getSize();
    for (size_t i = 0; i < bitArray.getSize(); i++) {
        result.bitArray.insertIndex(offset + i, bitArray.getData()[i]);
    }
    return result;
}

BitString::~BitString() noexcept {
    // деструктор Array автоматически освободит память
}