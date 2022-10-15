#include<iostream>
using namespace std;
int main(){
    int n,s;
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0,j=0,st=0,en=0,sum=0;//i and j are startig and ending index and st and en are declared
    //just to add one at the end as ans should be in 1 indexing as given
    while(j<n && sum+arr[j]<=s){//we check upto sum is lower or equal
        sum=sum+arr[j];//updating the sum
        j++;//increament
    }
    if(sum==s){//ans condition
      cout<<i+1<<" "<<j<<endl;//as i is 0 and j is increase by 1 from previous loop
      return 0;
    }
    while(j<n){//if ans conditon isn't satisfies
        sum=sum+arr[j];//adding last elemnent rejected from previous loop
        while(sum>s){//loop for moving i
            sum=sum-arr[i];
            i++;
        }//as its get lower we are now out of above loop
        if(sum==s){//first confition i.e. its eqaul to ans
            st=i+1;
            en=j+1;
            break;
        }
        j++;//2nd condition i.e. if sum<s then we increase j and add its value 
        //if sum>s then again while loop or ==s condition or increasing or stillits <s then j++ 
        //in this way we traverse through all pairs of elements with t.c. O(n).
    }
    cout<<st<<" "<<en<<endl;
}