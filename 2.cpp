#include "2.h"

int main(){
  //tests();
  cout << "Type of data? [short (S/s), int (I/i), uint (U/u), float (F/f), double (D/d)]" << endl;
  char type_of_data{};
  cin >> type_of_data;
  switch (type_of_data){
    case 'S': case 's': short_to_bitmap(); break;
    case 'I': case 'i': int_to_bitmap(); break;
    case 'U': case 'u': uint_to_bitmap(); break;
    case 'F': case 'f': float_to_bitmap(); break;
    case 'D': case 'd': double_to_bitmap(); break;
  }
  return 0;
}

void short_to_bitmap(){
  cout << "Enter short value between -32'768 and 32'767" << endl;
  short number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result, number);
}

void int_to_bitmap(){
  cout << "Enter integer value between -2'147'483'648 and 2'147'483'647" << endl;
  int number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result, number);
}

void uint_to_bitmap(){
  cout << "Enter uint integer value between 0 and 4'294'967'295" << endl;
  uint number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result, number);
}

void float_to_bitmap(){
  cout << "Enter float value between 1.175494351e-38 and 3.402823466e+38" << endl;
  float number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result, number);
}

void double_to_bitmap(){
  cout << "Enter double float value between -2.2250738585072014e-308, 1.7976931348623158e+308" << endl;
  double number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result, number);
}
