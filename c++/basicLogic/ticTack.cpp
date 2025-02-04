#include <iostream>
#include <string>
using namespace std;

int main(){
   string first,  l0, l1, l2;
   string space = " ";
    getline(cin, first);
    getline(cin, l0);
    getline(cin, l1);
    getline(cin, l2);

    // this code could be made shorter as I saw patterns while going through all the case in a proper manner 


   if(((( l0[0]==first[0])||( l0[0]==space[0])) && (( l1[0]==first[0])) && (( l2[0]==first[0]))) || 
      ((( l0[1]==first[0])||( l0[1]==space[0])) && (( l1[1]==first[0])) && (( l2[1]==first[0]))) ||  
      ((( l0[2]==first[0])||( l0[2]==space[0])) && (( l1[2]==first[0])) && (( l2[2]==first[0]))) ||  

      ((( l0[0]==first[0])||( l0[0]==space[0])) && (( l0[1]==first[0])) && (( l0[2]==first[0]))) || 
      ((( l1[0]==first[0])||( l1[0]==space[0])) && (( l1[1]==first[0])) && (( l1[2]==first[0]))) ||  
      ((( l2[0]==first[0])||( l2[0]==space[0])) && (( l2[1]==first[0])) && (( l2[2]==first[0]))) || 

      ((( l0[0]==first[0])||( l0[0]==space[0])) && (( l1[1]==first[0])) && (( l2[2]==first[0]))) || 
      ((( l0[2]==first[0])||( l0[2]==space[0])) && (( l1[1]==first[0])) && (( l2[0]==first[0]))) ||
      


      ((( l0[0]==first[0])) && (( l1[0]==first[0])||( l1[0]==space[0])) && (( l2[0]==first[0]))) || 
      ((( l0[1]==first[0])) && (( l1[1]==first[0])||( l1[1]==space[0])) && (( l2[1]==first[0]))) ||  
      ((( l0[2]==first[0])) && (( l1[2]==first[0])||( l1[2]==space[0])) && (( l2[2]==first[0]))) ||  

      ((( l0[0]==first[0])) && (( l0[1]==first[0])||( l0[1]==space[0])) && (( l0[2]==first[0]))) || 
      ((( l1[0]==first[0])) && (( l1[1]==first[0])||( l1[1]==space[0])) && (( l1[2]==first[0]))) ||  
      ((( l2[0]==first[0])) && (( l2[1]==first[0])||( l2[1]==space[0])) && (( l2[2]==first[0]))) || 

      ((( l0[0]==first[0])) && (( l1[1]==first[0])||( l1[1]==space[0])) && (( l2[2]==first[0]))) || 
      ((( l0[2]==first[0])) && (( l1[1]==first[0])||( l1[1]==space[0])) && (( l2[0]==first[0]))) ||



      ((( l0[0]==first[0])) && (( l1[0]==first[0])) && (( l2[0]==first[0])||( l2[0]==space[0]))) || 
      ((( l0[1]==first[0])) && (( l1[1]==first[0])) && (( l2[1]==first[0])||( l2[1]==space[0]))) ||  
      ((( l0[2]==first[0])) && (( l1[2]==first[0])) && (( l2[2]==first[0])||( l2[2]==space[0]))) ||  

      ((( l0[0]==first[0])) && (( l0[1]==first[0])) && (( l0[2]==first[0])||( l0[2]==space[0]))) || 
      ((( l1[0]==first[0])) && (( l1[1]==first[0])) && (( l1[2]==first[0])||( l1[2]==space[0]))) ||  
      ((( l2[0]==first[0])) && (( l2[1]==first[0])) && (( l2[2]==first[0])||( l2[2]==space[0]))) || 

      ((( l0[0]==first[0])) && (( l1[1]==first[0])) && (( l2[2]==first[0])||( l2[2]==space[0]))) || 
      ((( l0[2]==first[0])) && (( l1[1]==first[0])) && (( l2[0]==first[0])||( l2[0]==space[0])))
      ){
    cout<<"Yes you can.";
   }else{
    cout<<"No you can't.";
   }
   //cout<<endl<<first<<endl<<l0<<endl<<l1<<endl<<l2<<endl<<"00 "<<l0[0]<<endl<<"01 "<<l0[1]<<endl<<"02 "<<l0[2]<<endl<<"10 "<<l1[0]<<endl<<"11 "<<l1[1]<<endl<<"12 "<<l1[2]<<endl<<"20 "<<l2[0]<<endl<<"21 "<<l2[1]<<endl<<"22 "<<l2[2];
    return 0;
}