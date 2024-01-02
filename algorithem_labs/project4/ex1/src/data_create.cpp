#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
int main(void)
{
    fstream f;
    f.open("..\\input\\input.txt",ios::out);
    srand(time(NULL));
    
    //首先生成模式串P1 P2 P3，长度分别为20、30、50
    //字符集只包含26个英文字母，ASCII码值范围为97-122，对随机数mod26+97
    for(int i = 0;i < 3;i++)
    {
        int k;
        switch (i)
        {
            case(0):
                k = 20;
                break;
            case(1):
                k = 30;
                break;
            case(2):
                k = 50;
                break;
            default:
                break;
        }
        for(int j = 0;j < k;j++)
        {
            f << (char)((rand() % 26) + 97);
        }
        f << '\n';
    }

    //生成文本串，长度分别为200，400，...，2000一共10组样本
    for(int i = 0;i < 10;i++)
    {
        for(int j = 0;j < 200 * (i + 1);j++)
        {
            f << (char)((rand() % 26) + 97);
        }
        f << '\n';
    }
    f.close();
    return 0;
}