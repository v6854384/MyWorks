#include <iostream>
#include <fstream>

using namespace std;

void menu();

namespace BSTree
{
    struct Node{ // Описание узла
    int data; // Данные
    Node *left, *right; // Правый и левый потомки
    };

class Tree{
    ofstream out;
    void InsRecyrs(int x, Node *node);
    void print_recurs(Node *node, int deep);
    void del_recurs(Node *&node); // Рекурсивное удаление вершины
    void fout_recurs(Node *node); // Рекурсивный вывод в файл
    void child_kill(int x, Node *node);
public:
    Node *root=nullptr;
    Node * exist(int x,Node *node);
    void del(int x);
    void traversal_forwad(Node *node);
    void traversal_middle(Node *node);
    void traversal_back(Node *node);
    void fout(char *FileName); // Вывод в файл
    void f_in(char *FileName);

    void print()
    {
        cout<<endl;
        print_recurs(root,0);
    };
    void insert(int x);
    };

    void Tree::f_in(char *FileName)
    {
        ifstream in(FileName);
        cout<<"----\n";
        root=nullptr; // Заглушка, чтобы очистить дерево
        while(!in.eof())
        {
            int x;
            in>>x;
            cout<<x<<" ";
            insert(x);
        }
        in.close();
    }

    void Tree::del_recurs(Node *&node) // Рекурсивное удаление вершины
    {
        if(node==nullptr) return;
        if(node->left==nullptr && node->right==nullptr) // Если переден root и у него нет детей
        {
            node=nullptr;
            return;
        }

        if(node->right!=nullptr)
        {
            node->data=node->right->data;
            if(node->right->left==nullptr && node->right->right==nullptr) // Бездетная вершина???
            {
                delete node->right;
                node->right=nullptr;
            }
            del_recurs(node->right);
            return;
        }
        if(node->left!=nullptr)
        {
            node->data=node->left->data;
            if(node->left->left==nullptr && node->left->right==nullptr) // Бездетная вершина???
            {
                delete node->left;
                node->left=nullptr;
            }
            del_recurs(node->left);
            return;
        }
    }

    void Tree::child_kill(int x, Node *node)
    {
        if(node==nullptr) return;

        if(x>node->data)
            if(node->right->data==x)
                node->right=nullptr;
            else
                child_kill(x,node->right);
        else
            if(node->left->data==x)
                node->left==nullptr;
            else
                child_kill(x,node->left);
    }

    void Tree::del(int x)
    {
        Node* node=exist(x,root);

        if(node==nullptr) return;
        if(node==root && root->left==nullptr && root->right==nullptr)// Если нет детей у root
            root=nullptr;
        if(node->left==nullptr && node->right==nullptr) // Лист
            {
                child_kill(x,root);
                delete node;
                return;
            }
        del_recurs(node);
    }

    Node * Tree::exist(int x,Node *node)
    {
        if(node==nullptr) return nullptr;
        if(node->data==x) return node;
        if(x>node->data)
            return exist(x,node->right);
        else
            return exist(x,node->left);
    }
    void Tree::traversal_forwad(Node *node){
        if(node==nullptr) return;
        cout<<node->data<<" ";
        traversal_forwad(node->left);
        traversal_forwad(node->right);
    };
    void Tree::fout(char *FileName) // Вывод в файл
    {
        out.open(FileName);
        fout_recurs(root);
        out.close();
    }

    void Tree::fout_recurs(Node *node){
        if(node==nullptr) return;
        out<<node->data<<" ";
        fout_recurs(node->left);
        fout_recurs(node->right);
    };
    void Tree::traversal_middle(Node *node){
        if(node==nullptr) return;
        traversal_middle(node->left);
        cout<<node->data<<" ";
        traversal_middle(node->right);
    };
    void Tree::traversal_back(Node *node){
        if(node==nullptr) return;
        traversal_back(node->left);
        traversal_back(node->right);
        cout<<node->data<<" ";
    };
    void Tree::print_recurs(Node *node, int deep)
    {
        if(node==nullptr) return;
        print_recurs(node->right, deep+1);
        for(int i=0;i<deep;i++)
            cout<<"   ";
        cout<<node->data<<endl;
        print_recurs(node->left, deep+1);
    }
    void Tree::InsRecyrs(int x, Node *node) // Рекурсивная процедура вставки
                                                    // node - анализируемая вершина NewNode - вершина для вставки
    {
        if(x==node->data) return; // Обнаружено то же число в дереве
        if(x>node->data)
            if(node->right!=nullptr)
                InsRecyrs(x,node->right);
            else
            {
                Node *NewNode=new Node;
                *NewNode={x,nullptr,nullptr};
                node->right=NewNode;
                return;
           }
        else
            if(node->left!=nullptr)
                InsRecyrs(x,node->left);
            else
            {
                Node *NewNode=new Node;
                *NewNode={x,nullptr,nullptr};
                node->left=NewNode;
                return;
           }
    }

    void Tree::insert(int x){ // Процедура вставки для посльзователя
        if(root!=nullptr)
           InsRecyrs(x,root);
        else
           {
            Node *NewNode=new Node;
            (*NewNode).data=x;
            NewNode->left=nullptr;
            NewNode->right=nullptr;
            root=NewNode;
            return;
           }
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    BSTree::Tree tree; // Объявление объекта класса Tree
    for (int i = 1; i < argc; i++)
        tree.insert(atoi(argv[i]));

    int choice = 0;
/*    tree.insert(8);
    tree.insert(12);
    tree.insert(4);
    tree.insert(9);
    tree.insert(3);
    tree.insert(13);
    tree.insert(7);
*/
    tree.print();
    cout<<endl;
    tree.traversal_forwad(tree.root);
    cout<<endl;
    tree.traversal_middle(tree.root);
    cout<<endl;
    tree.traversal_back(tree.root);
    cout<<endl;
    if(tree.exist(10,tree.root)==nullptr)
        cout<<"not exist";
    else
        cout<<"exist";
    tree.del(4);
    tree.print();
    tree.fout("graph.txt");
    tree.f_in("graph.txt");
    tree.print();
/*    while (true){
        menu();
        cin >> choice;
        switch (choice){
         case 8: return 0;
        }
    }
*/
    return 0;
}

void menu(){
    cout << "Выберете одну из операций:" << endl;
    cout << "1. Вывести дерево на экран" << endl;
    cout << "2. Вывести список узлов дерева" << endl;
    cout << "3. Добавить узел в дерево" << endl;
    cout << "4. Удалить узел из дерева" << endl;
    cout << "5. Сохранить дерево в файл" << endl;
    cout << "6. Загрузить дерево из файла" << endl;
    cout << "7. Проверить наличие узла" << endl;
    cout << "8. Завершить работу программы" << endl;
}
