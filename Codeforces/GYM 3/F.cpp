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

set<int> mys,mys2;

int a[8],a2[8];
pii b[4];
vector<int> movelist;
queue<pii> myq;

int sort(int *a){
    REP(j,4){
        b[j].fi=a[j*2];
        b[j].se=a[j*2+1];
    }
    sort(b,b+4);
    REP(j,4){
        a[j*2]=b[j].fi;
        a[j*2+1]=b[j].se;
    }
}

int encode(int *x){
    int t[8];
    REP(i,8) t[i]=x[i];
    sort(t);
    int v=0;
    REP(i,8)  v=v*8+t[i];
    return v;
}

int decode(int *a, int v){
    REPD(i,8){
        a[i]=v%8;
        v/=8;   
    }   
}

bool found(int x, int y){
    REP(j,4) if(a[j*2]==x && a[j*2+1]==y) return 1;
    return 0;
}

vector<int> getmove(int v){
    decode(a,v);
    vector<int> list;   
    REP(i,4){
        int& x=a[i*2];
        int& y=a[i*2+1];
        if(x>0){
            if(!found(x-1,y)){
                x--;
                list.pb(encode(a));
                x++;
            }else if(x-1>0 && !found(x-2,y)){
                x-=2;
                list.pb(encode(a));
                x+=2;
            }
        }
        if(y>0){
            if(!found(x,y-1)){
                y--;
                list.pb(encode(a));
                y++;
            }else if(y-1>0 && !found(x,y-2)){
                y-=2;
                list.pb(encode(a));
                y+=2;
            }
        }
        if(x<7){
            if(!found(x+1,y)){
                x++;
                list.pb(encode(a));
                x--;
            }else if(x+1<7 && !found(x+2,y)){
                x+=2;
                list.pb(encode(a));
                x-=2;
            }
        }
        if(y<7){
            if(!found(x,y+1)){
                y++;
                list.pb(encode(a));
                y--;
            }else if(y+1<7 && !found(x,y+2)){
                y+=2;
                list.pb(encode(a));
                y-=2;
            }
        }
    }
    return list;
}

#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    REP(i,8){
        cin>>a[i];
        a[i]--;
    }
    int code=encode(a);
    mys.insert(code);
    
    while(!myq.empty()) myq.pop();
    myq.push(pii(code,0));
    while(!myq.empty()){
        int step=myq.front().se;
        code=myq.front().fi;
        myq.pop();
        movelist=getmove(code);
        REP(i,sz(movelist))
            if(mys.find(movelist[i])==mys.end()){
                mys.insert(movelist[i]);
                if(step<=3) myq.push(pii(movelist[i],step+1));
            }
    }
    
    REP(i,8){
        cin>>a[i];
        a[i]--;
    }
    code=encode(a);
    while(!myq.empty()) myq.pop();
    mys2.insert(code);
    myq.push(pii(code,0));
    while(!myq.empty()){
        int step=myq.front().se;
        code=myq.front().fi;
        
        if(mys.find(code)!=mys.end()){
            puts("YES");
            
            return 0;
        }
        myq.pop();
        movelist=getmove(code);
        REP(i,sz(movelist))
            if(mys2.find(movelist[i])==mys2.end()){
                mys2.insert(movelist[i]);
                if(step<=2) myq.push(pii(movelist[i],step+1));
            }
    }

    puts("NO");
    
    return 0;
}
    
    
    
