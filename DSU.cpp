class dsu{
    public:
    vl par;
    vl siz;

    dsu(ll n){
        ll i;
        siz.assign(n,1);
        fr(i,n) par.eb(i);
    }
    
    ll fp(ll a){
        if(par[a]==a) return a;
        return par[a]=fp(par[a]);
    }
    
    bool uni(ll a, ll b){ //true if can unite
        a=fp(a);
        b=fp(b);
        if(a==b) return false;
        if(siz[a]<siz[b]) swap(a,b);
        par[b]=a;
        siz[a]+=siz[b];
        return true;
    }
};