
#ifndef Tablica_hpp
#define Tablica_hpp

#include <iostream>
#include <fstream>
using namespace std;
// Klasa Tablicy
class Array{

private:
    // dynamiczna tablica
    int *arr;
    // ilość elementów zapasowych w tablicy
    int over_size = 4;
    // rozmiar tablicy
    int size;
    
    // Metoda dodaje elementy zapasowe do tablicy i realokuje ją
    void resize(){
        over_size += over_size;
        int *temp = new int[over_size];
        copy(temp);
        delete [] arr;
        arr = temp;
    }
    // metoda realokuje zmniejszając tablice
    void resize_down(){
        int *temp = new int[size + over_size];
        copy(temp);
        delete [] arr;
        arr = temp;
    }
    //metoda kopijuje elementy tablicy do podanej tablicy
    void copy(int temp[]){
        for(int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
    }
    
public:
    Array();
    // metoda dodaje lement na 1 pozycje
    void push_front(int val);
    // metoda dodaje lement na ostatnią pozycje
    void push_back(int val);
    // metoda dodaje lement na podaną pozycje
    void push_at_index(int val, int index);
    // metoda usuwa element z 1 pozycji
    void delete_first_elem();
    //metoda usuwa element z ostatniej pozycji
    void delete_last_elem();
    // metoda usuwa podany elemnt
    void delete_elem(int x);
    // metoda sprawdza czy podany elemnt jest w tablicy
    bool is_in_array(int x);
    //metoda wypisuje tablicę
    void print_array();
    // metoda usuwa tablicę
    void delete_array();
    //metoda stwarza tablicę z pliku tekstowego
    void create_from_file();
    
};







#endif /* Tablica_hpp */
