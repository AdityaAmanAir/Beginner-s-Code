#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n!=0){
            bool negative = false;
            if (x<0){
                x=-x;
                negative = true;
            }
            int k =n;
            if (n<0){
                x=1/x;
                n=-n;
                }
            double y=x;    
            int count =0, m=n;
            if (k!=-1 && k!=1){
            while (1<m){
                count++;
                m/=2;    
            }
            int two=1;
            for (int i =0; i<m;i++){
                x*=x;
                two*=2;
            }
            int loope = n-two;
            for (int i=0; i<loope; i++){
                x*=y;
            }
            if(n%2!=0 && negative == true){return -x;}
            return x;
            }else{
                if(n%2!=0 && negative == true){return -x;}
            return x;
            }
        }else{
            return 1;
        }
        
    }
};

int main(){
    Solution s;
    int t,n;
    double x;
    cin>>t;
    while(t--){
        cin>>x>>n;
        cout<<s.myPow(x,n);
}
}