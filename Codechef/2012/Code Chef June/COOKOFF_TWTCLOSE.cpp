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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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
typedef pair<pii,int> iii;

int main(){
    string s;
    //freopen("test.txt","r",stdin);
    vector<int> list;
    bool open[1001]; reset(open,0);
    int n,k,count=0,v;
    cin>>n>>k;
    REP(i,k){
        cin>>s;
        if(s=="CLICK"){
            cin>>v;
            if(!open[v]){
                open[v]=1;
                list.pb(v);
                count++;
            }else{
                open[v]=0;
                count--;
            }
        }else{
            while(!list.empty()){open[list[sz(list)-1]]=0; list.pop_back();}
            count=0;
        }
        printf("%d\n",count);
    }
    return 0;
}
            
