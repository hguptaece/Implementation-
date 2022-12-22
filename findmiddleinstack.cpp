#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
        }
};

class Stack{
    private:
        Node* top;
        Node* middle;
        int length;

    public:
        Stack(){
            top=NULL;
            middle=NULL;
            length=0;
        }

        void push(int data){
            Node* ptr=new Node(data);
            length++;
            
            if(top==NULL){
                top=ptr;
                middle=ptr;
            }else{
                top->prev=ptr;
                ptr->next=top;
                top=ptr;

                if(length%2==1){
                    middle=middle->prev;
                }
            }
        }

        int pop(){
            
            if(top==NULL){
                return -1;
            }else if(top->next==NULL){
                int data=top->data;
                delete(top);
                top=NULL;
                middle=NULL;
                length--;
                return data;
            }else{
                int data=top->data;
                Node* X=top;
                top=top->next;
                delete(X);
                length--;

                if(length%2==0){
                    middle=middle->next;
                }

                return data;
            }
            
        }

        int findMiddle(){
            if(middle==NULL){
                return -1;
            }
            return middle->data;
        }

        void deleteMiddle(){
            if(middle==NULL){
                return;
            }else if(middle==top){
                int data=top->data;
                delete(top);
                top=NULL;
                middle=NULL;
                length--;
            }else{
                Node* X=middle->prev;
                Node* Y=middle->next;
                if(Y != NULL)
                    Y->prev=middle->prev;
                X->next=middle->next;
                delete(middle);

                length--;

                if(length%2==0){
                    middle=Y;
                }else{
                    middle=X;
                }
            }
        }

        int size(){
            return length;
        }
};


int main(){
    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.findMiddle() << endl;
    st.deleteMiddle();
    cout <<"New Middle Element : "<< st.findMiddle() << endl;
    return 0;
}