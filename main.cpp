#include <iostream>
#include <windows.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};


void printNode(Node*& L){
    Node* tmp=L;
    if(tmp==NULL){
        cerr<<"EMPTY NODE\n";
        return;
    }
    cout<<tmp->data<<" ";
    while(tmp->next!=NULL){
        tmp=tmp->next;
        cout<<tmp->data<<" ";
    }
    cout<<endl;
}


void push(Node **head, int data) {
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = (*head);
    (*head) = tmp;
}
void push_back(Node*& head, int inp){
    Node *NewItem=new Node;
    NewItem->data=inp;
    NewItem->next = NULL;
    if (head == NULL) {
        head = NewItem;
    }else{
        Node *Current=head;
        for(int i=1;Current->next!=NULL; i++)
            Current=Current->next;
        Current->next = NewItem;
    }
}


void firstTask(Node* &head1, Node* &head2,Node* &headMain){
    Node* tmp1=head1;
    Node* tmp2=head2;
    Node* tmpMain=headMain;
    while(tmp1!=nullptr && tmp2!=nullptr){
            if(tmp1->data < tmp2->data){
                push_back(headMain,tmp1->data);
                tmp1=tmp1->next;
            }else{
                push_back(headMain,tmp2->data);
                tmp2=tmp2->next;
            }
    }
    while (tmp1!=nullptr){
        push_back(headMain,tmp1->data);
        tmp1=tmp1->next;
    }
    while (tmp2!=nullptr){
        push_back(headMain,tmp2->data);
        tmp2=tmp2->next;
    }
}

void pop_by_num(Node* &head,int Number){
    Node *ptr;
    Node *Current = head;
    for (int i = 1; i < Number && Current != nullptr; i++)
        Current = Current->next;
    if (Current != nullptr){
        if (Current == head){
            head = head->next;
            delete(Current);
            Current = head;
        }
        else {
            ptr = head;
            while (ptr->next != C urrent)
                ptr = ptr->next;
            ptr->next = Current->next;
            delete(Current);
            Current=ptr;
        }
    }
}

void insertToSorted(Node*& head, int inp){
    Node *NewItem=new Node;
    NewItem->data=inp;
    NewItem->next = nullptr;
    Node* temp = head;
    while(temp != nullptr){
        if(inp<= head->data){
            NewItem->next = head;
            head = NewItem;
            break;
        }else{
            if(temp->next == nullptr or (inp >= temp->data and inp<= temp->next->data)){
                NewItem->next = temp->next;
                temp->next = NewItem;
                break;
            }
        }
        temp = temp->next;
    }
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    Node* headList1 = nullptr;
    Node* headList2 = nullptr;
    Node* headListMain = nullptr;
    cout<<"Type length of L1 and L2\n";
    int len1,len2;
    cin>>len1>>len2;

    int temp;
    cout<<"Fill L1\n";
    for(int i=0;i<len1;i++){
        cin>>temp;
        push_back(headList1,temp);
    }

    cout<<"Fill L2\n";
    for(int i=0;i<len2;i++){
        cin>>temp;
        push_back(headList2,temp);
    }

    firstTask(headList1,headList2,headListMain);
    printNode(headListMain);
    cout<<"Введите номер для удаления:\n";
    int index;
    cin>>index;
    pop_by_num(headListMain,index);
    printNode(headListMain);

    cout<<"Введите значение для вставки:\n";
    cin>>temp;
    insertToSorted(headListMain,temp);
    printNode(headListMain);
    return 0;
}
