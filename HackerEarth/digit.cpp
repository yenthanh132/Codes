#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int LIMIT=30000;
ll A,B,X,Y,K;

ll dp[14][2][118][LIMIT];
ll a[14],p10[14];
int cnt;

ll get(int i, int smaller, int sumDigit, int sumVal){
    if(sumDigit>Y) return 0;
    if(i==-1) return (X<=sumDigit && sumDigit<=Y && sumVal==0);
    if(dp[i][smaller][sumDigit][sumVal]!=-1) return dp[i][smaller][sumDigit][sumVal];
    ll &res = dp[i][smaller][sumDigit][sumVal]; res=0;

    int vtop=a[i];
    if(smaller) vtop=9;

    for(int v=0; v<=vtop; ++v)
        res += get(i-1,smaller|(v<a[i]), sumDigit+v, (sumVal*10+v)%K);

    return res;
}

ll dem(ll v){
    if(v==0) return 0;
    cnt=0;
    while(v){
        a[cnt++]=v%10;
        v/=10;
    }

    reset(dp,-1);
    return get(cnt-1,0,0,0);
}

int countDigit(ll v){
    int res=0;
    while(v){
        res+=v%10;
        v/=10;
    }
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);

    p10[0]=1;
    for(int i=1; i<=13; ++i) p10[i]=p10[i-1]*10;

    cin>>A>>B>>X>>Y>>K;
    if(K<=LIMIT){
        cout<<dem(B)-dem(A-1)<<endl;
    }else{
        //brute
        ll v=((A-1)/K+1)*K;
        int res=0;
        while(v<=B){
            //cout<<v<<endl;
            int c = countDigit(v);
            if(X <= c && c <= Y) ++res;
            v+=K;
        }
        cout<<res<<endl;
    }
}

