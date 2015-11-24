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



int n,T;
char s[100001];

int main(){
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%s",s);
        n=strlen(s);
        int r=0;
        for(int i=0,j; i<n; i=j+1){
            j=i;
            while(j+1<n && s[j+1]==s[i]) ++j;
            ++r;
        }
        printf("%d\n",n-r);
    }
    return 0;
}
