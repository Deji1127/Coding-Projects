/* Ahmed Ibrahim
    1001820005
*/ 
package code2_1001820005;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Random;
import java.io.PrintWriter;
public class Code2_1001820005;
{
    enum ACTION 
    {
        DISPENSECHANGE, INSUFFICIENTCHANGE, INSUFFICIENTFUNDS, EXACTPAYMENT
    }
    
    public static void ReadFile(int change_inventory[], String filename, ArrayList<String> colors) throws FileNotFoundException
    {
		File infile = new File(filename);//reads in the file
        Scanner inFileRead = null;
        
        try
        {
            inFileRead = new Scanner(infile);
        }
        catch(Exception e)
        {
            System.out.println("File did not open...exiting");
            System.exit(0);
        }
        
        String FileLine = inFileRead.nextLine();//stores in the contents of the first line into a string
        String myArray[] = FileLine.split("[ ]");//splits the string into an array 
            
        change_inventory[0] = Integer.parseInt(myArray[0]);//puts the first int from the file as the change
        change_inventory[1] = Integer.parseInt(myArray[1]);//puts the second int from the file as the inventory*/
            
        String FileLine1 = inFileRead.nextLine();//reads colors on the second line into a string
        String colors_arraylist[] = FileLine1.split("[ ]");//splits the String into an array 
        
        for(String idk : colors_arraylist)//for loop to add the colors to the array list
        {
            colors.add(idk);
        }
        inFileRead.close();//close the file
    }
    public static String displayMoney(int user_payment)//function to display change as string
    {                                                   //takes in int as payment
        String dollar = String.valueOf(user_payment/100);//calculates dollars and makes it to string
        String cents = String.valueOf(user_payment%100);//calculates cents and makes it to string
        return "$" + dollar + "." + (cents.length() == 1 ? "0" : "") + cents;
    }   //returns $xx.yy as a string (xx is dollars nd yy is cents)

    public static int PencilMenu()//funtion to handle the menu for pencil
    {
        System.out.println("\nPlease choose from the following options\n\n0. No Pencils for me today\n1. Purchase pencils");
        System.out.print("2. Check inventory level\n3. Check change level\n\nChoice : ");
        
        Scanner in = new Scanner(System.in);
        int options = -1;
        
        while(options<0 || options>3)
        {
            try 
            {
                options = in.nextInt();
            }
            catch (Exception e)
            {
                options = -1;
                in.nextLine();
            }
            System.out.println("\nInvalid menu choice. Please choose again.");
            System.out.println("\nPlease choose from the following options\n\n0. No Pencils for me today\n1. Purchase pencils");
            System.out.print("2. Check inventory level\n3. Check change level\n\nChoice : ");
        }
        return options;
    }

    public static ACTION buyPencils(int pencil_price, int user_payment, int amnt_to_buy, int change_inventory[], String change[])
    {//function that handles buying pencils. returns an enumneration that describes cases
        int cost = pencil_price*amnt_to_buy; //this is the total cost of the pencils 
        int change_needed = user_payment-cost; //amnt of change needed
        
        ACTION action = null; //enumeration that is returned

        if(user_payment>cost) //if the payment that the user entered is more than the total cost (change is needed)
        {            
            if(change_inventory[0]<change_needed) //if the change needed is more than what is available
            {
                action = ACTION.INSUFFICIENTCHANGE; //not enough change
                return action;
            }
            else if(change_inventory[0]>change_needed);//if there is enough change
            {
                change_inventory[1] = change_inventory[1]-amnt_to_buy;
                change_inventory[0] = change_inventory[0]+cost;
                change[0] = displayMoney(change_needed); //calls the diplay money 
                action = ACTION.DISPENSECHANGE;          //function and assigns the change as a string
            }
            
        }
        else if(user_payment<cost)//if the total cost of the pencils is
        {                         //more than the payment that the user entered
            action = ACTION.INSUFFICIENTFUNDS;// not enough money/broke boy :(
            return action;
        }
        else if(user_payment==cost)//if the total cost is the same as the payment user entered 
        {
            action = ACTION.EXACTPAYMENT;//no change is needed
            change_inventory[0] = change_inventory[0] + user_payment;
            change_inventory[1] = change_inventory[1] - amnt_to_buy;
        }
        return action;
    }
    
