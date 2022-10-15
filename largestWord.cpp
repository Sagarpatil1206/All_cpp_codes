#include<iostream>
using namespace std;
int main(){
    int n;
    ci>>n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr,n);

    int i=0;
    int currLen=0;
    int maxLen=0;
    int st=0,maxst=0;//if first word is longest st=maxst=0
    while(1){
        if(arr[i]==' ' || arr[i]=='\0'){
            if(maxLen<currLen){
                maxLen=currLen;
                maxst=st;//current st as maxst and finally maxst will be starting index of longest word
            } 
            currLen=0;//reset to zero after space
            st=i+1;//starting index of new word as i is of space thats why i+1
        }
        else
         currLen++;//only when if condition do not strikes
        if(arr[i]=='\0'){//break when sentence ends
            break;
        }
        i++;
    }
    cout<<"The Max Length is "<<maxLen<<endl;
    for(int i=0;i<maxLen;i++){//i<maxLen as how many letters are there
        cout<<arr[maxst+i];//maxst=max word ka starting point
    }
    }
