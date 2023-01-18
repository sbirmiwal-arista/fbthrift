// Annotations that indicate which IDL definition a structured annotation can
// be place on.
// 
// For example:
//   include "thrift/annotation/scope.thrift"
// 
//   @scope.Struct
//   struct MyStructAnnotation {...}
// 
//   @MyStructAnnotation // Good.
//   struct Foo{
//     @MyStructAnnotation // Compile-time failure. MyStructAnnotation is not
//                         // allowed on fields.
//     1: i32 my_field;
//   }

// @generated by Thrift for /data/users/jchistyakov/fbsource/fbcode/thrift/annotation/scope.thrift
// This file is probably not the place you want to edit!

package scope // /data/users/jchistyakov/fbsource/fbcode/thrift/annotation/scope.thrift
