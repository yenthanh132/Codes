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

void pr(int a, int b, int c, char ch){
    printf("%d %c %d = %d\n",a,ch,b,c);
}

int main(){
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    if(n<4) puts("NO");
    else if(n==5){
        puts("YES");
        pr(4,2,2,'-');
        pr(5,1,4,'-');
        pr(2,3,6,'*');
        pr(6,4,24,'*');
    }else{
        puts("YES");
        pr(2,3,6,'*');
        pr(6,4,24,'*');
        if(n==4){
            pr(1,24,24,'*');
        }else{ //n>=6
            pr(6,5,1,'-');
            pr(1,1,0,'-');
            for(int v=7; v<=n; ++v) pr(0,v,0,'*');
            pr(24,0,24,'+');
        }
    }
    return 0;
}
