

#ifndef TestTime_hpp
#define TestTime_hpp

#include <iostream>
#include <chrono>

// funkcja mierzenia czasów wykonania metod dla drzewa BST
void time_test_bst(BinaryTree* b){
    cout << "============TIME TEST DLA BST DRZEWA===========\n\n";

    int x = 1000;
    int diferent_nums = 7;
    int repet = 10;
    for(int a = 0; a < diferent_nums; a++){
        double time_sum_insert=0;
        double time_sum_delete=0;
        double time_sum_find=0;

        cout << "Dla ilości elementów: " << x << endl;
        for(int i = 0; i < repet; i++){
            
            // mirzenie czasu dodania elementów do BST o liczbie elementów (x + 500*i)
            b->delete_all_elems();
            for(int j = 0; j < x; j++){
                b->add_value(rand()%(x));
            }
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                b->add_value(rand()%(x));
            }
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_insert += time_span.count();
            cout << "Czas wykonania dodania 100 elementów to: " << time_span.count() << " sekund." << endl;
            
            // mirzenie czasu usuniecia elementów z BST o liczbie elementów (x + 500*i)
            b->delete_all_elems();
            for(int j = 0; j < x; j++){
                b->add_value(rand()%(x));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                b->remove(rand()%(x));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_delete += time_span.count();
            cout << "Czas wykonania usuniecia 100 elementów to: " << time_span.count() << " sekund." << endl;
            
            // mirzenie czasu wyszukiwania elementu w BST o liczbie elementów (x + 500*i)
            b->delete_all_elems();
            for(int j = 0; j < x; j++){
                b->add_value(rand()%(x));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                b->is_in_bst(rand()%(x));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_find += time_span.count();
            cout << "Czas wykonania wyszukiwania 100 elementów to: " << time_span.count() << " sekund." << endl;
            
        }
        cout << "\nSr. arytm. czasu wykonania DODANIA 100 elementów: " << time_sum_insert*1000000/(double)repet << endl;
        cout << "Sr. arytme. czasu wykonania USUNIECIA 100 elementów: " << time_sum_delete*1000000/(double)repet << endl;
        cout << "Sr. arytme. czasu wykonania WYSZUkiwania 100 elementów: " << time_sum_find*1000000/(double)repet << endl;
        b->delete_all_elems();
        cout << "\n\n";
        x += 1000;
    }
    
}
// funkcja mierzenia czasów wykonania metod dla drzewa AVL
void time_test_val(AVL_Tree* avl){
    cout << "============TIME TEST DLA AVL DRZEWA===========\n\n";
    
    int x = 1000;
    int diferent_nums = 7;
    int repet = 10;
    for(int a = 0; a < diferent_nums; a++){
        double time_sum_insert=0;
        double time_sum_delete=0;
        double time_sum_find=0;

        cout << "Dla ilości elementów: " << x << endl;
        for(int i = 0; i < repet; i++){
            
            // mirzenie czasu dodania elementów do AVL o liczbie elementów (x + 500*i)
            avl->delete_all_elems();
            for(int j = 0; j < x; j++){
                avl->insert(rand()%(x));
            }
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                avl->insert(rand()%(x));
            }
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_insert += time_span.count();
            cout << "Czas wykonania dodania 100 elementów to: " << time_span.count() << " sekund." << endl;
            
            // mirzenie czasu usuniecia elementów z AVL o liczbie elementów (x + 500*i)
            avl->delete_all_elems();
            for(int j = 0; j < x; j++){
                avl->insert(rand()%(x));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                avl->delete_elem(rand()%(x));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_delete += time_span.count();
            cout << "Czas wykonania usuniecia 100 elementów to: " << time_span.count() << " sekund." << endl;
            
            // mirzenie czasu wyszukiwania elementu w AVL o liczbie elementów (x + 500*i)
            avl->delete_all_elems();
            for(int j = 0; j < x; j++){
                avl->insert(rand()%(x));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                avl->is_in_avl(rand()%(x));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_find += time_span.count();
            cout << "Czas wykonania wyszukiwania 100 elementów to: " << time_span.count() << " sekund." << endl;
            
            
        }
        cout << "\nSr. arytm. czasu wykonania DODANIA 100 elementów: " << time_sum_insert*1000000/(double)repet << endl;
        cout << "Sr. arytme. czasu wykonania USUNIECIA 100 elementów: " << time_sum_delete*1000000/(double)repet << endl;
        cout << "Sr. arytme. czasu wykonania WYSZUkiwania 100 elementów: " << time_sum_find*1000000/(double)repet << endl;
        avl->delete_all_elems();
        cout << "\n\n";
        x += 1000;
    }
    
}

// funkcja mierzenia czasów wykonania metod dla kopca
void time_test_heap(Heap* heap){
    cout << "============TIME TEST DLA KOPCA===========\n\n";
    
    int x = 1000;
    int diferent_nums = 7;
    int repet = 10;
    for(int a = 0; a < diferent_nums; a++){
        double time_sum_insert=0;
        double time_sum_delete=0;
        double time_sum_find=0;

        cout << "Dla ilości elementów: " << x << endl;
        for(int i = 0; i < repet; i++){
            
            // mirzenie czasu dodania elementów do kopca o liczbie elementów (x + 500*i)
            heap->delete_heap();
            for(int j = 0; j < x; j++){
                heap->insert_elem(rand()%(x));
            }
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                heap->insert_elem(rand()%(x));
            }
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_insert += time_span.count();
            cout << "Czas wykonania dodania 100 elementów to: " << time_span.count() << " sekund." << endl;
            
            // mirzenie czasu usuniecia elementów z kopca o liczbie elementów (x + 500*i)
            heap->delete_heap();
            for(int j = 0; j < x; j++){
                heap->insert_elem(rand()%(x));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                heap->delete_elem(rand()%(x));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_delete += time_span.count();
            cout << "Czas wykonania usuniecia 100 elementów to: " << time_span.count() << " sekund." << endl;
            
            // mirzenie czasu wyszukiwania elementu kopcu o liczbie elementów (x + 500*i)
            heap->delete_heap();
            for(int j = 0; j < x; j++){
                heap->insert_elem(rand()%(x));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                heap->is_in_heap(rand()%(x));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_find += time_span.count();
            cout << "Czas wykonania wyszukiwania 100 elementów to: " << time_span.count() << " sekund." << endl;
            
        }
        cout << "\nSr. arytm. czasu wykonania DODANIA 100 elementów: " << time_sum_insert*1000000/(double)repet << endl;
        cout << "Sr. arytme. czasu wykonania USUNIECIA 100 elementów: " << time_sum_delete*1000000/(double)repet << endl;
        cout << "Sr. arytme. czasu wykonania WYSZUkiwania 100 elementów: " << time_sum_find*1000000/(double)repet << endl;
        heap->delete_heap();
        cout << "\n\n";
        x += 1000;
    }
    
}

// funkcja mierzenia czasów wykonania metod dla tablicy
void time_test_arrey(Array* arr){
    cout << "============TIME TEST DLA TABLICY===========\n\n";
    
    int x = 1000;
    int diferent_nums = 7;
    int repet = 10;
    for(int a = 0; a < diferent_nums; a++){
        double time_sum_insert_back=0;
        double time_sum_insert_front=0;
        double time_sum_insert_at=0;
        double time_sum_delete_back=0;
        double time_sum_delete_front=0;
        double time_sum_delete_at=0;
        double time_sum_find=0;

        cout << "Dla ilości elementów: " << x << endl;
        for(int i = 0; i < repet; i++){
            
            // mirzenie czasu dodania elementów do tablicy o liczbie elementów (x + 500*i)
            //1. Dodanie na koniec
            arr->delete_array();
            for(int j = 0; j < x; j++){
                arr->push_back(rand()%(100));
            }
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                arr->push_back(rand()%(100));
            }
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_insert_back += time_span.count();
            cout << "Czas wykonania dodania na koniec 100 elementów to: " << time_span.count() << " sekund." << endl;
            //2. Dodanie na początek
            arr->delete_array();
            for(int j = 0; j < x; j++){
                arr->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                arr->push_front(rand()%(100));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_insert_front += time_span.count();
            cout << "Czas wykonania dodania 100 elementów na poczatek to: " << time_span.count() << " sekund." << endl;
            //3. Dodanie pod Index
            arr->delete_array();
            for(int j = 0; j < x; j++){
                arr->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                arr->push_at_index(rand()%(x), rand()%x);
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_insert_at += time_span.count();
            cout << "Czas wykonania dodania 100 elementów pod index to: " << time_span.count() << " sekund." << endl;
            
            // mirzenie czasu usuniecia elementów z tablicy o liczbie elementów (x + 500*i)
            //1. usuniecie z początku tabblicy
            arr->delete_array();
            for(int j = 0; j < x; j++){
                arr->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                arr->delete_first_elem();
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_delete_front += time_span.count();
            cout << "Czas wykonania usuniecia 100 elementów z poczatku to: " << time_span.count() << " sekund." << endl;
            
            //1. usuniecie z końca tabblicy
            arr->delete_array();
            for(int j = 0; j < x; j++){
                arr->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                arr->delete_last_elem();
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_delete_back += time_span.count();
            cout << "Czas wykonania usuniecia 100 elementów z konca to: " << time_span.count() << " sekund." << endl;
            
            //3. usuniecie według znaczenia
            arr->delete_array();
            for(int j = 0; j < x; j++){
                arr->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                arr->delete_elem(rand()%(100));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_delete_at += time_span.count();
            cout << "Czas wykonania usuniecia 100 elementów po indeksem to: " << time_span.count() << " sekund." << endl;
            
            // mirzenie czasu wyszukiwania elementu tablicy o liczbie elementów (x + 500*i)
            arr->delete_array();
            for(int j = 0; j < x; j++){
                arr->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                arr->is_in_array(rand()%(x));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_find += time_span.count();
            cout << "Czas wykonania wyszukiwania 100 elementów to: " << time_span.count() << " sekund." << endl;
            
            
        }
        cout << "\nSr. arytm. czasu wykonania DODANIA 100 elementów na koniec : " << (time_sum_insert_back*1000000/(double)repet) << endl;
        cout << "Sr. arytm. czasu wykonania DODANIA 100 elementów na poczatek: " << time_sum_insert_front*1000000/(double)repet << endl;
        cout << "Sr. arytm. czasu wykonania DODANIA 100 elementów pod index: " << time_sum_insert_at*1000000/(double)repet << endl;
        cout << "Sr. arytme. czasu wykonania USUNIECIA 100 elementów z konca: " << time_sum_delete_back*1000000/(double)repet << endl;
        cout << "Sr. arytme. czasu wykonania USUNIECIA 100 elementów z poczatku: " << time_sum_delete_front*1000000/(double)repet << endl;
        cout << "Sr. arytme. czasu wykonania USUNIECIA 100 elementów z indeksu: " << time_sum_delete_at*1000000/(double)repet << endl;
        cout << "Sr. arytme. czasu wykonania WYSZUkiwania 100 elementów: " << time_sum_find*1000000/(double)repet << endl;
        arr->delete_array();
        cout << "\n\n";
        x += 1000;
    }
    
}

// funkcja mierzenia czasów wykonania metod dla listy
void time_test_list(List* list){
    cout << "============TIME TEST DLA LISTY===========\n\n";
    
    int x = 1000;
    int diferent_nums = 7;
    int repet = 20;
    for(int a = 0; a < diferent_nums; a++){
        double time_sum_insert_back=0;
        double time_sum_insert_front=0;
        double time_sum_insert_at=0;
        double time_sum_delete_back=0;
        double time_sum_delete_front=0;
        double time_sum_delete_at=0;
        double time_sum_find=0;

        cout << "Dla ilości elementów: " << x << endl;
        for(int i = 0; i < repet; i++){
            
            // mirzenie czasu dodania elementów do listy o liczbie elementów (x + 500*i)
            //1. Dodanie na koniec
            list->delete_all_elem();
            for(int j = 0; j < x; j++){
                list->push_back(rand()%(100));
            }
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                list->push_back(rand()%(100));
            }
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_insert_back += time_span.count();
            cout << "Czas wykonania dodania na koniec 100 elementów to: " << time_span.count() << " sekund." << endl;
            //2. Dodanie na początek
            list->delete_all_elem();
            for(int j = 0; j < x; j++){
                list->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                list->push_front(rand()%(100));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_insert_front += time_span.count();
            cout << "Czas wykonania dodania 100 elementów na poczatek to: " << time_span.count() << " sekund." << endl;
            //3. Dodanie pod Index
            list->delete_all_elem();
            for(int j = 0; j < x; j++){
                list->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                list->insert_at(rand()%(x), rand()%x);
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_insert_at += time_span.count();
            cout << "Czas wykonania dodania 100 elementów po index to: " << time_span.count() << " sekund." << endl;

            // mirzenie czasu usuniecia elementów z tablicy o liczbie elementów (x + 500*i)
            //1. usuniecie z początku tabblicy
            list->delete_all_elem();
            for(int j = 0; j < x; j++){
                list->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                list->delete_first_elem();
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_delete_front += time_span.count();
            cout << "Czas wykonania usuniecia 100 elementów z poczatku to: " << time_span.count() << " sekund." << endl;
            
            //1. usuniecie z końca tabblicy
            list->delete_all_elem();
            for(int j = 0; j < x; j++){
                list->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                list->delete_last_elem();
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_delete_back += time_span.count();
            cout << "Czas wykonania usuniecia 100 elementów z konca to: " << time_span.count() << " sekund." << endl;
            
            //3. usuniecie według znaczenia
            list->delete_all_elem();
            for(int j = 0; j < x; j++){
                list->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                list->delete_elem(rand()%(100));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_delete_at += time_span.count();
            cout << "Czas wykonania usuniecia 100 elementów po indeksem to: " << time_span.count() << " sekund." << endl;
            
            // mirzenie czasu wyszukiwania elementu tablicy o liczbie elementów (x + 500*i)
            list->delete_all_elem();
            for(int j = 0; j < x; j++){
                list->push_back(rand()%(100));
            }
            t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                list->is_in_list(rand()%(x));
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            time_sum_find += time_span.count();
            cout << "Czas wykonania wyszukiwania 100 elementów to: " << time_span.count() << " sekund." << endl;
            
            
        }
        cout << "\nSr. arytm. czasu wykonania DODANIA 100 elementów na poczatek: " << time_sum_insert_front*1000000/(double)repet << endl;
        cout << "Sr. arytm. czasu wykonania DODANIA 100 elementów na koniec : " << time_sum_insert_back*1000000/(double)repet << endl;

        cout << "Sr. arytm. czasu wykonania DODANIA 100 elementów pod index: " << time_sum_insert_at*1000000/(double)repet << endl;
        cout << "Sr. arytm. czasu wykonania USUNIECIA 100 elementów z konca: " << time_sum_delete_back*1000000/(double)repet << endl;
        cout << "Sr. arytm. czasu wykonania USUNIECIA 100 elementów z poczatku: " << time_sum_delete_front*1000000/(double)repet << endl;
        cout << "Sr. arytm. czasu wykonania USUNIECIA 100 elementów z indeksu: " << time_sum_delete_at*1000000/(double)repet << endl;
        cout << "Sr. arytm. czasu wykonania WYSZUkiwania 100 elementów: " << time_sum_find*1000000/(double)repet << endl;
        list->delete_all_elem();
        cout << "\n\n";
        x += 1000;
    }
}

#endif /* TestTime_hpp */
