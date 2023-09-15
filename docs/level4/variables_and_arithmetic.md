# Variables and Arithmetic

In this task you are going to open a "Solution" from within Visual Studio and run the first project. With the help of the built in debugger you will view how the variables are created as the program runs.

| Task | Details |
| :--- | :---   |
| 1    | Open Visual Studio |
| 2    | From the list of options below "Get started", select "Open a project or solution" |
|3     | Navigate to where you cloned the "Software Engineering" repository and select "Tasks" then "01 - Variables and Arithmetic", open the file "variablesAndArithmetic.sln"|
| 4    | From the "Solution Explorer" right-click the line "101-Variables" and select "Set as Startup Project". Then use the small arrow on the left of the line to open up that project.|
| 5    | Under the section "Source Files" click on the line containing "101-Variables.cpp". The editing window should now show the code below.|
| | |

```C
#include <stdio.h>

// This is a single line comment - it does nothing

/*
   This is a block comment. 
   It also does nothing.
*/

//Entry point for your code
int main()
{ // Block opening brace

	char c = 88;				// Character
	short year = 2023;			// Short integer
	int age = 23;				// Integer
	long bigNumber = 123456789;	// Long integer
	long long veryBigNumber = 1LL << 30;	//2^30

	//Floating point numbers
	float pi_f   = 3.1415926535; //Does this work?
	double pi_df = 3.1415926535; //This one is "double precision"

	// The following are not initialised inline
	int serialNumber;			//What value is stored in here at this point?
	serialNumber = 50;


	// TASK: Use the debugger to step through the lines above. 
	//   Hover the mouse over each line to see it's value BEFORE and AFTER each line
	//   Note any discrepencies between the value in the source code and the value reported by the debugger


} // Block closing brace

```
| Task | Details |
| :--- | :---   |
| 6    | Set a 'break point', as the name suggests this is a point in the program (set by you) where the program execution will pause. To do this hover the cursor over the vertical grey bar on the far left of the edit window alongside line 14. A black disc will appear which will turn red if you click it. You have now set a break point on line 14. To remove break point simply click it.  |
| 7    | From the "Debug" menu select "Start debugging" (shortcut F5), the program will now be compiled and run in debug mode. A command window will open with the name of the program that is running in the title bar. The program has no output so all you should see is a flashing cursor in the top left corner. Minimise this window.
|8     | Look for a yellow arrow on top off your break point red disc. The arrow shows the next line the program will execute when you tell it to.|
| 9    | Below the edit window you should see section marked "Autos" and within it a greyed line with a lowercase "c" at the left edge. The column "Value" shows a decimal number and maybbe a character. The far right column "Type" shows char. All this data refers to the variable 'c' on line 14. Why do you think the value is not shown as 88 as set on line 14?|
| 10    | Now lets move the program on one line. Under the "Debug" menu select "Step Over" (shortcut F10). Where is the yellow arrow now? What value does the variable 'c' have now? What value does the variable 'year' have now? You can also see the values of the variables by hovering over them.|
| 11    | Continue to use the "Step Over" command to advance the yellow arrow one line at a time watching the variables as they change. When you go beyond the last line the program will exit. You may have noticed that some of the results are a bit strange, more on that below.|
| | |

## Variables
Lets look at the variables in a little more detail. First Integers.

| Task | Details |
| :--- | :---    |
| 1    | First you need to create a new project. From the "Solution Explorer" right click the Solution (VariablesAndArithmetic) and select "Add -> New Project". From the list on the right of the window that opens select "Console App" and then "Next". For Project Name enter IntegerFun (or similar) then "Create". The new project will appear at the bottom of the Solution Explorer window with a source file "IntegerFun.cpp". Right click on the first line of the new project "IntegerFun" and select "Set as Startup project" The file IntegerFun.cpp should now be in the edit window.|
| 2    |  The body of the function main() is between the curly braces {}, replace the code there with this:
```C++
int a, b = 8, c;
printf("a = %d , b = %d , c = %d\n", a ,b ,c);
```
Your code should now look something like this:
```C++
#include <iostream>

int main()
{
    int a, b = 8, c;
    printf("a = %d , b = %d , c = %d\n", a, b, c);
}
```
To save space all the comments have been removed, don't worry about the first line for now but the printf() function needs a little explanation - all of the text between the "" quotes will be displayed on the terminal with the exception of the %d characters. These are 'place holders' for the three variables a, b and c. The values of these variables will be printed where the place holders are. The d character after the % tells printf to expect an integer. The '\n' will insert a new line into the output.
 
| 3    | Now select "Start without debugging" from the Debug menu. In the window at the bottom of the screen (labelled "Output") you should see 2 error messages. These give detail the filename (IntegerFun.cpp) the line number (6) and the error (uninitialised local variable used). This compiler is setup to warn you that variables a and c have been defined but no values have been assigned, be aware that not all compilers will do this and will happily let you use variables that have a random value. It is good practice to always initialise variables wen they are defined. So now lets change line 5 to this:
```C++
int a = 3, b = 8, c = a * b;
```
A word of explanation here, the '*' character is the multiplication operator so the variable c is being set to the value of a multiplied by b. We can do this because a and b already have values. Now run the program and observe the output.|

| 4    | The variables a, b and c are fine and easy to type but they don't convey much about your intention as a programmer. Let's assume you are working on a program that needs to calculate the area of something. Now change lines 5 and 6 to this:
```C++
int width = 3, length = 8, area = width * length;
printf("width = %d , length = %d , area = %d\n", width, length, area);
``` 
This change doesn't affect the program functions (the compiler doesn't care what you call your variables) but it makes more sense to anyone reading the code. |

