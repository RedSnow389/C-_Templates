int main(){
    ll n,q,i,j;
    cin>>n>>q;
    ll a[n],mn[n][20];
    fr(i,n) cin>>a[i],mn[i][0]=a[i];
    fr(j,20) if(j){
        fr(i,n) if(i+(1<<(j-1))<n) mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        else mn[i][j]=mn[i][j-1];
    }
    while(q--){
        ll a,b;
        cin>>a>>b;
        ll ml=31-__builtin_clz(b-a); 
        cout<<min(mn[a][ml],mn[b-(1<<ml)][ml])<<endl;
    }
}