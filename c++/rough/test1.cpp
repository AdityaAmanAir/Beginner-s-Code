
#include <iostream>
#include <cmath>
using namespace std; // Boilerplate code,    #include <iostram>
                     // using namespace std;
                     // int main(){

//     return 0
// }
// comment, use // it is called single line comment , and /* xyz*/ /*is multi line comment  , shortcut select the text and press ctrl +     . It saves my time for now else i have to write std::cout everywhere it required 
int main() //std means standerd it represent that the globle object such as cout is taken from standerd convension, std::cout, std::endl, using namespace std;
{                      // >>, << are called overloaded operators 
    
    cout<<"Hello World\n";
    printf("Omg World");

    
    cout << "My name is Aditya \n Aman" <<"\n"; // <<"\n" is faster then <<endl
    int a = 2147483649; // I observed that if I write a = from -2147483649 to +212147483647 it display same, but from 2147483648 to 4294967296 the vale get started from -1 to -2147483648, apart from this it shows format error which is obvious because 4 bytes of space 1 byte store 8 bits that is 32, emplies 2^32 data space
    int b = 2147483646; // ( its Called) data type - int, char, float, bool, double thers are common data type and also called primitive data type
    int c = 4294967292 ; // 1 bit can store 2 values (data) i.e. 1 or 0 , 1 bytes has 8 bits.
    int d = -4;          // int has 4 bytes i.e 32 bits i.e 2^32 data (1 or 0)
    int x =0, y= -1, z=100;
    int m=1 , n =2, o =3 , p= 5, q= 7;

    //if you need to set the value of a variable as constant and it should not change through out the program than use const int uid = 65069960

    const int uid = 65069960;
                           // char has 1 byte
    cout << a <<endl;
    cout << b << "\n" ;    // Don't forget to terminate the sentence by using ;
    cout << c <<endl;          // -4
    cout << d <<endl;         // -4
    cout << "This is size of a in bytes i.e 4 bytes of int. " << sizeof(a) <<endl; // Here I forgot to use << after writing the statemen . Use << if you are running more then one task in one line 
    char Character = 'A' ;    // I did an error here , insted of using '' I used "" which is wrong for char , i am writing any statement here so use ''
    char grade = 'mk cf' ;    // i observed that, chat stores only one letter (ofcourse because of less space allotment) , in this if i try to write more then one charecters then it will take the last charecter of the word/ sentence as an variable
    cout << Character << " " << grade <<endl;
    string sentence = 'HII bro' // strings are immutable that is they cannot be change in between after they are defined 

    float PI = 3.1415926f;     // if we need the values of variable in decimel the we use float 
     cout << PI << endl;              // float 4 Bytes , up to 5 decimels, decimel is also called float values 
    //Good programmers thing: They assign the variable of constant in CAPTIAL letters only (The values which will be same through out the programm) example PI , E , etc..
     float E = 2.7182182;
     cout << E << endl; // if we don't use f after writing the value, compiler will assume it as double instee of float
    
    bool _is_it = false; // bool i.e boolen data type has only true or false  (only!!) value in it and has 1 byte reserve.    writing anything otherther true or false is not valid! Not even TrUe or FALSE is allowed , all character should be small
    bool it_is = true;
    cout << it_is << endl; // True -> 1 , false -> 0       it will print 1 for true and 0 for false and not the word true or false
    
    double f = 100.77; // doulbe has 8 bytes and it is double of float
    //100.99 // if we write any number like 100.99 bydefalt it will be double, I removed the number from code because it was generating error uing //
    
    // Type Casting , are of 2 type conversion (it is done defalt by compiler (implicite process) small to big data type) and casting ( Explicit )
char Grade = 'A';
int value = Grade ;
cout << Grade <<  " " << value << endl; // A has ascii Value 65, a has 97

double price = 100.999;
double price2 = 222.11;
int Newprice = price ;
(int)price2 ;
cout << Newprice << " " << price <<" "<< price2 << " "<<(int)price2 << endl; // (int)price was use to change the data type as it was double data type and got converted into int
    // input in c++, cin >> intput
    
    int _a;
    cout << _a << endl; // if we don't assign any vale to the variable then it will take any random value, it called garbage value.
    
    int age;
    cout << " What is your age? - ";
    cin >> age; // program will not run more untill the input has been feeded
    cout << "What! your age is " << age<< endl; ///////////// Cin , cout are not functions it is called globel object!
    //Operators,  first type of operator is Arithmetic , other two are Relational and logical operators. 
    int sum = m + n ;
    cout << sum << endl;
    float ss=0.1, sa=0.2; float sz=(ss + sa);
    cout<< (0.2 +0.1)<< endl<<(ss + sa)<<endl<< sz;
    cout << (p+q) << endl; // +, - , / , % (modulo), *
    cout << "a ="<<(a)<< " and a + a = "<< (a+a) << endl;
    cout << (5/2) << endl; // ans is 2 because it has int/ int i.e int  as data type, 
cout << (5/(double)2) << endl; // ans was 2.5 because it has int / double i.e double data type. 
                            // output data type will be decided in the basic of lagest data type present in the equation ,EXAMPLE : if we do any operation between floot and double the output will have floot data type because it is the biggest datatype in the entire fuction.
    //RELATIONAL OPERATORS , <,<=,>,>=,==,!=
    cout << (3<5) << endl; // true ->1 
    cout << (7<3) << endl; // false ->0
    cout << (2<=5) << " "  << (5<=5)<< endl; // 1 1
    cout << (3!=3)<< endl;  // operators always return boolian value that is 0 or 1
    
    //Logical Operations, OR || (pipe), AND && (ampersant), NOT !
    cout << !(3>1)<< endl; // i used ! and the answer got inverted from true(1) to false (0)
    cout << ((3<=3) || (2 < 7)) ;
    cout << ((1>2) || (5<7)); 
    cout << ((-2 > 1) || (2>777)) << endl;
    cout << ((3<=3) && (2 < 7)) ;
    cout << ((1>2) && (5<7));  // Don't forget to to use () , if you missed to use () it will take omly the first equation !
    cout << ((-2 > 1) && (2>777));
     // UNARY OPERATORS , { increment a = a-1 --> a++ or ++a}, {Decrement a = a-1 --> a-- or --a}
    cout << "m= "<<  m << endl; //m = 1
    m++;       // m++ means work then increment, ==m means increment first then work,
    cout << m; // m = 2
 int w = m++ ;  //w =2 , and m will become 3
 cout << w << m ; // if you wrote cout << w, m ; the compiler will print only w and not m because you didnot use <<
 
    // Conditional Staements [(if-else) syntax (rules), ()]

 if (age>=18){ 
    cout << endl << "You are a adult"<< endl;
    if (age%2==0){
    cout << "You age is even\n";
    }else {
        cout << "Your age is odd";
    } 

 } else { 
    cout << "\nYou are a minor, I will not tell what kind of number is your age\n";
 }
 cout << (int)Grade << "\n"; 
    // ternary statement
    // condition ? stt1 : strr2    stt1 will be printed if conditon is true  else if the the conditio is false it will print strr
 
 string gg;
 string _no = "no";
    cout << "Are you single? (yes/no)\n";
    cin >> gg ;
    cout << (gg == _no ? "You cannot be marry again" : " You will get married soon") << "\n";

//LOOPS (while loop , for loop, do while loop)
while(m<=100) //if i use ; afer this line the while loop will not work and the programm will tuck at input terminal
{
    cout <<m<<"\n" ; // donot use infinite loop because if it got run , the system will crash or vs code will crash , to stope infinite loop use "control + c"
    m++;

}
for (size_t n = 0; n < 101; n += 3) // for()
{
    cout<< n<< " ";
    if (n==24){
    break;}
}
do
{
    n++;
    cout << n<< "\n";
} while ( n<117); // it will do the work then check the while condition , advantage it will print atleat one line.

// loop has more loops in is Nested loops
 int a =5;
 cout << round((sqrt(a)));
char A='A', Z='Z';
bool TRUE =true;
bool FALSE = false;
cout<< (A<Z)<< endl;
cout << (Z-A)<< "\n"; // value is coming 20
cout << ('Z'-'A')<<"\n";
cout << ++A << endl;
    return 0;

} 
#include <iostream>
using namespace std;

