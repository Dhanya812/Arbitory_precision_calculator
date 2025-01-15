#include "apc.h"
int do_multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headRes1,Dlist **tailRes1,Dlist **headRes2,Dlist **tailRes2,Dlist **headRes3,Dlist **tailRes3)
{
	int num1,num2,mul,carry = 0,pos = 0,digit;
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	insert_at_last(headRes2,tailRes2,0);
	while(temp2 != NULL)       //the multiplier should not be null
	{
		num2 = temp2->data;
		while(temp1 != NULL)	//if multiplicant is not null
		{
			num1 = temp1->data;
			mul = num1 * num2 + carry;  //multiply and add carry
			carry = 0;
			if(mul > 9)     //if result greater than 9 take carry
			{
			digit = mul % 10;  //the tens place data should be inserted and other consider as carry
			insert_at_first(headRes1,tailRes1,digit);
			carry = mul / 10;
			}
			else
			{
				insert_at_first(headRes1,tailRes1,mul);
			}
			temp1 = temp1->prev;
		}
		if(carry > 0) 		//if there is carry insert it at first
		{
			insert_at_first(headRes1,tailRes1,carry);
		}
		carry = 0;
		do_addition(headRes1,tailRes1,headRes2,tailRes2,headRes3,tailRes3);  //add r1 and r2 and store it to r3
		temp2 = temp2->prev;  //move temp to prev
		pos++;   //incremnet the pos which helps to addzeros at first
		temp1 = *tail1;
		*headRes2 = *headRes3;   //copy data in r3 to r2
		*tailRes2 = *tailRes3;
		*headRes3 = NULL;  //make r3 null
		*tailRes3 = NULL;
		delete_list(headRes1,tailRes1);  //free r1
		*headRes1 =NULL;   //now r1 = NULL
		*tailRes1 = NULL;
		if(pos !=0)   //this loop is to add zeros
		{
		 for(int i=0;i<pos;i++)
                {
                        insert_at_first(headRes1,tailRes1,0);
                }
		}
	}
	return SUCCESS;
}
	




