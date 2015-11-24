
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

const int maxn=100007;

int n,m,a[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i) scanf("%d",&a[i]);
    char s[5];
    int v,pos=0;
    for(int i=0; i<m; ++i){
        scanf("%s%d",s,&v);
        if(s[0]=='A'){
            pos = (pos - v + n)%n;
        }else if(s[0]=='C'){
            pos = (pos + v)%n;
        }else{
            --v;
            printf("%d\n",a[(pos+v)%n]);
        }
    }
    return 0;
}
