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

void test_vcu_battery_frame_process()
{
	struct can_frame frame;
	frame.can_id = 0x526;
	frame.can_dlc = 2;
	frame.data[0] = 0xB5;
	frame.data[1] = 0x2E;
	float voltage;
	int output = vcu_battery_frame_process(frame, &voltage);
	printf("Verify that battery voltage is decoded correctly\n");
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

void test_vcu_wheel_speed_frame_process()
{
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
	printf("Verify that wheel speeds are decoded correctly\n");
	output = vcu_wheel_speed_frame_process(frame, &rr_speed, &rl_speed, &fr_speed, &fl_speed);
	TEST_ASSERT_EQUAL(40, rr_speed);
	TEST_ASSERT_EQUAL(20, rl_speed);
	TEST_ASSERT_EQUAL(23, fr_speed);
	TEST_ASSERT_EQUAL(20, fl_speed);
	TEST_ASSERT_EQUAL(0, output);
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

void test_torque_limit_front()
{
	int output;
	printf("Verify that torque limit is correctly applied for front wheels\n");
	output = torque_limit_front(500, 300, 200, 11.23);
	TEST_ASSERT_EQUAL(output, 120);
	output = torque_limit_front(500, 710, 200, 11.23);
	TEST_ASSERT_EQUAL(output, 50);
	output = torque_limit_front(500, 710, -200, 11.23);
	TEST_ASSERT_EQUAL(output, -50);
	output = torque_limit_front(500, 300, -200, 11.23);
	TEST_ASSERT_EQUAL(output, -120);
	output = torque_limit_front(500, 300, -200, 2.7);
	TEST_ASSERT_EQUAL(output, -20);
	output = torque_limit_front(500, 300, 200, 2.7);
	TEST_ASSERT_EQUAL(output, 20);
	output = torque_limit_front(200, 300, 250, 12.7);
	TEST_ASSERT_EQUAL(output, 250);
	output = torque_limit_front(200, 300, -250, 12.7);
	TEST_ASSERT_EQUAL(output, -250);
}

void test_calculate_front_current()
{
	float output;
	printf("Verify that front current is calculated correctly\n");
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
	printf("Verify that rear current is calculated correctly\n");
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
	printf("Verify that CAN frame for MOTOR_CURRENT (0x320) message is generated correctly\n");
	output = process_motor_current_request(2300, -120, buffer);
	TEST_ASSERT_EQUAL_UINT8_ARRAY((expected), (buffer), 4);
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

	RUN_TEST(test_vcu_battery_frame_process);
	RUN_TEST(test_ai_drive_request_frame_process);
	RUN_TEST(test_vcu_wheel_speed_frame_process);
	RUN_TEST(test_torque_limit_rear);
	RUN_TEST(test_torque_limit_front);
	RUN_TEST(test_calculate_front_current);
	RUN_TEST(test_calculate_rear_current);
	RUN_TEST(test_process_motor_current_request);
	
	UNITY_END();
	return 0;
}
