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
	uint16_t rr_speed, rl_speed, fr_speed, fl_speed;
	int output;
	frame.can_id = 0x525;
	frame.can_dlc = 8;
	frame.data[0] = 0xD1;
	frame.data[1] = 0x00;
	frame.data[2] = 0xEF;
	frame.data[3] = 0x00;
	frame.data[4] = 0xD1;
	frame.data[5] = 0x00;
	frame.data[6] = 0x90;
	frame.data[7] = 0x01;
	output = vcu_wheel_speed_frame_process(frame, &rr_speed, &rl_speed, &fr_speed, &fl_speed);
	TEST_ASSERT_EQUAL(40, rr_speed);
	TEST_ASSERT_EQUAL(20, rl_speed);
	TEST_ASSERT_EQUAL(23, fr_speed);
	TEST_ASSERT_EQUAL(20, fl_speed);
	TEST_ASSERT_EQUAL(0, output);
	UNITY_END();
	return 0;
}

