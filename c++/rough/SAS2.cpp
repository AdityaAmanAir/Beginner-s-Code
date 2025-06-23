#include <iostream>
#include <vector>
#include <array>

using namespace std;
int main(){
array <int,6> myArray= {1,2,3,14,25,36};
vector <int> myVector= {9,8,7,6};
int target =17, n=myArray.size();
int i=0, j = n-1;
while (i<j){
    int pairsum = myArray[i] + myArray[j];
    if (pairsum> target) j--;
    else if (pairsum< target) i++;
        else {cout<< "found at "<< myArray[i] <<" and "<<myArray[j];
        break;}

}
    return 0;
}