#include<bits/stdc++.h>
#include "common.h"
#include "tests.h"
#include "common.cpp"
#include "tests.cpp"

using namespace std;

int main(){
  tests();
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

