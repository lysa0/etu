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

vector<int> get_mantissa(double number, int depth=0, vector<int> bytes={}, int mnts_size=52){
  if (number<eps || depth>mnts_size) return bytes;
  double a=1./(double)pow(2.,depth);
  int byte=number-a<eps?0:1;
  //cout << a << ' ' << number << ' ' << depth << ' ' << byte << endl;
  bytes.push_back(byte);
  return get_mantissa(number-a*byte, ++depth, bytes, mnts_size);
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
  vector<int> mantissa = get_mantissa(abs(number/(pow(2,deg)+eps)),0,{},23);
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
  //cout << "size of mantissa: : " << mantissa.size() << endl;
  //cout << "size of exponenta: : " << exponenta.size() << endl;
  //cout << "size of vector: : " << result.size() << endl;
  return result;
}

vector<int> binary_repr(double number){
  int deg=get_deg(number);
  vector<int> mantissa = get_mantissa(abs(number/(pow(2,deg)+eps)));
  //cout << mantissa.size() << endl;
  //cout << "mantissa:" << endl;
  //print(mantissa);
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
  //cout << "size of mantissa: : " << mantissa.size() << endl;
  //cout << "size of exponenta: : " << exponenta.size() << endl;
  //cout << "size of vector: : " << result.size() << endl;
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

void long_to_bitmap(){
  cout << "Enter long integer value between  -9'223'372'036'854'775'808 and 9'223'372'036'854'775'807" << endl;
  long number{};
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
