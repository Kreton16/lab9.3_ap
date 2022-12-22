#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string name1 = "Lyman";
			string name2 = "Kyiv";
			Route* p = new Route[2];
			p[0].sname = "Lviv";
			p[0].ename = "Vinnytsia";
			p[0].rnum = 2;

			p[1].sname = "Lyman";
			p[1].ename = "Kyiv";
			p[1].rnum = 6;

			Sort(p, 2);
			Assert::AreEqual(p[0].sname, name1);
			Assert::AreEqual(p[0].ename, name2);
			Assert::AreEqual(p[0].rnum, 6);

		}
	};
}
