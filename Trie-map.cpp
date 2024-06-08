struct trie{
    map<ll, map<char, ll>> next;
    ll nextEmptyState;
    vll val;
 
    trie(){
        nextEmptyState = 1;
        val = {0};
    }
 
    void insert(string &s){
        ll curr = 0;
        ll n = (ll)s.size();
        rep(i,0,n){
            if(!next[curr].count(s[i])){
                next[curr][s[i]] = nextEmptyState;
                nextEmptyState++;
                val.PB(0);
            }
            curr = next[curr][s[i]];
            if(curr != 0) val[curr]++;
        }
    }
 
    ll query(string &s){
        ll res = 0;
        ll n = (ll)s.size();
        ll curr = 0;
        rep(i,0,n){
            if(!next[curr].count(s[i])){
                return  res;
            }
            curr = next[curr][s[i]];
            res += val[curr];
        }
        return res;
    }
};
 