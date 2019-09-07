#include<bits/stdc++.h>
#include "common.h"
#include "tests.h"
#include "common.cpp"
#include "tests.cpp"


using namespace std;

template<class T> auto sign(T & number);
vector<int> get_bitmap_by_long(long number, vector<int> bytes, int depth);
vector<int> get_mantissa(double number, int depth, vector<int> bytes);
template<class T> int get_deg(T & number);
void tests();
void print(vector<int> v);
vector<int> binary_repr(float number);
vector<int> binary_repr(double number);
vector<int> binary_repr(short number);
vector<int> binary_repr(int number);
vector<int> binary_repr(long number);
void short_to_bitmap();
void int_to_bitmap();
void long_to_bitmap();
void float_to_bitmap();
void double_to_bitmap();


int main(){
  tests();
  cout << "Type of data? [short (S/s), int (I/i), long (L/l), float (F/f), double (D/d)]" << endl;
  char type_of_data{};
  cin >> type_of_data;
  switch (type_of_data){
        case 'S': case 's': short_to_bitmap();
        case 'I': case 'i': int_to_bitmap();
        case 'L': case 'l': long_to_bitmap();
        case 'F': case 'f': float_to_bitmap();
        case 'D': case 'd': double_to_bitmap();
  }
  /*int number{};
  #cin >> number;
  vector<int> result = binary_repr(number);
  //result = binary_repr((float)1.2);
  //print(result);
  //result = binary_repr((double)1.2);
  //print(result);
  //result = binary_repr((int)12);
  //print(result);
  //result = binary_repr((long)12);
  print(result);
  */
  return 0;
}

