
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
#include <cassert>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxs = 307;
const int dx[2]={-1,-2};
const int dy[2]={-2,-1};

int arr[6][maxs][maxs],mark[maxs*maxs];

int main(){
    freopen("input.txt","r",stdin);
    for(int x=1; x<=5; ++x){
        reset(mark,0);
        int idx = 0;
        //int maxv = 0;
        for(int i=0; i<=300; ++i) for(int j=0; j<=300; ++j){
            ++idx;
            for(int y=1; y<=x; ++y){
                for(int v=0; v<(1<<y); ++v){
                    int i2=i, j2=j;
                    for(int k=0; k<y; ++k){
                        int t = v>>k&1;
                        i2+=dx[t];
                        j2+=dy[t];
                    }
                    if(i2>=0 && j2>=0) mark[arr[x][i2][j2]] = idx;
                }
            }
            int v = 0;
            while(mark[v]==idx) ++v;
            arr[x][i][j]=v;
            //maxv = max(maxv,v);
        }
        //cout<<maxv<<endl;
    }

    int T,x,n,k;
    scanf("%d",&T);
    map<int,int> mm;
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d%d",&n,&k,&x);
        int i,j;
        int v = 0;
        mm.clear();
        for(int r=0; r<n; ++r){
            scanf("%d%d",&i,&j);
            mm[arr[x][i][j]]++;
        }
        bool found = 0;
        for(map<int,int>::iterator it = mm.begin(); it!=mm.end(); ++it)
            if(it->first > 0 && it->second%(k+1)!=0)
                found = 1;
        if(found) puts("First player wins");
        else puts("Second player wins");
    }
}
