#include <iostream>
using namespace std;

struct Node{
    float data;
    Node *next;
};

void pushAfterLast(Node*& L, float d){
    Node *newnode=new Node;
    if(newnode!=NULL){
        newnode->data=d;
        newnode->next=NULL;//0 или nullptr
        if (L==NULL) //список пуст
            L=newnode;
        else{
// получить указатель на последний узел списка
            Node* tmp=L;
            while(tmp->next!=NULL){
                tmp=tmp->next;
            }
            tmp->next=newnode;
        }
    }
}

int main() {
    Node* headList1 = new Node;
    Node* headList2 = new Node;
    cout<<"Type length of L1 and L2 for random genertation\n";
    int len1,len2;
    cin>>len1>>len2;
    for(int i=0;i<len1)
}
