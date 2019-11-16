#ifndef BASICTEST_H
#define BASICTEST_H

#include <Godot.hpp>
#include <Node.hpp>
#include <string>

namespace godot{

class BasicTest : public Node {
    GODOT_CLASS(BasicTest, Node);

private:
    godot_string label;

public:
    static void _register_methods();

    BasicTest();
    ~BasicTest();

    void _init();

    void _process(float delta);
};
}
#endif