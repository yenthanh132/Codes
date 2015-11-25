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
typedef pair<char, int> pci;

#define maxn 100007

struct node{char ch; int v; node *left, *right;} *tree;
struct rnode{char ch; int v;};
int n,a[maxn],pos;
char type[maxn];
vector<int> num;
vector<char> syn;

node* buildtree(){
    if(pos==0) return NULL;
    node *p=new node;
    p->ch=type[pos];
    if (type[pos]=='#') p->v=a[pos]; else p->v=0;
    pos--;
    if (p->ch!='#'){
        p->right=buildtree();
        p->left=buildtree();
    }else p->right=p->left=NULL;
    return p;
}

void printQPN(){
    queue<node*> myqueue;
    vector<pci> ds;
    myqueue.push(tree);
    while (!myqueue.empty()){
        node *u=myqueue.front(); myqueue.pop();
        ds.pb(pci(u->ch,u->v));
        if(u->left!=NULL){
            myqueue.push(u->right);
            myqueue.push(u->left);
        }
    }
    for(int i=n-1; i>=0; i--)
        if(ds[i].fi=='#') printf("%d ",ds[i].se); else printf("%c ",ds[i].fi);
    printf("\n");
}

void dfs(node *p, int v){
    if(p->ch=='#'){
        if(v==1) p->v = -p->v;
    }else{
        if(p->ch=='-'){
           p->ch='+';
           dfs(p->left,v);
           dfs(p->right,1-v);
        }
        else if(p->ch=='*' && v==1){
            dfs(p->left,v);
            dfs(p->right,1-v);
        }else{
            dfs(p->left,v); 
            dfs(p->right,v);
        }
    }
}
    
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d\n",&n);
    char ch=' ';
    int v,i=0,j,c=0;
    string s;
    getline(cin,s);
    while(c<n){
        while(i<s.length() && s[i]==' ') i++;
        j=i; while(j<s.length() && s[j]!=' ') j++;
        c++;
        if(j-i>1 || ('0'<=s[i] && s[i]<='9')){
            type[c]='#';
            a[c]=atoi(s.substr(i,j-i).c_str());
        }else{
            type[c]=s[i];
            a[c]=0;
        }
        i=j+1;
    }
    pos=n;
    tree=buildtree();
    printQPN();
    dfs(tree,0);
    printQPN();
    //getch();
    return 0;
}
            
    
