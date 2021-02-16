from sys import argv
import sys


def main():
    while True:
        if len(argv)==2 :
            break
        else:
            print("Usage: python bleep.py dictionary")
            sys.exit(1)
            break
        
    print("What message would you like to censor?")
    text=input()  
    
    f=open(argv[1],"r")
    mySet=set()
    
    #adding all curse words to a set
    for line in f:
        mySet.add(line[:-1])
        
    text=text.split()
    final=""
    #loop through every word user typed and if one of them is curse word(doesn'nt matter upper or lower)
    #prints '*' as length of that word indtead of the word, prints the original oe otherwise
    for i in range(len(text)):
        if text[i].lower() in mySet:
           text[i]="*" * len(text[i])
           final+=text[i]+" "
        else:
           final+=text[i] + " "
    print(final)       
    f.close()
if __name__ == "__main__":
    main()
