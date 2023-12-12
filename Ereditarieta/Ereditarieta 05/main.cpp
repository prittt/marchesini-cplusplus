#define _CRT_SECURE_NO_WARNINGS

#include "canvas.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>

struct shape {
	std::string type_;
	int x_, y_;
	char ch_;

	shape(const std::string& type, int x, int y, char ch) {
		type_ = type;
		x_ = x;
		y_ = y;
		ch_ = ch;
		//print = shape_print;
	}

	virtual ~shape() { std::cout << "~shape()\n"; }

	virtual void print(canvas& c) const {
		c.set(x_, y_, ch_); // Solo per debug
	}
};

struct point : public shape {
	std::string inutile_;
	point(int x, int y, char ch): shape("point", x, y, ch) {
		inutile_ = "Ciao!";
	}
	~point() { std::cout << "~point()\n"; }
	void print(canvas& c) const override {
		c.set(x_, y_, ch_);
	}
};

struct line: public shape {
	int x1_, y1_;

	line(int x0, int y0, int x1, int y1, char ch) 
	: shape("line", x0, y0, ch), x1_(x1), y1_(y1) {
		//base.print = line_print;
	}
	~line() { std::cout << "~line()\n"; }
	void print(canvas& c) const override {
		c.line(x_, y_, x1_, y1_, ch_);
	}
};

struct rectangle : public shape {
	int x1_, y1_;

	rectangle(int x0, int y0, int x1, int y1, char ch) 
	: shape("rectangle", x0, y0, ch), x1_(x1), y1_(y1) {
		//base.print = rectangle_print;
	}
	~rectangle() { std::cout << "~rectangle()\n"; }
	void print(canvas& c) const override {
		c.rectangle(x_, y_, x1_, y1_, ch_);
	}
};

struct circle : public shape {
	int r_;

	circle(int x0, int y0, int r, char ch)
	: shape("circle", x0, y0, ch), r_(r) {
		//base.print = circle_print;
	}
	~circle() { std::cout << "~circle()\n"; }
	void print(canvas& c) const override {
		c.circle(x_, y_, r_, ch_);
	}
};

/*
type_of_object parameter_1 parameter_2 ... parameter_n

rectangle 0 0 79 24 *
point 5 15 ?
circle 10 10 4 @
circle 70 10 4 @
line 40 15 40 20 |
*/
/*
shape **read_shapes(FILE *f, size_t *size)
{
	shape **sv = NULL;
	size_t n = 0;

	char type[30];
	while (fscanf(f, "%29s", type) == 1) {
		int x0, y0, x1, y1, r;
		char ch;
		sv = realloc(sv, ++n * sizeof *sv);
		if (strcmp(type, "point") == 0) {
			fscanf(f, "%d%d %c", &x0, &y0, &ch);
			sv[n - 1] = new_shape(type, x0, y0, 0, 0, 0, ch);
		}
		else if (strcmp(type, "line") == 0) {
			fscanf(f, "%d%d%d%d %c", &x0, &y0, &x1, &y1, &ch);
			sv[n - 1] = new_shape(type, x0, y0, x1, y1, 0, ch);
		}
		else if (strcmp(type, "rectangle") == 0) {
			fscanf(f, "%d%d%d%d %c", &x0, &y0, &x1, &y1, &ch);
			sv[n - 1] = new_shape(type, x0, y0, x1, y1, 0, ch);
		}
		else if (strcmp(type, "circle") == 0) {
			fscanf(f, "%d%d%d %c", &x0, &y0, &r, &ch);
			sv[n - 1] = new_shape(type, x0, y0, 0, 0, r, ch);
		}
	}
	
	*size = n;
	return sv;
}
*/

int main(void)
{
	using namespace std;
	
	canvas c(80, 25);

	size_t n = 5;

	vector<unique_ptr<shape>> sv(5);
	sv[0].reset(new rectangle(0,0,79,24,'*'));
	sv[1].reset(new point(5, 15, '?'));
	sv[2].reset(new circle(10, 10, 4, '@'));
	sv[3].reset(new circle(70, 10, 4, '@'));
	sv[4].reset(new line(40, 15, 40, 20, '|'));

	// rectangle_print(sv[0], c);
	// point_print(sv[1], c);
	// circle_print(sv[2], c);
	// circle_print(sv[3], c);
	// line_print(sv[4], c);

	for (size_t i = 0; i < n; ++i) {
		sv[i]->print(c);
	}

	c.out(std::cout);
}