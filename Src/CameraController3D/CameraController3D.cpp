#include "CameraController3D.h"
#include "../Common/Common.h"

using namespace godot;

void CameraController3D::_register_methods()
{
    register_method("_input", &CameraController3D::_input);
    register_method("_ready", &CameraController3D::_ready);
    register_method("_physics_process", &CameraController3D::_physics_process);

    register_property<CameraController3D, NodePath>("camera", &CameraController3D::setCamera, &CameraController3D::getCamera, NodePath(""));
    register_property<CameraController3D, float>("rotation speed", &CameraController3D::CAMERA_ROTATION_SPEED, 0.001);
}

void CameraController3D::_init()
{
    Godot::print("CameraController3D::_init");
    Input::get_singleton()->set_mouse_mode(Input::MOUSE_MODE_CAPTURED);
}

void CameraController3D::_ready()
{
    orientation = camera->get_global_transform();
    orientation.set_origin(Vector3());
}

void CameraController3D::_input(const godot::Ref<godot::InputEvent> event)
{
    const InputEvent *input = event.ptr();
    if (event->get_class() == CameraController3D::INPUT_MOUSE_MOTION && !cursorActive)
    {
        InputEventMouseMotion *i = Object::cast_to<InputEventMouseMotion>(input);
        camera->rotate_y(i->get_relative().x * CAMERA_ROTATION_SPEED);
        camera->orthonormalize();
        cameraXRotation = std::clamp(cameraXRotation + i->get_relative().y * CAMERA_ROTATION_SPEED, Common::deg2rad<float>(CAMERA_X_ROTATION_MIN), Common::deg2rad<float>(CAMERA_X_ROTATION_MAX));
        camera->set_rotation(Vector3(cameraXRotation, camera->get_rotation().y, camera->get_rotation().z));
    }
    else if (input->get_class() == CameraController3D::INPUT_MOUSE_BUTTON)
    {
        Godot::print("Mouse button klick");
    }
    else if (input->get_class() == CameraController3D::INPUT_KEY)
    {
        if (input->is_action_pressed("alt"))
        {
            cursorActive = !cursorActive;
            Godot::print("Alt was pressed");
            if (cursorActive)
            {
                Input::get_singleton()->set_mouse_mode(Input::MOUSE_MODE_VISIBLE);
                Input::get_singleton()->set_mouse_mode(Input::MOUSE_MODE_CONFINED);
            }
            else
            {
                Input::get_singleton()->set_mouse_mode(Input::MOUSE_MODE_HIDDEN);
                Input::get_singleton()->set_mouse_mode(Input::MOUSE_MODE_CAPTURED);
            }
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

void CameraController3D::_physics_process(float delta)
{
}