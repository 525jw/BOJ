#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct _node{
    struct _node* llink;
    struct _node* rlink;
    int lnum;
    int rnum;
    int key;
}node;
int N;
node* createnode(int newkey){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->key=newkey;
    newnode->lnum=0;
    newnode->rnum=0;
    newnode->llink=NULL;
    newnode->rlink=NULL;
    return newnode;
}
node* insertnode(node* root,int newkey){
    if(root){
        if(root->lnum < root->rnum){
            if(root->key>newkey)
            root->lnum++;
            root->llink=insertnode(root->llink,newkey);
        }
        else if(root->lnum >= root->rnum){
            root->rnum++;
            root->rlink=insertnode(root->rlink,newkey);
        }
    }
    else
        root=createnode(newkey);
    return root;
}
int main(){
    cin>>N;
    node* priority_queue=NULL;
    while(N--){
        int inp;
        cin>>inp;
        priority_queue=insertnode(priority_queue,inp);
        cout<<'#';
        cout<<priority_queue->lnum<<' '<<priority_queue->rnum<<' ';
        cout<<priority_queue->key<<endl;
    }
    return 0;
}
