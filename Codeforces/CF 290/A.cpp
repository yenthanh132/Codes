#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<int> e[26];
int res[27],n,cnt;
string s[111];
bool inDFS[27],free1[27];
bool foundCir;

void dfs(int u){
    if(foundCir) return;
    free1[u]=0;
    inDFS[u]=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(free1[v]) dfs(v);
        else if(inDFS[v]){
            foundCir=1;
            return;
        }
    }
    inDFS[u]=0;
    res[cnt--]=u;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>s[i];
    for(int i=1; i<n; ++i){
        int j;
        for(j=0; j<min(sz(s[i]),sz(s[i+1])); ++j)
            if(s[i][j]!=s[i+1][j]){
                e[s[i][j]-'a'].pb(s[i+1][j]-'a');
                break;
            }
        if(j>=sz(s[i+1])){
            puts("Impossible");
            return 0;
        }
    }
    foundCir=0;
    reset(inDFS,0); reset(free1,1);
    cnt=26;
    for(int i=0; i<26; ++i) if(free1[i]){
        dfs(i);
        if(foundCir) break;
    }
    if(foundCir){
        puts("Impossible");
        return 0;
    }
    for(int i=1; i<=26; ++i) putchar('a'+res[i]);
}

