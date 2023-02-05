/* Ahmed Ibrahim
    1001820005
*/
package code5_1001820005;
import java.util.Random;
import java.util.HashMap;
public class CandyHouse extends House
{
    CandyHouse(String houseName, HashMap<String, Integer> CandyList)
    {            
        super(houseName,CandyList);
    }
    
    @Override
    public synchronized String ringDoorbell(TrickOrTreater TOT)
    {
        String Candy = null;
        TOT.addToPath("+");
        
        try
        {
            Thread.sleep(3000);
        }
        catch (InterruptedException e)
        {
            Thread.currentThread().interrupt();
        }
        
        Random rn = new Random();
        int rndm = rn.nextInt(CandyList.size()-1)+1;
        
        for(HashMap.Entry mapElement : CandyList.entrySet())
        {
            if((int)mapElement.getValue()==rndm)
            {
                Candy = (String)mapElement.getKey();
            }
        }
        return Candy;
    }
}