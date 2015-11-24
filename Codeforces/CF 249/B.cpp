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

ll a;
int k,n,arr[22];

int find(int i, int v){
    FORD(j,i,1) if(arr[j]==v) return j;
    return 0;
}

void sswap(int i, int j){
    FOR(x,j+1,i) swap(arr[x],arr[x-1]);
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>a>>k;
    n=0;
    while(a){
        arr[++n]=a%10;
        a/=10;
    }
    FORD(i,n,1){
        FORD(v,9,1){
            int p=find(i,v);
            if(p!=0 && i-p<=k){
                sswap(i,p);
                k-=i-p;
                break;
            }
        }
    }
    FORD(i,n,1) cout<<arr[i];
    cout<<endl;
    return 0;
}

