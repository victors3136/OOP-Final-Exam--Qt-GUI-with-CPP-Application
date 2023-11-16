//
// Created by victor on 28/06/2023.
//

#include "Repository.h"

#include <utility>

Repository::Repository(std::string courierFile, std::string packageFile) : courierFile(std::move(courierFile)),
                                                                                         packageFile(std::move(packageFile))
{
	readFromFile();
}

std::vector<Courier>& Repository::getCouriers()
{
	return couriers;
}


std::vector<Package> &Repository::getPackages()
{
	return packages;
}

Repository::~Repository()
{
	writeToFile();
}

