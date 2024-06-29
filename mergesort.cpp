vl a;

void mg(ll l, ll mid, ll r){
    ll i=l, j=mid+1;
    vl c;
    while(i<=mid && j<=r){
        if(a[i]<a[j]) ans[a[i]]+=r-j+1, c.eb(a[i]), i++;
        else c.eb(a[j]), j++;
    }
    while(i<=mid) c.eb(a[i]), i++;
    while(j<=r) c.eb(a[j]), j++;
    i=l;
    reverse(all(c));
    while(c.size()) a[i]=c.back(), c.pop_back(), i++;
}

void msort(ll l, ll r){
    if(l==r) return;
    ll mid=(l+r)/2;
    msort(l,mid);
    msort(1+mid,r);
    mg(l,mid,r);
}

int main(){
    fastio
    ll n,i;
    cin>>n;
    a.rs(n);
    fr(i,n) cin>>a[i];
    msort(0,n-1);
}