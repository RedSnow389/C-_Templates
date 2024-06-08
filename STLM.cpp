vector<set<ll> > cols;
vvl v;
vl ans;
 
void dfs(ll u, ll par=-1){
    fa(i,v[u]) if(i!=par){
        dfs(i,u);
        if(cols[i].size()>cols[u].size()) swap(cols[i], cols[u]);
        fa(j,cols[i]) cols[u].insert(j);
        cl(cols[i]);
    }
    ans[u]=cols[u].size();
}
