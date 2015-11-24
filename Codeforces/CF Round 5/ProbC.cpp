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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1000007;

char s[maxn];
int n, f[maxn],maxlen,c;
stack<int> mystack;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    gets(s);
    n=strlen(s);
    maxlen=0; c=1;
    REP(i,n)
        if(s[i]=='(') mystack.push(i), f[i]=-1;
        else
            if(mystack.empty()) f[i]=-1;
            else{
                f[i]=mystack.top(); mystack.pop();
                while(f[i]-1>=0 && s[f[i]-1]==')' && f[f[i]-1]!=-1) f[i]=f[f[i]-1];
                if(maxlen<i-f[i]+1) maxlen=i-f[i]+1, c=1;
                else if(maxlen==i-f[i]+1) c++;
            }
    cout<<maxlen<<' '<<c<<endl;
    //getch();
    return 0;
}
