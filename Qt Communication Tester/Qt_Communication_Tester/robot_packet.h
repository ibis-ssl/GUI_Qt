// Copyright (c) 2023 ibis-ssl
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#ifndef CRANE_SENDER__ROBOT_PACKET_H_
#define CRANE_SENDER__ROBOT_PACKET_H_

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// NOLINTBEGIN(readability/casting)

typedef struct
{
    uint8_t high;
    uint8_t low;
} TwoByte;

inline TwoByte convertFloatToTwoByte(float val, float range)
{
    TwoByte result;
    uint16_t uint16 = (uint16_t)(32767.f * (float)(val / range) + 32767.f);
    result.high = (uint16 & 0xFF00) >> 8;
    result.low = uint16 & 0x00FF;
    return result;
}

inline float convertTwoByteToFloat(uint8_t byte_high, uint8_t byte_low, float range)
{
    uint16_t two_byte = (byte_high << 8) | byte_low;
    return (float)(two_byte - 32767.f) / 32767.f * range;
}

inline TwoByte convertUInt16ToTwoByte(uint16_t val)
{
    TwoByte result;
    result.high = (val & 0xFF00) >> 8;
    result.low = val & 0x00FF;
    return result;
}

inline uint16_t convertTwoByteToUInt16(uint8_t byte_high, uint8_t byte_low) { return (byte_high << 8) | byte_low; }

inline void forward(uint8_t *arg1, uint8_t *arg2, float val, float range)
{
    TwoByte two_byte = convertFloatToTwoByte(val, range);
    *arg1 = two_byte.high;
    *arg2 = two_byte.low;
}

#define MODE_ARGS_SIZE (8)

typedef struct
{
    float ball_pos[2];
    float ball_vel[2];
    float target_global_vel[2];
} LocalCameraModeArgs;

inline void LocalCameraModeArgs_init(LocalCameraModeArgs *args, const uint8_t *data)
{
    args->ball_pos[0] = convertTwoByteToFloat(data[0], data[1], 32.767);
    args->ball_pos[1] = convertTwoByteToFloat(data[2], data[3], 32.767);
    args->ball_vel[0] = convertTwoByteToFloat(data[4], data[5], 32.767);
    args->ball_vel[1] = convertTwoByteToFloat(data[6], data[7], 32.767);
    args->target_global_vel[0] = convertTwoByteToFloat(data[8], data[9], 32.767);
    args->target_global_vel[1] = convertTwoByteToFloat(data[10], data[11], 32.767);
}

inline void LocalCameraModeArgs_serialize(const LocalCameraModeArgs *args, uint8_t *data)
{
    forward(&data[0], &data[1], args->ball_pos[0], 32.767);
    forward(&data[2], &data[3], args->ball_pos[1], 32.767);
    forward(&data[4], &data[5], args->ball_vel[0], 32.767);
    forward(&data[6], &data[7], args->ball_vel[1], 32.767);
    forward(&data[8], &data[9], args->target_global_vel[0], 32.767);
    forward(&data[10], &data[11], args->target_global_vel[1], 32.767);
}

typedef struct
{
    float target_global_pos[2];
    float terminal_velocity;
} PositionTargetModeArgs;

inline void PositionTargetModeArgs_init(PositionTargetModeArgs *args, const uint8_t *data)
{
    args->target_global_pos[0] = convertTwoByteToFloat(data[0], data[1], 32.767);
    args->target_global_pos[1] = convertTwoByteToFloat(data[2], data[3], 32.767);
    args->terminal_velocity = convertTwoByteToFloat(data[4], data[5], 32.767);
}

inline void PositionTargetModeArgs_serialize(const PositionTargetModeArgs *args, uint8_t *data)
{
    forward(&data[0], &data[1], args->target_global_pos[0], 32.767);
    forward(&data[2], &data[3], args->target_global_pos[1], 32.767);
    forward(&data[4], &data[5], args->terminal_velocity, 32.767);
}

typedef struct
{
    float target_global_vel[2];
} SimpleVelocityTargetModeArgs;

inline void SimpleVelocityTargetModeArgs_init(SimpleVelocityTargetModeArgs *args, const uint8_t *data)
{
    args->target_global_vel[0] = convertTwoByteToFloat(data[0], data[1], 32.767);
    args->target_global_vel[1] = convertTwoByteToFloat(data[2], data[3], 32.767);
}

