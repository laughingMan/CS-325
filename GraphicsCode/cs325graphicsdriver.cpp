//
/* file: CS325GraphicsDriver.cpp
/* author: djbouvier
/* date: 12 April 2011 
 */

#include <iostream>
#include <windows.h>
#include "vector3D.h"
#include "cs325graphics.h"

#define SCREEN_TEST 100
#define ROTATE_TEST 100
#define MOVE_TEST 100

int main(int argc, char* argv[])
{
	CS325Graphics window(argc, argv);

	float delta = 0.1;

	Point2D p1(CS325Graphics::X_MIN, CS325Graphics::Y_MAX / 4.5);
	Point2D p2(CS325Graphics::X_MAX, CS325Graphics::Y_MAX / 4.5);
	Point2D p3(CS325Graphics::X_MIN, CS325Graphics::Y_MIN);
	Point2D p4(CS325Graphics::X_MAX, CS325Graphics::Y_MAX);

	//Points 41, 42, 45, 46 control the sandbox. DON"T MESS WITH THEM!

	Point3D p30(0.5,  0.5,-3.5);
	Point3D p31(0.5, -0.5,-3.5);
	Point3D p32(-0.5,-0.5,-3.5);
	Point3D p33(-0.5, 0.5,-3.5);
	Point3D p34(0.5,  0.5,-1.5);
	Point3D p35(0.5, -0.5,-1.5);
	Point3D p36(-0.5,-0.5,-1.5);
	Point3D p37(-0.5, 0.5,-1.5);

	Point3D p40( -70.8, 28.8, -50.8);
	Point3D p41( 50.8,-2.8,  50.8);
	Point3D p42(-50.8,-2.8,  50.8);
	Point3D p43(-58.8, 25.8,  50.8);
	Point3D p44( 50.8, 50.8, -50.8);
	Point3D p45( 50.8,-2.8, -50.8);
	Point3D p46(-50.8,-2.8, -50.8);
	Point3D p47(-84.8,-2.8, -50.8);
	Point3D p49(-8.5,22.0, 50.8);
	Point3D p48(70,20,50.8);

	Point3D p50(3.5,  0.5,-3.5);
	Point3D p51(3.5, -0.5,-3.5);
	Point3D p52(2.5,-0.5,-3.5);
	Point3D p53(2.5, 0.5,-3.5);
	Point3D p54(3.5,  0.5,-1.5);
	Point3D p55(3.5, -0.5,-1.5);
	Point3D p56(2.5,-0.5,-1.5);
	Point3D p57(2.5, 0.5,-1.5);

	Point3D p60(3.5,  0.5, 13.5);
	Point3D p61(3.5, -0.5, 13.5);
	Point3D p62(2.5,-0.5,  13.5);
	Point3D p63(2.5, 0.5,  13.5);
	Point3D p64(3.5,  0.5, 16.5);
	Point3D p65(3.5, -0.5, 16.5);
	Point3D p66(2.5,-0.5,  16.5);
	Point3D p67(2.5, 0.5,  16.5);

	

	Point2D viewPos;
	Vector2D viewDir;
	Vector3D deltaV;
	viewDir.setAngle(0);


	// move view position

	for(int i = 0; i < MOVE_TEST; i){
		/*window.DrawLineOnScreen(p1, p2);*/
		//window.DrawLineOnScreen(p4, p3);

		window.DrawLineInSpace(p30, p31);
		window.DrawLineInSpace(p31, p32);
		window.DrawLineInSpace(p32, p33);
		window.DrawLineInSpace(p33, p30);
		window.DrawLineInSpace(p34, p35);
		window.DrawLineInSpace(p35, p36);
		window.DrawLineInSpace(p36, p37);
		window.DrawLineInSpace(p37, p34);
		window.DrawLineInSpace(p30, p34);
		window.DrawLineInSpace(p31, p35);
		window.DrawLineInSpace(p32, p36);
		window.DrawLineInSpace(p33, p37);

		window.DrawLineInSpace(p50, p51);
		window.DrawLineInSpace(p51, p52);
		window.DrawLineInSpace(p52, p53);
		window.DrawLineInSpace(p53, p50);
		window.DrawLineInSpace(p54, p55);
		window.DrawLineInSpace(p55, p56);
		window.DrawLineInSpace(p56, p57);
		window.DrawLineInSpace(p57, p54);
		window.DrawLineInSpace(p50, p54);
		window.DrawLineInSpace(p51, p55);
		window.DrawLineInSpace(p52, p56);
		window.DrawLineInSpace(p53, p57);

		window.DrawLineInSpace(p60, p61);
		window.DrawLineInSpace(p61, p62);
		window.DrawLineInSpace(p62, p63);
		window.DrawLineInSpace(p63, p60);
		window.DrawLineInSpace(p64, p65);
		window.DrawLineInSpace(p65, p66);
		window.DrawLineInSpace(p66, p67);
		window.DrawLineInSpace(p67, p64);
		window.DrawLineInSpace(p60, p64);
		window.DrawLineInSpace(p61, p65);
		window.DrawLineInSpace(p62, p66);
		window.DrawLineInSpace(p63, p67);


		//window.DrawLineInSpace(p40, p41);
		window.DrawLineInSpace(p41, p42);
		window.DrawLineInSpace(p42, p43);
		//window.DrawLineInSpace(p43, p40);
		//window.DrawLineInSpace(p44, p45);
		window.DrawLineInSpace(p45, p46);
		//window.DrawLineInSpace(p46, p47);
		//window.DrawLineInSpace(p47, p44);
		window.DrawLineInSpace(p40, p45);
		window.DrawLineInSpace(p41, p45);
		window.DrawLineInSpace(p42, p46);
		window.DrawLineInSpace(p43, p47);
		window.DrawLineInSpace(p40, p47);
		window.DrawLineInSpace(p41, p49);
		window.DrawLineInSpace(p42, p49);
		window.DrawLineInSpace(p41, p48);
		window.DrawLineInSpace(p45, p48);


				if(GetAsyncKeyState(VK_DOWN)) // the DOWN arrow was pressed, let's do something
		{
		delta = -.1;
		viewPos.setY(viewPos.getY() + cos(-viewDir.getAngle())*delta);
		viewPos.setX(viewPos.getX() + sin(-viewDir.getAngle())*delta);
		window.SetViewPosition(viewPos);
		cout << "view pos: " << viewPos.toString() << endl;

		window.DisplayNow();
		Sleep(50);
				}

			if(GetAsyncKeyState(VK_UP)) // the UP arrow was pressed, let's do something
		{
		delta = .1;
		viewPos.setY(viewPos.getY() + cos(-viewDir.getAngle())*delta);
		viewPos.setX(viewPos.getX() + sin(-viewDir.getAngle())*delta);
		window.SetViewPosition(viewPos);
		cout << "view pos: " << viewPos.toString() << endl;

		window.DisplayNow();
		Sleep(50);
				}
				if(GetAsyncKeyState(VK_RIGHT)) // the RIGHT arrow was pressed, let's do something
		{
	
		delta = .1;

		viewDir.setAngle(viewDir.getAngle()+delta);
		window.SetViewDirection(viewDir);
		cout << "view dir: " << viewDir.getAngle() << endl;

		window.DisplayNow();
		Sleep(50);	
			}
			
			if(GetAsyncKeyState(VK_LEFT)) // the LEFT arrow was pressed, let's do something
		{
	
		delta = -.1;

		viewDir.setAngle(viewDir.getAngle()+delta);
		window.SetViewDirection(viewDir);
		cout << "view dir: " << viewDir.getAngle() << endl;

		window.DisplayNow();
		Sleep(50);	
			}

		if(GetAsyncKeyState(VK_ESCAPE))
		{
			return 1;
		}
	}


		
	
}




