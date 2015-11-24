#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> iii;

int n,m;
struct node{
    node *next[3];
    int v;
}*trie;

node *newnode(){
    node *p = new node;
    p->v=0;
    for(int i=0; i<3; ++i) p->next[i]=0;
    return p;
}

char s[1000007];
int len;
bool found(node *p, int x, int i){
    if(x>1 || !p) return 0;
    if(i==len) return (p->v && x==1);
    int v=s[i]-'a';
    for(int c=0; c<3; ++c)
        if(found(p->next[c],x+(c!=s[i]-'a'),i+1)) return 1;
    return 0;
}

int main(){
//    freopen("input.txt","r",stdin);
    trie = newnode();
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i){
        scanf("%s",s+1); len=strlen(s+1);
        node *p = trie;
        for(int i=1; i<=len; ++i){
            int v=s[i]-'a';
            if(!p->next[v]) p->next[v]=newnode();
            p=p->next[v];
        }
        p->v=1;
    }
    for(int i=1; i<=m; ++i){
        scanf("%s",s); len=strlen(s);
        if(found(trie,0,0)) puts("YES");
        else puts("NO");
    }
}

