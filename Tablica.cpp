
#include "Tablica.hpp"

Array::Array(){
    arr = new int[over_size];
    size = 0;
}

void Array::push_front(int val){
    if(size == over_size) {
        resize();
    }
    
    for(int i = size - 1; i > -1; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = val;
    size++;
}

void Array::push_back(int val){
    if(size == over_size) {
        resize();
    }
    arr[size] = val;
    size++;
}

void Array::push_at_index(int val, int index){
    
    if((index > size) || (index < 0)) {
        cout << "Invalid index";
        return;
    }

    if(size == over_size) {
        resize();
    }
    size++;
    for(int i = size - 1; i >= index; i--) {
        if(i == index) {
            arr[i] = val;
        } else {
            arr[i] = arr[i-1];
        }
    }
}


void Array::delete_first_elem(){
    if(size == 0){ return; }
    if(size == 1 ){
        size--;
        resize_down();
        return;
    }
    
    for(int i = 0; i <= size; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    resize_down();
}


void Array::delete_last_elem(){
    size--;
    resize_down();
}

void Array::delete_array(){
    while (size != 0) {
        size--;
        resize_down();
    }
}


void Array::delete_elem(int x){
    int index = -1;
    for(int i = 0; i < size; i++){
        if(x == arr[i]){
            index = i;
            break;
        }
    }
    if(index == -1 ){
        return;
    }

    for(int i = index; i <= size; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    resize_down();
}

void Array::print_array(){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


bool Array::is_in_array(int x){
    for(int i = 0; i < size; i++) {
        if(x == arr[i]){
            return true;
        }
    }
    return false;
}


void Array::create_from_file(){
    
    delete_array();
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
            push_back(tmp);
            i++;
        }

        file.close();
    }
    else{
        cout << "Błednie podany path do pliku !" << endl;
    }
}



