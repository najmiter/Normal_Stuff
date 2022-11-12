#include <iostream>

int main()
{
    // FOR MACOS
    // If the file is in the same directory as the source file:
    system("open thatGuy.mp4");

    // or else you have to give the complete address:
    system("open ~/Downloads/thatGuy.mp4");

    // You can also open a file-with a specific software:
    system("open -a \"quickTime Player\" ~/Downloads/thatGuy.mp4");

    // FOR WINDOWS
    // You just type the name/complete address of the file.
    // system("thatGuy.mp4");
}
