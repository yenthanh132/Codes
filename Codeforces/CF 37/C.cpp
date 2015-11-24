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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=1007;

struct node{bool locked; node* next[2], *parent;} *root;

node* newnode(){
    node *p=new node;
    p->next[0] = p->next[1] = p->parent = NULL;
    p->locked=0;
    return p;
}

int n;
pii a[maxn];
char s[maxn][maxn];

bool go(int i){
    node *p=root;
    FOR(j,1,a[i].fi){
        if(p->next[0]==NULL || !p->next[0]->locked){
            if(p->next[0]==NULL){
                p->next[0]=newnode();
                p->next[0]->parent=p;
            }
            p=p->next[0];
            s[a[i].se][j]='0';
        }else if(p->next[1]==NULL || !p->next[1]->locked){
            if(p->next[1]==NULL){
                p->next[1]=newnode();
                p->next[1]->parent=p;
            }
            p=p->next[1];
            s[a[i].se][j]='1';
        }else return 0;
    }
    p->locked=1;
    while(p->parent!=NULL){
        p=p->parent;
        if(p->next[0]!=NULL && p->next[0]->locked && p->next[1]!=NULL && p->next[1]->locked) p->locked=1;
        else break;
    }
    s[i][a[i].fi+1]='\0';
    return 1;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i].fi), a[i].se=i;
    sort(a+1,a+n+1);
    bool ok=1;
    root=newnode();
    FOR(i,1,n) if(!go(i)){
        ok=0;
        break;
    }
    if(!ok) puts("NO");
    else{
        puts("YES");
        FOR(i,1,n) puts(s[i]+1);
    }
    return 0;
}
