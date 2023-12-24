#include <iostream>

using namespace std;
 int Last_digit_CNIC=4;
 int hexagon_length=Last_digit_CNIC;
 int square_length=Last_digit_CNIC+1;


 int calcArea()
 {
   return 1.5*1.732*hexagon_length;
 }
 int calcPeri()
 {
   return 6*hexagon_length;
 }
 int calcAngleSum()
 {
   return 6*120;
 }
 int calcAreaSquare()
 {
   return square_length*square_length;
 }
 int calcPeriSquare()
 {
   return 4*square_length;
 }
 void display(int c)
 {
   if(c==1)
    {
        cout<<"\nArea of hexagon is:"<<calcArea();
        cout<<"\nPerimeter of hexagon is:"<<calcPeri();
        cout<<"\nSum of angles of hexagon is:"<<calcAngleSum();
    }
   if(c==2)
    {
        cout<<"\nArea of Square is:"<<calcAreaSquare();
        cout<<"\nPerimeter of Square is:"<<calcPeriSquare();
    }
 }
int main()
{
while(true){
    int choice;
    cout<<"\nPress 1 to display area, perimeter and sum of all the angles of hexagon.";
    cout<<"\nPress 2 to display the area and perimeter of the square.";
    cout<<"\nPress any key to exit\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
           display(choice);
           break;
        case 2:
           display(choice);
           break;
        default:
          exit(0);
    }
   }
return 0;
}
