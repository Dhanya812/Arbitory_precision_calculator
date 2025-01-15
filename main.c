#include "apc.h"
#include<string.h>

void print_list(Dlist *head)			//printing list function
{
        /* Cheking the list is empty or not */
        if (head == NULL)
        {
                printf("INFO : List is empty\n");
        }
        else
        {
            while (head)
            {
                    /* Printing the list */
		    printf("%d",head->data);
                    head = head -> next;
            }
         printf("\n");
    }
}

int insert_at_last(Dlist **head, Dlist **tail, int data)	//inserting at last 
{
	//Allocating the memory for new node
	Dlist *new = malloc(sizeof (Dlist));

	// If the node is not created the returning failure
	if (!new)
	{
		return FAILURE;
	}
	new -> data = data;
	new -> prev = NULL;
	new -> next = NULL;

	// If the list is empty then inserting the node as first node
	if (!*head && !*tail)
	{	
		*head = *tail = new;
		return SUCCESS;
	}
	new -> prev = *tail;
	(*tail) -> next = new;
	*tail = new;
	return SUCCESS;
}
int insert_at_first(Dlist **head, Dlist **tail, int data)	//insert at first function
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    else
    {
        new->data = data;
        new->prev = NULL;
        new->next = NULL;

        if(*head == NULL)
        {
            *head = *tail = new;
            return SUCCESS;
        }
        else
        {
        new->next = *head;
        (*head)->prev = new;
        *head =new;
        return SUCCESS;
        }
    }
}	

