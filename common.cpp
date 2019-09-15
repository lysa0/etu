#include "common.h"

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

vector<int> get_mantissa(double number, int depth=0, vector<int> bytes={}, int mnts_size=52, double rev_pow=1.){
	if (number<eps || depth>mnts_size) return bytes;
	//double a=1./(double)pow(2.,depth);
    double a=rev_pow;
    rev_pow/=2.;
	int byte=abs(number-a)<0?1:number-a<eps?0:1;
	//cout << number-a << ' ' << a << ' ' << number << ' ' << depth << ' ' << byte << endl;
	bytes.push_back(byte);
	return get_mantissa(number-a*byte, ++depth, bytes, mnts_size, rev_pow);
}

template<class T> int get_deg(T & number){
	//if (number<1){
	//	return 0;
	//}
	int deg{};
	if (number>=2.)
		while(++deg && number/pow(2, deg)>=2.);
	else
		if (number<1.)
			while(--deg && number/pow(2, deg)<1.);
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
	//cout << mantissa_bm.size() << endl;
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
	int _sign = sign(number);
	number=(double)fabs(number);
	//cout << number << endl;
	int deg=get_deg(number);
	//cout << deg << endl;
	double mantissa=number/(pow(2., deg));
	//cout << mantissa << endl;
	vector<int> mantissa_bm = (mantissa>=2.)?vector<int>{1}:get_mantissa(abs(number/(pow(2,deg)))-1	);
	//cout << mantissa_bm.size() << endl;
	//cout << "mantissa_bm:" << endl;
	//print(mantissa_bm);
	for(int i=mantissa_bm.size(); i<53; i++)
		mantissa_bm.push_back(0);
	mantissa_bm.erase(mantissa_bm.begin());
	vector<int> exponenta = get_bitmap_by_long_long(deg+1023);
	//cout << exponenta.size() << endl;
	//cout << "exponenta:" << endl;
	//print(exponenta);
	vector<int> result={_sign};
	result.insert(result.end(), 11-exponenta.size(), 0);
	result.insert(result.end(),exponenta.begin(),exponenta.end());
	result.insert(result.end(),mantissa_bm.begin(),mantissa_bm.end());
	//cout << "size of mantiss1010a: : " << mantissa_bm.size() << endl;
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
	vector<int> result(32-bitmap.size());
	result[0] = sign(number);
	//cout << exponenta.size() << endl;
	result.insert(result.begin()+(32-bitmap.size()),bitmap.begin(),bitmap.end());
	//result.insert(result.end(),exponenta.begin(),exponenta.end());
	return result;
}


void print(vector<int> v, unsigned int number){ 
	int cnt{};
	for (vector<int>::const_iterator byte = v.begin(); byte!=v.end(); ++byte){
		cnt++;
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

void print(vector<int> v, short number){ 
	int cnt{};
	for (vector<int>::const_iterator byte = v.begin(); byte!=v.end(); ++byte){
		cnt++;
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
				if (cnt<10 && cnt>0)
					cout << EMPH(GREEN(+to_string(*byte)+));
				else
					cout << GREEN(+to_string(*byte)+);
			}
			else
				if (cnt<10 && cnt>0)
					cout << EMPH(+to_string(*byte)+);
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
				if (cnt<13 && cnt>0)
					cout << EMPH(GREEN(+to_string(*byte)+));
				else
					cout << GREEN(+to_string(*byte)+);
			}
			else
				if (cnt<13 && cnt>0)
					cout << EMPH(+to_string(*byte)+);
				else
					cout << (*byte);
		//cout << endl << byte-v.begin() << endl;
		if (cnt%4==0)
			cout << ' ';
	}
	cout << endl;
}

unsigned int get_uint_by_bitmap(vector<int> bitmap){
	unsigned int number{};
	int deg{0};
	for (auto byte = bitmap.rbegin(); byte!=bitmap.rend(); ++byte){
		number+=(*byte)*pow(2,deg);
	 	deg++;
	 }
	 return number;
}
int get_int_by_bitmap(vector<int> bitmap){
	int number{};
	int deg{0};
	for (auto byte = bitmap.rbegin(); byte!=--bitmap.rend(); ++byte){
		number+=(*byte)*pow(2,deg);
	 	deg++;
	 }
	 return bitmap[0]?number-pow(2,31):number;

}
short get_short_by_bitmap(vector<int> bitmap){
	short number{};
	int deg{0};
	for (auto byte = bitmap.rbegin(); byte!=bitmap.rend(); ++byte){
		number+=(*byte)*pow(2,deg);
	 	deg++;
	 }
	 return bitmap[0]?number-pow(2,15):number;
}
float get_float_by_bitmap(vector<int> bitmap){
	vector<int> mantissa_bm{};
	mantissa_bm.insert(mantissa_bm.begin(), bitmap.begin()+9, bitmap.end());
	vector<int> exponenta_bm{};
	exponenta_bm.insert(exponenta_bm.begin(), ++bitmap.begin(), bitmap.begin()+9);
	print(exponenta_bm, 1);
	//cout << exponenta_bm.size() << " " << mantissa_bm.size() << endl;
	//reverse(exponenta_bm.begin(),exponenta_bm.end());
	int exponenta = get_uint_by_bitmap(exponenta_bm)-127;
	double mantissa{1};
	int deg{-1};
	for (auto byte = mantissa_bm.begin(); byte!=mantissa_bm.end(); ++byte){
		mantissa+=(*byte)*pow(2,deg);
	 	deg--;
	 	//cout << mantissa << " " << *byte << " m" << endl;
	}
	//cout << mantissa << " " << exponenta << endl;
	double number = bitmap[0]?-mantissa*pow(2, exponenta):mantissa*pow(2, exponenta);
	return number;
}
double get_double_by_bitmap(vector<int> bitmap){
	vector<int> mantissa_bm{};
	mantissa_bm.insert(mantissa_bm.begin(), bitmap.begin()+12, bitmap.end());
	vector<int> exponenta_bm{};
	exponenta_bm.insert(exponenta_bm.begin(), ++bitmap.begin(), bitmap.begin()+12);
	print(exponenta_bm, 1);
	//cout << exponenta_bm.size() << " " << mantissa_bm.size() << endl;
	//reverse(exponenta_bm.begin(),exponenta_bm.end());
	int exponenta = get_uint_by_bitmap(exponenta_bm)-1023;
	double mantissa{1};
	int deg{-1};
	for (auto byte = mantissa_bm.begin(); byte!=mantissa_bm.end(); ++byte){
		mantissa+=(*byte)*pow(2,deg);
	 	deg--;
	 	//cout << mantissa << " " << *byte << " m" << endl;
	}
	//cout << mantissa << " " << exponenta << endl;
	double number = bitmap[0]?-mantissa*pow(2, exponenta):mantissa*pow(2, exponenta);
	return number;
}