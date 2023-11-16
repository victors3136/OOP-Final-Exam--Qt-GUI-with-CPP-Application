//
// Created by victor on 28/06/2023.
//

#ifndef E916_VICTORS3136_COURIER_H
#define E916_VICTORS3136_COURIER_H
#include <string>
#include <vector>
#include <iostream>

class Courier
{
	std::string name{};
	std::vector<std::string> streets{};
	int center_x{}, center_y{}, radius{};
public:
	Courier()=default;
	Courier(const std::string &name, const std::vector<std::string> &streets, int centerX, int centerY, int radius);

	const std::string &getName() const;

	void setName(const std::string &name);

	const std::vector<std::string> &getStreets() const;

	void setStreets(const std::vector<std::string> &streets);

	int getCenterX() const;

	void setCenterX(int centerX);

	int getCenterY() const;

	void setCenterY(int centerY);

	int getRadius() const;

	void setRadius(int radius);

	friend std::ostream &operator<<(std::ostream &os, const Courier &courier);

	friend std::istream &operator>>(std::istream &is,  Courier &courier);

	std::string getStreetsAsString(){
		std::string returnString;
		for(const  auto& street: streets){
			returnString+=street;
			returnString+='\n';
		}
		return returnString;
	}
};


#endif //E916_VICTORS3136_COURIER_H
