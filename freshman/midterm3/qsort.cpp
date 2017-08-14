#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int *data, int left, int right)
{
    int pivot, i, j;

    if (left >= right)
    {
        return;
    }

    pivot = data[left];

    i = left + 1;
    j = right;

    while (1)
    {
        while (i <= right)
        {
            if (data[i] > pivot)
            {
                break;
            }

            i = i + 1;
        }

        while (j > left)
        {
            if (data[j] < pivot)
            {
                break;
            }

            j = j - 1;
        }

        if (i > j)
        {
            break;
        }

        swap(&data[i], &data[j]);
    }

    swap(&data[left], &data[j]);

    quicksort(data, left, j - 1);
    quicksort(data, j + 1, right);
}
int main(void)
{
    char line[10000]={};
    fstream fin;
    fin.open("input.txt",ios::in);
    while(fin.getline(line,sizeof(line),'\n'))
    {
        istringstream input(line);

        int number,data[10000]= {};
        input>>number;
        for (int i = 0; i < number; i++)
            input>>data[i];

        quicksort(data, 0, number - 1);  //quicksort

        cout<<"ans: ";
        for (int i = 0; i < number; i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    fin.close();
    system("pause");
    return 0;
}
