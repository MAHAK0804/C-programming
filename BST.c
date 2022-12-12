#include <stdio.h>
#include <conio.h>
struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
};
struct tree *insert(struct tree *root, int x)
{
    if (!root)
    {
        root = (struct tree *)malloc(sizeof(struct tree));
        root->info = x;
        root->left = NULL;
        root->right = NULL;
        return (root);
    }
    if (root->left > x)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        if (root->left < x)
        {
            root->right = insert(root->right, x);
        }
    }
    return (root);
}
void inorder(struct tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->info);
        inorder(root->right);
    }
    return (root);
}
void postorder(struct tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->info);
    }
    return (root);
}
void preorder(struct tree *root)
{
    if (root != NULL)
    {
        printf("%d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
    return (root);
}
void delete(struct tree *r, int item)
{
    struct tree *ptr;
    if (ptr == NULL)
    {
        printf("\n Empty tree \n");
        return (0);
    }
    else if (item < r->info)
    {
        return (delete (r->left, item));
    }
    else if (item > ptr->info)
    {
        return (delete (r->right, item));
    }
    else
    {
        if (r->left == NULL)
        {
            ptr = r;
            r = r->right;
            free(ptr);
            return (1);
        }
        else if (r->right == NULL)
        {
            ptr = r;
            r = r->left;
            free(ptr);
            return (1);
        }
        else
        {
            ptr = r->left;
            while (ptr->right != NULL)
            {
                ptr = ptr->right;
                r->info = ptr->info;
                return (delete (r->left, ptr->info));
            }
        }
    }
}
struct tree *search(struct tree *root, int num)
{
    if (num = root->info)
    {
        printf("number  found");
    }
    else if ( root=NULL)
    {
        printf("number not found");
    }
    else if (num < root->info)
    {
        search(root->left, num);
    }
    else if (num > root->info)
    {
        search(root->right, num);
    }
}

int main()
{
    struct tree *root;
    int choice, item, item_no, num;
    root = NULL;
    do
    {
        do
        {
            printf("\n\t1.Insert in Binary Tree");
            printf("\n\t2.Delete from Binary Tree");
            printf("\n\t3.Inorder traversal OF Binary tree");
            printf("\n\t4.Postorder traversal OF Binary tree");
            printf("\n\t5.Preorder traversal OF Binary tree");
            printf("\n\t6.Search and replace");
            printf("\n\t7.exit");
            printf("\n*****ENTER CHOICE:*****");
            scanf("%d", &choice);
            if (choice < 1 || choice > 7)
            {
                printf("\n Invalid choice-try again");
            }
        } while (choice < 1 || choice > 7);
        switch (choice)
        {
        case 1:
            printf("\nEnter new element:");
            scanf("%d", &item);
            root = insert(root, item);
            printf("\n root is %d", root->info);
            break;
        case 2:
            printf("\nEnter the Element to be deleted:");
            scanf("%d", &item_no);
            delete (root, item_no);
            break;
        case 3:
            printf("\n Inorder traversal of Binary tree is:");
            inorder(root);
            break;
        case 4:
            printf("\n Postorder traversal of Binary tree is:");
            postorder(root);
            break;
        case 5:
            printf("\n Preorder traversal of Binary tree is:");
            preorder(root);
            break;
        case 6:
            printf("\n enter element to be search\n");
            scanf("%d", &num);
            printf("\n Search and replace operation in Binary tree");
            search(root, num);
            break;
        default:
            printf("\n End of program");
            break;
        }
    } while (choice != 7);
    return 0;
}