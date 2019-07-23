// Schlum.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Schlum.h"
#include "String.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana\gui\element.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/paint/image.hpp>
#include <nana/gui/timer.hpp>

using namespace nana;
using namespace paint;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void end() {

	form fm;
	fm.size(size(711, 400));

	fm.show();
	exec();
};

void the_game() {
	form fm;
	fm.size(size(711, 400));

	label lb{ fm, rectangle{ 75, 20, 140, 50 } };
	API::effects_bground(lb, effects::bground_transparent(0), 0);
	lb.typeface(font{
							 "Bauhaus 93",
							 35,
							 { 700 }
		});
	lb.fgcolor(colors::yellow);
	lb.caption("Time");

	label lb_cd{ fm, rectangle{ 50, 70, 182, 282 } };
	API::effects_bground(lb_cd, effects::bground_transparent(0), 0);
	lb_cd.typeface(font{
							 "Bauhaus 93",
							 90,
							 { 700 }
		});
	lb_cd.fgcolor(colors::black);

	timer tm{ std::chrono::seconds{1} };
	tm.elapse([&lb_cd, &tm] {
		static int i = 2;
		lb_cd.caption(std::to_string(i--));
		if (i <= -1) {
			timer tm2{ std::chrono::seconds{1} };
			static int j = 2;
			lb_cd.caption(std::to_string(j--));
			if (j<= -1) {
				timer tm3{ std::chrono::seconds{1} };
				static int k = 2;
				lb_cd.caption(std::to_string(k--));
				if (k <= -1) {
					timer tm3{ std::chrono::seconds{1} };
					static int l = 2;
					lb_cd.caption(std::to_string(l--));
					if (l <= -1 && l!=100) {
						l = 100;
						API::exit_all();
					}
				}
			}
		};
		});
	tm.start();

	button btn_schli_schla{ fm, rectangle{260, 70, 182, 282} };
	element::bground bground2;
	bground2.image(image("..\\..\\Schlum\\Schlum\\schli_bur.bmp"), true, {});
	API::effects_bground(btn_schli_schla, effects::bground_transparent(0), 0);
	bground2.stretch_parts(4, 4, 4, 4);
	btn_schli_schla.set_bground(bground2);

	label lb2{ fm, rectangle{ 541, 20, 150, 50 } };
	API::effects_bground(lb2, effects::bground_transparent(0), 0);
	lb2.typeface(font{
							 "Bauhaus 93",
							 35,
							 { 700 }
		});
	lb2.fgcolor(colors::yellow);
	lb2.caption("Points");

	label lb_pt{ fm, rectangle{479, 70, 182, 282 } };
	API::effects_bground(lb_pt, effects::bground_transparent(0), 0);
	lb_pt.typeface(font{
							 "Bauhaus 93",
							 90,
							 { 700 }
		});
	lb_pt.fgcolor(colors::black);
	int pt = 0;
	lb_pt.caption("0");
	btn_schli_schla.events().click([&lb_pt, &pt] {
		++pt;
		lb_pt.caption(std::to_string(pt));
		});
	

	image img("..\\..\\Schlum\\Schlum\\background2.bmp");
	drawing dw(fm);
	dw.draw([&img](graphics& graph)
		{
			if (img.empty()) return;
			img.paste(graph, point{});
		});
	dw.update();
	fm.show();
	exec();
}

void entry_window() {
	form fm;
	fm.caption("Schlum");
	fm.size(size(711, 400));

	button btn(fm, rectangle(285, 180, 140, 40));
	element::bground bground;
	bground.stretch_parts(4, 4, 4, 4);
	btn.set_bground(bground);
	btn.typeface(font{
							 "Bauhaus 93",
							 18,
							 { 700 }
		});
	btn.fgcolor(colors::yellow);
	btn.bgcolor(colors::blue);
	btn.caption("Schlay!");
	btn.events().click([] {
		API::exit_all();
		the_game();
		});

	label lb{ fm, rectangle{ 75, 20, 140, 50 } };
	API::effects_bground(lb, effects::bground_transparent(0), 0);
	lb.typeface(font{
							 "Bauhaus 93",
							 35,
							 { 700 }
		});
	lb.fgcolor(colors::yellow);
	lb.caption("Shli");
	

	button btn_schli{ fm, rectangle{50, 70, 182, 282} };
	element::bground bground2;
	bground2.image(image("..\\..\\Schlum\\Schlum\\schli_bur.bmp"), true, {});
	API::effects_bground(btn_schli, effects::bground_transparent(0), 0);
	bground2.stretch_parts(4, 4, 4, 4);
	btn_schli.set_bground(bground2);


	button btn_schla{ fm, rectangle{479, 70, 182, 282} };
	element::bground bground3;
	bground3.image(image("..\\..\\Schlum\\Schlum\\schli_bur.bmp"), true, {});
	API::effects_bground(btn_schla, effects::bground_transparent(0), 0);
	bground3.stretch_parts(4, 4, 4, 4);
	btn_schla.set_bground(bground3);


	label lb2{ fm, rectangle{ 551, 20, 140, 50 } };
	API::effects_bground(lb2, effects::bground_transparent(0), 0);
	lb2.typeface(font{
							 "Bauhaus 93",
							 35,
							 { 700 }
		});
	lb2.fgcolor(colors::yellow);
	lb2.caption("Shla");

	image img("..\\..\\Schlum\\Schlum\\background2.bmp");
	drawing dw(fm);
	dw.draw([&img](graphics& graph)
		{
			if (img.empty()) return;
			img.paste(graph, point{});
		});
	dw.update();
	fm.show();
	exec();
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	the_game();
}