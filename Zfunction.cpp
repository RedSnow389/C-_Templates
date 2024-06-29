ll n=s.size(), l=0, r=0;
vl z(n);
fr(i,n) if(i){
    if(i<r) z[i]=min(r-i,z[i-l]);
    while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
    if(i+z[i]>r) l=i, r=i+z[i];
}