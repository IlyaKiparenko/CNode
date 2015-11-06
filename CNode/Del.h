#include "CNode.h"
#include <iostream>
void Del(struct CNode** first)
{
	try{


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
	 catch(...){
	  std::cout <<"error"<< std::endl;
  }
}
