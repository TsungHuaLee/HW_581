//similar to cycle length after decimal point
#include<iostream>
using namespace std;

int main()
{
    int numCell,numSituation;
    while(cin>>numCell>>numSituation)
    {
        if(numCell == 0 && numSituation == 0)
            break;
        int cell[10100] = {};
        for(int i = 0; i < numCell; i++)
            cin>>cell[i];
        while(numSituation--)
        {
            int position, head;
            cin>>position>>head;
            int book[2][10100] = {},step = 1; //book store each position's step and head.
            if(head > 0)
                book[0][position] = step;
            else
                book[1][position] = step;
            while(1)
            {
                step++;
                int nextStep= cell[position] * head;
                position += nextStep;
                if(position > numCell - 1)
                {
                    cout<<"Forward"<<endl;
                    break;
                }
                if(position < 0)
                {
                    cout<<"Beckforward"<<endl;
                    break;
                }
                if(nextStep > 0)
                {
                    head = 1;
                    if(book[0][position])
                    {
                        cout<<"Cycle "<<step - book[0][position]<<endl;
                        break;
                    }
                    else
                        book[0][position] = step;
                }
                else
                {
                    head = -1;
                    if(book[1][position])
                    {
                        cout<<"Cycle "<<step - book[1][position]<<endl;
                        break;
                    }
                    else
                        book[1][position] = step;
                }
            }
        }
    }

}
