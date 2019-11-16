#include "BasicTest.h"
#include <Popup.hpp>

using namespace godot;

void BasicTest::_register_methods()
{
    register_method("_process", &BasicTest::_process);
}
BasicTest::BasicTest() {}
BasicTest::~BasicTest() {}

void BasicTest::_init()
{
    // initialize any variables here
    label = "test";
}

void BasicTest::_process(float delta)
{
    Godot::print(label);
    Popup *popupDialog = (Popup *)Node::get_node("PopupDialog");
    popupDialog->popup();
}