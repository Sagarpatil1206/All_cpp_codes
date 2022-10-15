import java.util.Scanner;
abstract class Diagram 
{
    public double length,breadth,area,base,height;
    abstract void area();
    void print_area()
    {
        System.out.println("");
        System.out.println("<<<<<<<<<<<<<<<<<<<<<<<<   Area is "+area+"sq m   >>>>>>>>>>>>>>>>>>>>>>>");
        System.out.println("");
    }
}
class rectangle extends Diagram
{
    Scanner sc = new Scanner(System.in);
    void getdata(){
        System.out.println("Enter the dimensions of rectangle-");
        System.out.println("Enter lemgth :");
        length = sc.nextDouble();
        System.out.println("Enter breadth :");
        breadth = sc.nextDouble();
    }
    public void area(){
        area=length*breadth;
    }
}
class triangle extends Diagram
{
    Scanner sc = new Scanner(System.in);
    void getdatat(){
        System.out.println("Enter the dimensions of rectangle-");
        System.out.println("Enter base :");
        base = sc.nextDouble();
        System.out.println("Enter height :");
        height = sc.nextDouble();
    }
    public void area(){
        area=base*height*0.5;
    }
}

class Areas {
    public static void main(String args [])
    {
        while(true){
            Scanner sc = new Scanner(System.in);    
            int n;
            System.out.println("<<<<<<<<<<<<<<<<<<<<<<<<  O  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
            System.out.println("1- area of rectangle \n2-calculate area of Triangle");
            n=sc.nextInt();
            switch (n) {
                case 1:
                    System.out.println("");
                    System.out.println("RECTANGLE AREA   ------->  \n ");
                    rectangle rec=new rectangle();
                    rec.getdata();
                    rec.area();
                    rec.print_area();
                    break;
                case 2:
                    System.out.println("");
                    System.out.println("RECTANGLE AREA   ------->  \n ");
                    triangle tri=new triangle();
                    tri.getdatat();
                    tri.area();
                    tri.print_area();
                    break;
                default:
                System.out.println("<<<<<<<<<<<<<<<<<<<<<<<<<<    PROGRAM ENDED   >>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                System.out.println("\n");
                sc.close();
                break;
            }
    }
}
}