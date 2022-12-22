#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node* next;

        Node(T data){
            this->data=data;
        }
};

template<class T>
class Stack{
    private:
        int length;
        Node<T>* top;

    public:
        Stack(){
            length=0;
            top=NULL;
        }

        void push(T data){
            Node<T>* ptr=new Node<T>(data);

            if(top==NULL){
                top=ptr;
            }else{
                ptr->next=top;
                top=ptr;
            }
            length++;
        }

        T getTop(){
            if(top==NULL){
                cout<<"Your Stack is Empty\n";
                return NULL;
            }
            return top->data;
        }

        T pop(){
            if(top==NULL){
                cout<<"Your Stack is Empty\n";
                return NULL;
            }
            Node<T>* deleted=top;
            top=top->next;
            T deletedData=deleted->data;
            delete(deleted);
            length--;
            return deletedData;
        }

        int size(){
            return length;
        }
};

int main(){
    Stack<string> st;
    st.push("Nikhil");
    st.push("Govind");
    st.push("Harshit");
    st.push("Pawan");
    cout<<st.getTop()<<" , "<<st.size()<<"\n";
    st.pop();
    st.pop();
    cout<<st.getTop()<<" , "<<st.size()<<"\n";
    st.push("Vineet");
    cout<<st.getTop()<<" , "<<st.size()<<"\n";

    return 0;
}   