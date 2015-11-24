
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

int n,res[maxn],val[maxn];
int a[maxn];
int plist[maxn],cnt;
int ok[maxn],f[maxn][1<<17],trace[maxn][1<<17],num[maxn][1<<17];

bool isprime(int n){
    if(n<2) return 0;
    for(int i=2; i*i<=n; ++i) if(n%i==0) return 0;
    return 1;
}

bool getmin(int &a, int v){
    if(a==-1 || a>v){
        a=v;
        return 1;
    }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    cnt=0;
    for(int i=2; i<=59; ++i) if(isprime(i)) plist[cnt++]=i;
    //cout<<cnt<<endl;
    for(int v=1; v<=59; ++v){
        ok[v]=0;
        for(int j=0; j<cnt; ++j) if(v%plist[j]==0) ok[v]|=1<<j;
    }
    int N=n;
    reset(f,-1);
    f[0][0]=0;
    for(int i=1; i<=n; ++i) for(int j=0; j<(1<<cnt); ++j) if(f[i-1][j]!=-1){
        for(int v=1; v<=59; ++v) if(!(ok[v]&j))
            if(getmin(f[i][j|ok[v]],f[i-1][j] + abs(v-a[i]))){
                trace[i][j|ok[v]]=j;
                num[i][j|ok[v]]=v;
            }
    }
    int u=-1;
    for(int j=0; j<(1<<cnt); ++j) if(u==-1 || (f[n][j]!=-1 && f[n][j]<f[n][u])) u=j;

    for(int i=n; i>=1; --i){
        res[i]=num[i][u];
        u=trace[i][u];
    }
    for(int i=1; i<=N; ++i) cout<<res[i]<<' ';
    return 0;
}
