# Rubik's cube
## History
Rubik's Cube is a 3-D combination puzzle invented in 1974[1][2] by Hungarian sculptor and professor of architecture Ernő Rubik. Originally called the Magic Cube.

In a classic Rubik's Cube, each of the six faces is covered by nine stickers, each of one of six solid colours: white, red, blue, orange, green, and yellow. In currently sold models, white is opposite yellow, blue is opposite green, and orange is opposite red, and the red, white and blue are arranged in that order in a clockwise arrangement.

## Introduction
The rubik's cube will be read from file or keyboard.
The standard position for the rubik's cube is: green side in front of you and white side up.
If your rubik's cube has different patterns or colours, look at this:

-Example 1: If the center of the left side is red, in all stickers you should select orange.

-Example 2: If the center of the back side is black, in your black stickers you should select blue.

The program will read 54 colours, one side each time.

## Colours
You can use three different options:
   W/w/1 for white
   O/o/2 for orange
   G/g/3 for green
   R/r/4 for red
   L/l/5 for blue
   Y/y/6 for yellow

You will be able to change the colours. The program will show:

![Colours](./img/colours.jepg "Colours")


## Movements
The rubik's cube has 12 different movements and double movements: F2, B2, R2, L2, U2, D2.
"FBRLUD" movements in clockwise
"fbrlud" the opposite movement.

F(ront), B(ack), R(igth), L(eft), U(p), D(own)

![Movements](./img/movements.jpg "Movements")

[Image from]
(http://rubiksolucion.blogspot.com.es/2012/07/notacion-cubo-de-rubik-3x3x3.html)

## Arguments
Without arguments, the rubik's cube will be read from file or keyboard.

With one argument it will read from this file.
$ Rubik readable_file.txt

Two arguments, read from first, show the solution on the other.
$ Rubik readable_file.txt solution.txt
