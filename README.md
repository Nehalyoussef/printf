Main idea :
the printf function produces printed data to the standard output in a special format. 
it's prototype is int _printf(const char *format, ...);
--------------------------------------------------------
Return value :
if this function is executed successfully it will return the quantity of characters printed according to your requirement , in case you faced an error during execution , the return value will be -1.
--------------------------------------------------------
Format of the argument string :
let's break down the format of argument string used in printf function into 
1) fixed characters: they are ragular characters like letters , numbers, symbols that aren't preceded by a % symbol.
--------------------------------
2)conversion specifications :it starts with % and then ends with a character that tells the printf function what to do with the following provided argument.
---------------------------------
3)flags: between % and the specifier you can have some flags like +- , space flag and #flag that we are going to discuss later.
---------------------------------
4)width: you can determine a specific width for the output.
---------------------------------
5)precision:this is used with floating-point numbers to control the number of decimal places.
---------------------------------
6)length modifier:this is optional if you want to determine the size of data type you are working with.
---------------------------------
7)conversion specifiers:this is a mandatory part that tells the printf function how to interpret the argumentfor example %f is for float numbers and so on.
----------------------------------
8)order of arguments:The function call's parameters must be given in the same order as the conversion specifiers. As a result, the first parameter matches the first% in the format string, the second argument matches the second%, and so on.
----------------------------------------------------------
let's dive deep into conversion specifiers:
1) d,i : interpreted into signed decimal integers.

for example:
------------------------
int main(void)
{
    _printf("%d\n", 5);
}
output:
5
-----------------------------------------------------
2) b: it is transformed to binary representation.

for example:
-----------------------
int main(void)
{
    _printf("%b\n", 5);
}
output:
101
-----------------------------------------------------
3) o, u, x, X: o prints octal number, u prints unsigned integer,x prints hexadecimal in lowercase,X prints hexadecimal in upper case.

for example:
-----------------------
int main(void)
{
    _printf("%o\n", 21);
}
output:25
------------------------------------------------------
4) c: prints a character.

for example: 
-----------------------
int main(void)
{
    _printf("%c\n", 38);
}
output:0
------------------------------------------------------
5) s: prints a string.

for example:
------------------------
int main(void)
{
    _printf("%s\n", "Hello everyone");
}
output:Hello everyone
------------------------------------------------------
6) r: deals with strings only but prints them in a reverse order.

for example:
------------------------
int main(void)
{
    _printf("%r\n", "Hello everyone");
}
output:enoyreve olleH
-------------------------------------------------------
7) R:prints string in rot13

we have the alphabet  [A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z] (it is like counting 13 character from the letter you want to encode by rot13)

for example:
----------------------
int main(void)
{
    _printf("%R\n", "Hello everyone");
}

let's apply rot13 encoding to Hello everyone

H becomes U

e becomes r

l becomes y

l becomes y

o becomes b

(space) remains

e becomes r

v becomes i

e becomes r

r becomes e

y becomes l

o becomes b

n becomes a

e becomes r

output:Uryyb rirelbar
----------------------------------------------------------
8) p:used to output the memory address of a pointer where the address is presented in hexadecimal format so it is preceded by 0x to indicate it is in hexadecimal format.

for example:
-------------------------
int main(void)
{
    _printf("%p\n", "Hello everyone");
}
output:
0x561a6d7bab5d (address depending on your memory system)
-------------------------------------------------------------
9)%: to print percision but not as a conversion specifier.

for example:
-------------------------
int main(void)
{
    _printf("%%\n");
}
output:
%
-------------------------------------------------------------
finally: flag specifier :
1)'+' flag: when you use a positive flag with %d or %f , it forces the result to be preceded with a plus sign (+) for positive numbers.
If the number is positive, it will have a plus sign in front of it.
If the number is negative, it will still have a minus sign in front of it.(the positive flag has no effect on negative numbers)
for example:

int pos_num = 15;
printf("%+d\n", num); // Prints "+15"

int neg_num = -10;
printf("%+d\n", negNum); // Prints "-10"
-------------------------------------------------------------

2) the (space) flag: When you use the (space) flag with a numeric format specifier, it inserts a blank space before the value for positive numbers when no sign is going to be written.
It's often used to ensure that positive numbers align properly with negative numbers when they have different lengths.
for example:

int pos_num = 15;
printf("% d\n", num); // Prints " 10" with a leading space for positive numbers

int neg_num = -10;
printf("% d\n", negNum); // Prints "-10" without a space for negative numbers.(the space flag has no effect on negative numbers)
--------------------------------------------------------------
3) # flag:
The behavior of the # flag depends on the format specifier used:
1) With 'o','x', or 'X' specifiers: It forces the value to be preceded with 0, 0x, or 0X, respectively, for values different than zero.
2) With 'e', 'E', and 'f' specifiers: It forces the written output to contain a decimal point (.) even if no digits would follow. By default, if no digits follow, no decimal point is written.
3) With 'g' or 'G' specifiers: The result is the same as with e or E, but trailing zeros are not removed.
for example:

int value = 32;
printf("%#o\n", value); // Prints "040" with a leading "0" for non-zero octal values

int hexValue = 250;
printf("%#x\n", hexValue); // Prints "0xFA" for non-zero hexadecimal values

double floatValue = 124.0;
printf("%#f\n", floatValue); // Prints "124.000000" with trailing zeros

float smallValue = 1.24;
printf("%#.3g\n", smallValue); // Prints "1.24" with three significant digits 
(The %#.3g format specifier specifies that the number should be printed with a minimum of three significant digits. Since smallValue has three significant digits (1.24), there are no trailing zeros to display, and the output is correctly "1.24.")
---------------------------------------------------------------
