#ifndef DEF_INPUTEVENTMANAGER_H
#define DEF_INPUTEVENTMANAGER_H

#include <list>
#include <map>
#include <functional>
#include "window.h"

struct Key {
    int _keyCode;
    int _modifier;
    Key(int key, int mod) : _keyCode(key), _modifier(mod) {

    }
};
typedef std::function<void()> KeyAction;

class InputEventManager {
public:
    bool Init(Window* window);
    void Update();
    bool AddAction(int key, KeyAction action);
    void QueueKey(Key key);
private:
    std::map<int, std::list<KeyAction>> _mappedActions;
    std::list<Key> _pressedKeys;
    Window* _window;
};

#endif