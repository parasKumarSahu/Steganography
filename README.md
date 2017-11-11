# Steganography
Hide a text message by breaking the message into group of some bits and then storing these bits in pixels of a gray-scale pgm image.

Compile
gcc HideMessage.c -o hide
gcc ShowMessage.c -o show

Run(to hide message in InputImage.pgm)
./hide InputImage.pgm “Message to hide”

Run(to show hidden message in InputImage.pgm)
./show InputImage.pgm

Output
Hidden message is printed on the terminal
