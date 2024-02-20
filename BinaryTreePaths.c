#include<stdio.h>
int resIdx;
void findpath (struct TreeNode* root, int *ls,int ls_idx,char **res);
char ** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    resIdx = 0;
    int i;
    char ** res = (char **)malloc(sizeof(char *) * 40);
    int ls[150];
    findpath(root,&ls[0],0,res);
    *returnSize = resIdx;
    return &res[0];

}


void findpath (struct TreeNode* root, int *ls,int ls_idx,char **res)
{
    char temp[100];
    int l=0,i=0;
    if (root->left == NULL && root->right == NULL)
    {
        ls[ls_idx] = root->val;
        ls_idx+=1;
        res[resIdx] = (char *)malloc(sizeof(char) * 100);
        while (i < ls_idx)
        {
            if (i==0)
            {
                l = l + sprintf(&temp[l], "%d", ls[i]);

            }
            else
            {
                l = l + sprintf(&temp[l], "->%d", ls[i]);
            }
            i++;
        }
        strcpy(res[resIdx],temp);
        resIdx++;
        return; 
    }  
    ls[ls_idx] = root->val;
    if (root->left != NULL)
    {
        findpath(root->left,ls,ls_idx+1,res);   
    }
    
    if (root->right != NULL)
    {
        findpath(root->right,ls,ls_idx+1,res); 
    }
    return;
    
}


