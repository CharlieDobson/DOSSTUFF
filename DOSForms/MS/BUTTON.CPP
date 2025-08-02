// button.cpp : button implementation file for DOSForms

#include "button.hpp"

void Button::Draw() {
    // Draw button using DOS graphics/text functions
}

void Button::HandleInput(int key) {
    // If key matches "Enter" or mouse click, call OnClick
    if (key == /* Enter key code */ && OnClick)
        OnClick();
}