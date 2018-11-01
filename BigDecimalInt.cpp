#include "BigDecimalInt.h"


BigDecimalInt::BigDecimalInt(int input)
{
 vector<int>data2;
 negative=input>0?false:true;
 while(input!=0)
    {
     data.push_back(input%10);
    input/=10;
    }
 for(int i=0;i<data.size();i++)
    {
    data2[data.size()-1-i]=data[i];
    }
    data=data2;
}
BigDecimalInt::BigDecimalInt(string input)
    {
     int counter;
     string temp="";
     int realnum;
        counter=input[0]=='-'?1:0;
        negative=input[0]=='-'?true:false;
     while(counter!=input.length())
        {
        temp=input[counter];
        stringstream convert(temp);
        convert>>realnum;
        this->data.push_back(realnum);
        counter++;
        }
    }
ostream& operator<<(ostream& out,BigDecimalInt number)
    {
    if(number.negative==true)
        out<<'-';
    for(int i=0;i<number.data.size();i++)
        out<<number.data[i]<<" ";
    return out;
    }
BigDecimalInt BigDecimalInt:: operator=(BigDecimalInt number)
    {
    this->data.resize(number.data.size());
    for(int i=0;i<number.data.size();i++)
        {
        this->data[i]=number.data[i];
        }
        return *this;
    }
BigDecimalInt BigDecimalInt:: operator+(BigDecimalInt number)
{
 BigDecimalInt result("55");
 if(number.data.size()>data.size())
    {
    result.data=correction(sumno1(number.data,data,number.negative,negative,result.negative));
    }
 else if(number.data.size()<data.size())
    {
    result.data=correction(sumno1(data,number.data,negative,number.negative,result.negative));
    }
 else
    {
     int index=0;
     while(true)
         {
         if(data[index]>number.data[index]){
             result.data=correction(sumno1(data,number.data,negative,number.negative,result.negative));
             break;
             }
         else if(data[index]<number.data[index]){
             result.data=correction(sumno1(number.data,data,number.negative,negative,result.negative));
             break;
             }
         index++;
        }
    }
return result;
}

BigDecimalInt BigDecimalInt:: operator-(BigDecimalInt number)
{
number.negative=!number.negative;
BigDecimalInt result("55");
 if(number.data.size()>data.size())
    {
    result.data=correction(sumno1(number.data,data,number.negative,negative,result.negative));
    }
 else if(number.data.size()<data.size())
    {
    result.data=correction(sumno1(data,number.data,negative,number.negative,result.negative));
    }
 else
    {
     int index=0;
     while(true)
         {
         if(data[index]>number.data[index]){
             result.data=correction(sumno1(data,number.data,negative,number.negative,result.negative));
             break;
             }
         else if(data[index]<number.data[index]){
             result.data=correction(sumno1(number.data,data,number.negative,negative,result.negative));
             break;
             }
         else{index++;}
        }
    }
return result;
}
