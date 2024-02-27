#include "StrList.h"
#include <stdio.h>
#include <string.h> // Include this header for strtok

int main()
{
    StrList *head = StrList_alloc();
    int choice = 0;
    int index = 0;
    char inputString[100];
    int firstTimeFlag = 1;
    int Flag = 1;
    int flag_list_is_free = 0;
   
    while (Flag) {
    
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d", &index);
            scanf(" %[^\n]", inputString); // Reads the whole line including spaces
            char *token = strtok(inputString, " "); // Tokenize the string by space

            for (int i = 0; i < index; i++)
            {
                StrList_insertLast(head, token);
                // Move to the next token
                token = strtok(NULL, " ");
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
            flag_list_is_free = 1;	
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
           Flag = 0;
           break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
        
    }
    if(flag_list_is_free == 0){
        free(head);
    } 
    
    return 0;
}
        
    } 
    
    return 0;
}
