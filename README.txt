The story begins like this. I wrote the program, however, since every thing was in one file it looked hideous and was hard to debug.
So, I decided to spit them up. However, every time I made some small tweaks it was a pain to compile those multiple files in the CLI interface.
Therefore, to make my life easier I decided to wirte a simple posix conforming shell script to build the solution.

How to build?
cd Assignment2:Counting_vowels
chmod +x build
./build

These commands will create the executable count_vowel
Typical use case: count_vowel file1 file2 file3 .............. file_(N) 


Program Folder Structure
src: contains the source code .c files
src/headers: contains the header .h files

Note:- executable gets created on the top folder where the build script is located and this README.txt is located.


 
