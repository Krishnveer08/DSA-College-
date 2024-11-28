#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;

    public:
        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

node* insert(node* root , int data){

    if(root==NULL){
        return  new node(data);
    }
    if(data>root->data){
        root->right = insert(root->right , data);
    }
    else{
        root->left = insert(root->left , data);
    }
    return root;
}

int search(node* root,int data){
    
    if(root==NULL){
        return 0;
    }

    else if(data==root->data){
        return 1;
    }

    if(data > root->data){
      return search(root->right ,data);
    }
    else{
      return  search(root->left,data );
    }
}

int main() {

    node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

   int value = 40;
    if (search(root, value)) {
        cout<<"Node with value "<<value<<" found in the BST."<<endl;
    } else {
        cout<<"Node with value "<<value<<"Not found in the BST."<<endl;
    }

    return 0;
}