# Il2Cpp-Modding-Codegen (BNM)
A fork of Il2Cpp-Modding-Codegen, made to use BNM-Android instead of beatsaber-hook.

Output may have a few errors depending on the game size, typically struct or generic errors, so just fix them yourself and it should be good.

## CMake Setup
```cmake
set_property(TARGET BNM PROPERTY BNM_INCLUDE_DIRECTORIES ${PUBLIC_INCLUDE_DIRS})

file(GLOB_RECURSE SDK_SOURCES
        ${CMAKE_SOURCE_DIR}/Include/output/src/*.cpp
)

add_library(project SHARED
    ${SDK_SOURCES}
)

target_include_directories( project PUBLIC
    Include/output/include
)
```

## Example Of Use
```c++
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Transform.hpp"
#include "UnityEngine/PrimitiveType.hpp"
#include "UnityEngine/Vector3.hpp"

void example() {
    using namespace ::UnityEngine;

    GameObject* obj = GameObject::CreatePrimitive(PrimitiveType::Cube);
    obj->set_name(BNM::CreateMonoString("Object Name"));

    Transform* tran = obj->get_transform();
    tran->set_localScale(Vector3::get_one() * .1f);
}
```

## Credits & Sources

Original and most code: https://github.com/sc2ad/Il2Cpp-Modding-Codegen

BNM: https://github.com/ByNameModding/BNM-Android