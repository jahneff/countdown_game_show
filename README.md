# countdown_game_show
Simple implementation of the countdown game on Countdown! game show. 

This is for code that solves the countdown game.

A user inputs 6 integers, and a number to evaluate these to. eg. {[1, 2, 3, 4, 5, 6], 24}

The code will return whether or not that number was possible to obtain by left-to-right in-order mathematical operations. 
This means PEMDAS is not applied and no parentheses are used. The numbers are simply evaluated left to right. 

**recursivecountdown.cpp**
  This is a single solution rescursion algorithm that ends after it finds a solution. 
  It is supposed to be low overhead but I have not yet tested how much memory it requires.
  
**iterativecountdown.cpp**
  This is a brute force iterative algorithm that finds all possible solutions and outputs them to the user. 
