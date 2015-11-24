#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<int,pii> iii;



const int maxn = 1007;
const int maxid = 15007;


struct node{
    int v,tail;
    int next[26];
} nodeArr[1111111];

int idx, root, idx2;

int idmap[1111111], idmap_inv[maxid];

int getIdx(int id){
    if(idmap[id]==-1){
        idmap[id]=++idx2;
        idmap_inv[idx2] = id;
    }
    return idmap[id];
}

int newNode(){
    ++idx;
    node &p = nodeArr[idx];
    for(int i=0; i<26; ++i) p.next[i] = 0;
    p.v=0;
    p.tail=0;
    return idx;
}

void dfs(int id){
    node &p = nodeArr[id];
    for(int i=0; i<26; ++i) if(p.next[i]){
        dfs(p.next[i]);
        p.tail = max(p.tail, nodeArr[p.next[i]].tail+1);
    }
}


//=======================

int dis[maxn][maxid];
priority_queue<iii,vector<iii>,greater<iii> > mys;

vector<iii> e[maxn];
int n,m;
char s[maxn];

//bfs
int d[maxn]; //distance from n
void bfs(){
    queue<int> myq;
    reset(d,-1);
    d[n]=0;
    myq.push(n);
    while(!myq.empty()){
        int u=myq.front(); myq.pop();
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i].first;
            if(d[v]==-1){
                d[v]=d[u]+1;
                myq.push(v);
            }
        }
    }
}

int main(){
//    freopen("input.txt","r",stdin);

    idx = 0;
    idx2 = 0;
    root = newNode();

    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i){
        int x,y,w;
        char s[10];
        scanf("%d%d%d%s",&x,&y,&w,s);
        e[x].pb(iii(y,pii(w,s[0]-'a')));
        e[y].pb(iii(x,pii(w,s[0]-'a')));
    }
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0; i<len; ++i){
        int pIdx = root;

        for(int j=i; j<len; ++j){
            node &p = nodeArr[pIdx];
            ++p.v;
            int v=s[j]-'a';
            if(p.next[v]==0) p.next[v] = newNode();
            pIdx = p.next[v];
        }
        node &p = nodeArr[pIdx];
        ++p.v;
    }

    dfs(root);
    bfs();

    reset(dis,63);
    reset(idmap, -1);
    int id = getIdx(root);
    dis[1][id] = 0;
    mys.push(iii(0,pii(1,id)));
    int res = -1;

    while(!mys.empty()){
        iii tripe = mys.top(); mys.pop();
        int u = tripe.second.first, id = tripe.second.second;
        int val = tripe.first;
        if(u == n){
            res = dis[n][id];
            break;
        }
        if(val > dis[n][id]) continue;
        node &p = nodeArr[idmap_inv[id]];
        for(int i=0; i<sz(e[u]); ++i){
            int v = e[u][i].first, w = e[u][i].second.first, x = e[u][i].second.second;
            if(p.next[x] == 0) continue;
            node &p2 = nodeArr[p.next[x]];
            if(p2.tail < d[v]) continue;
            int id2 = getIdx(p.next[x]);
            w *= p2.v;

            if(dis[v][id2] > dis[u][id] + w){
                dis[v][id2] = dis[u][id] + w;
                mys.push(iii(dis[v][id2],pii(v,id2)));
            }
        }
    }

    printf("%d\n",res);
}

