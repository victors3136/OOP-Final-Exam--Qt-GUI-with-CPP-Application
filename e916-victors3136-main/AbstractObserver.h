//
// Created by victor on 28/06/2023.
//

#ifndef E916_VICTORS3136_ABSTRACTOBSERVER_H
#define E916_VICTORS3136_ABSTRACTOBSERVER_H


class AbstractObserver
{
public:
	virtual void updateData()=0;
	virtual ~AbstractObserver(){};
};


#endif //E916_VICTORS3136_ABSTRACTOBSERVER_H
