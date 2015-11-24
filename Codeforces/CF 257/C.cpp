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

const int maxn=100007;

int n;
vector<int> p[maxn];
bool mark[maxn];
int pos[maxn],val[maxn];
vector<int> num[maxn];

bool cmp(const int &a, const int &b){
    return sz(num[a])<sz(num[b]);
}

bool cmp2(const int &a, const int &b){
    return val[a]<val[b];
}

vector<pii> res;

int main(){
    cin>>n;
    val[1]=oo;
    for(int i=2; i<=n; ++i){
        int v=i;
        val[i]=0;
        for(int j=2; j*j<=v; ++j) if(v%j==0){
            p[i].pb(j);
            val[i]++;
            num[j].pb(i);
            while(v%j==0) v/=j;
        }
        if(v>1){
            val[i]++;
            p[i].pb(v);
            num[v].pb(i);
        }
    }
    for(int i=1; i<=n; ++i) pos[i]=i;
    reset(mark,1);

    sort(pos+1,pos+n+1,cmp);
    for(int i=1; i<=n; ++i){
        int id=pos[i];
        if(sz(num[id])<2) continue;
        sort(num[id].begin(),num[id].end(),cmp2);
        int last=-1;
        for(int j=0; j<sz(num[id]); ++j){
            int x=num[id][j];
            if(!mark[x]) continue;
            if(last==-1) last=x;
            else{
                mark[last]=mark[x]=0;
                res.pb(pii(last,x));
                last=-1;
            }
        }
    }

    printf("%d\n",sz(res));
    for(int i=0; i<sz(res); ++i) printf("%d %d\n",res[i].first, res[i].second);

    return 0;
}
