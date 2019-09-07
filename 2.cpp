#include<bits/stdc++.h>
#define GREEN(a) "\e\[32m" a "\e\[0m"
#define RED(a) "\e\[31m" a "\e\[0m"
#define ASSERT(m, t) if(!(m)) cout << RED(t": fail. not "#m"!!!") << endl; else cout << GREEN(t": ok.") << endl;
#define MNTS_SIZE 52
#define eps 1e-200

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
  /*cout << "Type of data? [short (S/s), int (I/i), long (L/l), float (F/f), double (D/d)]" << endl;
  char type_of_data{};
  cin >> type_of_data;
  switch (type_of_data){
        case 'S': case 's': short_to_bitmap();
        case 'I': case 'i': int_to_bitmap();
        case 'L': case 'l': long_to_bitmap();
        case 'F': case 'f': float_to_bitmap();
        case 'D': case 'd': double_to_bitmap();
  }*/
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


template<class T> auto sign(T & number){
  return number<0?1:0;
}

vector<int> get_bitmap_by_long(long number, vector<int> bytes={}, int depth=0){
  if (number<=0) return {};
  int byte=number%2;
  //cout << number << ' ' << depth << ' ' << byte << endl;
  bytes=get_bitmap_by_long(number>>1, bytes, ++depth);
  bytes.push_back(byte);
  return bytes;
}

vector<int> get_mantissa(double number, int depth=0, vector<int> bytes={}){
  if (number==0. || depth>MNTS_SIZE) return bytes;
  double a=1./(double)pow(2.,depth);
  int byte=number-a<0.?0:1;
  //cout << a << ' ' << number << ' ' << depth << ' ' << byte << endl;
  bytes.push_back(byte);
  return get_mantissa(number-a*byte, ++depth, bytes);
}

template<class T> int get_deg(T & number){
  int deg{};
  if (number>=2.)
    while(++deg && number/pow(2, deg)>=2.);
  else
    if (number<=1.)
      while(--deg && number/pow(2, deg)<=1.);
  //cout << deg << " deg" << endl;
  return deg;
}


vector<int> binary_repr(float number){
  int deg=get_deg(number);
  vector<int> mantissa = get_mantissa(abs(number/(pow(2,deg)+eps)));
  //cout << mantissa.size() << endl;
  //cout << "mantissa:" << endl;
  //print(mantissa);
  if (mantissa.size()<24)
    for(int i=mantissa.size(); i<24; i++)
      mantissa.push_back(0);
  mantissa.erase(mantissa.begin()+1);
  vector<int> exponenta = get_bitmap_by_long(deg+127);
  //exponenta.push_back(sign(deg));
  //cout << exponenta.size() << endl;
  //cout << "exponenta:" << endl;
  //print(exponenta);  
  vector<int> result={sign(number)};
  result.insert(result.end(), 8-exponenta.size(), 0);
  result.insert(result.end(),exponenta.begin(),exponenta.end());
  result.insert(result.end(),mantissa.begin(),mantissa.end());
  cout << "size of mantissa: : " << mantissa.size() << endl;
  cout << "size of exponenta: : " << exponenta.size() << endl;
  cout << "size of vector: : " << result.size() << endl;
  return result;
}

vector<int> binary_repr(double number){
  int deg=get_deg(number);
  vector<int> mantissa = get_mantissa(abs(number/(pow(2,deg)+eps)));
  //cout << mantissa.size() << endl;
  //cout << "mantissa:" << endl;
  print(mantissa);
  for(int i=mantissa.size(); i<53; i++)
    mantissa.push_back(0);
  mantissa.erase(mantissa.begin()+1);
  vector<int> exponenta = get_bitmap_by_long(deg+1023);
  //cout << exponenta.size() << endl;
  //cout << "exponenta:" << endl;
  //print(exponenta);
  vector<int> result={sign(number)};
  result.insert(result.begin(), 11-exponenta.size(), 0);
  result.insert(result.end(),exponenta.begin(),exponenta.end());
  result.insert(result.end(),mantissa.begin(),mantissa.end());
  cout << "size of mantissa: : " << mantissa.size() << endl;
  cout << "size of exponenta: : " << exponenta.size() << endl;
  cout << "size of vector: : " << result.size() << endl;
  return result;
}

