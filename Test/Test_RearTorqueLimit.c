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

void test_torque_limit_rear()
{
	int output;
	printf("Verify that torque limit is correctly applied for rear wheels\n");
	output = torque_limit_rear(500, 300, 200, 11.23);
	TEST_ASSERT_EQUAL(output, 120);
	output = torque_limit_rear(500, 710, 200, 11.23);
	TEST_ASSERT_EQUAL(output, 50);
	output = torque_limit_rear(500, 710, -200, 11.23);
	TEST_ASSERT_EQUAL(output, -50);
	output = torque_limit_rear(500, 300, -200, 11.23);
	TEST_ASSERT_EQUAL(output, -120);
	output = torque_limit_rear(500, 300, -200, 2.7);
	TEST_ASSERT_EQUAL(output, -20);
	output = torque_limit_rear(500, 300, 200, 2.7);
	TEST_ASSERT_EQUAL(output, 20);
	output = torque_limit_rear(200, 300, 250, 12.7);
	TEST_ASSERT_EQUAL(output, 250);
	output = torque_limit_rear(200, 300, -250, 12.7);
	TEST_ASSERT_EQUAL(output, -250);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_torque_limit_rear);
	
	UNITY_END();
	return 0;
}
