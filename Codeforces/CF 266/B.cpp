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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
    ll n,a,b,s,a1,b1,x,y,z;
    cin>>n>>a>>b;
    if(a*b>=6*n){
        cout<<a*b<<endl<<a<<' '<<b<<endl;
        return 0;
    }
    s=-1;
    bool doSwap=false;
    if(a>b){
        swap(a,b);
        doSwap=true;
    }
    for(x=a; x*x<=6*n; ++x){
        y=(6*n-1)/x+1;
        y=max(y,b);
        z=x*y;
        if(s==-1 || s>z){
            s=z;
            a1=x;
            b1=y;
        }
    }
    if(doSwap) swap(a1,b1);
    cout<<s<<endl<<a1<<' '<<b1<<endl;
}
