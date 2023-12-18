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
	int output;
	output = torque_limit_front(500, 710, 200, 11.23);
	TEST_ASSERT_EQUAL(output, 50);
	output = torque_limit_front(500, 300, -200, 11.23);
	TEST_ASSERT_EQUAL(output, -120);
	output = torque_limit_front(500, 300, -200, 2.7);
	TEST_ASSERT_EQUAL(output, -20);
	output = torque_limit_front(500, 300, 200, 2.7);
	TEST_ASSERT_EQUAL(output, 20);
	output = torque_limit_front(200, 300, 250, 12.7);
	TEST_ASSERT_EQUAL(output, 250);
	UNITY_END();
}
