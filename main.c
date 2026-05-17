#include "inverted.h"

int main(int argc, char *argv[])
{
	F_node *head = NULL;
	M_node *HT[27];

	// initialize hash table
	for (int i = 0; i < 27; i++)
	{
		HT[i] = NULL;
	}

	// validate files
	validate_files(argv, &head);

	int option;

	do
	{
		printf("\nSelect your choice among following operations:\n");
		printf("1. Create Database\n");
		printf("2. Display Database\n");
		printf("3. Save Database\n");
		printf("4. Search\n");
		printf("5. Update Database\n");
		printf("6. Exit\n");
		printf("Enter your choice : ");

		scanf("%d", &option);

		switch (option)
		{
		case 1:
			create_database(HT, head);
			break;

		case 2:
			display_database(HT);
			break;

		case 3:
			save_database(HT);
			break;

		case 4:
			search_database(HT);
			break;

		case 5:
			update_database(HT, &head);
			break;

		case 6:
			break;

		default:
			printf("INFO : Please enter the valid option\n");
		}

	} while (option != 6);

	return 0;
}