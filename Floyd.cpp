vvl rv;
vl v;
vector<bool> vis;

ll n,i;
cin>>n;
v.rs(n+1);
rv.rs(n+1);
vis.rs(n+1,0);
fr(i,n){
    ll x;
    cin>>x;
    v[i+1]=x;
    rv[x].pb(i+1);
}
fr(i,n) if(!vis[i+1]){
    ll a=i+1, b=i+1;
    do{
        a=v[a], b=v[v[b]];
    }while(a!=b);
}