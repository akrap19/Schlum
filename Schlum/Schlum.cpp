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
#include <nana/gui/widgets/picture.hpp>
#include <nana/gui/place.hpp>

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

void the_game();

void entry_window();

void end(int r);



void the_game() {
	const size WINDOW_SIZE = { 711, 400 };
	constexpr bool set_min_size = false;
	constexpr bool set_max_size = true;
	form fm;
	fm.size(WINDOW_SIZE);
	API::track_window_size(fm, WINDOW_SIZE, set_min_size);
	API::track_window_size(fm, WINDOW_SIZE, set_max_size);
	fm.caption("Schlum");

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
	

	
	button btn_schla2{ fm, rectangle{260, 70, 182, 282} };
	element::bground bground3;
	bground3.image(image("..\\..\\Schlum\\Schlum\\schla_game.bmp"), false, rectangle{0, 0 ,1100,280 });
	API::effects_bground(btn_schla2, effects::bground_transparent(0), 0);
	bground3.stretch_parts(4, 4, 4, 4);
	btn_schla2.set_bground(bground3);
	button btn_schla{ fm, rectangle{260, 70, 182, 282} };
	btn_schla.set_bground(bground3);
	API::effects_bground(btn_schla, effects::bground_transparent(0), 0);

	button btn_schli2{ fm, rectangle{260, 70, 182, 282} };
	element::bground bground2;
	bground2.image(image("..\\..\\Schlum\\Schlum\\schli_game.bmp"), false, rectangle{ 0, 0 ,862,225 });
	API::effects_bground(btn_schli2, effects::bground_transparent(0), 0);
	bground2.stretch_parts(4, 4, 4, 4);
	btn_schli2.set_bground(bground2);
	button btn_schli{ fm, rectangle{260, 70, 182, 282} };
	API::effects_bground(btn_schli, effects::bground_transparent(0), 0);
	btn_schli.set_bground(bground2);
	


	label lb2{ fm, rectangle{ 541, 20, 150, 50 } };
	API::effects_bground(lb2, effects::bground_transparent(0), 0);
	lb2.typeface(font{
							 "Bauhaus 93",
							 35,
							 { 700 }
		});
	lb2.fgcolor(colors::yellow);
	lb2.caption("Points");

	label lb_state{ fm, rectangle{ 220, 5, 300, 50 } };
	API::effects_bground(lb_state, effects::bground_transparent(0), 0);
	lb_state.typeface(font{
							 "Bauhaus 93",
							 35,
							 { 700 }
		});
	lb_state.fgcolor(colors::yellow);
	

	label lb_pt{ fm, rectangle{479, 70, 182, 282 } };
	API::effects_bground(lb_pt, effects::bground_transparent(0), 0);
	lb_pt.typeface(font{
							 "Bauhaus 93",
							 90,
							 { 700 }
		});
	lb_pt.fgcolor(colors::black);
	static int pt = 0;
	lb_pt.caption(std::to_string(pt));

	
		
	static int i = 4, j = 0, k = 0, l = 0,  z = 0, e = 0, schla = 0, schli = 0;
	lb_cd.caption("4");
	timer tm3{ std::chrono::milliseconds{250} };
	timer tm2{ std::chrono::milliseconds{250} };
	timer tm{ std::chrono::milliseconds{1000} };
	tm.elapse([&lb_cd, &tm, &lb_state, &lb_pt, &btn_schli, &btn_schla, &bground2, &btn_schli2, &tm2, &bground3, &tm3] {
		
		if (i <= -1||j==0) {

			switch (j) {
			case 0:
				l = 0;
				k = 0;
				e = 0;
				i = 4;
				lb_state.caption("Shli ready?");
				btn_schla.hide();
				btn_schli2.hide();
				break;
			case 1:
				i = 15;
				lb_state.caption("Shli play?");
					
				tm2.elapse([&btn_schli, &lb_pt, &bground3] {
					if (l <= 61) {
					switch (k)
					{
					case 0:
						btn_schli.show();
						if(e==0)
						btn_schli.events().click([&lb_pt] {
								++pt;
								lb_pt.caption(std::to_string(pt));
							
							});
						++k;
						++l;
						++e;
						break;
					case 1:
						btn_schli.hide();
						--k;
						++l;
						break;
					}
					}
					});
				tm2.start();
				break;
			case 2:
				tm2.stop();
				btn_schli.hide();
				btn_schli2.show();
				i = 3;
				lb_state.caption("Shli ended!!!");
				schli = pt;
				pt = 0;
				break;
			case 3:
				btn_schli2.hide();
				btn_schla.show();
				i = 2;
				lb_state.caption("Shla ready?");
				lb_pt.caption(std::to_string(pt));
				break;
			case 4:
				l = 0;
				k = 0;
				e = 0;
				i = 15;
				lb_state.caption("Shla play!!!");
				tm3.elapse([&btn_schla, &lb_pt, &bground3,&btn_schli2] {
					if (l <= 61) {
						switch (k)
						{
						case 0:
							btn_schli2.hide();
							if (e == 0)
								btn_schla.events().click([&lb_pt] {
								++pt;
								lb_pt.caption(std::to_string(pt));

									});
							++k;
							++l;
							++e;
							break;
						case 1:
							btn_schli2.show();
							--k;
							++l;
							break;
						}
					}
					});
				tm3.start();
				break;
			case 5:
				tm3.stop();
				schla = pt;
				pt = 0;
				lb_pt.caption(std::to_string(schla));
				btn_schli2.hide();
				btn_schla.hide();
				i = 3;
				lb_state.caption("Shla ended!!!");
				break;
			case 6:
				j = 0;
				i = 2;
				tm.stop();
				API::exit_all();
				if (schla > schli) {
					schla = 0;
					schli = 0;
					end(2);
				}
				else if (schla < schli) {
					schla = 0;
					schli = 0;
					end(1);
				}
				else {
					schla = 0;
					schli = 0;
					end(0);
				}
				break;
			};
			j++;
		};
		lb_cd.caption(std::to_string(i--));
		});
	tm.start();

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
	const size WINDOW_SIZE = { 711, 400 };
	constexpr bool set_min_size = false;
	constexpr bool set_max_size = true;
	form fm;
	fm.size(WINDOW_SIZE);
	API::track_window_size(fm, WINDOW_SIZE, set_min_size);
	API::track_window_size(fm, WINDOW_SIZE, set_max_size);
	fm.caption("Schlum");
	
	

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
	btn.caption("Play!");
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


	label lb2{ fm, rectangle{ 551, 20, 140, 50 } };
	API::effects_bground(lb2, effects::bground_transparent(0), 0);
	lb2.typeface(font{
							 "Bauhaus 93",
							 35,
							 { 700 }
		});
	lb2.fgcolor(colors::yellow);
	lb2.caption("Shla");

	image img("..\\..\\Schlum\\Schlum\\background3.bmp");
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

void end(int r) {

	const size WINDOW_SIZE = { 711, 400 };
	constexpr bool set_min_size = false;
	constexpr bool set_max_size = true;
	form fm;
	fm.size(WINDOW_SIZE);
	API::track_window_size(fm, WINDOW_SIZE, set_min_size);
	API::track_window_size(fm, WINDOW_SIZE, set_max_size);
	fm.caption("Schlum");

	image img("..\\..\\Schlum\\Schlum\\bgrnd_tie.bmp");
	image img3("..\\..\\Schlum\\Schlum\\bgrnd_schli_win.bmp");
	image img2("..\\..\\Schlum\\Schlum\\bgrnd_schla_win.bmp");
	drawing dw(fm);
	label lb{ fm, rectangle{ 220, 5, 300, 50 } };
	API::effects_bground(lb, effects::bground_transparent(0), 0);
	lb.typeface(font{
							 "Bauhaus 93",
							 35,
							 { 700 }
		});
	lb.fgcolor(colors::yellow);

	switch (r) {
	case 0:
		dw.draw([&img](graphics& graph)
			{
				if (img.empty()) return;
				img.paste(graph, point{});
			});
		dw.update();
		lb.caption("It's a Tie!!!");
		break;
	case 1:
		dw.draw([&img2](graphics& graph)
			{
				if (img2.empty()) return;
				img2.paste(graph, point{});
			});
		dw.update();
		lb.caption("Schli wins!!!");
		break;
	case 2:
		dw.draw([&img3](graphics& graph)
			{
				if (img3.empty()) return;
				img3.paste(graph, point{});
			});
		dw.update();
		lb.caption("Schla wins!!!");
		break;
	};

	button btn(fm, rectangle(65, 180, 140, 40));
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
	btn.caption("Play again!");
	btn.events().click([] {
		API::exit_all();
		the_game();
		});

	button btn2(fm, rectangle(506, 180, 140, 40));
	element::bground bground2;
	bground2.stretch_parts(4, 4, 4, 4);
	btn2.set_bground(bground2);
	btn2.typeface(font{
							 "Bauhaus 93",
							 18,
							 { 700 }
		});
	btn2.fgcolor(colors::yellow);
	btn2.bgcolor(colors::blue);
	btn2.caption("Return");
	btn2.events().click([] {
		API::exit_all();
		entry_window();
		});

	fm.show();
	exec();
};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	entry_window();
}