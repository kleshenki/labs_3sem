#include "pch.h"
#include ".\CppUnitTest.h"
#define protected public
#include "..\String\String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(StringLength)
		{
			String* str = new String(50, "Test string");
			Assert::AreEqual(11, str->RealLength());
		}

		TEST_METHOD(StringConcat)
		{
			String* str = new String(50, "Starting string");
			char* append = " appended";
			*str + append;
			Assert::AreEqual("024Starting string appended", str->arr);
		}

		TEST_METHOD(ResizeStringLength)
		{
			String *str = new String(50, "New string");
			String *append = new String(40, " appended");
			*str + *append;
			Assert::AreEqual(str->RealLength(), 19);
		}
	};
}
