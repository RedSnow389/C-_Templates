#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class node{
    private:
    int priority, id;

    node(int a=-1, int b=-1){
        priority=a,id=b;
    }

    void swap1(node &a){
        int t1=priority;
        int t2=id;
        priority=a.priority;
        id=a.id;
        a.priority=t1;
        a.id=t2;
    }

    friend class minheap;
};

class minheap{
    private:
    int mx,size;
    vector<node> v;

    public:
    minheap(int a=-1){
        mx=a;
        size=0;
        node n;
        v.push_back(n);
    }

    void insert(int a,int b){
        if(size==mx) return;
        node n(a,b);
        v.push_back(n);
        int x=++size;
        while(x>1 && v[x].priority<v[x/2].priority){
            v[x].swap1(v[x/2]);
            x/=2;
        }
    }

    void print(){
        int i;
        for(i=1;i<=size;i++) cout<<v[i].priority<<' ';
        cout<<endl;
    }

    node getmin(){
        return v[0];
    }

    void delmin(){
        v[1]=v[size];
        v.pop_back();
        size--;
        int x=1;
        while(1){
            if(2*x+1<=size){
                if(v[2*x+1].priority<v[x].priority && v[2*x].priority<v[x].priority){
                    if(v[2*x+1].priority>v[2*x].priority){
                        v[x].swap1(v[2*x]);
                        x=2*x;
                    }
                    else{
                        v[x].swap1(v[2*x+1]);
                        x=2*x+1;
                    }
                }
                else if(v[2*x+1].priority>v[x].priority && v[2*x].priority<v[x].priority){
                    v[x].swap1(v[2*x]);
                    x=2*x;
                }
                else if(v[2*x+1].priority<v[x].priority && v[2*x].priority>v[x].priority){
                    v[x].swap1(v[2*x+1]);
                    x=2*x+1;
                }
                else break;
            }
            else if(2*x<=size){
                if(v[2*x].priority<v[x].priority){
                    v[x].swap1(v[2*x]);
                    x=2*x;
                }
                else break;
            }
            else break;
        }
    }
};

int main(){
    int n;
    cin>>n;
    minheap mh(n);
    while(n--){
        int pri,id;
        cin>>pri>>id;
        mh.insert(pri,id);
        mh.print();
        cout<<endl;
    }
    mh.print();
    cout<<endl;
    mh.delmin();
    mh.print();
    return 0;
}

/*
if(2*x+1)<size/