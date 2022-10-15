class exam{
    public static void main(String args[]){
        try{
            throw 1;
        }
        catch(int e){
            System.out.println("Got the exception "+e);
        }
    }
}