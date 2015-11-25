#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n=0,d=0; char ch;
    struct node{char ch; int c;}a[100000];
    cin>>ch;
    while (!cin.eof()){
        if (n==0 || a[n].ch!=ch){
            a[++n].ch=ch;
            a[n].c=1;
        }else if (a[n].ch==ch) a[n].c++;
        cin>>ch;
        
    }
    for(int i=1;i<=n;i++){
        if (a[i].c>1) d++;
        if (1<i<n && a[i-1].ch==a[i+1].ch && a[i].c==1) d--;
    }
    printf("%lld",(long long)n*(n-1)/2+d);
    return 0;
}
    
    
