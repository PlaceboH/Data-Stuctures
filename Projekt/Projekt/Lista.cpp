#include "Lista.hpp"


List::List(){
    head = nullptr;
    size = 0;
}


List::~List(){
    
    if( !(head) ){
        delete head;
    }
    else if(head->next == NULL){
        Node_S *temp = head;
        head = head->next;
        delete temp;
    }
    else{
        while(head){
            Node_S *temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }
}


void List::delete_all_elem(){
    Node_S *t = head;
    while (t != nullptr) {
        delete_first_elem();
        t = t->next;
    }
    size = 0;
};

void List::push_front(int val){
    
    Node_S* newNode = init(val);
    if(head == nullptr){
        head = newNode;
        size++;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    size++;
}

void List::push_back(int val){
    Node_S* newNode = init(val);
    if(head == nullptr){
        head = newNode;
        size++;
        return;
    }
    Node_S *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    
    temp->next = newNode;
    newNode->prev = temp;
    size++;
}

void List::insert_at(int val, const int newVal){
    Node_S *element;
    Node_S * newElement = new Node_S();
    if (!(is_in_list(val)))
    {
        push_front(newVal);
    }
    else
    {
        
        element = head;
        for (int i = 0; i < size; i++)
        {
            if (element->val == val)
            {
                newElement->next = element->next;
                newElement->prev = element;
                element->next = newElement;
                if (newElement->next){
                    newElement->next->prev = newElement;
                }
                else {
                    push_back(val);
                    return;
                }
                newElement->val = newVal;
                size++;
                break;
            }
            else element = element->next;
        }

    }
}


void List::delete_first_elem(){
    
    if(head == nullptr){
        return;
    }
    if(head->next == nullptr){
        head = nullptr;
        size--;
        return;
    }
    
    Node_S *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    size--;
}


void List::delete_last_elem(){
    
    if(head == nullptr){
        return;
    }
    
    Node_S *tempNext = head;
    tempNext = tempNext->next;
    
    Node_S *tempBack = head;
    if(tempNext == NULL){
        head = NULL;
        size--;
        delete tempBack;
    }
    else {
        while(tempNext->next!= NULL){
            tempBack = tempBack->next;
            tempNext = tempNext->next;
        }
        tempBack->next = NULL;
        size--;
        delete tempNext;
    }
}



void List::delete_elem(const int elem){
    if(!(head)){
        cout << "lista pusta " << endl;
        return;
    }
    Node_S *begin = head;
    
    if(begin->val == elem) {
        delete_first_elem();
        return;
        
    }
    
    while(begin){
        if( begin->val == elem ){
            
            if(begin->next == nullptr){
                delete_last_elem();
                return;
            }
            Node_S *cuicideVar = begin;
            
            Node_S *tempPrev = begin->prev;
            Node_S *tempNext = begin->next;

            tempNext->prev = tempPrev;
            tempPrev->next = tempNext;
            
            begin = tempNext;
            size--;
            delete cuicideVar;
        }
        else begin = begin->next;
    }
 
}

void List::print_revers(){
    if(!head){
        cout << "lista pusta " << endl;
        return;
    }
    
    Node_S *end = head;
    while (end->next != nullptr) {
        end = end->next;
    }
    
    while(end != nullptr){
        cout << end->val << " ";
        end = end->prev;
    }
}

bool List::is_in_list(int val){
    Node_S *temp = head;
    while (temp != nullptr) {
        if(temp->val == val){
            return true;
        }
        else{
            temp = temp->next;
        }
    }
    return false;
}

void List::create_from_file(){
    
    delete_all_elem();
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
    else
    {
        cout << "Błednie podany path do pliku !" << endl;
    }
}


ostream& operator <<(ostream& os, const List& l){
    
    os << "\n\t\t=======Lista=======\n\n";
    
    if(l.head == nullptr){
        os << "lista jest pusta\n";
        return os;
    }
    
    List::Node_S *temp = l.head;
    
    while (temp != nullptr) {
        os << temp->val << "  ";
        temp = temp->next;
    }
    return os;
}
