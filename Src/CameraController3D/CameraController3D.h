#ifndef CAMERA_CONTROLLER_3D_H
#define CAMERA_CONTROLLER_3D_H

#include <Godot.hpp>
#include <Node.hpp>

namespace godot
{
class CameraController3D : public Node
{
    GODOT_CLASS(CameraController3D, Node);

private:
    Variant camera;

public:
    static void _register_methods();

    CameraController3D();
    ~CameraController3D();

    void _init();

    void _process(float delta);
    void _ready();
};
} // namespace godot
#endif