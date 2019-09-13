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

void Windows(int r, int p);

class components {
private:
	const size WINDOW_SIZE = { 711, 400 };
	static constexpr bool set_min_size = false;
	static constexpr bool set_max_size = true;
	form fm;
	element::bground bground;
public:
	components() {
		fm.size(WINDOW_SIZE);
		API::track_window_size(fm, WINDOW_SIZE, set_min_size);
		API::track_window_size(fm, WINDOW_SIZE, set_max_size);
		fm.caption("Schlum");
		bground.stretch_parts(4, 4, 4, 4);
	}

	void ChoseComponent(int btn_x, int btn_y, int btn_x2, int btn_y2, std::string btn_cap,
		int btn2_x, int btn2_y, int btn2_x2, int btn2_y2, std::string btn2_cap,
		int lb_x, int lb_y, unsigned int lb_x2, unsigned int lb_y2, std::string lb_cap,
		int lb2_x, int lb2_y, unsigned int lb2_x2, unsigned int lb2_y2, std::string lb2_cap,
		std::string res_img, int game) {

		button btn_schla2{ fm, rectangle{260, 70, 182, 282} };
		button btn_schla{ fm, rectangle{260, 70, 182, 282} };
		button btn_schli2{ fm, rectangle{260, 70, 182, 282} };
		button btn_schli{ fm, rectangle{260, 70, 182, 282} };
		btn_schla2.hide();
		btn_schla.hide();
		btn_schli2.hide();
		btn_schli.hide();

		button btn(fm, rectangle(btn_x, btn_y, btn_x2, btn_y2));
		btn.set_bground(bground);
		btn.typeface(font{ "Bauhaus 93", 18, { 700 } });
		btn.fgcolor(colors::yellow);
		btn.bgcolor(colors::blue);
		btn.caption(btn_cap);
		btn.events().click([] {
			API::exit_all();
			Windows(1, 0);
			});

		button btn2(fm, rectangle(btn2_x, btn2_y, btn2_x2, btn2_y2));
		btn2.set_bground(bground);
		btn2.typeface(font{ "Bauhaus 93", 18, { 700 } });
		btn2.fgcolor(colors::yellow);
		btn2.bgcolor(colors::blue);
		btn2.caption(btn2_cap);
		btn2.events().click([] {
			API::exit_all();
			Windows(0, 0);
			});

		label lb_state{ fm, rectangle{ 220, 5, 300, 50 } };
		label lb_pt{ fm, rectangle{479, 70, 182, 282 } };
		label lb_cd{ fm, rectangle{ 50, 70, 182, 282 } };
		API::effects_bground(lb_cd, effects::bground_transparent(0), 0);
		lb_cd.typeface(font{ "Bauhaus 93", 90, { 700 } });
		lb_cd.fgcolor(colors::black);
		lb_state.hide();
		lb_pt.hide();
		lb_cd.hide();

		label lb{ fm, rectangle{ lb_x, lb_y, lb_x2, lb_y2 } };
		API::effects_bground(lb, effects::bground_transparent(0), 0);
		lb.typeface(font{ "Bauhaus 93",35, { 700 } });
		lb.fgcolor(colors::yellow);
		lb.caption(lb_cap);

		label lb2{ fm, rectangle{ lb2_x, lb2_y, lb2_x2, lb2_y2 } };
		API::effects_bground(lb2, effects::bground_transparent(0), 0);
		lb2.typeface(font{ "Bauhaus 93", 35, { 700 } });
		lb2.fgcolor(colors::yellow);
		lb2.caption(lb2_cap);

		image img(res_img);
		drawing dw(fm);
		dw.draw([&img](graphics& graph)
			{
				if (img.empty()) return;
				img.paste(graph, point{});
			});
		dw.update();

		timer tm3{ std::chrono::milliseconds{250} };
		timer tm2{ std::chrono::milliseconds{250} };
		timer tm{ std::chrono::milliseconds{1000} };

		if (game == 1) {

			lb.caption("Time");
			lb2.caption("Points");

			btn_schla2.show();
			btn_schla.show();
			btn_schli2.show();
			btn_schli.show();
			lb_state.show();
			lb_pt.show();
			lb_cd.show();

			element::bground bground3;
			bground3.image(image("..\\..\\Schlum\\Schlum\\schla_game.bmp"), false, rectangle{ 0, 0 ,1100,280 });
			API::effects_bground(btn_schla2, effects::bground_transparent(0), 0);
			bground3.stretch_parts(4, 4, 4, 4);
			btn_schla2.set_bground(bground3);
			btn_schla.set_bground(bground3);
			API::effects_bground(btn_schla, effects::bground_transparent(0), 0);

			element::bground bground2;
			bground2.image(image("..\\..\\Schlum\\Schlum\\schli_game.bmp"), false, rectangle{ 0, 0 ,862,225 });
			API::effects_bground(btn_schli2, effects::bground_transparent(0), 0);
			bground2.stretch_parts(4, 4, 4, 4);
			btn_schli2.set_bground(bground2);
			API::effects_bground(btn_schli, effects::bground_transparent(0), 0);
			btn_schli.set_bground(bground2);

			API::effects_bground(lb_state, effects::bground_transparent(0), 0);
			lb_state.typeface(font{ "Bauhaus 93", 35,{ 700 } });
			lb_state.fgcolor(colors::yellow);

			API::effects_bground(lb_pt, effects::bground_transparent(0), 0);
			lb_pt.typeface(font{ "Bauhaus 93", 90, { 700 } });
			lb_pt.fgcolor(colors::black);
			static int pt = 0;
			lb_pt.caption(std::to_string(pt));

			static int i = 4, j = 0, k = 0, l = 0, z = 0, e = 0, schla = 0, schli = 0;
			lb_cd.caption("4");
			tm.elapse([&lb_cd, &tm, &lb_state, &lb_pt, &btn_schli, &btn_schla, &bground2, &btn_schli2, &tm2, &bground3, &tm3] {
				if (i <= -1 || j == 0) {
					switch (j) {
					case 0:
						l = 0; k = 0; e = 0; i = 4;
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
									if (e == 0)
										btn_schli.events().click([&lb_pt] {
										++pt;
										lb_pt.caption(std::to_string(pt));
											});
									++k; ++l; ++e;
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
						l = 0; k = 0; e = 0; i = 15;
						lb_state.caption("Shla play!!!");
						tm3.elapse([&btn_schla, &lb_pt, &bground3, &btn_schli2] {
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
									++k; ++l; ++e;
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
							schla = 0; schli = 0;
							Windows(2, 2);
						}
						else if (schla < schli) {
							schla = 0; schli = 0;
							Windows(2, 1);
						}
						else {
							schla = 0; schli = 0;
							Windows(2, 0);
						}
						break;
					};
					j++;
				};
				lb_cd.caption(std::to_string(i--));
				});
			tm.start();
		}
		fm.show();
		exec();
	}
};

void Windows(int r, int p) {

	components comp;
	std::string res_cap, res_img;

	switch (r) {
	case 0:
		comp.ChoseComponent(285, 180, 140, 40, "Play!", 0, 0, 0, 0, "", 75, 20, 140, 50, "Schli", 521, 20, 140, 50, "Schla", "..\\..\\Schlum\\Schlum\\background3.bmp", 0);
		break;
	case 1:
		comp.ChoseComponent(0, 0, 0, 0, "", 0, 0, 0, 0, "", 75, 20, 140, 50, "Schli", 521, 20, 140, 50, "Schla", "..\\..\\Schlum\\Schlum\\background2.bmp", 1);
		break;
	case 2:
		if (p == 0) { res_cap = "It's a Tie!!!"; res_img = "..\\..\\Schlum\\Schlum\\bgrnd_tie.bmp"; }
		else if (p == 1) { res_cap = "Schli wins!!!"; res_img = "..\\..\\Schlum\\Schlum\\bgrnd_schla_win.bmp"; }
		else if (p == 2) { res_cap = "Schla wins!!!"; res_img = "..\\..\\Schlum\\Schlum\\bgrnd_schli_win.bmp"; }

		comp.ChoseComponent(65, 180, 140, 40, "Play again!", 506, 180, 140, 40, "Return", 220, 5, 300, 50, res_cap, 0, 0, 0, 0, "", res_img, 0);
		break;
	};
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	Windows(0, 2);
}