//function definition


void printAdi(){                // this is a void type funicion, void means null
    cout << "Aditya is a boy\n";

}
int asd(){                               // this is an int type function
    cout << "Vaishali is a girl\n";
    return 3;
}

int main() //This is called a funcion whose type is int
{
    //funcition call / invoke
    //printAdi(); 
    asd(); // it will invoke only the function and not the return value
    cout /*<< printAdi()*//*------------------------ << asd () <<endl; //asd() first called "khushi is a girl" and  "/n" and then returned the value 3
        // here printAdi() did not have any type so printing the function will show error!
    cout << asd << " " << printAdi << endl; // if () are not put after the function name the it will return the value 1, regardless of it data type;

// if we try to store the funcion in an variable the the value stored in the variable will be the return value of the function; */
int zzc = asd(); // int function's  without ()'s  has defalt return value 1 but if we try to store in an variable it will show an error & funcion without data type (void) will also show error;
cout << zzc<< endl;
    // if we call return statement in the function , no command after it will be exucuted;

    // Function Synthax

    // returntype functionName (Type paraeters 1, type parameater 2, ...){
    //   do the work/ task     }

    // redundancy is the sign of a BAD programmer, redundancy means unnecessary repetation of code/ work .

/*Function in memory 
 
    Memory are of two types : Call Stack and Heep;
    call stack (memory) < stacl frame() i.e functions eg main, sum, printAdi,... stack is like book upon book upon book... that is stack and book is called stack frame and each frame contain function , upper book (stack frame) contain other function;   

 // Pass by Value; */

    return 0;
}

