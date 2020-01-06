
template <class TCoordinates>
struct Coordinates
{
	Coordinates(){ x = 3000; y = 3000; }
	Coordinates(const TCoordinates &_x, const TCoordinates &_y) : x(_x), y(_y){ }
	Coordinates operator+(const Coordinates &_temp) const { return Coordinates(_temp.x + x, _temp.y + y); }

	TCoordinates x, y;
};

struct Offset
{
	Offset(){ distance = 0; degree = 0; }
	Offset(const float _distance, const float _degree) : degree(_degree), distance(_degree){ }

	double distance, degree;
};


template <class TArea>
struct Area
{
	Area(){ x = 10; y = 10; }
	Area(const TArea &_x, const TArea &_y) : x(_x), y(_y) { }
	TArea getArea(){ return x*y; };

	TArea x, y;
};
