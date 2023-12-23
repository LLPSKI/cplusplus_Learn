#include<iostream>
using namespace std;

int main(void)
{
    double arr[] = {-15,0,0,0,25};
    for(int i = 0;i < 50;i++)
    {
        for(int j = 1;j <= 3;j++)
        {
            double temp1 = (0.8 * (-5 + arr[j+1])) + (0.2 * (-5 + arr[j-1]));
            double temp2 = (0.8 * (-5 + arr[j-1])) + (0.2 * (-5 + arr[j+1]));
            if(temp2 > temp1)
            {
                cout<<"left";
                arr[j] = temp2;
            }
            else 
            {
                cout<<"right";
                arr[j] = temp1;
            }
            cout<<' ';
        }
        cout<<arr[1]<<' '<<arr[2]<<' '<<arr[3]<<'\n';
    }
    return 0;
}