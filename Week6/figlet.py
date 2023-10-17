#import sys module for argv and exit, and random module for choice
import sys
import random

#get figlet module
from pyfiglet import Figlet
figlet = Figlet()

#list of fonts
fonts = figlet.getFonts()
#get argc
argc = len(sys.argv)

#if argc is not acceptable
if argc != 1 and argc != 3:
    print("Invalid usage")
    sys.exit(1)
#no CLA, random font selection
elif argc == 1:
    text = input("Input: ").strip()
    figlet.setFont(font=random.choice(fonts))
    print(figlet.renderText(text))
#correct CLA, check if format is right
elif argc == 3:
    if (sys.argv[1] != '-f' and sys.argv[1] != '--font') or sys.argv[2] not in fonts:
        print("Invalid usage")
        sys.exit(1)
    else:
        text = input("Input: ").strip()
        figlet.setFont(font=sys.argv[2])
        print(figlet.renderText(text))