    public static String PencilColor(ArrayList<String> colors)
    {
        Scanner j = new Scanner(System.in);
        Random rn = new Random();
        
        int randomInt = rn.nextInt(colors.size()-1);
        
        return colors.get(randomInt);
    }
	public static void main(String[] args) throws FileNotFoundException
    {
        int index = args[0].lastIndexOf("=") + 1; 
        int index1 = args[1].lastIndexOf("=") + 1 ;
        String filename = args[0].substring(index);
        
        final int pencil_price = Integer.parseInt(args[1].substring(index1));
        
        int change_inventory[] = {500,100};//int array
        System.out.println("Welcome to my Pencil Machine");
        int num = -1;
        int user_payment;
        int amnt_to_buy;
        String change[] = {""};
        ACTION a;
        ArrayList<String> colors = new ArrayList<>();
        ReadFile(change_inventory, filename, colors);
        Scanner in = null;
        PrintWriter out = null;
        int inventory;
        while(num!=0)
        {
            num = PencilMenu();
            switch(num)
            {
                case 0:
                    out = new PrintWriter(filename);//open the file
                    out.printf("%d %d\n", change_inventory[0], change_inventory[1]);//change &inventory is printed to the file
                    
                    for(String it : colors)//for loop to print colors to out to the file
                    {
                        out.printf("%s ", it);
                    }
                    out.close();//closes the file
                    break;
                case 1:
                    if(change_inventory[1]==0)
                    {
                        System.out.println("\nThe pencil Dispenser is out of inventory.");
                    }
                    else
                    {
                        System.out.printf("\nA pencil costs %s", displayMoney(pencil_price));

                        System.out.printf("\nHow many pencils would you like to purchase? ");
                        in = new Scanner(System.in);
                        amnt_to_buy = in.nextInt();

                        while(amnt_to_buy>change_inventory[1] || amnt_to_buy<=0)
                        {
                            System.out.print("Cannot sell that quantity of pencils. Please reeneter quantity ");
                            amnt_to_buy = in.nextInt();
                        }
                        System.out.printf("\nYour total is %s", displayMoney(amnt_to_buy*pencil_price));

                        System.out.print("\n\nEnter your payment (in cents) ");

                        user_payment = in.nextInt();

                        a = buyPencils(pencil_price, user_payment, amnt_to_buy, change_inventory, change);
                        switch(a)
                        {
                            case DISPENSECHANGE:
                                System.out.printf("Here's your %s pencils and your change of %s\n", PencilColor(colors),change[0]);
                                break;

                            case EXACTPAYMENT:
                                System.out.printf("\nHere's your %s pencils. Thank you for exact payment\n", PencilColor(colors));
                                break;

                            case INSUFFICIENTCHANGE:
                                System.out.println("\nThis Dispenser does not have enough change and cannot accept your payment");  
                                break;      

                            case INSUFFICIENTFUNDS: 
                                System.out.println("\nYou did not enter a sufficient payment. No Pencils for you");
                                break;
                                
                            default: 
                                System.out.println("\nPlease enter a valid option");
                                break;
                        }
                    }
                    break;
                case 2:
                    inventory = change_inventory[1];
                    System.out.printf("\nThe current inventory level is %d\n",inventory);
                    break;

                case 3:
                    System.out.printf("\nThe current change level is %s\n", displayMoney(change_inventory[0]));
                    break;
                    
                default:
                    System.out.println("\nInvalid menu option\n");
                    break;
            }
        }
	}
}