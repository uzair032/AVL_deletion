#include <iostream>
#include"AVL.h"
using namespace std;

int main()
{
    AVL t1;
    AVL *node=t1.head;
    node=t1.insert(node,9);
    int x[]={1,2,3,4,5,6,7,8};
    cout<<"Array is "<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<" "<<x[i];
        t1.insert(node,x[i]);
    }
    cout<<endl;
    cout<<"Inorder Traversal"<<endl;
    t1.inorder(node);
    cout<<"\nPreorder Traversal"<<endl;
    t1.preorder(node);
    cout<<"\nPostorder Traversal"<<endl;
    t1.postorder(node);
    cout<<endl;

    cout<<"After deletion:"<<endl;
    t1.deleteNode(node,1);
    t1.preorder(node);
    int num,i=0;
    while(i<=2)
    {
    cout<<"\nNumber that you want to search: "<<endl;
    cin>>num;
    if(t1.search(node,num)!=NULL)
        cout<<"Number exists"<<endl;
        else
            cout<<"Number does not exists"<<endl;
            i++;
    }
    return 0;
}
