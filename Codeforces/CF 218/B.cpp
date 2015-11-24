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

int a,b;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>a>>b;
    int p1, p2, v,res=0;
    REP(i,3){
        p1=p2=0;
        if(i==0) v=2; 
        else if(i==1) v=3;
        else v=5;
        while(a%v==0){
            a/=v;
            p1++;
        }
        while(b%v==0){
            b/=v;
            p2++;   
        }
        res+=max(p1,p2) - min(p1,p2);
    }
    if(a!=b) puts("-1");
    else cout<<res<<endl;
}
