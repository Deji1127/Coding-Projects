#Ahmed Ibrahim
#1001820005
#Windows
#Python 3.9.5
import os #import to access info abt OS 
def dirSpace(Directory): #function to get size of all files in directory
    localSum = 0
    for files in os.listdir(Directory): #loops through all the files
        file = os.path.join(Directory, files) 
        if file == "." or file == "..":
            continue
        if os.path.isfile(file): #if it's a file
            localSum += os.path.getsize(file) #get it's size
        if os.path.isdir(file): #if it's a directory
            localSum += dirSpace(file) #recursively call the function to get the size of all files in a directory
    return localSum
targetDir = "."
print(dirSpace(targetDir))