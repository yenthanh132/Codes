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
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;

const int maxn=100007;
struct node{
    int t,v; //1 full, 2 empty
};
char s[maxn];
int n,q,cnt[26];

struct ITTree{
    node IT[maxn*4];
    void lazy_update(int i, int l, int r){
        if(IT[i].t==0) return;
        if(IT[i].t==1) IT[i].v=(r-l+1);    
        else IT[i].v=0;
        if(l<r) IT[i*2].t=IT[i*2+1].t=IT[i].t;   
        IT[i].t=0;
    }
    
    void modify(int i, int l, int r, int s, int f, int v){
        lazy_update(i,l,r);
        if(f<l || s>r) return;
        if(s<=l && r<=f){
            IT[i].t=v;
            lazy_update(i,l,r);
            return;   
        }   
        int mid=(l+r)/2;
        modify(i*2,l,mid,s,f,v);
        modify(i*2+1,mid+1,r,s,f,v);
        IT[i].v=IT[i*2].v+IT[i*2+1].v;    
    }
    
    void modify(int l, int r, int v){
        modify(1,1,n,l,r,v);   
    }
    
    int IT_res;
    void get(int i, int l, int r, int s, int f){
        lazy_update(i,l,r);
        if(f<l || s>r) return;
        if(s<=l && r<=f){
            IT_res+=IT[i].v;
            return;   
        }   
        int mid=(l+r)/2;
        get(i*2,l,mid,s,f);
        get(i*2+1,mid+1,r,s,f);
        IT[i].v=IT[i*2].v+IT[i*2+1].v;   
    }
    
    int get(int l, int r){
        IT_res=0;
        get(1,1,n,l,r);
        return IT_res;   
    }
} Tree[26];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    FOR(i,1,n) Tree[s[i]-'a'].modify(i,i,1);
    int x,y;
    REP(i,q){
        scanf("%d%d",&x,&y);
        reset(cnt,0);
        REP(ch,26) cnt[ch]=Tree[ch].get(x,y);
        int u=-1;
        bool ok=1;
        REP(ch,26) if(cnt[ch]&1)
            if(u!=-1) ok=0;
            else u=ch;
        if(!ok) continue;
        
        REP(ch,26) if(cnt[ch]) Tree[ch].modify(x,y,2);
        int l=x, r=y;
        REP(ch,26) if(cnt[ch]){
            int len=cnt[ch]/2;
            if(len==0) continue;
            Tree[ch].modify(l,l+len-1,1);
            Tree[ch].modify(r-len+1,r,1);
            l+=len; r-=len;
        }
        if(u!=-1) Tree[u].modify(l,l,1);  
    }
    
    FOR(i,1,n){
        REP(ch,26) if(Tree[ch].get(i,i)){
            putchar(ch+'a');
            break;   
        }   
    }
    
    return 0;
}
