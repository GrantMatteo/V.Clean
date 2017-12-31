V.Clean V1.0 Instructions:

Remember, all commands are CASE SENSITIVE

													SETUP:

1. Unzip this folder and put it somewhere.

2. Go to your start menu (press the windows key) and open Command Line
	
	2a.type the following command: setx PATH "%PATH%;<the path to your V.Clean.exe file>" 
		For Example, if it were in Program Files, you would type setx PATH "%PATH%;C:\Program Files\"
		NOTE: DO NOT type V.Clean.exe, only the filepath to the directory it's in (you can get the filepath by right clicking the exe and going to properties)
	
	2b. Close command prompt, then reopen if you want to use V.Clean
													USE:

1. In same folder as the csv you want to read (this will be referred to as input.csv), create an output file (this will be referred to as output.csv)

2. Open Command prompt and navigate to the directory of your csv file
	TIP: Use "dir" to see a list of files and folders in your current directory and "cd" to navigate to a new one

3. Type the following command:

"V.Clean <input file name> <output file name> <a list of columns you want to keep -- it can be as long as you want>"

	Example: V.Clean input.csv output.csv 1 2 3 4 5 6 7 8 9 10 13 15 18 42 211 212



Notes:

A 0 as input will make V.Clean keep all default values.

The columns are numbered from 1 to 212. Anything else will be ignored.

The inputs are SPACE-SEPARATED, so if you need to use a space in one of them, you have to surround that input in "quotes"
	Example: "input 2.csv" "output 2.csv" 0 3 4 7 12

You can also specify a file outside your current folder by using its filepath instead of just its name