#include <iostream>
#include <vector>

int main(){
    std::vector <char> verr={'A','B','C','x','y','5'};

    std::cout<< "size = "<< verr.size();

    verr.push_back('w'); // add the elements at the last only!

    std::cout<< "\nAfter push back, size = "<< verr.size()<<"\n"; 

    for (char val : verr){
        std::cout<<val<< " ";
    }

    verr.pop_back(); //olway pop last index value

    std::cout<<"\n";

    for (char val : verr){
        std::cout<<val<< " ";
    }
    std::cout<<"\n";

    std::cout<<verr.front()<<std::endl;
    std::cout<<verr.back()<<std::endl;

    std::cout<<verr.at(2)<<"\n";

    std::cout<< "Capicity  = "<< verr.capacity();
    return 0;
}