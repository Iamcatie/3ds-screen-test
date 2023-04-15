/*
	Hello World example made by Aurelio Mannara for libctru
	This code was modified for the last time on: 12/12/2014 21:00 UTC+1
*/

#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	gfxInitDefault();

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	PrintConsole topScreen, bottomScreen;
        consoleInit(GFX_TOP, &topScreen);
        consoleInit(GFX_BOTTOM, &bottomScreen);
        consoleSelect(&topScreen);

	//Move the cursor to row 15 and column 19 and then prints "Hello World!"
	//To move the cursor you have to print "\x1b[r;cH", where r and c are respectively
	//the row and column where you want your cursor to move
	//The top screen has 30 rows and 50 columns
	//The bottom screen has 30 rows and 40 columns
        
        //displays top screen text
	printf("\x1b[16;20HHD Burrito.");
        printf("\x1b[18;14HThis is the \x1b[31mTOP SCREEN\x1b[0m.");
        printf("\x1b[20;20H...I think?");
        //start command prompt
	printf("\x1b[29;7HPress Start to Test the \x1b[34mBOTTOM SCREEN\x1b[0m.");
        printf("\x1b[30;18HPress B to exit.");

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();
                //selects bottom screen and displays text when start is pressed
		if (kDown & KEY_START) 
                {
                   consoleSelect(&bottomScreen);
                   printf("\x1b[15;14H240p Burrito.");
                   printf("\x1b[17;8HThis is the \x1b[34mBOTTOM SCREEN\x1b[0m.");
                   printf("\x1b[19;15H...I think?");
                   //prompy to exit with B
                   printf("\x1b[29;13HPress B to exit.");
                };  
                if (kDown & KEY_B) break;
                // break in order to return to hbmenu

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
