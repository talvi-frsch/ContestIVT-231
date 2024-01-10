#include <iostream>

// Ваш код здесь
class Vector;

class Point {
public:
    int x, y;

	Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
	void move(const Vector& v); 
};

class Vector {
public:
	int x, y;

	Vector(const Point& startPoint, const Point& endPoint) {
		x = endPoint.x - startPoint.x;
		y = endPoint.y - startPoint.y;
	}
};

void Point::move(const Vector& v) {
	x += v.x;
	y += v.y;
}
// Конец вашего кода
int main(){
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    Point p(x1, y1);
    Vector dir(Point(x2, y2), Point(x3, y3));
    p.move(dir);
    
    std::cout << p.x << ' ' << p.y;
}
