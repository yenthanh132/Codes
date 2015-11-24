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
typedef pair<pii, int> iii;

const int maxn=150007;

char s[maxn], f[30];
int T,n,cnt[30],pos[30],match[30];
iii a[30];

int val(char ch){
    if('a'<=ch && ch<='z') return ch-'a';
    if('A'<=ch && ch<='Z') return ch-'A';
    return -1;   
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d\n",&T);
    REP(tt,T){
        gets(f);
        gets(s);
        n=strlen(s);
        reset(cnt,0);
        reset(pos,-1);
        REP(i,n){
            int v=val(s[i]);
            if(v!=-1){
                ++cnt[v];
                //if(pos[v]==-1) pos[v]=i;
            }
        }
        REP(i,26) a[i]=iii(pii(cnt[i],pos[i]),i);
        sort(a,a+26);
        REP(i,26) match[a[i].se]=f[i]-'a';
        REP(i,n){
            int v=val(s[i]);
            if(v!=-1){
                if('A'<=s[i] && s[i]<='Z') putchar('A'+match[v]);
                else putchar('a'+match[v]);
            }else putchar(s[i]);   
        }
        puts("");
        
    }
    
}
