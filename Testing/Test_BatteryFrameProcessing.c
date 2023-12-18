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
	struct can_frame frame;
	frame.can_id = 0x526;
	frame.can_dlc = 2;
	frame.data[0] = 0xB5;
	frame.data[1] = 0x2E;
	float voltage;
	int output = vcu_battery_frame_process(frame, &voltage);
	TEST_ASSERT_EQUAL(11.597, voltage);
	TEST_ASSERT_EQUAL(0, output);
	UNITY_END();
	return 0;
}
