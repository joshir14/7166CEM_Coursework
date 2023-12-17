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

void test_generate_can_frame()
{
	struct can_frame frame;
	uint16_t can_id;
	can_id = 0x320;
	uint8_t currentDataBuffer[8];
	currentDataBuffer[0] = 0xFC;
	currentDataBuffer[1] = 0x08;
	currentDataBuffer[2] = 0x88;
	currentDataBuffer[3] = 0xFF;
	int dlc;
	dlc = 4;
	uint8_t status;
	printf("Verify that CAN frame is correctly generated\n");
	status = generate_can_frame(&frame, currentDataBuffer, can_id, dlc);
	TEST_ASSERT_EQUAL_UINT8_ARRAY((currentDataBuffer), (frame.data), dlc);
	TEST_ASSERT_EQUAL(status, 1);
}

int main(void)
{
	UNITY_BEGIN();
	
	RUN_TEST(test_generate_can_frame);
	
	UNITY_END();
	return 0;
}
