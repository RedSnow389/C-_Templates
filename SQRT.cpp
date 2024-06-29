class sqrt{ // traditional
    public:
    ll B;
    vl blx;
    vl num;

    sqrt(ll n){
        B=sqrt(n);
        if(B*B!=n) B++;
        blx.rs(B);
    }

    void update(ll i, ll x){
        blx[i/B]-=num[i];
        num[i]=x;
        blx[i/B]+=num[i];
    }

    ll sum(ll l, ll r){
        ll ans=0;
        while(l<=r){
            if(l%B==0 && l+B-1<=r){
                ans+=blx[l/B];
                l+=B;
            }
            else ans+=num[l], l++;
        }
        return ans;
    }
}

class sqrt{ // range update
    public:
    ll B;
    vl blx;
    vl num;

    sqrt(ll n){
        B=sqrt(n);
        if(B*B!=n) B++;
        blx.rs(B);
    }

    void update(ll l, ll r, ll x){
        while(l<=r){
            if(l%B==0 && l+B-1<=r){
                blx[l/B]+=x;
                l+=B;
            }
            else num[l]+=x, l++;
        }
    }

    ll sum(ll i){
        return num[i]+blx[i/B];
    }
}