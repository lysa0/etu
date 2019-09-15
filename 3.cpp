#include "3.h"

int main(){
  //tests();
  cout << "Type of data? [short (S/s), int (I/i), uint (U/u), float (F/f), double (D/d)]" << endl;
  char type_of_data{};
  cin >> type_of_data;
  switch (type_of_data){
    case 'S': case 's': change_bytes_short(); break;
    case 'I': case 'i': change_bytes_int(); break;
    case 'U': case 'u': change_bytes_uint(); break;
    case 'F': case 'f': change_bytes_float(); break;
    case 'D': case 'd': change_bytes_double(); break;
  }
  return 0;
}


vector<int> change_bytes(vector<int> bitmap, map<int,int> bytes){
  for (auto byte:bytes){
    bitmap[byte.first]=byte.second;
  }
  return bitmap;
}

map<int,int> get_bytes(int size){
  int a{},b{};
  map<int,int> bytes{};
  cout << "Enter correct bit numbers (between 0 and " << size-1 << ") and them values {0, 1}, until ctrl+D" << endl;
  while(cin >> a >> b){
    if (b<0 || b>1){
      cerr << "INCORRECT BIT VALUE!!!!!!!" << endl;
      exit(1);
    }
    if (a<0 || a>size-1){
      cerr << "INCORRECT BIT NUMBER!!!!!!!" << endl;
      exit(1);
    }
    bytes[a]=b;
  }
  return bytes;
}

void change_bytes_float(){
  float number{};
  cout << "Enter float value between 1.175494351e-38 and 3.402823466e+38" << endl;
  cin >> number;
  vector<int> bitmap=binary_repr(number);
  print(bitmap, number);
  map<int, int> bytes = get_bytes(bitmap.size());
  vector<int> result=change_bytes(bitmap, bytes);
  print(result, number);
  float changed_number = get_float_by_bitmap(result);
  cout << changed_number << endl;
}

void change_bytes_double(){
  double number{};
    cout << "Enter double float value between -2.2250738585072014e-308, 1.7976931348623158e+308" << endl;
  cin >> number;
  vector<int> bitmap=binary_repr(number);
  print(bitmap, number);
  map<int, int> bytes = get_bytes(bitmap.size());
  vector<int> result=change_bytes(bitmap, bytes);
  print(result, number);
  double changed_number = get_double_by_bitmap(result);
  cout << changed_number << endl;
}

void change_bytes_int(){
  int number{};
  cout << "Enter integer value between -2'147'483'648 and 2'147'483'647" << endl;
  cin >> number;
  vector<int> bitmap=binary_repr(number);
  print(bitmap, number);
  map<int, int> bytes = get_bytes(bitmap.size());
  vector<int> result=change_bytes(bitmap, bytes);
  print(result, number);
  int changed_number = get_int_by_bitmap(result);
  cout << changed_number << endl;
}


void change_bytes_uint(){
  unsigned int number{};
  cout << "Enter uint integer value between 0 and 4'294'967'295" << endl;
  cin >> number;
  vector<int> bitmap=binary_repr(number);
  print(bitmap, number);
  map<int, int> bytes = get_bytes(bitmap.size());
  vector<int> result=change_bytes(bitmap, bytes);
  print(result, number);
  unsigned int changed_number = get_uint_by_bitmap(result);
  cout << changed_number << endl;
}


void change_bytes_short(){
  short number{};
  cout << "Enter short value between -32'768 and 32'767" << endl;
  cin >> number;
  vector<int> bitmap=binary_repr(number);
  print(bitmap, number);
  map<int, int> bytes = get_bytes(bitmap.size());
  vector<int> result=change_bytes(bitmap, bytes);
  print(result, number);
  short changed_number = get_short_by_bitmap(result);
  cout << changed_number << endl;
}

