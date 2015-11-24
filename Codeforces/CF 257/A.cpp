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

ll res,a,b,c;

void cal(ll x){
    ll k=c-a/x+1;
    k=max(k,0ll);
    if(k+1>=b) return;

    ll y=b/(k+1);
    res=max(res,x*y);
}

int main(){
    cin>>a>>b>>c;
    if(a+b-2<c){
        cout<<-1<<endl;
    }else{
        res=1;
        for(int i=1; i*i<=a; ++i) if(a%i==0){
            ll x=i;
            cal(x);
            cal(a/i);
        }
        swap(a,b);
        for(int i=1; i*i<=a; ++i) if(a%i==0){
            ll x=i;
            cal(x);
            cal(a/i);
        }
        cout<<res<<endl;
    }
}
