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

class segtree{ // traditional 
    public:
    vl v;
    ll sz; //sz=size of btm layer
 
    segtree(){}

    segtree(ll n){
        sz=1;
        while(sz<n) sz*=2;
        v.assign(sz*2,-inf);
    }
 
    void update(ll i,ll x){
        update(i,x,1,0,sz-1);
    }
 
    ll mx(ll l, ll r){
        return mx(l,r,1,0,sz-1);
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
 
    ll mx(ll l, ll r, ll ind, ll lr, ll rr){
        if(l>rr || r<lr) return -inf;
        if(l<=lr && r>=rr) return v[ind];
        return max(mx(l,r,2*ind,lr,(lr+rr)/2),mx(l,r,2*ind+1,(lr+rr)/2+1,rr));
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

vvl v;
vl val,sz,ind,topmost,par,dep;
segtree s;
ll cnt=0;

void dfs(ll u, ll parent){
    fa(i,v[u]) if(i!=parent){
        dep[i]=dep[u]+1;
        dfs(i,u);
        par[i]=u;
        sz[u]+=sz[i];
    }
}

void dfs(ll u, ll parent, ll tp){
    s.update(cnt,val[u]);
    ind[u]=cnt;
    topmost[u]=tp;
    cnt++;
    ll bc=-1, bcs=-1;
    fa(i,v[u]) if(i!=parent && sz[i]>bcs) bc=i, bcs=sz[bc];
    if(bc==-1) return;
    dfs(bc,u,tp);
    fa(i,v[u]) if(i!=parent && i!=bc) dfs(i,u,i);
}

ll mxquery(ll a, ll b){
    ll ans=-inf;
    while(topmost[a]!=topmost[b]){
        if(dep[topmost[a]]>dep[topmost[b]]) swap(a,b);
        ans=max(ans,s.mx(ind[topmost[b]],ind[b]));
        b=par[topmost[b]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    ans=max(ans,s.mx(ind[a],ind[b]));
    return ans;
}

int main(){
    fastio
    ll n,i,q;
    cin>>n>>q;
    v.rs(n+1);
    val.rs(n+1);
    ind.rs(n+1);
    sz.rs(n+1,1);
    par.rs(n+1,-1);
    dep.rs(n+1);
    topmost.rs(n+1,1);
    s=segtree(n);
    fr(i,n) cin>>val[i+1];
    fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        v[x].eb(y);
        v[y].eb(x);
    }
    dfs(1,1);
    dfs(1,1,1);
    while(q--){
        ll x,y,z;
        cin>>x>>y>>z;
        if(x==1) s.update(ind[y],z);
        else cout<<mxquery(y,z)<<' ';
    }
}   
