#include"BigDecimalInt.h"
vector<int> sumno1(vector<int>data,vector<int>data2,bool negative1,bool negative2,bool& negative3);
vector<int> correction(vector<int>data1);
vector<int> diff(vector<int>data,vector<int>data2,bool negative1,bool negative2,bool& negative3);
int main()
{
BigDecimalInt num1("123456789012345678901234567890");
BigDecimalInt num2("113456789011345678901134567890");
BigDecimalInt num3 = num2 + num1;
BigDecimalInt num4 = num2 - num1;
cout << "num1 = " << num1 << endl;
cout << "num2 = " << num2 << endl;
//236913578023691357802369135780
cout << "num2 + num1 = " << num3 << endl;
//10000000001000000000100000000
cout << "num2 - num1 = " << num4 << endl;
BigDecimalInt num5("333333333333333333333333333333");
BigDecimalInt num6("-111111111111111111111111111111");
BigDecimalInt num7 = num5 + num6;
BigDecimalInt num8 = num5 - num6;
//222222222222222222222222222222
cout << "num5 + num6 = " << num7 << endl;
//444444444444444444444444444444
cout << "num5 - num6 = " << num8 << endl;
}
vector<int> diff(vector<int>data,vector<int>data2,bool negative1,bool negative2,bool& negative3)
{
 vector<int>data1(4,5);
        int counter;
        if(data.size()>data2.size())
        {
        counter=data.size()-data2.size();
        for(int i=0;i<counter;i++)
            data2.insert(data2.begin(),0);
        }
        else if(data.size()<data2.size())
            {
            counter=data2.size()-data.size();
            for(int i=0;i<counter;i++)
                data.insert(data.begin(),0);
            }
        data1.resize(data2.size());
        if((negative1==false)&&(negative2==false))
        {
        for(int i=0;i<data.size();i++)
            data1[i]=data[i]-data2[i];
        negative3=true;
        }
        else if((negative2==true)&&(negative1==false))
            {
            transform(data.begin(), data.end(), data2.begin(), data1.begin(), std::plus<int>());
            negative3=true;
            }
        else if((negative2==false)&&(negative1==true))
            {
            transform(data.begin(), data.end(), data2.begin(), data1.begin(), std::plus<int>());
            negative3=false;
            }
        else if((negative1==true)&&(negative2==true))
            {
            for(int i=0;i<data.size();i++)
            data1[i]=data[i]-data2[i];
            negative3=false;
            }
            return data1;
}
vector<int> sumno1(vector<int>data,vector<int>data2,bool negative1,bool negative2,bool& negative3)//1>2 1-2, 2-1
{
 vector<int>data1(4,5);
        int counter;
        if(data.size()>data2.size())
        {
        counter=data.size()-data2.size();
        for(int i=0;i<counter;i++)
            data2.insert(data2.begin(),0);
        }
        else if(data.size()<data2.size())
            {
            counter=data2.size()-data.size();
            for(int i=0;i<counter;i++)
                data.insert(data.begin(),0);
            }
        data1.resize(data2.size());
        if((negative1==false)&&(negative2==false))
            {
            transform(data.begin(), data.end(), data2.begin(), data1.begin(), std::plus<int>());
            negative3=false;
            }
        else if((negative2==true)&&(negative1==false))
        {
         for(int i=0;i<data.size();i++)
            data1[i]=data[i]-data2[i];

        negative3=false;
        }
        else if((negative2==false)&&(negative1==true))
        {

         for(int i=0;i<data.size();i++)
            data1[i]=data[i]-data2[i];
        negative3=true;
        }
        else if((negative1==true)&&(negative2==true))
            {
            transform(data.begin(), data.end(), data2.begin(), data1.begin(), std::plus<int>());
            negative3=true;
            }
    return data1;
}

vector<int> correction(vector<int>data1)
{

 for(int i=1;i<data1.size();i++)
    {
    if(data1[data1.size()-i]>=10)
        {
        data1[data1.size()-i]-=10;
        data1[data1.size()-i-1]++;
        }
     else if(data1[data1.size()-i]<0)
        {
        data1[data1.size()-i]+=10;
        data1[data1.size()-i-1]--;
        }
    }
 if(data1[0]>=10)
    {
    data1[0]-=10;
    data1.insert(data1.begin(),1);
    }
 if(data1[0]==0)
    {
    data1.erase(data1.begin(),data1.begin()+1);
    }
return data1;
}
