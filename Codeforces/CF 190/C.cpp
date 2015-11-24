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

const int maxn=107;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int a,b,n,vx,vy;
char s[maxn];

int move(char ch){
    if(ch=='L') return 0;
    if(ch=='R') return 2;
    if(ch=='U') return 1;
    return 3;
}

bool check(int& x0, int& y0){
    if(pii(x0,y0)==pii(a,b)) return 1;
    FOR(i,1,n){
        int k=move(s[i]);
        x0+=dx[k]; y0+=dy[k];
        if(pii(x0,y0)==pii(a,b)) return 1;
    }
    return 0;
}

int main(){
    //freopen("test.txt","r",stdin);
    
    scanf("%d%d",&a,&b);
    scanf("%s",s+1);
    n=strlen(s+1);
    vx=vy=0;
    if(check(vx,vy)){
        cout<<"Yes";
        return 0;
    }
    
    if(vx==0 && vy==0){
        cout<<"No";
        return 0;
    }
        
    
    
    int x,y;
    ll v;
    x=y=0;
    FOR(i,0,n){
        if(i){
            x+=dx[move(s[i])];
            y+=dy[move(s[i])];   
        }   
        if(vx!=0 && (a-x)%vx==0){
            v=(a-x)/vx;
            if(v>=0 && vy*v+y==b){
                cout<<"Yes";
                return 0;
            }
        }else if(vy!=0 && (b-y)%vy==0){
            v=(b-y)/vy;
            if(v>=0 && vx*v+x==a){
                cout<<"Yes";
                return 0;
            }
        }
    }
    
    cout<<"No";
    return 0;
}
    
