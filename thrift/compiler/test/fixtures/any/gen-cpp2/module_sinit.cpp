/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * Macro for marking functions as having public visibility from folly/CPortability.h.
 */
#if defined(__GNUC__)
#define FOLLY_EXPORT __attribute__((__visibility__("default")))
#else
#define FOLLY_EXPORT
#endif

namespace cpp2 {

// Explicitly reference the static init varaibles.
//
// If this file is always linked (e.g. link_whole), it will force
// static linking to include the intialization logic.
extern FOLLY_EXPORT bool __fbthrift_static_init_MyStruct1;
FOLLY_EXPORT auto __fbthrift_static_reg_MyStruct1 =
    &__fbthrift_static_init_MyStruct1;

extern FOLLY_EXPORT bool __fbthrift_static_init_MyStruct2;
FOLLY_EXPORT auto __fbthrift_static_reg_MyStruct2 =
    &__fbthrift_static_init_MyStruct2;

} // cpp2