#include <iostream>
using namespace std;
int ppf=20;
int main(){
 int gghh = 10;
 cout <<gghh<<endl;
 cout << ppf;
    return 0;

#include <iostream>
using namespace std;
int ppf=20;
int testfun(){
    ppf *=3;
    cout << ppf << endl;
    return (ppf+1);
}
int main(){
 int gghh = 10, ppf =50;
 cout <<gghh<<endl;
 cout << ppf<< endl; 
 testfun();
 cout  << testfun();
    return 0;
}}
#include <iostream>
using namespace std;
void fun (){
    int c= 25;
    cout << "c = "<< c<< endl;
    }
int main(){
fun();
cout << c <endl;
    return 0;
}
        //this example shows that the fuction is invald out side the function , anf if we try to call the fumction it will show the error that the variable is not defined!            what happen her is that the memory in the stack get errased  
//Binary number
        //decimal to bunary conversion can be done by storing question and remender in memeory
//----decimal to binary   ->  find LCM with 2 (binary) take remenders as the vales of the number in binary system , ## arrange remender from down to up direction!
//----binary to Decimal   ->  binary digits * 2^(digit's position - 1) 
//----binary to hexa       -> remember the base 0 to 7 , seprate the given number in the set of 4 digits and distinguish the number...
//----hexa to binary        -> vice versa
//----decimal to hexa        -> same but with hexa base
//----hexa to decimal         -> same but with hexa base
/*To convert decimal to binary then we have to do repeated division or 2 and finds its remender untill we get 0 in questant  */

//Two's compliment 
/* In just a simple word : we store negative numbers in different way because the old system was not fitting with the calculation!! :) 2nd reaseon was the old system also had a problem of +0 and -0;

1st -- Define the number of bits , eg 1,2,3,4,etc..
2nd -- Define the 1st most bit ... example : lets us define a 5 bit -> _ _ _ _ _ -> the first most (MSB) will be reserved for sign , which means only 4 bits are mathematicaly operatable, 0 = + and 1 = - for the 1st bit. eg is 01010 i.e 10 in decimal 
3rd -- Inter change the bits value i.e. 1 to 0 and 0 to 1, eg -> 01010 become 10101
4th -- add +1 to it eg. -> 10101 becomes 10110
10110 is  -10 in decimal

NOTE ### 
if -10 was not 5 in bit, then the vales whould be different 
if it was 8 bit system then the vale of -10 would have = 11110101

MY LOGIC ###
The scientist just inverted the order of number i.e. 0,1,2,3,4,5,6,7,8,9 = 0,9,8,7,6,5,4,3,2,1 respectively 

given below will make it clear :-

5 bit binary system

    
10001 = -15
10010 = -14
    .
    .
    .
11101 = -3
11110 = -2
11111 = -1
00000 =  0
00001 = +1
00010 = +2
00011 = +3
    .
    .
    .
01110 = +14
01111 = +15
10000 = -16 
10001 = -15
10010 = -14
    .
    .
    .
11110 = -2
11111 = -1
00000 =  0
00001 = +1
00010 = +2
    .
    .
    .    
MSB = Most Significant Bit (The left most bit which desides the sign +/- of number)

    borrowing / carring +1 fits in the system hence no calculation mistake :)
*/

