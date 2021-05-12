
#ifndef Lista_hpp
#define Lista_hpp

#include <iostream>
#include <fstream>

using namespace std;

// Klasa Listy
class List{

private:
    
    // struktura opisująca pojedynczy elemnt listy
    typedef struct node{
        int val;
        struct node* next;
        struct node* prev;
    } Node_S;
    
    // wskażnik na początek listy
    Node_S* head;
    // rozmiar listy
    int size;
    
    // inicjalizacja elementu listy
    Node_S* init(int val){
            Node_S *head = nullptr;
            head = new Node_S;
            head->val = val;
            head->prev = nullptr;
            head->next = nullptr;
            return head;
        }
        
public:
    // konstruktor
    List();
    // destruktor
    ~List();
    
    // metoda usuwa wszystkie elementy z listy
    void delete_all_elem();
    // metoda dodaje alemant na początek
    void push_front(int val);
    // metoda dodaje alemant na koniec
    void push_back(int val);
    // metoda dodaje alemant w podanym miejscu
    void insert_at(int val, const int position);
    // metoda usuwa pierwszy element z listy
    void delete_first_elem();
    // metoda usuwa ostatni element z listy
    void delete_last_elem();
    // metoda usuwa dany element z listy
    void delete_elem(const int elem);
    // metoda wypisuje elementy w odwrotnej kolejności
    void print_revers();
    //metoda sprawdzo czy podany element jest w liscie
    bool is_in_list(int val);
    // metoda tworzy listę z pliku
    void create_from_file();
    // metoda umożwliwia wypisywanie listę za pomocą cout
    friend ostream& operator <<(ostream& os, const List& l);
};



#endif /* Lista_hpp */
