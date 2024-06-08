#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
#define fr(i,sz) for(i=0;i<sz;i++)
#define fa(i,v) for(auto &i:v)
#define yesno cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define vvl vector<vector<ll> >       
#define vl vector<ll>  
#define pll pair<ll,ll>  
#define vpll vector<pair<ll,ll> > 
#define vvpll vector<vector<pair<ll,ll> > > 
#define all(v) v.begin(),v.end()
#define mp make_pair
#define eb emplace_back
#define rs resize
#define cl(v) v.clear()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define inf (ll)1e18
#define f1 first
#define f2 second
#define mod (ll)(1e9+7)
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

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