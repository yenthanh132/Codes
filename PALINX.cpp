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

const int maxn=1000007;
const int hashbase=73471;

ll pw[maxn],val[maxn],val2[maxn];

int n, root;
vector<int> s[maxn];
char buf[maxn];


struct node{
    int v;
    int next[26];
} trie[maxn];
int cnt;

int new_node(){
    ++cnt;
    trie[cnt].v=0;
    for(int i=0; i<26; ++i) trie[cnt].next[i]=-1;
    return cnt;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    pw[0]=1;
    for(int i=1; i<=1000000; ++i) pw[i]=pw[i-1]*hashbase;

    ll res = 0;

    cnt=0;
    root = new_node();
    for(int i=1; i<=n; ++i){
        int len;
        scanf("%d%s",&len,buf);
        s[i].resize(len);

        for(int j=0; j<len; ++j) s[i][j]=buf[j]-'a';
        int p=root;
        for(int j=len-1; j>=0; --j){
            int v=s[i][j];
            if(trie[p].next[v]==-1) trie[p].next[v]=new_node();
            p=trie[p].next[v];
        }
        ++trie[p].v;
    }


    for(int i=1; i<=n; ++i){
        int len=sz(s[i]);
        val[0]=0; val2[len+1]=0;
        for(int j=1; j<=len; ++j) val[j]=val[j-1]*hashbase + s[i][j-1];
        for(int j=len; j>=1; --j) val2[j]=val2[j+1]*hashbase + s[i][j-1];
        int p=root;
        for(int j=1; j<=len; ++j){
            int v=s[i][j-1];
            if(trie[p].next[v]==-1) break;
            p=trie[p].next[v];
            if(trie[p].v > 0){
                int left2 = (len-j)/2;
                if(left2 == 0 || val2[len - left2 + 1] == val[j+left2] - val[j]*pw[left2]) res += trie[p].v;
            }
        }
    }

    //Reverse strings and do it again
    cnt=0;
    root = new_node();
    for(int i=1; i<=n; ++i){
        int len=sz(s[i]);
        reverse(s[i].begin(),s[i].end());
        int p=root;
        for(int j=len-1; j>=0; --j){
            int v=s[i][j];
            if(trie[p].next[v]==-1) trie[p].next[v]=new_node();
            p=trie[p].next[v];
        }
        ++trie[p].v;
    }


    for(int i=1; i<=n; ++i){
        int len=sz(s[i]);
        val[0]=0; val2[len+1]=0;
        for(int j=1; j<=len; ++j) val[j]=val[j-1]*hashbase + s[i][j-1];
        for(int j=len; j>=1; --j) val2[j]=val2[j+1]*hashbase + s[i][j-1];
        int p=root;
        for(int j=1; j<len; ++j){ // a little different from the first time
            int v=s[i][j-1];
            if(trie[p].next[v]==-1) break;
            p=trie[p].next[v];
            if(trie[p].v > 0){
                int left2 = (len-j)/2;
                if(left2 == 0 || val2[len - left2 + 1] == val[j+left2] - val[j]*pw[left2]) res += trie[p].v;
            }
        }
    }

    cout<<res<<endl;

    return 0;
}
