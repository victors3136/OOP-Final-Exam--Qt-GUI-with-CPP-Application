//
// Created by victor on 28/06/2023.
//

#ifndef E916_VICTORS3136_SUBJECTBASE_H
#define E916_VICTORS3136_SUBJECTBASE_H

#include "AbstractObserver.h"
#include <vector>
class SubjectBase
{
	std::vector<AbstractObserver*>observers;
public:
	void registerObserver(AbstractObserver* o){
		observers.push_back(o);
	}
	void notify(){
		for(const auto& o: observers){
			o->updateData();
		}
	}
	~SubjectBase(){
		for(auto o:observers)
			delete o;
	}
};


#endif //E916_VICTORS3136_SUBJECTBASE_H
