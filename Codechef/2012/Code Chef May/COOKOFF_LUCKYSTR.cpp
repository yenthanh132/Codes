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
int main(){
    int n,k;
    cin>>k>>n;
    string a[50],s;
    REP(i,k) cin>>a[i];
    REP(i,n){
        cin>>s;
        if(s.length()>=47) cout<<"Good"<<endl;
        else{
            bool ok=false;
            REP(j,k) if (s.find(a[j])!=string::npos) {ok=true; break;}
            if (ok) cout<<"Good"<<endl; else cout<<"Bad"<<endl;
        }
    }
    return 0;
}
