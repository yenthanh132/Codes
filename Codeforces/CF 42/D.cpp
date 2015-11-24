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

int m,n;

#include <conio.h>
int main(){
    cin>>m>>n;
    if(m==1){
        if(n>2){
            puts("1");
            printf("%d %d %d %d\n",m,n,1,1);
        }else puts("0");
        FOR(y,1,n) printf("%d %d\n",1,y);
        puts("1 1");
    }else if(n==1){
        if(m>2){
            puts("1");
            printf("%d %d %d %d\n",m,n,1,1);
        }else puts("0");
        FOR(x,1,m) printf("%d %d\n",x,1);
        puts("1 1");
    }else if((m&1) && (n&1)){
        puts("1");
        printf("%d %d %d %d\n",m,n,1,1);
        int x=1, y=1, k=1;
        while(x!=m || y!=n){
            printf("%d %d\n",x,y);
            y+=k;
            if(y>n){
                y=n;
                x++;
                k=-1;
            }else if(y<1){
                y=1;
                x++;
                k=1;
            }
        }
        printf("%d %d\n",x,y);
        puts("1 1");
    }else if(m%2==0){
        puts("0");
        int x=1, y=2, k=1;
        puts("1 1");
        
        while(x!=m-1 || y!=n){
            printf("%d %d\n",x,y);
            y+=k;
            if(y>n){
                y=n; 
                x++;
                k=-1;
            }else if(y<2){
                y=2;
                x++;
                k=1;
            }
        }
        printf("%d %d\n",x,y);
        FORD(yt,n,1) printf("%d %d\n",m,yt);
        FORD(xt,m-1,1) printf("%d %d\n",xt,1);
    }else{
        puts("0");
        int x=2, y=1, k=1;
        puts("1 1");
        while(x!=m || y!=n-1){
            printf("%d %d\n",x,y);
            x+=k;
            if(x>m){
                x=m; 
                y++;
                k=-1;
            }else if(x<2){
                x=2;
                y++;
                k=1;
            }
        }
        printf("%d %d\n",x,y);
        FORD(xt,m,1) printf("%d %d\n",xt,n);
        FORD(yt,n-1,1) printf("%d %d\n",1,yt);
    }
    
    //getch();
    return 0;
}
