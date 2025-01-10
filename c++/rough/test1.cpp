
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
//----decimal to binary
//----binary to Decimal
//----binary to hexa
//----hexa to binary
//----decimal to hexa 
//----hexa to decimal
/*To convert decimal to binary then we have to do repeated division or 2 and finds its remender untill we get 0 in questant  */