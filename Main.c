#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"

int main()
{
    StrList *head = StrList_alloc();
    int choice = 0;
    int index = 0;
    char *story = NULL;
    char inputString[100];
   
    int Flag = 1;
    int flag_list_is_free = 0;
   
    while (Flag) {
    
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf(" %d", &index);
                for (int i = 0; i < index; i++) {
                    story = (char*)malloc(100 * sizeof(char));
                    scanf(" %s", story);
                    StrList_insertLast(head, story);
                }
                break;
        

        case 2:
            scanf(" %d", &index);
                story = (char*)malloc(100 * sizeof(char));
                scanf("%s", story);
                StrList_insertAt(head, story, index);
                break;

        case 3:
            // printf("List: ");
             StrList_print(head);
               
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

        StrList_free(head);
   
    
    return 0;
}
