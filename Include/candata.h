/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 37.2.0 Tue Nov 14 16:48:17 2023.
 */

#ifndef CANDATA_H
#define CANDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef EINVAL
#    define EINVAL 22
#endif

/* Frame ids. */
#define CANDATA_AI_DRIVE_REQUEST_FRAME_ID (0x521u)
#define CANDATA_VCU_WHEEL_SPEEDS_FRAME_ID (0x525u)
#define CANDATA_VCU_BATTERY_FRAME_ID (0x526u)
#define CANDATA_MOTOR_CURRENT_FRAME_ID (0x320u)

/* Frame lengths in bytes. */
#define CANDATA_AI_DRIVE_REQUEST_LENGTH (6u)
#define CANDATA_VCU_WHEEL_SPEEDS_LENGTH (8u)
#define CANDATA_VCU_BATTERY_LENGTH (2u)
#define CANDATA_MOTOR_CURRENT_LENGTH (4u)

/* Extended or standard frame types. */
#define CANDATA_AI_DRIVE_REQUEST_IS_EXTENDED (0)
#define CANDATA_VCU_WHEEL_SPEEDS_IS_EXTENDED (0)
#define CANDATA_VCU_BATTERY_IS_EXTENDED (0)
#define CANDATA_MOTOR_CURRENT_IS_EXTENDED (0)

/* Frame cycle times in milliseconds. */


/* Signal choices. */


/**
 * Signals in message AI_DRIVE_REQUEST.
 *
 * All signal values are as on the CAN bus.
 */
struct candata_ai_drive_request_t {
    /**
     * Range: -32768..32767 (-32768..32767 Nm)
     * Scale: 1
     * Offset: 0
     */
    int16_t front_trq_request;

    /**
     * Range: -35..35 (-0.35..0.35 rad)
     * Scale: 0.01
     * Offset: 0
     */
    int16_t steering_request;

    /**
     * Range: -32768..32767 (-32768..32767 Nm)
     * Scale: 1
     * Offset: 0
     */
    int16_t rear_trq_request;
};

/**
 * Signals in message VCU_WHEEL_SPEEDS.
 *
 * All signal values are as on the CAN bus.
 */
struct candata_vcu_wheel_speeds_t {
    /**
     * Range: 0..655350 (0..65535 rpm)
     * Scale: 0.1
     * Offset: 0
     */
    uint16_t fl_wheel_speed;

    /**
     * Range: 0..655350 (0..65535 rpm)
     * Scale: 0.1
     * Offset: 0
     */
    uint16_t fr_wheel_speed;

    /**
     * Range: 0..655350 (0..65535 rpm)
     * Scale: 0.1
     * Offset: 0
     */
    uint16_t rl_wheel_speed;

    /**
     * Range: 0..655350 (0..65535 rpm)
     * Scale: 0.1
     * Offset: 0
     */
    uint16_t rr_wheel_speed;
};

/**
 * Signals in message VCU_BATTERY.
 *
 * All signal values are as on the CAN bus.
 */
struct candata_vcu_battery_t {
    /**
     * Range: 0..13000 (0..13 V)
     * Scale: 0.001
     * Offset: 0
     */
    uint16_t voltage;
};

/**
 * Signals in message MOTOR_CURRENT.
 *
 * All signal values are as on the CAN bus.
 */
struct candata_motor_current_t {
    /**
     * Range: -30000..30000 (-30000..30000 mA)
     * Scale: 1
     * Offset: 0
     */
    int16_t front_current;

    /**
     * Range: -30000..30000 (-30000..30000 mA)
     * Scale: 1
     * Offset: 0
     */
    int16_t rear_current;
};

/**
 * Pack message AI_DRIVE_REQUEST.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int candata_ai_drive_request_pack(
    uint8_t *dst_p,
    const struct candata_ai_drive_request_t *src_p,
    size_t size);

/**
 * Unpack message AI_DRIVE_REQUEST.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int candata_ai_drive_request_unpack(
    struct candata_ai_drive_request_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int16_t candata_ai_drive_request_front_trq_request_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float candata_ai_drive_request_front_trq_request_decode(int16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool candata_ai_drive_request_front_trq_request_is_in_range(int16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int16_t candata_ai_drive_request_steering_request_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float candata_ai_drive_request_steering_request_decode(int16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool candata_ai_drive_request_steering_request_is_in_range(int16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int16_t candata_ai_drive_request_rear_trq_request_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float candata_ai_drive_request_rear_trq_request_decode(int16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool candata_ai_drive_request_rear_trq_request_is_in_range(int16_t value);

/**
 * Pack message VCU_WHEEL_SPEEDS.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int candata_vcu_wheel_speeds_pack(
    uint8_t *dst_p,
    const struct candata_vcu_wheel_speeds_t *src_p,
    size_t size);

/**
 * Unpack message VCU_WHEEL_SPEEDS.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int candata_vcu_wheel_speeds_unpack(
    struct candata_vcu_wheel_speeds_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t candata_vcu_wheel_speeds_fl_wheel_speed_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float candata_vcu_wheel_speeds_fl_wheel_speed_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool candata_vcu_wheel_speeds_fl_wheel_speed_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t candata_vcu_wheel_speeds_fr_wheel_speed_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float candata_vcu_wheel_speeds_fr_wheel_speed_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool candata_vcu_wheel_speeds_fr_wheel_speed_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t candata_vcu_wheel_speeds_rl_wheel_speed_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float candata_vcu_wheel_speeds_rl_wheel_speed_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool candata_vcu_wheel_speeds_rl_wheel_speed_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t candata_vcu_wheel_speeds_rr_wheel_speed_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float candata_vcu_wheel_speeds_rr_wheel_speed_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool candata_vcu_wheel_speeds_rr_wheel_speed_is_in_range(uint16_t value);

/**
 * Pack message VCU_BATTERY.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int candata_vcu_battery_pack(
    uint8_t *dst_p,
    const struct candata_vcu_battery_t *src_p,
    size_t size);

/**
 * Unpack message VCU_BATTERY.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int candata_vcu_battery_unpack(
    struct candata_vcu_battery_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t candata_vcu_battery_voltage_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float candata_vcu_battery_voltage_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool candata_vcu_battery_voltage_is_in_range(uint16_t value);

/**
 * Pack message MOTOR_CURRENT.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int candata_motor_current_pack(
    uint8_t *dst_p,
    struct candata_motor_current_t *src_p,
    size_t size);

/**
 * Unpack message MOTOR_CURRENT.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int candata_motor_current_unpack(
    struct candata_motor_current_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int16_t candata_motor_current_front_current_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float candata_motor_current_front_current_decode(int16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool candata_motor_current_front_current_is_in_range(int16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int16_t candata_motor_current_rear_current_encode(float value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
float candata_motor_current_rear_current_decode(int16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool candata_motor_current_rear_current_is_in_range(int16_t value);

#ifdef __cplusplus
}
#endif

#endif
