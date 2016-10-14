//
// Created by 황나윤 on 2016. 10. 13..
//
#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{
    char data;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

//root노드를 생성하여 left sub tree 와 right sub tree를 연결한다.
treeNode* makeRootNode(int data, treeNode* left, treeNode* right){
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));

    root->data=data;
    root->left=left;
    root->right=right;

    return root;
}

//순회. preorder visit-> left-> right

void preorder(treeNode* root){
    //root 노드가 존재한다면,
    if(root){
        printf("%c",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(treeNode* root){
    if(root){
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}
void postorder(treeNode* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%c",root->data);
    }
}

int main(){
    treeNode* n7=makeRootNode('D',NULL,NULL);
    treeNode* n6=makeRootNode('C',NULL,NULL);
    treeNode* n5=makeRootNode('B',NULL,NULL);
    treeNode* n4=makeRootNode('A',NULL,NULL);
    treeNode* n3=makeRootNode('/',n6,n7);
    treeNode* n2=makeRootNode('*',n4,n5);
    treeNode* n1=makeRootNode('-',n2,n3);

    printf("\n preorder\n");
    preorder(n1);

    printf("\n inorder\n");
    inorder(n1);

    printf("\n postorder\n");
    postorder(n1);

    getchar();

}