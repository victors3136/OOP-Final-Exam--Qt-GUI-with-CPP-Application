//
// Created by victor on 28/06/2023.
//

#ifndef E916_VICTORS3136_COURIERWINDOW_H
#define E916_VICTORS3136_COURIERWINDOW_H


#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include "AbstractObserver.h"
#include "Courier.h"
#include "Controller.h"

class CourierWindow: public QWidget, public AbstractObserver
{
	Courier& courier;
	Controller& controller;
	QListWidget* undeliveredPackages{new QListWidget};
	QPushButton* deliverButton{new QPushButton{"Deliver"}};
	QComboBox* streets { new QComboBox };
	void showError(const char* message);
	void init();
	void populate();
	void connect();
public:
	CourierWindow(Courier&  c, Controller& cont): courier(c), controller(cont){};
	void updateData() override{
		streets->clear();
		populate();
	};
	void run();

};


#endif //E916_VICTORS3136_COURIERWINDOW_H
