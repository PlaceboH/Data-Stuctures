

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include "TestTime.hpp"
using namespace std;

void list_menu(List* lista){
    
    cout << "Lista Menu" << endl;
    
    
    unsigned short menu = 1;
    cout << "1 -> zbuduj z pliku" << endl;
    cout << "2 -> usuń element" << endl;
    cout << "3 -> dodaj element" << endl;
    cout << "4 -> utwóż losowo" << endl;
    cout << "5 -> wyświetl" << endl;
    cout << "6 -> testuj" << endl;
    cout << "7 -> wyszukaj" << endl;
    cout << "0 -> koniec" << endl;

    while (menu != 0) {
        cout << "Wybierz od 1 - 6" << endl;
        cin >> menu;
        

        switch (menu) {
            case 1:
                lista->create_from_file();
                cout << *lista << endl;
                lista->print_revers();
                cout << endl;

                break;
            case 2:
                cout << " 1 -> usuń pierwszy element\n 2 -> usuń ostatni element\n 3-> podaj wartość" << endl;
                int f_where;
                cin >> f_where;
                if(f_where == 1) lista->delete_first_elem();
                else if(f_where == 2) lista->delete_last_elem();
                else if(f_where == 3){
                    int elem;
                    cin >> elem;
                    lista->delete_elem(elem);
                    cout << endl;

                }
                cout << *lista << endl;
                lista->print_revers();
                cout << endl;
                break;
            case 3:
                int val;
                cout << "wpisz liczbe: " << endl;
                cin >> val;
                cout << " 1 -> dodaj na początek\n 2 -> dodaj na koniec\n 3-> podaj index listy" << endl;
                int where;
                cin >> where;
                if(where == 1) lista->push_front(val);
                else if(where == 2) lista->push_back(val);
                else if(where == 3){
                    unsigned int index;
                    cin >> index;
                    lista->insert_at(val, index);
                }
                cout << *lista << endl;
                lista->print_revers();
                cout << endl;

                break;
            case 4:
                cout << "Podaj rozmiar listy " <<endl;
                unsigned int size;
                cin >> size;
                for(int i(0); i < size; i++)
                    lista->push_back(rand()%1000);
                
                cout << *lista << endl;
                lista->print_revers();
                cout << endl;

                break;
                
            case 5:
                cout << *lista << endl;
                lista->print_revers();
                cout << endl;

                break;
                
            case 6:
                time_test_list(lista);
                break;
            case 7:
                int x;
                cout << "wpisz liczbę którą szukano" << endl;
                cin >> x;
                cout << lista->is_in_list(x) << endl;
                break;
            default:
                break;
        }
        if(menu == 0) break;

    }
}


void tablica_menu(Array* arr){
    
    cout << "Tablica Menu" << endl;
    
    
    unsigned short menu = 1;
    cout << "1 -> zbuduj z pliku" << endl;
    cout << "2 -> usuń element" << endl;
    cout << "3 -> dodaj element" << endl;
    cout << "4 -> utwóż losowo" << endl;
    cout << "5 -> wyświetl" << endl;
    cout << "6 -> testuj" << endl;
    cout << "7 -> wyszukaj" << endl;
    cout << "0 -> koniec" << endl;

    while (menu != 0) {
        cout << "Wybierz od 1 - 6" << endl;
        cin >> menu;
        

        switch (menu) {
            case 1:
                arr->create_from_file();
                arr->print_array();
                cout << endl;
                break;
            case 2:
                cout << " 1 -> usuń pierwszy element\n 2 -> usuń ostatni element\n 3-> podaj wartość" << endl;
                int f_where;
                cin >> f_where;
                if(f_where == 1) arr->delete_first_elem();
                else if(f_where == 2) arr->delete_last_elem();
                else if(f_where == 3){
                    int elem;
                    cin >> elem;
                    arr->delete_elem(elem);
                    cout << endl;

                }
                arr->print_array();
                cout << endl;
                break;
            case 3:
                int val;
                cout << "wpisz liczbe: " << endl;
                cin >> val;
                cout << " 1 -> dodaj na początek\n 2 -> dodaj na koniec\n 3-> podaj index listy" << endl;
                int where;
                cin >> where;
                if(where == 1) arr->push_front(val);
                else if(where == 2) arr->push_back(val);
                else if(where == 3){
                    unsigned int index;
                    cin >> index;
                    arr->push_at_index(val, index);
                }
                arr->print_array();
                cout << endl;

                break;
            case 4:
                cout << "Podaj rozmiar listy " <<endl;
                unsigned int size;
                cin >> size;
                for(int i(0); i < size; i++)
                    arr->push_back(rand()%1000);
                
                arr->print_array();
                cout << endl;

                break;
                
            case 5:
                arr->print_array();
                cout << endl;

                break;
            case 6:
                time_test_arrey(arr);
                break;
            case 7:
                int x;
                cout << "wpisz liczbę którą szukano" << endl;
                cin >> x;
                cout << arr->is_in_array(x) << endl;
                break;
            default:
                break;
        }
        if(menu == 0) break;

    }
}

