#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray {
private:
    int maxSize;        
    int currentIndex;   
    int* array;         
    static int count;   

public:
    
    DynamicArray();                             
    DynamicArray(int size);                     
    DynamicArray(const DynamicArray& other);    
    
    
    ~DynamicArray();
    
    
    bool addElement(int value);                 
    int findElement(int value) const;           
    bool replaceElement(int index, int value);  
    bool removeElement(int index);              
    void display() const;                       
    int getSize() const;                        
    int getMaxSize() const;                     
    
    
    static int getObjectCount();                
};

#endif
