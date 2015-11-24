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
int T,a[maxn],N,S;
int dp[maxn][maxn];
map<string,int> mm;

int main(){
    //freopen("input.txt","r",stdin);
    cin>>T;
    for(int tt=0; tt<T; ++tt){
        mm.clear();
        string s;
        cin>>S; getline(cin,s);
        for(int i=1; i<=S; ++i) getline(cin,s), mm[s]=i;
        cin>>N; getline(cin,s);
        for(int i=1; i<=N; ++i) getline(cin,s), a[i]=mm[s];
        for(int j=1; j<=S; ++j) dp[1][j]=(j!=a[1])?0:oo;
        int res = oo;
        for(int i=2; i<=N; ++i){
            int minv;
            minv=oo;
            for(int j=1; j<=S; ++j) minv=min(minv,dp[i-1][j]);

            for(int j=1; j<=S; ++j)
                if(j==a[i]) dp[i][j]=oo;
                else
                    dp[i][j]=min(dp[i-1][j],minv+1);

        }
        if(N==0) res = 0;
        else
            for(int j=1; j<=S; ++j) res=min(res,dp[N][j]);
        cout<<res<<endl;
    }
    return 0;
}
