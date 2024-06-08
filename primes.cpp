ll N=1e6+1;
vector<bool> seiv(N,1);
vl primes;

ll i,j;
for(i=2;i<N;i++){
    if(!seiv[i]) continue;
    for(j=2*i;j<N;j+=i) seiv[j]=0;
}
for(i=2;i<N;i++) if(seiv[i]) primes.eb(i);
