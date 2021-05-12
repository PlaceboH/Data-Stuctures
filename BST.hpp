#ifndef BST_hpp
#define BST_hpp

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

// Klasa drzewa BST
class BinaryTree{
    
private:
    // Struktura opisująca pojedynczy element drzewa
    typedef struct Tree{
        int val;
        Tree* left;
        Tree* right;
    }Tree_S;

    // wkażnik na kożeń drzewa
    Tree_S* root;

    // Metoda usuwa podane drzewo i zwraca nullpointer
    Tree_S* delete_tree(Tree_S* root){
        if(root != nullptr){
            delete_tree(root->left);
            delete_tree(root->right);
            delete root;
        }
        return nullptr;
    }

    // Metoda realizuje algorytm dodawanie elementu do dorzewa avl
    Tree_S* add_elem(int x, Tree_S* root){

        if(root == nullptr){
            root = new Tree_S;
            root->val = x;
            root->left = nullptr;
            root->right = nullptr;
        }
        else if(x < root->val)
            root->left = add_elem(x, root->left);
        else if(x > root->val)
            root->right = add_elem(x, root->right);
        return root;
    }


    

    // znajdż minimalny element w podanym drzewie
    Tree_S* findMin(Tree_S* tree){
        if(tree == NULL)
            return NULL;
        else if(tree->left == NULL)
            return tree;
        else
            return findMin(tree->left);
    }

    // znajdż maksymalne element w podanym drzewie
    Tree_S* findMax(Tree_S* tree){
        if(tree == nullptr)
            return nullptr;
        else if(tree->right == nullptr)
            return tree;
        else
            return findMax(tree->right);
    }
    
    // metoda realizuje algorytm wyszukiwania kluczy w drzewie
    bool find_elem( Tree_S *root, int val){
        if (root == nullptr)
             return false;
         if (root->val == val)
             return true;
        
         bool res1 = find_elem(root->left, val);
         if(res1) return true;
        
         bool res2 = find_elem(root->right, val);
         return res2;
    }


    // metoda realizuje algorytm usunięcia klucza z drzewa bst
    Tree_S* delete_elem(Tree_S* root, int x) {
        Tree_S* temp;
        if(root == nullptr)
            return nullptr;
        else if(x < root->val)
            root->left = delete_elem(root->left, x);
        else if(x > root->val)
            root->right = delete_elem(root->right, x);
        else if(root->left && root->right){
            temp = findMin(root->right);
            root->val = temp->val;
            root->right = delete_elem(root->right, root->val);
        }
        else{
            temp = root;
            if(root->left == nullptr)
                root = root->right;
            else if(root->right == nullptr)
                root = root->left;
            delete temp;
        }

        return root;
    }

    
    Tree_S* left_rotate(Tree_S* root){
        if(root->right != nullptr){
            Tree_S *right_child = root->right;
            root->right = right_child->right;
            right_child->right = right_child->left;
            
            root->left = right_child;
            int temp = root->val;
            root->val = right_child->val;
            right_child->val = temp;
        }
        
        return root;
    }
    
    Tree_S* right_rotate(Tree_S* root){
        if(root->left != nullptr){
            Tree_S *left_child = root->left;
            root->left = left_child->left;
            left_child->left = left_child->right;
            
            root->right = left_child;
            int temp = root->val;
            root->val = left_child->val;
            left_child->val = temp;
        }
        
        return root;
    }
    
    
    Tree_S * plank_tree(Tree_S* root){
        
        Tree_S* temp = root;
        while (temp->left != nullptr) {
            temp = right_rotate(temp);
        }
        if(temp->right != nullptr){
            temp->right = plank_tree(temp->right);
        }
        return temp;
    }
    
    
    int get_right_count(Tree_S* root){
        Tree_S* temp = root;
        if(root)
            return 0;
        int count = 0;
        while (temp->right) {
            count++;
            temp = temp->right;
        }
        return count;
    }
    
    Tree_S* dsw(Tree_S* root){
        Tree_S* temp = root;
        temp = plank_tree(root);
        int count = get_right_count(temp);
        int times = log2(count);
        Tree_S *newTree = temp;
        for(int i = 0; i < times; i++){
            newTree = left_rotate(newTree);
            temp = newTree->right;
            for(int j = 0; j < (count/2) - 1; j++){
                temp = left_rotate(temp);
                temp = temp->right;
            }
            count >>= 1;
        }
        return root;
    }


    // metoda realizuje wypisywanie drzewa inorder
    void inorder(Tree_S* tree){
        if(tree == nullptr)
            return;
        inorder(tree->left);
        cout << tree->val << " ";
        inorder(tree->right);
    }
    
    /* ============P=R=I=N=T=======(https://www.techiedelight.com/c-program-print-binary-tree/) **/

    struct Trunk
    {
        struct Trunk *prev;
        string str;

        Trunk(Trunk *prev, string str){
            this->prev = prev;
            this->str = str;
        }
    };

    void showTrunks(struct Trunk *p)
    {
        if (p == nullptr)
            return;

        showTrunks(p->prev);

        cout << p->str;
    }

    void printTree(Tree_S *head, Trunk *prev, bool isLeft)
    {
        if (head == nullptr)
            return;

        string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);

        printTree(head->left, trunk, true);

        if (!prev)
            trunk->str = "---";
        else if (isLeft)
        {
            trunk->str = ".---";
            prev_str = "   |";
        }
        else
        {
            trunk->str = "`---";
            prev->str = prev_str;
        }

        showTrunks(trunk);
        cout << head->val << endl;

        if (prev)
            prev->str = prev_str;
        trunk->str = "   |";

        printTree(head->right, trunk, false);
    }

    // =====================================================================
    
    
    
    

public:
    // Konstruktor
    BinaryTree(){ root = NULL; }

    // Metoda wywołuje główną metodę dla wstawiania kluczy w drzewo
    void add_value(int x){
        root = add_elem(x, root);
    }
    
    void makeBSW(){
        root = dsw(root);
    }

    // Metoda wywołuje główną metodę dla usunięcia kluczy z drzewa
    void remove(int x){
        root = delete_elem(root, x);
    }

    void print_bst(){ printTree(root, nullptr, false); }
    
    // Metoda wywołuje główną metodę dla usunięcia wszystkich kluczy z drzewa
    void delete_all_elems(){ root = delete_tree(root); }

    // Metoda wyświetla dzewo inorder
    void display_inorder(){
        inorder(root);
        cout << " (inorder)" << endl;
    }
    
    // sprawdzamy czy element znajduje się w drzewie
    bool is_in_bst(int val){
        Tree_S *temp = root;
        return find_elem(temp, val);
    }
    
    // metoda wypełnia drzewo z pliku
    void create_from_file(){
        
        root = delete_tree(root);
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
                root = add_elem(tmp, root);
                i++;
            }

            file.close();
        }
        else{
            cout << "Błednie podany path do pliku !" << endl;
        }
    }
    
};


#endif