//BITWISE OPERATORS
// operaters which works with the bits... 
/* --Bitwise & (AND)
   --Bitwise | (OR)
   --Bitwise  ^ (XOR)
   --Bitwise ~ (NOT) 
   --Bitwise << (Left shift)
   --Bitwise << (Right shift)*/


/*
Bitwise & (AND)
0,0  0
0,1  0
1,0  0
1,1  1

eg
(4 & 12)
4  = ...0100
12 = ...1100
     ...0100 = 4

eg
(4 & 8)
4 = ...0100
8 = ...1000
    ...0000 = 0       

Bitwise | (OR)
0,0  0
0,1  1
1,0  1
1,1  1

eg
(4 | 12)
4  = ...0100
12 = ...1100
     ...1100 = 12  
eg
(4 | 8)
4 = ...0100
8 = ...1000
    ...1100 = 12     

Bitwise  ^ (XOR)
0,0  0
0,1  1
1,0  1
1,1  0

eg
(4 ^ 12)
4  = ...0100
12 = ...1100
     ...1000 = 8

Bitwise ~ (NOT)
0  1
0  1
1  0
1  0

eg
20=   0...0010100
~20=  1...1101011 = -21

--Bitwise << (Left shift)
if i write : n<<i
the bits of n will shift i places towards left, mathematically n*2^i

eg
10 = 1010
10<<2
101000 = 40

eg
11 = 1011
11<<3
101100 = 44

   --Bitwise << (Right shift)

if i write : n>>i
the bits of n will shift i places towards right, mathematically n/2^i
eg
10 = 1010
10>>1
101 = 5

eg
11 = 1011
11>>3
101 = 5

##NOTE## MSB are not affected by left or right shift operator 

*/
 
 //SCOPE : area of variable

/* --Local scope 
-- global scope */

#include <bits/stdc++.h>
using namespace std;
int Y =120 // this is in global scope
int main(){
int x = 420; // this is in local scope
if(X=420){

    int C= 0; // this is in local scope
}
    return 0;
}
// DATA TYPE MODIFIER
/* To change the meaning of exesting data type by using modifiers

--long = will give >=4 bits = 8 byte
--short = will make it of 2 bytes
--long long
--signed = by defalt all the number comes with MSB 
--unsigned = will remove the MSB and make it unsigned, this is done general due tho increase the space. 

NOTE##*/
#include <iostream>
using namespace std;
unsigned int x = -10;
cout<<x;// since it is a unsigned data there for the output will be : 4294967286 , these come from adding + 2^32 with -10 because the bit which was responsible for storing value will be taken to consideratin in the calculation...
// -10 = 10 + 2^(size data type in bit or 8*Bytes)

//ARRAYS

/////// DATA TYPE:
//Arrays
// arrays only store one type of data
// data of array are stored together (contigious in memory)

int marks[5]

#include <iostream>
#include <array>
using namespace std;
int main(){
    int marks[5]={99,100,98,87,97};
    int marks[50]={99,100,98,87,97};
    double id[]={2.99,3.87,4.001};
    array <int,5> Myarray69 ;
    return 0;
}

//Array index 
position of array

cout<<marks[3]<<" "<<mark[4]<<" "<<mark[-1]<<" "<<mark[40]<<" "<<mark[400];
 
// -1, 40, 400 will have garbage value, and not  value 0
//NOTE : 0 will come to few palce but it does not mean it is not garbage value 

// size of array

int sz = sizeof(marks);
    int len = sizeof(marks)/sizeof(int);
    int len1 = sizeof(mark)/sizeof(int);
    int len2 = sizeof(id)/sizeof(double);
    cout<<endl<<sz<<" "<<len<<" "<<len1<<" "<<len2;

// Find Values of array by loop 
we will use loop to get all the values

for(int i=0; i<len1+50;i++){
    marks[i]=marks[i]+1;
    cout<<marks[i]<<" "<<mark[i]<<endl;
}
for(int i=0; i<len1+50;i++){
    cout<<marks[i]<<" "<<mark[i]<<endl;
}

int len_input =sizeof(input)/sizeof(int);

