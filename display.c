#include "inverted.h"

void display_database(M_node *HT[])
{
    printf("-----------------------------------------------------------------\n");
    printf("%-10s", "Index");
    printf("%-10s", "Word");
    printf("%-15s", "File Count");
    printf("%15s", "File Name");
    printf("%15s", "Word Count");
    printf("\n");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < 27; i++)
    {
        if (HT[i] != NULL)
        {
            M_node *temp = HT[i];
            while (temp != NULL)
            {
                printf("%-10d", i);
                printf("%-10s", temp->word);
                printf("%-15d", temp->file_count);
                S_node *stemp = temp->sub_link;
                while (stemp != NULL)
                {
                    printf("%15s", stemp->filename);
                    printf("%15d", stemp->word_count);
                    if (stemp->sub_link != NULL)
                    {
                        printf("\n");
                        printf("                                   ");
                    }
                    stemp = stemp->sub_link;
                }
                temp = temp->main_link;
                printf("\n");
            }
        }
    }
    printf("-----------------------------------------------------------------\n");
}
