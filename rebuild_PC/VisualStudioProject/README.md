# Preparation Guide
* Find your licensed disc in the american region SCUS-94426 Crash Team Racing 
* Insert the disk into the computer's CD drive and make an image in .CUE .BIN format
* Compare the checksums of the .BIN file with these:
	+ MD5: ab95bfca8a4bb3d90daa6519acf6e944
	+ SHA1: 1bb785082def3fe25f6b46be06d4eaf33c5bc772
	+ SHA256: f780bf2331476aabfc00772fa758b12dd95ebfbc907968132cbd3cdd4e2c07c0
	+ SHA512: f9cac755e2b29fccf7484dfa7fda0458d345d7309fcefa1b6481a370eb32c075bdd822dbbb71f20cb8b407c4737c326ad6f7b4402700caeeb1eab12686cb41ec
* Rename the file to "ctr-u.bin" (we are a quote)
# How to use
* To build this project you will need a modern compiler from Microsoft, "release" and "x86" project configuration.
* To run, the operating system must have 32-bit SDL2.dll (available, or find it yourself) and OpenAL for Windows installed.
* The ctr-u.bin is launched by transferring it to an executable file or place a file named "ctr-u.bin" in the directory with the executable file.

# Command Line
You can run the program from the command line. You can use the parameters "/w number" and "/h number" to set the width and height, the last parameter should be the path to the .BIN file.
