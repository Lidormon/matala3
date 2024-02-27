#include "StrList.h"

int main()
{
    StrList *head = StrList_alloc();
    int choice, index;
    char inputString[100];
    int firstTimeFlag = 1;
    do
    {
        // printf("\nMenu:\n");
        // printf("1. Put string at the end\n");
        // printf("2. Put string at index\n");
        // printf("3. Print list\n");
        // printf("4. Print list size\n");
        // printf("5. Print string at index\n");
        // printf("6. Print number of characters in the list\n");
        // printf("7. Print occurrences of a string\n");
        // printf("8. Delete all occurrences of a string\n");
        // printf("9. Delete at index\n");
        // printf("10. Reverse the list\n");
        // printf("11. Delete entire list\n");
        // printf("12. Arrange list in lexicographic order\n");
        // printf("13. Check if the list is in lexicographic order\n");
        // printf("0. Exit\n");

        // printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // printf("number of words: ");
            scanf("%d", &index);
            // printf("Enter string: ");
            scanf(" %[^\n]", inputString);          // Reads the whole line including spaces
            char *token = strtok(inputString, " "); // Tokenize the string by space

            for (int i = 0; i < index; i++)
            {
                StrList_insertLast(head, token);
                token = strtok(NULL, " "); // Move to the next token
            }
            

            break;

        case 2:
            // printf("Enter index: ");
            scanf("%d", &index);
            
            // printf("Enter string: ");
            scanf("%s", inputString);
           
            StrList_insertAt(head, inputString, index);
            break;

        case 3:
            // printf("List: ");
             if (firstTimeFlag) {
                printf("\n");
                StrList_print(head);
                firstTimeFlag = 0; // Set the flag to indicate it's not the first time anymore
            } else {
                StrList_print(head);
            }
           
            break;

        case 4:
            // printf("List size: %zu\n", StrList_size(head));
             printf("%zu\n", StrList_size(head));
            break;

        case 5:
            // printf("Enter index: ");
            scanf("%d", &index);
            StrList_printAt(head, index);
            break;

        case 6:
            //"Number of characters in the list:
            printf("%d\n", StrList_printLen(head));
            break;

        case 7:
            // printf("Enter string to search: ");
            scanf("%s", inputString);
           
            // printf("Occurrences of %s: %d\n", inputString, StrList_count(head, inputString));
            printf("%d\n", StrList_count(head, inputString));
            break;

        case 8:
            // printf("Enter string to delete: ");
            scanf("%s", inputString);
            StrList_remove(head, inputString);
            break;

        case 9:
            // printf("Enter index to delete: ");
            scanf("%d", &index);
            StrList_removeAt(head, index);
            break;

        case 10:
            StrList_reverse(head);
            // printf("List reversed.\n");
            break;

        case 11:
            StrList_free(head);
            // printf("List deleted.\n");
            break;

        case 12:
            StrList_sort(head);
            // printf("List arranged in lexicographic order.\n");
            break;

        case 13:
            if (StrList_isSorted(head))
            {
                // printf("List is in lexicographic order.\n");
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
            break;

        case 0:
           printf("\n");
           break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
        
    } while (choice != 0);
    
    return 0;
}
