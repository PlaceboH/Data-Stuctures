
#include "Kopiec.hpp"


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Konstruktor kopca buduje tablicę o MAX_SIZE rozmiarze
Heap::Heap(){
    size = 0;
    head = new int[MAX_SIZE];
}
  
// wstawiamy nowy element o znaczeniu k
void Heap::insert_elem(int k){
    if (size == MAX_SIZE){
        cout << "\nPrzekroczona ilość elementów w kopcu \n";
        return;
    }

    // Najperw wstawiamy na końcu
    size++;
    int i = size - 1;
    head[i] = k;
    
  
    // redukujemy poprawnośc kopca jeżeli jest w tym potrzeba
    while (i != 0 && head[get_parent(i)] < head[i])
    {
       swap(&head[i], &head[get_parent(i)]);
       i = get_parent(i);
    }
}
  

void Heap::delete_elem( int val)
{
    int i;
    for(i = 0; i < size; i++){
        if(head[i] == val)
            break;
        if( i == size-1 && head[i] != val){
            return;
        }
    }
    size--;
    head[i] = head[size];
    int temp[size];
    for(int i = 0; i < size; i++){
        temp[i] = head[i];
    }
    int curent_size = size;
    delete_heap();
    for(int i = 0; i < curent_size; i++){
        insert_elem(temp[i]);
    }

}
  

bool Heap::is_in_heap(int x){
    for(int i = 0; i < size; i++){
        if(head[i] == x){
            return true;
        }
    }
    return false;
}

void Heap::print_heap(){
    for(int i = 0; i < size; i++){
        cout << " " << head[i];
    }
    cout << endl;
}


void Heap::create_from_file(){
    
    delete_heap();
    string filename = "";
    double tmp;
    cout << "podaj ścieżkę do pliku" <<endl;
    cin >> filename;

    ifstream file;
    file.open(filename.c_str());
    
    if(file.is_open()){
        int ile = 0;
        int i = 0;
        file >> ile;
        while(i < ile){
            file >> tmp;
            insert_elem(tmp);
            i++;
        }

        file.close();
    }
    else{
        cout << "Błednie podany path do pliku !" << endl;
    }
}
