#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
#define num 400

class MyString
{
private:
    

public:
    char *p;
    int len;
    //三个重载构造函数
    MyString();
    MyString(const char* str);
    MyString(const MyString &str);
    ~MyString();

    //重载运算符
    friend MyString operator+ (const MyString &str);
    friend bool operator == (const MyString &str1,const MyString &str2);
    friend bool operator != (const MyString &str1,const MyString &str2);
    friend bool operator < (const MyString &str1, const MyString &str2);
    friend bool operator > (const MyString &str1, const MyString &str2);
    char & operator [] (int index);
    friend ostream & operator << (ostream &out, const MyString &str);
};

//默认函数构造，初始化为空字串
MyString::MyString()
{
    len = 0;
    p = new char[len + 1];
    p[0] = '\0';
}

//构造函数用一个字符串初始化
MyString::MyString(const char *str)
{
    len = strlen(str);
    p = new char[len + 1];
    strcpy(p, str);     //strcpy_s(p, len, str);?   为什么用不了？
}

//拷贝构造函数，用另一个string初始化
MyString::MyString(const MyString &str)
{
    len = str.len;
    p = new char[strlen(str.p) + 1];
    strcpy(p, str.p);
}

//析构函数
MyString::~MyString()
{
    delete[] p;
}

//重载符的运算操作（+）
MyString operator + (const MyString &str1, const MyString str2)
{
    MyString str;
    delete[] str.p;
    str.len = str1.len + str2.len;
    str.p = new char[str.len + 1];
    strcpy(str.p,str1.p);           // strcpy_s(str.p, str.len + 1,str1.p);   
    strcpy(str.p,str2.p);           // strcpy_s(str.p,str.len + 1,str2.p);               
                                    
    return str;
}

//重载符的运算操作（==）
bool operator ==(const MyString &str1, const MyString &str2)
{
    if(strcmp(str1.p, str2.p) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//重载的运算符（！=）

bool operator !=(const MyString &str1, const MyString &str2)
{
    if(strcmp(str1.p, str2.p) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//重载的运算符（<）
bool operator < (const MyString &str1, const MyString &str2)
{
    if(strlen(str1.p) < strlen(str2.p))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator > (const MyString &str1, const MyString &str2)
{
    if(strlen(str1.p) > strlen(str2.p))
    {
        return true;
    }
    else
    {
        return false;
    }
}

char & MyString ::operator[](int index)
{
    return p[index];
}

ostream & operator << (ostream &out, const MyString & str)
{
    out << str.p;
    return out;
}

int main(void)
{
    MyString str1("hjkl;");        
    MyString str2("ertyu");
    MyString str;
    str = str1 + str2;
    cout << str1.p << endl;    
    cout << str2.p << endl;
    cout << str.p << endl;

    str1 ==str2;   //怎么调用？
    str1 < str2;
    str1 > str2;
    str1 != str2;
    
     
}