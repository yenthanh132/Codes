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

int m,n,rx,ry;
int a[30][30];

struct piece{
    int m,n,id;
    int a[21][21];
    bool operator < (const piece &p) const{
        FOR(i,1,m) FOR(j,1,n) if(a[i][j]<p.a[i][j]) return 1; else if(a[i][j]>p.a[i][j]) return 0;
        return id<p.id;
    }
    bool operator == (const piece &p) const{
        FOR(i,1,m) FOR(j,1,n) if(a[i][j]!=p.a[i][j]) return 0;
        return id!=p.id;
    }
};
vector<piece> list;

void update(int x, int y){
    if(x*y < rx*ry || (x*y==rx*ry && x<rx)){
        rx=x;
        ry=y;
    }
}

piece rotate(const piece &p){
    piece q;
    q.m=p.n; q.n=p.m; q.id=p.id;
    FOR(i,1,q.m) FOR(j,1,q.n) q.a[i][j]=p.a[j][p.n-i+1];  
    return q;
}

bool check(int x, int y){
    piece p;
    p.m=x; p.n=y;
    int id=0;
    list.clear();
    for(int i=1; i<=m; i+=x) for(int j=1; j<=n; j+=y){
        p.id=++id;
        FOR(i2,1,x) FOR(j2,1,y) p.a[i2][j2]=a[i+i2-1][j+j2-1];
        list.pb(p);
        p=rotate(p);
        if(x==y)list.pb(p);
        p=rotate(p);
        list.pb(p);
        if(x==y){
            p=rotate(p);
            list.pb(p);
        }
    }
    sort(list.begin(),list.end());
    REP(i,sz(list)-1) if(list[i]==list[i+1]) return 0;
    return 1;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>m>>n;
    
    FOR(i,1,m){
        string s;
        cin>>s;
        FOR(j,1,n) a[i][j]=s[j-1]-'A';
    }
    
    int cnt=0;
    rx=m; ry=n;
    FOR(x,1,m) if(m%x==0) 
        FOR(y,1,n) if(n%y==0)
        if(check(x,y)){
            cnt++;
            update(x,y);
        }
    cout<<cnt<<endl;
    cout<<rx<<' '<<ry<<endl;
    //getch();
    return 0;
}
        
    
    
