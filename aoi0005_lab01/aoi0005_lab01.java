/*ahmed ibrahim 
1001820005
java version "18.0.2.1" 2022-08-18
Windows
*/
import java.io.File; //import to get info abt the file

public class aoi0005_lab01 {
    public static int dirSpace(File directory) 
    {
        int localSum = 0; //holds the total sum of the size of the files
        File[] file = directory.listFiles(); //array that holds all files within a directory
        for (File it : file) //iterator to iterate through all the files
        {
            if (it.getName().equals(".") || it.getName().equals("..")) 
            {
                continue;
            }
            if (it.isFile()) // if it's a file
            {
                localSum += it.length(); //get the size of file and add it to the rest
            } 
            if (it.isDirectory()) //if it's a directory
            {
                localSum += dirSpace(it); //recursively call the function
            }
        }
        return localSum;
    }

    public static void main(String[] args) {
        File targetDir = new File("."); // gets current directory
        System.out.print(dirSpace(targetDir)); // print out size in bytes
    }
}