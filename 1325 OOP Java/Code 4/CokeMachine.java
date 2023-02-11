/* Ahmed Ibrahim
    1001820005
*/
package Code4_1001820005;
public class CokeMachine
{
    private String machineName;
    private int changeLevel;
    private int maxChangeCapacity = 5000;
    private int inventoryLevel;
    private int maxInventoryCapacity = 100;
    private int CokePrice;
    private int changeDispensed;
    private static int numberofCokesSold = 0;
    
    enum ACTION 
    {
        DISPENSECHANGE, INSUFFICIENTCHANGE, INSUFFICIENTFUNDS, EXACTPAYMENT, NOINVENTORY
    }

    public CokeMachine(String Name, int cost, int change, int inventory)
    {
        machineName = Name;
        CokePrice = cost;
        changeLevel = change;
        inventoryLevel = inventory;
    }
    
    public void setMachineName(String newMachineName)
    {
        machineName = newMachineName;
    }
    
    public void setCokePrice(int newCokePrice)
    {
        CokePrice = newCokePrice;
    }
    
    public CokeMachine()
    {
        machineName = "New Machine";
        CokePrice = 50;
        changeLevel = 500;
        inventoryLevel = 100;
    }
    
    public String getMachineName()
    {
        return machineName;
    }
    
    public int getChangeLevel()
    {
        return changeLevel;
    }
    
    public int getMaxChangeCapacity()
    {
        return maxChangeCapacity;
    }
    
    public int getInventoryLevel()
    {
        return inventoryLevel;
    }
    
    public int getMaxInventory()
    {
        return maxInventoryCapacity;
    }
    
    public int getCokePrice()
    {
        return CokePrice;
    }
    
    public int getChangeDispensed()
    {
        return changeDispensed;
    }
    
    public static int getNumberOfCokesSold()
    {
        return numberofCokesSold;
    }
    
    public boolean incrementInventoryLevel(int amountToAdd)
    {
        if(inventoryLevel+amountToAdd>maxInventoryCapacity)
        {
            return false;
        }
        else
        {
            inventoryLevel = inventoryLevel+amountToAdd;
            return true;
        }
    }
    
    public boolean incrementChangeLevel(int amountToAdd)
    {
        if(changeLevel+amountToAdd>maxChangeCapacity)
        {
            return false;
        }
        else
        {
            changeLevel = changeLevel+amountToAdd;
            return true;
        }
    }
    
    public ACTION buyACoke(int payment)
    {
        ACTION action = null;
        int change_needed = payment-CokePrice;
        
        if(inventoryLevel<0 || changeLevel>=maxChangeCapacity)
        {
            action = ACTION.NOINVENTORY;
            return action;
        }

        else if(payment>CokePrice)
        {
            if(changeLevel<change_needed)
            {
                action = ACTION.INSUFFICIENTCHANGE; 
                return action;
            }
            
            else if(changeLevel>change_needed)
            {
                inventoryLevel--;
                changeDispensed = change_needed;
                changeLevel += payment-change_needed;
                numberofCokesSold++;
                action = ACTION.DISPENSECHANGE;
            }
        }
        else if(payment<CokePrice)
        {
            action = ACTION.INSUFFICIENTFUNDS;
            return action;  
        }
        else if(payment==CokePrice)
        {
            numberofCokesSold++;
            changeLevel += payment;
            inventoryLevel--;
            action = ACTION.EXACTPAYMENT;
        }
        return action;
    }
    
    public String toString()
    {
        return String.format("\nMachine Name\t\t" + machineName + "\nCurrent Inventory Level\t" +
        inventoryLevel + "\nCurrent Change Level\t" + changeLevel + "\nLast Change Dispensed\t" +
        changeDispensed + "\nInventory Capacity\t" + maxInventoryCapacity + "\nChange Capacity\t\t" +
        maxChangeCapacity + "\nCoke Price\t\t" + CokePrice  + "\nCokes Sold\t\t" + numberofCokesSold);
    }
}