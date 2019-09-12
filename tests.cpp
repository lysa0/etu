#include "tests.h"

void tests(){
  int_tests();
  short_tests();
  uint_tests();
  float_tests();
  double_tests();
}

void int_tests(){
  int number=0;
  vector<int> result=binary_repr(number);
  print(result, number);
  vector<int> expected{0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
  ASSERT(expected, result, "test 1");

  number=1;
  result=binary_repr(number);
  print(result, number);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected, result, "test 2");
 

  number=1023;
  result=binary_repr(number);
  print(result, number);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected, result, "test 3");
 


  number=-1;
  result=binary_repr(number);
  print(result, number);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected, result, "test 4");
 

  number=-512;
  result=binary_repr(number);
  print(result, number);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected, result, "test 5");
 
}


void short_tests(){
  short number=0;
  vector<int> result=binary_repr(number);
  print(result, number);
  vector<int> expected{0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
  ASSERT(expected, result, "test 6");

  number=1;
  result=binary_repr(number);
  print(result, number);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected, result, "test 7");
 

  number=1023;
  result=binary_repr(number);
  print(result, number);
  expected = {0,0,0,0, 0,0,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected, result, "test 8");
 


  number=-1;
  result=binary_repr(number);
  print(result, number);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected, result, "test 9");
 

  number=-511;
  result=binary_repr(number);
  print(result, number);
  expected = {1,0,0,0, 0,0,0,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected, result, "test 10");
 
}


void uint_tests(){
  unsigned int number=0;
  vector<int> result=binary_repr(number);
  print(result, number);
  vector<int> expected{0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
  ASSERT(expected, result, "test 11");

  number=511;
  result=binary_repr(number);
  print(result, number);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected, result, "test 12");
 

  number=pow(2,32)-1;
  result=binary_repr(number);
  print(result, number);
  expected = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected, result, "test 13");
 
}


void float_tests(){
  float number=3.14;
  vector<int> result=binary_repr(number);
  print(result, number);
  vector<int> expected{0,1,0,0, 0,0,0,0, 0,1,0,0, 1,0,0,0, 1,1,1,1, 0,1,0,1, 1,1,0,0, 0,0,1,0};
  ASSERT(expected, result, "test 16");


  number=0.;
  result=binary_repr(number);
  print(result, number);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
  ASSERT(expected, result, "test 17");
 /*

  number=9223372036854775807;
  result=binary_repr(number);
  print(result, number);
  expected = {0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected, result, "test 18");
 

  number=-1;
  result=binary_repr(number);
  print(result, number);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected, result, "test 19");
 

  number=-9223372036854775807;
  result=binary_repr(number);
  print(result, number);
  expected = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected, result, "test 20");
  */
}


void double_tests(){
  double number=3.14;
  vector<int> result=binary_repr(number);
  print(result, number);
  vector<int> expected{0,1,0,0, 0,0,0,0, 0,0,0,0, 1,0,0,1, 0,0,0,1, 1,1,1,0, 1,0,1,1, 1,0,0,0, 0,1,0,1, 0,0,0,1, 1,1,1,0, 1,0,1,1, 1,0,0,0, 0,1,0,1, 0,0,0,1, 1,1,1,0};
  ASSERT(expected, result, "test 21");


  number=0.;
  result=binary_repr(number);
  print(result, number);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
  ASSERT(expected, result, "test 22");
 /*

  number=9223372036854775807;
  result=binary_repr(number);
  print(result, number);
  expected = {0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected, result, "test 23");
 

  number=-1;
  result=binary_repr(number);
  print(result, number);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected, result, "test 24");
 

  number=-9223372036854775807;
  result=binary_repr(number);
  print(result, number);
  expected = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected, result, "test 25");
  */
}
