#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;
vector<int> sumno1(vector<int>data,vector<int>data2,bool negative1,bool negative2,bool& negative3);
vector<int> correction(vector<int>data1);
vector<int> diff(vector<int>data,vector<int>data2,bool negative1,bool negative2,bool& negative3);

class BigDecimalInt
{
private:
    bool negative=false;
    vector<int>data;
public:
BigDecimalInt(int input);
BigDecimalInt(string input);
friend ostream& operator<<(ostream& out,BigDecimalInt number);
BigDecimalInt operator=(BigDecimalInt number);
BigDecimalInt operator+(BigDecimalInt number);
BigDecimalInt operator-(BigDecimalInt number);
};
#endif // BIGDECIMALINT_H
