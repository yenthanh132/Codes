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

const int maxn=100007;

int n,p;
ll a,b,c;
int arr[maxn*2];
//#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    string s;
    cin>>s;
    while(s!="[END]"){
        cin>>n>>p>>a>>b>>c;
        //cout<<n<<' '<<p<<endl;
        if(n&1) cout<<0<<endl;
        else{
            int id=0,c;
            REP(i,p) arr[++id]=((a*i)*i+b*i+c)%n;
            sort(arr+1,arr+p+1);
            FOR(i,1,p) arr[i+p]=arr[i]+n;
            c=0;
            FOR(i,2,p*2)
                if(arr[i]<=arr[i-1]){
                    arr[i]=arr[i-1]+1;
                    if(i>p) arr[i-p]=arr[i]-n; else arr[i+p]=arr[i]+n;
                }
            ll res=0;
            int j=1;
            FOR(i,1,p){
                while(arr[i]+n/2>arr[j]) j++;
                if(arr[i]+n/2==arr[j]) res+=j-i-1;
            }
            cout<<res<<endl;
        }
            
        cin>>s;
    }
    //getch();
    return 0;
}
        
    
