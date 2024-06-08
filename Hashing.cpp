const ll N=1e6;
const ll M=127657753; // or 987654319
const ll p=137; // or 277
ll pw[N+1], ipw[N+1];

ll bp(ll a, ll b, ll modu){
    if(!b) return 1;
    ll x=bp(a,b/2,M);
    if(b%2) return (((a*x)%modu)*x)%modu;
    return (x*x)%modu;
}

ll mi(ll a, ll modu){
    return bp(a,modu-2,modu);
}

void computehash(){
    ll i;
    pw[0]=1;
    fr(i,N+1) if(i) pw[i]=(pw[i-1]*p)%M;
    ll ip=mi(p,M);
    ipw[0]=1;
    fr(i,N+1) if(i) ipw[i]=(ipw[i-1]*ip)%M;
}

class Hashing{
    public:
    ll n;
    string s; // 0 - indexed
    vl hs; 

    Hashing(string t="") {
        ll i;
        n=t.size();
        s=t;
        hs.rs(n);
        fr(i,n) if(i) hs[i]=(hs[i-1]+((s[i]-'a'+1)*pw[i])%M)%M;
        else hs[i]=((s[i]-'a'+1)*pw[i])%M;
    }

    ll get(ll l, ll r){
        if(l) return (((hs[r]-hs[l-1]+M)%M)*ipw[l])%M;
        else return hs[r];
    }

    ll get(){
        return get(0,n-1);
    }
};