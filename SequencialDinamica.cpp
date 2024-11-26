#include <iostream>
#include <cstdlib> 

class DynamicList 
{
private:
    int *data;
    int size;
    int capacity;

    void resize(int newCapacity) 
    {
        data = (int *)realloc(data, newCapacity * sizeof(int));
        capacity = newCapacity;
    }

public:
    DynamicList() 
    {
        capacity = 50;
        size = 0;
        data = (int *)malloc(capacity * sizeof(int));
    }

    ~DynamicList() 
    {
        free(data);
    }

    void addElement(int value) 
    {
        if (size == capacity) 
        {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void printList() const 
    {
        std::cout << "Lista: ";
        for (int i = 0; i < size; i++) 
        {
            std::cout << data[i] << " ";
        }
        std::cout << "\nCapacidade: " << capacity << "\n";
    }
};

int main() 
{
    DynamicList list;

    for (int i = 0; i < 60; i++) 
    {
        list.addElement(i + 1);
    }

    list.printList();

    return 0;
}

