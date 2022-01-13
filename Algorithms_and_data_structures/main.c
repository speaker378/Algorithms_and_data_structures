//
//  main.c
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 15.12.2021.
//

//  1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
//  2. Переписать программу, реализующее двоичное дерево поиска.
//      а) Добавить в него обход дерева различными способами;
//      б) Реализовать поиск в двоичном дереве поиска;
//      в) *Добавить в программу обработку командной строки с помощью которой можно указывать из какого файла считывать данные, каким образом обходить дерево.
//  3. *Разработать базу данных студентов из двух полей “Имя”, “Возраст”, “Табельный номер” в которой использовать все знания, полученные на уроках.
//  Считайте данные в двоичное дерево поиска. Реализуйте поиск по какому-нибудь полю базы данных (возраст, вес)

#include <stdio.h>
#include <stdlib.h>

int hash(char *string)
{
    int result = 0;
    while(*string)
    {
        result += *string;
        string++;
    }
    return result;
}


typedef int T;
typedef struct Node
{
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

void printTree(Node *root) {
    if (root)
    {
        printf("%d", root->data);
        if (root->left || root->right)
        {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

Node* createNode(T value, Node *parent)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->data = value;
    temp->parent = parent;
    return temp;
}

void insertNode(Node **head, int value) {
    if (*head == NULL)
        *head = createNode(value, NULL);
    else if (value > (*head)->data) {
        if ((*head)->right)
            insertNode(&(*head)->right, value);
        else
            (*head)->right = createNode(value, *head);
    } else  {
        if ((*head)->left)
            insertNode(&(*head)->left, value);
        else
            (*head)->left = createNode(value, *head);
    }
}

void preorderTravers(Node *root) {
    if (root) {
        printf("%i ", root->data);
        preorderTravers(root->left);
        preorderTravers(root->right);
    }
}

void postorderTravers(Node *root) {
    if (root) {
        postorderTravers(root->left);
        postorderTravers(root->right);
        printf("%i ", root->data);
    }
}

void inorderTravers(Node *root) {
    if (root) {
        inorderTravers(root->left);
        printf("%i ", root->data);
        inorderTravers(root->right);
    }
}

T search(Node *root, T value)
{
    if (root == NULL)
        return -1;
    else if (root->data == value)
        return value;
    else if (root->data <= value)
        return search(root->right, value);
    else
        return search(root->left, value);
}

int main ()
{
    int Hash;
    Hash = hash("Test Text");
    printf("%i \n", Hash);

    int data[10] = {12, 3, 1, 10, 222, 4, 18, 11, 120, 3};
    Node *root = NULL;
    for (int i = 0; i <= 9; ++i) {
        insertNode(&root, data[i]);
    }
    printTree(root);
    printf("\n");
    preorderTravers(root);
    printf("\n");
    postorderTravers(root);
    printf("\n");
    inorderTravers(root);
    printf("\n");
    printf("%i", search(root, 10));

    return 0;
}
