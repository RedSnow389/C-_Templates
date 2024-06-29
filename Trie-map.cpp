struct trie{
    map<ll, map<char, ll> > next;
    ll nextEmptyState;
    vl val;
 
    trie(){
        nextEmptyState=1;
        val={0};
    }
 
    void insert(string &s){
        ll curr=0, n=s.size();
        fr(i,n){
            if(!next[curr].count(s[i])){
                next[curr][s[i]]=nextEmptyState;
                nextEmptyState++;
                val.eb(0);
            }
            curr=next[curr][s[i]];
            if(curr) val[curr]++;
        }
    }
 
    ll query(string &s){
        ll curr=0, n=s.size(), res=0;
        fr(i,n){
            if(!next[curr].count(s[i])) return res;
            curr=next[curr][s[i]];
            res+=val[curr];
        }
        return res;
    }
};
 