#include "CppUnitTest.h"

import ArithmeticBasics;
import IntegerTypes;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ZERO
{
	TEST_CLASS(ArithmeticBasicTests)
	{
	public:
		
		TEST_METHOD(TestArithmeticBasics)
		{
			using IntegerTypes::int32;
			using IntegerTypes::uint16;
			using IntegerTypes::uint32;
			using IntegerTypes::uint64;

			Logger::WriteMessage("In TestArithmeticBasics");

			int32 sum = Arithmetic::Sum(1, 2, 3, 4, 5);
			Assert::AreEqual(15, sum);

			uint64 square = Arithmetic::Square(7);
			Assert::AreEqual(uint64(49), square);

			int32 evenCount = Arithmetic::CountEven(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
			Assert::AreEqual(5, evenCount);

			uint32 factorial = Arithmetic::Factorial(5);
			Assert::AreEqual(uint32(120), factorial);
		}
	};
}
