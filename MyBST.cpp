#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class elem{
    private:
    elem* left;
    elem* right;
    elem* par;
    int val;

    elem(int a){
        val=a;
        left=nullptr;
        right=nullptr;
        par=nullptr;
    }

    void print(){
        cout<<val<<' ';
    }

    friend class bst;
};

class bst{
    private:
    elem* root;

    public:
    bst(){
        root=nullptr;
    }

    void insert(int a, elem* n=nullptr){
        elem* e=new elem(a);
        if(root==nullptr) root=e;
        else if(n==nullptr) insert(a,root);
        else if(n->val<a){
            if(!n->right){
                n->right=e;
                e->par=n;
                return;
            }
            insert(a,n->right);
        }
        else if(n->val>a){
            if(!n->left){
                n->left=e;
                e->par=n;
                return;
            }
            insert(a,n->left);
        }
    }

    elem* searchbst(int a, elem* n=nullptr){
        if(root==nullptr) return nullptr;
        if(n==nullptr) return searchbst(a,root);
        if(n->val<a && n->right) return searchbst(a,n->right);
        if(n->val>a && n->left) return searchbst(a,n->left);
        if(n->val==a) return n;
        return nullptr;
    }

    void inorder(elem* n=nullptr){
        if(n==nullptr){
            inorder(root);
            return;
        }
        if(n->left) inorder(n->left);
        n->print();
        if(n->right) inorder(n->right);
        return;
    }

    elem* findmin(elem* n){
        while(n->left) n=n->left;
        return n;
    }

    void del(elem* n){
        if(n==nullptr) return;
        if(root==n){
            if(!root->left && !root->right){
                root=nullptr;
                delete root;
            }
            else if(root->left && !root->right){
                root=root->left;
                root->par=nullptr;
                delete n;
            }
            else if(!root->left && root->right){
                root=root->right;
                root->par=nullptr;
                delete n;
            }
            else{
                elem* mn=findmin(root->right);
                root->val=mn->val;
                del(mn);
            }  
            return;
        }
        if(!n->left && !n->right){
            if(n->par->left==n) n->par->left=nullptr;
            else n->par->right=nullptr;
            n->par=nullptr;
            delete n;
        }
        else if(n->left && !n->right){
            if(n->par->left==n) n->par->left=n->left;
            else n->par->right=n->right;
            n->par=nullptr;
            n->left=nullptr;
            delete n;
        }
        else if(!n->left && n->right){
            if(n->par->left==n) n->par->left=n->left;
            else n->par->right=n->right;
            n->par=nullptr;
            n->right=nullptr;
            delete n;
        }
        else{
            elem* mn=findmin(n->right);
            n->val=mn->val;
            del(mn);
        }
    }

    void levorder(){
        queue<elem*> q;
        q.push(root);
        while(!q.empty()){
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.front()->print();
            q.pop();
        }
        cout<<endl;
    }
};

int main(){
    bst tree;
    tree.insert(5);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(0);
    tree.insert(88);
    tree.insert(3);
    tree.insert(-80);
    tree.levorder();
    cout<<endl;
    tree.del(tree.searchbst(5));
    tree.levorder();
    return 0;
}