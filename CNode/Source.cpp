#include "Del.h"
#include <iostream>
int main(){
struct CNode* t;
  struct CNode* start; 
  start = new struct CNode();
	start->data = 0;
	start->next = 0;
	std::cout << start -> data << ' ';
    t=start;
  for(int i = 0; i < 1200; i++) {
	t->next = new struct CNode();
	t = t->next;
	t->data = i/(7);
	t->next = 0;
	std::cout << t -> data << ' ';
     
  }

 
  std:: cout << std:: endl;
  t=start;
  try{
  Del(&start);
  } catch(...){
	  std::cout <<"error"<< std::endl;
  }
 //ASSERT_ANY_THROW(Del(&start));
  while(t!=0) {
    std::cout << t -> data << ' ';
	t=t->next;
  }	
  return 0;
}