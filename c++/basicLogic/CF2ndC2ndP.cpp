#include <iostream>
#include<cmath>
using namespace std;
double sum(double a){
    double f=0;
        f=((a)*(a+1))/2;
    
    return f;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        double a,b;
        bool jj=false;
        float c;
        cin>>a;
        b=sum(a);
        c= sqrt(b);
        if(c==(int)c){
            cout<<-1;
            jj=true;
        }
        if(jj==false){
            for (int i = 1; i <=a; i++)
            {
                if((i==1)||(i==8)||(i==49)||(i==288)||(i==1681)||(i==9800)||(i==57121)||(i==332928)){
                    continue;
                }
                cout<< i<<" ";
                if((i==2)||(i==9)||(i==50)||(i==289)||(i==1682)||(i==9801)||(i==57122)||(i==332929)){
                    cout<<i-1<<" ";
                }
            }
            

        }cout<<"\n";
        
    }
    return 0;
}