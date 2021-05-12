
#ifndef Kopiec_hpp
#define Kopiec_hpp

#include <iostream>
#include <fstream>
using namespace std;

void swap(int *x, int *y);

// A class for Min Heap
class Heap{
private:
    int* head; // pointer to array of elements in heap
    int size; // ilosć elementów w kopcu
    const int MAX_SIZE = 50000; // stała maksymalna ilość elementów kopca
    
public:
    // Constructor
    Heap();
  
    void delete_heap(){ size = 0; }
    
    void MinHeapify(int i);
  
    int get_parent(int i) { return (i-1)/2; }
  
    int get_left(int i) { return (2*i + 1); }
  
    int get_right(int i) { return (2*i + 2); }

    int getMin() { return head[0]; }
  
    void delete_elem(int val);
  
    void insert_elem(int k);
    
    bool is_in_heap(int x);
    
    void print_heap();
    
    void create_from_file();
};


#endif /* Kopiec_hpp */