inline void SimpleVelocityTargetModeArgs_serialize(const SimpleVelocityTargetModeArgs *args, uint8_t *data)
{
    forward(&data[0], &data[1], args->target_global_vel[0], 32.767);
    forward(&data[2], &data[3], args->target_global_vel[1], 32.767);
}

typedef struct
{
    float target_global_vel[2];
    float trajectory_global_origin[2];
    float trajectory_origin_angle;
    float trajectory_curvature;
} VelocityTargetWithTrajectoryModeArgs;

inline void VelocityTargetWithTrajectoryModeArgs_init(VelocityTargetWithTrajectoryModeArgs *args, const uint8_t *data)
{
    args->target_global_vel[0] = convertTwoByteToFloat(data[0], data[1], 32.767);
    args->target_global_vel[1] = convertTwoByteToFloat(data[2], data[3], 32.767);
    args->trajectory_global_origin[0] = convertTwoByteToFloat(data[4], data[5], 32.767);
    args->trajectory_global_origin[1] = convertTwoByteToFloat(data[6], data[7], 32.767);
    args->trajectory_origin_angle = convertTwoByteToFloat(data[8], data[9], M_PI);
    args->trajectory_curvature = convertTwoByteToFloat(data[10], data[11], 32.767);
}

inline void VelocityTargetWithTrajectoryModeArgs_serialize(const VelocityTargetWithTrajectoryModeArgs *args, uint8_t *data)
{
    forward(&data[0], &data[1], args->target_global_vel[0], 32.767);
    forward(&data[2], &data[3], args->target_global_vel[1], 32.767);
    forward(&data[4], &data[5], args->trajectory_global_origin[0], 32.767);
    forward(&data[6], &data[7], args->trajectory_global_origin[1], 32.767);
    forward(&data[8], &data[9], args->trajectory_origin_angle, M_PI);
    forward(&data[10], &data[11], args->trajectory_curvature, 32.767);
}

typedef enum
{
    LOCAL_CAMERA_MODE = 0,
    POSITION_TARGET_MODE = 1,
    SIMPLE_VELOCITY_TARGET_MODE = 2,
    VELOCITY_TARGET_WITH_TRAJECTORY_MODE = 3,
} ControlMode;

typedef struct
{
    uint8_t header;
    uint8_t check_counter;

    float vision_global_pos[2];
    float vision_global_theta;
    bool is_vision_available;
    float target_global_theta;
    float kick_power;
    float dribble_power;
    bool enable_chip;
    bool lift_dribbler;
    bool stop_emergency;
    float acceleration_limit;
    float linear_velocity_limit;
    float angular_velocity_limit;
    uint16_t latency_time_ms;
    bool prioritize_move;
    bool prioritize_accurate_acceleration;
    uint16_t elapsed_time_ms_since_last_vision;
    ControlMode control_mode;

    union
    {
        LocalCameraModeArgs local_camera;
        PositionTargetModeArgs position;
        SimpleVelocityTargetModeArgs simple_velocity;
        VelocityTargetWithTrajectoryModeArgs velocity;
    } mode_args;
} RobotCommandV2;

typedef struct
{
    uint8_t data[64];
} RobotCommandSerializedV2;

enum Address
{
    HEADER,
    CHECK_COUNTER,
    VISION_GLOBAL_X_HIGH,
    VISION_GLOBAL_X_LOW,
    VISION_GLOBAL_Y_HIGH,
    VISION_GLOBAL_Y_LOW,
    VISION_GLOBAL_THETA_HIGH,
    VISION_GLOBAL_THETA_LOW,
    TARGET_GLOBAL_THETA_HIGH,
    TARGET_GLOBAL_THETA_LOW,
    KICK_POWER,
    DRIBBLE_POWER,
    ACCELERATION_LIMIT_HIGH,
    ACCELERATION_LIMIT_LOW,
    LINEAR_VELOCITY_LIMIT_HIGH,
    LINEAR_VELOCITY_LIMIT_LOW,
    ANGULAR_VELOCITY_LIMIT_HIGH,
    ANGULAR_VELOCITY_LIMIT_LOW,
    LATENCY_TIME_MS_HIGH,
    LATENCY_TIME_MS_LOW,
    ELAPSED_TIME_MS_SINCE_LAST_VISION_HIGH,
    ELAPSED_TIME_MS_SINCE_LAST_VISION_LOW,
    FLAGS,
    CONTROL_MODE,
    CONTROL_MODE_ARGS,
};

