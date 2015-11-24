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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=507;

map<string,double> res;
int T;
double mat[maxn][maxn];

string normalize(string s){
    int val[26]; reset(val,-1);
    int v=0;
    for(int i=0; i<sz(s); ++i) if(val[s[i]-'a']==-1) val[s[i]-'a']=v++;
    for(int i=0; i<sz(s); ++i) s[i]=val[s[i]-'a']+'a';
    return s;
}

bool ispalindrome(string s){
    int len=sz(s);
    for(int i=0; i<len/2; ++i) if(s[i]!=s[len-i-1]) return 0;
    return 1;
}

double solve(string s){
    s = normalize(s);
    string original = s;
    if(res.find(s)!=res.end()) return res[s];
    sort(s.begin(), s.end());
    vector<string> arr;
    do{
        string t=normalize(s);
        arr.pb(t);
    }while(next_permutation(s.begin(),s.end()));
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(),arr.end())-arr.begin());
    int n = sz(arr);
    //init the matrix
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) mat[i][j]=0;
    for(int i=0; i<n; ++i){
        mat[i][i]=1;
        if(ispalindrome(arr[i])) continue;
        mat[i][n]=1;
        string s=arr[i];
        int len = sz(s);
        double prop = 2.0/len/(len-1);
        for(int x=0; x<len; ++x) for(int y=x+1; y<len; ++y){
            swap(s[x],s[y]);
            string t=normalize(s);
            int id = lower_bound(arr.begin(),arr.end(),t)-arr.begin();
            mat[i][id] -= prop;
            swap(s[x],s[y]);
        }
    }
    //gauss
    for(int i=0; i<n; ++i){
        for(int j=n; j>=i; --j) mat[i][j]/=mat[i][i];
        for(int j=0; j<n; ++j) if(i!=j)
            for(int k=n; k>=i; --k)
                mat[j][k] -= mat[j][i] * mat[i][k];
    }

    //get result
    for(int i=0; i<n; ++i) res[arr[i]] = mat[i][n];
    return res[original];
}

int main(){
    //freopen("input.txt","r",stdin);
    string s;
    char sc[10];
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%s",sc);
        printf("%0.4lf\n",solve(string(sc)));
    }
    return 0;
}
