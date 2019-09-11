template<class T> auto sign(T & number){
  return number<0?1:0;
}

vector<int> get_bitmap_by_long_long(long long number, vector<int> bytes={}, int depth=0){
  if (number<=0) return {};
  int byte=number%2;
  //cout << number << ' ' << depth << ' ' << byte << endl;
  bytes=get_bitmap_by_long_long(number>>1, bytes, ++depth);
  bytes.push_back(byte);
  return bytes;
}

vector<int> get_mantissa(double number, int depth=0, vector<int> bytes={}, int mnts_size=52){
  if (number<eps || depth>mnts_size) return bytes;
  double a=1./(double)pow(2.,depth);
  int byte=abs(number-a)<eps?1:number-a<eps?0:1;
  //cout << number-a << ' ' << a << ' ' << number << ' ' << depth << ' ' << byte << endl;
  bytes.push_back(byte);
  return get_mantissa(number-a*1, ++depth, bytes, mnts_size);
}

template<class T> int get_deg(T & number){
  int deg{};
  if (number>=2.)
    while(++deg && number/pow(2, deg)>2.);
  else
    if (number<=1.)
      while(--deg && number/pow(2, deg)<=1.);
  //cout << deg << " deg" << endl;
  return deg;
}


vector<int> binary_repr(float number){
  int deg=get_deg(number);
  float mantissa=number/(pow(2., deg));
  vector<int> mantissa_bm = get_mantissa(mantissa,0,{},23);
  //cout << mantissa_bm.size() << endl;
  //cout << "mantissa_bm:" << endl;
  //print(mantissa_bm);
  if (mantissa_bm.size()<24)
    for(int i=mantissa_bm.size(); i<24; i++)
      mantissa_bm.push_back(0);
  mantissa_bm.erase(mantissa_bm.begin()+1);
  vector<int> exponenta = get_bitmap_by_long_long(deg+127);
  //exponenta.push_back(sign(deg));
  //cout << exponenta.size() << endl;
  //cout << "exponenta:" << endl;
  //print(exponenta);  
  vector<int> result={sign(number)};
  result.insert(result.end(), 8-exponenta.size(), 0);
  result.insert(result.end(),exponenta.begin(),exponenta.end());
  result.insert(result.end(),mantissa_bm.begin(),mantissa_bm.end());
  //cout << "size of mantissa: : " << mantissa_bm.size() << endl;
  //cout << "size of exponenta: : " << exponenta.size() << endl;
  //cout << "size of vector: : " << result.size() << endl;
  return result;
}

vector<int> binary_repr(double number){
  int deg=get_deg(number);
  double mantissa=number/(pow(2., deg));
  cout << mantissa << endl;
  vector<int> mantissa_bm = (mantissa>=2.-2*eps)?vector<int>{1}:get_mantissa(abs(number/(pow(2,deg))));
  //cout << mantissa_bm.size() << endl;
  //cout << "mantissa_bm:" << endl;
  //print(mantissa_bm);
  for(int i=mantissa_bm.size(); i<53; i++)
    mantissa_bm.push_back(0);
  mantissa_bm.erase(mantissa_bm.begin()+1);
  vector<int> exponenta = get_bitmap_by_long_long(deg+1023);
  //cout << exponenta.size() << endl;
  //cout << "exponenta:" << endl;
  //print(exponenta);
  vector<int> result={sign(number)};
  result.insert(result.begin(), 11-exponenta.size(), 0);
  result.insert(result.end(),exponenta.begin(),exponenta.end());
  result.insert(result.end(),mantissa_bm.begin(),mantissa_bm.end());
  //cout << "size of mantissa: : " << mantissa_bm.size() << endl;
  //cout << "size of exponenta: : " << exponenta.size() << endl;
  //cout << "size of vector: : " << result.size() << endl;
  return result;
}

vector<int> binary_repr(short number){
  vector<int> bitmap = number<0?get_bitmap_by_long_long(pow(2,15)+number):get_bitmap_by_long_long(number);
  //cout << exponenta.size() << endl;
  //cout << "exponenta:" << endl;
  //print(exponenta);
  vector<int> result(16-bitmap.size());
  result[0] = sign(number);
  //cout << exponenta.size() << endl;
  result.insert(result.begin()+(16-bitmap.size()),bitmap.begin(),bitmap.end());
  return result;
}

vector<int> binary_repr(int number){
  vector<int> bitmap = number<0?get_bitmap_by_long_long(pow(2,31)+number):get_bitmap_by_long_long(number);
  //cout << exponenta.size() << endl;
  //cout << "exponenta:" << endl;
  //print(exponenta);
  vector<int> result(32-bitmap.size());
  result[0] = sign(number);
  //cout << exponenta.size() << endl;
  result.insert(result.begin()+(32-bitmap.size()),bitmap.begin(),bitmap.end());
  //result.insert(result.end(),exponenta.begin(),exponenta.end());
  return result;
}

vector<int> binary_repr(unsigned int number){
  vector<int> bitmap = get_bitmap_by_long_long(number);
  //cout << exponenta.size() << endl;
  //cout << "exponenta:" << endl;
  //print(exponenta);
  vector<int> result(64-bitmap.size());
  result[0] = sign(number);
  //cout << exponenta.size() << endl;
  result.insert(result.begin()+(64-bitmap.size()),bitmap.begin(),bitmap.end());
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
  cout << "Enter short value between -32'768 and 32'767" << endl;
  short number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result);
}

void int_to_bitmap(){
  cout << "Enter integer value between -2'147'483'648 and 2'147'483'647" << endl;
  int number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result);
}

void uint_to_bitmap(){
  cout << "Enter uint integer value between  -9'223'372'036'854'775'808 and 9'223'372'036'854'775'807" << endl;
  uint number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result);
}

void float_to_bitmap(){
  cout << "Enter float value between 1.175494351e-38 and 3.402823466e+38" << endl;
  float number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result);
}

void double_to_bitmap(){
  cout << "Enter double float value between -2.2250738585072014e-308, 1.7976931348623158e+308" << endl;
  double number{};
  cin >> number;
  vector<int> result=binary_repr(number);
  print(result);
}
