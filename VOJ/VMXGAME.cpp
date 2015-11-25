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
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
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

void CutLeft(int x, int y){
    printf("%d %d %d %d\n",x,y+1,x,y-1);
    printf("%d %d %d %d\n",x+2,y,x,y);
    printf("%d %d %d %d\n",x,y-1,x,y+1);
}

void CutRight(int x,int y){
    printf("%d %d %d %d\n",x,y-1,x,y+1);
    printf("%d %d %d %d\n",x+2,y,x,y);
    printf("%d %d %d %d\n",x,y+1,x,y-1);
}

void CutUp(int x, int y){
    printf("%d %d %d %d\n",x+1,y+2,x-1,y+2);
    printf("%d %d %d %d\n",x,y,x,y+2);
    printf("%d %d %d %d\n",x-1,y+2,x+1,y+2);
}

void CutDown(int x, int y){
    printf("%d %d %d %d\n",x-1,y,x+1,y);
    printf("%d %d %d %d\n",x,y+2,x,y);
    printf("%d %d %d %d\n",x+1,y,x-1,y);
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,n,x,y;
    scanf("%d",&T);
    REP(index,T){
        scanf("%d",&n);
        if(n==1) printf("%d\n",0);
        else if(n==2){
            printf("%d\n",3);
            printf("%d %d %d %d\n",1,1,3,1);
            printf("%d %d %d %d\n",1,2,3,2);
            printf("%d %d %d %d\n",3,1,3,3);
        }else if(n%3==0){
            printf("%d\n",n*n-2);
            FORD(x,n,4) for(y=1;y<=n-2;y+=3) CutDown(x,y);
            FORD(y,n,2) CutRight(1,y);
            printf("%d %d %d %d\n",2,1,4,1);
        }else if(n%3==1){
            printf("%d\n",n*n-1);
            for(x=2;x<=n-2;x+=3) CutLeft(x,1);
            FORD(x,n,4) for(y=2;y<=n-2;y+=3) CutDown(x,y);
            FORD(y,n,2) CutRight(1,y);
        }else{ //n%3==2
            printf("%d\n",n*n-1);
            for(x=3;x<=n-2;x+=3) CutLeft(x,1), CutLeft(x,2);
            FORD(x,n,4) for(y=3;y<=n-2;y+=3) CutDown(x,y);
            FORD(y,n,4) CutRight(1,y);
            CutUp(1,1); CutUp(2,1);
        }
    }
    //getch();
    return 0;
}

