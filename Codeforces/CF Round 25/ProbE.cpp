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

const int base = 73471;
const int maxn=100007;

ll v[2][maxn*3],hashpw[maxn*3];
char s[3][maxn];

ll get(int i, int s, int f){
    return v[i][f]-v[i][s-1]*hashpw[f-s+1];
}

int test(int i1, int i2, int i3){
    int n1=strlen(s[i1]), n2=strlen(s[i2]);
    FOR(i,1,n1) v[0][i]=v[0][i-1]*base+s[i1][i-1];
    FOR(i,1,n2) v[1][i]=v[1][i-1]*base+s[i2][i-1];
    bool inside=0;
    FOR(i,1,n1-n2+1) if(get(0,i,i+n2-1)==v[1][n2]){
        inside=1;
        break;
    }
    if(!inside){
        int p=n1+1;
        FORD(i,min(n1,n2),1) if(get(0,n1-i+1,n1)==get(1,1,i)){p=n1-i+1; break;}
        FOR(i,p,p+n2-1) v[0][i]=v[0][i-1]*base+s[i2][i-p];
        n1=p+n2-1; 
    }
    n2=strlen(s[i3]);
    FOR(i,1,n2) v[1][i]=v[1][i-1]*base+s[i3][i-1];
    FOR(i,1,n1-n2+1) if(get(0,i,i+n2-1)==v[1][n2]) return n1;
    FORD(i,min(n1,n2),1) if(get(0,n1-i+1,n1)==get(1,1,i)) return(n1+n2-i);
    return n1+n2;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    gets(s[0]); gets(s[1]); gets(s[2]);
    int res=oo;
    hashpw[0]=1; FOR(i,1,300000) hashpw[i]=hashpw[i-1]*base;
    v[0][0]=v[1][0]=0;
    REP(i,3) REP(j,3) if(i!=j) REP(z,3) if(z!=i && z!=j) res=min(res,test(i,j,z));
    printf("%d\n",res);
    //getch();
    return 0;
}
    
    
        
