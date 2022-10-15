#include<iostream>
using namespace std;
template <class T>
class pair{
    private:
        T first, second;
    public: 
    pair(T a,T b):first(a),second(b){ }//pair constructor to  initializze the variables
            T bigger(); //declaring the member function inside the class
};
template<class T>//whatever function follows this is under the template
T pair<T>::bigger(){//class having return type T and having parameter T defining outside the class therfore:: is used
    return (first > second ? first:second);
}
int main(){
  pair<double> obj(23.43,5.68);
  cout<<obj.bigger();
  return 0;
}