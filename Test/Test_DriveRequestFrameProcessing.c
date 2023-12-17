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

void test_ai_drive_request_frame_process()
{
	struct can_frame frame;
	frame.can_id = 0x521;
	frame.can_dlc = 6;
	frame.data[0] = 0x48;
	frame.data[1] = 0x00;
	frame.data[2] = 0xAA;
	frame.data[3] = 0x00;
	frame.data[4] = 0xD3;
	frame.data[5] = 0xFF;
	float frontTrq, rearTrq, steeringReq;
	int output = ai_drive_request_frame_process(frame, &frontTrq, &rearTrq, &steeringReq);
	printf("Verify that torque requests are decoded correctly\n");
	TEST_ASSERT_EQUAL(1.7, steeringReq);
	TEST_ASSERT_EQUAL(72, frontTrq);
	TEST_ASSERT_EQUAL(-45, rearTrq);
	TEST_ASSERT_EQUAL(0, output);
}

int main()
{
	UNITY_BEGIN();
	
	RUN_TEST(test_ai_drive_request_frame_process);
	
	UNITY_END();
	return 0;
}
