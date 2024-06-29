vvl aut;

vl prefix_fn(string &s){
    ll n=s.size(),i;
    vl pi(n);
    fr(i,n) if(i){
        pi[i]=pi[i-1];
        while(pi[i] && s[i]!=s[pi[i]]) pi[i]=pi[pi[i]-1];
        if(s[i]==s[pi[i]]) pi[i]++;
    }
    return pi;
}
void compute_automaton(string s){
    s+='#';
    ll n=s.size(),i,j;
    aut.assign(n, vl(26));
    vl pi=prefix_fn(s);
    fr(i,n) fr(j,26) if (i && 'a'+j!=s[i]) aut[i][j] = aut[pi[i-1]][j];
    else aut[i][j]=i+('a'+j==s[i]);
}


// kmp to check existence of t in s
ll m=t.size(), n=s.size();
// t#s
ll j = 0;
fr(i,n){
    while(j>=0 && t[j]!=s[i]) if(j) j=pi[j-1];
    else j=-1;
    j++;
    if(j==m){
        j=pi[j-1];
        // pattern found in string s at position i-m+1
    }
}   
// after each loop we have j=longest common suffix of s[0..i] which is also prefix of p

