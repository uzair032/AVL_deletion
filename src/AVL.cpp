#include "AVL.h"
#include<iostream>
using namespace std;

AVL::AVL()
{
    //ctor
}

AVL::AVL(int val)
{
    data=val;
    left=NULL;
    right=NULL;
}

AVL *AVL::insert(AVL *head,int val)
{
    if(head==NULL)
        return new AVL(val);//entering value at first node
    else if(val<head->data)
    {
        head->left=insert(head->left,val);//calling recursivly
        int htdiff=height(head->left) - height(head->right);
        if( htdiff>1 )
        {
            if( val < head->left->data ) // outside insertion case
              singlerightRotation( head );
            else  // inside insertion case
              doubleleftrightrotation( head );
        }
        return head;
    }
    else if(val>head->data)
    {
       head->right=insert(head->right,val);//calling recursivly
        int htdiff=height(head->right) - height(head->left);
        if( htdiff > 1 )
        {
            if( val < head->right->data ) // outside insertion case
               singleleftRotation( head );
            else  // inside insertion case
               doublerightleftrotation( head );
        }
    return head;
    }
    int ht = Max(height(head->left), height(head->right));
    //int ht2=ht+1;
    head->hei= ht+1 ; // new height for root.
    return head;

}

AVL *AVL::singlerightRotation(AVL *k2)
{

    if( k2 == NULL )
    return NULL;
    // k1 (first node in k2's left subtree) will be the new root
    k1 = k2->left;

    // Y moves from k1's right to k2's left
    k2->left= k1->right ;
    k1->right=k2;

    // reassign heights. First k2
    int h = Max(height(k2->left), height(k2->right));
    k2->hei= h+1 ;
    // k2 is now k1's right subtree
    h = Max( height(k1->left), k2->hei);
    k1->hei= h+1 ;
    return k1;

}

AVL *AVL::singleleftRotation(AVL *k1)
{
   if( k1 == NULL )
    return NULL;
    // k1 (first node in k2's left subtree) will be the new root
    k2 = k1->right;

    // Y moves from k1's right to k2's left
    k1->right=k2->left ;
    k2->left=k1;

    // reassign heights. First k2
    int h = Max(height(k1->left), height(k1->right));
    k2->hei= h+1 ;
    // k2 is now k1's right subtree
    h = Max( height(k2->right), k2->hei);
    k2->hei= h+1 ;
    return k2;


}

int AVL::Max(int x1,int x2)
{
    int maxvalue;
    if(x1>x2)
        return maxvalue=x1;
    else if(x2>x1)
        return maxvalue=x2;

}

AVL *AVL::doublerightleftrotation(AVL *k1)
{
    if( k1 == NULL ) return NULL;

    // single right rotate with k3 (k1's right child)
    k1->right= singlerightRotation(k1->right);

    // now single left rotate with k1 as the root
    return singleleftRotation(k1);
}

AVL *AVL::doubleleftrightrotation(AVL *k3)
{
    if( k3 == NULL ) return NULL;

    // single left rotate with k1 (k3's left child)
    k3->left= singleleftRotation(k3->left);

    // now single right rotate with k3 as the root
    return singlerightRotation(k3);

}

int AVL::height(AVL *head)
{
    if( head != NULL )
    return head->hei;
    return -1;
}

void AVL::inorder(AVL *head)
{
    if(head==NULL)
        return ;
    else
    {
        inorder(head->left);//recursive invoking of function
        cout<<head->data<<" ";
        inorder(head->right);//recursive invoking of function
    }
}

void AVL::postorder(AVL *head)
{
    if(head==NULL)
        return ;
    else
    {
        cout<<head->data<<" ";
        postorder(head->left);//recursive invoking of function
        postorder(head->right);//recursive invoking of function
    }
}

void AVL::preorder(AVL *head)
{
    if(head==NULL)
        return ;
    else
    {
        preorder(head->left);//recursive invoking of function
        preorder(head->right);//recursive invoking of function
        cout<<head->data<<" ";
    }
}

AVL *AVL::search(AVL *head,int num)
{
    if(head==NULL)
        return NULL;
    else if(num==head->data)
        return head;
    else if(num>head->data)
        return search(head->right,num);
    else if(num<head->data)
        return search(head->left,num);
}

AVL *AVL::deleteNode(AVL *head, int value)
{

    // STEP 1: PERFORM STANDARD BST DELETE
    if (head == NULL)
        return head;

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( value < head->data )
        head->left = deleteNode(head->left, value);

    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if( value > head->data )
        head->right = deleteNode(head->right, value);

    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (head->left == NULL) ||
            (head->right == NULL) )
        {
            AVL *dummy = head->left ? head->left : head->right;

            // No child case
            if (dummy == NULL)
            {
                dummy = head;
                head = NULL;
            }
            else // One child case
            *head = *dummy; // Copy the contents of
                           // the non-empty child
            free(dummy);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            AVL *dummy = minnode(head->right);

            // Copy the inorder successor's
            // data to this node
            head->data = dummy->data;

            // Delete the inorder successor
            head->right = deleteNode(head->right,
                                     dummy->data);
        }
    }

    // If the tree had only one node
    // then return
    if (head == NULL)
    return head;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    head->hei =1+ Max(height(head->left), height(head->right));

    // STEP 3: NOW CHECKING THE OTHER
    // THIS NODE (to check whether this
    // node became unbalanced)
    if(value<head->data)
    {
        int htdiff=height(head->left) - height(head->right);
        if( htdiff == 2 )
        {
            if( value < head->left->data ) // outside insertion case
              return singlerightRotation( head );
            else  // inside insertion case
              return doubleleftrightrotation( head );
        }
        return head;
    }
    else if(value>head->data)
    {
        int htdiff=height(head->right) - height(head->left);
        if( htdiff == 2 )
        {
            if( value < head->right->data ) // outside insertion case
              return singleleftRotation( head );
            else  // inside insertion case
              return doublerightleftrotation( head );
        }
    return head;
    }
    head->hei = 1 + Max(height(head->left), height(head->right)); // new height for root.
    return head;
}

AVL *AVL::minnode(AVL *head)
{
    AVL *current = head;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

AVL::~AVL()
{
    //dtor
}
