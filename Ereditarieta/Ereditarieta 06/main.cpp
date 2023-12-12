#define _CRT_SECURE_NO_WARNINGS

#include "canvas.h"
#include <string>
#include <iostream>
#include <fstream>
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
	}

	virtual ~shape() = default;
	virtual void print(canvas& c) const = 0;
};

struct point : public shape {
	point(int x, int y, char ch): shape("point", x, y, ch) {}

	void print(canvas& c) const override {
		c.set(x_, y_, ch_);
	}
};

struct line: public shape {
	int x1_, y1_;

	line(int x0, int y0, int x1, int y1, char ch) 
		: shape("line", x0, y0, ch), x1_(x1), y1_(y1) {}

	void print(canvas& c) const override {
		c.line(x_, y_, x1_, y1_, ch_);
	}
};

struct rectangle : public shape {
	int x1_, y1_;

	rectangle(int x0, int y0, int x1, int y1, char ch) 
		: shape("rectangle", x0, y0, ch), x1_(x1), y1_(y1) {}

	void print(canvas& c) const override {
		c.rectangle(x_, y_, x1_, y1_, ch_);
	}
};

struct circle : public shape {
	int r_;

	circle(int x0, int y0, int r, char ch)
		: shape("circle", x0, y0, ch), r_(r) {}

	void print(canvas& c) const override {
		c.circle(x_, y_, r_, ch_);
	}
};

std::vector<std::unique_ptr<shape>> read_shapes(const std::string& filename)
{
	std::vector<std::unique_ptr<shape>> sv;
	return sv;
}

int main(void)
{
	using namespace std;

	canvas c(80, 25);

	auto sv = read_shapes("drawing1.txt");

	for (const auto& x : sv) {
		x->print(c);
	}

	c.out(std::cout);
}