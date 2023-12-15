#include "Application.h"
#include "unity.c"
#include "candata.h"
#include "candata.c"

void setUp()
{
}

void tearDown()
{
}

void test_vcu_battery_frame_process()
{
	struct can_frame frame;
	frame.can_id = 0x526;
	frame.can_dlc = 2;
	frame.data[0] = 0xB5;
	frame.data[1] = 0x2E;
	float voltage;
	int output = vcu_battery_frame_process(frame, &voltage);
	TEST_ASSERT_EQUAL(11.597, voltage);
	TEST_ASSERT_EQUAL(0, output);
}

void test_ai_drive_request_frame_process()
{
	struct can_frame frame;
	frame.can_id = 0x521;
	frame.can_dlc = 6;
	frame.data[0] = 0x48;
	frame.data[1] = 0x00;
	frame.data[2] = 0x00;
	frame.data[3] = 0x00;
	frame.data[4] = 0xD3;
	frame.data[5] = 0xFF;
	float frontTrq, rearTrq, steeringReq;
	int output = ai_drive_request_frame_process(frame, &frontTrq, &rearTrq, &steeringReq);
	TEST_ASSERT_EQUAL(0, steeringReq);
	TEST_ASSERT_EQUAL(72, frontTrq);
	TEST_ASSERT_EQUAL(-45, rearTrq);
	TEST_ASSERT_EQUAL(0, output);
}

void test_vcu_wheel_speed_frame_process()
{
	struct can_frame frame;
	uint16_t rr_speed, rl_speed, fr_speed, fl_speed;
	int output;
	frame.can_id = 0x525;
	frame.can_dlc = 8;
	frame.data[0] = 0xD1;
	frame.data[1] = 0x00;
	frame.data[2] = 0xD1;
	frame.data[3] = 0x00;
	frame.data[4] = 0xD1;
	frame.data[5] = 0x00;
	frame.data[6] = 0xD1;
	frame.data[7] = 0x00;
	output = vcu_wheel_speed_frame_process(frame, &rr_speed, &rl_speed, &fr_speed, &fl_speed);
	TEST_ASSERT_EQUAL(20, rr_speed);
	TEST_ASSERT_EQUAL(20, rl_speed);
	TEST_ASSERT_EQUAL(20, fr_speed);
	TEST_ASSERT_EQUAL(20, fl_speed);
	TEST_ASSERT_EQUAL(0, output);
}

void test_torque_limit_rear()
{
	int output;
	output = torque_limit_rear(650, 400, 150, 11.23);
	TEST_ASSERT_EQUAL(85, output);
	output = torque_limit_rear(650, 400, 150, 2.23);
	TEST_ASSERT_EQUAL(20, output);
}

void test_torque_limit_front()
{
	int output;
	output = torque_limit_front(650, 400, 150, 11.23);
	TEST_ASSERT_EQUAL(85, output);
	output = torque_limit_front(650, 400, 150, 2.23);
	TEST_ASSERT_EQUAL(20, output);
}

void test_calculate_front_current()
{
	float output;
	output = calculate_front_current(200, 0, 200);
	TEST_ASSERT_EQUAL(0, output);
	output = calculate_front_current(200, 11.23, 200);
	TEST_ASSERT_EQUAL(4833, output);
	output = calculate_front_current(200, 11.23, -900);
	TEST_ASSERT_EQUAL(30000, output);
}

void test_calculate_rear_current()
{
	float output;
	output = calculate_rear_current(200, 0, 200);
	TEST_ASSERT_EQUAL(0, output);
	output = calculate_rear_current(200, 11.23, 200);
	TEST_ASSERT_EQUAL(4833, output);
	output = calculate_rear_current(200, 11.23, -900);
	TEST_ASSERT_EQUAL(30000, output);
}

void test_process_motor_current_request()
{
	int output;
	uint8_t buffer[8], expected[8];
	expected[0] = 0xFC;
	expected[1] = 0x08;
	expected[2] = 0x88;
	expected[3] = 0xFF;
	output = process_motor_current_request(2300, -120, buffer);
	TEST_ASSERT_EQUAL_UINT8_ARRAY((expected), (buffer), 4);
}

int main(void)
{
	UNITY_BEGIN();
	
	RUN_TEST(test_vcu_battery_frame_process);
	RUN_TEST(test_ai_drive_request_frame_process);
	RUN_TEST(test_vcu_wheel_speed_frame_process);
	RUN_TEST(test_torque_limit_rear);
	RUN_TEST(test_torque_limit_front);
	RUN_TEST(test_calculate_front_current);
	RUN_TEST(test_calculate_rear_current);
	
	UNITY_END();
	return 0;
}
