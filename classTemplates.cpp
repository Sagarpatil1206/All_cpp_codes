#include<iostream>
using namespace std;

template <class T>
class Pair{//class must have a name start with a captital letter
    private:
        T first, second;
    public: 
    Pair(T a,T b):first(a),second(b){ }//pair constructor to  initializze the variables
            T bigger(); //declaring the member function inside the class
};

template<class T>//whatever function follows this is under the template
T Pair<T>::bigger(){//class having return type T and having parameter T defining outside the class therfore:: is used
          return (first>second ? first:second);
}
int main(){
  Pair<double> obj(5.68,23.43);//here we have to specify the data type in angle brackets for instantination
  cout<<obj.bigger()<<endl;
  Pair<int> obj1(12,15);
  cout<<obj1.bigger();
  return 0;

}