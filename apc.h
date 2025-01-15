#ifndef APC_H
#define APC_L

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct node
{
        int data;
        struct node *prev;
        struct node *next;
}Dlist;
int compare_opr(Dlist *head1, Dlist *head2);
int do_addition(Dlist **,Dlist **,Dlist **,Dlist **,Dlist **,Dlist **);
int do_subtraction(Dlist **,Dlist **,Dlist **,Dlist **,Dlist **,Dlist **);
int do_multiplication(Dlist **,Dlist **,Dlist **,Dlist **,Dlist **,Dlist **,Dlist **,Dlist **,Dlist **,Dlist **);
int do_division(Dlist **,Dlist **,Dlist **,Dlist **,Dlist **,Dlist **,Dlist **,Dlist **);
void print_list(Dlist *head);
int delete_first(Dlist **head, Dlist **tail);
int insert_at_last(Dlist **head, Dlist **tail, int data);
int insert_at_first(Dlist **head, Dlist **tail, int data);
int delete_list(Dlist **head, Dlist **tail);
int cal(Dlist **head);
int compare(Dlist *, Dlist *);
int remove_zeros(Dlist **, Dlist **);
int check_data(Dlist **rh, Dlist **rt);
#endif
