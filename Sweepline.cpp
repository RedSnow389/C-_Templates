sort(v.begin(),v.end()); //pq swwepline
priority_queue<pll, vpll, greater<pll> > pq;
fr(i,n){
    while(pq.size() && pq.top().f1<v[i].f1){
        if(pq.top().f1==m) cmx--;
        if(pq.top().f2) cmn--;
        pq.pop();
    }
    if(v[i].f2==m) cmx++;
    if(v[i].f1==1) cmn++;
    pq.push(mp(v[i].f2,v[i].f1==1));
    ans=max(ans,(ll)pq.size()-min(cmn,cmx))
}

ll n,i,q; //capygrad
cin>>n;
vvl v(n, vl(4));
fr(i,n) cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3]; //l,r,a,b
sort(all(v));
ll op=-inf,bm=0;
map<ll,ll> m;
fr(i,n){
    if(v[i][0]>bm){
        m[op]=bm;
        op=v[i][0];
        bm=v[i][3];
    }
    bm=max(bm,v[i][3]);
}
m[op]=bm;
cin>>q;
while(q--){
    ll x;
    cin>>x;
    auto it=--m.upper_bound(x);
    cout<<max((*it).f2,x)<<' ';
}
cout<<endl;