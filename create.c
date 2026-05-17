#include "inverted.h"
int cr = 0;
void create_database(M_node *HT[], F_node *head)
{
    if (cr < 1)
    {
        cr++;

        static int flag = 0;

        if (flag == 0)
        {
            for (int i = 0; i < 27; i++)
            {
                HT[i] = NULL;
            }
            flag = 1;
        }

        while (head != NULL) // file by file
        {
            FILE *fp = fopen(head->f_name, "r");

            if (fp == NULL)
            {
                head = head->link;
                continue;
            }

            char word[25];

            while (fscanf(fp, "%s", word) != EOF) // word by word
            {
                int index = get_index(word);

                // CASE 1: index empty
                if (HT[index] == NULL)
                {
                    M_node *mnew = malloc(sizeof(M_node));
                    S_node *snew = malloc(sizeof(S_node));

                    strcpy(mnew->word, word);
                    mnew->file_count = 1;
                    mnew->main_link = NULL;
                    mnew->sub_link = snew;

                    strcpy(snew->filename, head->f_name);
                    snew->word_count = 1;
                    snew->sub_link = NULL;

                    HT[index] = mnew;
                }
                else
                {
                    M_node *temp = HT[index];
                    M_node *prev = NULL;

                    // search word
                    while (temp != NULL)
                    {
                        if (strcmp(temp->word, word) == 0)
                            break;

                        prev = temp;
                        temp = temp->main_link;
                    }

                    // CASE 2: word not found
                    if (temp == NULL)
                    {
                        M_node *mnew = malloc(sizeof(M_node));
                        S_node *snew = malloc(sizeof(S_node));

                        strcpy(mnew->word, word);
                        mnew->file_count = 1;
                        mnew->main_link = NULL;
                        mnew->sub_link = snew;

                        strcpy(snew->filename, head->f_name);
                        snew->word_count = 1;
                        snew->sub_link = NULL;

                        prev->main_link = mnew;
                    }
                    else
                    {
                        // CASE 3: word found → check file
                        S_node *stemp = temp->sub_link;
                        S_node *sprev = NULL;

                        while (stemp != NULL)
                        {
                            if (strcmp(stemp->filename, head->f_name) == 0)
                                break;

                            sprev = stemp;
                            stemp = stemp->sub_link;
                        }

                        // file not found
                        if (stemp == NULL)
                        {
                            S_node *snew = malloc(sizeof(S_node));

                            strcpy(snew->filename, head->f_name);
                            snew->word_count = 1;
                            snew->sub_link = NULL;

                            sprev->sub_link = snew;
                            temp->file_count++;
                        }
                        else
                        {
                            // file found → increment count
                            stemp->word_count++;
                        }
                    }
                }
            }

            fclose(fp);
            head = head->link;
        }

        printf("Database created successfully\n");
    }
}