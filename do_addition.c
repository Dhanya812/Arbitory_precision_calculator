#include "apc.h"
int do_addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headRes,Dlist **tailRes)
{
	int carry = 0;  //consider carry variable initially 0
	int data=0;     
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	while(temp1 != NULL || temp2 !=NULL)   //checking the nodes present or not
	{
		if(temp1 != NULL && temp2 != NULL)	//if both nodes presents present
		{
			
			data = temp1->data + temp2->data +carry;   //add the temp->datas
			if(data > 9)  //if result is greater than 9 should take carry
			{
				int data1 = data %10;
				insert_at_first(headRes,tailRes,data1);
				carry = data/10;
			}
			else
			{
				insert_at_first(headRes,tailRes,data);
				carry = 0;
			}
			 temp1 = temp1->prev;
	                 temp2 = temp2->prev;
		}
		else if(temp1 != NULL && temp2 == NULL)		//if only one node present add that temp->data with carry
		{
			data = temp1->data + carry;
			insert_at_first(headRes,tailRes,data);
			temp1 = temp1->prev;
		}
		else if(temp1 == NULL && temp2 != NULL)
		{
			data = temp2->data + carry;
			insert_at_first(headRes,tailRes,data);
			temp2 = temp2->prev;
		}
	}
	if(carry >0)	//if there is any carry remained add
	{
		insert_at_first(headRes,tailRes,carry);
		carry =0;
	}
	return SUCCESS;
}



