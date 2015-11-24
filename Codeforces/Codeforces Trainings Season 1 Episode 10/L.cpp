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

const int maxn=10000007;
const int maxlen=100007;
int a[maxn],b[1007],next[maxlen][26],n,mul,add,len,pos[26],q,st,fi,repLen;
char buf[7];
bool res;
int savepos[26][26];

void init(){
    reset(savepos,-1);
    FOR(i,1,100000){
        if(savepos[a[i]][(i-1)%26]!=-1){
            st=savepos[a[i]][(i-1)%26];
            fi=i-1;
            repLen=i-st;
        }
        savepos[a[i]][(i-1)%26]=i;
    }
    
    REP(i,26) pos[i]=oo;
    FORD(i,100000,0){
        REP(j,26) next[i][j]=pos[j];
        if(i) pos[a[i]]=i;
    }
}

int getnext(int p, int v){
    if(p==0) return next[0][v];
    if(p<st) return next[p][v];
    int i=(p-st)%repLen+st;
    if(next[i][v]==oo) return oo;
    return p+next[i][v]-i;
}

int main(){
    freopen("mahdi.in","r",stdin);   
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%s%d%d%d",buf,&n,&mul,&add);
        a[1]=buf[0]-'a';
        mul%=26; add%=26;
        FOR(i,2,100000) a[i]=(a[i-1]*mul+(i-1)*add)%26;
        
        init();
        
        printf("Case %d:\n",tt);
        scanf("%d",&q);
        int x;
        REP(tt,q){
            scanf("%s%d%d%d",buf,&len,&mul,&add);
            res=1;        
            b[1]=buf[0]-'a';
            x=0;
            FOR(i,2,len){
                x=getnext(x,b[i-1]);
                if(x>n){
                    res=0;
                    break;   
                }   
                b[i]=(b[i-1]*mul+(i-1)*add)%26;
            }
            if(res){
                x=getnext(x,b[len]);
                if(x>n) res=0;   
            }
            if(res) puts("BRAVO");
            else puts("REPEAT");
        }
    }
    return 0;
}
