#include "inverted.h"

int update_database(M_node *HT[], F_node **head)
{
    char fname[20];

    printf("Enter file name to update: ");
    scanf("%s", fname);

    // Step 1: validate extension
    if (strstr(fname, ".txt") == NULL)
    {
        printf("Invalid file\n");
        return FAILURE;
    }

    // Step 2: open file
    FILE *fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("File not found\n");
        return FAILURE;
    }

    // Step 3: check empty
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0)
    {
        printf("File is empty\n");
        fclose(fp);
        return FAILURE;
    }
    fclose(fp);

    // Step 4: check duplicate
    if (!check_duplicates(*head, fname))
    {
        printf("File already exists\n");
        return FAILURE;
    }

    // Step 5: insert into file list
    insert_last(head, fname);

    // Step 6: process only this file
    fp = fopen(fname, "r");

    char word[25];

    while (fscanf(fp, "%s", word) != EOF)
    {
        int index = get_index(word);

        if (HT[index] == NULL)
        {
            M_node *mnew = malloc(sizeof(M_node));
            S_node *snew = malloc(sizeof(S_node));

            strcpy(mnew->word, word);
            mnew->file_count = 1;
            mnew->main_link = NULL;
            mnew->sub_link = snew;

            strcpy(snew->filename, fname);
            snew->word_count = 1;
            snew->sub_link = NULL;

            HT[index] = mnew;
        }
        else
        {
            M_node *temp = HT[index];
            M_node *prev = NULL;

            while (temp != NULL)
            {
                if (!strcmp(temp->word, word))
                    break;

                prev = temp;
                temp = temp->main_link;
            }

            if (temp == NULL)
            {
                M_node *mnew = malloc(sizeof(M_node));
                S_node *snew = malloc(sizeof(S_node));

                strcpy(mnew->word, word);
                mnew->file_count = 1;
                mnew->main_link = NULL;
                mnew->sub_link = snew;

                strcpy(snew->filename, fname);
                snew->word_count = 1;
                snew->sub_link = NULL;

                prev->main_link = mnew;
            }
            else
            {
                S_node *stemp = temp->sub_link;
                S_node *sprev = NULL;

                while (stemp != NULL)
                {
                    if (!strcmp(stemp->filename, fname))
                        break;

                    sprev = stemp;
                    stemp = stemp->sub_link;
                }

                if (stemp == NULL)
                {
                    S_node *snew = malloc(sizeof(S_node));

                    strcpy(snew->filename, fname);
                    snew->word_count = 1;
                    snew->sub_link = NULL;

                    sprev->sub_link = snew;
                    temp->file_count++;
                }
                else
                {
                    stemp->word_count++;
                }
            }
        }
    }

    fclose(fp);

    printf("Database updated successfully\n");

    return SUCCESS;
}
