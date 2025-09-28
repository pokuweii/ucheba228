#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>


int DynamicArray::count = 0;


DynamicArray::DynamicArray() : maxSize(10), currentIndex(0) {
    array = new int[maxSize];
    count++;
    std::cout << "Вызван конструктор по умолчанию. Создан массив размером " << maxSize << std::endl;
}


DynamicArray::DynamicArray(int size) : maxSize(size > 0 ? size : 10), currentIndex(0) {
    array = new int[maxSize];
    count++;
    std::cout << "Вызван конструктор с параметром. Создан массив размером " << maxSize << std::endl;
}


DynamicArray::DynamicArray(const DynamicArray& other) 
    : maxSize(other.maxSize), currentIndex(other.currentIndex) {
    array = new int[maxSize];
    for (int i = 0; i < currentIndex; i++) {
        array[i] = other.array[i];
    }
    count++;
    std::cout << "Вызван конструктор копирования. Скопирован массив размером " << maxSize << std::endl;
}


DynamicArray::~DynamicArray() {
    delete[] array;
    count--;
    std::cout << "Вызван деструктор. Удален массив. Осталось объектов: " << count << std::endl;
}


bool DynamicArray::addElement(int value) {
    if (currentIndex >= maxSize) {
        std::cout << "Ошибка: Массив переполнен!" << std::endl;
        return false;
    }
    array[currentIndex] = value;
    currentIndex++;
    return true;
}


int DynamicArray::findElement(int value) const {
    for (int i = 0; i < currentIndex; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}


bool DynamicArray::replaceElement(int index, int value) {
    if (index < 0 || index >= currentIndex) {
        std::cout << "Ошибка: Неверный индекс!" << std::endl;
        return false;
    }
    array[index] = value;
    return true;
}


bool DynamicArray::removeElement(int index) {
    if (index < 0 || index >= currentIndex) {
        std::cout << "Ошибка: Неверный индекс!" << std::endl;
        return false;
    }
    
    for (int i = index; i < currentIndex - 1; i++) {
        array[i] = array[i + 1];
    }
    currentIndex--;
    return true;
}


void DynamicArray::display() const {
    std::cout << "Массив [" << currentIndex << "/" << maxSize << "]: ";
    if (currentIndex == 0) {
        std::cout << "пустой";
    } else {
        for (int i = 0; i < currentIndex; i++) {
            std::cout << array[i];
            if (i < currentIndex - 1) std::cout << ", ";
        }
    }
    std::cout << std::endl;
}


int DynamicArray::getSize() const {
    return currentIndex;
}


int DynamicArray::getMaxSize() const {
    return maxSize;
}


int DynamicArray::getObjectCount() {
    return count;
}
