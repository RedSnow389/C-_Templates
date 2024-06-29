class suffixarray{
    public:
    ll n;
    string s;
    vl ind; // ind stores perm after sorting, ec stores eq classes of sorted suffixes
    vl lcp; // lowest common prefix, lcp[i] is the lcp of i and i-1 

    suffixarray(string& s1){
        ll i;
        s=s1+'$'; // to eliminate tiebrekers, ascii of $<a
        n=s.size();
        ind.rs(n);
        vl ec(n);
        //k==0 case
        vector<pair<char,ll> > a(n);
        fr(i,n){
            a[i].f1=s[i];
            a[i].f2=i;
        }
        sort(all(a));
        fr(i,n) ind[i]=a[i].f2;
        fr(i,n) if(i){
            if(a[i].f1==a[i-1].f1) ec[ind[i]]=ec[ind[i-1]];
            else ec[ind[i]]=ec[ind[i-1]]+1;
        }
        vl pos(n), new_ind(n), new_ec(n), cnt(n);
        // other k, going from k to k+1
        for(ll k=0;(1<<k)<n;k++){
            fr(i,n) ind[i]=(ind[i]-(1<<k)+n)%n;
            //radix sort on first halfs, second halfs already sorted
            cnt.assign(n,0);
            fa(i,ec) cnt[i]++;
            pos[0]=0;
            fr(i,n) if(i) pos[i]=pos[i-1]+cnt[i-1];
            fa(i,ind){
                new_ind[pos[ec[i]]]=i;
                pos[ec[i]]++;
            }
            ind=new_ind;
            // done
            fr(i,n) if(i){ // half is of length k 
                if(mp(ec[ind[i-1]],ec[(ind[i-1]+(1<<k))%n])==mp(ec[ind[i]],ec[(ind[i]+(1<<k))%n])) new_ec[ind[i]]=new_ec[ind[i-1]];
                else new_ec[ind[i]]=new_ec[ind[i-1]]+1;
            }
            ec=new_ec;
        }
        // now ec is also the postion of each index in the suffix array 
        lcp.rs(n);
        ll k=0;
        fr(i,n-1){
            while(s[i+k]==s[ind[ec[i]-1]+k]) k++;
            lcp[ec[i]]=k;
            k=max(k-1,0ll);
        }
    }
};

int main(){
    string s;
    cin>>s;
    suffixarray sa(s);
}