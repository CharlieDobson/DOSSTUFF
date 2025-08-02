// label.hpp : label definition file for DOSForms

#ifndef LABEL_HPP
#define LABEL_HPP 1

#include "control.hpp"

// Label control
//
// Derived from Control; implement specific rendering
// and behavior
//
class Label : public Control {
public:
    char text[32]; // Fixed-size string
    void (*OnClick)();

    virtual void Draw();
    virtual void HandleInput(int key);
};

#endif