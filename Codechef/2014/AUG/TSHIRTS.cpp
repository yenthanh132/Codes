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


bool a[107][17];
ll f[107][1<<10];
int T,n;

int main(){
    //freopen("input.txt","r",stdin);
    cin>>T;
    for(int tt=1; tt<=T; ++tt){
        cin>>n;
        reset(a,0);
        string line;
        getline(cin,line);
        for(int i=0; i<n; ++i){
            getline(cin,line);
            stringstream ss;
            ss<<line;
            int v;
            while(ss>>v) a[v][i]=1;
        }
        reset(f,0);
        f[0][0]=1;
        for(int v=1; v<=100; ++v)
            for(int mask=0; mask < (1<<n); ++mask){
                f[v][mask]=f[v-1][mask];
                for(int i=0; i<n; ++i) if(a[v][i] && (mask>>i&1)) f[v][mask] += f[v-1][mask & ~(1<<i)];
                f[v][mask]%=oo;
            }
        cout<<f[100][(1<<n)-1]<<endl;
    }
}
