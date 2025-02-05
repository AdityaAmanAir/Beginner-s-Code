#include <iostream>
#include <string>
using namespace std;

int main(){
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   if(a+b+c==100){
      cout<<"Train 1, Train 2 and Train 3\nTrain 4";
   }else if(a+b+d==100){
      cout<<"Train 1, Train 2 and Train 4\nTrain 3";
   }else if(a+d+c==100){
      cout<<"Train 1, Train 3 and Train 4\nTrain 2";
   }else if(d+b+c==100){
      cout<<"Train 1\nTrain 2 Train3 and Train 4";
   }else if(a+b==100){
      cout<<"Train 1 and Train 2\nTrain 3 and Train 4";
   }else if(a+c==100){
      cout<<"Train 1 and Train 3\nTrain 2 and Train 4";
   }else if(a+d==100){
      cout<<"Train 1 and Train 4\nTrain 2 and Train 3";
   }
    return 0;
}