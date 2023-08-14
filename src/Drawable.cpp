#include "Drawable.h"

Drawable::Drawable(Rectangle rectangle, double angle) 
	: rectangle_(rectangle)
	, angle_(angle){
}

double Drawable::GetAngle() const {
	return angle_;
}

Dimensions Drawable::GetDimensions() const {
	return { rectangle_.w, rectangle_.h };
}

Point Drawable::GetPosition() const {
	return { rectangle_.x, rectangle_.y };
}

Rectangle Drawable::GetRectangle() const {
	return rectangle_;
}

void Drawable::SetAngle(double angle) {
	angle_ = angle;
}

void Drawable::SetDimensions(Dimensions dimensions) {
	rectangle_.w = dimensions.w;
	rectangle_.h = dimensions.h;
}

void Drawable::SetPosition(Point position) {
	rectangle_.x = position.x;
	rectangle_.y = position.y;
}

void Drawable::SetRectangle(Rectangle rectangle) {
	rectangle_ = rectangle;
}