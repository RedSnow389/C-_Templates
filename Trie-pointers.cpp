const int A=26;

class node{
	public:
	bool isend;
	node* children[A];

	node(){
		ll i;
		fr(i,A) children[i]=nullptr;
		isend=0;
	}
};

class trie{
	public:
	node* root;

	trie(){
		root=new node();
	}

	void insert(string &s){
		node* temp=root;
		fa(i,s){
			if(!temp->children[i-'a']) temp->children[i-'a']=new node();
			temp=temp->children[i-'a'];
		}
		temp->isend=1;
	}
};

//bitwise

class node{
	public:
	ll isend;
	node* children[2];
 
	node(){
		ll i;
		fr(i,2) children[i]=nullptr;
		isend=0;
	}
};
 
 
class trie{
	public:
	node* root;
 
	trie(){
		root=new node();
	}
 
	void insert(ll x){
		node* temp=root;
        ll i;
		for(i=63;i>=0;i--){
			if(p2(i)&x){
                if(!temp->children[1]) temp->children[1]=new node();
                temp=temp->children[1];
            }
			else{
                if(!temp->children[0]) temp->children[0]=new node();
                temp=temp->children[0];
            }
		    temp->isend++;
		}
	}
};
 