// Input Values of array by loop 


for(int i=0; i<len_input+3;i++){
    cin>>input[i];
}
cout<<"-------------\n";
for(int i=0; i<len_input+9;i++){
    cout<<input[i]<<endl;
}
//--------------------------------------------------------
max data type value :-
INT_MAX
INT8_MAX
INT16_MAX
INT32_MAX
INT64_MAX

//--------------------------------------------------------
 min- max function
 cout<< min ( a,b);
 cout<< max( a,b);

//-------------------------------------------------------
double se[3] = {1,2,3};
double xe[] = {1,2,3};

//In c++ , the array only can be accised by pass-by-referance and not pass-by-value

swap(a,b) //swap two data type , under hood it is using <template> temp

//VECTORS

vector has a dynamic space allocation that is ... its size can be change even after decleration it ... and in Array, onec the size has been alloted , it cannoted be changed after ...

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> myVector ={1,2,3,4};
    vector <int> myvector2;
    vector <int> myVector3(4,9); 
    cout<< myVector[0] <<"\n" <<myVecttor2[0]; //it will show segmentation falt if we acces the element  apart from vector 
    /// command g++ -std=c++11 to use vector poperly with no error
    //for each loop 
    for (int i : myVector ){
        cout<<i;
    }
    vector <char > myCv ={'a','b','c','d','e','z','b'};

    for(char val : myCv){
        cout<< val;
    }
    return 0;
}
cout<<"Size = "<<myVector.size()<<endl;

vector <int> myvector;

//THE DIFFERENCE BETWEEN ARRAY AND THE VECTOR IS ... ARRAY HAS FIXED SIZE ... VECTOR HAS DYNAMIC SIZE 

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
    return 0;
}

//STATIC VS DYNAMIC 
DYNAMIC VECTOR SIZE GETS DOUBLED (x2) WHENEVER THE PREVIOUS SIZE GETS FULL... the capicity gets dubbled 


//TIME COMPLEXITY 

It is a graph of // INPUT vs OUTPUT

MAXIMUM SUBARRAY SUM

Kadans algo.

pair sum.
(Two Pointer Approch)

majority element 
    - moore's 
    - brute force
    - optmize

Time and space complexity 

    int n;
    cin>>n;
    int ans= n*(n+1)/2; //O(1) time complexity

    recursion (factorial example) // O(n)

    merge step 
    merge sort   //time complixity : O(n*log n), space : o(n)

//##### operation vs second

10^8 operation = 1 sec
TLE : Time level exceeded 

e.g.  n<10^5 given 

if we go for O(n^2)
 it will do 10^10 which will take more than 1.001 sec

practical Usage 

n > 10^8 O(log n) ,  O(1)
n <=10^8 O(n)
n <=10^6 O(n*log(n))
n <=10^4 O(n^2)
n <=500  O(n^3)
n <=25   O(2^n)
n <=12   O(n!)

//ADDRESS OF OPERATOR &
& is used to find the addres of the assigned data/ data type 
// Dereferencing operator *
* is used to dereference the value inside an __cpp_variable_templates
** dereferance 2x times
*** dereferance 3x times
**** dereferance 4x times ... and so on ..
//POINTER 
it is a special variables that store address of other condition_variable

int *a = &b; //it is a pointer i.e stores the address of data

    int a =10;
    int* p = &a;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;
    //cout<<*a<<endl;//this will show error because it in not pointer
//-------------------------------------------------------------------------------
    //POINTER to POINTER & pointer = pointer
 int a =10;
    int* p = &a;
    cout<<a<<endl;
    cout<<&a<<endl<<endl;

    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl<<endl;
    //cout<<*a<<endl;//this will show error because it in not pointer
int* p2 =p;
    cout<<p2<<endl;
    cout<<*p2<<endl;
    cout<<&p2<<endl<<endl;