void bst_tree_menu(BinaryTree* bst){
    
    cout << "BST Menu" << endl;
    
    
    unsigned short menu = 1;
    cout << "1 -> zbuduj z pliku" << endl;
    cout << "2 -> usuń element" << endl;
    cout << "3 -> dodaj element" << endl;
    cout << "4 -> utwóż losowo" << endl;
    cout << "5 -> wyświetl" << endl;
    cout << "6 -> testuj" << endl;
    cout << "7 -> wyszukaj" << endl;
    cout << "8 -> DSW" << endl;
    cout << "0 -> koniec" << endl;

    while (menu != 0) {
        cout << "Wybierz od 1 - 5" << endl;
        cin >> menu;
        

        switch (menu) {
            case 1:
                bst->create_from_file();
                bst->print_bst();
                cout << endl;
                break;
            case 2:
                cout << "Podaj element do usunięcia" << endl;

                int elem;
                cin >> elem;
                bst->remove(elem);
                bst->print_bst();
                cout << endl;
                break;
            case 3:
                int val;
                cout << "wpisz liczbe: " << endl;
                cin >> val;
                bst->add_value(val);
                bst->print_bst();
                cout << endl;
                break;
            case 4:
                cout << "Podaj ilość elementów do wylosowania " <<endl;
                unsigned int size;
                cin >> size;
                for(int i(0); i < size; i++)
                    bst->add_value(rand()%1000);
                bst->print_bst();
                cout << endl;
                break;
                
            case 5:
                bst->print_bst();
                cout << endl;

                break;
            case 6:
                time_test_bst(bst);
                break;
            case 7:
                int x;
                cout << "wpisz liczbę którą szukano" << endl;
                cin >> x;
                cout << bst->is_in_bst(x) << endl;
                break;
            case 8:
                bst->makeBSW();
                bst->print_bst();
                break;
            default:
                break;
        }
        if(menu == 0) break;

    }
}

void avl_tree_menu(AVL_Tree* avl){
    
    cout << "AVL Menu" << endl;
    
    
    unsigned short menu = 1;
    cout << "1 -> zbuduj z pliku" << endl;
    cout << "2 -> usuń element" << endl;
    cout << "3 -> dodaj element" << endl;
    cout << "4 -> utwóż losowo" << endl;
    cout << "5 -> wyświetl" << endl;
    cout << "6 -> testuj" << endl;
    cout << "7 -> wyszukaj" << endl;
    cout << "0 -> koniec" << endl;

    while (menu != 0) {
        cout << "Wybierz od 1 - 6" << endl;
        cin >> menu;
        

        switch (menu) {
            case 1:
                avl->create_from_file();
                avl->print_avl();
                cout << endl;
                break;
            case 2:
                cout << "Podaj element do usunięcia" << endl;

                int elem;
                cin >> elem;
                avl->delete_elem(elem);
                avl->print_avl();
                cout << endl;
                break;
            case 3:
                int val;
                cout << "wpisz liczbe: " << endl;
                cin >> val;
                avl->insert(val);
                avl->print_avl();
                cout << endl;
                break;
            case 4:
                cout << "Podaj ilość elementów do wylosowania " <<endl;
                unsigned int size;
                cin >> size;
                for(int i(0); i < size; i++)
                    avl->insert(rand()%1000);
                avl->print_avl();
                cout << endl;
                break;
                
            case 5:
                avl->print_avl();
                cout << endl;

                break;
            case 6:
                time_test_val(avl);
                break;
                
            case 7:
                int x;
                cout << "wpisz liczbę którą szukano" << endl;
                cin >> x;
                cout << avl->is_in_avl(x) << endl;
                break;
            default:
                break;
        }
        if(menu == 0) break;

    }
}


void heap_menu(Heap* heap){
    
    cout << "Heap Menu" << endl;
    
    
    unsigned short menu = 1;
    cout << "1 -> zbuduj z pliku" << endl;
    cout << "2 -> usuń element" << endl;
    cout << "3 -> dodaj element" << endl;
    cout << "4 -> utwóż losowo" << endl;
    cout << "5 -> wyświetl" << endl;
    cout << "6 -> testuj" << endl;
    cout << "7 -> wyszukaj" << endl;
    cout << "0 -> koniec" << endl;

    while (menu != 0) {
        cout << "Wybierz od 1 - 6" << endl;
        cin >> menu;
        

        switch (menu) {
            case 1:
                heap->create_from_file();
                heap->print_heap();
                cout << endl;
                break;
            case 2:
                cout << "Podaj element do usunięcia" << endl;

                int elem;
                cin >> elem;
                heap->delete_elem(elem);
                heap->print_heap();
                cout << endl;
                break;
            case 3:
                int val;
                cout << "wpisz liczbe: " << endl;
                cin >> val;
                heap->insert_elem(val);
                heap->print_heap();
                cout << endl;
                break;
            case 4:
                cout << "Podaj ilość elementów do wylosowania " <<endl;
                unsigned int size;
                cin >> size;
                for(int i(0); i < size; i++)
                    heap->insert_elem(rand()%1000);
                heap->print_heap();
                cout << endl;
                break;
                
            case 5:
                heap->print_heap();
                cout << endl;

                break;
            case 6:
                time_test_heap(heap);
                break;
            case 7:
                int x;
                cout << "wpisz liczbę którą szukano" << endl;
                cin >> x;
                cout << heap->is_in_heap(x) << endl;
                
                break;
            default:
                break;
        }
        if(menu == 0) break;

    }
}



#endif /* Menu_hpp */
