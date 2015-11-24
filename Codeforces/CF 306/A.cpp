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
    cin>>s;
    for(int i=0; i<sz(s)-1; ++i)
        if(s[i]=='A' && s[i+1]=='B'){
            for(int j=i+2; j<sz(s)-1; ++j)
                if(s[j]=='B' && s[j+1]=='A'){
                    cout<<"YES"<<endl;
                    return 0;
                }
            break;
        }
    for(int i=0; i<sz(s)-1; ++i)
        if(s[i]=='B' && s[i+1]=='A'){
            for(int j=i+2; j<sz(s)-1; ++j)
                if(s[j]=='A' && s[j+1]=='B'){
                    cout<<"YES"<<endl;
                    return 0;
                }
            break;
        }
    cout<<"NO"<<endl;
}

