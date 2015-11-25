#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
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
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 201

int n,m,d[maxn],matchx[maxn],matchy[maxn];
vector<int> a[maxn];

bool findpath(){
    queue<int> myqueue;
    for(int i=1;i<=n;i++)
        if (matchx[i]==0) d[i]=0, myqueue.push(i); else d[i]=oo;
    d[0]=oo;
    while (!myqueue.empty()){
        int u=myqueue.front(); myqueue.pop();
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i];
            if (d[matchy[v]]==oo){
                d[matchy[v]]=d[u]+1;
                if (matchy[v]!=0) myqueue.push(matchy[v]);
            }
        }
    }
    return (d[0]!=oo);
}

bool dfs(int u){
    if (u==0) return 1;
    for(int i=0; i<a[u].size();i++){
        int v=a[u][i];
        if (d[matchy[v]]==d[u]+1 && dfs(matchy[v])){
            matchx[u]=v; 
            matchy[v]=u;
            return 1;
        }
    }
    d[u]=oo; 
    return 0;
}

//#include <conio.h>
    
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    reset(matchx,0); reset(matchy,0);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        int v;
        scanf("%d",&v);
        if(v) a[i].pb(j);
    }
    int res=0;
    while (findpath())
        for(int i=1;i<=n;i++) 
            if (matchx[i]==0 && dfs(i)) res++;
    printf("%d",res);
    //getch();
    return 0;
}
