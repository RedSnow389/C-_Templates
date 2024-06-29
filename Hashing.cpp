#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
#define fr(i,n) for(i=0;i<n;i++)
#define fa(i,v) for(auto &i:v)
#define yesno cout<<"YES"<<endl; else cout<<"NO"<<endl;
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
#define mod 998244353
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

const ll N=1e6;
const pll M=mp(127657753,987654319);
const pll p=mp(137,277);
pll pw[N+1], ipw[N+1];

ll bp(ll a, ll b, ll modu){
    if(!b) return 1;
    ll x=bp(a,b/2,modu);
    if(b%2) return (((a*x)%modu)*x)%modu;
    return (x*x)%modu;
}

ll mi(ll a, ll modu){
    return bp(a,modu-2,modu);
}

void computehash(){
    ll i;
    pw[0]=mp(1,1);
    fr(i,N+1) if(i) pw[i].f1=(pw[i-1].f1*p.f1)%M.f1, pw[i].f2=(pw[i-1].f2*p.f2)%M.f2;
    pll ip=mp(mi(p.f1,M.f1), mi(p.f2,M.f2));
    ipw[0]=mp(1,1);
    fr(i,N+1) if(i) ipw[i].f1=(ipw[i-1].f1*ip.f1)%M.f1, ipw[i].f2=(ipw[i-1].f2*ip.f2)%M.f2;
}

class Hashing{
    public:
    ll n;
    string s; // 0 - indexed
    vpll hs; 

    Hashing(string t="") {
        ll i;
        n=t.size();
        s=t;
        hs.rs(n);
        fr(i,n) if(i) hs[i].f1=(hs[i-1].f1+((s[i]-'a'+1)*pw[i].f1)%M.f1)%M.f1, hs[i].f2=(hs[i-1].f2+((s[i]-'a'+1)*pw[i].f2)%M.f2)%M.f2;
        else hs[i].f1=((s[i]-'a'+1)*pw[i].f1)%M.f1, hs[i].f2=((s[i]-'a'+1)*pw[i].f2)%M.f2;
    }

    pll get(ll l, ll r){
        if(l) return mp((((hs[r].f1-hs[l-1].f1+M.f1)%M.f1)*ipw[l].f1)%M.f1, (((hs[r].f2-hs[l-1].f2+M.f2)%M.f2)*ipw[l].f2)%M.f2);
        else return hs[r];
    }

    pll get(){
        return get(0,n-1);
    }
};