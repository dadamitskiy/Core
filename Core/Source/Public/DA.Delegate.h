/// Copyright © Daniel Adamitskiy. All Rights Reserved.

#pragma once

#include "DA.Type.h"

template<typename Type>
class Delegate;

template <typename ReturnType, typename ...Args>
class Delegate<ReturnType(Args...)>
{
public:

	Delegate()
		: invoking_object(nullptr)
		, callback(nullptr)
	{
	}

	ReturnType operator() (Args... args) const
	{
		return (*callback)(invoking_object, args...);
	}

	bool operator==(const Delegate& other) const
	{
		return invoking_object == other.invoking_object && callback == other.callback;
	}

	/// C++ standard doesn't allow us to call a constructor with explicit template arguments. As such,
	/// we're going to use create factory functions.

	template<ReturnType(*FunctionPointer)(Args...)>
	static Delegate Create()
	{
		return Delegate(nullptr, &StaticCaller<FunctionPointer>);
	}

	template<typename Type, ReturnType(Type::*FunctionPointer)(Args...)>
	static Delegate Create(Type* invokingObject)
	{
		return Delegate(invokingObject, &MemberFunctionCaller<Type, FunctionPointer>);
	}

private:

	typedef ReturnType(*CallbackType)(v32, Args...);

	v32 invoking_object { nullptr };
	CallbackType callback { nullptr };

	Delegate(v32 invokingObject, CallbackType functionPointer)
		: invoking_object(invokingObject)
		, callback(functionPointer)
	{
	}

	template<ReturnType(*FuctionPointer)(Args...)>
	static ReturnType StaticCaller(v32, Args... args)
	{
		return FuctionPointer(args...);
	}

	template<typename Type, ReturnType(Type::*FunctionPointer)(Args...)>
	static ReturnType MemberFunctionCaller(v32 invokingObject, Args... args)
	{
		return (static_cast<Type*>(invokingObject)->*FunctionPointer)(args...);
	}
};
