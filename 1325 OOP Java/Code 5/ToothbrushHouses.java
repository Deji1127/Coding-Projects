/* Ahmed Ibrahim
    1001820005
*/
package code5_1001820005;
import java.util.HashMap;
public class ToothbrushHouses extends House
{
    ToothbrushHouses(String houseName, HashMap<String, Integer> CandyList)
    {
        super(houseName,CandyList);
    }
    
    @Override
    public synchronized String ringDoorbell(TrickOrTreater TOT)
    {
        TOT.addToPath("-");
        
        try
        {
            Thread.sleep(3000);
        }
        catch (InterruptedException e)
        {
            Thread.currentThread().interrupt();
        }
        
        return "Toothbrush";
    }
}