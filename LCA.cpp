const ll L=20;
vvl kpar;
vl lev;

void findpar(ll u, ll par=-1){
    ll i;
    if(par){
        lev[u]=lev[par]+1;
        kpar[u][0]=par;
    }
    else kpar[u][0]=u;
    fr(i,L) if(i) kpar[u][i]=kpar[kpar[u][i-1]][i-1];
    fa(i,v[u]) if(i!=par) findpar(i,u);
}

ll lca(ll x, ll y){
    ll i;
    if(lev[x]>lev[y]) swap(x,y);
    ll diff=lev[y]-lev[x];
    fr(i,L) if((1<<i)&diff) y=kpar[y][i];
    if(x==y) return x;
    for(i=L-1;i>=0;i--) if(kpar[x][i]!=kpar[y][i]){
        x=kpar[x][i];
        y=kpar[y][i];
    }
    return kpar[x][0];
}