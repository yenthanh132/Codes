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

const int maxn=(1<<20)+7;
const int maxk=20;

ll p2[maxn],f[maxn];

int n;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    int v;
    for(int i=1; i<=n; ++i){
        scanf("%d",&v);
        f[v]++;
    }
    for(int k=0; k<20; ++k){
        for(int v=(1<<20)-1; v>=0; --v)
            if(!(v>>k&1)) f[v]=(f[v]+f[v|(1<<k)])%oo;
    }
    p2[0]=1;
    for(int v=1; v<=1000000; ++v) p2[v]=p2[v-1]*2%oo;
    ll res=-1;
    for(int v=0; v<=1<<20; ++v){
        int cbit=0;
        for(int k=0; k<20; ++k) if(v>>k&1) ++cbit;
        res=(res + (cbit&1?-1:1)*p2[f[v]])%oo;
    }
    res=(res+oo)%oo;
    cout<<res<<endl;
    return 0;
}