enum FlagAddress
{
    IS_VISION_AVAILABLE = 0,
    ENABLE_CHIP = 1,
    LIFT_DRIBBLER = 2,
    STOP_EMERGENCY = 3,
    PRIORITIZE_MOVE = 4,
    PRIORITIZE_ACCURATE_ACCELERATION = 5,
};

inline void RobotCommandSerializedV2_serialize(RobotCommandSerializedV2 *serialized, const RobotCommandV2 *command)
{
    serialized->data[HEADER] = command->header;
    serialized->data[CHECK_COUNTER] = command->check_counter;
    forward(&serialized->data[VISION_GLOBAL_X_HIGH], &serialized->data[VISION_GLOBAL_X_LOW], command->vision_global_pos[0], 32.767);
    forward(&serialized->data[VISION_GLOBAL_Y_HIGH], &serialized->data[VISION_GLOBAL_Y_LOW], command->vision_global_pos[1], 32.767);
    forward(&serialized->data[VISION_GLOBAL_THETA_HIGH], &serialized->data[VISION_GLOBAL_THETA_LOW], command->vision_global_theta, M_PI);
    forward(&serialized->data[TARGET_GLOBAL_THETA_HIGH], &serialized->data[TARGET_GLOBAL_THETA_LOW], command->target_global_theta, M_PI);
    serialized->data[KICK_POWER] = command->kick_power * 20;
    serialized->data[DRIBBLE_POWER] = command->dribble_power * 20;
    forward(&serialized->data[ACCELERATION_LIMIT_HIGH], &serialized->data[ACCELERATION_LIMIT_LOW], command->acceleration_limit, 32.767);
    forward(&serialized->data[LINEAR_VELOCITY_LIMIT_HIGH], &serialized->data[LINEAR_VELOCITY_LIMIT_LOW], command->linear_velocity_limit, 32.767);
    forward(&serialized->data[ANGULAR_VELOCITY_LIMIT_HIGH], &serialized->data[ANGULAR_VELOCITY_LIMIT_LOW], command->angular_velocity_limit, 32.767);
    TwoByte latency_time = convertUInt16ToTwoByte(command->latency_time_ms);
    serialized->data[LATENCY_TIME_MS_HIGH] = latency_time.high;
    serialized->data[LATENCY_TIME_MS_LOW] = latency_time.low;
    TwoByte elapsed_time = convertUInt16ToTwoByte(command->elapsed_time_ms_since_last_vision);
    serialized->data[ELAPSED_TIME_MS_SINCE_LAST_VISION_HIGH] = elapsed_time.high;
    serialized->data[ELAPSED_TIME_MS_SINCE_LAST_VISION_LOW] = elapsed_time.low;
    uint8_t flags = 0x00;
    flags |= (command->is_vision_available << IS_VISION_AVAILABLE);
    flags |= (command->enable_chip << ENABLE_CHIP);
    flags |= (command->lift_dribbler << LIFT_DRIBBLER);
    flags |= (command->stop_emergency << STOP_EMERGENCY);
    flags |= (command->prioritize_move << PRIORITIZE_MOVE);
    flags |= (command->prioritize_accurate_acceleration << PRIORITIZE_ACCURATE_ACCELERATION);
    serialized->data[FLAGS] = flags;
    serialized->data[CONTROL_MODE] = (uint8_t)command->control_mode;
    switch (command->control_mode)
    {
    case LOCAL_CAMERA_MODE:
        LocalCameraModeArgs_serialize(&command->mode_args.local_camera, &serialized->data[CONTROL_MODE_ARGS]);
        break;
    case POSITION_TARGET_MODE:
        PositionTargetModeArgs_serialize(&command->mode_args.position, &serialized->data[CONTROL_MODE_ARGS]);
        break;
    case SIMPLE_VELOCITY_TARGET_MODE:
        SimpleVelocityTargetModeArgs_serialize(&command->mode_args.simple_velocity, &serialized->data[CONTROL_MODE_ARGS]);
        break;
    case VELOCITY_TARGET_WITH_TRAJECTORY_MODE:
        VelocityTargetWithTrajectoryModeArgs_serialize(&command->mode_args.velocity, &serialized->data[CONTROL_MODE_ARGS]);
        break;
    }
}

