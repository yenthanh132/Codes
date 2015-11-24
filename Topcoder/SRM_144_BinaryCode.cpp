#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ton(i) (int(i)-48)

class BinaryCode{
    public:
    vector <string> decode(string message){
        vector <string> res;
        string s=message;
        int n=s.size(),i,j,k,a[50];
        bool ok=false;
        for(k=0;k<=1;k++){
            if (n==1) {
                if (ton(s[0])==k) res.push_back(message); else res.push_back("NONE");
                continue;
            }
            a[0]=k;  
            for(i=0;i<=1;i++){
                a[1]=i;
                if (ton(s[0])!=a[0]+a[1]) continue;
                
                ok=true;
                for(j=2;j<n;j++){
                    a[j]=ton(s[j-1])-a[j-1]-a[j-2];
                    if (a[j]<0 || a[j]>1){ok=false; break;}
                }
                if (ton(s[n-1])!=a[n-1]+a[n-2]) continue;
                if (ok){
                    string ss=""; 
                    for(j=0;j<n;j++) ss+=char(a[j]+48); 
                    res.push_back(ss);
                }
            }
            
            if (res.size()==k) res.push_back("NONE");
        }
        return res;
    }
};

int main(){
    return 0;
}
