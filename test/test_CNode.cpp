#include "C:/Vladimir/CNode/CNode/Del.h"

#include "C:/Vladimir/CNode/gtest/gtest.h"

CNode* create(int* val, int len) {
  if(len > 0) {
    CNode* start = new struct CNode;
    CNode* tmp = start;
    start -> data = val[0];
    for (int i = 1; i < len; i++) {
      tmp -> next = new struct CNode;
      tmp = tmp -> next;
      tmp -> data = val[i];
    }
    tmp -> next = 0;
    return start;
  } else
    return 0;
}

int comp(CNode* a, CNode* b) {
  if((a == 0) || (b == 0)) return (a == b);
  while((a != 0) && (b != 0) && (a -> data == b -> data)) {
    a = a -> next;
    b = b -> next;
  }
  return (a == b);
}

void del(CNode* a){
  if(a != 0) 
    del(a -> next);
  delete a;
}

TEST(CNode, can_delete_empty_list)
{
  CNode* start = create(0,0);
  ASSERT_NO_THROW(Del(&start));
}

TEST(CNode, can_delete_list_right)
{
  int TEST_SIZE = 10;
  int TEST_K = 2;
  int TEST_SUM = 0;
  for (int size = 0; size < TEST_SIZE; size++) {
    for (int k = 1; k < TEST_K + 1; k++) {
      int tsize=(size!=0)?(size-1)/k+1:0;
      int* r = new int[size];
      int* q = new int[tsize];
      for (int i = 0; i < size; i++)
        r[i] = i / k;
      for (int i = 0; i < tsize; i++)
        q[i] = i;
      CNode* start = create(r, size);
      CNode* test = create(q, tsize);
      ASSERT_NO_THROW(Del(&start));
      EXPECT_EQ(1, comp(test, start));
      del(start);
      del(test);
      delete[] r;
      delete[] q;
    }
  }
}