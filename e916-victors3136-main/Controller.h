//
// Created by victor on 28/06/2023.
//

#ifndef E916_VICTORS3136_CONTROLLER_H
#define E916_VICTORS3136_CONTROLLER_H


#include <algorithm>
#include "SubjectBase.h"
#include "Repository.h"

class Controller: public SubjectBase
{
	Repository& repository;
public:
	explicit Controller(Repository& r): repository(r){};
	std::vector<Courier> &getCouriers(){
		return repository.getCouriers();
	}
	std::vector<Package> &getPackages(){
		return repository.getPackages();
	}
	std::vector<Package> getUndeliveredPackages(){
		std::vector<Package> undelivered;
		std::copy_if(repository.getPackages().begin(), repository.getPackages().end(), std::back_inserter
		(undelivered), [](const Package& p){
			return !p.isDelivered1();
		});
		return undelivered;
	}
	std::vector<std::string> getStreets(){
		std::vector<Package>packagesWithUniqueStreets;
		std::vector<std::string> streetNames;
		std::copy_if(repository.getPackages().begin(), repository.getPackages().end(), std::back_inserter
		(packagesWithUniqueStreets),
					 [streetNames](const Package p){
			return std::find(streetNames.begin(), streetNames.end(), p.getStreetName()) == streetNames.end();
		});
		for(const auto& p: packagesWithUniqueStreets){
			streetNames.push_back(p.getStreetName());
		}
		return streetNames;
	};
	void addPackage(std::string recipient,std::string street, int nr, int x_coord, int y_coord){
		Package p{recipient, street, nr, x_coord, y_coord, false};
		repository.addPackage(p);
		notify();
	};
	std::vector<Package> getOnStreet(std::string streetName){
		std::vector<Package> packagesOnStreet;
		std::copy_if(repository.getPackages().begin(), repository.getPackages().end(), std::back_inserter
		(packagesOnStreet),[streetName](const Package& p){
			return p.getStreetName()==streetName;
		});
		return packagesOnStreet;
	};
	void setDelivered(int x, int y){
		auto it = std::find_if(repository.getPackages().begin(), repository.getPackages().end(), [x,y](const Package&p){
			return p.getXCoord()==x&&p.getYCoord()==y;
		});
		if(it!=repository.getPackages().end()){
			it->setIsDelivered(true);
			notify();
		}
		notify();
	}

};


#endif //E916_VICTORS3136_CONTROLLER_H
