#include <iostream>
#include <algorithm>
#include <cstdio>
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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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
typedef pair<pii,int> iii;
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    string s;
    int i,n,t,j,a,b,len,dp[26][26];
    cin>>n;
    reset(dp,0);
    for(i=0;i<n;i++){
        cin>>s;
        a=(s[0]-'a'); b=s[s.length()-1]-'a';
        len=s.length();
        for(j=0;j<26;j++) if (dp[j][a]) dp[j][b]=max(dp[j][b],dp[j][a]+len);
        dp[a][b]=max(dp[a][b],len);
    }
    t=0; for(j=0;j<26;j++) t=max(t,dp[j][j]);
    cout<<t<<endl;
    //getch();
    return 0;
}
