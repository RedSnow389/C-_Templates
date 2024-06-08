vvl matmul(vvl a, vvl b){
	ll n=a.size(),i,j,k;
	vvl c(n, vl(n));
	fr(i,n) fr(j,n) fr(k,n) (c[i][j]+=a[i][k]*b[k][j])%=mod;
	return c;
}
 
vvl matexp(vvl a, ll x){
	ll i,j,n=a.size();
	if(x==0){
		vvl c(n, vl(n));
		fr(i,n) fr(j,n) if(i==j) c[i][j]=1;
		return c;
	}
	vvl c=exp(a,x/2);
	if(x%2) return mul(c,mul(c,a));
	return mul(c,c);
}