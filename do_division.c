#include "apc.h"

int cal(Dlist **h)  //function to calculate the number of nodes in the list.
{
	Dlist *t1 = *h;
	int count = 0;
	while(t1 != NULL)
	{
		count++;
		t1 = t1->next;
	}
	return count;
}

int compare(Dlist *rh1, Dlist *rh2)  //function to compare the data in the lists when both list having equal nodes.
{
	while(rh1 != NULL && rh2 != NULL)
	{
		if(rh1->data < rh2->data)
			return rh1->data - rh2->data;
		else if(rh1->data == rh2->data)
		{
			rh1 = rh1->next;
			rh2 = rh2->next;
		}
		else
		{
			return rh1->data - rh2->data;
		}
	}
	return 0;
}

int remove_zeros(Dlist **rh, Dlist **rt) //function to remove zeros in the result list after performing the subtraction
{
	while((*rh)->next != NULL && (*rh)->data == 0)
	{
		delete_first(rh, rt);
	}

}

int check_data(Dlist **rh, Dlist **rt)  //function to check the data in the list are all zeros.
{
	Dlist *t = *rh;
	while(t != NULL)
	{
		if(t->data != 0)
			return 0;
		t = t->next;
	}
	return 1;
}


int do_division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3, Dlist **head4, Dlist **tail4)
{
	int flag = 0;
	int c = 0;
	int c1 = cal(head2);
	Dlist *temp = *head1;
	int c2 = 0;
	while(c2 < c1)  //extract the nodes from the dividend list to intermediate list for the further process.
	{
		insert_at_last(head3, tail3, temp->data);
		c2 = cal(head3);
		if(temp->next != NULL)
		temp = temp->next;
	}
	if(temp->prev != NULL)
	temp = temp->prev;
	int c3 = cal(head1);
	if(c3 == c2 && temp->next != NULL)
		temp = temp->next;
	Dlist *head6 = NULL; //take one intermediate list to store the result of the subtraction. 
	Dlist *tail6 = NULL;
	int count = 0;
	while(temp != NULL)
	{
		while(c2 > c1)  //perform the subtraction when the number of nodes in the list3 is greater than number of nodes in the divisor list 
                {
			while(check_data(head3, tail3) == 1 && temp != NULL) //check for the data in the list3 are complete zeros,if yes,add 0 to the result
			{
				insert_at_last(head4, tail4, 0);
				temp = temp->next;
                                if(temp != NULL)
                                insert_at_last(head3, tail3, temp->data);
			}
			do_subtraction(head3, tail3, head2, tail2, &head6,&tail6);
                        count++;
                        remove_zeros(&head6, &tail6);  //remove zeros in the list3 after subtraction
                        *head3 = head6;
                        *tail3 = tail6;
                        head6 = NULL;
                        tail6 = NULL;
                        c2 = cal(head3);
                }
		if(c1 == c2 && compare(*head3, *head2) < 0 && temp != NULL)  //check with the data of both the lists when number of nodes are equal
		{
			if(temp != NULL)
			{
				temp = temp->next;
				if(temp != NULL)
					insert_at_last(head3, tail3, temp->data);
			}
			c2 = cal(head3);
			while(check_data(head3, tail3) == 1 && temp != NULL)
                        {
                                insert_at_last(head4, tail4, 0);
				temp = temp->next;
				if(temp != NULL)
				insert_at_last(head3, tail3, temp->data);
                        }
		}
		//if the data in list3 is greater than the divisor list when nodes are equal, perform the subtraction.
		while(c1 == c2 && compare(*head3, *head2) >= 0 && temp != NULL)
		{
			do_subtraction(head3, tail3, head2, tail2, &head6, &tail6);
                        count++;
                        remove_zeros(&head6, &tail6);
                        *head3 = head6;
                        *tail3 = tail6;
                        head6 = NULL;
                        tail6 = NULL;
                        c2 = cal(head3);
		}
		if(count != 0)
		{
		insert_at_last(head4, tail4, count);
		count = 0;
		}
		if(c2 < c1)  //if the number of nodes in the list3 is less than divisor list, add 0 to the division result list
		{
			temp = temp->next;
			if(temp != NULL)
			{
				if(temp->data == 0 && temp->next == NULL && compare(*head3, *head2) < 0) //add 0 to division result list, when the extracted node is last node and it is 0.
				{
					insert_at_last(head4, tail4, 0);
					break;
				}
				insert_at_last(head3, tail3, temp->data);
			}
			c2 = cal(head3);
			while(c2 <= c1 && temp != NULL && temp->next != NULL && compare(*head3, *head2) < 0) 
                	{
                        	insert_at_last(head4, tail4, 0);
                        	temp = temp->next;
                        	if(temp != NULL)
				{
                                	insert_at_last(head3, tail3, temp->data);
					remove_zeros(head3, tail3);
				}
                        	c2 = cal(head3);
                	}
		}
	}				
}
