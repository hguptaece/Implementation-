#include<iostream> 
using namespace std;

class Student{
    public:

    //default costructor
    Student(){
        rollno=0;
        marks=100;
        name="Empty";
        cout<<"Hii my name is default contructor\n";

    } 

    //parameterized contructor
    Student(string sName, int sMarks, int sRoll){
        name=sName;
        marks=sMarks;
        rollno=sRoll;
        cout<<"Hii my name is parameterized contructor\n";

    }

    Student(string sName, int sRoll){
        name =sName;
        rollno=sRoll;
        marks=10000;
        cout<<"Hii i am second Parameterized constructor\n";
    }

    //copy constructor
    Student(Student& x){
        name=x.name;
        marks=x.marks+3;
        rollno=x.rollno-1;
        cout<<"Hii my name is copy contructor\n";
    }

    //destructor
    ~Student(){
        marks=0;
        rollno=0;
        name="";
        cout<<"Hii i am destructor\n";
    }

    int rollno;
    string name;
    float marks;

    bool candance(){
        if(rollno > 35){
            cout<<name<<" can dance..\n";
            return true;
        }else{
            cout<<name<<" can't dance..\n";
            return false;
        }
    }
    void greet(){
        cout<<"Hello\n";
    }

};

int main(){
    Student s1;
    Student s2("megha sharma",45,34);

    //copy constructor
    Student s3=s2;
    Student s4("harshit gupta",24);

    s2.name="Megha verma";

    /*s1.name="Harshit gupta";
    s1.rollno=23;
    s1.marks=64;

    s2.name="Nikhil tyagi";
    s2.rollno=36;
    s2.marks=34;

    s3.name="mohit";
    s3.rollno=31;
    s3.marks=56;

    cout<<" "<<s3.candance();*/

    cout<<s1.name<<" "<<s1.marks<<" "<<s1.rollno<<"\n";
    cout<<s2.name<<" "<<s2.marks<<" "<<s2.rollno<<"\n";
    cout<<s3.name<<" "<<s3.marks<<" "<<s3.rollno<<"\n";
    cout<<s4.name<<" "<<s4.marks<<" "<<s4.rollno<<"\n";
    cout<<"Hello\n";

    /*Student students[5];

    students[0].name="neha ";
    students[0].rollno=23;

    students[2].name="harshit";
    students[2].marks=89;

    cout<<students[0].rollno<<"\n"<<students[2].name<<"\n";

    Student students[3];
    int n=3;

    for(int i=0; i<n; i++){
        cout<<"Name: ";
        cin>>students[i].name;
        cout<<"Marks: ";
        cin>>students[i].marks;
        cout<<"Roll No: ";
        cin>>students[i].rollno;
    }

    for(int i=0; i<n; i++){
        cout<<"( Roll Number: "<<students[i].rollno<<", Name: "<<students[i].name<<", Marks: "<<students[i].marks<<")\n";
    }*/

    return 0;
}
