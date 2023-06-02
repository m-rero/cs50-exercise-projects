from cs50 import get_int 
import sys


while True:
    try:
        height = get_int("Height: ")
        if (height <= 8) and (height >= 0):
            break
    except:
            continue
        
    
spaces= 1
for x in range(height):
    for i in range(height - spaces):
        print(" ", end="")
    for i in range(height-(height-spaces)):
        print("#", end="")
    print(" ", end="")
    
    for i in range(height-(height-spaces)):
        print("#", end="")

    print()
    spaces += 1
       
spaces= 1

