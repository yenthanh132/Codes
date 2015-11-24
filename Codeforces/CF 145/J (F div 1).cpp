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

const int maxn=10007;
struct node{
    int t,v; //1 full, 2 empty
}IT[26][maxn*4];
char s[maxn];
int n,q,cnt[26];

void lazy_update(node *IT, int i, int l, int r){
    
    if(IT[i].t==0) return;
    if(IT[i].t==1) IT[i].v=(r-l+1);    
    else IT[i].v=0;
    
    if(l<r) IT[i*2].t=IT[i*2+1].t=IT[i].t;   
    IT[i].t=0;
}

void modify(node *IT, int i, int l, int r, int s, int f, int v){
    lazy_update(IT,i,l,r);
    if(f<l || s>r) return;
    if(s<=l && r<=f){
        IT[i].t=v;
        lazy_update(IT,i,l,r);
        return;   
    }   
    int mid=(l+r)/2;
    modify(IT,i*2,l,mid,s,f,v);
    modify(IT,i*2+1,mid+1,r,s,f,v);
    IT[i].v=IT[i*2].v+IT[i*2+1].v;    
}

void modify(char ch, int l, int r, int v){
    modify(IT[ch-'a'],1,1,n,l,r,v);   
}

int IT_res;
void get(node *IT, int i, int l, int r, int s, int f){
    lazy_update(IT,i,l,r);
    if(f<l || s>r) return;
    if(s<=l && r<=f){
        IT_res+=IT[i].v;
        return;   
    }   
    int mid=(l+r)/2;
    get(IT,i*2,l,mid,s,f);
    get(IT,i*2+1,mid+1,r,s,f);
    IT[i].v=IT[i*2].v+IT[i*2+1].v;   
}

int get(char ch, int l, int r){
    IT_res=0;
    get(IT[ch-'a'],1,1,n,l,r);
    return IT_res;   
}

int main(){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    puts(s+1);
    FOR(i,1,n) modify(s[i],i,i,1);
    int x,y;
    REP(i,q){
        scanf("%d%d",&x,&y);
        reset(cnt,0);
        REP(ch,26) cnt[ch]=get(ch,x,y);
        int u=-1;
        bool ok=1;
        REP(ch,26) if(cnt[ch]&1)
            if(u!=-1) ok=0;
            else u=ch;
        if(!ok) continue;
        
        REP(ch,26) if(cnt[ch]) modify(ch,x,y,2);
        int l=x, r=y;
        REP(ch,26) if(ch!=u && cnt[ch]){
            int len=cnt[ch]/2;
            modify(ch,l,l+len-1,1);
            modify(ch,r-len+1,r,1);
            l+=len; r-=len;
        }
    }
    
    FOR(i,1,n){
        REP(ch,26) if(get(ch,i,i)){
            putchar(ch+'a');
            break;   
        }   
    }
    
    return 0;
}
