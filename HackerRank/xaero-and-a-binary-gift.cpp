#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string a,b;
int c1,c2;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>a>>b;
    if(sz(a)!=sz(b)){
        cout<<-1<<endl;
        return 0;
    }
    c1=c2=0;
    int res=0;
    for(int i=0; i<sz(a); ++i){
        if(a[i]=='1') ++c1;
        if(b[i]=='1') ++c2;
        if(a[i]!=b[i]) ++res;
    }
    if(c1!=c2){
        cout<<-1<<endl;
        return 0;
    }
    cout<<res/2<<endl;
}

