#include <iostream>

using namespace std;

struct item2{
    int data;
    item2* next=nullptr, * prev=nullptr;
};

int main()
{
    int x;
    item2 *head2=nullptr;
    while(cin>>x,x>0)
    {
        item2 *new_item2=new item2;
        new_item2->data=x;

        item2 *cur2=head2;

        if(head2==nullptr) // если пустой список
            {head2=new_item2;
            head2->next=head2;
            head2->prev=head2;

             continue;}
        bool F=true; // Для того, чтобы прошела первая интерация
        for(cur2=head2; (cur2!=head2 || F) && cur2->data<x; cur2=cur2->next, F=false);

        new_item2->next=cur2;
        new_item2->prev=cur2->prev;
        cur2->prev->next=new_item2;
        cur2->prev=new_item2;
        if(cur2==head2)
            head2=new_item2; // Новая голова
    }
    bool F=true;
    if(head2!=nullptr)
        for(item2 *uk=head2; uk!=head2 || F; uk=uk->next, F=false)
            cout<<uk->data<<" ";
    return 0;
}
