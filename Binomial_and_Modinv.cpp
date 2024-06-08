const ll N=1e6;

vl fac(N+1);
vl inv(N+1);

ll bp(ll a, ll b){
    if(!b) return 1;
    ll x=bp(a,b/2);
    if(b%2) return (((a*x)%mod)*x)%mod;
    return (x*x)%mod;
}

ll mi(ll a){
    return bp(a,mod-2);
}

ll bincoe(ll a, ll b){
    if(a<b) return 0;
    return (((fac[a]*inv[a-b])%mod)*inv[b])%mod;
}

void computefac(){
    ll i;
    fac[0]=1;
    fr(i,N+1) if(i) fac[i]=(fac[i-1]*i)%mod;
    inv[N]=mi(fac[N]);
    for(i=N-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%mod;
}
