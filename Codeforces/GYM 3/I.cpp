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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char str[20];

int cal()
{
    int i,j,k,n,t;
    char ch;
    n = strlen(str);
    int ans = 0;
    int sum;
    while (1)
    {
        i = 0,j = n-1,sum = 1;
        while (i<=j && str[i]==str[j])
              ++i,--j,sum*=10;
        if (i>j)    
            break;
        ch = str[i];
        if (ch > str[j])
            k = ch - str[j];
        else
            k = 10 + ch - str[j];
        ans += k*sum;
        if (str[j] > ch)
        {
            t = j-1;
            while (t>=0 && str[t]+1>'9')
            {
                str[t--] = '0';
            }
            ++str[t];
        }
        str[j] = ch;
    }
    return ans;
}

int main()
{
    int i,j,k,n,m;
    while (scanf("%s",str)!=EOF){
        n = strlen(str);
        if (1 == n){
            if ('0' == str[0]) break;
            else printf("0\n");
        }
        printf("%d\n",cal());
    }
    return 0;
}


