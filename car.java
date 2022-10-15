public abstract class car{
    public car(Car_Type model){
        this.model=model;
        arrangeParts();
    }

    private void arrangeParts(){
        System.out.println("Arranging parts....")
    }

    protected abstract void construct();

    private Car_Type model=null;

    public carType getModel(){
        return model;
    }

    public void setModel(carType model){
        this.model=model;
    }
}
