#pragma once
#include <BNM/BasicMonoStructures.hpp>
#include <BNM/Class.hpp>
#include <BNM/ClassesManagement.hpp>
#include <BNM/ComplexMonoStructures.hpp>
#include <BNM/Coroutine.hpp>
#include <BNM/DebugMessages.hpp>
#include <BNM/Defaults.hpp>
#include <BNM/Delegates.hpp>
#include <BNM/Event.hpp>
#include <BNM/EventBase.hpp>
#include <BNM/EventBase.hpp>
#include <BNM/Exceptions.hpp>
#include <BNM/Field.hpp>
#include <BNM/FieldBase.hpp>
#include <BNM/Il2CppHeaders.hpp>
#include <BNM/Image.hpp>
#include <BNM/Loading.hpp>
#include <BNM/Method.hpp>
#include <BNM/MethodBase.hpp>
#include <BNM/Operators.hpp>
#include <BNM/Property.hpp>
#include <BNM/PropertyBase.hpp>
#include <BNM/UnityStructures.hpp>
#include <BNM/Utils.hpp>
#include "BNM/UnityStructures.hpp"
#include "BNM/UnityStructures/Color.hpp"
#include "BNM/UnityStructures/Vector3.hpp"
#include "BNM/UnityStructures/Vector2.hpp"
#include "BNM/UnityStructures/Quaternion.hpp"
#include "BNM/UnityStructures/Rect.hpp"
#include "BNM/UnityStructures/Ray.hpp"
#include "BNM/UnityStructures/RaycastHit.hpp"
#include "BNM/UnityStructures/RaycastHit2D.hpp"
#include "BNM/UnityStructures/Matrix3x3.hpp"
#include "BNM/UnityStructures/Matrix4x4.hpp"

using namespace ::BNM::IL2CPP;


namespace il2cpp_utils {
    template<typename T, typename = void>
    struct Il2CppClassFromType {
        static ::BNM::Class get() {
            BNM_LOG_ERR("Failed to get class for type");
            return ::BNM::Class("", "");
        }
    };

    template<typename T>
    inline ::BNM::Class GetIl2CppClassFromType() {
        return Il2CppClassFromType<T>::get();
    }
}

#define DEFINE_IL2CPP_ARG_TYPE(type, ns, cn)        \
namespace il2cpp_utils {                            \
    template <>                                     \
    struct Il2CppClassFromType<type> {             \
        static ::BNM::Class get() {                \
            return ::BNM::Class(ns, cn);           \
        }                                          \
    };                                             \
}

#define DEFINE_IL2CPP_ARG_TYPE_GENERIC(templateType, ns, cn)  \
namespace il2cpp_utils {                                       \
    template<typename... Ts>                                    \
    struct Il2CppClassFromType<templateType<Ts...>> {          \
        static ::BNM::Class get() {                            \
            return ::BNM::Class(ns, cn);                      \
        }                                                      \
    };                                                         \
}
