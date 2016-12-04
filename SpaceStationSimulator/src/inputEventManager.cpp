#include "inputEventManager.h"
#include "log.h"
#include "gvars.h"
#include <GLFW/glfw3.h>

void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    //GLFW_MOD_SHIFT   0x0001
    //GLFW_MOD_CONTROL   0x0002
    //GLFW_MOD_ALT   0x0004
    //GLFW_MOD_SUPER   0x0008

    Key k(key, mods);
    if (action == GLFW_PRESS)
    {
        gInputEventManager.QueueKey(k);
    }
}

bool InputEventManager::Init(Window* window)
{
    _window = window;
    glfwSetKeyCallback(window->GetWindow(), KeyboardCallback);
    return true;
}

void InputEventManager::Update()
{
    glfwPollEvents();
    size_t count = _pressedKeys.size();
    if (count)
    {
        LOG("InputEventManager : {} inputs during frame: {}", count, gFrame - 1);
        for (auto& it : _pressedKeys)
        {
            auto i = _mappedActions.find(it._keyCode);
            for (auto& action : i->second)
            {
                action();
            }
        }
        _pressedKeys.clear();
    }
}

bool InputEventManager::AddAction(int key, KeyAction action)
{
    auto fi = _mappedActions.find(key);
    if (fi == _mappedActions.end())
    {
        //This key is not mapped yet, adding a new mapping
        _mappedActions[key] = std::list<KeyAction>();
    }
    auto& list = _mappedActions[key];
    list.push_back(action);
    return true;
}

void InputEventManager::QueueKey(Key key)
{
    _pressedKeys.push_back(key);
}