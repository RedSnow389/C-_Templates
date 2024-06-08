//Name: RAjeev Rangarajan Balaji
//Roll no: CS22B094

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

class node1{
    private:
    int acc, bal;
    node1* next;

    node1(int num = -1){
        acc=num, bal=1000;
        next=NULL;
    }
    friend class ll;
};

class node2{
    private:
    int acc, tra;
    node2* prev;
    node2* next;

    node2(){
        acc=-1, tra=0;
        prev=NULL;
        next=NULL;
    }

    node2(int a, int b){
        acc=a;
        tra=b;
        prev=NULL;
        next=NULL;
    }
    friend class ll;
};

class ll{
    private:
    node1* first;
    node1* last;
    node2* first2;
    node2* last2;
    node2* cursor;
    int len;

    public:
    ll(){
        first=NULL;
        first2=new node2();
        last2=new node2();
        first2->next=last2;
        last2->prev=first2;
        cursor=first2;
    }
    
    void push(int k){
        node1* n=new node1(k);
        if(!first){
            first=n;
            last=n;
        }
        else{
            last->next=n;
            last=n;
        }
        len++;
    }

    void push2(int acc, int tra){
        node2* n=new node2(acc,tra);
        last2->prev->next=n;
        n->prev=last2->prev;
        n->next=last2;
        last2->prev=n;
    }

    void process(node2* pro, bool boo = true){
        node1* temp=first;
        while(temp->acc!=pro->acc) temp=temp->next;
        if(boo) temp->bal+=pro->tra;
        else temp->bal-=pro->tra;
        return;
    }

    void prox(int x){
        while(x-- && cursor->next!=last2){
            process(cursor->next);
            cursor=cursor->next;
        }
    }

    void proy(int y){
        while(y-- && cursor!=first2){
            process(cursor,false);
            cursor=cursor->prev;
        }
    }

    void insertnode(int a, int b, int k){
        bool boo=false;
        node2* n=new node2(a,b);
        node2* temp=first2;
        while(k-- && temp!=last2){
            temp=temp->next;
            if(temp==cursor) boo=true;
        }
        if(temp==last2) return;
        temp->next->prev=n;
        n->next=temp->next;
        temp->next=n;
        n->prev=temp;
        if(!boo) process(n);
    }

    void del2(node2* todel){
        node2* previ=todel->prev;
        node2* nexti=todel->next;
        previ->next=nexti;
        nexti->prev=previ;
    }

    void update(int a, int k){
        if(k>0){
            node2* temp=cursor->next;
            while(temp!=last2 && k){
                if(temp->acc==a){
                    del2(temp);
                    k--;
                }
                temp=temp->next;
            }
        }
        else{
            node2* temp=cursor->prev;
            k=-k;
            while(temp!=first2 && k){
                if(temp->acc==a){
                    process(temp,false);
                    del2(temp);
                    k--;
                }
                temp=temp->prev;
            }
        }
    }

    void proafter(){
        while(cursor->next!=last2){
            process(cursor->next);
            cursor=cursor->next;
        }
    }

    void printofacc(int y){
        node2* temp=first2;
        while(temp!=cursor->next){
            if(temp->acc==y){
                cout<<temp->acc<<' ';
                if(temp->tra>0) cout<<'D'<<' '<<temp->tra<<endl;
                else cout<<'W'<<' '<<-temp->tra<<endl;
            }
            temp=temp->next;
        }
    }   

    void gr(int k){
        node1* temp=first;
        int c=0;
        while(temp!=NULL){
            if(temp->bal>=k) c++;
            temp=temp->next;
        }
        cout<<c<<endl;
    }

    void highbal(){
        node1* temp=first;
        int mx=temp->bal,i;
        vector<int> v;
        while(temp!=NULL){
            if(temp->bal>mx) mx=temp->bal;
            temp=temp->next;
        }
        temp=first;
        while(temp!=NULL){
            if(temp->bal==mx) v.push_back(temp->acc);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        for(i=0;i<(int)v.size() && v[i]==v[0];i++) cout<<v[i]<<' ';
        cout<<endl;
    }

    void printacc(int x){
        node1* temp=first;
        while(temp!=NULL && temp->acc!=x) temp=temp->next;
        cout<<temp->bal<<endl;
    }
};

int main(){
    int c,i,x,q;
    ll l;
    cin>>c;
    while(c--){
        cin>>x;
        l.push(x);
    }
    cin>>q;
    while(q--){
        int a,b;
        char d;
        cin>>a>>d>>b;
        if(d=='D') l.push2(a,b);
        else l.push2(a,-b);
    }
    char s;
    while(1){
        cin>>s;
        if(s=='F'){
            int p;
            cin>>p;
            l.prox(p);
        }
        else if(s=='R'){
            int p;
            cin>>p;
            l.proy(p);
        }
        else if(s=='I'){
            int a,b,p;
            char d;
            cin>>a>>d>>b>>p;
            if(d=='D') l.insertnode(a,b,p);
            else l.insertnode(a,-b,p);
        }
        else if(s=='D'){
            int a,m;
            cin>>a>>m;
            l.update(a,m);
        }
        else if(s=='C'){
            l.proafter();
        }
        else if(s=='S'){
            int y;
            cin>>y;
            l.printofacc(y);
        }
        else if(s=='G'){
            int y;
            cin>>y;
            l.gr(y);
        }
        else if(s=='M'){
            l.highbal();
        }
        else if(s=='V'){
            int y;
            cin>>y;
            l.printacc(y);
        }
        else break;
    }
    return 0;
}