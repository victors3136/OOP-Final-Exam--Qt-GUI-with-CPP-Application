#include <QApplication>
#include <QPushButton>
#include "Repository.h"
#include "Controller.h"
#include "CourierWindow.h"
#include "CompanyWindow.h"

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	Repository repo {"Couriers" , "Packages"};

	Controller controller {repo};
	for(auto& courier:controller.getCouriers()){
		auto* window = new CourierWindow(courier, controller);
		controller.registerObserver(window);
		window->run();
	}
	auto* controllerWindow= new CompanyWindow(controller);
	controller.registerObserver(controllerWindow);
	controllerWindow->run();
	return QApplication::exec();
}
