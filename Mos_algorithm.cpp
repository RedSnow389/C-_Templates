vl v,cnt;
ll n,B,ans=0,i,q;

bool comp(pair<pll,ll> a, pair<pll,ll> b){
    if(a.f1.f1/B<b.f1.f1/B) return 1;
    if(a.f1.f1/B>b.f1.f1/B) return 0;
    return a.f1.f2<b.f1.f2;
}

void rem(ll ind){
    ans-=cnt[ind]*cnt[ind]*ind;
    cnt[ind]--;
    ans+=cnt[ind]*cnt[ind]*ind;
}

void add(ll ind){
    ans-=cnt[ind]*cnt[ind]*ind;
    cnt[ind]++;
    ans+=cnt[ind]*cnt[ind]*ind;
}

int main(){
    fastio
    cin>>n>>q;
    B=sqrt(n);
    v.rs(n);
    cnt.rs(1e6+1);
    fa(i,v) cin>>i;
    vector<pair<pll,ll> > qu(q);
    vl qans(q);
    fr(i,q) cin>>qu[i].f1.f1>>qu[i].f1.f2, qu[i].f2=i;
    sort(all(qu),comp);
    ll mor=-1, mol=0;
    fa(i,qu){
        ll l=i.f1.f1, r=i.f1.f2;
        l--,r--;
        while(mor>r){
            rem(v[mor]);
            mor--;
        }
        while(mor<r){
            mor++;
            add(v[mor]);
        }
        while(mol>l){
            mol--;
            add(v[mol]);
        }
        while(mol<l){
            rem(v[mol]);
            mol++;
        }
        qans[i.f2]=ans;
    }
    fa(i,qans) cout<<i<<' ';
}