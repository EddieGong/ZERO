#include "CppUnitTest.h"
import ArithmeticBasics;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ZERO
{
	TEST_CLASS(ArithmeticBasicTests)
	{
	public:
		
		TEST_METHOD(TestArithmeticBasics)
		{
			Logger::WriteMessage("In TestArithmeticBasics");

			int sum = ZERO::Arithmetic::Sum(1, 2, 3, 4, 5);
			Assert::AreEqual(15, sum);

			int square = ZERO::Arithmetic::Square(7);
			Assert::AreEqual(49, square);

			int evenCount = ZERO::Arithmetic::CountEven(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
			Assert::AreEqual(5, evenCount);

			int factorial = ZERO::Arithmetic::Factorial(5);
			Assert::AreEqual(120, factorial);
		}
	};
}
