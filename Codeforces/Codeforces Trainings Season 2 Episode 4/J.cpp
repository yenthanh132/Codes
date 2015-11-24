#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct node{
    int v;
    node *next[26];
}*root;

node * new_node(){
    node *p=new node;
    p->v=0;
    for(int i=0; i<26; ++i) p->next[i]=NULL;
    return p;
}

void add(char *s){
    int len=strlen(s);
    node *p=root;
    p->v++;
    for(int i=0; i<len; ++i){
        int v=s[i]-'a';
        if(p->next[v]==NULL) p->next[v]=new_node();
        p=p->next[v];
        p->v++;
    }
}

ll count(char *s){
    int len=strlen(s);
    node *p=root;
    ll res = p->v;
    for(int i=0; i<len; ++i){
        int v=s[i]-'a';
        if(p->next[v]==NULL) break;
        p=p->next[v];
        res+=p->v;
    }
    return res;
}

const int maxn=30007;
const int base=73471;

int n,q;
char s[maxn][37],sq[maxn][37];
vector<int> query[maxn];
map<ll,int> pos;
ll res[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    root = new_node();
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%s",s[i]);
        int len=strlen(s[i]);
        ll val=0;
        for(int j=0; j<len; ++j) val=val*base+s[i][j];
        if(pos[val]==0) pos[val]=i;
    }
    scanf("%d",&q);
    for(int i=1; i<=q; ++i){
        scanf("%s",sq[i]);
        int len=strlen(sq[i]);
        ll val=0;
        for(int j=0; j<len; ++j) val=val*base+sq[i][j];
        if(pos[val]) query[pos[val]].pb(i);
        else query[n+1].pb(i);
    }

    for(int i=1; i<=n+1; ++i){
        if(i<=n) add(s[i]);
        for(int j=0; j<sz(query[i]); ++j){
            int iq=query[i][j];
            res[iq]=count(sq[iq]);
        }
    }
    for(int i=1; i<=q; ++i) printf("%I64d\n",res[i]);

    return 0;
}

