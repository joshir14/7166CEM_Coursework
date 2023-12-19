#include "Application.h"

int main()
{
	const int socket_id = can_connect("vcan0", 0);
	float cf1, cr1;
	cf1 = 0;
	cr1 = 0;
	int count1, count2, count3;
	struct can_frame frame, TxFrame;
	float batteryVoltage = 0.0f;
	int dlc = 0;
	uint16_t rr_wheelSpeed, rl_wheelSpeed, fr_wheelSpeed, fl_wheelSpeed;
	rr_wheelSpeed = 0;
	rl_wheelSpeed = 0;
	fr_wheelSpeed = 0;
	fl_wheelSpeed = 0;
	uint16_t fs, rs;
	fs = 0;
	rs = 0;
	float frontCurrent, rearCurrent;
	frontCurrent = 0.0f;
	rearCurrent = 0.0f;
	float steeringReq, rearTrq, frontTrq;
	steeringReq = 0.0f;
	rearTrq = 0.0f;
	frontTrq = 0.0f;
	uint8_t currentDataBuffer[8];
	int tf1, tr1;
	tf1 = 0;
	tr1 = 0;
	count1 = 0;
	count2 = 0;
	count3 = 0;
	while (1) {
		if (can_read(socket_id, &frame) == 1) {
			if ((frame.can_id == 0x526) && (frame.can_dlc > 0)) {
				count1 = count1 + 1;
				vcu_battery_frame_process(frame, &batteryVoltage);
				printf("Battery voltage is %f\n", batteryVoltage);
			} else if ((frame.can_id == 0x521) && (frame.can_dlc > 0)) {
				count2 = count2 + 1;
				ai_drive_request_frame_process(frame, &frontTrq, &rearTrq,
							       &steeringReq);
				printf("Front torque is %f\n", frontTrq);
				printf("Rear torque is %f\n", rearTrq);
				printf("Steering request is %f\n", steeringReq);
			} else if ((frame.can_id == 0x525) && (frame.can_dlc > 0)) {
				count3 = count3 + 1;
				vcu_wheel_speed_frame_process(frame, &rr_wheelSpeed, &rl_wheelSpeed,
							      &fr_wheelSpeed, &fl_wheelSpeed);
				printf("Front right wheel speed is %d\n", fr_wheelSpeed);
				printf("Front left wheel speed is %d\n", fl_wheelSpeed);
				printf("Rear right wheel speed is %d\n", rr_wheelSpeed);
				printf("Rear left wheel speed is %d\n", rl_wheelSpeed);
			} else {
			}

			if ((count1 > 0) && (count2 > 0) && (count3 > 0)) {
				fs =
				    (fr_wheelSpeed > fl_wheelSpeed) ? (fr_wheelSpeed) : (fl_wheelSpeed);
				rs =
				    (rr_wheelSpeed > rl_wheelSpeed) ? (rr_wheelSpeed) : (rl_wheelSpeed);
				tf1 = torque_limit_front(fr_wheelSpeed, fl_wheelSpeed, frontTrq,
							 batteryVoltage);
				tr1 = torque_limit_rear(rr_wheelSpeed, rl_wheelSpeed, rearTrq,
							batteryVoltage);
				printf("Front torque limit %d\n", tf1);
				printf("Rear torque limit %d\n", tr1);
				cf1 = calculate_front_current(tf1, batteryVoltage, fs);
				cr1 = calculate_rear_current(tr1, batteryVoltage, rs);
				printf("Front current %f\n", cf1);
				printf("Rear current %f\n", cr1);
				dlc = process_motor_current_request(cf1, cr1, currentDataBuffer);

				if (generate_can_frame(&TxFrame, currentDataBuffer, 0x320, dlc) == 1) {
					if (!can_write(socket_id, &TxFrame)) {
						printf("Error\n");
					}
				}
				count2 = 0;
			}
		}
	}
}
