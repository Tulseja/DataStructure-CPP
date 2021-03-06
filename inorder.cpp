#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std ;
struct node
{
    int data ;
    struct node *left ;
    struct node *right ;

};

void inorder(struct node *root)
{
    struct node *curr = root ;
    if( curr == NULL )
    return ;

    stack<node *>st ;
    //st.push(curr);
    bool done = false ;
    while(!done)
    {
       // cout<<"size of stack : "<<st.size()<<endl;


        if(curr)
        {
           // cout<<"current node : "<<curr->data;//" : psuhed !! "<<endl ;
            st.push(curr);
            curr=curr->left ;
        }
        else
        {
            if(st.empty() == false)
            {
                curr = st.top();

                st.pop();
                cout<<curr->data<<" ";//"  is popped !! "<<endl  ;
             //   if(curr->right)
                curr=curr->right ;
            }
            else
            done = true ;
        }
    }

}
struct node *newNode(int data )
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data ;
    temp->left =NULL ;
    temp->right =NULL;

    return temp ;
}
void preorder(struct node *root)
{
    stack<node *>st ;
    bool done = true ;
    struct node *cur = root ;

    while(done)
    {
        if(cur)
        {
            cout<<cur->data<<" " ;
            st.push(cur);
            cur=cur->left ;
        }
        else
        {
            if(st.empty() == false)
            {
                cur = st.top();
                st.pop();
                cur = cur->right ;

            }
            else
            done = false ;
        }
    }
}
void inorderwithoutstack(struct node *root)
{
    struct node *curr = root ;
    struct node *temp ;
    while(curr)
    {
        if(curr->left == NULL )
        {
            cout<<curr->data<<" ";
            curr=curr->right;

        }
        else
        {
            temp=curr->left ;
            while(temp->right != NULL && temp->right != curr)
            {
                temp=temp->right;
            }
            if(temp->right == NULL)
            {
                cout<<temp->data <<" " ;
                temp->right = curr ;
                curr = curr->left ;
            }
            else
            {
                temp->right=NULL;
                cout<<curr->data<<" "<<endl ;
                curr = curr->right;
            }
        }


    }

}
void postorder(struct node *root)
{
    struct node *curr;
    stack<node *>st1,st2;
    if(root == NULL )
    return ;

    curr = root ;
    struct node * temp ;
    st1.push(root);
    while(st1.empty() == false)
    {
        temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left)
        st1.push(temp->left);
        if(temp->right)
        st1.push(temp->right);
    }
    while(st2.empty()==false)
    {
        temp=st2.top();
        st2.pop() ;
        cout<<temp->data<<" ";
    }


}
void postorderonestack(struct node *root)
{
    stack<node *>st ;
    struct node *curr , *temp ;
    curr=root;

    while(curr)
    {
        if(curr->right)
        {
            st.push(curr->right);
            st.push(curr);

        }
        if(curr->left)
        {
            curr = curr->left ;

        }
        else
        cout<<curr->data<<" ";

    }

    while(st.empty() == false)
    {

    }
}
int main(void)
{
//    struct node*NewRoot=NULL;
    struct node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
    //levelorder(root);

//    inorderwithoutstack(root);
    postorder(root);

    return 0 ;
}

