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

const int maxn=100007;

ll a[maxn],Right[maxn],res;
int n;

struct node{int c; node *next[2];} *root;

void newNode(node *&p){
    p=new node;
    p->c=0;
    p->next[0]=p->next[1]=NULL;
}

void add(ll v){
    node *p=root;
    REPD(i,40)
        if((v>>i)&1){
            if(p->next[1]==NULL) newNode(p->next[1]);
            p=p->next[1];
            p->c++;
        }else{
            if(p->next[0]==NULL) newNode(p->next[0]);
            p=p->next[0];
            p->c++;
        }
}

void del(ll v){
    node *p=root;
    REPD(i,40){
        if((v>>i)&1) p=p->next[1];
        else p=p->next[0];
        p->c--;
    }
}
            
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%I64d\n",&a[i]);
    Right[n+1]=0;
    newNode(root);
    add(0);
    res=0;
    FORD(i,n,1){
        Right[i]=Right[i+1] ^ a[i];
        res=max(res,Right[i]);
        add(Right[i]);
    }
    
    ll val=0, ans, bit;
    node *p;
    FOR(i,1,n-1){
        val^=a[i];
        del(Right[i]);
        p=root;
        ans=0;
        REPD(j,40){
            bit=(val>>j)&1;
            if(p->next[1^bit]!=NULL && p->next[1^bit]->c > 0){
                p=p->next[1^bit];
                ans+=(1ll<<j);
            }else p=p->next[bit];
        }
        res=max(res,ans);
    }
    
    cout<<res<<endl;
    //getch();
    return 0;
}
