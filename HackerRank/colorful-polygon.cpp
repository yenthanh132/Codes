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

const int maxn=200007;

int n,a[maxn],pos[maxn];
ll p2[maxn];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]), a[i+n]=a[i];
    reset(pos,-1);
    int first,last,best=oo;
    for(int i=1; i<2*n; ++i){
        if(pos[a[i]]!=-1 && best > i-pos[a[i]]){
            best = i-pos[a[i]];
            first=pos[a[i]];
            last=i;
        }
        pos[a[i]]=i;
    }

    p2[0]=1;
    for(int i=1; i<=n; ++i) p2[i]=p2[i-1]*2%oo;

    if(best==oo){
        cout<<p2[n]-n-1;
        return 0;
    }



}
