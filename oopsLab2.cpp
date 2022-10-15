class compare{
    public static void main(String args[])
    {
        int num1,num2,sum;
        num1=10;
        num2=20;
        sum=num1+num2;
        System.out.println("The Result is : "+sum);
        if(num1>num2){
            System.out.println(num1+" is greater than "+num2);
        }else if(num1<num2){
            System.out.println(num2+" is greater than "+num1);
        }else{
            System.out.println(num1+" is equal to "+num2);
        }
    }
}