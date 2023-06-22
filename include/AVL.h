#ifndef AVL_H
#define AVL_H
#include<iostream>

class AVL
{
    public:
        AVL();//non-parametrized constructor
        AVL(int val);//parametrized constructor
        int height(AVL *root);
        int Max(int x1,int x2);
        AVL *insert(AVL *root,int value);//adding data through binary search
        AVL *singlerightRotation(AVL *k2);
        AVL *singleleftRotation(AVL *k1);
        AVL *doublerightleftrotation(AVL *k1);
        AVL *doubleleftrightrotation(AVL *k2);
        AVL *deleteNode(AVL *root, int value);
        AVL *minnode(AVL *root);
        void inorder(AVL *root);
        void preorder(AVL *root);
        void postorder(AVL *root);
        AVL *search(AVL *root,int value);//searching number in binary search tree
        virtual ~AVL();

    //private:
        int data,hei;
        AVL *head=NULL,*left,*right,*k1=NULL,*k2=NULL,*k3=NULL;
};

#endif // AVL_H
