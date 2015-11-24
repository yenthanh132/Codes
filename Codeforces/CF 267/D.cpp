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

typedef long long ll;
typedef pair<ll,ll> pii;


const int maxn=500007;

map<string,int> mm;
int n,m,cnt;
char buf[maxn];
vector<int> e[maxn];
int pos[maxn];
pii val[maxn];
bool free1[maxn];
int id[maxn];

pii get(string s){
    pii x=pii(0,0);
    for(int i=0; i<sz(s); ++i) if(s[i]=='R') x.first++;
    x.second = sz(s);
    return x;
}

bool cmp(const int &a, const int &b){
    return val[a]<val[b];
}

void dfs(int u, pii &value){
    free1[u]=0;
    val[u]=value;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(free1[v]) dfs(v,value);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&m);
    cnt = 0;
    for(int i=1; i<=m; ++i){
        scanf("%s",buf);
        int len=strlen(buf);
        for(int i=0; i<len; ++i) if(buf[i]>='a') buf[i]=buf[i]-'a'+'A';
        string s=string(buf,buf+len);
        if(mm[s]==0){
            mm[s]=++cnt;
            val[cnt]=get(s);
        }
        pos[i]=mm[s];
    }

    scanf("%d",&n);
    for(int i=0; i<n; ++i){
        scanf("%s",buf);
        int len=strlen(buf);
        for(int i=0; i<len; ++i) if(buf[i]>='a') buf[i]=buf[i]-'a'+'A';
        string s1=string(buf,buf+len);
        scanf("%s",buf);
        len=strlen(buf);
        for(int i=0; i<len; ++i) if(buf[i]>='a') buf[i]=buf[i]-'a'+'A';
        string s2=string(buf,buf+len);
        if(mm[s1]==0){
            mm[s1]=++cnt;
            val[cnt]=get(s1);
        }
        if(mm[s2]==0){
            mm[s2]=++cnt;
            val[cnt]=get(s2);
        }
        e[mm[s2]].pb(mm[s1]);
    }

    reset(free1,1);
    for(int i=1; i<=cnt; ++i) id[i]=i;
    sort(id+1,id+cnt+1,cmp);
    for(int i=1; i<=cnt; ++i){
        int u=id[i];
        if(free1[u]) dfs(u,val[u]);
    }

    pii res=pii(0,0);
    for(int i=1; i<=m; ++i){
        res.first += val[pos[i]].first;
        res.second += val[pos[i]].second;
    }
    cout<<res.first<<' '<<res.second<<endl;

    return 0;
}
