#include <iostream>
using namespace std;
int main(){
    int marks[5]={99,100,98,87,97};
    int mark[50]={999,1000,908,807,907};
    double id[]={2.99,3.87,4.001};
    int input[5];

    cout<<marks[3]<<" "<<mark[4]<<" "<<marks[5]<<" "<<mark[-1]<<" "<<mark[40]<<" "<<mark[400];
    int sz = sizeof(marks);
    int len = sizeof(marks)/sizeof(int);
    int len1 = sizeof(mark)/sizeof(int);
    int len2 = sizeof(id)/sizeof(double);
    cout<<endl<<sz<<" "<<len<<" "<<len1<<" "<<len2<<endl<<endl;

    for(int i=0; i<len1+50;i++){
        marks[i]=marks[i]+1;
        cout<<marks[i]<<" "<<mark[i]<<endl;
    }
    for(int i=0; i<len1+50;i++){
        cout<<marks[i]<<" "<<mark[i]<<endl;
    }



    int len_input =sizeof(input)/sizeof(int);

    for(int i=0; i<len_input+3;i++){
        cin>>input[i];
    }
    cout<<"-------------\n";
    for(int i=0; i<len_input+9;i++){
        cout<<input[i]<<endl;
    }

    return 0;
}