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

const int maxn=5007;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

vector<int> listx,listy;
int a[maxn][maxn];
int sk[maxn],sv[maxn],n,M,N;

int getx(int v){
    int t=lower_bound(listx.begin(),listx.end(),v)-listx.begin()+1;
    return t;
}

int gety(int v){
    int t=lower_bound(listy.begin(),listy.end(),v)-listy.begin()+1;
    return t;
}

void mark(int x1, int y1, int x2, int y2, int k){
    while(x1!=x2 ||y1!=y2){
        a[x1][y1]=1;
        x1+=dx[k];
        y1+=dy[k];
    }
    a[x2][y2]=1;
}

void bfs(){
    queue<pii> myqueue;
    myqueue.push(pii(0,0));
    a[0][0]=2;
    int x1,y1,x2,y2;
    while(!myqueue.empty()){
        x1=myqueue.front().fi; y1=myqueue.front().se; myqueue.pop();
        REP(k,4){
            x2=x1+dx[k];
            y2=y1+dy[k];
            if(x2>=0 && x2<=M && y2>=0 && y2<=N && a[x2][y2]==0){
                a[x2][y2]=2;
                myqueue.push(pii(x2,y2));
            }
        }
    }
}


#include <conio.h>

int main(){
    freopen("test.txt","r",stdin);
    scanf("%d\n",&n);
    char ch;
    int x,y,v,k;
    listx.pb(0); listy.pb(0);
    x=y=0;
    FOR(i,1,n){
        scanf("%c%d\n",&ch,&v);
        if(ch=='U') k=0; else if(ch=='R') k=1; else if(ch=='D') k=2; else k=3;
        x+=dx[k]*v; y+=dy[k]*v;
        listx.pb(x); listy.pb(y);
        sk[i]=k; sv[i]=v;
    }
    sort(listx.begin(),listx.end()); listx.resize(unique(listx.begin(),listx.end())-listx.begin());
    sort(listy.begin(),listy.end()); listy.resize(unique(listy.begin(),listy.end())-listy.begin());
    
    x=y=0;
    int x1=getx(0), y1=gety(0), x2,y2;
    
    FOR(i,1,n){
        k=sk[i]; v=sv[i];
        x+=dx[k]*v; y+=dy[k]*v;
        x2=getx(x); y2=gety(y);
        
        mark(x1,y1,x2,y2,k);
        x1=x2; y1=y2;
    }
    M=sz(listx)+1; N=sz(listy)+1;
    bfs();
    FOR(i,0,M){
        FOR(j,0,N) cout<<a[i][j];
        cout<<endl;
    }
    ll res=0,w,h;
    FOR(i,1,M-1) FOR(j,1,N-1) if(a[i][j]!=2){
        
        if(i<M-1) h=listx[i]-listx[i-1]; else h=0;
        if(j<N-1) w=listy[j]-listy[j-1]; else w=0;
        cout<<i<<' '<<j<<' '<<h<<' '<<w<<endl;
        res+=h*w;
    }
    REP(i,sz(listx)) cout<<listx[i]<<' '; cout<<endl;
        REP(i,sz(listy)) cout<<listy[i]<<' '; cout<<endl;
    cout<<res<<endl;
    
    getch();
    return 0;
}
