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

const int maxn=4007;
vector<int> list[maxn];
int n,a[maxn],b[maxn];
map<int,int> mm;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]), mm[a[i]]++;
    int res=0,v,c;
    for(map<int,int>::iterator it=mm.begin(); it!=mm.end(); it++) res=max(res,it->se);
    mm.clear(); c=0;
    FOR(i,1,n){
        if(mm[a[i]]==0){
            mm[a[i]]=++c;
            b[c]=a[i];
        }
        list[mm[a[i]]].pb(i);
    }
    FOR(i,1,c-1) FOR(j,i+1,c){
        v=0;
        int x=0, y=0, z=0;
        while(x<sz(list[i]) || y<sz(list[j])){
            if(y>=sz(list[j]) || (list[i][x]<list[j][y])){
                if(z!=b[i]){
                    v++;
                    z=b[i];
                }
                x++;
            }else{
                if(z!=b[j]){
                    v++;
                    z=b[j];
                }
                y++;
            }
        }
        res=max(res,v);
    }
    printf("%d\n",res);
    return 0;
}
    
    
