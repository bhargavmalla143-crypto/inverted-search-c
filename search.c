#include "inverted.h"

int search_database(M_node *HT[])
{
    char str[20];
    printf("Enter the Word to Search : ");
    scanf("%s", str);

    int i = get_index(str);

    printf("-----------------------------------------------\n");

    if (HT[i] == NULL)
    {
        printf("Word Not Present\n");
        printf("-----------------------------------------------\n");
        return FAILURE;
    }

    M_node *temp = HT[i];
    int c = 0;

    while (temp != NULL)
    {
        if (!strcmp(str, temp->word))
        {
            c++;

            printf("Word '%s' is present in %d files\n", str, temp->file_count);

            S_node *stemp = temp->sub_link;

            while (stemp != NULL)
            {
                printf("In %s : %d times\n", stemp->filename, stemp->word_count);
                stemp = stemp->sub_link;
            }
            break;
        }
        else
        {
            temp = temp->main_link;
        }
    }

    if (c == 0)
    {
        printf("Word Not present in any file\n");
    }

    printf("-----------------------------------------------\n");

    return SUCCESS;
}
