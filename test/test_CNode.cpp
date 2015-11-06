#include "C:/Ilya/Vova/CNode/Del.h"

#include "C:/Ilya/Vova/gtest/gtest.h"
#include <iostream>
TEST(CNode, can_vova_do_nothing)
{
  struct CNode* t;
  struct CNode* start; 
  start = new struct CNode();
	start->data = 0;
	start->next = 0;
	std::cout << start -> data << ' ';
    t=start;
  for(int i = 0; i < 10; i++) {
	t->next = new struct CNode();
	t = t->next;
	t->data = i/3;
	t->next = 0;
	std::cout << t -> data << ' ';
     
  }
  std:: cout << std:: endl;
  t=start;
  ASSERT_NO_THROW(Del(&start));
  while(t!=0) {
    std::cout << t -> data << ' ';
	t=t->next;
  }	




 
}