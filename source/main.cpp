#include "Iw2D.h"
#include "input.h"

int main()
{
	// Initialise the 2D graphics system
	Iw2DInit();

	// Set up input systems
	g_pInput = new Input();

	// Create an image from a PNG file
	CIw2DImage* image = Iw2DCreateImage("textures/letter_A.png");
	CIwFVec2    image_position = CIwFVec2::g_Zero;

	// Loop forever, until the user or the OS performs some action to quit the app
	while (!s3eDeviceCheckQuitRequest())
	{
		// Update input system
		g_pInput->Update();

		// Clear the drawing surface
		Iw2DSurfaceClear(0xff000000);

		// Draw an image
		CIwFVec2 sz = CIwFVec2(50, 50);
		Iw2DDrawImage(image, image_position, sz);

		// Check for user tapping screen
		if (!g_pInput->m_Touched && g_pInput->m_PrevTouched)
		{
			// Move image to touched position
			image_position.x = (float)g_pInput->m_X - 25;
			image_position.y = (float)g_pInput->m_Y - 25;

			// Reset input
			g_pInput->Reset();
		}

		// Show the drawing surface
		Iw2DSurfaceShow();

		// Yield to the OS
		s3eDeviceYield(0);
	}

	// Clean-up
	delete image;
	delete g_pInput;
	Iw2DTerminate();

	return 0;
}