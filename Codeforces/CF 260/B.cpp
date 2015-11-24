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

const int maxn=500007;

int e[maxn][26],win[maxn],lose[maxn];
int cnt,n,k;
char s[maxn];

void dfs(int u){
    win[u] = 0;
    for(int v=0; v<26; ++v)
        if(e[u][v]!=-1){
            int u2=e[u][v];
            dfs(u2);
            if(!win[u2]) win[u]=1;
        }
}

void dfs2(int u){
    lose[u] = 0;
    bool found = 0;
    for(int v=0; v<26; ++v)
        if(e[u][v]!=-1){
            found = 1;
            int u2=e[u][v];
            dfs2(u2);
            if(!lose[u2]) lose[u]=1;
        }
    if(!found) lose[u]=1;
}

int main(){
    //freopen("input.txt","r",stdin);
    cnt = 1;
    reset(e,-1);
    scanf("%d%d",&n,&k);

    for(int i=0; i<n; ++i){
        scanf("%s",&s);
        int len = strlen(s);
        int p = 1;
        for(int j=0; j<len; ++j){
            int v = s[j]-'a';
            if(e[p][v]==-1){
                e[p][v] = ++cnt;
            }
            p=e[p][v];
        }
    }

    dfs(1);
    dfs2(1);
    if(win[1] && ((k&1) || lose[1])) puts("First");
    else puts("Second");
}