vector<int> binary_repr(short number){
  vector<int> exponenta = get_bitmap_by_long(abs(number));
  //cout << exponenta.size() << endl;
  //cout << "exponenta:" << endl;
  //print(exponenta);
  vector<int> result(16-exponenta.size());
  result[0] = sign(number);
  //cout << exponenta.size() << endl;
  result.insert(result.begin()+(16-exponenta.size()),exponenta.begin(),exponenta.end());
  return result;
}

vector<int> binary_repr(int number){
  vector<int> exponenta = get_bitmap_by_long(abs(number));
  //cout << exponenta.size() << endl;
  //cout << "exponenta:" << endl;
  //print(exponenta);
  vector<int> result(32-exponenta.size());
  result[0] = sign(number);
  //cout << exponenta.size() << endl;
  result.insert(result.begin()+(32-exponenta.size()),exponenta.begin(),exponenta.end());
  //result.insert(result.end(),exponenta.begin(),exponenta.end());
  return result;
}

vector<int> binary_repr(long number){
  vector<int> exponenta = get_bitmap_by_long(abs(number));
  //cout << exponenta.size() << endl;
  //cout << "exponenta:" << endl;
  //print(exponenta);
  vector<int> result(64-exponenta.size());
  result[0] = sign(number);
  //cout << exponenta.size() << endl;
  result.insert(result.begin()+(64-exponenta.size()),exponenta.begin(),exponenta.end());
  //result.insert(result.end(),exponenta.begin(),exponenta.end());
  return result;
}


void print(vector<int> v){ 
  int cnt{};
  for (vector<int>::const_iterator byte = v.begin(); byte!=v.end(); ++byte){
    cnt++;
    if (byte == v.begin())
      cout << *byte << ' ';
    else
      if(*byte){
        //string a=GREEN(str_byte);
        cout << GREEN(+to_string(*byte)+);
      }
      else
        cout << (*byte);
    //cout << endl << byte-v.begin() << endl;
    if (cnt%4==0)
      cout << ' ';
  }
  cout << endl;
}

void print(vector<int> v, int number){ 
  int cnt{};
  for (vector<int>::const_iterator byte = v.begin(); byte!=v.end(); ++byte){
    cnt++;
    if (byte == v.begin())
      cout << *byte << ' ';
    else
      if(*byte){
        //string a=GREEN(str_byte);
        cout << GREEN(+to_string(*byte)+);
      }
      else
        cout << (*byte);
    //cout << endl << byte-v.begin() << endl;
    if (cnt%4==0)
      cout << ' ';
  }
  cout << endl;
}

void print(vector<int> v, float number){ 
  int cnt{};
  for (vector<int>::const_iterator byte = v.begin(); byte!=v.end(); ++byte){
    cnt++;
    if (byte == v.begin())
      cout << *byte << ' ';
    else
      if(*byte){
        //string a=GREEN(str_byte);
        cout << GREEN(+to_string(*byte)+);
      }
      else
        cout << (*byte);
    //cout << endl << byte-v.begin() << endl;
    if (cnt%4==0)
      cout << ' ';
  }
  cout << endl;
}

void print(vector<int> v, double number){ 
  int cnt{};
  for (vector<int>::const_iterator byte = v.begin(); byte!=v.end(); ++byte){
    cnt++;
    if (byte == v.begin())
      cout << *byte << ' ';
    else
      if(*byte){
        //string a=GREEN(str_byte);
        cout << GREEN(+to_string(*byte)+);
      }
      else
        cout << (*byte);
    //cout << endl << byte-v.begin() << endl;
    if (cnt%4==0)
      cout << ' ';
  }
  cout << endl;
}




void short_to_bitmap(){
  cout << "Print short value between -32'768 and 32'767" << endl;
  short number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result);
}

void int_to_bitmap(){
  cout << "Print integer value between -2'147'483'648 and 2'147'483'647" << endl;
  int number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result);
}

void long_to_bitmap(){
  cout << "Print long integer value between  -9'223'372'036'854'775'808 and 9'223'372'036'854'775'807" << endl;
  long number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result);
}

