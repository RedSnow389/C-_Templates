vl disc,low,vis;
vvpll v;
set<ll> br;
ll tim;
 
void dfs1(ll u, ll par){
    tim++;
    low[u]=tim;
    disc[u]=tim;
    fa(i,v[u]) if(i.first!=par){
        if(!disc[i.first]){
            dfs1(i.first,u);
            if(disc[u]<low[i.first]) br.insert(i.second);
            low[u]=min(low[u],low[i.first]);
        }
        else low[u]=min(low[u],disc[i.first]);
    }
}
 