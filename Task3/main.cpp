#include <iostream>
using namespace std;
int electricity_unit[3][3]={
        {55, 65 , 75},
        {120,150,170},
        {210,230,240}
};
void costSlab1()
{
    int unit_costSlab1=10;
    int Total_costSlab1[1][3];
    cout<<"\nBILL FOR SLAB1 IS:\n";
  for(int i=0;i<1;i++)
    for(int j=0;j<3;j++)
    {
      Total_costSlab1[i][j]=unit_costSlab1*electricity_unit[i][j];
      cout<<"\t"<<Total_costSlab1[i][j];
    }
}
void costSlab2()
{
    int unit_costSlab2=15;
    int Total_costSlab2[2][3];
    cout<<"\nBILL FOR SLAB2 IS:\n";
  for(int i=1;i<2;i++)
    for(int j=0;j<3;j++)
    {
      Total_costSlab2[i][j]=unit_costSlab2*electricity_unit[i][j];
      cout<<"\t"<<Total_costSlab2[i][j];
    }
}
void costSlab3()
{
    int unit_costSlab3=20;
    int Total_costSlab3[3][3];
    cout<<"\nBILL FOR SLAB3 IS:\n";
  for(int i=2;i<3;i++)
    for(int j=0;j<3;j++)
    {
      Total_costSlab3[i][j]=unit_costSlab3*electricity_unit[i][j];
      cout<<"\t"<<Total_costSlab3[i][j];
    }
}
int main()
{
    cout<<"======================MENU==========================";
    string Student_ID;
    cout<<"\n My Student ID is";
    cin>>Student_ID;
while(true){
    char choice;
    cout<<"\nEnter your choice";
    cout<<"\nPress 1 to display the bill of slab1 and slab2";
    cout<<"\nPress 2 to display the bill of slab3";
    cout<<"\nPress any key to exit\n";
    cin>>choice;
    switch(choice){
        case '1':
           costSlab1();
           costSlab2();
           break;
        case '2':
           costSlab3();
           break;
        default:
          exit;
          return 0;
    }
   }
}
