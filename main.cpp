
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
#include "Lista.hpp"
#include "BST.hpp"
#include "AVL.hpp"
#include "Kopiec.hpp"
#include "Tablica.hpp"
#include "Menu.hpp"
#include "TestTime.hpp"





int main() {

    
    BinaryTree *b = new BinaryTree();
    AVL_Tree *avl = new AVL_Tree();
    Array *arr = new Array();
    List *lista = new List();
    Heap *heap = new Heap();
    
    srand((unsigned int)time(NULL));
    
    

    
    //time_test_bst(b);
    //time_test_val(avl);
    //time_test_heap(heap);
    //time_test_arrey(arr);
    //time_test_list(lista);

        
    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica" << endl;
        cout << "2.Lista" << endl;
        cout << "3.Kopiec" << endl;
        cout << "4.BST drzewo" << endl;
        cout << "5.AVL drzewo" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;
    
        switch (option){
            case '1':
                tablica_menu(arr);
                break;

            case '2':
                list_menu(lista);
                break;

            case '3':
                heap_menu(heap);
                break;
            case '4':
                bst_tree_menu(b);
                break;
            case '5':
                avl_tree_menu(avl);
                break;
        }

    } while (option != '0');



    
    return 0;
}
