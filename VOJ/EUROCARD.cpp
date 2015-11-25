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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

int d[6][6],s[6][6],m,n;
vector<int> list[6][6];

void addresult(const int& m,const int& n){
    int t=0; int v=0;
    FOR(i,1,m) FOR(j,1,n) v+=d[i][j]*(1<<t++);
    list[m][n].pb(v);
}   

void duyet(int i, int j,const int& m,const int& n){
    if(i>m){
        addresult(m,n);
        return;
    }
    int v,x; 
    bool ok;
    for(int bit=0; bit<=1; bit++){
        d[i][j]=bit;
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+bit;
        ok=true;
        for(x=1;min(i,j)-x>=0;x++){
            v=s[i][j]-s[i-x][j]-s[i][j-x]+s[i-x][j-x];
            if(abs(x*x-v*2)>2){ok=false; break;}
        }
        if(ok) if(j<n) duyet(i,j+1,m,n); else duyet(i+1,1,m,n);
    }
}   

int count(int v1, int v0){
    int res=0,v,vv;
    bool ok;
    REP(index,list[m][n].size()){
        v=list[m][n][index];
        vv=~v;
        if(((v-v1)|v)==v && ((vv-v0)|vv)==vv) res++;
    }
    return res;
}
    
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    FOR(i,1,5) FOR(j,1,5) duyet(1,1,i,j);
    char ch;
    int test,v1,v0,t;
    scanf("%d\n",&test);
    REP(i,test){
        scanf("%d%d\n",&m,&n);
        v1=0; v0=0; t=0;
        FOR(i,1,m){
            FOR(j,1,n){
                scanf("%c",&ch); 
                if(ch=='R') v1+=(1<<t); 
                else if(ch=='B') v0+=(1<<t);
                t++;
            }
            scanf("\n");
        }
        printf("%d\n",count(v1,v0));
    }
    //getch();
    return 0;
}
