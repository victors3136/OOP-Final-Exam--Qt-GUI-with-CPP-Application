//
// Created by victor on 28/06/2023.
//

#include "CourierWindow.h"

void CourierWindow::run(){
	init();
	connect();
	populate();
	show();
}

void CourierWindow::connect(){
	QObject::connect(deliverButton, &QPushButton::clicked, [this](){
		if(undeliveredPackages->selectedItems().empty())
		{
			showError("No package selected");
			return ;}
		QString package = undeliveredPackages->selectedItems().at(0)->text();
		auto postSplit = package.split(" ");
		int x = postSplit[postSplit.length()-2].toInt();
		int y =  postSplit[postSplit.length()-1].toInt();
		controller.setDelivered(x,y);
	});
	QObject::connect(streets, &QComboBox::currentIndexChanged, [this](){
		undeliveredPackages->clear();
		std::string streetName = streets->currentText().toStdString();
		if(streetName == "All"){

			for(const auto& p: controller.getPackages()){
				if(!p.isDelivered1()){
					undeliveredPackages->addItem(QString::fromStdString(p.getRecipient()+" "+p.getStreetName
							()+" "+std::to_string(p.getStreetNumber())+" "+std::to_string(p.getXCoord())
					                                                    +" "+std::to_string(p.getYCoord())));

				}
			}
			return;
		}else
		for(const auto& package: controller.getPackages()){
			if(!package.isDelivered1()){
				if(package.getDistance(courier)<courier.getRadius()){
					undeliveredPackages->addItem(QString::fromStdString(package.getRecipient()+" "+package.getStreetName
							()+" "+std::to_string(package.getStreetNumber())+" "+std::to_string(package.getXCoord())
					                                                    +" "+std::to_string(package.getYCoord())));

				}else{
					for(const auto& s:courier.getStreets()){
						if(package.getStreetName() == s)
							undeliveredPackages->addItem(QString::fromStdString(package.getRecipient()+" "+package.getStreetName
									()+" "+std::to_string(package.getStreetNumber())+" "+std::to_string(package.getXCoord())
							                                                    +" "+std::to_string(package.getYCoord())));
					}
				}
			}
		}
	});
}

void CourierWindow::populate(){
	undeliveredPackages->clear();
	for(const auto&  street: courier.getStreets()){
		for(const auto& package: controller.getOnStreet(street)){
			if(package.getDistance(courier) <= courier.getRadius()&& !package.isDelivered1())
				undeliveredPackages->addItem(QString::fromStdString(package.getRecipient()+" "+package.getStreetName
						()+" "+std::to_string(package.getStreetNumber())+" "+std::to_string(package.getXCoord())+" "
				                                                                                                 ""+std::to_string(package.getYCoord())));
		}
	}
	streets->addItem("All");
	for(const auto & street: controller.getStreets()){
		streets->addItem(QString::fromStdString(street));
	}

}

void CourierWindow::init(){
	setWindowTitle(QString::fromStdString(courier.getName()));
	auto left = new QVBoxLayout;
	auto right = new QVBoxLayout;
	auto center = new QVBoxLayout;
	auto layout = new QHBoxLayout;
	left->addWidget(new QLabel(QString::fromStdString(courier.getStreetsAsString()+"\n("+std::to_string(courier
	.getCenterX())+"; "+std::to_string(courier.getCenterY())+")-> "+std::to_string(courier.getRadius()))));
	center->addWidget(streets);
	center->addWidget(undeliveredPackages);
	right->addWidget(deliverButton);
	layout->addLayout(left);
	layout->addLayout(center);
	layout->addLayout(right);
	setLayout(layout);
}

void CourierWindow::showError(const char *message){
	auto popup = new QMessageBox{};
	popup->setWindowTitle("Warning");
	popup->setIcon(QMessageBox::Warning);
	popup->setText(message);
	popup->setDefaultButton(QMessageBox::Ok);
	popup->show();
};


