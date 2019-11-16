#include "CameraController3D.h"
#include "../Common/Common.h"

using namespace godot;

void CameraController3D::_register_methods()
{
    register_method("_input", &CameraController3D::_input);
    register_method("_ready", &CameraController3D::_ready);

    register_property<CameraController3D, NodePath>("camera", &CameraController3D::setCamera, &CameraController3D::getCamera, NodePath(""));
    register_property<CameraController3D, float>("rotation speed", &CameraController3D::CAMERA_ROTATION_SPEED, 0.001);
}

void CameraController3D::_init()
{
    Godot::print("CameraController3D::_init");
}

void CameraController3D::_ready()
{
    orientation = camera->get_global_transform();
    orientation.set_origin(Vector3());
}

void CameraController3D::_input(const godot::Ref<godot::InputEvent> event)
{
    const InputEvent *input = event.ptr();
    if (event->get_class() == CameraController3D::INPUT_MOUSE_MOTION)
    {
        InputEventMouseMotion *i = Object::cast_to<InputEventMouseMotion>(input);
        Godot::print("Mouse movement");
        camera->rotate_y(-i->get_relative().x * CAMERA_ROTATION_SPEED);
        camera->orthonormalize();
        cameraXRotation = std::clamp(cameraXRotation + i->get_relative().y * CAMERA_ROTATION_SPEED, CAMERA_X_ROTATION_MIN, CAMERA_X_ROTATION_MAX);
        camera->set_rotation(Vector3(cameraXRotation, camera->get_rotation().y, camera->get_rotation().z));
    }
    else if (input->get_class() == CameraController3D::INPUT_MOUSE_BUTTON)
    {
        Godot::print("Mouse button klick");
    }
    else if (input->get_class() == CameraController3D::INPUT_KEY)
    {
        if(input->is_action_pressed("alt"))
        {
            Godot::print("Alt was pressed");
        }
    }

    Godot::print(input->as_text());
}

void CameraController3D::setCamera(NodePath nodePath)
{
    if (nodePath.is_empty())
    {
        Godot::print("[Error] ");
    }
    camera = (Camera *)Node::get_node(nodePath);
}
NodePath CameraController3D::getCamera() const
{
    return camera->get_path();
}