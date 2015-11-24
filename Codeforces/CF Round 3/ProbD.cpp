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

string s;
int n,m;
vector<int> cost;
ll res;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>s;
    n=sz(s); m=0;
    if(n&1 || s[0]==')'){cout<<-1; return 0;}
    
    vector<int> pos;
    REP(i,n) if(s[i]=='?') m++, pos.pb(i);
    int a,b;
    res=0;
    cost.resize(n,0);
    REP(i,m){
        scanf("%d%d",&a,&b);
        res+=a;
        cost[pos[i]]=b-a;
    }
    
    priority_queue<pii,vector<pii>,greater<pii> > heap;
    int v=0;
    REPD(i,n){
        if(i>0 && s[i]=='?') heap.push(mp(cost[i],i));
        if(s[i]==')') v++; else v--;
        if(s[i]=='?') s[i]='(';
        if(v<0)
            if(heap.empty()){
                cout<<-1;
                return 0;
            }else{
                res+=heap.top().fi;
                s[heap.top().se]=')';
                heap.pop();
                v+=2;
            }
        
    }
    if(v>0){cout<<-1; return 0;}
    cout<<res<<endl;
    cout<<s;
    //getch();
    return 0;
}
        
        
