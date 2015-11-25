#include <iostream>
#include <algorithm>
#include <cstdio>
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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 1001
int n,prime[]={1,2,3,5,7,11,13,17,19,21};
ll res,f[maxn][10];

ll mul(double a, double b){
    if (a*b<oo) return(ll(a*b)); else return(oo);
}

ll min(ll a,ll b){return(a<b?a:b);}

ll pow(int a,int b){
    ll res=1;
    FOR(i,1,b){
        if(mul(res,a)==oo) return oo;
        res*=a;
    }
    return res;
}

void optimize(){
    int i,j,k;
    for(i=1;i<=n;i++) for(j=1;j<=9;j++) f[i][j]=oo;
    for(i=1;i<=n;i++) f[i][1]=pow(prime[1],i-1);
    for(j=2;j<=9;j++)
        for(i=1;i<=n;i++){
            f[i][j]=oo;
            for(k=1;k<=n;k++) 
                if (i%k==0 && pow(prime[j],k-1)!=oo && f[i/k][j-1]!=oo && mul(f[i/k][j-1],pow(prime[j],k-1))!=oo)
                    f[i][j]=min(f[i][j],f[i/k][j-1]*pow(prime[j],k-1));
        }
}

int main(){
    cin>>n;
    optimize();
    res=oo;
    for(int i=1;i<=9;i++) res=min(res,f[n][i]);
    cout<<res;
    return 0;
}
    
