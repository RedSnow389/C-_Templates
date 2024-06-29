class segtree{ // traditional 
    public:
    vl vmx,vmn,v;
    ll sz; //sz=size of btm layer
 
    segtree(ll n){
        sz=1;
        while(sz<n) sz*=2;
        v.assign(sz*2,0);
        vmx.assign(sz*2,-inf);
        vmn.assign(sz*2,inf);
    }
 
    void update(ll i,ll x){
        update(i,x,1,0,sz-1);
    }

    void update(ll i, ll x, ll ind, ll lr, ll rr){
        if(ind>=sz){
            v[ind]=x;
            vmx[ind]=x;
            vmn[ind]=x;
            return;
        }
        if((rr+lr)/2>=i) update(i,x,2*ind,lr,(rr+lr)/2);
        else update(i,x,2*ind+1,(rr+lr)/2+1,rr);
        v[ind]=v[2*ind]+v[2*ind+1];
        vmx[ind]=max(vmx[2*ind],vmx[2*ind+1]);
        vmn[ind]=min(vmn[2*ind],vmn[2*ind+1]);
    }

    ll sum(ll l, ll r){
        return sum(l,r,1,0,sz-1);
    }

    ll sum(ll l, ll r, ll ind, ll lr, ll rr){
        if(l>rr || r<lr) return 0;
        if(l<=lr && r>=rr) return v[ind];
        return sum(l,r,2*ind,lr,(lr+rr)/2)+sum(l,r,2*ind+1,(lr+rr)/2+1,rr);
    }

    ll mx(ll l, ll r){
        return mx(l,r,1,0,sz-1);
    }
 
    ll mx(ll l, ll r, ll ind, ll lr, ll rr){
        if(l>rr || r<lr) return -inf;
        if(l<=lr && r>=rr) return vmx[ind];
        return max(mx(l,r,2*ind,lr,(lr+rr)/2),mx(l,r,2*ind+1,(lr+rr)/2+1,rr));
    }

    ll mn(ll l, ll r){
        return mn(l,r,1,0,sz-1);
    }

    ll mn(ll l, ll r, ll ind, ll lr, ll rr){
        if(l>rr || r<lr) return inf;
        if(l<=lr && r>=rr) return vmn[ind];
        return min(mn(l,r,2*ind,lr,(lr+rr)/2),mn(l,r,2*ind+1,(lr+rr)/2+1,rr));
    }

    void print(){
        ll i,j;
        fr(i,2*sz){
            if(i) cout<<vmx[i]<<' ';
            ll c=0;
            fr(j,32) if((1<<j)&(1+i)) c++;
            if(c==1) cout<<endl;
        }
    }
};

class segtree{ //rerooting type
    public:
    vl v;
    ll sz; //sz=size of btm layer
 
    segtree(ll n){
        sz=1;
        while(sz<n) sz*=2;
        v.assign(sz*2,0);
    }

    void prop(ll ind){ //lazy prop
        if(ind>=sz || v[ind]==-1){
            v[ind]=-1;
            return;
        }
        v[2*ind]=v[ind];
        v[2*ind+1]=v[ind];
        v[ind]=-1;
    }
 
    void sum(ll l, ll r, ll x){
        sum(l,r,x,1,0,sz-1);
    }
 
    void sum(ll l, ll r, ll x, ll ind, ll lr, ll rr){
        if(l>rr || r<lr) return;
        if(l<=lr && r>=rr){
            v[ind]+=x;
            return;
        }
        sum(l,r,x,2*ind,lr,(lr+rr)/2);
        sum(l,r,x,2*ind+1,(lr+rr)/2+1,rr);
    }
 
    ll val(ll i){
        return val(i,1,0,sz-1);
    }
 
    ll val(ll i, ll ind, ll lr, ll rr){
        if(ind>=sz) return v[ind];
        if((lr+rr)/2>=i) return v[ind]+val(i,2*ind,lr,(lr+rr)/2);
        return v[ind]+val(i,2*ind+1,(lr+rr)/2+1,rr);
    }
 
    void print(){
        ll i,j;
        fr(i,2*sz){
            if(i) cout<<v[i]<<' ';
            ll c=0;
            fr(j,32) if((1<<j)&(1+i)) c++;
            if(c==1) cout<<endl;
        }
    }
};

vl a;
ll n,i;
 
class segtree{ // first elem such that j>=i and a[j]>=x
    public:
    vl v;
    ll sz; //sz=size of btm layer
 
    segtree(ll n){
        sz=1;
        while(sz<n) sz*=2;
        v.rs(sz*2);
    }
 
    void update(ll i,ll x){
        update(i,x,1,0,sz-1);
    }
 
    void update(ll i, ll x, ll ind, ll lr, ll rr){
        if(ind>=sz){
            v[ind]=x;
            return;
        }
        if((rr+lr)/2>=i) update(i,x,2*ind,lr,(rr+lr)/2);
        else update(i,x,2*ind+1,(rr+lr)/2+1,rr);
        v[ind]=max(v[2*ind],v[2*ind+1]);
    }
 
    ll mx(ll x, ll l){
        return mx(x,l,1,0,sz-1);
    }
 
    ll mx(ll x, ll l, ll ind, ll lr, ll rr){
        if(ind>=sz){
            if(ind-sz<l || ind-sz>=n || a[ind-sz]<x) return -1;
            return ind-sz;
        }
        ll p=-1;
        if(v[2*ind]>=x && (lr+rr)/2>=l) p=mx(x,l,2*ind,lr,(lr+rr)/2);
        if(p!=-1) return p;
        return mx(x,l,2*ind+1,1+(lr+rr)/2,rr);
    }
};

class segtree{ // first elem such that j<=i and a[j]>=x
    public:
    vl v;
    ll sz; //sz=size of btm layer
 
    segtree(ll n){
        sz=1;
        while(sz<n) sz*=2;
        v.rs(sz*2);
    }
 
    void update(ll i,ll x){
        update(i,x,1,0,sz-1);
    }
 
    void update(ll i, ll x, ll ind, ll lr, ll rr){
        if(ind>=sz){
            v[ind]=x;
            return;
        }
        if((rr+lr)/2>=i) update(i,x,2*ind,lr,(rr+lr)/2);
        else update(i,x,2*ind+1,(rr+lr)/2+1,rr);
        v[ind]=max(v[2*ind],v[2*ind+1]);
    }
 
    ll mx(ll x, ll l){
        return mx(x,l,1,0,sz-1);
    }
 
    ll mx(ll x, ll l, ll ind, ll lr, ll rr){
        if(ind>=sz){
            if(ind-sz>l || ind-sz<=-1 || a[ind-sz]<x) return -1;
            return ind-sz;
        }
        ll p=-1;
        if(v[2*ind+1]>=x && (lr+rr)/2<=l) p=mx(x,l,2*ind+1,1+(lr+rr)/2,rr);
        if(p!=-1) return p;
        return mx(x,l,2*ind,lr,(lr+rr)/2);
    }
};
