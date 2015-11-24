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

const int maxn=307;

int a[maxn][maxn],n, f[maxn*2][maxn][maxn];
vector<int> arr[maxn*2];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) scanf("%d",&a[i][j]);
    for(int j=1; j<=n; ++j) for(int i=1; i<=n; ++i)
        arr[i+j-1].pb(a[i][j]);
    for(int i=1; i<2*n; ++i){

        int m=sz(arr[i]);
        //for(int j=0; j<m; ++j) cout<<arr[i][j]<<' '; cout<<endl;
        for(int j1=0; j1<m; ++j1) for(int j2=j1; j2<m; ++j2){
            f[i][j1][j2]=-oo;
        }
    }
    f[1][0][0]=arr[1][0];
    for(int i=1; i<2*n-1; ++i){
        int m=sz(arr[i]);
        for(int j1=0; j1<m; ++j1) for(int j2=j1; j2<m; ++j2){
            int vl,vr;
            if(i<n){ vl=0; vr=1; }
            else {vl=-1; vr=0; }
            for(int k1=j1+vl; k1<=j1+vr; ++k1) for(int k2=j2+vl; k2<=j2+vr; ++k2)
                if(k2>=k1 && 0<=k1 && k1<sz(arr[i+1]) && 0<=k2 && k2<sz(arr[i+1]))
                {
                    int v=arr[i+1][k1];
                    if(k2>k1) v+=arr[i+1][k2];
                    f[i+1][k1][k2]=max(f[i+1][k1][k2], f[i][j1][j2]+v);
                }
        }
    }

    printf("%d\n",f[2*n-1][0][0]);

    return 0;
}
