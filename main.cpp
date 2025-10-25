#include <iostream>
#include <string>

#include "BitString.h"

int main(){
    std::cout << "=== Lab 2: class BitString ===" << std::endl;
    
    // === ДЕМОНСТРАЦИЯ РАЗЛИЧНЫХ КОНСТРУКТОРОВ ===
    
    std::cout << "\n Creating objects using different constructors" << std::endl;
    
    BitString firstArray{'1', '0', '1', '0', '1'};
    std::cout << "first array: ";
    firstArray.print();

    BitString secondArray{'1', '1', '0'};
    std::cout << "second array: ";
    secondArray.print();

    BitString fromString("11001");
    std::cout << "from string '11001': ";
    fromString.print();

    BitString sizedArray(8, '1');
    std::cout << "array of size 8 with '1': ";
    sizedArray.print();

    // === ДЕМОНСТРАЦИЯ БИТОВЫХ ОПЕРАЦИЙ ===
    
    std::cout << "\nBit operations (for first array)" << std::endl;
    
    BitString andResult = firstArray.bitAnd(secondArray);
    std::cout << "AND: ";
    andResult.print();

    BitString orResult = firstArray.bitOr(secondArray);
    std::cout << "OR: ";
    orResult.print();

    BitString xorResult = firstArray.bitXor(secondArray);
    std::cout << "XOR: ";
    xorResult.print();

    BitString notResult = firstArray.bitNot();
    std::cout << "NOT:";
    notResult.print();

    // === ДЕМОНСТРАЦИЯ КОПИРУЮЩЕГО КОНСТРУКТОРА ===
    
    std::cout << "\n Copy constructor " << std::endl;
    
    BitString copiedArray(firstArray);
    std::cout << "Copied array: ";
    copiedArray.print();

    // === ДЕМОНСТРАЦИЯ ПЕРЕМЕЩАЮЩЕГО КОНСТРУКТОРА ===
    
    std::cout << "\n Move constructor " << std::endl;
    
    BitString movedArray(std::move(andResult));
    std::cout << "Moved array: ";
    movedArray.print();

    // === ДЕМОНСТРАЦИЯ ПРЕОБРАЗОВАНИЯ В СТРОКУ ===
    
    std::cout << "\n String conversion " << std::endl;
    
    std::string strResult = firstArray.toString();
    std::cout << " First bit string as std::string: " << strResult << std::endl;

    // === ДЕМОНСТРАЦИЯ ОБРАБОТКИ ИСКЛЮЧЕНИЙ ===
    
    std::cout << "\nException handling" << std::endl;

    try {
        // Попытка создания с недопустимыми символами
        BitString invalidArray{'1', '2', '0'}; // '2' - недопустимый символ
        std::cout << "This code won't execute" << std::endl;
    } 
    catch (const std::invalid_argument& exception) {
        std::cerr << "Caught exception: " << exception.what() << std::endl;
    }

    try {
        // Попытка создания из пустой строки
        BitString emptyString("");
        std::cout << "This code won't execute" << std::endl;
    } 
    catch (const std::invalid_argument& exception) {
        std::cerr << "Caught exception: " << exception.what() << std::endl;
    }

    try {
        // Попытка создания из строки с недопустимыми символами
        BitString invalidString("10102"); // '2' - недопустимый символ
        std::cout << "This code won't execute" << std::endl;
    } 
    catch (const std::invalid_argument& exception) {
        std::cerr << "Caught exception: " << exception.what() << std::endl;
    }

    // === ДЕМОНСТРАЦИЯ РАБОТЫ С РАЗНЫМИ РАЗМЕРАМИ ===
    
    std::cout << "\n Operations with different sizes " << std::endl;
    
    BitString shortArray{'1', '0'};
    BitString longArray{'1', '1', '1', '0', '0'};
    
    std::cout << "Short: ";
    shortArray.print();
    std::cout << "Long : ";
    longArray.print();
    
    BitString sizedAnd = shortArray.bitAnd(longArray);
    std::cout << "AND with different sizes: ";
    sizedAnd.print();

    BitString sizedOr = shortArray.bitOr(longArray);
    std::cout << "OR with different sizes: ";
    sizedOr.print();

    std::cout << "\nExiting main() - destructors call" << std::endl;
    
    // Деструкторы вызываются в обратном порядке создания
    
    std::cout << "\n END " << std::endl;
    return 0;
}