#include <stdio.h>
#include <cstdlib>
#include <gccore.h>
#include <asndlib.h>
#include <wiiuse/wpad.h>
#include <mp3player.h>
#include "wrbtbgm_mp3.h"




static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

int main (int argc, char **argv) {
    
	VIDEO_Init();

	WPAD_Init();

	ASND_Init();

	MP3Player_Init();

	rmode = VIDEO_GetPreferredMode(NULL);

	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);

	VIDEO_Configure(rmode);

	VIDEO_SetNextFramebuffer(xfb);

	VIDEO_SetBlack(FALSE);

	VIDEO_Flush();

	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();


printf ("Welcome to the Wii Remote Button Tester!\n Press HOME + A to exit.");

MP3Player_PlayBuffer(wrbtbgm_mp3, wrbtbgm_mp3_size, NULL);

	while(1) {

		WPAD_ScanPads();

		u32 pressed = WPAD_ButtonsDown(0);

		if ( pressed & WPAD_BUTTON_HOME ) printf ("\n \n Home Button is Working!");

		if ( pressed & WPAD_BUTTON_HOME && pressed & WPAD_BUTTON_A)  exit(0);

        if  ( pressed & WPAD_BUTTON_HOME && pressed & WPAD_BUTTON_A ) printf ("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n Exiting...");

		if ( pressed & WPAD_BUTTON_2 ) printf ("\n \n Button 2 is Working!");

		if ( pressed & WPAD_BUTTON_1 ) printf ("\n \n Button 1 is Working!");

		if ( pressed & WPAD_BUTTON_A ) printf ("\n \n A Button is Working!");

		if ( pressed & WPAD_BUTTON_B ) printf ("\n \n B Button is Working!");

		if ( pressed & WPAD_BUTTON_MINUS ) printf ("\n \n - Button is Working!");

		if ( pressed & WPAD_BUTTON_PLUS ) printf ("\n \n + Button is Working!");

		if ( pressed & WPAD_BUTTON_LEFT ) printf ("\n \n D-PAD Left Button is Working!");

		if ( pressed & WPAD_BUTTON_RIGHT ) printf ("\n \n D-PAD Right Button is Working!");

		if ( pressed & WPAD_BUTTON_UP ) printf ("\n \n D-PAD Up Button is Working!");

		if ( pressed & WPAD_BUTTON_DOWN ) printf ("\n \n D-PAD Down Button is Working!");
		
		VIDEO_WaitVSync();
	}


return 0;
}
