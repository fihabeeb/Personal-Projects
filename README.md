# Personal Work
This repository is dedicated to my personal programming projects that I don't think each need their own individual repos, but are notable enough to be put on my GitHub.

# Find and Rename Script

```findandrename.py``` is arguably the most interesting of my personal projects as of writing this README, so I'd like to save it for last.

# Find missing number in list efficiently
```findmissingnuminbigofN.py``` is code I wrote while doing a Codility coding practice.

The task was straight forward, Write a python file that *efficiently* finds the missing number in a list.

The input would be a random list of numbers that are unordered. When ordered, these list would essentially be ```list[N + 1] == list[N] + 1``` except for one instance where a number would be missing.

For example, the input list is ```[7,2,4,1,3,5]```. When ordered, it'd be ```[1,2,3,4,5,7]```. And the program should output ```6``` as the answer since its the number missing.

## Issues immediately encountered

When doing that project, we were yet to study Algorithms in our Computer Science course, so programming efficiently was new to me.

## Solution

I came up with the solution of sorting the array once, then looping through it once to check for the missing number.
This solution was successful in my limited testing, however Codility found errors with it.


Since I couldn't really understand what the input was, Codility didn't tell it to me outright, I haven's yet solved the issues it found.


Otherwise it works fine, although I believe it to be ```O(N ** 2)```, which isn't ideal.




# Frog Jumps

```frogjumps.py``` was the Codility practice right after the one above. Since I solved it very well, and in ```O(N)```, I won't go into much detail.


The question was essentially to write a function ```solution(X: int, Y: int, D: int)``` that would return the minimum number of ```D```s it would take to go from ```X``` to ```Y```.


# Pysux

WIP

# String Ascending Linked List
```StringAscendingLinkedList.c``` was a personal project when I first learnt about linked lists on CS50.


This C program would take a bunch of strings seperated by spaces, and would sort them and store them in a linked list


To run this program, you write on the terminal: ```./StringAscendingLinkedList.c [string1] [string2] [string3]```.

Example:


*insert example here*

# Brief Explanation


-   Firstly we had to make a function to sort out strings, for this I wrote a function ```int alpha_Values(char input)``` that inputted each character and returned a number. For example: ``` alpha_Values('c')``` returned 3. It doesn't matter if the input character is upper or lower case.

-   Next we create the ```struct``` for the linked list called ```node``` so we store the word itself, the pointer to the next struct, and number count array which is basically an array that stores each letter as a number, not a letter (```"abc" would == [1,2,3]```).

-   Once the words have been turned into their number equivalents, we then compare them and add them to their proper position in the list.

-   To sort the words with each other, we use a ```for``` loop that compares our current value to the latest one added in the linked list.
If its smaller, we add it behind the previous value, making it the second to the last one in the linked list and the previous final value stays the final value

-   We then run the loop again and again until our value is not less than the one preceding it, we then ```break``` out of the loop.


-   Lastly, we use a ```for``` loop to print the value of the first linked list's ```name``` attribute, and we then advance to the value pointed by the first value's "next-value pointer".




# Find Number without a pair

```findloner.py``` has a function ```solution()``` that inputs an array and returns the value in the list that doesn't have a duplicate efficiently.

## Multiple of the same function

Because this was another Codility project, I wrote 4 different functions trying to minimize the time complexity.


The first one has 4 ```for``` loops and 2 nested loops. The second one has 1 less loop, the third one has 1 less, and the fourth one has 1 less.


In the end, I managed to get a good score for time complexity, but the last function returned some wrong answers.



# X and O
```xomultiplayers.py``` is a simple X/O game that requires 2 players to play.