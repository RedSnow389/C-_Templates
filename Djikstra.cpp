int main(){
    ll n,m,i;
    cin>>n>>m;
    vvpll v(n+1);
    vl dist(n+1,inf);
    vl par(n+1);
    while(m--){
        ll x,y,z;
        cin>>x>>y>>z;
        v[x].pb(mp(y,z));
        v[y].pb(mp(x,z));
    }
    priority_queue<pll, vector<pll>, greater<pll> > q;
    dist[1]=0;
    q.push(mp(0,1));
    while(!q.empty()){
        ll b=q.top().f2, a=q.top().f1;
        q.pop();
        if(dist[b]<a) continue;
        fa(i,v[b]) if(dist[i.f1]>dist[b]+i.f2){
            par[i.f1]=b;
            dist[i.f1]=dist[b]+i.f2;
            q.push(mp(dist[i.f1],i.f1));
        }
    }
    if(dist[n]==inf){
        cout<<-1;
        return 0;
    }
    vl path;
    path.pb(n);
    while(n!=1){
        n=par[n];
        path.pb(n);
    }
    reverse(path.begin(),path.end());
    fa(i,path) cout<<i<<' ';
} 