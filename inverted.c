#include "inverted.h"

/* Function definitions */

/* validate files */
void validate_files(char *argv[], F_node **head)
{
    for (int i = 1; argv[i] != NULL; i++)
    {
        char *str = strstr(argv[i], ".txt");

        if (str == NULL || strcmp(str, ".txt") != 0)
        {
            continue;
        }

        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL)
        {
            continue;
        }

        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0)
        {
            fclose(fp);
            continue;
        }
        fclose(fp);

        if (!check_duplicates(*head, argv[i]))
        {
            continue;
        }

        insert_last(head, argv[i]);
    }
}

/* check duplicates */
int check_duplicates(F_node *head, char *f_name)
{
    F_node *temp = head;
    while (temp != NULL)
    {
        if (!strcmp(temp->f_name, f_name))
        {
            return FAILURE;
        }
        temp = temp->link;
    }
    return SUCCESS;
}

/* insert last */
int insert_last(F_node **head, char *f_name)
{
    F_node *new = malloc(sizeof(F_node));

    if (new == NULL)
        return FAILURE;

    if (*head == NULL)
    {
        strcpy(new->f_name, f_name);
        new->link = NULL;
        *head = new;
    }
    else
    {
        F_node *temp = *head;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = new;
        new->link = NULL;
        strcpy(new->f_name, f_name);
    }

    return SUCCESS;
}

int print_filenames(F_node *head)
{
    F_node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        printf("%s\n", temp->f_name);
        temp = temp->link;
        count++;
    }

    return count;
}

int get_index(char *word)
{
    if (word[0] >= 'A' && word[0] <= 'Z')
    {
        return word[0] - 'A';
    }
    else if (word[0] >= 'a' && word[0] <= 'z')
    {
        return word[0] - 'a';
    }
    else
    {
        return 26;
    }
}