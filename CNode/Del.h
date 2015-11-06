#include "CNode.h"

void Del(CNode** first)
{
	if (*first!=0)
	{
		CNode* curr=*first;
		while (curr!=0)
		{
			if (curr->data != (curr->next)->data)
				curr=curr->next;
			else
			{
				CNode* tmp;
				tmp=curr->next;
				curr->next=(curr->next)->next;
				delete tmp;
			}

		}

	}

}
