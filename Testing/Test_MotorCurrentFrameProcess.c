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
	uint8_t buffer[8], expected[8];
	expected[0] = 0xFC;
	expected[1] = 0x08;
	expected[2] = 0x88;
	expected[3] = 0xFF;
	output = process_motor_current_request(2300, -120, buffer);
	TEST_ASSERT_EQUAL_UINT8_ARRAY((expected), (buffer), 4);
	UNITY_END();
}
