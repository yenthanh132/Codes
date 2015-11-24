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
    //freopen("input.txt","r",stdin);
    int res=-1,n,s;
    cin>>n>>s;
    int x,y;
    for(int i=0; i<n; ++i){
        cin>>x>>y;
        int cost=x*100+y;
        for(int d=1; d<=s; ++d){
            int pay=d*100;
            if(pay>=cost)
                res = max(res,(pay-cost)%100);
        }
    }
    cout<<res<<endl;
}
