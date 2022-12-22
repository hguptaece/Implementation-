#include<iostream>
using namespace std;

template<class T>
class vector{
    private:
        T* arr;
        int size;
        int capacity;

        void doubleTheSize(){
            T* temp=new T[2*capacity];
            for(int i=0;i<size;i++){
                temp[i]=arr[i];
            }
            capacity*=2;
            arr=temp;
        }

        void halfTheSize(){
            T* temp=new T[capacity/2];
            for(int i=0;i<size;i++){
                temp[i]=arr[i];
            }
            capacity/=2;
            arr=temp;
        }

    public:
        vector(){
            size=0;
            capacity=1;
            arr=new T[1];
        }

        void push(T data){
            if(size == capacity){
                doubleTheSize();
            }
            arr[size]=data;
            size++;
        }

        T pop(){
            if(size==0){
                cout<<"Nothing To Delete\n";
                return NULL;
            }
            T deleted=arr[size-1];
            size--;
            if(size==capacity/2 && capacity != 1){
                halfTheSize();
            }
            return deleted;
        }

        T rear(){
            if(size==0){
                cout<<"Vector is Empty\n";
                return NULL;
            }
            return arr[size-1];
        }

        void display(){
            cout<<"You have "<<size<<" Elements in your vector: [";
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" , ";
            }
            cout<<"]\n";
        }

        void displayWithCapacity(){
            cout<<"You have "<<capacity<<" capacity in your vector: [";
            for(int i=0;i<capacity;i++){
                if(i < size)
                    cout<<arr[i]<<" , ";
                else
                    cout<<"NULL , ";
            }
            cout<<"]\n";
        }
};

int main(){
    vector<string> v;

    v.push("raveet");
    v.push("neha");
    v.push("shivani");
    v.push("deeksha");
    v.push("nikhil");
    v.push("harshit");
    v.display();
    v.displayWithCapacity();
    cout<<"\n";
    cout<<"deleted element is: "<<v.pop()<<"\n";
    v.display();
    v.displayWithCapacity();
    cout<<"\n";
    cout<<"deleted element is: "<<v.pop()<<"\n";
    v.display();
    v.displayWithCapacity();
    cout<<"\n";
    cout<<"deleted element is: "<<v.pop()<<"\n";
    v.display();
    v.displayWithCapacity();
    cout<<"\n";
    cout<<"deleted element is: "<<v.pop()<<"\n";
    v.display();
    v.displayWithCapacity();
    cout<<"\n";
    cout<<"deleted element is: "<<v.pop()<<"\n";
    v.display();
    v.displayWithCapacity();
    cout<<"\n";


    v.push("shreyas");
    v.display();
    v.displayWithCapacity();
    cout<<"\n";
    
    return 0;
}