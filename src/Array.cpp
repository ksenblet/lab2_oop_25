#include "Array.h"

// Конструктор по умолчанию
Array::Array() : size(0), data(nullptr) {}

// Конструктор с заполнением
Array::Array(const size_t& arraySize, unsigned char defaultValue) {
    size = arraySize;
    data = new unsigned char[arraySize];
    
    // заполняем массив значением по умолчанию
    for (size_t i = 0; i < arraySize; ++i) {
        data[i] = defaultValue;
    }
}

// Конструктор из списка инициализации (C++11)
Array::Array(const std::initializer_list<unsigned char>& initialValues) {
    size = initialValues.size();
    data = new unsigned char[size];
    
    // копируем значения из списка инициализации
    size_t index = 0;
    for (const auto& value : initialValues) {
        data[index++] = value;
    }
}

// Конструктор из строки
Array::Array(const std::string& sourceString) {
    size = sourceString.size();
    data = new unsigned char[size];
    
    // копируем символы из строки
    for (size_t i = 0; i < size; ++i) {
        data[i] = static_cast<unsigned char>(sourceString[i]);
    }
}

// Копирующий конструктор (глубокое копирование)
Array::Array(const Array& other) {
    size = other.size;
    data = new unsigned char[size];
    
    // Глубокое копирование данных
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Перемещающий конструктор (C++11) крадет ресурсы
Array::Array(Array&& other) noexcept {
    
    // Крадем ресурсы у другого объекта
    size = other.size;
    data = other.data;
    
    // Обнуляем другой объект, чтобы деструктор не освободил память
    other.size = 0;
    other.data = nullptr;
}

bool Array::equals(const Array& other) const {
    if (other.size != size) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool Array::moreThan(const Array& other) const {
    if (other.size != size) {
        return size > other.size;
    }
    for (size_t i = 0; i < size; ++i) {
        if (data[i] < other.data[i]) {
            return false;
        } 
        if (data[i] > other.data[i]) {
            return true;
        }
    }
    return false;
}

bool Array::lessThan(const Array& other) const {
    if (other.size != size) {
        return size < other.size;
    }
    for (size_t i = 0; i < size; ++i) {
        if (data[i] > other.data[i]) {
            return false;
        } 
        if (data[i] < other.data[i]) {
            return true;
        }
    }
    return false;
}

// установка значения по индексу (для BitString)
void Array::insertIndex(size_t index, const char toInsert) {
    // индекс в пределах массива?
    if (index >= size) {
        throw std::logic_error("Index out of array bounds");
    }
    
    data[index] = static_cast<unsigned char>(toInsert);
}

// Вывод массива
std::ostream& Array::print(std::ostream& outputStream) {
    for (size_t i = 0; i < size; ++i) {
        outputStream << data[i];
    }
    return outputStream;
}

// ГЕТТЕРЫ
size_t Array::getSize() const {
    return size;
}

unsigned char* Array::getData() const {
    return data;
}

// СЕТТЕРЫ 
void Array::setData(size_t newSize, unsigned char* newData) {
    delete[] data;
    size = newSize;
    data = newData;
}

void Array::setSize(size_t newSize) {
    if (newSize == size) {
        return;
    }
    unsigned char* newData = new unsigned char[newSize];
    size_t copySize = (newSize < size) ? newSize : size;
    for (size_t i = 0; i < copySize; ++i) {
        newData[i] = data[i];
    }
    for (size_t i = copySize; i < newSize; ++i) {
        newData[i] = '0';
    }
    delete[] data;
    data = newData;
    size = newSize;
}

// деструктор 
Array::~Array() noexcept {
    delete[] data;
    data = nullptr;
    size = 0;
}