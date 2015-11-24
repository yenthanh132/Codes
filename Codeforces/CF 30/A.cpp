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

#include <conio.h>
int main(){
    int a,b,n;
    bool neg;
    cin>>a>>b>>n;
    if(a==0 && b==0) cout<<1<<endl;
    else if(a==0 && b!=0) cout<<"No solution"<<endl;
    else if(b%a!=0) cout<<"No solution"<<endl;
    else{
        int v=b/a;
        if(v<0 && n%2==0){
            cout<<"No solution"<<endl;
            return 0;
        }
        if(v<0){
            neg=1;
            v=-v;
        }else neg=0;
        
        double x=exp(log(v)/n);
        
        int X=int(x+1e-9);
        if(fabs(x-X)>1e-9){
            cout<<"No solution"<<endl;
            return 0;
        }
        if(neg) X=-X;
        cout<<X<<endl;
    }
    return 0;
}        
        

