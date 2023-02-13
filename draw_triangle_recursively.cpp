#include <iostream>

void draw_triangle(int32_t _radius)
{
	static const int32_t boudary{_radius};
	static int32_t counter{};

	if (_radius > 0 and _radius != boudary)
	{
		std::cout<< "*";
		draw_triangle(--_radius);
	}
	else if (counter < boudary)
	{
		std::cout<< "\n\t\t\t"; // because you can't see it :D
		draw_triangle(++counter);
	}
}

int main()
{
	
	draw_triangle(10); // radius = 10
	std::cout<< "\n";

}
