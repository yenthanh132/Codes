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

const int maxr=507;
const int maxc=2507;

int r,c,n;
int ch['z'],lab[maxr*maxc],a[maxr*maxc];

void init(){
    REP(i,r*c) lab[i]=-1,a[i]=0;
}

int chtonum(char ch){
    if(ch<='Z') return ch-'A'; else return ch-'a'+26;
}

int tonum(char a, char b){
    return chtonum(a)*52+chtonum(b)-1;
}

int toid(int x, int y){
    return y*c+x;
}

int getroot(int u){
    if(lab[u]<0) return u;
    int r=getroot(lab[u]);
    lab[u]=r;
    return r;
}

void dsu(int u, int v){
    int r1=getroot(u), r2=getroot(v);
    if(r1==r2) return;
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
        a[r1]+=a[r2];
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
        a[r2]+=a[r1];
    }
}

//#include <conio.h>
int main(){
//    freopen("test.txt","r",stdin);
    scanf("%d%d%d\n",&n,&r,&c);    
    init();
    char s[16];
    int x1,y1,x2,y2,r1,r2;
    REP(index,n){
        gets(s);
        if(s[0]=='W' || s[0]=='L'){
            x1=tonum(s[1],s[2]);
            y1=tonum(s[3],s[4])/5;
            x2=tonum(s[5],s[6]);
            y2=tonum(s[7],s[8])/5;
            if(s[0]=='W') dsu(toid(x1,y1), toid(x2,y2));
            else{
                r1=getroot(toid(x1,y1));
                r2=getroot(toid(x2,y2));
                if(a[r1]*a[r2]==0 && a[r1]+a[r2]>0) puts("ON"); else puts("OFF");
            }
        }else{
            x1=tonum(s[1],s[2]);
            y1=tonum(s[3],s[4])/5;
            r1=getroot(toid(x1,y1));
            if(s[0]=='V') a[r1]++; else a[r1]--;
        }
    }
//    getch();
    return 0;
}
