#include "Input.h"

namespace Charlotte::Input {

    // 348 is the maximum number of keys glfw supports
    inline static bool keysDown[348];
    inline static bool lastKeysDown[348];

    inline static Vector2 cursorPosition = { };

    void SetKey(Key key, bool state) {
        keysDown[key] = state;
    }

    void SetCursorPosition(float x, float y) {
        cursorPosition = { x, y };
    }

    void LateUpdate() {
        for (uint16_t i = 0; i < 348; i++) 
            lastKeysDown[i] = keysDown[i];
    }

    bool GetKey(Key key) {
        return keysDown[key];
    }

    bool GetKeyDown(Key key) {
        return keysDown[key] && !lastKeysDown[key];
    }

    bool GetKeyUp(Key key) {
        return !keysDown[key] && lastKeysDown[key];
    }

    Vector2 GetCursorPosition() {
        return cursorPosition;
    }

    float GetX() {
        return cursorPosition.x;
    }

    float GetY() {
        return cursorPosition.y;
    }

}