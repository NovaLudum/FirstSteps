#include "BasicTest.h"

using namespace godot;

void BasicTest::_register_methods() {
    register_method("_process", &BasicTest::_process);
}
BasicTest::BasicTest() {}
BasicTest::~BasicTest() {}

void BasicTest::_init() {
    // initialize any variables here
    label = "Hello World";
}

void BasicTest::_process(float delta) {
    printf("%s", label.c_str());
}