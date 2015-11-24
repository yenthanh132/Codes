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
char s[maxn];
int n,len;
int ca[2],cb[2];
ll r1,r2;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%s",s+1);
    len=strlen(s+1);
    reset(ca,0); reset(cb,0);
    r1=r2=0;
    for(int i=1; i<=len; ++i){
        if(s[i]=='a'){
            ca[i&1]++;
            r1 += ca[i&1];
            r2 += ca[(i&1)^1];
        }else{
            cb[i&1]++;
            r1 += cb[i&1];
            r2 += cb[(i&1)^1];
        }
    }
    cout<<r2<<' '<<r1<<endl;
    return 0;
}

