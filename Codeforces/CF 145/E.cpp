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

struct team{
    string name;
    int v;
} arr[111];
vector<team> bas[4];

bool cmp(const team &a, const team &b){
    return a.v>b.v;   
}
int n,x,a,b,c,m;

int myrnd(){
    int y=(a*x+b)%c;
    x=y;
    return x;   
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    cin>>x>>a>>b>>c;
    REP(i,n) cin>>arr[i].name>>arr[i].v;
    sort(arr,arr+n,cmp);
    m=n/4;
    
    REP(i,n) bas[i/m].pb(arr[i]);
    
    char ch='A';
    REP(i,m){
        cout<<"Group "<<ch<<":"<<endl;
        REP(j,4){
            int v=myrnd()%sz(bas[j]);
            cout<<bas[j][v].name<<endl;
            bas[j].erase(bas[j].begin()+v);   
        }   
        ++ch;
    }
    
    return 0;
}
