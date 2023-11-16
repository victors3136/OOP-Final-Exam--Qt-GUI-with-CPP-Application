//
// Created by victor on 28/06/2023.
//

#include "Courier.h"

Courier::Courier(const std::string &name, const std::vector<std::string> &streets, int centerX, int centerY, int radius)
		: name(name), streets(streets), center_x(centerX), center_y(centerY), radius(radius)
{}

const std::string &Courier::getName() const
{
	return name;
}

void Courier::setName(const std::string &name)
{
	Courier::name = name;
}

const std::vector<std::string> &Courier::getStreets() const
{
	return streets;
}

void Courier::setStreets(const std::vector<std::string> &streets)
{
	Courier::streets = streets;
}

int Courier::getCenterX() const
{
	return center_x;
}

void Courier::setCenterX(int centerX)
{
	center_x = centerX;
}

int Courier::getCenterY() const
{
	return center_y;
}

void Courier::setCenterY(int centerY)
{
	center_y = centerY;
}

int Courier::getRadius() const
{
	return radius;
}

void Courier::setRadius(int radius)
{
	Courier::radius = radius;
}

std::ostream &operator<<(std::ostream &os, const Courier &courier)
{
	os << courier.name << ";";
	for(const auto& streetName:courier.streets){
		os<< streetName <<"|";
	}
	os <<";"<< courier.center_x<< ";" << courier.center_y << ";" << courier.radius;
	return os;
}
std::istream &operator>>(std::istream &is,  Courier &courier){
	std::string n,x_str,y_str,r_str;
	std::vector<std::string> streets;
	std::getline(is, n,';');
	if(n.empty())return is;

	while(is.peek()!=';'&&is.peek()!='\n'&&!is.eof()){
		std::string s;
		std::getline(is, s,'|');
		streets.push_back(s);
	}
	if(is.peek()==';')is.get();
	std::getline(is,x_str,';');
	std::getline(is,y_str,';');
	std::getline(is,r_str);
	if(n.empty()||streets.empty()||x_str.empty()||y_str.empty()||r_str.empty())
		return is;

	courier.name = n;
	courier.streets= streets;
	courier.center_x=std::stoi(x_str);
	courier.center_y=std::stoi(y_str);
	courier.radius=std::stoi(r_str);
	return is;
}