//
// Created by victor on 28/06/2023.
//

#ifndef E916_VICTORS3136_PACKAGE_H
#define E916_VICTORS3136_PACKAGE_H
#include <string>
#include <iostream>
#include <cmath>
#include "Courier.h"

class Package
{
	std::string recipient, streetName;
	int streetNumber,x_coord,y_coord;
	bool isDelivered;
public:
	Package();

	Package(const std::string &recipient, const std::string &streetName, int streetNumber, int xCoord, int yCoord,
	        bool isDelivered);

	const std::string &getRecipient() const;

	void setRecipient(const std::string &recipient);

	const std::string &getStreetName() const;

	void setStreetName(const std::string &streetName);

	int getStreetNumber() const;

	void setStreetNumber(int streetNumber);

	int getXCoord() const;

	void setXCoord(int xCoord);

	int getYCoord() const;

	void setYCoord(int yCoord);

	bool isDelivered1() const;

	void setIsDelivered(bool isDelivered);

	friend std::ostream &operator<<(std::ostream &os, const Package &aPackage);

	friend std::istream &operator>>(std::istream &is, Package &aPackage);

	Package& operator=(const Package& other){
		recipient=other.recipient;
		streetName=other.streetName;
		streetNumber=other.streetNumber;
		x_coord=other.x_coord;
		y_coord=other.y_coord;
		isDelivered=other.isDelivered;
		return *this;
	};
	bool operator==(const Package& other) const{
		return x_coord==other.x_coord&&y_coord==other.y_coord;
	}
	double getDistance(Courier& c) const{
		return sqrt((c.getCenterX()-x_coord)*(c.getCenterX()-x_coord)+(c.getCenterY()-y_coord)*(c.getCenterY()-y_coord));
	}
};


#endif //E916_VICTORS3136_PACKAGE_H
