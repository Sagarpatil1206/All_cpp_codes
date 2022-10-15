public Shape getShape {
    public shape getShape(string shapeType){
    if(shapeType == null){
        return null;
    }
    if(shapeType.equalsIgnoreCase("Circle")){
        return new Circle();
    }
    if(shapeType.equalsIgnoreCase("Rectangle")){
        return new Circle();
    }
    if(shapeType.equalsIgnoreCase("Square")){
        return new Circle();
    }
    return null;
    } 
}