| 5    | Not all software runs on large PCs with virtually unlimited memory, you might be working on an embedded device for the next Android device for example where the memory is fixed and might be very limited. So how much space are your variables using?

Insert the following line at the end of your code:
```C++
printf("Size of a int is %zd bytes\n", sizeof(int));
```
The sizeof() function returns (in this case) how much memory (in bytes) an integer uses in this envornment. Run the program.
You should see that an integer here takes 4 bytes (32 bits). Integers variables can be signed or unsigned the maximum values as follows:
unsigned int    0 to 4294967295
signed int      -2147483648 to 2147483647 
(source https://learn.microsoft.com/en-us/cpp/cpp/integer-limits?view=msvc-170)
As the programmer it's up to you to decide which to use, in this case negative values (for the sides of  box) doesn't make sense so you would probable choose unsigned. 
|

| 6    | Now lets assume you have to save some memory there is a smaller integer variable called a short which in unsigned form has a maximum value of 65535, you checked the specification of the project and that is sufficient. Change  line 5 to this:
```C++
unsigned short width = 3, length = 8, area = width * length;
```
and add this line to the end of the code:
```C++
printf("Size of a short is %zd bytes\n", sizeof(short));
```
Run the program - it still works as before and as you can see short only uses 2 bytes. But there is a potential problem!|

| 7    |  Try changing the values of width and length to say 32000 and see what happens. What do you think has happened? The value you are now tring to store in area is too big for a short int. Change the definition of area as below and run the code again.
```C++
unsigned short width = 32000, length = 32000; 
unsigned int area = width * length;
```
You can see from this that the type of variables you use must be chosen carefully!

There are larger integers available, refer to the link above for more details.

Add the following lines to the code and run the program again.
```C++
printf("Size of a long is %zd bytes\n", sizeof(long));
printf("Size of a long long is %zd bytes\n", sizeof(long long));
```
In this environment long takes 4 bytes and long long takes 8 bytes.
|
| 8    |  |
| | |

| Task | Details |
| :--- | :---    |
| 1    |  |
| 2    |  |
| 3    |  |
| 4    |  |
| 5    |  |
| 6    |  |
| | |
| Task | Details |
| :--- | :---    |
| 1    |  |
| 2    |  |
| 3    |  |
| 4    |  |
| 5    |  |
| 6    |  |
| | |


| Task | Details |
| :--- | :---   |
| 12    | Run the program again with the breakpoint on line 15 so that the variable 'c' has been assigned a value.  Hover the cursor over the 'c' in the source code and the value should show as 88 'X'.  Under the "Debug" menu select "Stop Debugging" (shortcut Shift-F5). Now change line 14 to read: `char c = 'X'    // Character;` Run the program again. What value does 'c' have now? Try the same thing with different values for 'c' and see what happens - referring to an 'ASCII' table (online search) will help explain the results. Note - the range of values that make sense for this is 0 to 127. |
| 13    | For this task we will use the Project 2 "102-Sizeof". Right click this project and select "Set as Startup Project". Open the file sizeof.cpp. This uses printf to output values to the terminal window. To run the program select "Start without Debugging" from the "Debug" menu. The output will appear in a command window, the code on line 51 just keeps the window open until you close it.
|14     | Examine the output and compare it to what you were expecting. Can you explain why line 21 produces two different outputs for the same variable? Why does neither output for pi match the number in the source code? Why does adding 1 to the variable shortCount turn it into a negative value?|
| 15    | The final part of the program shows the size of the various variable types in this environment.|
| 10    | Now lets move the program on one line. Under the "Debug" menu select "Step Over" (shortcut F10). Where is the yellow arrow now? What value does the variable 'c' have now? What value does the variable 'year' have now? You can also see the values of the variables by hovering over them.|
| 11    | Continue to use the "Step Over" command to advance the yellow arrow one line at a time watching the variables as they change. When you go beyond the last line the program will exit. You may have noticed that some of the results are a bit strange, more on that below.|
| | |


## Writing to the Console

Without input or output, a computer cannot fulfill a useful function.

> Philosophically speaking, is a computer actually a computer if it has no input or output? Discuss<sup>**</sup> (max. 2000 words)

> **<sub>Only joking. If you ever hear me ask for an essay, assume I have been abducted by aliens and replaced with a extra-terrestrial imitation.<sub> 

So it is that we cannot begin to learn a programming language without some form of input and output.

### `puts` (put string)

### `printf` (print formatted)

### `getchar` (read a character)

## Integers

## Integer Arithmetic

## Characters

## Signed and Unsigned

## Floating Point

## Floating Point Arithmetic

## Structures

## Using `sizeof`

## Type casting

## Constants

## Pre-processor constants

## Numerical Errors

## Debugging

### Watching Variables

### Inspecting Memory

All variables are numbers stored in the  memory of a computer. Whatever **type** of data they are, they all end up stored as binary numbers (grouped together, these make integers) stored in the volatile or persistent memory of the computer.

Some development tools allow us to look inside the computer memory so we can see how the binary data is organised internally.

## The `&` operator

Now we have seen data in memory, you will note once more the two key properties of computer data:

* **address** - this is the *location* of the data in the computer memory. In C and C++, it is always an integer value

* value

### `scanf` (scan formatted)

## Challenges

## Advanced Topics

### Unions

### Bitfields

### Endienness

### Compiler warnings

