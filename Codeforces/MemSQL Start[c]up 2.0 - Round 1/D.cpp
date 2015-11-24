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

multiset<int> mys[4];
int n[4],t[4],c[4],k,res;
int main(){
    int res;
    freopen("input.txt","r",stdin);
    cin>>k>>n[1]>>n[2]>>n[3]>>t[1]>>t[2]>>t[3];
    res=0;
    for(int i=0; i<k; ++i){
        int time=0;
        for(int j=1; j<=3; ++j){
            if(sz(mys[j])<n[j]) mys[j].insert(time);
            else{
                int v=*mys[j].begin(); mys[j].erase(mys[j].begin());
                time=max(time,v+t[j]);
                mys[j].insert(time);
            }
            time+=t[j];
        }
    }
    while(!mys[3].empty()) res=max(res,*mys[3].begin()), mys[3].erase(mys[3].begin());
    cout<<res+t[3]<<endl;
}
