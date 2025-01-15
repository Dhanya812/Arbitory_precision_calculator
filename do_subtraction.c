#include "apc.h"
int do_subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headRes,Dlist **tailRes)
{
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int num1=0;
	int num2=0;
	int borrow = 0;
	int res =0;
	while(temp1 !=NULL )		//here the first number should not be null
	{

	if(temp1 !=NULL && temp2 == NULL)	//if only temp1->data found
                {
		if((temp1->data == -1))		//check if the data is -1 due to borrow
                {
                        temp1->data = 9;      //then change it to 9
                        borrow = 1;   
                }
                        num1 = temp1->data;
                        num2 = 0;
                        res = num1 - num2;   //normalsubtraction
                        insert_at_first(headRes,tailRes,res);
			temp1 = temp1->prev;
			 if(borrow == 1) 	//if borrow is 1 then decrement 1 from prev temp->data
                        {
                                temp1->data = temp1->data - 1;
                                borrow = 0;
                        }

                }		


	else if(temp1!=NULL && temp2!=NULL)	//if both datas in temps present
	{
		if((temp1->data == -1) && (temp1->data<temp2->data)) 	//check for data is -1 due to borrow or temp1 < temp2
		{
			temp1->data = 9;
			borrow = 1;
		}
                {
                num1 = temp1->data;
                num2 = temp2->data;
                }

		if(num1 < num2)		//if num1 < num2 takeborrow and subtract
		{
			borrow = 1;
			num1 = num1+10;
			res = num1 - num2;
			insert_at_first(headRes,tailRes,res);

			temp1 = temp1->prev;
			temp2= temp2 ->prev;

			if(borrow == 1)
			{
				temp1->data = temp1->data - 1;
				borrow = 0;
			}

		}
		else if(num1 > num2)	//if num1 > num2 direct subtract and insert in list
		{
			res = num1 - num2;
			insert_at_first(headRes,tailRes,res);
			borrow = 0;
			temp1 = temp1->prev;
			temp2 = temp2->prev;
		}
		else if(num1 == num2)		//if both equal direct subtract
		{
			res = num1 - num2;
			insert_at_first(headRes,tailRes,res);
			temp1 = temp1->prev;
                        temp2 = temp2->prev;
			if(borrow == 1)
			 {
				 temp1->data = temp1->data -1;
			 }
                        borrow =0;
		}
		
	}
	}

	return SUCCESS;
}



                   
