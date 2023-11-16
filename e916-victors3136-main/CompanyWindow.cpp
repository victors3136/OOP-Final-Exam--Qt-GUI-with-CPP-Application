//
// Created by victor on 28/06/2023.
//

#include "CompanyWindow.h"
#include <QBrush>
#include <QColor>
void CompanyWindow::updateData()
{
	populate();
}

void CompanyWindow::run()
{
	init();
	populate();
	connect();
	show();
}

void CompanyWindow::populate()
{
	allPackages->clear();
	for(const auto& package: cont.getPackages()){
		auto entry= new QListWidgetItem {(QString::fromStdString(package.getRecipient()+" "+package.getStreetName()+" "+
		std::to_string(package.getStreetNumber())+" "+std::to_string(package.getXCoord())+" "+std::to_string(package
		.getYCoord())))};
		if(package.isDelivered1())
			entry->setBackground(QBrush(QColor(Qt::green)));
		allPackages->addItem(entry);
	}
}

void CompanyWindow::connect()
{
	QObject::connect(submitButton, &QPushButton::clicked, [this](){
		addPackage();
	});
}

void CompanyWindow::addPackage()
{
	if(recipient->text().isEmpty()||street->text().isEmpty()){

		auto popup = new QMessageBox{};
		popup->setWindowTitle("Warning");
		popup->setIcon(QMessageBox::Warning);
		popup->setText("Empty boxes");
		popup->setDefaultButton(QMessageBox::Ok);
		popup->show();
		return;
	}
	std::string rec, str;
	int nr, _x, _y;

	rec=recipient->text().toStdString();recipient->clear();
	str=street->text().toStdString();street->clear();
	nr=number->text().toInt();number->clear();
	_x=x->text().toInt();x->clear();
	_y=y->text().toInt();y->clear();

	cont.addPackage(rec,str,nr,_x,_y);

}

void CompanyWindow::init(){
	setWindowTitle("Courier company");
	auto left = new QVBoxLayout;
	auto right = new QVBoxLayout;
	auto main = new QHBoxLayout;
	auto form = new QFormLayout;
	form->addRow("Recipient: ", recipient);
	form->addRow("Street Name: ", street);
	form->addRow("Street Number: ", number);
	form->addRow("X coordinate: ", x);
	form->addRow("Y coordinate: ", y);
	form->addWidget(submitButton);
	left->addLayout(form);
	right->addWidget(allPackages);
	main->addLayout(left);
	main->addLayout(right);
	setLayout(main);
}
