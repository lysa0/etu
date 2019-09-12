#include<bits/stdc++.h>
using namespace std;
#define GREEN(a) "\e\[32m" a "\e\[0m"
#define RED(a) "\e\[31m" a "\e\[0m"
#define eps 1e-306
template<class T> auto sign(T & number);
vector<int> get_bitmap_by_long(long number, vector<int> bytes, int depth);
vector<int> get_mantissa(double number, int depth, vector<int> bytes);
template<class T> int get_deg(T & number);
void tests();
void print(vector<int> v, float number);
void print(vector<int> v, double number);
void print(vector<int> v, int number);
void print(vector<int> v, unsigned int number);
void print(vector<int> v, short number);
void short_to_bitmap();
void int_to_bitmap();
void uint_to_bitmap();
void float_to_bitmap();
void double_to_bitmap();
