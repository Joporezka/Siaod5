#include <iostream>
using namespace std;

struct Node{
    float data;
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
}


void push(Node **head, float data) {
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = (*head);
    (*head) = tmp;
}

float pop(Node **head) {
    Node* prev = NULL;
    float val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->data;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

bool isInList(float el, Node*& head){
    Node* tmp=head;
    if(head==NULL) return false;

    while(true){
        if(tmp->data == el){
            return true;
        }
        if(tmp->next!=NULL){
            tmp = tmp->next;
        }else{
            break;
        }
    }
    return false;
}


void firstTask(Node* &head1, Node* &head2,Node* &headMain){
    Node* tmp1=head1;
    Node* tmp2=head2;
    Node* tmpMain=headMain;
    while(true){
        if(isInList(tmp1->data, tmp2) && !isInList(tmp1->data, headMain)){
            push(&headMain,tmp1->data);
        }
        if(tmp1->next!=NULL){
            tmp1 = tmp1->next;
        }else{
            break;
        }
    }
}

void Delete_Item_Single_List(Node* &head,int Number){
    Node *ptr;//вспомогательный указатель
    Node *Current = head;
    for (int i = 1; i < Number && Current != NULL; i++)
        Current = Current->next;
    if (Current != NULL){//проверка на корректность
        if (Current == head){//удаляем первый элемент
            head = head->next;
            delete(Current);
            Current = head;
        }
        else {//удаляем непервый элемент
            ptr = head;
            while (ptr->next != Current)
                ptr = ptr->next;
            ptr->next = Current->next;
            delete(Current);
            Current=ptr;
        }
    }
}
bool second(Node* &Head){
    Node* ptr; //вспомогательным указатель
    for (int i=1;ptr != NULL;i++){//пока не конец списка
        if(i==30) cout<<"fuck";
        if (ptr->next->data<0){
            Delete_Item_Single_List(Head,i);
        }

        ptr = ptr->next;
    }
    return false;
}
/*void secondTask(Node* &head2){
    Node* ptr;
    Node* tmp2=head2;

    while(tmp2!= nullptr){
        if(tmp2->next != nullptr &&tmp2->next->data<0){
            if(tmp2 == head2){
                head2 = head2->next;
                delete(tmp2);
                tmp2 = head2;

            }else{
                ptr = head2;
                while (ptr->next != tmp2)
                    ptr = ptr->next;
                ptr->next = tmp2->next;
                delete(tmp2);
                tmp2=ptr;
            }
        }else{
            tmp2 = tmp2->next;
        }
    }
}*/

int main() {
    Node* headList1 = NULL;
    Node* headList2 = NULL;
    Node* headListMain = NULL;
    cout<<"Type length of L1 and L2\n";
    int len1,len2;
    cin>>len1>>len2;

    float temp;
    cout<<"Fill L1\n";
    for(int i=0;i<len1;i++){
        cin>>temp;
        push(&headList1,temp);
    }
    //printNode(headList1);

    cout<<"Fill L2\n";
    for(int i=0;i<len2;i++){
        cin>>temp;
        push(&headList2,temp);
    }
    //printNode(headList2);

    //cout<<"Answer for task 1: \n";
    //firstTask(headList1,headList2,headListMain);
    //printNode(headListMain);

    cout<<"Answer for task 2: \n";
    second(headList2);
    printNode(headList2);






}
