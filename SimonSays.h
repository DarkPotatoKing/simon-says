#ifndef SIMONSAYS_H
#define SIMONSAYS_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

#include "Button.h"

class SimonSays : public Gtk::Window
{
public:
	SimonSays();
	virtual ~SimonSays();
protected:
	void start_clicked();


	Gtk::Box box;
	Gtk::Box row;
	Button buttons[4];
	Button start;
};

#endif