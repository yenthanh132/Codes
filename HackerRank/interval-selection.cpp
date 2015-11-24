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

const int maxn=1007;

int dp[maxn], last[maxn];
pii a[maxn];
bool mark[maxn];

bool cmp(const pii &a, const pii &b){
    return a.second<b.second;
}

int main(){
    //freopen("input.txt","r",stdin);
    int T,n;
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].first,&a[i].second);
        sort(a+1,a+n+1,cmp);
        int res=0;
        for(int i=1; i<=n; ++i){
            dp[i]=1; last[i]=-oo;
            for(int j=i-1; j>=1; --j)
                if(last[j] < a[i].first)
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        if(a[j].second < a[i].first) last[i] = last[j];
                        else last[i] = a[j].second;
                    }else if(dp[i] == dp[j] + 1){
                        int newlast;
                        if(a[j].second < a[i].first) newlast = last[j];
                        else newlast = a[j].second;
                        if(newlast < last[i]) last[i] = newlast;
                    }
            res = max(res, dp[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
