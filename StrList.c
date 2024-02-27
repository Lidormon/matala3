#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

// Node structure for the linked list
struct Node {
    char *data;
    struct Node *next;
};

// StrList structure
typedef struct _StrList{
    struct Node *head;
}StrList;

// Function to create a new node
struct Node *createNode(const char *str) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = strdup(str); // is do malloc for each data
    newNode->next = NULL; // because i create one node
    return newNode;
}

// Allocates a new empty StrList
StrList* StrList_alloc() {
    StrList *list = (StrList*)malloc(sizeof(StrList));
    list->head = NULL;
    return list;
}

// Frees the memory and resources allocated to StrList
// Empties the StrList by freeing all nodes and their data
void StrList_free(StrList* StrList) {
    struct Node *current = StrList->head;
    struct Node *next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    StrList->head = NULL; // Set the head to NULL after emptying the list
}


// Returns the number of elements in the StrList
size_t StrList_size(const StrList* StrList) {
    size_t count = 0;
    struct Node *current = StrList->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Inserts an element in the end of the StrList
void StrList_insertLast(StrList* StrList, const char* data) {
    struct Node *newNode = createNode(data);

    if (StrList->head == NULL) {
        StrList->head = newNode;
        return;
    }

    struct Node *temp = StrList->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Inserts an element at given index
void StrList_insertAt(StrList* StrList, const char* data, int index) {
    struct Node *newNode = createNode(data);

    if (index == 0 || StrList->head == NULL) {
        newNode->next = StrList->head;
        StrList->head = newNode;
        return;
    }

    struct Node *temp = StrList->head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Returns the StrList first data
char* StrList_firstData(const StrList* StrList) {
    if (StrList->head != NULL)
        return StrList->head->data;
    else
        return NULL;
}

// Prints the StrList to the standard output
void StrList_print(const StrList* StrList) {

    
    if(StrList){
    	struct Node *current = StrList->head;
    	printf("%s", current->data);
    current = current->next;
    while (current != NULL) {
        printf(" %s", current->data);
        current = current->next;
    }
    }
    
    printf("\n");
}

// Prints the word at the given index to the standard output
void StrList_printAt(const StrList* StrList, int index) {
    struct Node *current = StrList->head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Index out of bounds\n");
    } else {
        printf("%s\n", current->data);
    }
}

// Return the amount of chars in the list
int StrList_printLen(const StrList* StrList) {
    int count = 0;
    struct Node *current = StrList->head;
    while (current != NULL) {
        count += strlen(current->data);
        current = current->next;
    }
    return count;
}

// Given a string, return the number of times it exists in the list
int StrList_count(StrList* StrList, const char* data) {
    int count = 0;
    struct Node *current = StrList->head;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Given a string and a list, remove all the appearances of this string in the list
void StrList_remove(StrList* StrList, const char* data) {
    struct Node *current = StrList->head;
    struct Node *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            if (prev == NULL) {
                StrList->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->data);
            free(current);
            if (prev == NULL) {   // now after the changes is the current
                current = StrList->head;
            } else {
                current = prev->next;
            }
        } else {       // move foward
            prev = current;
            current = current->next;
        }
    }
}

// Given an index and a list, remove the string at that index
void StrList_removeAt(StrList* StrList, int index) {
    if (StrList->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = StrList->head;

    if (index == 0) {
        StrList->head = temp->next;
        free(temp->data);
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    struct Node *nextNode = temp->next->next;

    free(temp->next->data);
    free(temp->next);

    temp->next = nextNode; // move foward
}

// Checks if two StrLists have the same elements
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
    struct Node *current1 = StrList1->head;
    struct Node *current2 = StrList2->head;

    while (current1 != NULL && current2 != NULL) {
        if (strcmp(current1->data, current2->data) != 0)
            return 0; // Not equal (return false)
        current1 = current1->next;
        current2 = current2->next;
    }

    // If both are NULL, lists are equal, otherwise not equal
    return (current1 == NULL && current2 == NULL); // return 1
}

// Clones the given StrList
StrList* StrList_clone(const StrList* strList) {
    StrList *newList = StrList_alloc();
    struct Node *current = strList->head;
    while (current != NULL) {
        StrList_insertLast(newList, current->data);
        current = current->next;
    }
    return newList;
}



// Reverse the given StrList
void StrList_reverse(StrList* StrList) {
    struct Node *prev = NULL;
    struct Node *current = StrList->head;
    struct Node *nextt = NULL;

    while (current != NULL) {
        nextt = current->next;
        current->next = prev;
        prev = current;
        current = nextt;
    }

    StrList->head = prev;
}



// Sort the given list in lexicographical order
void StrList_sort(StrList* StrList) {
    // Sorting a linked list in-place is generally more complex and
    // less efficient compared to arrays, using an array-based sorting
    // algorithm like quicksort would be better suited for efficiency.
    // However, for the sake of simplicity, we can implement a simpler
    // sorting algorithm like bubble sort here.
    struct Node *current = StrList->head;
    struct Node *index = NULL;
    char *temp;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (strcmp(current->data, index->data) > 0) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }

            index = index->next;
        }

        current = current->next;
    }
}

// Checks if the given list is sorted in lexicographical order
int StrList_isSorted(StrList* StrList) {
    struct Node *current = StrList->head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->data, current->next->data) > 0) {
            return 0; // Not sorted
        }
        current = current->next;
    }
    return 1; // Sorted
}
