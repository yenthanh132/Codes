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

const int maxn=200007;

int n,m;
int a[maxn],b[maxn],pre[maxn], ja[maxn],ka[maxn];

bool equal(int j, int i, int *s){
    if(ja[j]!=0 && s[i-ja[j]] >= s[i]) return 0;
    if(ka[j]!=0 && s[i-ka[j]] <= s[i]) return 0;
    return 1;
}

set<int> mys;
int pos[maxn];

void init(){
    mys.clear();
    for(int i=1; i<=n; ++i){
        mys.insert(a[i]);
        pos[a[i]]=i;
        set<int>::iterator it = mys.lower_bound(a[i]);
        if(it!=mys.begin()){
            --it;
            ja[i]=i-pos[*it];
        }else ja[i]=0;
    }

    mys.clear();
    for(int i=1; i<=n; ++i){
        mys.insert(a[i]);
        pos[a[i]]=i;
        set<int>::iterator it = mys.lower_bound(a[i]+1);
        if(it!=mys.end()){
            ka[i]=i-pos[*it];
        }else ka[i]=0;
    }

    int i=1, j=0;
    pre[1]=0;
    while(i<=n){
        while(j>0 && !equal(j,i,a)) j=pre[j];
        ++i; ++j;
        pre[i]=j;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int v;
    for(int i=1; i<=n; ++i){
        scanf("%d",&v);
        a[v]=i;
    }
    for(int i=1; i<=m; ++i){
        scanf("%d",&v);
        b[v]=i;
    }

//    for(int i=1; i<=n; ++i) a[i]=i;
//do{

    init();
    //for(int i=1; i<=n; ++i) cout<<a[i]<<' '; cout<<endl;
    //for(int i=1; i<=m; ++i) cout<<b[i]<<' '; cout<<endl;
    int i=1, j=1;
    int res = 0;
    while(i<=m){
        while(j>0 && !equal(j,i,b)) j=pre[j];
        ++i; ++j;
        if(j>n){
            ++res;
            //cout<<i-3<<' ';
            j=pre[j];
        }
    }

    cout<<res<<endl;

//}while(next_permutation(a+1,a+n+1));

    return 0;

}
