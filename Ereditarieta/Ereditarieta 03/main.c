#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>

#include "canvas.h"
#include <string.h>
#include <stdlib.h>

typedef struct shape {
	char *type_;
	int x_, y_;
	char ch_;
} shape;
shape *shape_create(shape *this, const char *type, int x, int y, char ch) {
	this->type_ = strcpy(malloc(strlen(type) + 1), type);
	this->x_ = x;
	this->y_ = y;
	this->ch_ = ch;
	return this;
}
shape *shape_destroy(shape *this) {
	free(this->type_);
	return this;
}
shape *new_shape(const char *type, int x, int y, char ch) {
	return shape_create(malloc(sizeof(shape)), type, x, y, ch);
}
void delete_shape(shape *this) {
	free(shape_destroy((shape*)this));
}
void shape_print(const shape *this, canvas *c) {
	canvas_set(c, this->x_, this->y_, this->ch_); // Solo per debug

	// if (strcmp(this->type_, "point") == 0) {
	// }
	// else if (strcmp(this->type_, "line") == 0) {
	// }
	// else if (strcmp(this->type_, "rectangle") == 0) {
	// }
	// else if (strcmp(this->type_, "circle") == 0) {
	// }
}

typedef struct point {
	shape base;
} point;
point *point_create(point *this, int x, int y, char ch) {
	shape_create((shape*)this, "point", x, y, ch);
	return this;
}
point *point_destroy(point *this) {
	shape_destroy((shape*)this);
	return this;
}
point *new_point(int x, int y, char ch) {
	return point_create(malloc(sizeof(point)), x, y, ch);
}
void delete_point(point *this) {
	free(point_destroy(this));
}
void point_print(const point *this, canvas *c) {
	canvas_set(c, this->base.x_, this->base.y_, this->base.ch_);
}

typedef struct line {
	shape base;
	int x1_, y1_;
} line;
line *line_create(line *this, int x0, int y0, int x1, int y1, char ch) {
	shape_create((shape*)this, "line", x0, y0, ch);
	this->x1_ = x1;
	this->y1_ = y1;
	return this;
}
line *line_destroy(line *this) {
	shape_destroy((shape*)this);
	return this;
}
line *new_line(int x0, int y0, int x1, int y1, char ch) {
	return line_create(malloc(sizeof(line)), x0, y0, x1, y1, ch);
}
void delete_line(line *this) {
	free(line_destroy(this));
}
void line_print(const line *this, canvas *c) {
	canvas_line(c, this->base.x_, this->base.y_, this->x1_, this->y1_, this->base.ch_);
}

typedef struct rectangle {
	shape base;
	int x1_, y1_;
} rectangle;
rectangle *rectangle_create(rectangle *this, int x0, int y0, int x1, int y1, char ch) {
	shape_create((shape*)this, "rectangle", x0, y0, ch);
	this->x1_ = x1;
	this->y1_ = y1;
	return this;
}
rectangle *rectangle_destroy(rectangle *this) {
	shape_destroy((shape*)this);
	return this;
}
rectangle *new_rectangle(int x0, int y0, int x1, int y1, char ch) {
	return rectangle_create(malloc(sizeof(rectangle)), x0, y0, x1, y1, ch);
}
void delete_rectangle(rectangle *this) {
	free(rectangle_destroy(this));
}
void rectangle_print(const rectangle *this, canvas *c) {
	canvas_rectangle(c, this->base.x_, this->base.y_, this->x1_, this->y1_, this->base.ch_);
}

typedef struct circle {
	shape base;
	int r_;
} circle;
circle *circle_create(circle *this, int x0, int y0, int r, char ch) {
	shape_create((shape*)this, "circle", x0, y0, ch);
	this->r_ = r;
	return this;
}
circle *circle_destroy(circle *this) {
	shape_destroy((shape*)this);
	return this;
}
circle *new_circle(int x0, int y0, int r, char ch) {
	return circle_create(malloc(sizeof(circle)), x0, y0, r, ch);
}
void delete_circle(circle *this) {
	free(circle_destroy(this));
}
void circle_print(const circle *this, canvas *c) {
	canvas_circle(c, this->base.x_, this->base.y_, this->r_, this->base.ch_);
}

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
	canvas* c = new_canvas(80, 25);

	rectangle *s1 = new_rectangle(0,0,79,24,'*');
	point *s2 = new_point(5, 15, '?');
	circle *s3 = new_circle(10, 10, 4, '@');
	circle *s4 = new_circle(70, 10, 4, '@');
	line *s5 = new_line(40, 15, 40, 20, '|');

/*
	size_t n = 0;
	shape **sv = read_shapes(stdin, &n);

	for (size_t i = 0; i < n; ++i) {
		shape_print(sv[i], c);
	}
*/
	canvas_out(c, stdout);
/*
	for (size_t i = 0; i < n; ++i) {
		delete_shape(sv[i]);
	}*/
	delete_canvas(c);
}