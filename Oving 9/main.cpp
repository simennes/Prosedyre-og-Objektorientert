#include <iostream>
#include "Car.h"
#include "Person.h"
#include "Meeting.h"
#include "MeetingWindow.h"

int main()
{
	
	Person p1{"Rune", "morrapuler@online.no"};
	std::cout << p1;
	Car espenBil{4};

	Person espen{"Espen", "noobmail@prostata.org", std::make_unique<Car>(espenBil)};
	std::cout << "\n" << espen;

	const std::shared_ptr<Person> leader = std::make_shared<Person>(std::move(p1));
	Meeting m1{3, 8, 12, Campus::Trondheim, "Banebrytende forskning paa hemoroider", leader};
	std::shared_ptr<Person> p2 = std::make_shared<Person>("Adolf", "Adolf.Art@DDR.de");
	std::shared_ptr<Person> p3 = std::make_shared<Person>("Espen", "noobmail@prostata.org", std::make_unique<Car>(espenBil));
	m1.addParticipant(p2);
	m1.addParticipant(p3);
	std::cout << "\n\n";
	std::cout << m1 << "\n\n";

	
	MeetingWindow mw(100, 100, 600, 300, "Meeting Planner");
	gui_main();
	mw.printPeople();
}