inline RobotCommandV2 RobotCommandSerializedV2_deserialize(const RobotCommandSerializedV2 *serialized)
{
    RobotCommandV2 command;
    command.header = serialized->data[HEADER];
    command.check_counter = serialized->data[CHECK_COUNTER];
    command.vision_global_pos[0] = convertTwoByteToFloat(serialized->data[VISION_GLOBAL_X_HIGH], serialized->data[VISION_GLOBAL_X_LOW], 32.767);
    command.vision_global_pos[1] = convertTwoByteToFloat(serialized->data[VISION_GLOBAL_Y_HIGH], serialized->data[VISION_GLOBAL_Y_LOW], 32.767);
    command.vision_global_theta = convertTwoByteToFloat(serialized->data[VISION_GLOBAL_THETA_HIGH], serialized->data[VISION_GLOBAL_THETA_LOW], M_PI);
    command.target_global_theta = convertTwoByteToFloat(serialized->data[TARGET_GLOBAL_THETA_HIGH], serialized->data[TARGET_GLOBAL_THETA_LOW], M_PI);
    command.kick_power = serialized->data[KICK_POWER] / 20.;
    command.dribble_power = serialized->data[DRIBBLE_POWER] / 20.;
    command.acceleration_limit = convertTwoByteToFloat(serialized->data[ACCELERATION_LIMIT_HIGH], serialized->data[ACCELERATION_LIMIT_LOW], 32.767);
    command.linear_velocity_limit = convertTwoByteToFloat(serialized->data[LINEAR_VELOCITY_LIMIT_HIGH], serialized->data[LINEAR_VELOCITY_LIMIT_LOW], 32.767);
    command.angular_velocity_limit = convertTwoByteToFloat(serialized->data[ANGULAR_VELOCITY_LIMIT_HIGH], serialized->data[ANGULAR_VELOCITY_LIMIT_LOW], 32.767);
    command.latency_time_ms = convertTwoByteToUInt16(serialized->data[LATENCY_TIME_MS_HIGH], serialized->data[LATENCY_TIME_MS_LOW]);
    command.elapsed_time_ms_since_last_vision = convertTwoByteToUInt16(serialized->data[ELAPSED_TIME_MS_SINCE_LAST_VISION_HIGH], serialized->data[ELAPSED_TIME_MS_SINCE_LAST_VISION_LOW]);
    uint8_t flags = serialized->data[FLAGS];
    command.is_vision_available = (flags >> IS_VISION_AVAILABLE) & 0x01;
    command.enable_chip = (flags >> ENABLE_CHIP) & 0x01;
    command.lift_dribbler = (flags >> LIFT_DRIBBLER) & 0x01;
    command.stop_emergency = (flags >> STOP_EMERGENCY) & 0x01;
    command.prioritize_move = (flags >> PRIORITIZE_MOVE) & 0x01;
    command.prioritize_accurate_acceleration = (flags >> PRIORITIZE_ACCURATE_ACCELERATION) & 0x01;
    command.control_mode = (ControlMode)serialized->data[CONTROL_MODE];
    switch (command.control_mode)
    {
    case LOCAL_CAMERA_MODE:
        LocalCameraModeArgs_init(&command.mode_args.local_camera, &serialized->data[CONTROL_MODE_ARGS]);
        break;
    case POSITION_TARGET_MODE:
        PositionTargetModeArgs_init(&command.mode_args.position, &serialized->data[CONTROL_MODE_ARGS]);
        break;
    case SIMPLE_VELOCITY_TARGET_MODE:
        SimpleVelocityTargetModeArgs_init(&command.mode_args.simple_velocity, &serialized->data[CONTROL_MODE_ARGS]);
        break;
    case VELOCITY_TARGET_WITH_TRAJECTORY_MODE:
        VelocityTargetWithTrajectoryModeArgs_init(&command.mode_args.velocity, &serialized->data[CONTROL_MODE_ARGS]);
        break;
    }
    return command;
}

// NOLINTEND

#endif // CRANE_SENDER__ROBOT_PACKET_H_