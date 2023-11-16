//
// Created by victor on 28/06/2023.
//

#ifndef E916_VICTORS3136_REPOSITORY_H
#define E916_VICTORS3136_REPOSITORY_H
#include <fstream>
#include "Courier.h"
#include "Package.h"
class Repository
{
	std::string courierFile, packageFile;
	std::vector<Courier> couriers;
	std::vector<Package> packages;
//	void writeFile(){
//		std::ofstream fout {""}
//	}
	void readFromFile(){
		std::ifstream fin ;
		fin.open(courierFile);
		Courier c;
		while(fin>>c){
			if(c.getName().empty())
				break;
			couriers.push_back(c);
			Courier newCourier;
			c=newCourier;
		}
		fin.close();
		fin.open(packageFile);
		Package p;
		while(fin>>p){
			if(p.getRecipient().empty())break;
			packages.push_back(p);
			Package newPackage;
			p=newPackage;

		}
		fin.close();
	}
	void writeToFile(){
		std::ofstream fout { packageFile } ;
		for(const auto& p: packages){
			fout<<p<<std::endl;
		}
		fout.close();
	}
public:
	Repository(std::string courierFile, std::string packageFile);
	~Repository();
	[[nodiscard]] std::vector<Courier> &getCouriers();

	[[nodiscard]] std::vector<Package> &getPackages();
	void addPackage(Package p){
		packages.push_back(p);
	}
};


#endif //E916_VICTORS3136_REPOSITORY_H
