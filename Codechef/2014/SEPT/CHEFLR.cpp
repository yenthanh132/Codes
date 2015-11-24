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

char s[100007];
int n;

int main(){
    //freopen("input.txt","r",stdin);

    int T;
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%s",s);
        n=strlen(s);
        ll v=1;
        for(int i=0; i<n; ++i)
            if(i&1){
                if(s[i]=='l') v=(v*2+oo-1)%oo;
                else v=(v*2+1)%oo;
            }else{
                if(s[i]=='l') v=v*2%oo;
                else v=(v+1)*2%oo;
            }
        printf("%lld\n",v);
    }
    return 0;
}
