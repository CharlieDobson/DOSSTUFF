// Control.hpp : Control definition file for DOSForms

#ifndef CONTROL_HPP
#define CONTROL_HPP 1

// Base Control class
//
// Abstract base for all UI elements (buttons, labels, etc)
//
class Control {
public:
    unsigned int x, y, width, height;
    Control* next; // Linked list of controls

    virtual void Draw() = 0;
    virtual void HandleInput(int key) = 0;
};

#endif