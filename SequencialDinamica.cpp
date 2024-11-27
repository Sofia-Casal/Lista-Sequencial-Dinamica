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
        if (newCapacity < 50) newCapacity = 50;
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
        if (data == NULL) 
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

    void testAddElements(int count) 
    {
        std::cout << "Adicionando " << count << " elementos:\n";
        for (int i = 0; i < count; i++) 
        {
            addElement(i + 1);
        }
        printList();
    }

    void testRemoveElements(int count) 
    {
        std::cout << "Removendo " << count << " elementos:\n";
        for (int i = 0; i < count; i++) 
        {
            removeElement();
        }
        printList();
    }
};

int main() 
{
    DynamicList list;

    list.testAddElements(100);

    list.testRemoveElements(80);

    list.testAddElements(30);

list.testRemoveElements(list.getSize());

    return 0;
}
