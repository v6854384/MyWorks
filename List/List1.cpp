#include <iostream>

using namespace std;

struct item{
    int data;
    item* next;
};

int main()
{
    int x;
    item *head=nullptr;
    while(cin>>x,x>0)
    {
        item *new_item=new item;
        new_item->data=x;
        new_item->next=nullptr;

        item *prev=nullptr;
        item *cur=head;
        if(head==nullptr) // если пустой список
            {head=new_item; continue;}

        while(cur!=nullptr && cur->data<x) // Поиск элемента больше заданного
        {
            prev=cur;
            cur=cur->next;
        }
        // Модификация списка
        if(cur==head)
            head=new_item; // Новая голова
        else
            prev->next=new_item;
        new_item->next=cur;
    }
    for(item *uk=head;uk!=nullptr;uk=uk->next)
        cout<<uk->data<<" ";
    return 0;
}
