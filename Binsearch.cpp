l=0, r=n+1;
while(good(a,n,k,r)) r*=2;
while(r>l+1){
    mid=(l+r)/2;
    if(good(a,n,k,mid)) l=mid;
    else r=mid;
}
cout<<l
// for finding max val
l=-1, r=n;
while(!good(a,n,k,r)) r*=2;
while(r>l+1){
    mid=(l+r)/2;
    if(good(a,n,k,mid)) r=mid;
    else l=mid;
}
cout<<r
// for finding min val