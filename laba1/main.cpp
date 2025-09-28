#include "DynamicArray.h"
#include <iostream>

void demonstrateArrayOperations() {
    std::cout << "=== ДЕМОНСТРАЦИЯ РАБОТЫ КЛАССА DYNAMICARRAY ===" << std::endl << std::endl;
    
 
    std::cout << "1. СОЗДАНИЕ ОБЪЕКТОВ:" << std::endl;
    DynamicArray arr1; 
    DynamicArray arr2(5); 
    
   
    std::cout << std::endl << "2. ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ:" << std::endl;
    arr1.addElement(10);
    arr1.addElement(20);
    arr1.addElement(30);
    arr1.display();
    
    arr2.addElement(100);
    arr2.addElement(200);
    arr2.addElement(300);
    arr2.addElement(400);
    arr2.addElement(500);
    arr2.display();
    
    
    std::cout << std::endl << "3. КОНСТРУКТОР КОПИРОВАНИЯ:" << std::endl;
    DynamicArray arr3 = arr1;
    std::cout << "Скопированный массив: ";
    arr3.display();
    
    
    std::cout << std::endl << "4. ПОИСК ЭЛЕМЕНТОВ:" << std::endl;
    int searchValue = 20;
    int foundIndex = arr1.findElement(searchValue);
    if (foundIndex != -1) {
        std::cout << "Элемент " << searchValue << " найден по индексу: " << foundIndex << std::endl;
    } else {
        std::cout << "Элемент " << searchValue << " не найден" << std::endl;
    }
    
    
    std::cout << std::endl << "5. ЗАМЕНА ЭЛЕМЕНТОВ:" << std::endl;
    std::cout << "До замены: ";
    arr1.display();
    arr1.replaceElement(1, 999);
    std::cout << "После замены элемента с индексом 1 на 999: ";
    arr1.display();
    
    
    std::cout << std::endl << "6. УДАЛЕНИЕ ЭЛЕМЕНТОВ:" << std::endl;
    std::cout << "До удаления: ";
    arr2.display();
    arr2.removeElement(2);
    std::cout << "После удаления элемента с индексом 2: ";
    arr2.display();
    
    
    std::cout << std::endl << "7. ПРОВЕРКА ПЕРЕПОЛНЕНИЯ:" << std::endl;
    DynamicArray smallArr(3);
    smallArr.addElement(1);
    smallArr.addElement(2);
    smallArr.addElement(3);
    std::cout << "Попытка добавить 4-й элемент в массив размером 3: ";
    if (!smallArr.addElement(4)) {
        std::cout << "Переполнение обработано корректно!" << std::endl;
    }
    smallArr.display();
    
   
    std::cout << std::endl << "8. СТАТИЧЕСКИЙ СЧЕТЧИК ОБЪЕКТОВ:" << std::endl;
    std::cout << "Текущее количество объектов: " << DynamicArray::getObjectCount() << std::endl;
    
    std::cout << std::endl << "=== ЗАВЕРШЕНИЕ ДЕМОНСТРАЦИИ ===" << std::endl;
}

int main() {
    demonstrateArrayOperations();
    
   
    std::cout << std::endl << "Проверка деструкторов при выходе из области видимости..." << std::endl;
    {
        DynamicArray tempArr(2);
        tempArr.addElement(42);
        tempArr.addElement(24);
        std::cout << "Временный массив создан внутри блока" << std::endl;
    } 
    std::cout << "Выход из блока завершен" << std::endl;
    
    std::cout << std::endl << "Финальное количество объектов: " << DynamicArray::getObjectCount() << std::endl;
    
    return 0;
}
