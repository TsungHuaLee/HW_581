#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
#include<cmath>
using namespace std;
int number;
double matrix[110][110]= {},determinant;
void check(float eps)       //make sure abs(x)<0.0001
{
    for(int i=0; i<number; i++)
        for(int j=0; j<=number; j++)
            if(abs(matrix[i][j])<eps)
                matrix[i][j]=0;
}
void change(int row)
{
    int column=row;
    if(matrix[row][column]==0)
    {
        for(int i=row+1; i<number; i++)
            if(matrix[i][column]!=0)
            {
                double temp;
                for(int j=0;j<=number;j++)
                    {
                        temp=matrix[i][j];
                        matrix[i][j]=matrix[row][j];
                        matrix[row][j]=temp;
                    }
                break;
            }
    }
}
void arrange(int row)       //head by 1
{
    int divide=matrix[row][row];
    determinant*=divide;
    for(int i=0; i<=number; i++)
        matrix[row][i]/=divide;
}
void neg_to_pos(int row)    //head by 1
{
    int column=row;
    for(int i=row; i<number; i++)
    {
        if(matrix[i][column]<0)
        {
            for(int j=0; j<=number; j++)
                matrix[i][j]=abs(matrix[i][j]);
        }
    }
}
void compute(int row)
{
    int column=row;
    for(int i=row+1; i<number; i++)
    {
        int multi=matrix[i][column];
        if(multi==0)
            continue;
//        cout<<"i="<<i<<" multi="<<multi<<endl;
        int k=0;
        for(int j=row; j<=number; j++)
        {
            double temp=matrix[i][j]-multi*matrix[row][row+k];
//            cout<<"row="<<row<<" ""column="<<row+k<<" "<<matrix[i][j]<<"-"<<multi*matrix[row][row+k]<<endl;
//            cout<<matrix[i][j]-multi*matrix[row][row+k]<<" "<<temp<<endl;
            matrix[i][j]=temp;
            k++;
        }
    }
}
int deter()
{
    int judge=1;
    for(int i=0;i<number;i++)
    {
        judge*=matrix[i][i];
    }
    return judge;
}
int main()
{
    char line[10000]= {};
    float eps=0.0001;
    int times=0;
    fstream fin;
    fin.open("input.txt",ios::in);
    while(fin.getline(line,sizeof(line),'\n'))    //cin>>n
    {
        istringstream input(line);
        input>>number;
        if(number==0)
            break;

        for(int i=0; i<110; i++)            //reset
            for(int j=0; j<110; j++)
                matrix[i][j]=0;
        determinant=1;
        for(int i=0; i<=number; i++)        //cin>>matrix
        {
            fin.getline(line,sizeof(line),'\n');
            istringstream input(line);
            if(i==number)
            {
                for(int j=0; j<number; j++)
                    input>>matrix[j][i];
            }
            for(int j=0; j<number; j++)
                input>>matrix[i][j];
        }

        for(int i=0; i<number; i++)   //compute
        {
            check(eps);                 //0.0001=0
            change(i);
            neg_to_pos(i);
            if(abs(matrix[i][i])!=1&&abs(matrix[i][i])!=0)
                arrange(i);
            compute(i);
        }
        cout<<"Case "<<times<<": n="<<number<<"\n\n";
        for(int i=0; i<number; i++)
            {
                for(int j=0; j<=number; j++)
                    cout<<fixed<<setprecision(4)<<matrix[i][j]<<" ";
                cout<<endl;
            }
        if(deter())
        {
            cout<<"determinant="<<determinant<<endl;
        }
        else
            cout<<"determinant is zero"<<endl;
        cout<<"==============="<<endl;
        times++;
    }
    fin.close();
    return 0;
}
