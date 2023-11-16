//
// Created by victor on 28/06/2023.
//

#include "Package.h"

Package::Package()
{}

Package::Package(const std::string &recipient, const std::string &streetName, int streetNumber, int xCoord, int yCoord,
                 bool isDelivered) : recipient(recipient), streetName(streetName), streetNumber(streetNumber),
                                     x_coord(xCoord), y_coord(yCoord), isDelivered(isDelivered)
{}

std::ostream &operator<<(std::ostream &os, const Package &aPackage)
{
	os << aPackage.recipient << ";" << aPackage.streetName << ";"
	   << aPackage.streetNumber << ";" << aPackage.x_coord << ";" << aPackage.y_coord
	   << ";" << aPackage.isDelivered;
	return os;
}

std::istream &operator>>(std::istream &is, Package &aPackage)
{
	std::string recipient, streetName, streetNum, x_str,y_str,delivered_str;
	std::getline(is, recipient,';');
	std::getline(is, streetName,';');
	std::getline(is, streetNum,';');
	std::getline(is, x_str,';');
	std::getline(is, y_str,';');
	std::getline(is, delivered_str);
	if(recipient.empty()||streetName.empty()||streetNum.empty()||x_str.empty()||y_str.empty()||delivered_str.empty())
		return is;
	aPackage.recipient=recipient;
	aPackage.streetName=streetName;
	aPackage.streetNumber=std::stoi(streetNum);
	aPackage.x_coord= std::stoi(x_str);
	aPackage.y_coord=std::stoi(y_str);
	aPackage.isDelivered = (bool)std::stoi(delivered_str);
	return is;
}

const std::string &Package::getRecipient() const
{
	return recipient;
}

void Package::setRecipient(const std::string &recipient)
{
	Package::recipient = recipient;
}

const std::string &Package::getStreetName() const
{
	return streetName;
}

void Package::setStreetName(const std::string &streetName)
{
	Package::streetName = streetName;
}

int Package::getStreetNumber() const
{
	return streetNumber;
}

void Package::setStreetNumber(int streetNumber)
{
	Package::streetNumber = streetNumber;
}

int Package::getXCoord() const
{
	return x_coord;
}

void Package::setXCoord(int xCoord)
{
	x_coord = xCoord;
}

int Package::getYCoord() const
{
	return y_coord;
}

void Package::setYCoord(int yCoord)
{
	y_coord = yCoord;
}

bool Package::isDelivered1() const
{
	return isDelivered;
}

void Package::setIsDelivered(bool isDelivered)
{
	Package::isDelivered = isDelivered;
}