int delete_first(Dlist **head, Dlist **tail)	//delete first element from the list function
{
    if(*head == NULL)
    return FAILURE;
    
    if(*head == *tail)
    {
        free(*head);
        *head = *tail =NULL;
        return SUCCESS;
    }
    else
    {
       Dlist *temp = *head;
        *head = (*head)->next;
        free(temp);
        (*head)->prev = NULL;
        return SUCCESS;
    }
}
int delete_list(Dlist **head, Dlist **tail)	//delete list function
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    while(*head!=NULL)
    {
        Dlist *temp = *head;
        *head = (temp)->next;
        temp->prev = NULL;
        free(temp);
    }
       
}
int main(int argc, char *argv[])
{
	char option;
	{
		if(argc < 3)			//checking the valid number of arguments
		{
			printf("ERROR : Insuffient argument passed\n");
			return 1;
		}
		//creating double linked lists
		Dlist *head1 = NULL,*tail1 = NULL;
		Dlist *head2 = NULL, *tail2 = NULL;
		Dlist *headRes = NULL,*tailRes = NULL;
		Dlist *headRes1 = NULL, *tailRes1 = NULL;
		Dlist *headRes2 = NULL, *tailRes2 = NULL;
		Dlist *headRes3 = NULL, *tailRes3 = NULL;
		char op;
		int i=0;
		while(argv[1][i] != '\0')	//passing element tolist using insert at last
		{
			 if(argv[1][i] == '-')   //checking signs
                        printf("-");
                else if(argv[1][i] == '+')    
                        printf("+");

		else if((argv[1][i] >= '0') || (argv[1][i] <='9'))
			{
			insert_at_last(&head1,&tail1,(argv[1][i]-48));
			}
			i++;
		}
		print_list(head1);
		int j=0;
		while(argv[3][j] != '\0')
                {
			if(argv[3][j] == '-')
                        printf("-");
                else if(argv[3][j] == '+')
                        printf("+");

		else if((argv[3][j] >= '0') || (argv[3][j] <='9'))
                        {
                        insert_at_last(&head2,&tail2,(argv[3][j]-48));
			}
			j++;
                }
		
		char operator = argv[2][0];
		printf("%c\n",operator);
		print_list(head2);
		switch(operator)		//switch case for operators
		{
			case '+':		//addition
				if((argv[1][0]=='-') && (argv[3][0]=='-'))	//if both negative - + - = -, o/p will be negative
				{
				do_addition(&head1,&tail1,&head2,&tail2,&headRes,&tailRes);
				printf("the result of addition is \n");
				printf("-");
				print_list(headRes);
				break;
				}
				else if(((argv[1][0] == '-') && ((argv[3][0]>='0') || (argv[3][0]<='9'))) || ((argv[3][0] == '-') && ((argv[1][0]>='0') || (argv[1][0]<='9'))))
                                {
		                        goto label;	
                                        print_list(headRes);
                                        break;
                                }
				else if(((argv[1][0] == '+') && (argv[3][0] == '+')) || (((argv[1][0]>='0') || (argv[1][0]<='9')) && ((argv[3][0]>='0') || argv[3][0]<='9')))
				{
					do_addition(&head1,&tail1,&head2,&tail2,&headRes,&tailRes);
        	                        printf("the result of addition is ");
	                                printf("+");
                                	print_list(headRes);
                                	break;
                                }

		label: case '-':                //subtraction
				//finding lengths of string
				int len1 = strlen(argv[1]); 
				int len2 = strlen(argv[3]);
				char sign;
				if((argv[1][0] >='0' && argv[1][0] <='9') && (argv[3][0] >= '0' && argv[3][0] <='9'))  //if both positive + - + = +
				{
				if(len1 == len2)	//if length same compare using strcmp
				{
					if(strcmp(argv[1],argv[3]) < 0 )
					{
						Dlist *temp = head1;
						head1 = head2;
						head2 = temp;
						Dlist *temp1 = tail1;
						tail1 = tail2;
						tail2 = temp1;

						do_subtraction(&head1,&tail1,&head2,&tail2,&headRes,&tailRes);
						printf("the result of subtraction is ");
						printf("-");
					}
					else if(strcmp(argv[1],argv[3]) == 0)
					{
						 do_subtraction(&head1,&tail1,&head2,&tail2,&headRes,&tailRes);
						 printf("the result of subreaction is ");
					}
					else if(strcmp(argv[1],argv[3]) > 0 )
					{
						do_subtraction(&head1,&tail1,&head2,&tail2,&headRes,&tailRes);
						printf("the result of subtraction is ");
					}
				}

				else if(len1 > len2)
				{
					do_subtraction(&head1,&tail1,&head2,&tail2,&headRes,&tailRes);
					printf("the result of subtraction is ");
					printf("-");
				}
				else if(len1 < len2)
				{
					 Dlist *temp = head1;
                                        head1 = head2;
                                        head2 = temp;
                                        Dlist *temp1 = tail1;
                                        tail1 = tail2;
                                        tail2 = temp1;
                                        do_subtraction(&head1,&tail1,&head2,&tail2,&headRes,&tailRes);
                                }}
				if(((argv[1][0] == '-') && ((argv[3][0] >= '0' && argv[3][0] <='9')))||((argv[1][0]>='0' && argv[1][0]<='9') && (argv[3][0] =='-')))   //if - - + and + - - == - condition
				{
					do_addition(&head1,&tail1,&head2,&tail2,&headRes,&tailRes);
					printf("the result of subtraction is ");
					printf("-");
				}
                                print_list(headRes);
                                break;

			 case 'x':    // multiplication
				   printf("the result of multiplication is ");
				if((argv[1][0] =='-' && argv[3][0] == '-') || ((argv[1][0] =='+' && argv[3][0] == '+')))  // - - - = +
				{
					 printf("+");
					
				}
				else
				printf("-");

                               do_multiplication(&head1,&tail1,&head2,&tail2,&headRes1,&tailRes1,&headRes2,&tailRes2,&headRes3,&tailRes3);
                                print_list(headRes2);
				
                               break;
				

			 case '/':   //division
				 printf("the result of division is ");
			       if((argv[1][0] == '-' && argv[3][0] == '-' ) || (argv[1][0] =='+' && argv[3][0] == '+')) //same sign cancels and gives positive value
				       printf("+");
			       else
				       printf("-");
			       int len3 = strlen(argv[1]);
			       int len4 = strlen(argv[3]);
			       if(len3 < len4)
			       {
				       printf("the numerator is less than the denominator. so the result is 0\n");
			       }
			       if(len3 > len4)
			       {
				       do_division(&head1,&tail1,&head2,&tail2,&headRes1,&tailRes1,&headRes2,&tailRes2);
				        print_list(headRes2);
			       }
			       if(len3 == len4)
			       {
				       if(strcmp(argv[1],argv[3]) < 0)
				       {
					        printf("the numerator is less than the denominator. so the result is 0\n");
                                       }
				       else if(strcmp(argv[1],argv[3]) == 0)
				       {

					        printf("the numerator is equal than the denominator. so the result is 1\n");
                               	       }
				       else
				       {
					       do_division(&head1,&tail1,&head2,&tail2,&headRes1,&tailRes1,&headRes2,&tailRes2);
					        print_list(headRes2);
				       }
			       }
                                break;

			default:
				printf("ERROR : Invalid option\n");
				return 1;
		}
		printf("\n");

	}
	return 0;

}

