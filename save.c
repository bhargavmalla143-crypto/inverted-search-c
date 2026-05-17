#include "inverted.h"

int save_database(M_node *HT[])
{
    char str[15];

    printf("Enter the Backup file name : ");
    scanf("%s", str);

    if (strstr(str, ".txt") == NULL)
    {
        printf("File name should have .txt\n");
        return FAILURE;
    }

    FILE *fp = fopen(str, "w");

    if (fp == NULL)
    {
        printf("File not created\n");
        return FAILURE;
    }

    for (int i = 0; i < 27; i++)
    {
        if (HT[i] != NULL)
        {
            M_node *temp = HT[i];

            while (temp != NULL)
            {
                fprintf(fp, "#");
                fprintf(fp, "%d;", i);
                fprintf(fp, "%s;", temp->word);
                fprintf(fp, "%d;", temp->file_count);

                S_node *stemp = temp->sub_link;

                while (stemp != NULL)
                {
                    fprintf(fp, "%s;", stemp->filename);
                    fprintf(fp, "%d;", stemp->word_count);
                    stemp = stemp->sub_link;
                }

                fprintf(fp, "#\n");
                temp = temp->main_link;
            }
        }
    }

    fclose(fp);

    printf("Database saved successfully\n");

    return SUCCESS;
}