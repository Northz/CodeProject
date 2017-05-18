// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CODEPROJECT_CodeProjectCharacter_generated_h
#error "CodeProjectCharacter.generated.h already included, missing '#pragma once' in CodeProjectCharacter.h"
#endif
#define CODEPROJECT_CodeProjectCharacter_generated_h

#define CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_RPC_WRAPPERS
#define CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_RPC_WRAPPERS_NO_PURE_DECLS
#define CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesACodeProjectCharacter(); \
	friend CODEPROJECT_API class UClass* Z_Construct_UClass_ACodeProjectCharacter(); \
	public: \
	DECLARE_CLASS(ACodeProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/CodeProject"), NO_API) \
	DECLARE_SERIALIZER(ACodeProjectCharacter) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_INCLASS \
	private: \
	static void StaticRegisterNativesACodeProjectCharacter(); \
	friend CODEPROJECT_API class UClass* Z_Construct_UClass_ACodeProjectCharacter(); \
	public: \
	DECLARE_CLASS(ACodeProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/CodeProject"), NO_API) \
	DECLARE_SERIALIZER(ACodeProjectCharacter) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACodeProjectCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACodeProjectCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACodeProjectCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACodeProjectCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACodeProjectCharacter(ACodeProjectCharacter&&); \
	NO_API ACodeProjectCharacter(const ACodeProjectCharacter&); \
public:


#define CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACodeProjectCharacter(ACodeProjectCharacter&&); \
	NO_API ACodeProjectCharacter(const ACodeProjectCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACodeProjectCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACodeProjectCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACodeProjectCharacter)


#define CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ACodeProjectCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ACodeProjectCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__MaxCameraDistance() { return STRUCT_OFFSET(ACodeProjectCharacter, MaxCameraDistance); }


#define CodeProject_Source_CodeProject_CodeProjectCharacter_h_6_PROLOG
#define CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_PRIVATE_PROPERTY_OFFSET \
	CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_RPC_WRAPPERS \
	CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_INCLASS \
	CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_PRIVATE_PROPERTY_OFFSET \
	CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_INCLASS_NO_PURE_DECLS \
	CodeProject_Source_CodeProject_CodeProjectCharacter_h_9_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CodeProject_Source_CodeProject_CodeProjectCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
