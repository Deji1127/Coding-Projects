/* Ahmed Ibrahim
    1001820005
*/
package code5_1001820005;
import java.util.ArrayList;
import java.util.Random;
import java.util.HashMap;
public class TrickOrTreater implements Runnable
{
    public static int ImDone;
    private String name;
    private String path = ".";
    private ArrayList<House> ListOfHouses = new ArrayList<>();
    private HashMap<String, Integer> Bucket = new HashMap<>();
    
    TrickOrTreater(String name, ArrayList<House> ListOfHouses)
    {
        this.name = name;
        this.ListOfHouses = ListOfHouses;
    }
    public String getName()
    {
        return name;
    }
    public String getPath()
    {
        return path;
    }
    public void addToPath(String concate)
    {
        path += concate;
    }
    private void Walk(int speed)
    {
        for(int i = 0; i<10; i++)
        {
            path = path + ".";
            try
            {
                Thread.sleep(speed);
            }
            catch (InterruptedException e)
            {
                Thread.currentThread().interrupt();
            }
        }
    }
    public String printBucket()
    {
        String Candy;
        String BucketContents;
        int CandyCount = 0;
        
        BucketContents = String.format("%-10s - ", name);
        
        for(HashMap.Entry mapElement : Bucket.entrySet())
        {
            Candy = (String)mapElement.getKey();
            CandyCount = (int)mapElement.getValue();
            BucketContents += String.format("%15s %d ", Candy, CandyCount);
        }
        BucketContents += "\n";
        return BucketContents;
    }
    @Override
    public void run()
    {
        int speed = 0;
        int count = 0;
        String Candy;
        Random rn = new Random();
        for(House it: ListOfHouses)
        {
            speed = rn.nextInt(1501)+1;
            Walk(speed);
            Candy = it.ringDoorbell(this);
            if(Bucket.containsKey(Candy))
            {
                count = Bucket.get(Candy);
                Bucket.put(Candy, ++count);
            }
            else
            {
                Bucket.put(Candy, 1);                
            }
        }
        synchronized(this)
        { 
            ImDone++;
        }
    }
}


