#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
//    freopen("input.txt","r",stdin);
    string s;
    int n;

    ll row=1,col=1;

    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>s;
        if(s=="ULDR"){
            row++;
            col++;
        }else if(s=="UL" || s=="DR"){
            col++;
        }else{
            row++;
        }
    }
    cout<<row*col;
}

