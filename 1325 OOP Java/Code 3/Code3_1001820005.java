/* 
Ahmed Ibrahim 1001820005
*/ 
package code3_1001820005;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Random;
import java.io.PrintWriter;
public class Code3_1001820005
{
    enum ACTION 
    {
        DISPENSECHANGE, INSUFFICIENTCHANGE, INSUFFICIENTFUNDS, EXACTPAYMENT, NOINVENTORY
    }
    
    public static int CokeMenu(String machine_name)
    {
        System.out.printf("\n%s\n\n\n0.   Walk away\n1.   Buy a Coke\n2.   Restock Machine\n3.   Add change\n4.   Display Machine Info\n", machine_name);
        System.out.print("\nChoice? ");
        Scanner in = new Scanner(System.in);
        int options = -1;
        
        while(options<0 || options>4)
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
            if(options>4 || options<0)
            {
                System.out.println("\nInvalid menu choice. Please choose again.");
                System.out.printf("\n\n%s\n\n\n0.   Walk away\n1.   Buy a Coke\n2.   Restock Machine\n3.   Add change\n4.   Display Machine Info\n", machine_name);
                System.out.print("\nChoice? ");
            }
        }
        return options;
    }

    public static String displayMoney(int user_payment)//function to display change as string
    {                                           
        String dollar = String.valueOf(user_payment/100);//calculates dollars and makes it to string
        String cents = String.valueOf(user_payment%100);//calculates cents and makes it to string
        return "$" + dollar + "." + (cents.length() == 1 ? "0" : "") + cents;
    }   //returns $xx.yy as a string (xx is dollars nd yy is cents)
    
	public static void main(String[] args) throws FileNotFoundException
	{
		CokeMachine MyCokeMachine = new CokeMachine("CSE 1325 Coke Machine", 50, 500, 100);

		int options = -1;
		
		int user_payment;
		
		Scanner in = new Scanner(System.in);
		
		int product_to_add;
		int change_to_add;
		
		while(options!=0)
		{
		    options = CokeMenu(MyCokeMachine.getMachineName());
		    
		    switch(options)
            {
                case 0:
                    
                    if(MyCokeMachine.getNumberOfCokesSold()==0)
                    {
                        System.out.println("\n\nAre you sure you aren't really THIRSTY and need a coke?");
                    }
                    else
                    {
                        System.out.println("\n\nBye - enjoy you're Coke");
                    }
                    break;
                case 1:
                    System.out.printf("A Coke costs %s\n", displayMoney(MyCokeMachine.getCokePrice()));
                    System.out.printf("\nInsert payment ");
                    
                    user_payment = in.nextInt();
    
                    switch(MyCokeMachine.buyACoke(user_payment))
                    {
                        case DISPENSECHANGE:
                            
                            System.out.printf("\n\nHere's your Coke and your change of %s\n\n\n", displayMoney(MyCokeMachine.getChangeDispensed()));
                            break;
                            
                        case INSUFFICIENTCHANGE:
                            
                            System.out.println("Insufficent change...return your payment");
                            break;
                            
                        case INSUFFICIENTFUNDS:
                            
                            System.out.println("\n\nInsufficient payment...returning your payment\n");  
                            break;
                            
                        case EXACTPAYMENT:
                            
                            System.out.println("\n\nThank you for exact payment.\nHere's your Coke\n");
                            break;
                            
                        case NOINVENTORY:
                            
                            System.out.println("\n\nUnable to sell a Coke - call 1800WEDONTCARE to register a complaint...returning your payment.\n\n");
                            break;
                    }
                    
                    break;
                case 2:
                    
                    System.out.print("\n\nHow much product are you adding to the machine? ");
                    product_to_add = in.nextInt();
                    
                    if(MyCokeMachine.incrementInventoryLevel(product_to_add)==false)
                    {
                        System.out.println("\n\nYou have exceeded your machine's max capacity - no inventory was added\n");
                        System.out.printf("Your inventory is %d\n\n", MyCokeMachine.getInventoryLevel());
                    }
                    else
                    {
                        System.out.println("\n\nYour machine has been restocked\n");
                        System.out.printf("Your inventory is %d\n\n", MyCokeMachine.getInventoryLevel());
                    }
                    
                    break;
                case 3:
                    System.out.print("How much change are you adding to the machine? ");
                    change_to_add = in.nextInt();

                    if(MyCokeMachine.incrementChangeLevel(change_to_add)==false)
                    {
                        System.out.println("\n\nYou exceed your machine's max change capacity - no change added");
                        System.out.printf("\n\nYour change level is %s with a max capacity of %s\n\n", displayMoney(MyCokeMachine.getChangeLevel()), displayMoney(MyCokeMachine.getMaxChangeCapacity()));
                    }
                    else
                    {
                       System.out.println("\n\nYour change level has been updated\n"); 
                       System.out.printf("\n\nYour change level is %s with a max capacity of %s\n\n", displayMoney(MyCokeMachine.getChangeLevel()), displayMoney(MyCokeMachine.getMaxChangeCapacity()));
                    }
                    
                    break;
                case 4: 
                    System.out.println(MyCokeMachine);
                    break;
            }
		}
	}
}
