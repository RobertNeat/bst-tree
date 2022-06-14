#include <iostream>

using namespace std;

/* Operations:
- adding node to the tree (add_node),
- search element in the tree structure(find_node),
- delete node (delete_node),
- walking through tree (inorder, postorder, preorder).
*/

struct node{
    int key;
    node* parent;
    node* left;
    node* leeft;
    node* right;
};

////////////////////BST tree functions//////////////////////
node* make_node(int value){
    node* n=new node;
    n->key=value;
    n->left=nullptr;
    n->right=nullptr;
    n->parent=nullptr;
    return n;
}

node* addNode(int value, node*& root){
    node* temp;
    if(root==nullptr){
        root=make_node(value);
        return root;
    }
    temp=root;

    while(true){
        if(value>=temp->key){
            if(temp->right==nullptr){
                temp->right=make_node(value);
                temp->right->parent=temp;
                return temp;
            }
            temp=temp->right;
        }
        else{
        if(temp->left==nullptr){
            temp->left=make_node(value);
            temp->left->parent=temp;
            return temp;
        }
        temp=temp->left;
        }
    }
}
///////////WALKING THROUGH TREE//////////////////////
void preorder(node* root){
    if(root!=nullptr){
        cout<<root->key<<",";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<",";
    }
}

void inorder(node* root){
    if(root!=nullptr){
    inorder(root->left);
    cout<<root->key<<",";
    inorder(root->right);
    }
}
//////////////SEARCHING ELEMENT///////////////////////////
node* findNode(node* root, int value){
    while(root!=nullptr){
        if(root->key==value){
            return root;
        }
        if(value>root->key){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return nullptr;
}

node* findSuccessor(node*n){
    if(n->right!=nullptr){
        n=n->right;
        while(n->left!=nullptr){
            n=n->left;
        }
        return n;
    }
    node* temp=n->parent;
    while(temp!=nullptr && temp->left!=n){
        n=temp;
        temp=temp->parent;
    }
    return temp;
}

void delete_tree(node* &root){
    if(root!=nullptr){
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
    root=nullptr;
}
////////////////////////////////////////////////////////////////////
void line(){cout<<"---------------------------------------------------\n";}
void menu(int &a){
line();
cout<<"Menu:\n";
cout<<"1.Check if tree is empty\n";
cout<<"2.Add new node to the tree\n";
cout<<"3.Check if node of given key exists\n";
cout<<"4.Display tree - preorder\n";
cout<<"5.Display tree - inorder\n";
cout<<"6.Display tree - postorder\n";
cout<<"8.Delete all nodes from the tree\n";
cout<<"9. Exit\n";
line();
cout<<"Choosing:";
cin>>a;
}
////////////////////////////////////////////////////////////////////
bool isEmpty(node* n){
    if(n==nullptr) return true;
    return false;
}
//////////////////////////////////////////////////////////////////////
int main()
{
    node* tree=nullptr;

    int a;
    menu(a);

    int key;

while(a!=9){
    switch(a){
    case 1:
            if(isEmpty(tree)) cout<<"BST tree is empty\n";
            else cout<<"BST tree contains something\n";
        menu(a);
        break;
    case 2:
            cout<<"Provide key value:";
            cin>>key;
            if(findNode(tree, key)==nullptr){
                    cout<<"Tree before adding node:";
                    inorder(tree);
                    cout<<"\n";
                    addNode(key,tree);
                    cout<<"Tree after node is added:";
                    inorder(tree);
                    cout<<"\n";
            }
            else cout<<"Node already exists in BST tree (execution rollback)\n";
        menu(a);
        break;
    case 3:
            cout<<"Provide key value:";
            cin>>key;
            if(findNode(tree, key)==nullptr) cout<<"Given node don't exist in tree structure\n";
            else cout<<"Node of a given key exists in tree structure\n";
        menu(a);
        break;
    case 4:
            preorder(tree);
            cout<<"\n";
        menu(a);
        break;
    case 5:
            inorder(tree);
            cout<<"\n";
        menu(a);
        break;
    case 6:
            postorder(tree);
            cout<<"\n";
        menu(a);
        break;
    case 8:
            delete_tree(tree);
            cout<<"Tree deleted\n";
        menu(a);
        break;
    default:
        cout<<"Bad position\n";
        menu(a);
        break;
    }
}

    cout << "Program end" << endl;
    return 0;
}
