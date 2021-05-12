
#ifndef AVL_hpp
#define AVL_hpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

// Klasa drzewa AVL
class AVL_Tree{
    
private:
    // Struktura opisująca pojedynczy element drzewa 
    typedef struct Tree{
        int val;
        Tree* left;
        Tree* right;
        int height;
    }Tree_S;

    // wkażnik na kożeń drzewa
    Tree_S* root;

    // Metoda usuwa podane drzewo i zwraca nullpointer
    Tree_S* delete_tree(Tree_S* tree){
        if(tree != nullptr){
            delete_tree(tree->left);
            delete_tree(tree->right);
            delete tree;
        }
        return nullptr;
    }

    // Metoda realizuje algorytm dodawanie elementu do dorzewa avl
    Tree_S* add_elem(int val, Tree_S* tree){
        if(tree == nullptr){
            tree = new Tree_S;
            tree->val = val;
            tree->height = 0;
            tree->left = tree->right = nullptr;
        }
        else if(val < tree->val){
            tree->left = add_elem(val, tree->left);
            if(height(tree->left) - height(tree->right) == 2){
                if(val < tree->left->val)
                    tree = singleRightRotate(tree);
                else
                    tree = doubleRightRotate(tree);
            }
        }
        else if(val > tree->val){
            tree->right = add_elem(val, tree->right);
            if(height(tree->right) - height(tree->left) == 2){
                if(val > tree->right->val)
                    tree = singleLeftRotate(tree);
                else
                    tree = doubleLeftRotate(tree);
            }
        }

        tree->height = max(height(tree->left), height(tree->right))+1;
        return tree;
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
    
    // metoda realizuje rotację w prawo na podanym drzewie
    Tree_S* singleRightRotate(Tree_S* &tree){
        Tree_S* temp = tree->left;
        Tree_S* t = temp->right;
        temp->right = tree;
        tree->left = t;
        tree->height = max(height(tree->left), height(tree->right))+1;
        temp->height = max(height(temp->left), height(temp->right))+1;
        return temp;
    }

    // metoda realizuje rotację w lewo na podanym drzewie
    Tree_S* singleLeftRotate(Tree_S* &tree){
        Tree_S* temp = tree->right;
        Tree_S* t = temp->left;
        temp->left = tree;
        tree->right = t;
        tree->height = max(height(tree->left), height(tree->right))+1;
        temp->height = max(height(temp->left), height(temp->right))+1;

        return temp;
    }

    // metoda realizuje podwujną rotacje w lewo
    Tree_S* doubleLeftRotate(Tree_S* &tree){
        tree->right = singleRightRotate(tree->right);
        return singleLeftRotate(tree);
    }

    // metoda realizuje podwujną rotacje w prawo
    Tree_S* doubleRightRotate(Tree_S* &tree){
        tree->left = singleLeftRotate(tree->left);
        return singleRightRotate(tree);
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

    // metoda realizuje algorytm usunięcia klucza z drzewa avl
    Tree_S* remove(Tree_S* root, int val){
          
        if (root == nullptr)
            return root;

        if ( val < root->val )
            root->left = remove(root->left, val);

        else if( val > root->val )
            root->right = remove(root->right, val);
      

        else{
            if( (root->left == nullptr) || (root->right == nullptr) ){
                Tree_S *temp = root->left ? root->left : root->right;
      

                if (temp == NULL){
                    temp = root;
                    root = NULL;
                }
                else{
                    *root = *temp;
                }
                delete temp;
            }
            else{
                Tree_S* temp = findMin(root->right);
                root->val = temp->val;
                root->right = remove(root->right, temp->val);
            }
        }
        if (root == NULL)
            return root;
        
        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);
    
        if (balance > 1 &&
            getBalance(root->left) >= 0)
            return singleRightRotate(root);
      
        if (balance > 1 &&
            getBalance(root->left) < 0)
        {
            root->left = singleLeftRotate(root->left);
            return singleRightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return singleLeftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0){
            root->right = singleRightRotate(root->right);
            return singleLeftRotate(root);
        }
      
        return root;
    }

    // metoda zwraca wysokość drzewa
    int height(Tree_S* tree){ return (tree == nullptr ? 0 : tree->height); }

    // metoda sprawdza czy drzewo jest zbalansowane
    int getBalance(Tree_S* tree){
        if(tree == nullptr)
            return 0;
        else
            return height(tree->left) - height(tree->right);
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
    AVL_Tree(){ root = NULL; }

    // Metoda wywołuje główną metodę dla wstawiania kluczy w drzewo
    void insert(int x){ root = add_elem(x, root); }

    // Metoda wywołuje główną metodę dla usunięcia kluczy z drzewa
    void delete_elem(int x){ root = remove(root, x); }

    void print_avl(){ printTree(root, nullptr, false); }
    
    // Metoda wywołuje główną metodę dla usunięcia wszystkich kluczy z drzewa
    void delete_all_elems(){ root = delete_tree(root); }

    // Metoda wyświetla dzewo inorder
    void display_inorder(){
        inorder(root);
        cout << " (inorder)" << endl;
    }
    
    // sprawdzamy czy element znajduje się w drzewie
    bool is_in_avl(int val){
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




#endif /* AVL_hpp */
