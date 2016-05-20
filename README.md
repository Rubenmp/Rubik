# Rubik's cube
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

You will be able to change the colours.

## Movements
The rubik's cube has 12 different movements and double movements: F2, B2, R2, L2, U2, D2.
"FBRLUD" movements in clockwise
"fbrlud" the opposite movement.

F(ront), B(ack), R(igth), L(eft), U(p), D(own)

![Title](./img/movements.jpg "Movements")

[Image from](
https://www.google.es/search?q=movimientos+cubo+de+rubik&client=ubuntu&hs=OJX&channel=fs&source=lnms&tbm=isch&sa=X&ved=0ahUKEwj7iMzrq-nMAhUCChoKHUZcAVsQ_AUIBygB&biw=1088&bih=561#imgrc=h6oNMf74ZSsQSM%3A)

## Arguments
Without arguments, the rubik's cube will be read from file or keyboard.

With one argument it will read from this file.
$ Rubik readable_file.txt

Two arguments, read from first, show the solution on the other.
$ Rubik readable_file.txt solution.txt
