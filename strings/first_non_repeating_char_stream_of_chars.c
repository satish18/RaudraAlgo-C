#include <stdio.h>
#include <stdlib.h>
#define NO_OF_CHAR 256
 
struct node
{
    char ch;
    struct node *next, *prev;
};
 
void appendNode(struct node **head, struct node **tail, char ch)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->ch = ch;
    temp->prev = temp->next = NULL;
 
    if (!(*head))
    {
        *head = *tail = temp;
        return;
    }
    (*tail)->next = temp;
    temp->prev = *tail;
    *tail = temp;
}
 
void removeNode(struct node **head, struct node **tail, struct node *temp)
{
    if (!(*head))
        return; 
    if (*head == temp)
        *head = (*head)->next;
    if (*tail == temp)
        *tail = (*tail)->prev;
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp->prev)
        temp->prev->next = temp->next; 
    free(temp);
}
 
void findFirstNonRepeatingChar()
{
    struct node *DLL[NO_OF_CHAR]; 
    int repeated[NO_OF_CHAR], index;
    char ch; 
    struct node *head = NULL, *tail = NULL;
    
    for(index = 0; index < NO_OF_CHAR; index++)
    {
        DLL[index] = NULL;
        repeated[index] = 0;
    } 
    char stream[] = "ravindra babu ravula";
    for(index = 0; stream[index]; index++)
    {
        ch = stream[index];
        printf("Reading %c from stream\n", ch); 
        if(!repeated[ch])
        {
            if(!DLL[ch])
            {
                appendNode(&head, &tail, stream[index]);
                DLL[ch] = tail;
            }
            else 
            {
                removeNode(&head, &tail, DLL[ch]);
                DLL[ch] = NULL;
                repeated[ch] = 0; 
            }
        } 
        if(head)
            printf("First non-repeating character so far is = %c\n", head->ch);
    }
}
 
int main()
{
    findFirstNonRepeatingChar();
    return 0;
}