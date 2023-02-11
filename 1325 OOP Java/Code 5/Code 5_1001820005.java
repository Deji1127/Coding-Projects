/* Ahmed Ibrahim
    1001820005
*/
package code5_1001820005;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Random;
import java.util.HashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
public class Code5_1001820005
{
    public static void CreateCandyList(String filename, HashMap<String,Integer>map) throws FileNotFoundException
    {
        File infile = new File(filename);//reads in the file
        Scanner inFileRead = null;
        int count = 0;
        String word = null;
        
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
            word = inFileRead.nextLine();//stores in the contents of the first line into a string
            String myArray[] = word.split("[|]");//splits the string into an array
            word = myArray[0].toLowerCase();
            /*if(map.containsKey(word))
            {
                count = map.get(word);
                map.put(word, ++count);
            }
            else
            {*/
                map.put(word, Integer.parseInt(myArray[1]));
            //}
        }
        
        inFileRead.close();//close the file
    }
    public static String CreateHouses(String filename1, ArrayList<House> Houses, HashMap<String, Integer> map) throws FileNotFoundException
    {
        String HouseHeading = "          ";
        File infile = new File(filename1);//reads in the file
        Scanner inFileRead = null;
        String hn = " ";
        Random rn = new Random();
        try
        {
            inFileRead = new Scanner(infile);
        }
        catch(Exception e)
        {
            System.out.printf("%s file does not exist...exiting\n", filename1);
            System.exit(0);
        }
        
        while(inFileRead.hasNextLine())
        {
            hn = inFileRead.nextLine();
            HouseHeading = HouseHeading + hn;
            
            for(int i = 0; i<11-hn.length(); i++)
            {
                HouseHeading += " ";
            }
            
            int randomInt = rn.nextInt(2);
            
            if(randomInt==0)
            {
                Houses.add(new CandyHouse(hn, map));
            }
            else
            {
                Houses.add(new ToothbrushHouses(hn, map));
            }
        }
        inFileRead.close();
        HouseHeading += "\n\n";
        return HouseHeading;
    }
    
    public static void CreateTOTs(String filename2, ArrayList<TrickOrTreater> Name, ArrayList<House> Houses) throws FileNotFoundException
    {
        File infile = new File(filename2);//reads in the file
        Scanner inFileRead = null;
        String word = " ";
        try
        {
            inFileRead = new Scanner(infile);
        }
        catch(Exception e)
        {
            System.out.printf("%s file does not exist...exiting\n", filename2);
            System.exit(0);
        }
        while(inFileRead.hasNextLine())
        {
            word = inFileRead.nextLine();
            Name.add(new TrickOrTreater(word, Houses));
        }
        inFileRead.close();
    }
	public static void main(String[] args) throws FileNotFoundException
	{
	    String filename;
	    String filename1;
	    String filename2;
	    if(args.length!=3)
		{
		    System.out.println("Missing command line parameters");
		    System.exit(0);
		}
        filename = args[0].substring(args[0].lastIndexOf("=") + 1);
        filename1 = args[1].substring(args[1].lastIndexOf("=") + 1);
        filename2 = args[2].substring(args[2].lastIndexOf("=") + 1);
		
		HashMap<String, Integer> myMap = new HashMap<>();
		
		ArrayList<House> Houses = new ArrayList<>();
		ArrayList<TrickOrTreater> Name = new ArrayList<>();
		

		CreateCandyList(filename, myMap);
		String HouseHeading = CreateHouses(filename1, Houses, myMap);
        
		CreateTOTs(filename2, Name, Houses);

		ExecutorService executorService = Executors.newCachedThreadPool();
		for(TrickOrTreater it: Name)
		{
		    executorService.execute(it);
		}
		
		TextAreaFrame TAF = new TextAreaFrame();

		TAF.setVisible(true);
		
		while(TrickOrTreater.ImDone != Name.size())
		{
            String ScreenOutput = String.format("%s", HouseHeading);
            
            for(TrickOrTreater it: Name)
            {
                ScreenOutput += String.format("%s%s\n", it.getPath(), it.getName());
            }
            TAF.textArea.setText(ScreenOutput);
		}
		executorService.shutdown();
		String BucketContents = "Candy!!" + "\n\n";
		for(TrickOrTreater it: Name)
		{
            BucketContents += it.printBucket();
		}
		TAF.textArea.setText(BucketContents);
	}
}
