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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

string s[maxn],des;
int n,dp[maxn],len,match[maxn];
bool ok[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>s[i];
    cin>>des;
    len=sz(des);

    sort(s+1,s+n+1);

    for(int i=1; i<=len+1; ++i) dp[i]=i;

    for(int i=1; i<=n; ++i){
        ok[i]=1;
        for(int j=0; j<sz(s[i]); ++j) if(s[i][j]!=des[j]){
            ok[i]=0;
            match[i]=j;
            break;
        }
        if(ok[i]){
            match[i]=sz(s[i]);
            dp[sz(s[i])] = min(dp[sz(s[i])], i);
        }
    }


    for(int i=1; i<=len; ++i){
        dp[i+1] = min(dp[i+1], dp[i]+1);
        int j=1;
        while(j<=n && match[j]<i) ++j;
        int c=1;
        while(j<=n && match[j]>=i){
            if(ok[j]) dp[sz(s[j])] = min(dp[sz(s[j])], dp[i]+c);
            ++j; ++c;
        }
    }
    cout<<dp[len+1]<<endl;
}
