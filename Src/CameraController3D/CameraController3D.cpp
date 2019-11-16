#include "CameraController3D.h"

using namespace godot;

void CameraController3D::_register_methods()
{
    register_method("_process", &CameraController3D::_process);
    register_method("_ready", &CameraController3D::_ready);

    register_property<CameraController3D, Variant>("camera", &CameraController3D::camera, Node::_new());
}