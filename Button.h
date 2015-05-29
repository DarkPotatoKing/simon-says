#include <gtkmm/button.h>
#include <gtkmm/image.h>

class Button : public Gtk::Button
{
public:
	Gtk::Image def;
	Gtk::Image clk;
};