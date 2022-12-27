/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Perimeter and Area of a Polygon
* IDE: VSCode
*/

import javax.swing.*;

public class Activity1_Polygon{
    
    static Float area, perimeter;   
    static String in;               //Temporary var for measurement of shapes                    

    public static void main(String[] args) {
        Menu();
    } //Main method

    /**Menu */
    public static void Menu(){
        char exit = 'N', polygon;   //exit menu, choice, repeat main menu
        int repeat;                 //repeat program once exit is clicked
        String SPoly;               //String to convert to char   

        try{
            while(exit == 'N'){
                /** User input */
                SPoly = JOptionPane.showInputDialog(null, "[S] Square\n[R] Rectangle\n[T] Triangle\n[E] Exit\n\nEnter polygon to compute:", "Polygon Calculator", JOptionPane.QUESTION_MESSAGE);
                
                if(SPoly != null){  //Ok is clicked

                    //Empty text field
                    if(SPoly.isEmpty()){
                        JOptionPane.showMessageDialog(null, "Cannot accept blank text fields!", "Error", JOptionPane.WARNING_MESSAGE);
                        Menu();
                    }

                    SPoly = SPoly.toUpperCase(); polygon = SPoly.charAt(0); //Turns choice to uppercase and changes to char
                    switch (polygon) {
                        case 'S': Square(); break;              
                        case 'R': Rectangle(); break;          
                        case 'T': Triangle(); break;
                        case 'E': repeat = JOptionPane.showConfirmDialog(null, "Are you sure you want to exit the application?", "Warning", JOptionPane.YES_NO_OPTION);
                                    if(repeat == JOptionPane.YES_OPTION) {
                                        exit = 'Y';
                                    }
                                    break;
                        default: JOptionPane.showMessageDialog(null, "Error! Invalid Input!", "Error", JOptionPane.ERROR_MESSAGE);
                                    repeat = JOptionPane.showConfirmDialog(null, "Do you want to try again?", "Error", JOptionPane.YES_NO_OPTION);
                                    if(repeat == JOptionPane.NO_OPTION) {
                                        exit = 'Y';
                                    }
                                    break;
                    }
                }else exit = 'Y';   //Cancel button
            }
            JOptionPane.showMessageDialog(null, "Have a great day!", "Exit", JOptionPane.PLAIN_MESSAGE);    //Exit message
        }catch (StringIndexOutOfBoundsException e){
            exit = 'Y'; //Catch errors and close program
        }
    } //Method Menu

    /**Area and Perimeter of a Square*/
    public static void Square(){
        //User input
        in = JOptionPane.showInputDialog(null, "Enter side:", "Square", JOptionPane.QUESTION_MESSAGE);

        try{
            if(in != null){
                float side = Float.parseFloat(in);
                
                //Formula
                area = side * side;
                perimeter = 4 * side;

                //Output
                JOptionPane.showMessageDialog(null, "Area: " + String.format("%.2f", area) + "\nPerimeter: " + String.format("%.2f", perimeter), "Square", JOptionPane.INFORMATION_MESSAGE);
            }
        }catch (NumberFormatException e) {   //catch blank or non-integer text fields
            JOptionPane.showMessageDialog(null, "Cannot accept blank/non-integer values!", "Error", JOptionPane.WARNING_MESSAGE);
        }
    } //Method Square

    /**Area and Perimeter of a Rectangle*/
    public static void Rectangle(){
        float length = 0, width = 0;

        try{
            //User input
            in = JOptionPane.showInputDialog(null, "Enter length of rectangle: ", "Rectangle", JOptionPane.QUESTION_MESSAGE);
            
            if(in != null){
                length = Float.parseFloat(in);
                in = JOptionPane.showInputDialog(null, "Enter width of rectangle: ", "Rectangle", JOptionPane.QUESTION_MESSAGE);
            
                if(in != null){ 
                    width = Float.parseFloat(in);

                    //Formula
                    area = length * width;
                    perimeter = (2 * length) + (2 * width);

                    //Output
                    JOptionPane.showMessageDialog(null, "Area: " + String.format("%.2f", area) + "\nPerimeter: " + String.format("%.2f", perimeter), "Rectangle", JOptionPane.INFORMATION_MESSAGE);
                }
            }
        }catch (NumberFormatException e) {   //catch blank or non-integer text fields
            JOptionPane.showMessageDialog(null, "Cannot accept blank/non-integer values!", "Error", JOptionPane.WARNING_MESSAGE);
        }
    } //Method Rectangle

    /**Area and Perimeter of a Triangle*/
    public static void Triangle(){
        float side1 = 0, side2 = 0, side3 = 0;
        
        try{
            //User input
            in = JOptionPane.showInputDialog(null, "Enter side 1 or base: ", "Triangle", JOptionPane.QUESTION_MESSAGE);
            
            if(in != null){
                side1 = Float.parseFloat(in);
                in = JOptionPane.showInputDialog(null, "Enter side 2 or height: ", "Triangle", JOptionPane.QUESTION_MESSAGE);
            
                if(in != null){
                    side2 = Float.parseFloat(in);
                    in = JOptionPane.showInputDialog(null, "Enter side 3: ", "Triangle", JOptionPane.QUESTION_MESSAGE);
            
                    if(in != null){
                        side3 = Float.parseFloat(in);

                        //Formula
                        area = 0.5f*(side1 * side2);
                        perimeter = side1 + side2 + side3;

                        //Output
                        JOptionPane.showMessageDialog(null, "Area: " + String.format("%.2f", area) + "\nPerimeter: " + String.format("%.2f", perimeter), "Triangle", JOptionPane.INFORMATION_MESSAGE);  
                    }
                }
            }
        }catch (NumberFormatException e) {   //catch blank or non-integer text fields
            JOptionPane.showMessageDialog(null, "Cannot accept blank/non-integer values!", "Error", JOptionPane.WARNING_MESSAGE);
        }
    } //method Triangle

} //class Polygon