pair<ll,string> dp[20][2][2][2];// len, under, over, started
ll a[20], b[20];

// max product of digits

pair<ll,string> digitdp(ll pos, bool under, bool over, bool started){
    if(dp[pos][under][over][started].f1!=-1) return dp[pos][under][over][started];
    ll ub=9, lb=0, i, ans=-1;
    string retstr;
    if(under) lb=a[pos];
    if(over) ub=b[pos];
    if(pos==19) return mp(ub,to_string(ub));
    for(i=lb;i<=ub;i++){
        if(i!=0 || started){
            auto ans1=digitdp(pos+1,under&(i==a[pos]),over&(i==b[pos]),1);
            if(ans1.f1*i>ans) ans=ans1.f1*i, retstr=to_string(i)+ans1.f2; 
        }
        else{
            auto ans1=digitdp(pos+1,under&(i==a[pos]),over&(i==b[pos]),0);
            if(ans1.f1>ans) ans=ans1.f1, retstr=ans1.f2; 
        }
    }
    return dp[pos][under][over][started]=mp(ans,retstr);
}

string helper(ll n1, ll n2){
    ll i,j,k,l;
    for(i=19;i>=0;i--){
        a[i]=n1%10;
        n1/=10;
        b[i]=n2%10;
        n2/=10;
    }
    fr(i,20) fr(j,2) fr(k,2) fr(l,2) dp[i][j][k][l]=mp(-1,"");
    return digitdp(0,1,1,0).f2;
}

// sum of digits%k==0

ll k, dp[10000][101][2];
string a;
 
ll digitdp(ll pos, ll sumth, bool tillb){
    if(dp[pos][sumth][tillb]!=-1) return dp[pos][sumth][tillb];
    ll ub,i,ans=0;
    if(tillb) ub=(a[pos]-'0');
    else ub=9;
    for(i=0;i<=ub;i++){
        if(pos==a.size()-1){
            if((sumth+i)%k==0) ans++;    
        }
        else{
            (ans+=digitdp(pos+1,(sumth+i)%k,tillb&(i==ub)))%=mod;
        }
    }
    return dp[pos][sumth][tillb]=ans;
}
 
ll solvedp(string &a){
    memset(dp,-1,sizeof(dp));
    return digitdp(0,0,1);
}
