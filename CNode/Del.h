#include "CNode.h"

void Del(struct CNode** first)
{
	if (*first!=0)
	{
		struct CNode* curr=*first;
		while (curr!=0)
		{
			if (curr->data != (curr->next)->data)
				curr=curr->next;
			else
			{
				struct CNode* tmp;
				tmp=curr->next;
				curr->next=(curr->next)->next;
				delete tmp;
			}

		}

	}

}
