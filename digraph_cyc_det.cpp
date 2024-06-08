vvl v;
vector<bool> vis,dfsvis;
vl cyc;

bool dfs(ll u){
    vis[u]=1;
    dfsvis[u]=1;
    fa(i,v[u]) if(dfsvis[i]){
        cyc.pb(u);
        dfsvis[u]=0;
        dfsvis[i]=0;
        return 1;
    }
    else if(!vis[i]){
        if(dfs(i)){
            if(dfsvis[u]){
                dfsvis[u]=0;
                cyc.pb(u);
                return 1;
            }
            else{
                cyc.pb(u); // this is the vertex whcih was vis twice as dfsvis[i] was made 0 before
                return 0;
            }
        }
        if(cyc.size()) return 0;
    }
    dfsvis[u]=0;
    return 0;
}

int main(){
    fastio
    ll n,i,m;
    cin>>n>>m;
    v.rs(n+1);
    vis.rs(n+1);
    dfsvis.rs(n+1);
    while(m--){
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
    }
    for(i=1;cyc.empty() && i<=n;i++) dfs(i);
    if(cyc.empty()) cout<<"IMPOSSIBLE"<<endl;
    else{
        reverse(all(cyc));
        cout<<cyc.size()+1<<endl;
        fa(i,cyc) cout<<i<<' ';
        cout<<cyc[0];
    }
}  
