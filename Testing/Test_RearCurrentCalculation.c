#include "Application.h"
#include "candata.c"
#include "candata.h"
#include "unity.c"

void setUp()
{
}

void tearDown()
{
}

int main()
{
	UNITY_BEGIN();
	float output;
	output = calculate_rear_current(200, 0, 200);
	TEST_ASSERT_EQUAL(0, output);
	output = calculate_rear_current(200, 11.23, 200);
	TEST_ASSERT_EQUAL(4833, output);
	output = calculate_rear_current(200, 11.23, -900);
	TEST_ASSERT_EQUAL(30000, output);
	UNITY_END();
}
