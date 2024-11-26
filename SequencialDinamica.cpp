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
        validateList();
        if (size == capacity) 
        {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void removeElement() 
    {
        if (size > 0)
        {
            size--;
            if (size > 0 && size <= capacity / 4) 
            {
                resize(capacity / 2);
            }
        } 
        else
        {
            std::cerr << "Erro: a lista está vazia!\n";
        }
    }

void validateList() const 
    {
        if (data == nullptr) 
        {
            std::cerr << "Erro: ponteiro de dados é nulo.\n";
            exit(1);
        }
        if (capacity < size) 
        {
            std::cerr << "Erro: capacidade é menor que o número de elementos.\n";
            exit(1);
        }
    }

    void printList() const 
    {
        validateList();
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
    
    for (int i = 0; i < 10; i++) 
    {
        list.removeElement();
    }
    list.printList();

    for (int i = 0; i < 50; i++) 
    {
        list.removeElement();
    }
    list.printList();

    list.validateList();

    return 0;
}