void float_to_bitmap(){
  cout << "Print float value between 1.175494351e-38 and 3.402823466e+38" << endl;
  float number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result);
}

void double_to_bitmap(){
  cout << "Print double float value between -2.2250738585072014e-308, 1.7976931348623158e+308" << endl;
  double number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result);
}


void int_tests(){
  int number=0;
  vector<int> result=binary_repr(number);
  print(result);
  vector<int> expected{0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
  ASSERT(expected == result, "test 1");

  number=1;
  result=binary_repr(number);
  print(result);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected == result, "test 2");
 

  number=1023;
  result=binary_repr(number);
  print(result);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected == result, "test 3");
 


  number=-1;
  result=binary_repr(number);
  print(result);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected == result, "test 4");
 

  number=-511;
  result=binary_repr(number);
  print(result);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected == result, "test 5");
 
}


void short_tests(){
  short number=0;
  vector<int> result=binary_repr(number);
  print(result);
  vector<int> expected{0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
  ASSERT(expected == result, "test 6");

  number=1;
  result=binary_repr(number);
  print(result);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected == result, "test 7");
 

  number=1023;
  result=binary_repr(number);
  print(result);
  expected = {0,0,0,0, 0,0,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected == result, "test 8");
 


  number=-1;
  result=binary_repr(number);
  print(result);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected == result, "test 9");
 

  number=-511;
  result=binary_repr(number);
  print(result);
  expected = {1,0,0,0, 0,0,0,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected == result, "test 10");
 
}


void long_tests(){
  long number=0;
  vector<int> result=binary_repr(number);
  print(result);
  vector<int> expected{0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
  ASSERT(expected == result, "test 11");

  number=1;
  result=binary_repr(number);
  print(result);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected == result, "test 12");
 

  number=9223372036854775807;
  result=binary_repr(number);
  print(result);
  expected = {0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected == result, "test 13");
 


  number=-1;
  result=binary_repr(number);
  print(result);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected == result, "test 14");
 

  number=-9223372036854775807;
  result=binary_repr(number);
  print(result);
  expected = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected == result, "test 15");
 
}


void float_tests(){
  float number=3.14;
  vector<int> result=binary_repr(number);
  print(result);
  vector<int> expected{0,1,0,0, 0,0,0,0, 0,1,0,0, 1,0,0,0, 1,1,1,1, 0,1,0,1, 1,1,0,0, 0,0,1,0};
  ASSERT(expected == result, "test 16");


  number=0.;
  result=binary_repr(number);
  print(result);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
  ASSERT(expected == result, "test 17");
 /*

  number=9223372036854775807;
  result=binary_repr(number);
  print(result);
  expected = {0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected == result, "test 18");
 

  number=-1;
  result=binary_repr(number);
  print(result);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected == result, "test 19");
 

  number=-9223372036854775807;
  result=binary_repr(number);
  print(result);
  expected = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected == result, "test 20");
  */
}


void double_tests(){
  double number=3.14;
  vector<int> result=binary_repr(number);
  print(result);
  vector<int> expected{0,1,0,0, 0,0,0,0, 0,0,0,0, 1,0,0,1, 0,0,0,1, 1,1,1,0, 1,0,1,1, 1,0,0,0, 0,1,0,1, 0,0,0,1, 1,1,1,0, 1,0,1,1, 1,0,0,0, 0,1,0,1, 0,0,0,1, 1,1,1,0};
  ASSERT(expected == result, "test 21");


  number=0.;
  result=binary_repr(number);
  print(result);
  expected = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
  ASSERT(expected == result, "test 22");
 /*

  number=9223372036854775807;
  result=binary_repr(number);
  print(result);
  expected = {0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected == result, "test 23");
 

  number=-1;
  result=binary_repr(number);
  print(result);
  expected = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
  ASSERT(expected == result, "test 24");
 

  number=-9223372036854775807;
  result=binary_repr(number);
  print(result);
  expected = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  ASSERT(expected == result, "test 25");
  */
}

void tests(){
  int_tests();
  short_tests();
  long_tests();
  float_tests();
  double_tests();
}
