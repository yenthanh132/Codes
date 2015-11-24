#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;

int a[maxn];

int main(){
    cin>>a[1];
    for(int len=2; ; len*=2){
        for(int i=2; i<=len; ++i){
            cout<<"R"<<endl;
            cout.flush();
            cin>>a[i];
        }
        cout<<"S"<<endl;
        cout.flush();
        for(int i=len-1; i>=1; --i){
            cout<<"L"<<endl;
            cout.flush();
            int x;
            cin>>x;
            if(a[i]!=x){
                cout<<len-i<<endl;
                return 0;
            }
        }
    }
}

