// form.hpp : form definition file for DOSForms

#ifndef FORM_HPP
#define FORM_HPP 1

#include "control.hpp"


// Form class to contain controls
//
// Represents a window; manages layout,
// controls, and input focus
//
class Form {
public:
    Control* controls; // Head of linked list

    Form() : controls(0) {}

    void AddControl(Control* ctrl) {
        ctrl->next = controls;
        controls = ctrl;
    }

    void Draw() {
        for (Control* c = controls; c; c = c->next)
            c->Draw();
    }

    void HandleInput(int key) {
        for (Control* c = controls; c; c = c->next)
            c->HandleInput(key);
    }
};

#endif