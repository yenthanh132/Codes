#include <conio.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=5007;

string s,st;
int a[maxn],n,sum[maxn];
ll cnt[maxn],dp[maxn];

int main(){
    //freopen("test.txt","r",stdin);
    cin>>s;
    n=0;
    while(s!="0"){
        a[++n]=(s[sz(s)-1]-'0')&1;
        st="";
        int t=0;
        REP(i,sz(s)){
            t=t*10+s[i]-'0';
            st+=char(t/2+'0');
            t%=2;
        }
        while(sz(st)>1 && st[0]=='0') st.erase(0,1);
        s=st;
    }
    sum[0]=0;
    FOR(i,1,n){
        sum[i]=sum[i-1];
        if(!a[i]) sum[i]+=((i&1)?1:2);
    }
    cnt[0]=1;
    dp[0]=0;
    
    FOR(i,1,n){
        dp[i]=dp[i-1];
        cnt[i]=cnt[i-1];
        if(a[i]==1) dp[i]+=((i&1)?1:2);
        int v;
        if(i&1) continue;
        FORD(j,i-1,1){
            v=1;
            if(j&1) v+=1; else continue;
            v+=sum[i]-sum[j-1];
            v+=dp[j-1];
            if(dp[i]>v){
                dp[i]=v;
                cnt[i]=cnt[j-1];   
            }else if(dp[i]==v){
                cnt[i]=(cnt[i]+cnt[j-1])%oo;
            }
        }
    }
    //cout<<dp[n]<<endl;
    cout<<cnt[n]<<endl;
    //getch();
    return 0;
}
