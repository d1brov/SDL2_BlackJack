#pragma once

#include "Surface.h"

class Window;

class Drawable {
	friend Window;

public:
	Drawable() = delete;
	Drawable(Rectangle rectangle, double angle = 0);
	virtual ~Drawable() = default;
	virtual Surface* GetSurface() = 0;

	double GetAngle() const;
	Dimensions GetDimensions() const;
	Point GetPosition() const;
	Rectangle GetRectangle() const;

	void SetAngle(double angle);
	void SetDimensions(Dimensions dimensions);
	void SetPosition(Point position);
	void SetRectangle(Rectangle rectangle);

private:
	Rectangle rectangle_{};
	double angle_{};
};