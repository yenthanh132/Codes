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

const int maxn=2007;

int a[maxn][maxn],b[maxn][maxn];
int m,n,mys[maxn],last,L[maxn],R[maxn],H[maxn];

int calc(int M, int N, int extH, int extW){
    int res=1;
    for(int i=1; i<=M; ++i){
        for(int j=1; j<=N; ++j) if(i>1 && b[i-1][j]==b[i][j]) H[j]++; else H[j]=1;
        last=0;
        int lbound=0;
        for(int j=1; j<=N; ++j){
            if(j>1 && b[i][j-1]!=b[i][j]) last=0, lbound=j-1;
            while(last>0 && H[mys[last]] >= H[j]) --last;
            if(last>0) L[j]=mys[last]; else L[j]=lbound;
            mys[++last]=j;
        }
        int rbound=N+1;
        for(int j=N; j>=1; --j){
            if(j<N && b[i][j+1]!=b[i][j]) last=0, rbound=j+1;
            while(last>0 && H[mys[last]] >= H[j]) --last;
            if(last>0) R[j]=mys[last]; else R[j]=rbound;
            mys[++last]=j;
        }

        for(int j=1; j<=N; ++j) if(b[i][j]!=oo){
            int h = H[j];
            int w = R[j]-L[j]-1;
            h+=extH; w+=extW;
            int e=min(h,w);
            res=max(res,e*e);
        }
    }
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d",&m,&n),m>0){
        for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) scanf("%d",&a[i][j]);
        int res=1;
        //h
        for(int i=1; i<m; ++i) for(int j=1; j<n; ++j){
            if(a[i][j]-a[i][j+1]==a[i+1][j]-a[i+1][j+1] && a[i][j]==a[i+1][j]) b[i][j]=a[i][j]-a[i][j+1];
            else b[i][j]=oo;
        }
        res=max(res,calc(m-1,n-1,+1,+1));
        //v
        for(int i=1; i<m; ++i) for(int j=1; j<n; ++j){
            if(a[i][j]-a[i+1][j]==a[i][j+1]-a[i+1][j+1] && a[i][j]==a[i][j+1]) b[i][j]=a[i][j]-a[i+1][j];
            else b[i][j]=oo;
        }
        res=max(res,calc(m-1,n-1,+1,+1));
        //d
        for(int i=1; i<m; ++i) for(int j=1; j<n; ++j){
            int v1=a[i][j]-a[i+1][j];
            int v2=a[i][j]-a[i][j+1];
            int v3=a[i][j]-a[i+1][j+1];
            if(v1==v2 && v1*2==v3) b[i][j]=v1;
            else b[i][j]=oo;
        }
        res=max(res,calc(m-1,n-1,+1,+1));

        //d2
        for(int i=1; i<m; ++i) for(int j=1; j<n; ++j){
            int v1=a[i+1][j]-a[i][j];
            int v2=a[i+1][j]-a[i+1][j+1];
            int v3=a[i+1][j]-a[i][j+1];
            if(v1==v2 && v1*2==v3) b[i][j]=v1;
            else b[i][j]=oo;
        }
        res=max(res,calc(m-1,n-1,+1,+1));

        printf("%d\n",res);
    }
}
