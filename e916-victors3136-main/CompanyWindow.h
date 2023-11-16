//
// Created by victor on 28/06/2023.
//

#ifndef E916_VICTORS3136_COMPANYWINDOW_H
#define E916_VICTORS3136_COMPANYWINDOW_H

#include <QMessageBox>
#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include "AbstractObserver.h"
#include "Controller.h"

class CompanyWindow: public QWidget, public AbstractObserver
{
	Controller& cont;
	QListWidget* allPackages{new QListWidget};
	QLineEdit* recipient{new QLineEdit}, *street{new QLineEdit},* number{new QLineEdit},* x{new QLineEdit},* y{new
	QLineEdit};
	QPushButton* submitButton {new QPushButton {"Submit"}};
	void init();
	void populate();
	void connect();
public:
	CompanyWindow(Controller& c): cont(c){};
	void updateData()override;
	void run();
	void addPackage();
};


#endif //E916_VICTORS3136_COMPANYWINDOW_H
