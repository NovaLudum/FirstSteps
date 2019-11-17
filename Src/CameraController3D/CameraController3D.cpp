#include "CameraController3D.h"
#include "../Common/Common.h"

using namespace godot;

void CameraController3D::_register_methods()
{
    register_method("_input", &CameraController3D::_input);
    register_method("_ready", &CameraController3D::_ready);
    register_method("_physics_process", &CameraController3D::_physics_process);

    register_property<CameraController3D, float>("rotation speed", &CameraController3D::CAMERA_ROTATION_SPEED, 0.003);
    register_property<CameraController3D, float>("CAMERA_X_ROTATION_MIN", &CameraController3D::CAMERA_X_ROTATION_MIN, 70);
    register_property<CameraController3D, float>("CAMERA_X_ROTATION_MAX", &CameraController3D::CAMERA_X_ROTATION_MAX, 100);
}

void CameraController3D::_init()
{
    Godot::print("CameraController3D::_init");
    Input::get_singleton()->set_mouse_mode(Input::MOUSE_MODE_CAPTURED);
}

void CameraController3D::_ready()
{
    camera = Object::cast_to<Camera>(Node::get_node_or_null("Character/Camera"));
    character = Object::cast_to<Spatial>(Node::get_node_or_null("Character"));

    orientation = camera->get_global_transform();
    orientation.set_origin(Vector3());
    camera->set_rotation(character->get_rotation());

    if (character == NULL)
    {
        Godot::print("Error loading character");
    }
    else
    {
        Godot::print("character loaded successfully");
    }
    if (CAMERA_ROTATION_SPEED <= 0)
    {
        CAMERA_ROTATION_SPEED = 0.001;
    }
}

void CameraController3D::_input(const godot::Ref<godot::InputEvent> event)
{
    const InputEvent *input = event.ptr();
    if (event->get_class() == CameraController3D::INPUT_MOUSE_MOTION && !cursorActive)
    {
        InputEventMouseMotion *i = Object::cast_to<InputEventMouseMotion>(input);
        //Rotation links/rechts y-Axe
        character->rotate_y(-i->get_relative().x * CAMERA_ROTATION_SPEED);
        camera->orthonormalize();

        cameraXRotation = std::clamp(cameraXRotation + i->get_relative().y * CAMERA_ROTATION_SPEED, Common::deg2rad<float>(CAMERA_X_ROTATION_MIN), Common::deg2rad<float>(CAMERA_X_ROTATION_MAX));
        camera->set_rotation(Vector3(-1.0 * cameraXRotation, camera->get_rotation().y, camera->get_rotation().z));
    }
    else if (input->get_class() == CameraController3D::INPUT_MOUSE_BUTTON)
    {
        //Godot::print("Mouse button klick");
    }
    else if (input->get_class() == CameraController3D::INPUT_KEY)
    {
        if (input->is_action_pressed(ACTION_INVENTORY))
        {
            cursorActive = !cursorActive;
            //Godot::print("Alt was pressed");
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
        if (input->is_action_pressed(ACTION_MOVE_LEFT))
        {
            // direction.x -= 1;
            character->translate(Vector3(character->get_translation().x - 1,
                                         character->get_translation().y,
                                         character->get_translation().z));
        }
    }

    //Godot::print(input->as_text());
}

void CameraController3D::_physics_process(float delta)
{
    // Vector3 maxSpeed = MOVEMENT_SPEED * direction.normalized();
    // velocity = velocity.linear_interpolate(maxSpeed, delta * ACCELERATION);
    // movement = character->get_transform().get_basis() * (velocity);
    // character->

    //character->rotate_y(10);
    //Godot::print("process physics");
    /*Transform cameraTransformation = camera->get_global_transform();

    Vector3 dir = Vector3();
    bool moving = false;

    if (Input::get_singleton()->is_action_just_pressed(ACTION_MOVE_FORWARD))
    {
        moving = true;
    }
    if (Input::get_singleton()->is_action_just_pressed(ACTION_MOVE_BACKWARD))
    {
        moving = true;
    }
    if (Input::get_singleton()->is_action_just_pressed(ACTION_MOVE_LEFT))
    {
        moving = true;
    }
    if (Input::get_singleton()->is_action_just_pressed(ACTION_MOVE_RIGHT))
    {
        moving = true;
    }

    dir.y = 0;
    dir = dir.normalized();

    velocity.y += delta * GRAVITY;

    Vector3 hv = velocity;
    hv.y = 0;

    Vector3 newPosition = dir * 6;
    int acceleration = 5;

    if (dir.dot(hv) > 0)
    {
        acceleration = 3;
    }

    hv = hv.linear_interpolate(newPosition, acceleration * delta);

    velocity.x = hv.x;
    velocity.z = hv.z;

    velocity = velocity.slide(Vector3(0, 1, 0));

    auto hvspeed = hv.length() / 6;

    if (moving)
    {
        double angle = atan2(hv.x, hv.z);
        Vector3 characterRotation = character->get_rotation();
        characterRotation.y = angle;
        character->set_rotation(characterRotation);
    }*/
}

/**
 *     Vector2 motionTarget = Vector2(Input::get_singleton()->get_action_strength(ACTION_MOVE_RIGHT) - Input::get_singleton()->get_action_strength(ACTION_MOVE_LEFT),
                                   Input::get_singleton()->get_action_strength(ACTION_MOVE_FORWARD) - Input::get_singleton()->get_action_strength(ACTION_MOVE_BACKWARD));

    motion = motion.linear_interpolate(motionTarget, MOTION_INTERPOLATE_SPEED * delta);

    Vector3 cameraZ = camera->get_global_transform().get_basis().z;
    Vector3 cameraX = camera->get_global_transform().get_basis().x;

    cameraZ.y = 0;
    cameraZ = cameraZ.normalized();
    cameraX.y = 0;
    cameraX = cameraX.normalized();

    Vector3 velocityPhysics = orientation.origin / delta;
    velocity.x = velocityPhysics.x;
    velocity.z = velocityPhysics.z;
    velocity += GRAVITY * delta;
    velocity = velocity.slide(Vector3(0, 1, 0));
    orientation.set_origin(Vector3());
    orientation = orientation.orthonormalized();

    camera->get_global_transform().set_basis(orientation.get_basis());
 * */