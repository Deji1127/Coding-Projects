/* Ahmed Ibrahim
    1001820005
*/
package code5_1001820005;
import java.util.HashMap;
public abstract class House
{
    private String houseName;
    HashMap<String, Integer> CandyList = new HashMap<>();
    
    House(String houseName, HashMap<String, Integer> CandyList)
    {
        this.houseName = houseName;
        this.CandyList = CandyList;
    }
    public abstract String ringDoorbell(TrickOrTreater TOT);
}