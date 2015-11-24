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
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=5007;

int a[maxn],n,f[maxn][maxn],c[maxn];


int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i], a[i]++;
    int sum=0;
    FOR(i,1,n) FOR(j,1,i-1) if(a[j]>a[i]) ++sum;

    reset(c,0);
    FOR(i,1,n){
        int s=0;
        c[a[i]]++;
        FOR(v,1,n){
            s+=c[v];
            f[i][v]=s;
        }
    }

    int best=sum, cnt=0;

    FOR(i,1,n-1) FOR(j,i+1,n){
        int u=a[i], v=a[j];
        int tmp=sum;
        int len=j-i-1;
        if(u<v) ++tmp; else --tmp;
        tmp -= len - (f[j-1][v]-f[i][v]);
        tmp -= f[j-1][u-1]-f[i][u-1];
        tmp += len - (f[j-1][u]-f[i][u]);
        tmp += f[j-1][v-1]-f[i][v-1];
        if(best>tmp){
            best=tmp;
            cnt=1;
        }else if(best==tmp)
            ++cnt;

    }
    cout<<best<<' '<<cnt<<endl;
    return 0;
}

