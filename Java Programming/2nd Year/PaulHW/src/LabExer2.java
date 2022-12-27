import java.util.*;

public class LabExer2 {
        
        String itemName;
        double itemPrice;
        int itemQuantity;
        double amountDue;
        
        public void setItemName(String itemName)
        {
            this.itemName = itemName;
        }
        public void setitemPrice(double itemPrice)
        {
            this.itemPrice = itemPrice;
        }
        public void setitemQuantity(int itemQuantity)
        {
            this.itemQuantity = itemQuantity;
        }
        public void setamountDue(double amountDue)
        {
            this.amountDue = amountDue;
        }

        public String getitemName()
        {
            return itemName;
        }
        public double getitemPrice()
        {
            return itemPrice;
        }
        public int getitemQuantity()
        {
            return itemQuantity;
        }
        public double getamountDue()
        {
            return amountDue;
        }
        
        public static void main(String[] args){
        
            String itemName;
            double itemPrice;
            int itemQuantity;
            double amountDue;
            
            Scanner s = new Scanner(System.in);
            
            System.out.println("Enter the name of the item you are purchasing.");
            itemName = s.nextLine();
            System.out.println("Enter the quantity and price seperated by space.");
            itemQuantity = s.nextInt();
            itemPrice = s.nextDouble();
            s.close();
            
            amountDue = itemQuantity * itemPrice;

            System.out.println("You are purchasing " + itemQuantity + " " + itemName + "(s) at " + itemPrice + " each.");
            System.out.println("Amount due is " + String.format("%.2f",amountDue));

        }
}
