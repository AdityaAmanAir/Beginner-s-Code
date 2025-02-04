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
   if(((( l0[0]==first[0])||( l0[0]==space[0])) && (( l1[0]==first[0])||( l1[0]==space[0])) && (( l2[0]==first[0])||( l2[0]==space[0]))) || 
      ((( l0[1]==first[0])||( l0[1]==space[0])) && (( l1[1]==first[0])||( l1[1]==space[0])) && (( l2[1]==first[0])||( l2[1]==space[0]))) ||  
      ((( l0[2]==first[0])||( l0[2]==space[0])) && (( l1[2]==first[0])||( l1[2]==space[0])) && (( l2[2]==first[0])||( l2[2]==space[0]))) ||  

      ((( l0[0]==first[0])||( l0[0]==space[0])) && (( l0[1]==first[0])||( l0[1]==space[0])) && (( l0[2]==first[0])||( l0[2]==space[0]))) || 
      ((( l1[0]==first[0])||( l1[0]==space[0])) && (( l1[1]==first[0])||( l1[1]==space[0])) && (( l1[2]==first[0])||( l1[2]==space[0]))) ||  
      ((( l2[0]==first[0])||( l2[0]==space[0])) && (( l2[1]==first[0])||( l2[1]==space[0])) && (( l2[2]==first[0])||( l2[2]==space[0]))) || 

      ((( l0[0]==first[0])||( l0[0]==space[0])) && (( l1[1]==first[0])||( l1[1]==space[0])) && (( l2[2]==first[0])||( l2[2]==space[0]))) || 
      ((( l0[2]==first[0])||( l0[2]==space[0])) && (( l1[1]==first[0])||( l1[1]==space[0])) && (( l2[0]==first[0])||( l2[0]==space[0]))) ){
    cout<<"Yes you can.";
   }else{
    cout<<"No you can't.";
   }
    return 0;
}