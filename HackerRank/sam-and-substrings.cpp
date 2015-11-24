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

using namespace std;

const int oo=1000000007;
char s[200007];
int n;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",s+1);
    n=strlen(s+1);
    long long res=0, sum=0, cnt=1;
    for(int i=1; i<=n; ++i){
        sum = (sum*10 + i*(s[i]-'0'))%oo;
        res = (res + sum) %oo;
    }
    printf("%lld\n",res);
}
