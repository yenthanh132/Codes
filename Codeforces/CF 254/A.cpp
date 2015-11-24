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

const int maxn=107;

int n,v[maxn];
string a[maxn];
int per[15];

int toint(char s){
    if(s=='R') return 0;
    if(s=='G') return 1;
    if(s=='B') return 2;
    if(s=='Y') return 3;
    if(s=='W') return 4;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    sort(a,a+n);
    n = unique(a,a+n)-a;
    int res = oo;
    for(int i=0; i < (1<<10); ++i){
        for(int k=0; k<n; ++k) v[k]=0;
        int cnt = 0;
        for(int j=0; j<10; ++j) if(i>>j&1){
            for(int k=0; k<n; ++k)
                if((j<5 && j==toint(a[k][0])) || (j>=5 && j-5==a[k][1]-'1'))
                    v[k]|=1<<cnt;
            ++cnt;
        }
        bool ok=1;
        for(int j=0; j<n; ++j)
            for(int k=j+1; k<n; ++k) if(v[j]==v[k]) ok=0;
        if(ok) res=min(res,cnt);
    }
    cout<<res<<endl;
    return 0;
}
