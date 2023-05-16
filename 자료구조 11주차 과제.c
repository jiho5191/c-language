#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char word[100];
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Ʈ�� ���� �Լ�
TreeNode* createNode(char* word) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->word, word);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ���� �Լ�
TreeNode* insertNode(TreeNode* root, char* word) {
    // Ʈ���� ����ִٸ� root�� �ܾ� ����
    if (root == NULL) {
        return createNode(word);
    }

    // �Է¹��� �ܾ�� root�� �ִ� �ܾ� strcmp�� ���ڿ� ��
    int compare = strcmp(word, root->word);

    if (compare < 0) {
        root->left = insertNode(root->left, word);
    }
    else if (compare > 0) {
        root->right = insertNode(root->right, word);
    }

    return root;
}

// ���� ��ȸ �Լ�
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);        // ���� ����Ʈ��
        printf("%s\n", root->word); // ��Ʈ ���
        inorder(root->right);       // ������ ����Ʈ��
    }
}

// �Ҵ�� �޸� ���� �Լ�
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    TreeNode* root = NULL;

    root = insertNode(root, "NETWORK");
    root = insertNode(root, "DATA");
    root = insertNode(root, "SYSTEM");
    root = insertNode(root, "PROGRAM");
    root = insertNode(root, "AI");
    root = insertNode(root, "SOFTWARE");
    root = insertNode(root, "DAUM");
    root = insertNode(root, "SOUND");

    /*
                       NETWORK
                    /          |
                 DATA        SYSTEM
                /   |        /
               AI  DAUM   PROGRAM
                                |
                            SOFTWARE
                                |
                              SOUND

    */

    printf("���� Ž�� Ʈ�� ���� ��ȸ ���\n");
    inorder(root);

    freeTree(root);

    return 0;
}