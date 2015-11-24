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

int x,y,T;

bool found(int x, int y){
    int bot = oo, top = -oo;
    if(x&1 && x>0){
        bot = -x + 1;
        top = bot + x*2;
    }
    if(x%2==0 && x<=0){
        top = -x;
        bot = x;
    }
    if(bot <=y && y <= top) return 1;

    bot = oo; top = -oo;
    if(y%2==0){
        if(y>0){
            bot = -y;
            top = y-1;
        }else{
            bot = y;
            top = -y + 1;
        }
    }
    if(bot <=x && x <= top) return 1;

    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&x,&y);
        if(found(x,y)) puts("YES");
        else puts("NO");
    }
}
