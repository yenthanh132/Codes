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

string s,ch;
int n;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    
    ios::sync_with_stdio(0);
    cin>>n;
    int minv=-oo, maxv=oo;
    int v;
    REP(i,n){
        cin>>s>>v>>ch;
        if(s==">="){
            if(ch=="Y") minv = max(minv,v);
            else maxv=min(maxv,v-1);   
        }else if(s==">"){
            if(ch=="Y") minv = max(minv,v+1);
            else maxv=min(maxv,v);   
        }else if(s=="<="){
            if(ch=="Y") maxv = min(maxv,v);
            else minv = max(minv,v+1);   
        }else{
            if(ch=="Y") maxv = min(maxv,v-1);
            else minv = max(minv,v);      
        }
    }
    if(minv>maxv) cout<<"Impossible"<<endl;
    else cout<<minv<<endl;
    
    return 0;
}
