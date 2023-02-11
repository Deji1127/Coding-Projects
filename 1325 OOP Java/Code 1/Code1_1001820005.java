/* Ahmed Ibrahim
    1001820005
*/
package code1_1001820005;
import java.util.Scanner;
public class Code1_1001820005
{
    enum ACTION 
    {
        DISPENSECHANGE, INSUFFICIENTCHANGE, INSUFFICIENTFUNDS, EXACTPAYMENT
    }

    public static String displayMoney(int user_payment)//function to display change as string
    {                                                   //takes in int as payment
        String dollar = String.valueOf(user_payment/100);//calculates dollars and makes it to string
        String cents = String.valueOf(user_payment%100);//calculates cents and makes it to string
        return "$" + dollar + (cents.length() == 1 ? "0" : ".") + cents;
    }   //returns $xx.yy as a string (xx is dollars nd yy is cents)

    public static int PencilMenu() //funtion to handle the menu for pencil
    {
        System.out.println("\nPlease choose from the following options\n\n0. No Pencils for me today\n1. Purchase pencils");
        System.out.print("2. Check inventory level\n3. Check change level\n\nChoice : ");

        Scanner in = new Scanner(System.in);
        int options = in.nextInt();
        while(options<0 || options>3)
        {
            System.out.println("\nPlease choose from the following options\n\n0. No Pencils for me today\n1. Purchase pencils");
            System.out.print("2. Check inventory level\n3. Check change level\n\nChoice : ");
            options = in.nextInt();
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
            if(change_inventory[1]<change_needed) //if the change needed is more than what is available
            {
                action = ACTION.INSUFFICIENTCHANGE; //not enough change
                return action;
            }
            else if(change_inventory[1]>change_needed);//if there is enough change
            {
                change_inventory[0] = change_inventory[0] - amnt_to_buy;
                change_inventory[1] = change_inventory[1] - change_needed;
                change[0] = displayMoney(change_needed); //calls the diplay money function and assigns the change as a string
                action = ACTION.DISPENSECHANGE;          
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
            change_inventory[1] = change_inventory[1] + user_payment;
            change_inventory[0] = change_inventory[0] - amnt_to_buy;
        }
        return action;
    }

	public static void main(String[] args) 
    {
        final int pencil_price = 60; 
        int change_inventory[] = {100,500};//int array
        System.out.println("Welcome to my Pencil Machine");
        int num = -1;
        int user_payment;
        int amnt_to_buy;
        String change[] = {""};
        ACTION a;
        int inventory;
        while(num!=0)
        {
            num = PencilMenu();
            switch(num)
            {
                case 0:
                    break;
                case 1:
                    if(change_inventory[0]==0)
                    {
                        System.out.println("\nThe pencil Dispenser is out of inventory.");
                    }
                    else
                    {
                        System.out.printf("\nA pencil costs %s", displayMoney(pencil_price));

                        System.out.printf("\nHow many pencils would you like to purchase? ");
                        Scanner in1 = new Scanner(System.in);
                        amnt_to_buy = in1.nextInt();

                        while(amnt_to_buy>change_inventory[0] || amnt_to_buy<=0)
                        {
                            System.out.print("Cannot sell that quantity of pencils. Please reeneter quantity ");
                            Scanner inn = new Scanner(System.in);
                            amnt_to_buy = inn.nextInt();
                        }
                        System.out.printf("\nYour total is %s", displayMoney(amnt_to_buy*pencil_price));

                        System.out.print("\n\nEnter your payment (in cents) ");

                        Scanner in2 = new Scanner(System.in);
                        user_payment = in2.nextInt();

                        a = buyPencils(pencil_price, user_payment, amnt_to_buy, change_inventory, change);
                        switch(a)
                        {
                            case DISPENSECHANGE:
                                change_inventory[0] = change_inventory[0]-amnt_to_buy;
                                System.out.printf("Here's your pencils and your change of %s\n", change[0]);
                                break;

                            case EXACTPAYMENT:
                                System.out.println("\nHere's your pencils. Thank you for exact payment");
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
                    inventory = change_inventory[0];
                    System.out.printf("\nThe current inventory level is %d\n",inventory);
                    break;

                case 3:
                    System.out.printf("\nThe current change level is %s\n",displayMoney(change_inventory[1]));
                    break;
                    
                default:
                    System.out.println("\nInvalid menu option\n");
                    break;
            }
        }
	}
}