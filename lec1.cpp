#include<iostream>
using namespace std;
class Rectangle {
    public:
    double height;
    double width;
};
int main(){
    Rectangle rectangleObj;
    double area;
    rectangleObj.height=10.0;
    rectangleObj.width=20.0;
    area=rectangleObj.height*rectangleObj.width;
    cout<<area;
}  