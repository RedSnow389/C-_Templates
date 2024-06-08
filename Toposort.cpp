ll n,m,i;
cin>>n>>m;
vvl v(n+1), rv(n+1);
vl ts, ind(n+1);
while(m--){
    ll x,y;
    cin>>x>>y;
    v[x].eb(y);
    rv[y].eb(x);
    ind[y]++;
}
queue<ll> q;
fr(i,n) if(ind[i+1]==0) q.push(i+1);
while(!q.empty()){
    ll a=q.front();
    ts.eb(a);
    q.pop();
    fa(i,v[a]){
        ind[i]--;
        if(!ind[i]) q.push(i);
    }
}