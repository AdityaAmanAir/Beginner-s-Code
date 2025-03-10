#include<iostream>
#include<string>
using namespace std;

class Teacher{
    private:     //Access modifier
    double salary; //attributes

    //properties/ attributes
    public:      //Access specifier or modifier
    string name;
    string dept;
    string subject;
    double id;

    //methods/ member function
    int calRate(int star){
        return id*id;
    }
    //setter (it is a function who sets the value)
    void changeDept(string newDept){ 
        dept=newDept;
    }
    //getter (it is a function who gets the value)
    double getSalary(){
        return salary;
    }
};

int main(){
    Teacher t1;
    t1.name="Vaishali";
    cout<<t1.name<<endl;
    cout<<t1.subject; //Empty string
    cout<<t1.id; //Garbage value
    return 0;
}