int** p3 =&p;
    cout<<p3<<endl;
    cout<<*p3<<endl;
    cout<<**p3<<endl;
    //cout<<***p3<<endl; *** do not contain any address
    cout<<&p3<<endl<<endl;


    int*** p4 =&p3;
    cout<<p4<<endl;
    cout<<*p4<<endl;
    cout<<**p4<<endl;
    cout<<***p4<<endl; 
    cout<<&p4<<endl<<endl;
    return 0;
 //---------------------------------------

 // NULL POINTER
 int* p = NULL;

 //Example
 int main(){
    int* p = NULL;
    std::cout<<p;
    std::cout<<*p; //This will give Segmentation Fault error ... Because we are trying to access those memomy which is not allowed ;
    return 0;
 }

 // Pass by value vs Pass by referance 
 int a=10;
 int b =a; //pass by value (changes only in the copy of variable and not actual variable)
 int* p =&a;// pass by referance [specifically POINTER and referances] (direct change in the main memory/location of the variable)

 //ARRAY POINTER

 Array is a pointer (constent pointer)

 //example:
    int MyArr[]={1,2,3,4,5}
    cout<<MyArr; // will retuen the address of it first index (like 0xf252f9) 
    cout<<*MyArr// will return 1 , the 0th index

#include <iostream>

using namespace std;

int main() {
    int b=10;
int arr[]={1,2,3,4};
arr* =&b;
    return 0;
    
}
//arr(pointer) address cannot be modified 

//every Array is a pointer but every pointer is not an array

#include <iostream>

using namespace std;

int main() {
    int p[5]={0,1,2,3,4};
    cout<<&p<<endl; // 0x7ffc709981a0
    cout<<*p<<endl; // 0
}

#include <iostream>

using namespace std;

int main() {
    int a=10;
    int* p=&a;
    cout<<a<<endl; //10
    cout<<&a<<endl; //0x7ffe0f6fd5ac
    a++;
    cout<<a<<endl; //11
    cout<<&a<<endl;//0x7ffe0f6fd5ac

    cout<<p<<endl;//0x7ffe0f6fd5ac
    cout<<&p<<endl;//0x7ffe0f6fd5b0
    cout<<*p<<endl;//11
    p++; // P STORES LOCATION + 4 BITES(BEC. POINTER IS INT)
    cout<<p<<endl;//0x7ffe0f6fd5b0
    cout<<&p<<endl;//0x7ffe0f6fd5b0
    cout<<*p<<endl;//258987440

    cout<<a<<endl; //11
    cout<<&a<<endl;//0x7ffe0f6fd5ac
    a++;
    cout<<a<<endl;//12
    cout<<&a<<endl;///0x7ffe0f6fd5ac

    cout<<"-----------------"<<endl;
    *p= *p+5555;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;

//     aditya-aman@aditya-aman-LINUX:~/All Repository/Beginner-s-Code$ g++ -std=c++17 c++/rough/erase.cpp && ./a.out
// 10
// 0x7ffd26da7bec
// 11
// 0x7ffd26da7bec
// 0x7ffd26da7bec
// 0x7ffd26da7bf0
// 11
// 0x7ffd26da7bf0
// 0x7ffd26da7bf0
// 651852784
// 11
// 0x7ffd26da7bec
// 12
// 0x7ffd26da7bec
// -----------------
// 12
// 0x7ffd26da7bec
// Segmentation fault (core dumped)
// aditya-aman@aditya-aman-LINUX:~/All Repository/Beginner-s-Code$ g++ -std=c++17 c++/rough/erase.cpp && ./a.out
// 10
// 0x7ffeaf03880c
// 11
// 0x7ffeaf03880c
// 0x7ffeaf03880c
// 0x7ffeaf038810
// 11
// 0x7ffeaf038810
// 0x7ffeaf038810
// -1358723056
// 11
// 0x7ffeaf03880c
// 12
// 0x7ffeaf03880c
// -----------------
// 12
// 0x7ffeaf03880c
// 1818321775
// 0x7ffeaf039dc3
// 0x7ffeaf038810

}

//POINTER ARITHEMATIC 
p++ , p--, --p, ++p ... //the pointer point to next index .. like first int* p =myArray[0], p++ , p = address of myArray[1], ++p , p = address of myArray[2];

// pointer Subtraction 
Addition of 2 pointers are not allowed!!!! (p1 +p2) x (wrong)!!!
BUT
Subtraction of 2 pointers are allowed (p2- p1) //right .... it willl give the size of the array's data type

//POINTER COMPARISION  (relation operators)is allowed
==,<=,>,<,>=,!=

int arr[]={10,20,30,40,50};
int *p =&arr;
cout<< *(p+3);
cout<< *(p+1);
cout<< *(p);


//BINARY SEARCH ALGORITHM 
only applied of shorted(ass. dess.) array

