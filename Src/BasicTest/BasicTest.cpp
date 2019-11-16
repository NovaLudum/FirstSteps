#include "BasicTest.h"

using namespace godot;

void BasicTest::_register_methods() {
    register_method("_process", &BasicTest::_process);
}
BasicTest::BasicTest() {}
BasicTest::~BasicTest() {}

void BasicTest::_init() {
    // initialize any variables here
}

void BasicTest::_process(float delta) {
    auto msg = api->godot_string_chars_to_utf8("Test string from c++");
    //godot_variant godotMsg;
    //api->godot_variant_new_string(&godotMsg, &msg);
    //godot_print(&msg);
    api->godot_print(&msg);
}