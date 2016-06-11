# Intermediate269

Taken from: https://www.reddit.com/r/dailyprogrammer/comments/4m3ddb/20160601_challenge_269_intermediate_mirror/

# Description:

We are going to encrypt and decrypt with a mirror field.

It works like this:

We align letters to a mirror field:

     ab
    A \c
    B\ d
     CD

Every letter has now a mirror image

For example A has as mirror image D

    A-\ 
      | 
      D

The / and \ act as a mirror that will turn the line 90 degrees like you would if you had a laserpointer pointed to a mirror.

The full letter grid will look like this (without the seperators):

     |a|b|c|d|e|f|g|h|i|j|k|l|m|
    -----------------------------
    A| | | | | | | | | | | | | |n
    -----------------------------
    B| | | | | | | | | | | | | |o
    -----------------------------
    C| | | | | | | | | | | | | |p
    -----------------------------
    D| | | | | | | | | | | | | |q
    -----------------------------
    E| | | | | | | | | | | | | |r
    -----------------------------
    F| | | | | | | | | | | | | |s
    -----------------------------
    G| | | | | | | | | | | | | |t
    -----------------------------
    H| | | | | | | | | | | | | |u
    -----------------------------
    I| | | | | | | | | | | | | |v
    -----------------------------
    J| | | | | | | | | | | | | |w
    -----------------------------
    K| | | | | | | | | | | | | |x
    -----------------------------
    L| | | | | | | | | | | | | |y
    -----------------------------
    M| | | | | | | | | | | | | |z
    -----------------------------
     |N|O|P|Q|R|S|T|U|V|W|X|Y|Z|
