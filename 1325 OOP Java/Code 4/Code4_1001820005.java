/* Ahmed Ibrahim
    1001820005
*/ 
package code4_1001820005;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Random;
import java.io.PrintWriter;
public class Code4_1001820005
{
    enum ACTION 
    {
        DISPENSECHANGE, INSUFFICIENTCHANGE, INSUFFICIENTFUNDS, EXACTPAYMENT, NOINVENTORY
    }
    
    public static int CokeMenu(String machine_name)
    {
        System.out.printf("\n\n%s\n\n\n0.   Walk away\n1.   Buy a Coke\n2.   Restock Machine\n3.   Add change\n4.   Display Machine Info\n5.   Update Machine Name\n6.   Update Coke price", machine_name);
        System.out.print("\n\nChoice? ");
        Scanner in = new Scanner(System.in);
        int options = -1;
        
        while(options<0 || options>6)
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
            if(options>6 || options<0)
            {
                System.out.println("\nInvalid menu choice. Please choose again.");
                System.out.printf("\n%s\n\n\n0.   Walk away\n1.   Buy a Coke\n2.   Restock Machine\n3.   Add change\n4.   Display Machine Info\n5.   Update Machine Name\n6.   Update Coke price", machine_name);
                System.out.print("\nChoice? ");
            }
        }
        return options;
    }
    public static int Machine_Menu(ArrayList<CokeMachine> SetOfCokeMachines)
    { 
        int i;
        int options = -1;
        CokeMachine bum = null;
        System.out.println("Pick a Coke Machine\n\n\n0. Exit");
        for(i = 0; i<SetOfCokeMachines.size(); i++)
        {
            bum = SetOfCokeMachines.get(i);
            System.out.printf("%d. %s\n", i+1, SetOfCokeMachines.get(i).getMachineName());
        }
        System.out.printf("%d. Add new machine\n\nChoice? ", SetOfCokeMachines.size()+1);
        
        Scanner in = new Scanner(System.in);
        
        while(options<0 || options>SetOfCokeMachines.size()+1)
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
            if(options>SetOfCokeMachines.size()+1 || options<0)
            {
                System.out.println("\nInvalid menu choice. Please choose again.");
                System.out.println("0. Exit");
                for(i = 0; i<SetOfCokeMachines.size(); i++)
                {
                    System.out.printf("%d. %s\n", i+1, SetOfCokeMachines.get(i).getMachineName());
                }
                System.out.printf("%d. Add new machine\n\nChoice? ", SetOfCokeMachines.size()+1);
            }
        }
        return options;
    }
    public static void ReadFile(String filename, ArrayList<CokeMachine> SetOfCokeMachines) throws FileNotFoundException
    {
		File infile = new File(filename);//reads in the file
        Scanner inFileRead = null;
        
        try
        {
            inFileRead = new Scanner(infile);
        }
        catch(Exception e)
        {
            System.out.printf("%s file does not exist...exiting\n", filename);
            System.exit(0);
        }
        
        while(inFileRead.hasNextLine())
        {
            String FileLine = inFileRead.nextLine();//stores in the contents of the first line into a string
            String myArray[] = FileLine.split("\\|");//splits the string into an array
            SetOfCokeMachines.add(new CokeMachine(myArray[0], Integer.parseInt(myArray[1]), Integer.parseInt(myArray[2]), Integer.parseInt(myArray[3])));
        }
        
        inFileRead.close();//close the file
    }
    
    public static void Output(String filename1, ArrayList<CokeMachine> SetOfCokeMachines)throws FileNotFoundException
    {
        PrintWriter out = null;

        try
        {
            out = new PrintWriter(filename1);//reads in the file    
        }
        catch(FileNotFoundException e)
        {
            System.out.printf("Unable to write output file\n%s", e.getMessage());
            System.exit(0);
        }
        for(CokeMachine it: SetOfCokeMachines)
        {
            out.printf("%s|%d|%d|%d\n", it.getMachineName(), it.getCokePrice(), it.getChangeLevel(), it.getInventoryLevel());
        }
        out.close();
    }
    
    public static String displayMoney(int user_payment)//function to display change as string
    {                                           
        String dollar = String.valueOf(user_payment/100);//calculates dollars and makes it to string
        String cents = String.valueOf(user_payment%100);//calculates cents and makes it to string
        return "$" + dollar + "." + (cents.length() == 1 ? "0" : "") + cents;
    }   //returns $xx.yy as a string (xx is dollars nd yy is cents)
    
	public static void main(String[] args) throws FileNotFoundException
	{
		CokeMachine MyCokeMachine = null;

		int options = -1;
		int user_payment;
		
		Scanner in = new Scanner(System.in);
		
		int product_to_add;
		int change_to_add;
		
		String newMachineName;
		int newCokePrice;

		String filename;
		String filename1;
		ArrayList<CokeMachine> SetOfCokeMachines = new ArrayList<>();

        /*filename = args[0].substring(args[0].lastIndexOf("=") + 1);
        filename1 = args[1].substring(args[1].lastIndexOf("=") + 1);*/
		if(args.length!=2)
		{
		    System.out.println("Missing command line parameters – - Usage : INPUTFILENAME= OUTPUTFILENAME=");
		    System.exit(0);
		}
		else if(args.length==2)
		{
		    filename = args[0].substring(args[0].lastIndexOf("=") + 1);
		    ReadFile(filename, SetOfCokeMachines);
		}
		filename1 = args[1].substring(args[1].lastIndexOf("=") + 1);
		int idk = -1;
		while(idk!=0)
		{
            idk = Machine_Menu(SetOfCokeMachines);
            if(idk==SetOfCokeMachines.size()+1)
            {
                MyCokeMachine = new CokeMachine();
                SetOfCokeMachines.add(MyCokeMachine);
                System.out.println("\n");
            }
            else if(idk==0)
    		{
    		    Output(filename1, SetOfCokeMachines);
    		    MyCokeMachine = SetOfCokeMachines.get(0);
                if(MyCokeMachine.getNumberOfCokesSold()==0)
                {
                    System.out.println("0 Coke(s) were sold");
                }
                else
                {
                    System.out.printf("%d Coke(s) were sold today!\n", CokeMachine.getNumberOfCokesSold());
                }
    		}
            else
            {
                MyCokeMachine = SetOfCokeMachines.get(idk-1);
                while(options!=0)
                {
                    options = CokeMenu(MyCokeMachine.getMachineName());
                    switch(options)
                    {
                        case 0:
                            if(MyCokeMachine.getNumberOfCokesSold()==0)
                            {
                                System.out.println("\n\nAre you sure you aren't really THIRSTY and need a coke?\n\n");
                            }
                            else
                            {
                                System.out.println("\n\nBye - enjoy you're Coke\n\n");
                            }
                            break;
                        case 1:
                            System.out.printf("A Coke costs %s\n", displayMoney(MyCokeMachine.getCokePrice()));
                            System.out.printf("\nInsert payment ");
                        
                            user_payment = in.nextInt();
        
                            switch(MyCokeMachine.buyACoke(user_payment))
                            {
                                case DISPENSECHANGE:
                                
                                    System.out.printf("\n\nHere's your Coke and your change of %s\n\n", displayMoney(MyCokeMachine.getChangeDispensed()));
                                    break;
                                
                                case INSUFFICIENTCHANGE:
                                
                                    System.out.println("\n\nUnable to give change at this time...return your \n");
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
                        case 5:
                            System.out.print("\n\nEnter a new machine name ");
                            newMachineName = in.nextLine();
                            MyCokeMachine.setMachineName(newMachineName);
                            System.out.println("\n\nMachine name has been updated");
                            break;
                        case 6:
                            System.out.print("\n\nUpdate Coke price ");
                            newCokePrice = in.nextInt();
                            MyCokeMachine.setCokePrice(newCokePrice);
                            System.out.println("\n\nCoke price has been updated");
                            break;
                    }
                }
                options = -1;
            }
		}
	}
}