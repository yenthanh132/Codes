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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;++a)
#define FORD(a,b,c) for (int a=b;a>=c;--a)
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

int s[maxn][maxn],m,n,a,b,c,d,arr[maxn][maxn];
int posX[maxn][maxn],posY[maxn][maxn],minrow[maxn][maxn],minrec[maxn][maxn];
int myq[maxn],first,last;
int best,X1,Y1,X2,Y2;

inline int get(int x1, int y1, int x2, int y2){
    return s[x2][y2]+s[x1-1][y1-1]-s[x1-1][y2]-s[x2][y1-1];
}

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}


//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d%d%d%d",&n,&m,&b,&a,&d,&c);
    int v;
    FOR(i,1,m) FOR(j,1,n){
        read(v);
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+v;
    }
    
    FOR(i,2,m-c) FOR(j,2,n-d) arr[i][j]=get(i,j,i+c-1,j+d-1);
    
    int width=b-2;
    int height=a-2;
    
    FOR(i,2,m-c){
        first=1; last=0;
        FOR(j,2,n-d){
            while(first<=last && myq[first]<j+d-width) first++;
            while(first<=last && arr[i][myq[last]]>=arr[i][j]) last--;
            myq[++last]=j;
            if(j+d-width>=2){
                minrow[i][j+d-width]=arr[i][myq[first]];
                posY[i][j+d-width]=myq[first];
            }
        }
    }
    FOR(j,2,n-d){
        first=1; last=0;
        FOR(i,2,m-c){
            while(first<=last && myq[first]<i+c-height) first++;
            while(first<=last && minrow[myq[last]][j]>=minrow[i][j]) last--;
            myq[++last]=i;
            if(i+c-height>=1){
                minrec[i+c-height][j]=minrow[myq[first]][j];
                posX[i+c-height][j]=myq[first];
            }
        }
    }
    best=-oo;
    
    FOR(x,1,m-a+1) FOR(y,1,n-b+1){
        v=get(x,y,x+a-1,y+b-1) - minrec[x+1][y+1];
        if(v>best){
            best=v;
            X1=x; Y1=y;
            X2=posX[x+1][y+1]; Y2=posY[X2][y+1];
        }
    }
    
    printf("%d %d\n%d %d\n",Y1,X1,Y2,X2);
    //cout<<clock()*1.0/CLOCKS_PER_SEC<<endl;
    //getch();
    return 0;
}
    
