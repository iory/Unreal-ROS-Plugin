#include "Unreal_ROS.h"
#include "ros_msg_test.h"

void F_trajectory_msgs_JointTrajectoryPoint::Unserialization(
  rapidjson::Value& v) {
    if (v.HasMember("time_from_start") && v["time_from_start"].IsInt64())
        this->time_from_start = v["time_from_start"].GetInt64();
}

rapidjson::Value F_trajectory_msgs_JointTrajectoryPoint::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value ttime_from_start;
    ttime_from_start.SetString("time_from_start");

    s.AddMember(ttime_from_start, this->time_from_start, d.GetAllocator());

    return s;
}

U_trajectory_msgs_JointTrajectoryPointAdvertiser*
U_trajectory_msgs_JointTrajectoryPointAdvertiser::
  Create_JointTrajectoryPoint_Advertiser(FString TopicName) {
    U_trajectory_msgs_JointTrajectoryPointAdvertiser* c =
      NewObject<U_trajectory_msgs_JointTrajectoryPointAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_trajectory_msgs_JointTrajectoryPointAdvertiser::Publish(
  F_trajectory_msgs_JointTrajectoryPoint Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_trajectory_msgs_JointTrajectoryPointAdvertiser::
  U_trajectory_msgs_JointTrajectoryPointAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("trajectory_msgs/JointTrajectoryPoint");
}

U_trajectory_msgs_JointTrajectoryPointSubscriber::
  U_trajectory_msgs_JointTrajectoryPointSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("trajectory_msgs/JointTrajectoryPoint");
}
void U_trajectory_msgs_JointTrajectoryPointSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_trajectory_msgs_JointTrajectoryPoint fdata;
    fdata.Unserialization(obj);
    OnJointTrajectoryPointData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_trajectory_msgs_JointTrajectoryPointSubscriber::OnRecieve(
  F_trajectory_msgs_JointTrajectoryPoint Data) {}

U_trajectory_msgs_JointTrajectoryPointSubscriber*
U_trajectory_msgs_JointTrajectoryPointSubscriber::
  Create_JointTrajectoryPoint_Subscriber(FString _TopicName) {
    U_trajectory_msgs_JointTrajectoryPointSubscriber* sub =
      NewObject<U_trajectory_msgs_JointTrajectoryPointSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Int16::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt())
        this->data = v["data"].GetInt();
}

rapidjson::Value F_std_msgs_Int16::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_Int16Advertiser* U_std_msgs_Int16Advertiser::Create_Int16_Advertiser(
  FString TopicName) {
    U_std_msgs_Int16Advertiser* c = NewObject<U_std_msgs_Int16Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Int16Advertiser::Publish(F_std_msgs_Int16 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Int16Advertiser::U_std_msgs_Int16Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int16");
}

U_std_msgs_Int16Subscriber::U_std_msgs_Int16Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int16");
}
void U_std_msgs_Int16Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Int16 fdata;
    fdata.Unserialization(obj);
    OnInt16Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Int16Subscriber::OnRecieve(F_std_msgs_Int16 Data) {}

U_std_msgs_Int16Subscriber* U_std_msgs_Int16Subscriber::Create_Int16_Subscriber(
  FString _TopicName) {
    U_std_msgs_Int16Subscriber* sub = NewObject<U_std_msgs_Int16Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionStatusFollowme::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("mission_type") && v["mission_type"].IsInt())
        this->mission_type = v["mission_type"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionStatusFollowme::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tmission_type;
    tmission_type.SetString("mission_type");

    s.AddMember(tmission_type, this->mission_type, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionStatusFollowmeAdvertiser*
U_dji_sdk_MissionStatusFollowmeAdvertiser::
  Create_MissionStatusFollowme_Advertiser(FString TopicName) {
    U_dji_sdk_MissionStatusFollowmeAdvertiser* c =
      NewObject<U_dji_sdk_MissionStatusFollowmeAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionStatusFollowmeAdvertiser::Publish(
  F_dji_sdk_MissionStatusFollowme Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionStatusFollowmeAdvertiser::
  U_dji_sdk_MissionStatusFollowmeAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionStatusFollowme");
}

U_dji_sdk_MissionStatusFollowmeSubscriber::
  U_dji_sdk_MissionStatusFollowmeSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionStatusFollowme");
}
void U_dji_sdk_MissionStatusFollowmeSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionStatusFollowme fdata;
    fdata.Unserialization(obj);
    OnMissionStatusFollowmeData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionStatusFollowmeSubscriber::OnRecieve(
  F_dji_sdk_MissionStatusFollowme Data) {}

U_dji_sdk_MissionStatusFollowmeSubscriber*
U_dji_sdk_MissionStatusFollowmeSubscriber::
  Create_MissionStatusFollowme_Subscriber(FString _TopicName) {
    U_dji_sdk_MissionStatusFollowmeSubscriber* sub =
      NewObject<U_dji_sdk_MissionStatusFollowmeSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_UInt16::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt())
        this->data = v["data"].GetInt();
}

rapidjson::Value F_std_msgs_UInt16::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_UInt16Advertiser*
U_std_msgs_UInt16Advertiser::Create_UInt16_Advertiser(FString TopicName) {
    U_std_msgs_UInt16Advertiser* c = NewObject<U_std_msgs_UInt16Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_UInt16Advertiser::Publish(F_std_msgs_UInt16 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_UInt16Advertiser::U_std_msgs_UInt16Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt16");
}

U_std_msgs_UInt16Subscriber::U_std_msgs_UInt16Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt16");
}
void U_std_msgs_UInt16Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_UInt16 fdata;
    fdata.Unserialization(obj);
    OnUInt16Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_UInt16Subscriber::OnRecieve(F_std_msgs_UInt16 Data) {}

U_std_msgs_UInt16Subscriber*
U_std_msgs_UInt16Subscriber::Create_UInt16_Subscriber(FString _TopicName) {
    U_std_msgs_UInt16Subscriber* sub = NewObject<U_std_msgs_UInt16Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_UInt32::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt())
        this->data = v["data"].GetInt();
}

rapidjson::Value F_std_msgs_UInt32::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_UInt32Advertiser*
U_std_msgs_UInt32Advertiser::Create_UInt32_Advertiser(FString TopicName) {
    U_std_msgs_UInt32Advertiser* c = NewObject<U_std_msgs_UInt32Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_UInt32Advertiser::Publish(F_std_msgs_UInt32 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_UInt32Advertiser::U_std_msgs_UInt32Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt32");
}

U_std_msgs_UInt32Subscriber::U_std_msgs_UInt32Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt32");
}
void U_std_msgs_UInt32Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_UInt32 fdata;
    fdata.Unserialization(obj);
    OnUInt32Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_UInt32Subscriber::OnRecieve(F_std_msgs_UInt32 Data) {}

U_std_msgs_UInt32Subscriber*
U_std_msgs_UInt32Subscriber::Create_UInt32_Subscriber(FString _TopicName) {
    U_std_msgs_UInt32Subscriber* sub = NewObject<U_std_msgs_UInt32Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionEventWpAction::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("incident_type") && v["incident_type"].IsInt())
        this->incident_type = v["incident_type"].GetInt();

    if (v.HasMember("repeat") && v["repeat"].IsInt())
        this->repeat = v["repeat"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionEventWpAction::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tincident_type;
    tincident_type.SetString("incident_type");

    s.AddMember(tincident_type, this->incident_type, d.GetAllocator());

    rapidjson::Value trepeat;
    trepeat.SetString("repeat");

    s.AddMember(trepeat, this->repeat, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionEventWpActionAdvertiser*
U_dji_sdk_MissionEventWpActionAdvertiser::
  Create_MissionEventWpAction_Advertiser(FString TopicName) {
    U_dji_sdk_MissionEventWpActionAdvertiser* c =
      NewObject<U_dji_sdk_MissionEventWpActionAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionEventWpActionAdvertiser::Publish(
  F_dji_sdk_MissionEventWpAction Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionEventWpActionAdvertiser::
  U_dji_sdk_MissionEventWpActionAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionEventWpAction");
}

U_dji_sdk_MissionEventWpActionSubscriber::
  U_dji_sdk_MissionEventWpActionSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionEventWpAction");
}
void U_dji_sdk_MissionEventWpActionSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionEventWpAction fdata;
    fdata.Unserialization(obj);
    OnMissionEventWpActionData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionEventWpActionSubscriber::OnRecieve(
  F_dji_sdk_MissionEventWpAction Data) {}

U_dji_sdk_MissionEventWpActionSubscriber*
U_dji_sdk_MissionEventWpActionSubscriber::
  Create_MissionEventWpAction_Subscriber(FString _TopicName) {
    U_dji_sdk_MissionEventWpActionSubscriber* sub =
      NewObject<U_dji_sdk_MissionEventWpActionSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Bool::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsBool())
        this->data = v["data"].GetBool();
}

rapidjson::Value F_std_msgs_Bool::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_BoolAdvertiser* U_std_msgs_BoolAdvertiser::Create_Bool_Advertiser(
  FString TopicName) {
    U_std_msgs_BoolAdvertiser* c = NewObject<U_std_msgs_BoolAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_BoolAdvertiser::Publish(F_std_msgs_Bool Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_BoolAdvertiser::U_std_msgs_BoolAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Bool");
}

U_std_msgs_BoolSubscriber::U_std_msgs_BoolSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Bool");
}
void U_std_msgs_BoolSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Bool fdata;
    fdata.Unserialization(obj);
    OnBoolData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_BoolSubscriber::OnRecieve(F_std_msgs_Bool Data) {}

U_std_msgs_BoolSubscriber* U_std_msgs_BoolSubscriber::Create_Bool_Subscriber(
  FString _TopicName) {
    U_std_msgs_BoolSubscriber* sub = NewObject<U_std_msgs_BoolSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_UInt64::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt())
        this->data = v["data"].GetInt();
}

rapidjson::Value F_std_msgs_UInt64::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_UInt64Advertiser*
U_std_msgs_UInt64Advertiser::Create_UInt64_Advertiser(FString TopicName) {
    U_std_msgs_UInt64Advertiser* c = NewObject<U_std_msgs_UInt64Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_UInt64Advertiser::Publish(F_std_msgs_UInt64 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_UInt64Advertiser::U_std_msgs_UInt64Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt64");
}

U_std_msgs_UInt64Subscriber::U_std_msgs_UInt64Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt64");
}
void U_std_msgs_UInt64Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_UInt64 fdata;
    fdata.Unserialization(obj);
    OnUInt64Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_UInt64Subscriber::OnRecieve(F_std_msgs_UInt64 Data) {}

U_std_msgs_UInt64Subscriber*
U_std_msgs_UInt64Subscriber::Create_UInt64_Subscriber(FString _TopicName) {
    U_std_msgs_UInt64Subscriber* sub = NewObject<U_std_msgs_UInt64Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionStatusHotpoint::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("mission_type") && v["mission_type"].IsInt())
        this->mission_type = v["mission_type"].GetInt();

    if (v.HasMember("mission_status") && v["mission_status"].IsInt())
        this->mission_status = v["mission_status"].GetInt();

    if (v.HasMember("hotpoint_radius") && v["hotpoint_radius"].IsInt())
        this->hotpoint_radius = v["hotpoint_radius"].GetInt();

    if (v.HasMember("error_code") && v["error_code"].IsInt())
        this->error_code = v["error_code"].GetInt();

    if (v.HasMember("hotpoint_velocity") && v["hotpoint_velocity"].IsInt())
        this->hotpoint_velocity = v["hotpoint_velocity"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionStatusHotpoint::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tmission_type;
    tmission_type.SetString("mission_type");

    s.AddMember(tmission_type, this->mission_type, d.GetAllocator());

    rapidjson::Value tmission_status;
    tmission_status.SetString("mission_status");

    s.AddMember(tmission_status, this->mission_status, d.GetAllocator());

    rapidjson::Value thotpoint_radius;
    thotpoint_radius.SetString("hotpoint_radius");

    s.AddMember(thotpoint_radius, this->hotpoint_radius, d.GetAllocator());

    rapidjson::Value terror_code;
    terror_code.SetString("error_code");

    s.AddMember(terror_code, this->error_code, d.GetAllocator());

    rapidjson::Value thotpoint_velocity;
    thotpoint_velocity.SetString("hotpoint_velocity");

    s.AddMember(thotpoint_velocity, this->hotpoint_velocity, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionStatusHotpointAdvertiser*
U_dji_sdk_MissionStatusHotpointAdvertiser::
  Create_MissionStatusHotpoint_Advertiser(FString TopicName) {
    U_dji_sdk_MissionStatusHotpointAdvertiser* c =
      NewObject<U_dji_sdk_MissionStatusHotpointAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionStatusHotpointAdvertiser::Publish(
  F_dji_sdk_MissionStatusHotpoint Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionStatusHotpointAdvertiser::
  U_dji_sdk_MissionStatusHotpointAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionStatusHotpoint");
}

U_dji_sdk_MissionStatusHotpointSubscriber::
  U_dji_sdk_MissionStatusHotpointSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionStatusHotpoint");
}
void U_dji_sdk_MissionStatusHotpointSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionStatusHotpoint fdata;
    fdata.Unserialization(obj);
    OnMissionStatusHotpointData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionStatusHotpointSubscriber::OnRecieve(
  F_dji_sdk_MissionStatusHotpoint Data) {}

U_dji_sdk_MissionStatusHotpointSubscriber*
U_dji_sdk_MissionStatusHotpointSubscriber::
  Create_MissionStatusHotpoint_Subscriber(FString _TopicName) {
    U_dji_sdk_MissionStatusHotpointSubscriber* sub =
      NewObject<U_dji_sdk_MissionStatusHotpointSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Point::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("x") && v["x"].IsDouble()) this->x = v["x"].GetDouble();

    if (v.HasMember("y") && v["y"].IsDouble()) this->y = v["y"].GetDouble();

    if (v.HasMember("z") && v["z"].IsDouble()) this->z = v["z"].GetDouble();
}

rapidjson::Value F_geometry_msgs_Point::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tx;
    tx.SetString("x");

    s.AddMember(tx, this->x, d.GetAllocator());

    rapidjson::Value ty;
    ty.SetString("y");

    s.AddMember(ty, this->y, d.GetAllocator());

    rapidjson::Value tz;
    tz.SetString("z");

    s.AddMember(tz, this->z, d.GetAllocator());

    return s;
}

U_geometry_msgs_PointAdvertiser*
U_geometry_msgs_PointAdvertiser::Create_Point_Advertiser(FString TopicName) {
    U_geometry_msgs_PointAdvertiser* c =
      NewObject<U_geometry_msgs_PointAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_PointAdvertiser::Publish(F_geometry_msgs_Point Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_PointAdvertiser::U_geometry_msgs_PointAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Point");
}

U_geometry_msgs_PointSubscriber::U_geometry_msgs_PointSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Point");
}
void U_geometry_msgs_PointSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Point fdata;
    fdata.Unserialization(obj);
    OnPointData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_PointSubscriber::OnRecieve(F_geometry_msgs_Point Data) {}

U_geometry_msgs_PointSubscriber*
U_geometry_msgs_PointSubscriber::Create_Point_Subscriber(FString _TopicName) {
    U_geometry_msgs_PointSubscriber* sub =
      NewObject<U_geometry_msgs_PointSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Byte::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt())
        this->data = v["data"].GetInt();
}

rapidjson::Value F_std_msgs_Byte::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_ByteAdvertiser* U_std_msgs_ByteAdvertiser::Create_Byte_Advertiser(
  FString TopicName) {
    U_std_msgs_ByteAdvertiser* c = NewObject<U_std_msgs_ByteAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_ByteAdvertiser::Publish(F_std_msgs_Byte Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_ByteAdvertiser::U_std_msgs_ByteAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Byte");
}

U_std_msgs_ByteSubscriber::U_std_msgs_ByteSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Byte");
}
void U_std_msgs_ByteSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Byte fdata;
    fdata.Unserialization(obj);
    OnByteData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_ByteSubscriber::OnRecieve(F_std_msgs_Byte Data) {}

U_std_msgs_ByteSubscriber* U_std_msgs_ByteSubscriber::Create_Byte_Subscriber(
  FString _TopicName) {
    U_std_msgs_ByteSubscriber* sub = NewObject<U_std_msgs_ByteSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionEventWpReach::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("incident_type") && v["incident_type"].IsInt())
        this->incident_type = v["incident_type"].GetInt();

    if (v.HasMember("waypoint_index") && v["waypoint_index"].IsInt())
        this->waypoint_index = v["waypoint_index"].GetInt();

    if (v.HasMember("current_status") && v["current_status"].IsInt())
        this->current_status = v["current_status"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionEventWpReach::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tincident_type;
    tincident_type.SetString("incident_type");

    s.AddMember(tincident_type, this->incident_type, d.GetAllocator());

    rapidjson::Value twaypoint_index;
    twaypoint_index.SetString("waypoint_index");

    s.AddMember(twaypoint_index, this->waypoint_index, d.GetAllocator());

    rapidjson::Value tcurrent_status;
    tcurrent_status.SetString("current_status");

    s.AddMember(tcurrent_status, this->current_status, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionEventWpReachAdvertiser*
U_dji_sdk_MissionEventWpReachAdvertiser::Create_MissionEventWpReach_Advertiser(
  FString TopicName) {
    U_dji_sdk_MissionEventWpReachAdvertiser* c =
      NewObject<U_dji_sdk_MissionEventWpReachAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionEventWpReachAdvertiser::Publish(
  F_dji_sdk_MissionEventWpReach Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionEventWpReachAdvertiser::
  U_dji_sdk_MissionEventWpReachAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionEventWpReach");
}

U_dji_sdk_MissionEventWpReachSubscriber::
  U_dji_sdk_MissionEventWpReachSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionEventWpReach");
}
void U_dji_sdk_MissionEventWpReachSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionEventWpReach fdata;
    fdata.Unserialization(obj);
    OnMissionEventWpReachData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionEventWpReachSubscriber::OnRecieve(
  F_dji_sdk_MissionEventWpReach Data) {}

U_dji_sdk_MissionEventWpReachSubscriber*
U_dji_sdk_MissionEventWpReachSubscriber::Create_MissionEventWpReach_Subscriber(
  FString _TopicName) {
    U_dji_sdk_MissionEventWpReachSubscriber* sub =
      NewObject<U_dji_sdk_MissionEventWpReachSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Header::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("seq") && v["seq"].IsInt()) this->seq = v["seq"].GetInt();

    if (v.HasMember("stamp") && v["stamp"].IsInt64())
        this->stamp = v["stamp"].GetInt64();

    if (v.HasMember("frame_id") && v["frame_id"].IsString())
        this->frame_id = FString(v["frame_id"].GetString());
}

rapidjson::Value F_std_msgs_Header::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tseq;
    tseq.SetString("seq");

    s.AddMember(tseq, this->seq, d.GetAllocator());

    rapidjson::Value tstamp;
    tstamp.SetString("stamp");

    s.AddMember(tstamp, this->stamp, d.GetAllocator());

    rapidjson::Value tframe_id;
    tframe_id.SetString("frame_id");

    rapidjson::Value sframe_id;
    std::string fuck_frame_id = TCHAR_TO_UTF8(*this->frame_id);
    sframe_id.SetString(rapidjson::StringRef(fuck_frame_id.c_str()));
    s.AddMember(tframe_id, sframe_id, d.GetAllocator());

    return s;
}

U_std_msgs_HeaderAdvertiser*
U_std_msgs_HeaderAdvertiser::Create_Header_Advertiser(FString TopicName) {
    U_std_msgs_HeaderAdvertiser* c = NewObject<U_std_msgs_HeaderAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_HeaderAdvertiser::Publish(F_std_msgs_Header Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_HeaderAdvertiser::U_std_msgs_HeaderAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Header");
}

U_std_msgs_HeaderSubscriber::U_std_msgs_HeaderSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Header");
}
void U_std_msgs_HeaderSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Header fdata;
    fdata.Unserialization(obj);
    OnHeaderData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_HeaderSubscriber::OnRecieve(F_std_msgs_Header Data) {}

U_std_msgs_HeaderSubscriber*
U_std_msgs_HeaderSubscriber::Create_Header_Subscriber(FString _TopicName) {
    U_std_msgs_HeaderSubscriber* sub = NewObject<U_std_msgs_HeaderSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_actionlib_msgs_GoalStatusArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);
}

rapidjson::Value F_actionlib_msgs_GoalStatusArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    return s;
}

U_actionlib_msgs_GoalStatusArrayAdvertiser*
U_actionlib_msgs_GoalStatusArrayAdvertiser::Create_GoalStatusArray_Advertiser(
  FString TopicName) {
    U_actionlib_msgs_GoalStatusArrayAdvertiser* c =
      NewObject<U_actionlib_msgs_GoalStatusArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_actionlib_msgs_GoalStatusArrayAdvertiser::Publish(
  F_actionlib_msgs_GoalStatusArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_actionlib_msgs_GoalStatusArrayAdvertiser::
  U_actionlib_msgs_GoalStatusArrayAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("actionlib_msgs/GoalStatusArray");
}

U_actionlib_msgs_GoalStatusArraySubscriber::
  U_actionlib_msgs_GoalStatusArraySubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("actionlib_msgs/GoalStatusArray");
}
void U_actionlib_msgs_GoalStatusArraySubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_actionlib_msgs_GoalStatusArray fdata;
    fdata.Unserialization(obj);
    OnGoalStatusArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_actionlib_msgs_GoalStatusArraySubscriber::OnRecieve(
  F_actionlib_msgs_GoalStatusArray Data) {}

U_actionlib_msgs_GoalStatusArraySubscriber*
U_actionlib_msgs_GoalStatusArraySubscriber::Create_GoalStatusArray_Subscriber(
  FString _TopicName) {
    U_actionlib_msgs_GoalStatusArraySubscriber* sub =
      NewObject<U_actionlib_msgs_GoalStatusArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_LocalPosition::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("ts") && v["ts"].IsInt()) this->ts = v["ts"].GetInt();

    if (v.HasMember("x") && v["x"].IsDouble()) this->x = v["x"].GetDouble();

    if (v.HasMember("y") && v["y"].IsDouble()) this->y = v["y"].GetDouble();

    if (v.HasMember("z") && v["z"].IsDouble()) this->z = v["z"].GetDouble();
}

rapidjson::Value F_dji_sdk_LocalPosition::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tts;
    tts.SetString("ts");

    s.AddMember(tts, this->ts, d.GetAllocator());

    rapidjson::Value tx;
    tx.SetString("x");

    s.AddMember(tx, this->x, d.GetAllocator());

    rapidjson::Value ty;
    ty.SetString("y");

    s.AddMember(ty, this->y, d.GetAllocator());

    rapidjson::Value tz;
    tz.SetString("z");

    s.AddMember(tz, this->z, d.GetAllocator());

    return s;
}

U_dji_sdk_LocalPositionAdvertiser*
U_dji_sdk_LocalPositionAdvertiser::Create_LocalPosition_Advertiser(
  FString TopicName) {
    U_dji_sdk_LocalPositionAdvertiser* c =
      NewObject<U_dji_sdk_LocalPositionAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_LocalPositionAdvertiser::Publish(F_dji_sdk_LocalPosition Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_LocalPositionAdvertiser::U_dji_sdk_LocalPositionAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/LocalPosition");
}

U_dji_sdk_LocalPositionSubscriber::U_dji_sdk_LocalPositionSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/LocalPosition");
}
void U_dji_sdk_LocalPositionSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_LocalPosition fdata;
    fdata.Unserialization(obj);
    OnLocalPositionData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_LocalPositionSubscriber::OnRecieve(
  F_dji_sdk_LocalPosition Data) {}

U_dji_sdk_LocalPositionSubscriber*
U_dji_sdk_LocalPositionSubscriber::Create_LocalPosition_Subscriber(
  FString _TopicName) {
    U_dji_sdk_LocalPositionSubscriber* sub =
      NewObject<U_dji_sdk_LocalPositionSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_Illuminance::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("illuminance") && v["illuminance"].IsDouble())
        this->illuminance = v["illuminance"].GetDouble();

    if (v.HasMember("variance") && v["variance"].IsDouble())
        this->variance = v["variance"].GetDouble();
}

rapidjson::Value F_sensor_msgs_Illuminance::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tilluminance;
    tilluminance.SetString("illuminance");

    s.AddMember(tilluminance, this->illuminance, d.GetAllocator());

    rapidjson::Value tvariance;
    tvariance.SetString("variance");

    s.AddMember(tvariance, this->variance, d.GetAllocator());

    return s;
}

U_sensor_msgs_IlluminanceAdvertiser*
U_sensor_msgs_IlluminanceAdvertiser::Create_Illuminance_Advertiser(
  FString TopicName) {
    U_sensor_msgs_IlluminanceAdvertiser* c =
      NewObject<U_sensor_msgs_IlluminanceAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_IlluminanceAdvertiser::Publish(
  F_sensor_msgs_Illuminance Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_IlluminanceAdvertiser::U_sensor_msgs_IlluminanceAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Illuminance");
}

U_sensor_msgs_IlluminanceSubscriber::U_sensor_msgs_IlluminanceSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Illuminance");
}
void U_sensor_msgs_IlluminanceSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_Illuminance fdata;
    fdata.Unserialization(obj);
    OnIlluminanceData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_IlluminanceSubscriber::OnRecieve(
  F_sensor_msgs_Illuminance Data) {}

U_sensor_msgs_IlluminanceSubscriber*
U_sensor_msgs_IlluminanceSubscriber::Create_Illuminance_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_IlluminanceSubscriber* sub =
      NewObject<U_sensor_msgs_IlluminanceSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_nav_msgs_GridCells::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("cell_width") && v["cell_width"].IsDouble())
        this->cell_width = v["cell_width"].GetDouble();

    if (v.HasMember("cell_height") && v["cell_height"].IsDouble())
        this->cell_height = v["cell_height"].GetDouble();
}

rapidjson::Value F_nav_msgs_GridCells::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tcell_width;
    tcell_width.SetString("cell_width");

    s.AddMember(tcell_width, this->cell_width, d.GetAllocator());

    rapidjson::Value tcell_height;
    tcell_height.SetString("cell_height");

    s.AddMember(tcell_height, this->cell_height, d.GetAllocator());

    return s;
}

U_nav_msgs_GridCellsAdvertiser*
U_nav_msgs_GridCellsAdvertiser::Create_GridCells_Advertiser(FString TopicName) {
    U_nav_msgs_GridCellsAdvertiser* c =
      NewObject<U_nav_msgs_GridCellsAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_nav_msgs_GridCellsAdvertiser::Publish(F_nav_msgs_GridCells Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_nav_msgs_GridCellsAdvertiser::U_nav_msgs_GridCellsAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("nav_msgs/GridCells");
}

U_nav_msgs_GridCellsSubscriber::U_nav_msgs_GridCellsSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("nav_msgs/GridCells");
}
void U_nav_msgs_GridCellsSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_nav_msgs_GridCells fdata;
    fdata.Unserialization(obj);
    OnGridCellsData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_nav_msgs_GridCellsSubscriber::OnRecieve(F_nav_msgs_GridCells Data) {}

U_nav_msgs_GridCellsSubscriber*
U_nav_msgs_GridCellsSubscriber::Create_GridCells_Subscriber(
  FString _TopicName) {
    U_nav_msgs_GridCellsSubscriber* sub =
      NewObject<U_nav_msgs_GridCellsSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_Joy::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("axes") && v["axes"].IsArray()) {
        rapidjson::Value& Aaxes = v["axes"];
        for (rapidjson::SizeType i = 0; i < Aaxes.Size(); i++) {
            rapidjson::Value& kv = Aaxes[i];

            if (kv.IsDouble()) this->axes.Add(kv.GetDouble());
        }
    }

    if (v.HasMember("buttons") && v["buttons"].IsArray()) {
        rapidjson::Value& Abuttons = v["buttons"];
        for (rapidjson::SizeType i = 0; i < Abuttons.Size(); i++) {
            rapidjson::Value& kv = Abuttons[i];

            if (kv.IsInt()) this->buttons.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_sensor_msgs_Joy::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value taxes;
    taxes.SetString("axes");

    rapidjson::Value Aaxes(rapidjson::kArrayType);
    for (float Element : axes) {
        Aaxes.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(taxes, Aaxes, d.GetAllocator());

    rapidjson::Value tbuttons;
    tbuttons.SetString("buttons");

    rapidjson::Value Abuttons(rapidjson::kArrayType);
    for (int32 Element : buttons) {
        Abuttons.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tbuttons, Abuttons, d.GetAllocator());

    return s;
}

U_sensor_msgs_JoyAdvertiser* U_sensor_msgs_JoyAdvertiser::Create_Joy_Advertiser(
  FString TopicName) {
    U_sensor_msgs_JoyAdvertiser* c = NewObject<U_sensor_msgs_JoyAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_JoyAdvertiser::Publish(F_sensor_msgs_Joy Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_JoyAdvertiser::U_sensor_msgs_JoyAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Joy");
}

U_sensor_msgs_JoySubscriber::U_sensor_msgs_JoySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Joy");
}
void U_sensor_msgs_JoySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_Joy fdata;
    fdata.Unserialization(obj);
    OnJoyData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_JoySubscriber::OnRecieve(F_sensor_msgs_Joy Data) {}

U_sensor_msgs_JoySubscriber* U_sensor_msgs_JoySubscriber::Create_Joy_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_JoySubscriber* sub = NewObject<U_sensor_msgs_JoySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_RCChannels::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("ts") && v["ts"].IsInt()) this->ts = v["ts"].GetInt();

    if (v.HasMember("roll") && v["roll"].IsDouble())
        this->roll = v["roll"].GetDouble();

    if (v.HasMember("pitch") && v["pitch"].IsDouble())
        this->pitch = v["pitch"].GetDouble();

    if (v.HasMember("yaw") && v["yaw"].IsDouble())
        this->yaw = v["yaw"].GetDouble();

    if (v.HasMember("throttle") && v["throttle"].IsDouble())
        this->throttle = v["throttle"].GetDouble();

    if (v.HasMember("mode") && v["mode"].IsDouble())
        this->mode = v["mode"].GetDouble();

    if (v.HasMember("gear") && v["gear"].IsDouble())
        this->gear = v["gear"].GetDouble();
}

rapidjson::Value F_dji_sdk_RCChannels::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tts;
    tts.SetString("ts");

    s.AddMember(tts, this->ts, d.GetAllocator());

    rapidjson::Value troll;
    troll.SetString("roll");

    s.AddMember(troll, this->roll, d.GetAllocator());

    rapidjson::Value tpitch;
    tpitch.SetString("pitch");

    s.AddMember(tpitch, this->pitch, d.GetAllocator());

    rapidjson::Value tyaw;
    tyaw.SetString("yaw");

    s.AddMember(tyaw, this->yaw, d.GetAllocator());

    rapidjson::Value tthrottle;
    tthrottle.SetString("throttle");

    s.AddMember(tthrottle, this->throttle, d.GetAllocator());

    rapidjson::Value tmode;
    tmode.SetString("mode");

    s.AddMember(tmode, this->mode, d.GetAllocator());

    rapidjson::Value tgear;
    tgear.SetString("gear");

    s.AddMember(tgear, this->gear, d.GetAllocator());

    return s;
}

U_dji_sdk_RCChannelsAdvertiser*
U_dji_sdk_RCChannelsAdvertiser::Create_RCChannels_Advertiser(
  FString TopicName) {
    U_dji_sdk_RCChannelsAdvertiser* c =
      NewObject<U_dji_sdk_RCChannelsAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_RCChannelsAdvertiser::Publish(F_dji_sdk_RCChannels Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_RCChannelsAdvertiser::U_dji_sdk_RCChannelsAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/RCChannels");
}

U_dji_sdk_RCChannelsSubscriber::U_dji_sdk_RCChannelsSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/RCChannels");
}
void U_dji_sdk_RCChannelsSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_RCChannels fdata;
    fdata.Unserialization(obj);
    OnRCChannelsData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_RCChannelsSubscriber::OnRecieve(F_dji_sdk_RCChannels Data) {}

U_dji_sdk_RCChannelsSubscriber*
U_dji_sdk_RCChannelsSubscriber::Create_RCChannels_Subscriber(
  FString _TopicName) {
    U_dji_sdk_RCChannelsSubscriber* sub =
      NewObject<U_dji_sdk_RCChannelsSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_Acceleration::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("ts") && v["ts"].IsInt()) this->ts = v["ts"].GetInt();

    if (v.HasMember("ax") && v["ax"].IsDouble()) this->ax = v["ax"].GetDouble();

    if (v.HasMember("ay") && v["ay"].IsDouble()) this->ay = v["ay"].GetDouble();

    if (v.HasMember("az") && v["az"].IsDouble()) this->az = v["az"].GetDouble();
}

rapidjson::Value F_dji_sdk_Acceleration::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tts;
    tts.SetString("ts");

    s.AddMember(tts, this->ts, d.GetAllocator());

    rapidjson::Value tax;
    tax.SetString("ax");

    s.AddMember(tax, this->ax, d.GetAllocator());

    rapidjson::Value tay;
    tay.SetString("ay");

    s.AddMember(tay, this->ay, d.GetAllocator());

    rapidjson::Value taz;
    taz.SetString("az");

    s.AddMember(taz, this->az, d.GetAllocator());

    return s;
}

U_dji_sdk_AccelerationAdvertiser*
U_dji_sdk_AccelerationAdvertiser::Create_Acceleration_Advertiser(
  FString TopicName) {
    U_dji_sdk_AccelerationAdvertiser* c =
      NewObject<U_dji_sdk_AccelerationAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_AccelerationAdvertiser::Publish(F_dji_sdk_Acceleration Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_AccelerationAdvertiser::U_dji_sdk_AccelerationAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/Acceleration");
}

U_dji_sdk_AccelerationSubscriber::U_dji_sdk_AccelerationSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/Acceleration");
}
void U_dji_sdk_AccelerationSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_Acceleration fdata;
    fdata.Unserialization(obj);
    OnAccelerationData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_AccelerationSubscriber::OnRecieve(F_dji_sdk_Acceleration Data) {}

U_dji_sdk_AccelerationSubscriber*
U_dji_sdk_AccelerationSubscriber::Create_Acceleration_Subscriber(
  FString _TopicName) {
    U_dji_sdk_AccelerationSubscriber* sub =
      NewObject<U_dji_sdk_AccelerationSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Point32::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("x") && v["x"].IsDouble()) this->x = v["x"].GetDouble();

    if (v.HasMember("y") && v["y"].IsDouble()) this->y = v["y"].GetDouble();

    if (v.HasMember("z") && v["z"].IsDouble()) this->z = v["z"].GetDouble();
}

rapidjson::Value F_geometry_msgs_Point32::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tx;
    tx.SetString("x");

    s.AddMember(tx, this->x, d.GetAllocator());

    rapidjson::Value ty;
    ty.SetString("y");

    s.AddMember(ty, this->y, d.GetAllocator());

    rapidjson::Value tz;
    tz.SetString("z");

    s.AddMember(tz, this->z, d.GetAllocator());

    return s;
}

U_geometry_msgs_Point32Advertiser*
U_geometry_msgs_Point32Advertiser::Create_Point32_Advertiser(
  FString TopicName) {
    U_geometry_msgs_Point32Advertiser* c =
      NewObject<U_geometry_msgs_Point32Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_Point32Advertiser::Publish(F_geometry_msgs_Point32 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_Point32Advertiser::U_geometry_msgs_Point32Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Point32");
}

U_geometry_msgs_Point32Subscriber::U_geometry_msgs_Point32Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Point32");
}
void U_geometry_msgs_Point32Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Point32 fdata;
    fdata.Unserialization(obj);
    OnPoint32Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_Point32Subscriber::OnRecieve(
  F_geometry_msgs_Point32 Data) {}

U_geometry_msgs_Point32Subscriber*
U_geometry_msgs_Point32Subscriber::Create_Point32_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_Point32Subscriber* sub =
      NewObject<U_geometry_msgs_Point32Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_trajectory_msgs_MultiDOFJointTrajectory::Unserialization(
  rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);
}

rapidjson::Value F_trajectory_msgs_MultiDOFJointTrajectory::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    return s;
}

U_trajectory_msgs_MultiDOFJointTrajectoryAdvertiser*
U_trajectory_msgs_MultiDOFJointTrajectoryAdvertiser::
  Create_MultiDOFJointTrajectory_Advertiser(FString TopicName) {
    U_trajectory_msgs_MultiDOFJointTrajectoryAdvertiser* c =
      NewObject<U_trajectory_msgs_MultiDOFJointTrajectoryAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_trajectory_msgs_MultiDOFJointTrajectoryAdvertiser::Publish(
  F_trajectory_msgs_MultiDOFJointTrajectory Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_trajectory_msgs_MultiDOFJointTrajectoryAdvertiser::
  U_trajectory_msgs_MultiDOFJointTrajectoryAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("trajectory_msgs/MultiDOFJointTrajectory");
}

U_trajectory_msgs_MultiDOFJointTrajectorySubscriber::
  U_trajectory_msgs_MultiDOFJointTrajectorySubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("trajectory_msgs/MultiDOFJointTrajectory");
}
void U_trajectory_msgs_MultiDOFJointTrajectorySubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_trajectory_msgs_MultiDOFJointTrajectory fdata;
    fdata.Unserialization(obj);
    OnMultiDOFJointTrajectoryData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_trajectory_msgs_MultiDOFJointTrajectorySubscriber::OnRecieve(
  F_trajectory_msgs_MultiDOFJointTrajectory Data) {}

U_trajectory_msgs_MultiDOFJointTrajectorySubscriber*
U_trajectory_msgs_MultiDOFJointTrajectorySubscriber::
  Create_MultiDOFJointTrajectory_Subscriber(FString _TopicName) {
    U_trajectory_msgs_MultiDOFJointTrajectorySubscriber* sub =
      NewObject<U_trajectory_msgs_MultiDOFJointTrajectorySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Float32::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsDouble())
        this->data = v["data"].GetDouble();
}

rapidjson::Value F_std_msgs_Float32::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_Float32Advertiser*
U_std_msgs_Float32Advertiser::Create_Float32_Advertiser(FString TopicName) {
    U_std_msgs_Float32Advertiser* c = NewObject<U_std_msgs_Float32Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Float32Advertiser::Publish(F_std_msgs_Float32 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Float32Advertiser::U_std_msgs_Float32Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Float32");
}

U_std_msgs_Float32Subscriber::U_std_msgs_Float32Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Float32");
}
void U_std_msgs_Float32Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Float32 fdata;
    fdata.Unserialization(obj);
    OnFloat32Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Float32Subscriber::OnRecieve(F_std_msgs_Float32 Data) {}

U_std_msgs_Float32Subscriber*
U_std_msgs_Float32Subscriber::Create_Float32_Subscriber(FString _TopicName) {
    U_std_msgs_Float32Subscriber* sub =
      NewObject<U_std_msgs_Float32Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_TimeStamp::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("time") && v["time"].IsInt())
        this->time = v["time"].GetInt();

    if (v.HasMember("time_ns") && v["time_ns"].IsInt())
        this->time_ns = v["time_ns"].GetInt();

    if (v.HasMember("sync_flag") && v["sync_flag"].IsInt())
        this->sync_flag = v["sync_flag"].GetInt();
}

rapidjson::Value F_dji_sdk_TimeStamp::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value ttime;
    ttime.SetString("time");

    s.AddMember(ttime, this->time, d.GetAllocator());

    rapidjson::Value ttime_ns;
    ttime_ns.SetString("time_ns");

    s.AddMember(ttime_ns, this->time_ns, d.GetAllocator());

    rapidjson::Value tsync_flag;
    tsync_flag.SetString("sync_flag");

    s.AddMember(tsync_flag, this->sync_flag, d.GetAllocator());

    return s;
}

U_dji_sdk_TimeStampAdvertiser*
U_dji_sdk_TimeStampAdvertiser::Create_TimeStamp_Advertiser(FString TopicName) {
    U_dji_sdk_TimeStampAdvertiser* c =
      NewObject<U_dji_sdk_TimeStampAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_TimeStampAdvertiser::Publish(F_dji_sdk_TimeStamp Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_TimeStampAdvertiser::U_dji_sdk_TimeStampAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/TimeStamp");
}

U_dji_sdk_TimeStampSubscriber::U_dji_sdk_TimeStampSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/TimeStamp");
}
void U_dji_sdk_TimeStampSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_TimeStamp fdata;
    fdata.Unserialization(obj);
    OnTimeStampData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_TimeStampSubscriber::OnRecieve(F_dji_sdk_TimeStamp Data) {}

U_dji_sdk_TimeStampSubscriber*
U_dji_sdk_TimeStampSubscriber::Create_TimeStamp_Subscriber(FString _TopicName) {
    U_dji_sdk_TimeStampSubscriber* sub =
      NewObject<U_dji_sdk_TimeStampSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_NavSatStatus::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("status") && v["status"].IsInt())
        this->status = v["status"].GetInt();

    if (v.HasMember("service") && v["service"].IsInt())
        this->service = v["service"].GetInt();
}

rapidjson::Value F_sensor_msgs_NavSatStatus::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tstatus;
    tstatus.SetString("status");

    s.AddMember(tstatus, this->status, d.GetAllocator());

    rapidjson::Value tservice;
    tservice.SetString("service");

    s.AddMember(tservice, this->service, d.GetAllocator());

    rapidjson::Value tCONSTANT_SERVICE_GPS;
    tCONSTANT_SERVICE_GPS.SetString("CONSTANT_SERVICE_GPS");

    s.AddMember(tCONSTANT_SERVICE_GPS, this->CONSTANT_SERVICE_GPS,
                d.GetAllocator());

    rapidjson::Value tCONSTANT_SERVICE_GLONASS;
    tCONSTANT_SERVICE_GLONASS.SetString("CONSTANT_SERVICE_GLONASS");

    s.AddMember(tCONSTANT_SERVICE_GLONASS, this->CONSTANT_SERVICE_GLONASS,
                d.GetAllocator());

    rapidjson::Value tCONSTANT_SERVICE_GALILEO;
    tCONSTANT_SERVICE_GALILEO.SetString("CONSTANT_SERVICE_GALILEO");

    s.AddMember(tCONSTANT_SERVICE_GALILEO, this->CONSTANT_SERVICE_GALILEO,
                d.GetAllocator());

    return s;
}

U_sensor_msgs_NavSatStatusAdvertiser*
U_sensor_msgs_NavSatStatusAdvertiser::Create_NavSatStatus_Advertiser(
  FString TopicName) {
    U_sensor_msgs_NavSatStatusAdvertiser* c =
      NewObject<U_sensor_msgs_NavSatStatusAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_NavSatStatusAdvertiser::Publish(
  F_sensor_msgs_NavSatStatus Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_NavSatStatusAdvertiser::U_sensor_msgs_NavSatStatusAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/NavSatStatus");
}

U_sensor_msgs_NavSatStatusSubscriber::U_sensor_msgs_NavSatStatusSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/NavSatStatus");
}
void U_sensor_msgs_NavSatStatusSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_NavSatStatus fdata;
    fdata.Unserialization(obj);
    OnNavSatStatusData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_NavSatStatusSubscriber::OnRecieve(
  F_sensor_msgs_NavSatStatus Data) {}

U_sensor_msgs_NavSatStatusSubscriber*
U_sensor_msgs_NavSatStatusSubscriber::Create_NavSatStatus_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_NavSatStatusSubscriber* sub =
      NewObject<U_sensor_msgs_NavSatStatusSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionFollowmeTask::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("mode") && v["mode"].IsInt())
        this->mode = v["mode"].GetInt();

    if (v.HasMember("yaw_mode") && v["yaw_mode"].IsInt())
        this->yaw_mode = v["yaw_mode"].GetInt();

    if (v.HasMember("initial_latitude") && v["initial_latitude"].IsDouble())
        this->initial_latitude = v["initial_latitude"].GetDouble();

    if (v.HasMember("initial_longitude") && v["initial_longitude"].IsDouble())
        this->initial_longitude = v["initial_longitude"].GetDouble();

    if (v.HasMember("initial_altitude") && v["initial_altitude"].IsInt())
        this->initial_altitude = v["initial_altitude"].GetInt();

    if (v.HasMember("sensitivity") && v["sensitivity"].IsInt())
        this->sensitivity = v["sensitivity"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionFollowmeTask::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tmode;
    tmode.SetString("mode");

    s.AddMember(tmode, this->mode, d.GetAllocator());

    rapidjson::Value tyaw_mode;
    tyaw_mode.SetString("yaw_mode");

    s.AddMember(tyaw_mode, this->yaw_mode, d.GetAllocator());

    rapidjson::Value tinitial_latitude;
    tinitial_latitude.SetString("initial_latitude");

    s.AddMember(tinitial_latitude, this->initial_latitude, d.GetAllocator());

    rapidjson::Value tinitial_longitude;
    tinitial_longitude.SetString("initial_longitude");

    s.AddMember(tinitial_longitude, this->initial_longitude, d.GetAllocator());

    rapidjson::Value tinitial_altitude;
    tinitial_altitude.SetString("initial_altitude");

    s.AddMember(tinitial_altitude, this->initial_altitude, d.GetAllocator());

    rapidjson::Value tsensitivity;
    tsensitivity.SetString("sensitivity");

    s.AddMember(tsensitivity, this->sensitivity, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionFollowmeTaskAdvertiser*
U_dji_sdk_MissionFollowmeTaskAdvertiser::Create_MissionFollowmeTask_Advertiser(
  FString TopicName) {
    U_dji_sdk_MissionFollowmeTaskAdvertiser* c =
      NewObject<U_dji_sdk_MissionFollowmeTaskAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionFollowmeTaskAdvertiser::Publish(
  F_dji_sdk_MissionFollowmeTask Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionFollowmeTaskAdvertiser::
  U_dji_sdk_MissionFollowmeTaskAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionFollowmeTask");
}

U_dji_sdk_MissionFollowmeTaskSubscriber::
  U_dji_sdk_MissionFollowmeTaskSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionFollowmeTask");
}
void U_dji_sdk_MissionFollowmeTaskSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionFollowmeTask fdata;
    fdata.Unserialization(obj);
    OnMissionFollowmeTaskData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionFollowmeTaskSubscriber::OnRecieve(
  F_dji_sdk_MissionFollowmeTask Data) {}

U_dji_sdk_MissionFollowmeTaskSubscriber*
U_dji_sdk_MissionFollowmeTaskSubscriber::Create_MissionFollowmeTask_Subscriber(
  FString _TopicName) {
    U_dji_sdk_MissionFollowmeTaskSubscriber* sub =
      NewObject<U_dji_sdk_MissionFollowmeTaskSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionStatusOther::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("mission_type") && v["mission_type"].IsInt())
        this->mission_type = v["mission_type"].GetInt();

    if (v.HasMember("last_mission_type") && v["last_mission_type"].IsInt())
        this->last_mission_type = v["last_mission_type"].GetInt();

    if (v.HasMember("is_broken") && v["is_broken"].IsInt())
        this->is_broken = v["is_broken"].GetInt();

    if (v.HasMember("error_code") && v["error_code"].IsInt())
        this->error_code = v["error_code"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionStatusOther::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tmission_type;
    tmission_type.SetString("mission_type");

    s.AddMember(tmission_type, this->mission_type, d.GetAllocator());

    rapidjson::Value tlast_mission_type;
    tlast_mission_type.SetString("last_mission_type");

    s.AddMember(tlast_mission_type, this->last_mission_type, d.GetAllocator());

    rapidjson::Value tis_broken;
    tis_broken.SetString("is_broken");

    s.AddMember(tis_broken, this->is_broken, d.GetAllocator());

    rapidjson::Value terror_code;
    terror_code.SetString("error_code");

    s.AddMember(terror_code, this->error_code, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionStatusOtherAdvertiser*
U_dji_sdk_MissionStatusOtherAdvertiser::Create_MissionStatusOther_Advertiser(
  FString TopicName) {
    U_dji_sdk_MissionStatusOtherAdvertiser* c =
      NewObject<U_dji_sdk_MissionStatusOtherAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionStatusOtherAdvertiser::Publish(
  F_dji_sdk_MissionStatusOther Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionStatusOtherAdvertiser::U_dji_sdk_MissionStatusOtherAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionStatusOther");
}

U_dji_sdk_MissionStatusOtherSubscriber::U_dji_sdk_MissionStatusOtherSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionStatusOther");
}
void U_dji_sdk_MissionStatusOtherSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionStatusOther fdata;
    fdata.Unserialization(obj);
    OnMissionStatusOtherData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionStatusOtherSubscriber::OnRecieve(
  F_dji_sdk_MissionStatusOther Data) {}

U_dji_sdk_MissionStatusOtherSubscriber*
U_dji_sdk_MissionStatusOtherSubscriber::Create_MissionStatusOther_Subscriber(
  FString _TopicName) {
    U_dji_sdk_MissionStatusOtherSubscriber* sub =
      NewObject<U_dji_sdk_MissionStatusOtherSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_PointStamped::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("point") && v["point"].IsObject())
        this->point.Unserialization(v["point"]);
}

rapidjson::Value F_geometry_msgs_PointStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tpoint;
    tpoint.SetString("point");

    s.AddMember(tpoint, this->point.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_PointStampedAdvertiser*
U_geometry_msgs_PointStampedAdvertiser::Create_PointStamped_Advertiser(
  FString TopicName) {
    U_geometry_msgs_PointStampedAdvertiser* c =
      NewObject<U_geometry_msgs_PointStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_PointStampedAdvertiser::Publish(
  F_geometry_msgs_PointStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_PointStampedAdvertiser::U_geometry_msgs_PointStampedAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PointStamped");
}

U_geometry_msgs_PointStampedSubscriber::U_geometry_msgs_PointStampedSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PointStamped");
}
void U_geometry_msgs_PointStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_PointStamped fdata;
    fdata.Unserialization(obj);
    OnPointStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_PointStampedSubscriber::OnRecieve(
  F_geometry_msgs_PointStamped Data) {}

U_geometry_msgs_PointStampedSubscriber*
U_geometry_msgs_PointStampedSubscriber::Create_PointStamped_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_PointStampedSubscriber* sub =
      NewObject<U_geometry_msgs_PointStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_Range::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("radiation_type") && v["radiation_type"].IsInt())
        this->radiation_type = v["radiation_type"].GetInt();

    if (v.HasMember("field_of_view") && v["field_of_view"].IsDouble())
        this->field_of_view = v["field_of_view"].GetDouble();

    if (v.HasMember("min_range") && v["min_range"].IsDouble())
        this->min_range = v["min_range"].GetDouble();

    if (v.HasMember("max_range") && v["max_range"].IsDouble())
        this->max_range = v["max_range"].GetDouble();

    if (v.HasMember("range") && v["range"].IsDouble())
        this->range = v["range"].GetDouble();
}

rapidjson::Value F_sensor_msgs_Range::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tradiation_type;
    tradiation_type.SetString("radiation_type");

    s.AddMember(tradiation_type, this->radiation_type, d.GetAllocator());

    rapidjson::Value tfield_of_view;
    tfield_of_view.SetString("field_of_view");

    s.AddMember(tfield_of_view, this->field_of_view, d.GetAllocator());

    rapidjson::Value tmin_range;
    tmin_range.SetString("min_range");

    s.AddMember(tmin_range, this->min_range, d.GetAllocator());

    rapidjson::Value tmax_range;
    tmax_range.SetString("max_range");

    s.AddMember(tmax_range, this->max_range, d.GetAllocator());

    rapidjson::Value trange;
    trange.SetString("range");

    s.AddMember(trange, this->range, d.GetAllocator());

    rapidjson::Value tCONSTANT_ULTRASOUND;
    tCONSTANT_ULTRASOUND.SetString("CONSTANT_ULTRASOUND");

    s.AddMember(tCONSTANT_ULTRASOUND, this->CONSTANT_ULTRASOUND,
                d.GetAllocator());

    rapidjson::Value tCONSTANT_INFRARED;
    tCONSTANT_INFRARED.SetString("CONSTANT_INFRARED");

    s.AddMember(tCONSTANT_INFRARED, this->CONSTANT_INFRARED, d.GetAllocator());

    return s;
}

U_sensor_msgs_RangeAdvertiser*
U_sensor_msgs_RangeAdvertiser::Create_Range_Advertiser(FString TopicName) {
    U_sensor_msgs_RangeAdvertiser* c =
      NewObject<U_sensor_msgs_RangeAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_RangeAdvertiser::Publish(F_sensor_msgs_Range Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_RangeAdvertiser::U_sensor_msgs_RangeAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Range");
}

U_sensor_msgs_RangeSubscriber::U_sensor_msgs_RangeSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Range");
}
void U_sensor_msgs_RangeSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_Range fdata;
    fdata.Unserialization(obj);
    OnRangeData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_RangeSubscriber::OnRecieve(F_sensor_msgs_Range Data) {}

U_sensor_msgs_RangeSubscriber*
U_sensor_msgs_RangeSubscriber::Create_Range_Subscriber(FString _TopicName) {
    U_sensor_msgs_RangeSubscriber* sub =
      NewObject<U_sensor_msgs_RangeSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Quaternion::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("x") && v["x"].IsDouble()) this->x = v["x"].GetDouble();

    if (v.HasMember("y") && v["y"].IsDouble()) this->y = v["y"].GetDouble();

    if (v.HasMember("z") && v["z"].IsDouble()) this->z = v["z"].GetDouble();

    if (v.HasMember("w") && v["w"].IsDouble()) this->w = v["w"].GetDouble();
}

rapidjson::Value F_geometry_msgs_Quaternion::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tx;
    tx.SetString("x");

    s.AddMember(tx, this->x, d.GetAllocator());

    rapidjson::Value ty;
    ty.SetString("y");

    s.AddMember(ty, this->y, d.GetAllocator());

    rapidjson::Value tz;
    tz.SetString("z");

    s.AddMember(tz, this->z, d.GetAllocator());

    rapidjson::Value tw;
    tw.SetString("w");

    s.AddMember(tw, this->w, d.GetAllocator());

    return s;
}

U_geometry_msgs_QuaternionAdvertiser*
U_geometry_msgs_QuaternionAdvertiser::Create_Quaternion_Advertiser(
  FString TopicName) {
    U_geometry_msgs_QuaternionAdvertiser* c =
      NewObject<U_geometry_msgs_QuaternionAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_QuaternionAdvertiser::Publish(
  F_geometry_msgs_Quaternion Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_QuaternionAdvertiser::U_geometry_msgs_QuaternionAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Quaternion");
}

U_geometry_msgs_QuaternionSubscriber::U_geometry_msgs_QuaternionSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Quaternion");
}
void U_geometry_msgs_QuaternionSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Quaternion fdata;
    fdata.Unserialization(obj);
    OnQuaternionData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_QuaternionSubscriber::OnRecieve(
  F_geometry_msgs_Quaternion Data) {}

U_geometry_msgs_QuaternionSubscriber*
U_geometry_msgs_QuaternionSubscriber::Create_Quaternion_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_QuaternionSubscriber* sub =
      NewObject<U_geometry_msgs_QuaternionSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Pose2D::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("x") && v["x"].IsDouble()) this->x = v["x"].GetDouble();

    if (v.HasMember("y") && v["y"].IsDouble()) this->y = v["y"].GetDouble();

    if (v.HasMember("theta") && v["theta"].IsDouble())
        this->theta = v["theta"].GetDouble();
}

rapidjson::Value F_geometry_msgs_Pose2D::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tx;
    tx.SetString("x");

    s.AddMember(tx, this->x, d.GetAllocator());

    rapidjson::Value ty;
    ty.SetString("y");

    s.AddMember(ty, this->y, d.GetAllocator());

    rapidjson::Value ttheta;
    ttheta.SetString("theta");

    s.AddMember(ttheta, this->theta, d.GetAllocator());

    return s;
}

U_geometry_msgs_Pose2DAdvertiser*
U_geometry_msgs_Pose2DAdvertiser::Create_Pose2D_Advertiser(FString TopicName) {
    U_geometry_msgs_Pose2DAdvertiser* c =
      NewObject<U_geometry_msgs_Pose2DAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_Pose2DAdvertiser::Publish(F_geometry_msgs_Pose2D Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_Pose2DAdvertiser::U_geometry_msgs_Pose2DAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Pose2D");
}

U_geometry_msgs_Pose2DSubscriber::U_geometry_msgs_Pose2DSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Pose2D");
}
void U_geometry_msgs_Pose2DSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Pose2D fdata;
    fdata.Unserialization(obj);
    OnPose2DData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_Pose2DSubscriber::OnRecieve(F_geometry_msgs_Pose2D Data) {}

U_geometry_msgs_Pose2DSubscriber*
U_geometry_msgs_Pose2DSubscriber::Create_Pose2D_Subscriber(FString _TopicName) {
    U_geometry_msgs_Pose2DSubscriber* sub =
      NewObject<U_geometry_msgs_Pose2DSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Int8::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt())
        this->data = v["data"].GetInt();
}

rapidjson::Value F_std_msgs_Int8::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_Int8Advertiser* U_std_msgs_Int8Advertiser::Create_Int8_Advertiser(
  FString TopicName) {
    U_std_msgs_Int8Advertiser* c = NewObject<U_std_msgs_Int8Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Int8Advertiser::Publish(F_std_msgs_Int8 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Int8Advertiser::U_std_msgs_Int8Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int8");
}

U_std_msgs_Int8Subscriber::U_std_msgs_Int8Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int8");
}
void U_std_msgs_Int8Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Int8 fdata;
    fdata.Unserialization(obj);
    OnInt8Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Int8Subscriber::OnRecieve(F_std_msgs_Int8 Data) {}

U_std_msgs_Int8Subscriber* U_std_msgs_Int8Subscriber::Create_Int8_Subscriber(
  FString _TopicName) {
    U_std_msgs_Int8Subscriber* sub = NewObject<U_std_msgs_Int8Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_LaserEcho::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("echoes") && v["echoes"].IsArray()) {
        rapidjson::Value& Aechoes = v["echoes"];
        for (rapidjson::SizeType i = 0; i < Aechoes.Size(); i++) {
            rapidjson::Value& kv = Aechoes[i];

            if (kv.IsDouble()) this->echoes.Add(kv.GetDouble());
        }
    }
}

rapidjson::Value F_sensor_msgs_LaserEcho::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value techoes;
    techoes.SetString("echoes");

    rapidjson::Value Aechoes(rapidjson::kArrayType);
    for (float Element : echoes) {
        Aechoes.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(techoes, Aechoes, d.GetAllocator());

    return s;
}

U_sensor_msgs_LaserEchoAdvertiser*
U_sensor_msgs_LaserEchoAdvertiser::Create_LaserEcho_Advertiser(
  FString TopicName) {
    U_sensor_msgs_LaserEchoAdvertiser* c =
      NewObject<U_sensor_msgs_LaserEchoAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_LaserEchoAdvertiser::Publish(F_sensor_msgs_LaserEcho Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_LaserEchoAdvertiser::U_sensor_msgs_LaserEchoAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/LaserEcho");
}

U_sensor_msgs_LaserEchoSubscriber::U_sensor_msgs_LaserEchoSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/LaserEcho");
}
void U_sensor_msgs_LaserEchoSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_LaserEcho fdata;
    fdata.Unserialization(obj);
    OnLaserEchoData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_LaserEchoSubscriber::OnRecieve(
  F_sensor_msgs_LaserEcho Data) {}

U_sensor_msgs_LaserEchoSubscriber*
U_sensor_msgs_LaserEchoSubscriber::Create_LaserEcho_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_LaserEchoSubscriber* sub =
      NewObject<U_sensor_msgs_LaserEchoSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_String::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsString())
        this->data = FString(v["data"].GetString());
}

rapidjson::Value F_std_msgs_String::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value sdata;
    std::string fuck_data = TCHAR_TO_UTF8(*this->data);
    sdata.SetString(rapidjson::StringRef(fuck_data.c_str()));
    s.AddMember(tdata, sdata, d.GetAllocator());

    return s;
}

U_std_msgs_StringAdvertiser*
U_std_msgs_StringAdvertiser::Create_String_Advertiser(FString TopicName) {
    U_std_msgs_StringAdvertiser* c = NewObject<U_std_msgs_StringAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_StringAdvertiser::Publish(F_std_msgs_String Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_StringAdvertiser::U_std_msgs_StringAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/String");
}

U_std_msgs_StringSubscriber::U_std_msgs_StringSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/String");
}
void U_std_msgs_StringSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_String fdata;
    fdata.Unserialization(obj);
    OnStringData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_StringSubscriber::OnRecieve(F_std_msgs_String Data) {}

U_std_msgs_StringSubscriber*
U_std_msgs_StringSubscriber::Create_String_Subscriber(FString _TopicName) {
    U_std_msgs_StringSubscriber* sub = NewObject<U_std_msgs_StringSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Polygon::Unserialization(rapidjson::Value& v) {}

rapidjson::Value F_geometry_msgs_Polygon::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    return s;
}

U_geometry_msgs_PolygonAdvertiser*
U_geometry_msgs_PolygonAdvertiser::Create_Polygon_Advertiser(
  FString TopicName) {
    U_geometry_msgs_PolygonAdvertiser* c =
      NewObject<U_geometry_msgs_PolygonAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_PolygonAdvertiser::Publish(F_geometry_msgs_Polygon Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_PolygonAdvertiser::U_geometry_msgs_PolygonAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Polygon");
}

U_geometry_msgs_PolygonSubscriber::U_geometry_msgs_PolygonSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Polygon");
}
void U_geometry_msgs_PolygonSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Polygon fdata;
    fdata.Unserialization(obj);
    OnPolygonData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_PolygonSubscriber::OnRecieve(
  F_geometry_msgs_Polygon Data) {}

U_geometry_msgs_PolygonSubscriber*
U_geometry_msgs_PolygonSubscriber::Create_Polygon_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_PolygonSubscriber* sub =
      NewObject<U_geometry_msgs_PolygonSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_JointState::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);
}

rapidjson::Value F_sensor_msgs_JointState::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    return s;
}

U_sensor_msgs_JointStateAdvertiser*
U_sensor_msgs_JointStateAdvertiser::Create_JointState_Advertiser(
  FString TopicName) {
    U_sensor_msgs_JointStateAdvertiser* c =
      NewObject<U_sensor_msgs_JointStateAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_JointStateAdvertiser::Publish(
  F_sensor_msgs_JointState Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_JointStateAdvertiser::U_sensor_msgs_JointStateAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/JointState");
}

U_sensor_msgs_JointStateSubscriber::U_sensor_msgs_JointStateSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/JointState");
}
void U_sensor_msgs_JointStateSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_JointState fdata;
    fdata.Unserialization(obj);
    OnJointStateData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_JointStateSubscriber::OnRecieve(
  F_sensor_msgs_JointState Data) {}

U_sensor_msgs_JointStateSubscriber*
U_sensor_msgs_JointStateSubscriber::Create_JointState_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_JointStateSubscriber* sub =
      NewObject<U_sensor_msgs_JointStateSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_RelativeHumidity::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("relative_humidity") && v["relative_humidity"].IsDouble())
        this->relative_humidity = v["relative_humidity"].GetDouble();

    if (v.HasMember("variance") && v["variance"].IsDouble())
        this->variance = v["variance"].GetDouble();
}

rapidjson::Value F_sensor_msgs_RelativeHumidity::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value trelative_humidity;
    trelative_humidity.SetString("relative_humidity");

    s.AddMember(trelative_humidity, this->relative_humidity, d.GetAllocator());

    rapidjson::Value tvariance;
    tvariance.SetString("variance");

    s.AddMember(tvariance, this->variance, d.GetAllocator());

    return s;
}

U_sensor_msgs_RelativeHumidityAdvertiser*
U_sensor_msgs_RelativeHumidityAdvertiser::Create_RelativeHumidity_Advertiser(
  FString TopicName) {
    U_sensor_msgs_RelativeHumidityAdvertiser* c =
      NewObject<U_sensor_msgs_RelativeHumidityAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_RelativeHumidityAdvertiser::Publish(
  F_sensor_msgs_RelativeHumidity Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_RelativeHumidityAdvertiser::
  U_sensor_msgs_RelativeHumidityAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/RelativeHumidity");
}

U_sensor_msgs_RelativeHumiditySubscriber::
  U_sensor_msgs_RelativeHumiditySubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/RelativeHumidity");
}
void U_sensor_msgs_RelativeHumiditySubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_sensor_msgs_RelativeHumidity fdata;
    fdata.Unserialization(obj);
    OnRelativeHumidityData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_RelativeHumiditySubscriber::OnRecieve(
  F_sensor_msgs_RelativeHumidity Data) {}

U_sensor_msgs_RelativeHumiditySubscriber*
U_sensor_msgs_RelativeHumiditySubscriber::Create_RelativeHumidity_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_RelativeHumiditySubscriber* sub =
      NewObject<U_sensor_msgs_RelativeHumiditySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionWaypointTask::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("velocity_range") && v["velocity_range"].IsDouble())
        this->velocity_range = v["velocity_range"].GetDouble();

    if (v.HasMember("idle_velocity") && v["idle_velocity"].IsDouble())
        this->idle_velocity = v["idle_velocity"].GetDouble();

    if (v.HasMember("action_on_finish") && v["action_on_finish"].IsInt())
        this->action_on_finish = v["action_on_finish"].GetInt();

    if (v.HasMember("mission_exec_times") && v["mission_exec_times"].IsInt())
        this->mission_exec_times = v["mission_exec_times"].GetInt();

    if (v.HasMember("yaw_mode") && v["yaw_mode"].IsInt())
        this->yaw_mode = v["yaw_mode"].GetInt();

    if (v.HasMember("trace_mode") && v["trace_mode"].IsInt())
        this->trace_mode = v["trace_mode"].GetInt();

    if (v.HasMember("action_on_rc_lost") && v["action_on_rc_lost"].IsInt())
        this->action_on_rc_lost = v["action_on_rc_lost"].GetInt();

    if (v.HasMember("gimbal_pitch_mode") && v["gimbal_pitch_mode"].IsInt())
        this->gimbal_pitch_mode = v["gimbal_pitch_mode"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionWaypointTask::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tvelocity_range;
    tvelocity_range.SetString("velocity_range");

    s.AddMember(tvelocity_range, this->velocity_range, d.GetAllocator());

    rapidjson::Value tidle_velocity;
    tidle_velocity.SetString("idle_velocity");

    s.AddMember(tidle_velocity, this->idle_velocity, d.GetAllocator());

    rapidjson::Value taction_on_finish;
    taction_on_finish.SetString("action_on_finish");

    s.AddMember(taction_on_finish, this->action_on_finish, d.GetAllocator());

    rapidjson::Value tmission_exec_times;
    tmission_exec_times.SetString("mission_exec_times");

    s.AddMember(tmission_exec_times, this->mission_exec_times,
                d.GetAllocator());

    rapidjson::Value tyaw_mode;
    tyaw_mode.SetString("yaw_mode");

    s.AddMember(tyaw_mode, this->yaw_mode, d.GetAllocator());

    rapidjson::Value ttrace_mode;
    ttrace_mode.SetString("trace_mode");

    s.AddMember(ttrace_mode, this->trace_mode, d.GetAllocator());

    rapidjson::Value taction_on_rc_lost;
    taction_on_rc_lost.SetString("action_on_rc_lost");

    s.AddMember(taction_on_rc_lost, this->action_on_rc_lost, d.GetAllocator());

    rapidjson::Value tgimbal_pitch_mode;
    tgimbal_pitch_mode.SetString("gimbal_pitch_mode");

    s.AddMember(tgimbal_pitch_mode, this->gimbal_pitch_mode, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionWaypointTaskAdvertiser*
U_dji_sdk_MissionWaypointTaskAdvertiser::Create_MissionWaypointTask_Advertiser(
  FString TopicName) {
    U_dji_sdk_MissionWaypointTaskAdvertiser* c =
      NewObject<U_dji_sdk_MissionWaypointTaskAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionWaypointTaskAdvertiser::Publish(
  F_dji_sdk_MissionWaypointTask Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionWaypointTaskAdvertiser::
  U_dji_sdk_MissionWaypointTaskAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionWaypointTask");
}

U_dji_sdk_MissionWaypointTaskSubscriber::
  U_dji_sdk_MissionWaypointTaskSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionWaypointTask");
}
void U_dji_sdk_MissionWaypointTaskSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionWaypointTask fdata;
    fdata.Unserialization(obj);
    OnMissionWaypointTaskData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionWaypointTaskSubscriber::OnRecieve(
  F_dji_sdk_MissionWaypointTask Data) {}

U_dji_sdk_MissionWaypointTaskSubscriber*
U_dji_sdk_MissionWaypointTaskSubscriber::Create_MissionWaypointTask_Subscriber(
  FString _TopicName) {
    U_dji_sdk_MissionWaypointTaskSubscriber* sub =
      NewObject<U_dji_sdk_MissionWaypointTaskSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Empty::Unserialization(rapidjson::Value& v) {}

rapidjson::Value F_std_msgs_Empty::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    return s;
}

U_std_msgs_EmptyAdvertiser* U_std_msgs_EmptyAdvertiser::Create_Empty_Advertiser(
  FString TopicName) {
    U_std_msgs_EmptyAdvertiser* c = NewObject<U_std_msgs_EmptyAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_EmptyAdvertiser::Publish(F_std_msgs_Empty Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_EmptyAdvertiser::U_std_msgs_EmptyAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Empty");
}

U_std_msgs_EmptySubscriber::U_std_msgs_EmptySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Empty");
}
void U_std_msgs_EmptySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Empty fdata;
    fdata.Unserialization(obj);
    OnEmptyData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_EmptySubscriber::OnRecieve(F_std_msgs_Empty Data) {}

U_std_msgs_EmptySubscriber* U_std_msgs_EmptySubscriber::Create_Empty_Subscriber(
  FString _TopicName) {
    U_std_msgs_EmptySubscriber* sub = NewObject<U_std_msgs_EmptySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_nav_msgs_Path::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);
}

rapidjson::Value F_nav_msgs_Path::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    return s;
}

U_nav_msgs_PathAdvertiser* U_nav_msgs_PathAdvertiser::Create_Path_Advertiser(
  FString TopicName) {
    U_nav_msgs_PathAdvertiser* c = NewObject<U_nav_msgs_PathAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_nav_msgs_PathAdvertiser::Publish(F_nav_msgs_Path Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_nav_msgs_PathAdvertiser::U_nav_msgs_PathAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("nav_msgs/Path");
}

U_nav_msgs_PathSubscriber::U_nav_msgs_PathSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("nav_msgs/Path");
}
void U_nav_msgs_PathSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_nav_msgs_Path fdata;
    fdata.Unserialization(obj);
    OnPathData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_nav_msgs_PathSubscriber::OnRecieve(F_nav_msgs_Path Data) {}

U_nav_msgs_PathSubscriber* U_nav_msgs_PathSubscriber::Create_Path_Subscriber(
  FString _TopicName) {
    U_nav_msgs_PathSubscriber* sub = NewObject<U_nav_msgs_PathSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Int64::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt())
        this->data = v["data"].GetInt();
}

rapidjson::Value F_std_msgs_Int64::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_Int64Advertiser* U_std_msgs_Int64Advertiser::Create_Int64_Advertiser(
  FString TopicName) {
    U_std_msgs_Int64Advertiser* c = NewObject<U_std_msgs_Int64Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Int64Advertiser::Publish(F_std_msgs_Int64 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Int64Advertiser::U_std_msgs_Int64Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int64");
}

U_std_msgs_Int64Subscriber::U_std_msgs_Int64Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int64");
}
void U_std_msgs_Int64Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Int64 fdata;
    fdata.Unserialization(obj);
    OnInt64Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Int64Subscriber::OnRecieve(F_std_msgs_Int64 Data) {}

U_std_msgs_Int64Subscriber* U_std_msgs_Int64Subscriber::Create_Int64_Subscriber(
  FString _TopicName) {
    U_std_msgs_Int64Subscriber* sub = NewObject<U_std_msgs_Int64Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_PointCloud2::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("height") && v["height"].IsInt())
        this->height = v["height"].GetInt();

    if (v.HasMember("width") && v["width"].IsInt())
        this->width = v["width"].GetInt();

    if (v.HasMember("is_bigendian") && v["is_bigendian"].IsBool())
        this->is_bigendian = v["is_bigendian"].GetBool();

    if (v.HasMember("point_step") && v["point_step"].IsInt())
        this->point_step = v["point_step"].GetInt();

    if (v.HasMember("row_step") && v["row_step"].IsInt())
        this->row_step = v["row_step"].GetInt();

    if (v.HasMember("is_dense") && v["is_dense"].IsBool())
        this->is_dense = v["is_dense"].GetBool();

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_sensor_msgs_PointCloud2::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value theight;
    theight.SetString("height");

    s.AddMember(theight, this->height, d.GetAllocator());

    rapidjson::Value twidth;
    twidth.SetString("width");

    s.AddMember(twidth, this->width, d.GetAllocator());

    rapidjson::Value tis_bigendian;
    tis_bigendian.SetString("is_bigendian");

    s.AddMember(tis_bigendian, this->is_bigendian, d.GetAllocator());

    rapidjson::Value tpoint_step;
    tpoint_step.SetString("point_step");

    s.AddMember(tpoint_step, this->point_step, d.GetAllocator());

    rapidjson::Value trow_step;
    trow_step.SetString("row_step");

    s.AddMember(trow_step, this->row_step, d.GetAllocator());

    rapidjson::Value tis_dense;
    tis_dense.SetString("is_dense");

    s.AddMember(tis_dense, this->is_dense, d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (uint8 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_sensor_msgs_PointCloud2Advertiser*
U_sensor_msgs_PointCloud2Advertiser::Create_PointCloud2_Advertiser(
  FString TopicName) {
    U_sensor_msgs_PointCloud2Advertiser* c =
      NewObject<U_sensor_msgs_PointCloud2Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_PointCloud2Advertiser::Publish(
  F_sensor_msgs_PointCloud2 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_PointCloud2Advertiser::U_sensor_msgs_PointCloud2Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/PointCloud2");
}

U_sensor_msgs_PointCloud2Subscriber::U_sensor_msgs_PointCloud2Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/PointCloud2");
}
void U_sensor_msgs_PointCloud2Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_PointCloud2 fdata;
    fdata.Unserialization(obj);
    OnPointCloud2Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_PointCloud2Subscriber::OnRecieve(
  F_sensor_msgs_PointCloud2 Data) {}

U_sensor_msgs_PointCloud2Subscriber*
U_sensor_msgs_PointCloud2Subscriber::Create_PointCloud2_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_PointCloud2Subscriber* sub =
      NewObject<U_sensor_msgs_PointCloud2Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_MultiArrayDimension::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("label") && v["label"].IsString())
        this->label = FString(v["label"].GetString());

    if (v.HasMember("size") && v["size"].IsInt())
        this->size = v["size"].GetInt();

    if (v.HasMember("stride") && v["stride"].IsInt())
        this->stride = v["stride"].GetInt();
}

rapidjson::Value F_std_msgs_MultiArrayDimension::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlabel;
    tlabel.SetString("label");

    rapidjson::Value slabel;
    std::string fuck_label = TCHAR_TO_UTF8(*this->label);
    slabel.SetString(rapidjson::StringRef(fuck_label.c_str()));
    s.AddMember(tlabel, slabel, d.GetAllocator());

    rapidjson::Value tsize;
    tsize.SetString("size");

    s.AddMember(tsize, this->size, d.GetAllocator());

    rapidjson::Value tstride;
    tstride.SetString("stride");

    s.AddMember(tstride, this->stride, d.GetAllocator());

    return s;
}

U_std_msgs_MultiArrayDimensionAdvertiser*
U_std_msgs_MultiArrayDimensionAdvertiser::Create_MultiArrayDimension_Advertiser(
  FString TopicName) {
    U_std_msgs_MultiArrayDimensionAdvertiser* c =
      NewObject<U_std_msgs_MultiArrayDimensionAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_MultiArrayDimensionAdvertiser::Publish(
  F_std_msgs_MultiArrayDimension Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_MultiArrayDimensionAdvertiser::
  U_std_msgs_MultiArrayDimensionAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/MultiArrayDimension");
}

U_std_msgs_MultiArrayDimensionSubscriber::
  U_std_msgs_MultiArrayDimensionSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/MultiArrayDimension");
}
void U_std_msgs_MultiArrayDimensionSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_std_msgs_MultiArrayDimension fdata;
    fdata.Unserialization(obj);
    OnMultiArrayDimensionData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_MultiArrayDimensionSubscriber::OnRecieve(
  F_std_msgs_MultiArrayDimension Data) {}

U_std_msgs_MultiArrayDimensionSubscriber*
U_std_msgs_MultiArrayDimensionSubscriber::Create_MultiArrayDimension_Subscriber(
  FString _TopicName) {
    U_std_msgs_MultiArrayDimensionSubscriber* sub =
      NewObject<U_std_msgs_MultiArrayDimensionSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_QuaternionStamped::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("quaternion") && v["quaternion"].IsObject())
        this->quaternion.Unserialization(v["quaternion"]);
}

rapidjson::Value F_geometry_msgs_QuaternionStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tquaternion;
    tquaternion.SetString("quaternion");

    s.AddMember(tquaternion, this->quaternion.Serialization(d),
                d.GetAllocator());

    return s;
}

U_geometry_msgs_QuaternionStampedAdvertiser*
U_geometry_msgs_QuaternionStampedAdvertiser::
  Create_QuaternionStamped_Advertiser(FString TopicName) {
    U_geometry_msgs_QuaternionStampedAdvertiser* c =
      NewObject<U_geometry_msgs_QuaternionStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_QuaternionStampedAdvertiser::Publish(
  F_geometry_msgs_QuaternionStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_QuaternionStampedAdvertiser::
  U_geometry_msgs_QuaternionStampedAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/QuaternionStamped");
}

U_geometry_msgs_QuaternionStampedSubscriber::
  U_geometry_msgs_QuaternionStampedSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/QuaternionStamped");
}
void U_geometry_msgs_QuaternionStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_QuaternionStamped fdata;
    fdata.Unserialization(obj);
    OnQuaternionStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_QuaternionStampedSubscriber::OnRecieve(
  F_geometry_msgs_QuaternionStamped Data) {}

U_geometry_msgs_QuaternionStampedSubscriber*
U_geometry_msgs_QuaternionStampedSubscriber::
  Create_QuaternionStamped_Subscriber(FString _TopicName) {
    U_geometry_msgs_QuaternionStampedSubscriber* sub =
      NewObject<U_geometry_msgs_QuaternionStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Int32::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt())
        this->data = v["data"].GetInt();
}

rapidjson::Value F_std_msgs_Int32::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_Int32Advertiser* U_std_msgs_Int32Advertiser::Create_Int32_Advertiser(
  FString TopicName) {
    U_std_msgs_Int32Advertiser* c = NewObject<U_std_msgs_Int32Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Int32Advertiser::Publish(F_std_msgs_Int32 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Int32Advertiser::U_std_msgs_Int32Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int32");
}

U_std_msgs_Int32Subscriber::U_std_msgs_Int32Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int32");
}
void U_std_msgs_Int32Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Int32 fdata;
    fdata.Unserialization(obj);
    OnInt32Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Int32Subscriber::OnRecieve(F_std_msgs_Int32 Data) {}

U_std_msgs_Int32Subscriber* U_std_msgs_Int32Subscriber::Create_Int32_Subscriber(
  FString _TopicName) {
    U_std_msgs_Int32Subscriber* sub = NewObject<U_std_msgs_Int32Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_Image::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("height") && v["height"].IsInt())
        this->height = v["height"].GetInt();

    if (v.HasMember("width") && v["width"].IsInt())
        this->width = v["width"].GetInt();

    if (v.HasMember("encoding") && v["encoding"].IsString())
        this->encoding = FString(v["encoding"].GetString());

    if (v.HasMember("is_bigendian") && v["is_bigendian"].IsInt())
        this->is_bigendian = v["is_bigendian"].GetInt();

    if (v.HasMember("step") && v["step"].IsInt())
        this->step = v["step"].GetInt();

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_sensor_msgs_Image::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value theight;
    theight.SetString("height");

    s.AddMember(theight, this->height, d.GetAllocator());

    rapidjson::Value twidth;
    twidth.SetString("width");

    s.AddMember(twidth, this->width, d.GetAllocator());

    rapidjson::Value tencoding;
    tencoding.SetString("encoding");

    rapidjson::Value sencoding;
    std::string fuck_encoding = TCHAR_TO_UTF8(*this->encoding);
    sencoding.SetString(rapidjson::StringRef(fuck_encoding.c_str()));
    s.AddMember(tencoding, sencoding, d.GetAllocator());

    rapidjson::Value tis_bigendian;
    tis_bigendian.SetString("is_bigendian");

    s.AddMember(tis_bigendian, this->is_bigendian, d.GetAllocator());

    rapidjson::Value tstep;
    tstep.SetString("step");

    s.AddMember(tstep, this->step, d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (uint8 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_sensor_msgs_ImageAdvertiser*
U_sensor_msgs_ImageAdvertiser::Create_Image_Advertiser(FString TopicName) {
    U_sensor_msgs_ImageAdvertiser* c =
      NewObject<U_sensor_msgs_ImageAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_ImageAdvertiser::Publish(F_sensor_msgs_Image Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_ImageAdvertiser::U_sensor_msgs_ImageAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Image");
}

U_sensor_msgs_ImageSubscriber::U_sensor_msgs_ImageSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Image");
}
void U_sensor_msgs_ImageSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_Image fdata;
    fdata.Unserialization(obj);
    OnImageData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_ImageSubscriber::OnRecieve(F_sensor_msgs_Image Data) {}

U_sensor_msgs_ImageSubscriber*
U_sensor_msgs_ImageSubscriber::Create_Image_Subscriber(FString _TopicName) {
    U_sensor_msgs_ImageSubscriber* sub =
      NewObject<U_sensor_msgs_ImageSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Pose::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("position") && v["position"].IsObject())
        this->position.Unserialization(v["position"]);

    if (v.HasMember("orientation") && v["orientation"].IsObject())
        this->orientation.Unserialization(v["orientation"]);
}

rapidjson::Value F_geometry_msgs_Pose::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tposition;
    tposition.SetString("position");

    s.AddMember(tposition, this->position.Serialization(d), d.GetAllocator());

    rapidjson::Value torientation;
    torientation.SetString("orientation");

    s.AddMember(torientation, this->orientation.Serialization(d),
                d.GetAllocator());

    return s;
}

U_geometry_msgs_PoseAdvertiser*
U_geometry_msgs_PoseAdvertiser::Create_Pose_Advertiser(FString TopicName) {
    U_geometry_msgs_PoseAdvertiser* c =
      NewObject<U_geometry_msgs_PoseAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_PoseAdvertiser::Publish(F_geometry_msgs_Pose Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_PoseAdvertiser::U_geometry_msgs_PoseAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Pose");
}

U_geometry_msgs_PoseSubscriber::U_geometry_msgs_PoseSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Pose");
}
void U_geometry_msgs_PoseSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Pose fdata;
    fdata.Unserialization(obj);
    OnPoseData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_PoseSubscriber::OnRecieve(F_geometry_msgs_Pose Data) {}

U_geometry_msgs_PoseSubscriber*
U_geometry_msgs_PoseSubscriber::Create_Pose_Subscriber(FString _TopicName) {
    U_geometry_msgs_PoseSubscriber* sub =
      NewObject<U_geometry_msgs_PoseSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_nav_msgs_MapMetaData::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("map_load_time") && v["map_load_time"].IsInt64())
        this->map_load_time = v["map_load_time"].GetInt64();

    if (v.HasMember("resolution") && v["resolution"].IsDouble())
        this->resolution = v["resolution"].GetDouble();

    if (v.HasMember("width") && v["width"].IsInt())
        this->width = v["width"].GetInt();

    if (v.HasMember("height") && v["height"].IsInt())
        this->height = v["height"].GetInt();

    if (v.HasMember("origin") && v["origin"].IsObject())
        this->origin.Unserialization(v["origin"]);
}

rapidjson::Value F_nav_msgs_MapMetaData::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tmap_load_time;
    tmap_load_time.SetString("map_load_time");

    s.AddMember(tmap_load_time, this->map_load_time, d.GetAllocator());

    rapidjson::Value tresolution;
    tresolution.SetString("resolution");

    s.AddMember(tresolution, this->resolution, d.GetAllocator());

    rapidjson::Value twidth;
    twidth.SetString("width");

    s.AddMember(twidth, this->width, d.GetAllocator());

    rapidjson::Value theight;
    theight.SetString("height");

    s.AddMember(theight, this->height, d.GetAllocator());

    rapidjson::Value torigin;
    torigin.SetString("origin");

    s.AddMember(torigin, this->origin.Serialization(d), d.GetAllocator());

    return s;
}

U_nav_msgs_MapMetaDataAdvertiser*
U_nav_msgs_MapMetaDataAdvertiser::Create_MapMetaData_Advertiser(
  FString TopicName) {
    U_nav_msgs_MapMetaDataAdvertiser* c =
      NewObject<U_nav_msgs_MapMetaDataAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_nav_msgs_MapMetaDataAdvertiser::Publish(F_nav_msgs_MapMetaData Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_nav_msgs_MapMetaDataAdvertiser::U_nav_msgs_MapMetaDataAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("nav_msgs/MapMetaData");
}

U_nav_msgs_MapMetaDataSubscriber::U_nav_msgs_MapMetaDataSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("nav_msgs/MapMetaData");
}
void U_nav_msgs_MapMetaDataSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_nav_msgs_MapMetaData fdata;
    fdata.Unserialization(obj);
    OnMapMetaDataData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_nav_msgs_MapMetaDataSubscriber::OnRecieve(F_nav_msgs_MapMetaData Data) {}

U_nav_msgs_MapMetaDataSubscriber*
U_nav_msgs_MapMetaDataSubscriber::Create_MapMetaData_Subscriber(
  FString _TopicName) {
    U_nav_msgs_MapMetaDataSubscriber* sub =
      NewObject<U_nav_msgs_MapMetaDataSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_nav_msgs_OccupancyGrid::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("info") && v["info"].IsObject())
        this->info.Unserialization(v["info"]);
}

rapidjson::Value F_nav_msgs_OccupancyGrid::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tinfo;
    tinfo.SetString("info");

    s.AddMember(tinfo, this->info.Serialization(d), d.GetAllocator());

    return s;
}

U_nav_msgs_OccupancyGridAdvertiser*
U_nav_msgs_OccupancyGridAdvertiser::Create_OccupancyGrid_Advertiser(
  FString TopicName) {
    U_nav_msgs_OccupancyGridAdvertiser* c =
      NewObject<U_nav_msgs_OccupancyGridAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_nav_msgs_OccupancyGridAdvertiser::Publish(
  F_nav_msgs_OccupancyGrid Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_nav_msgs_OccupancyGridAdvertiser::U_nav_msgs_OccupancyGridAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("nav_msgs/OccupancyGrid");
}

U_nav_msgs_OccupancyGridSubscriber::U_nav_msgs_OccupancyGridSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("nav_msgs/OccupancyGrid");
}
void U_nav_msgs_OccupancyGridSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_nav_msgs_OccupancyGrid fdata;
    fdata.Unserialization(obj);
    OnOccupancyGridData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_nav_msgs_OccupancyGridSubscriber::OnRecieve(
  F_nav_msgs_OccupancyGrid Data) {}

U_nav_msgs_OccupancyGridSubscriber*
U_nav_msgs_OccupancyGridSubscriber::Create_OccupancyGrid_Subscriber(
  FString _TopicName) {
    U_nav_msgs_OccupancyGridSubscriber* sub =
      NewObject<U_nav_msgs_OccupancyGridSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_PoseStamped::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("pose") && v["pose"].IsObject())
        this->pose.Unserialization(v["pose"]);
}

rapidjson::Value F_geometry_msgs_PoseStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tpose;
    tpose.SetString("pose");

    s.AddMember(tpose, this->pose.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_PoseStampedAdvertiser*
U_geometry_msgs_PoseStampedAdvertiser::Create_PoseStamped_Advertiser(
  FString TopicName) {
    U_geometry_msgs_PoseStampedAdvertiser* c =
      NewObject<U_geometry_msgs_PoseStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_PoseStampedAdvertiser::Publish(
  F_geometry_msgs_PoseStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_PoseStampedAdvertiser::U_geometry_msgs_PoseStampedAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PoseStamped");
}

U_geometry_msgs_PoseStampedSubscriber::U_geometry_msgs_PoseStampedSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PoseStamped");
}
void U_geometry_msgs_PoseStampedSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_PoseStamped fdata;
    fdata.Unserialization(obj);
    OnPoseStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_PoseStampedSubscriber::OnRecieve(
  F_geometry_msgs_PoseStamped Data) {}

U_geometry_msgs_PoseStampedSubscriber*
U_geometry_msgs_PoseStampedSubscriber::Create_PoseStamped_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_PoseStampedSubscriber* sub =
      NewObject<U_geometry_msgs_PoseStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_JoyFeedback::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("type") && v["type"].IsInt())
        this->type = v["type"].GetInt();

    if (v.HasMember("id") && v["id"].IsInt()) this->id = v["id"].GetInt();

    if (v.HasMember("intensity") && v["intensity"].IsDouble())
        this->intensity = v["intensity"].GetDouble();
}

rapidjson::Value F_sensor_msgs_JoyFeedback::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value ttype;
    ttype.SetString("type");

    s.AddMember(ttype, this->type, d.GetAllocator());

    rapidjson::Value tid;
    tid.SetString("id");

    s.AddMember(tid, this->id, d.GetAllocator());

    rapidjson::Value tintensity;
    tintensity.SetString("intensity");

    s.AddMember(tintensity, this->intensity, d.GetAllocator());

    rapidjson::Value tCONSTANT_TYPE_LED;
    tCONSTANT_TYPE_LED.SetString("CONSTANT_TYPE_LED");

    s.AddMember(tCONSTANT_TYPE_LED, this->CONSTANT_TYPE_LED, d.GetAllocator());

    rapidjson::Value tCONSTANT_TYPE_RUMBLE;
    tCONSTANT_TYPE_RUMBLE.SetString("CONSTANT_TYPE_RUMBLE");

    s.AddMember(tCONSTANT_TYPE_RUMBLE, this->CONSTANT_TYPE_RUMBLE,
                d.GetAllocator());

    rapidjson::Value tCONSTANT_TYPE_BUZZER;
    tCONSTANT_TYPE_BUZZER.SetString("CONSTANT_TYPE_BUZZER");

    s.AddMember(tCONSTANT_TYPE_BUZZER, this->CONSTANT_TYPE_BUZZER,
                d.GetAllocator());

    return s;
}

U_sensor_msgs_JoyFeedbackAdvertiser*
U_sensor_msgs_JoyFeedbackAdvertiser::Create_JoyFeedback_Advertiser(
  FString TopicName) {
    U_sensor_msgs_JoyFeedbackAdvertiser* c =
      NewObject<U_sensor_msgs_JoyFeedbackAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_JoyFeedbackAdvertiser::Publish(
  F_sensor_msgs_JoyFeedback Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_JoyFeedbackAdvertiser::U_sensor_msgs_JoyFeedbackAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/JoyFeedback");
}

U_sensor_msgs_JoyFeedbackSubscriber::U_sensor_msgs_JoyFeedbackSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/JoyFeedback");
}
void U_sensor_msgs_JoyFeedbackSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_JoyFeedback fdata;
    fdata.Unserialization(obj);
    OnJoyFeedbackData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_JoyFeedbackSubscriber::OnRecieve(
  F_sensor_msgs_JoyFeedback Data) {}

U_sensor_msgs_JoyFeedbackSubscriber*
U_sensor_msgs_JoyFeedbackSubscriber::Create_JoyFeedback_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_JoyFeedbackSubscriber* sub =
      NewObject<U_sensor_msgs_JoyFeedbackSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_trajectory_msgs_JointTrajectory::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);
}

rapidjson::Value F_trajectory_msgs_JointTrajectory::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    return s;
}

U_trajectory_msgs_JointTrajectoryAdvertiser*
U_trajectory_msgs_JointTrajectoryAdvertiser::Create_JointTrajectory_Advertiser(
  FString TopicName) {
    U_trajectory_msgs_JointTrajectoryAdvertiser* c =
      NewObject<U_trajectory_msgs_JointTrajectoryAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_trajectory_msgs_JointTrajectoryAdvertiser::Publish(
  F_trajectory_msgs_JointTrajectory Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_trajectory_msgs_JointTrajectoryAdvertiser::
  U_trajectory_msgs_JointTrajectoryAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("trajectory_msgs/JointTrajectory");
}

U_trajectory_msgs_JointTrajectorySubscriber::
  U_trajectory_msgs_JointTrajectorySubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("trajectory_msgs/JointTrajectory");
}
void U_trajectory_msgs_JointTrajectorySubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_trajectory_msgs_JointTrajectory fdata;
    fdata.Unserialization(obj);
    OnJointTrajectoryData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_trajectory_msgs_JointTrajectorySubscriber::OnRecieve(
  F_trajectory_msgs_JointTrajectory Data) {}

U_trajectory_msgs_JointTrajectorySubscriber*
U_trajectory_msgs_JointTrajectorySubscriber::Create_JointTrajectory_Subscriber(
  FString _TopicName) {
    U_trajectory_msgs_JointTrajectorySubscriber* sub =
      NewObject<U_trajectory_msgs_JointTrajectorySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionFollowmeTarget::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("latitude") && v["latitude"].IsDouble())
        this->latitude = v["latitude"].GetDouble();

    if (v.HasMember("longitude") && v["longitude"].IsDouble())
        this->longitude = v["longitude"].GetDouble();

    if (v.HasMember("altitude") && v["altitude"].IsInt())
        this->altitude = v["altitude"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionFollowmeTarget::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlatitude;
    tlatitude.SetString("latitude");

    s.AddMember(tlatitude, this->latitude, d.GetAllocator());

    rapidjson::Value tlongitude;
    tlongitude.SetString("longitude");

    s.AddMember(tlongitude, this->longitude, d.GetAllocator());

    rapidjson::Value taltitude;
    taltitude.SetString("altitude");

    s.AddMember(taltitude, this->altitude, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionFollowmeTargetAdvertiser*
U_dji_sdk_MissionFollowmeTargetAdvertiser::
  Create_MissionFollowmeTarget_Advertiser(FString TopicName) {
    U_dji_sdk_MissionFollowmeTargetAdvertiser* c =
      NewObject<U_dji_sdk_MissionFollowmeTargetAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionFollowmeTargetAdvertiser::Publish(
  F_dji_sdk_MissionFollowmeTarget Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionFollowmeTargetAdvertiser::
  U_dji_sdk_MissionFollowmeTargetAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionFollowmeTarget");
}

U_dji_sdk_MissionFollowmeTargetSubscriber::
  U_dji_sdk_MissionFollowmeTargetSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionFollowmeTarget");
}
void U_dji_sdk_MissionFollowmeTargetSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionFollowmeTarget fdata;
    fdata.Unserialization(obj);
    OnMissionFollowmeTargetData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionFollowmeTargetSubscriber::OnRecieve(
  F_dji_sdk_MissionFollowmeTarget Data) {}

U_dji_sdk_MissionFollowmeTargetSubscriber*
U_dji_sdk_MissionFollowmeTargetSubscriber::
  Create_MissionFollowmeTarget_Subscriber(FString _TopicName) {
    U_dji_sdk_MissionFollowmeTargetSubscriber* sub =
      NewObject<U_dji_sdk_MissionFollowmeTargetSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_WaypointList::Unserialization(rapidjson::Value& v) {}

rapidjson::Value F_dji_sdk_WaypointList::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    return s;
}

U_dji_sdk_WaypointListAdvertiser*
U_dji_sdk_WaypointListAdvertiser::Create_WaypointList_Advertiser(
  FString TopicName) {
    U_dji_sdk_WaypointListAdvertiser* c =
      NewObject<U_dji_sdk_WaypointListAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_WaypointListAdvertiser::Publish(F_dji_sdk_WaypointList Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_WaypointListAdvertiser::U_dji_sdk_WaypointListAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/WaypointList");
}

U_dji_sdk_WaypointListSubscriber::U_dji_sdk_WaypointListSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/WaypointList");
}
void U_dji_sdk_WaypointListSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_WaypointList fdata;
    fdata.Unserialization(obj);
    OnWaypointListData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_WaypointListSubscriber::OnRecieve(F_dji_sdk_WaypointList Data) {}

U_dji_sdk_WaypointListSubscriber*
U_dji_sdk_WaypointListSubscriber::Create_WaypointList_Subscriber(
  FString _TopicName) {
    U_dji_sdk_WaypointListSubscriber* sub =
      NewObject<U_dji_sdk_WaypointListSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionPushInfo::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("type") && v["type"].IsInt())
        this->type = v["type"].GetInt();

    if (v.HasMember("data_1") && v["data_1"].IsInt())
        this->data_1 = v["data_1"].GetInt();

    if (v.HasMember("data_2") && v["data_2"].IsInt())
        this->data_2 = v["data_2"].GetInt();

    if (v.HasMember("data_3") && v["data_3"].IsInt())
        this->data_3 = v["data_3"].GetInt();

    if (v.HasMember("data_4") && v["data_4"].IsInt())
        this->data_4 = v["data_4"].GetInt();

    if (v.HasMember("data_5") && v["data_5"].IsInt())
        this->data_5 = v["data_5"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionPushInfo::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value ttype;
    ttype.SetString("type");

    s.AddMember(ttype, this->type, d.GetAllocator());

    rapidjson::Value tdata_1;
    tdata_1.SetString("data_1");

    s.AddMember(tdata_1, this->data_1, d.GetAllocator());

    rapidjson::Value tdata_2;
    tdata_2.SetString("data_2");

    s.AddMember(tdata_2, this->data_2, d.GetAllocator());

    rapidjson::Value tdata_3;
    tdata_3.SetString("data_3");

    s.AddMember(tdata_3, this->data_3, d.GetAllocator());

    rapidjson::Value tdata_4;
    tdata_4.SetString("data_4");

    s.AddMember(tdata_4, this->data_4, d.GetAllocator());

    rapidjson::Value tdata_5;
    tdata_5.SetString("data_5");

    s.AddMember(tdata_5, this->data_5, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionPushInfoAdvertiser*
U_dji_sdk_MissionPushInfoAdvertiser::Create_MissionPushInfo_Advertiser(
  FString TopicName) {
    U_dji_sdk_MissionPushInfoAdvertiser* c =
      NewObject<U_dji_sdk_MissionPushInfoAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionPushInfoAdvertiser::Publish(
  F_dji_sdk_MissionPushInfo Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionPushInfoAdvertiser::U_dji_sdk_MissionPushInfoAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionPushInfo");
}

U_dji_sdk_MissionPushInfoSubscriber::U_dji_sdk_MissionPushInfoSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionPushInfo");
}
void U_dji_sdk_MissionPushInfoSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_MissionPushInfo fdata;
    fdata.Unserialization(obj);
    OnMissionPushInfoData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionPushInfoSubscriber::OnRecieve(
  F_dji_sdk_MissionPushInfo Data) {}

U_dji_sdk_MissionPushInfoSubscriber*
U_dji_sdk_MissionPushInfoSubscriber::Create_MissionPushInfo_Subscriber(
  FString _TopicName) {
    U_dji_sdk_MissionPushInfoSubscriber* sub =
      NewObject<U_dji_sdk_MissionPushInfoSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_MultiArrayLayout::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data_offset") && v["data_offset"].IsInt())
        this->data_offset = v["data_offset"].GetInt();

    if (v.HasMember("dim") && v["dim"].IsArray()) {
        rapidjson::Value& Adim = v["dim"];
        for (rapidjson::SizeType i = 0; i < Adim.Size(); i++) {
            rapidjson::Value& kv = Adim[i];

            if (kv.IsObject()) {
                F_std_msgs_MultiArrayDimension e;
                e.Unserialization(kv);
                this->dim.Add(e);
            }
        }
    }
}

rapidjson::Value F_std_msgs_MultiArrayLayout::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata_offset;
    tdata_offset.SetString("data_offset");

    s.AddMember(tdata_offset, this->data_offset, d.GetAllocator());

    rapidjson::Value tdim;
    tdim.SetString("dim");

    rapidjson::Value Adim(rapidjson::kArrayType);
    for (F_std_msgs_MultiArrayDimension Element : dim) {
        Adim.PushBack(Element.Serialization(d), d.GetAllocator());
    }
    s.AddMember(tdim, Adim, d.GetAllocator());

    return s;
}

U_std_msgs_MultiArrayLayoutAdvertiser*
U_std_msgs_MultiArrayLayoutAdvertiser::Create_MultiArrayLayout_Advertiser(
  FString TopicName) {
    U_std_msgs_MultiArrayLayoutAdvertiser* c =
      NewObject<U_std_msgs_MultiArrayLayoutAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_MultiArrayLayoutAdvertiser::Publish(
  F_std_msgs_MultiArrayLayout Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_MultiArrayLayoutAdvertiser::U_std_msgs_MultiArrayLayoutAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/MultiArrayLayout");
}

U_std_msgs_MultiArrayLayoutSubscriber::U_std_msgs_MultiArrayLayoutSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/MultiArrayLayout");
}
void U_std_msgs_MultiArrayLayoutSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_MultiArrayLayout fdata;
    fdata.Unserialization(obj);
    OnMultiArrayLayoutData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_MultiArrayLayoutSubscriber::OnRecieve(
  F_std_msgs_MultiArrayLayout Data) {}

U_std_msgs_MultiArrayLayoutSubscriber*
U_std_msgs_MultiArrayLayoutSubscriber::Create_MultiArrayLayout_Subscriber(
  FString _TopicName) {
    U_std_msgs_MultiArrayLayoutSubscriber* sub =
      NewObject<U_std_msgs_MultiArrayLayoutSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Float32MultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsDouble()) this->data.Add(kv.GetDouble());
        }
    }
}

rapidjson::Value F_std_msgs_Float32MultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (float Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_Float32MultiArrayAdvertiser*
U_std_msgs_Float32MultiArrayAdvertiser::Create_Float32MultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_Float32MultiArrayAdvertiser* c =
      NewObject<U_std_msgs_Float32MultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Float32MultiArrayAdvertiser::Publish(
  F_std_msgs_Float32MultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Float32MultiArrayAdvertiser::U_std_msgs_Float32MultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Float32MultiArray");
}

U_std_msgs_Float32MultiArraySubscriber::U_std_msgs_Float32MultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Float32MultiArray");
}
void U_std_msgs_Float32MultiArraySubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_std_msgs_Float32MultiArray fdata;
    fdata.Unserialization(obj);
    OnFloat32MultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Float32MultiArraySubscriber::OnRecieve(
  F_std_msgs_Float32MultiArray Data) {}

U_std_msgs_Float32MultiArraySubscriber*
U_std_msgs_Float32MultiArraySubscriber::Create_Float32MultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_Float32MultiArraySubscriber* sub =
      NewObject<U_std_msgs_Float32MultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_ByteMultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_std_msgs_ByteMultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (uint8 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_ByteMultiArrayAdvertiser*
U_std_msgs_ByteMultiArrayAdvertiser::Create_ByteMultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_ByteMultiArrayAdvertiser* c =
      NewObject<U_std_msgs_ByteMultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_ByteMultiArrayAdvertiser::Publish(
  F_std_msgs_ByteMultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_ByteMultiArrayAdvertiser::U_std_msgs_ByteMultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/ByteMultiArray");
}

U_std_msgs_ByteMultiArraySubscriber::U_std_msgs_ByteMultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/ByteMultiArray");
}
void U_std_msgs_ByteMultiArraySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_ByteMultiArray fdata;
    fdata.Unserialization(obj);
    OnByteMultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_ByteMultiArraySubscriber::OnRecieve(
  F_std_msgs_ByteMultiArray Data) {}

U_std_msgs_ByteMultiArraySubscriber*
U_std_msgs_ByteMultiArraySubscriber::Create_ByteMultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_ByteMultiArraySubscriber* sub =
      NewObject<U_std_msgs_ByteMultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_UInt8MultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_std_msgs_UInt8MultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (uint8 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_UInt8MultiArrayAdvertiser*
U_std_msgs_UInt8MultiArrayAdvertiser::Create_UInt8MultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_UInt8MultiArrayAdvertiser* c =
      NewObject<U_std_msgs_UInt8MultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_UInt8MultiArrayAdvertiser::Publish(
  F_std_msgs_UInt8MultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_UInt8MultiArrayAdvertiser::U_std_msgs_UInt8MultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt8MultiArray");
}

U_std_msgs_UInt8MultiArraySubscriber::U_std_msgs_UInt8MultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt8MultiArray");
}
void U_std_msgs_UInt8MultiArraySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_UInt8MultiArray fdata;
    fdata.Unserialization(obj);
    OnUInt8MultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_UInt8MultiArraySubscriber::OnRecieve(
  F_std_msgs_UInt8MultiArray Data) {}

U_std_msgs_UInt8MultiArraySubscriber*
U_std_msgs_UInt8MultiArraySubscriber::Create_UInt8MultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_UInt8MultiArraySubscriber* sub =
      NewObject<U_std_msgs_UInt8MultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Int32MultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_std_msgs_Int32MultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (int32 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_Int32MultiArrayAdvertiser*
U_std_msgs_Int32MultiArrayAdvertiser::Create_Int32MultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_Int32MultiArrayAdvertiser* c =
      NewObject<U_std_msgs_Int32MultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Int32MultiArrayAdvertiser::Publish(
  F_std_msgs_Int32MultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Int32MultiArrayAdvertiser::U_std_msgs_Int32MultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int32MultiArray");
}

U_std_msgs_Int32MultiArraySubscriber::U_std_msgs_Int32MultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int32MultiArray");
}
void U_std_msgs_Int32MultiArraySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Int32MultiArray fdata;
    fdata.Unserialization(obj);
    OnInt32MultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Int32MultiArraySubscriber::OnRecieve(
  F_std_msgs_Int32MultiArray Data) {}

U_std_msgs_Int32MultiArraySubscriber*
U_std_msgs_Int32MultiArraySubscriber::Create_Int32MultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_Int32MultiArraySubscriber* sub =
      NewObject<U_std_msgs_Int32MultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_UInt32MultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_std_msgs_UInt32MultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (int32 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_UInt32MultiArrayAdvertiser*
U_std_msgs_UInt32MultiArrayAdvertiser::Create_UInt32MultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_UInt32MultiArrayAdvertiser* c =
      NewObject<U_std_msgs_UInt32MultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_UInt32MultiArrayAdvertiser::Publish(
  F_std_msgs_UInt32MultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_UInt32MultiArrayAdvertiser::U_std_msgs_UInt32MultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt32MultiArray");
}

U_std_msgs_UInt32MultiArraySubscriber::U_std_msgs_UInt32MultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt32MultiArray");
}
void U_std_msgs_UInt32MultiArraySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_UInt32MultiArray fdata;
    fdata.Unserialization(obj);
    OnUInt32MultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_UInt32MultiArraySubscriber::OnRecieve(
  F_std_msgs_UInt32MultiArray Data) {}

U_std_msgs_UInt32MultiArraySubscriber*
U_std_msgs_UInt32MultiArraySubscriber::Create_UInt32MultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_UInt32MultiArraySubscriber* sub =
      NewObject<U_std_msgs_UInt32MultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Float64MultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsDouble()) this->data.Add(kv.GetDouble());
        }
    }
}

rapidjson::Value F_std_msgs_Float64MultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (float Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_Float64MultiArrayAdvertiser*
U_std_msgs_Float64MultiArrayAdvertiser::Create_Float64MultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_Float64MultiArrayAdvertiser* c =
      NewObject<U_std_msgs_Float64MultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Float64MultiArrayAdvertiser::Publish(
  F_std_msgs_Float64MultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Float64MultiArrayAdvertiser::U_std_msgs_Float64MultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Float64MultiArray");
}

U_std_msgs_Float64MultiArraySubscriber::U_std_msgs_Float64MultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Float64MultiArray");
}
void U_std_msgs_Float64MultiArraySubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_std_msgs_Float64MultiArray fdata;
    fdata.Unserialization(obj);
    OnFloat64MultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Float64MultiArraySubscriber::OnRecieve(
  F_std_msgs_Float64MultiArray Data) {}

U_std_msgs_Float64MultiArraySubscriber*
U_std_msgs_Float64MultiArraySubscriber::Create_Float64MultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_Float64MultiArraySubscriber* sub =
      NewObject<U_std_msgs_Float64MultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_NavSatFix::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("status") && v["status"].IsObject())
        this->status.Unserialization(v["status"]);

    if (v.HasMember("latitude") && v["latitude"].IsDouble())
        this->latitude = v["latitude"].GetDouble();

    if (v.HasMember("longitude") && v["longitude"].IsDouble())
        this->longitude = v["longitude"].GetDouble();

    if (v.HasMember("altitude") && v["altitude"].IsDouble())
        this->altitude = v["altitude"].GetDouble();

    if (v.HasMember("position_covariance_type") &&
        v["position_covariance_type"].IsInt())
        this->position_covariance_type = v["position_covariance_type"].GetInt();
}

rapidjson::Value F_sensor_msgs_NavSatFix::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tstatus;
    tstatus.SetString("status");

    s.AddMember(tstatus, this->status.Serialization(d), d.GetAllocator());

    rapidjson::Value tlatitude;
    tlatitude.SetString("latitude");

    s.AddMember(tlatitude, this->latitude, d.GetAllocator());

    rapidjson::Value tlongitude;
    tlongitude.SetString("longitude");

    s.AddMember(tlongitude, this->longitude, d.GetAllocator());

    rapidjson::Value taltitude;
    taltitude.SetString("altitude");

    s.AddMember(taltitude, this->altitude, d.GetAllocator());

    rapidjson::Value tposition_covariance_type;
    tposition_covariance_type.SetString("position_covariance_type");

    s.AddMember(tposition_covariance_type, this->position_covariance_type,
                d.GetAllocator());

    rapidjson::Value tCONSTANT_COVARIANCE_TYPE_UNKNOWN;
    tCONSTANT_COVARIANCE_TYPE_UNKNOWN.SetString(
      "CONSTANT_COVARIANCE_TYPE_UNKNOWN");

    s.AddMember(tCONSTANT_COVARIANCE_TYPE_UNKNOWN,
                this->CONSTANT_COVARIANCE_TYPE_UNKNOWN, d.GetAllocator());

    rapidjson::Value tCONSTANT_COVARIANCE_TYPE_APPROXIMATED;
    tCONSTANT_COVARIANCE_TYPE_APPROXIMATED.SetString(
      "CONSTANT_COVARIANCE_TYPE_APPROXIMATED");

    s.AddMember(tCONSTANT_COVARIANCE_TYPE_APPROXIMATED,
                this->CONSTANT_COVARIANCE_TYPE_APPROXIMATED, d.GetAllocator());

    rapidjson::Value tCONSTANT_COVARIANCE_TYPE_DIAGONAL_KNOWN;
    tCONSTANT_COVARIANCE_TYPE_DIAGONAL_KNOWN.SetString(
      "CONSTANT_COVARIANCE_TYPE_DIAGONAL_KNOWN");

    s.AddMember(tCONSTANT_COVARIANCE_TYPE_DIAGONAL_KNOWN,
                this->CONSTANT_COVARIANCE_TYPE_DIAGONAL_KNOWN,
                d.GetAllocator());

    rapidjson::Value tCONSTANT_COVARIANCE_TYPE_KNOWN;
    tCONSTANT_COVARIANCE_TYPE_KNOWN.SetString("CONSTANT_COVARIANCE_TYPE_KNOWN");

    s.AddMember(tCONSTANT_COVARIANCE_TYPE_KNOWN,
                this->CONSTANT_COVARIANCE_TYPE_KNOWN, d.GetAllocator());

    return s;
}

U_sensor_msgs_NavSatFixAdvertiser*
U_sensor_msgs_NavSatFixAdvertiser::Create_NavSatFix_Advertiser(
  FString TopicName) {
    U_sensor_msgs_NavSatFixAdvertiser* c =
      NewObject<U_sensor_msgs_NavSatFixAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_NavSatFixAdvertiser::Publish(F_sensor_msgs_NavSatFix Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_NavSatFixAdvertiser::U_sensor_msgs_NavSatFixAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/NavSatFix");
}

U_sensor_msgs_NavSatFixSubscriber::U_sensor_msgs_NavSatFixSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/NavSatFix");
}
void U_sensor_msgs_NavSatFixSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_NavSatFix fdata;
    fdata.Unserialization(obj);
    OnNavSatFixData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_NavSatFixSubscriber::OnRecieve(
  F_sensor_msgs_NavSatFix Data) {}

U_sensor_msgs_NavSatFixSubscriber*
U_sensor_msgs_NavSatFixSubscriber::Create_NavSatFix_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_NavSatFixSubscriber* sub =
      NewObject<U_sensor_msgs_NavSatFixSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Float64::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsDouble())
        this->data = v["data"].GetDouble();
}

rapidjson::Value F_std_msgs_Float64::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_Float64Advertiser*
U_std_msgs_Float64Advertiser::Create_Float64_Advertiser(FString TopicName) {
    U_std_msgs_Float64Advertiser* c = NewObject<U_std_msgs_Float64Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Float64Advertiser::Publish(F_std_msgs_Float64 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Float64Advertiser::U_std_msgs_Float64Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Float64");
}

U_std_msgs_Float64Subscriber::U_std_msgs_Float64Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Float64");
}
void U_std_msgs_Float64Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Float64 fdata;
    fdata.Unserialization(obj);
    OnFloat64Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Float64Subscriber::OnRecieve(F_std_msgs_Float64 Data) {}

U_std_msgs_Float64Subscriber*
U_std_msgs_Float64Subscriber::Create_Float64_Subscriber(FString _TopicName) {
    U_std_msgs_Float64Subscriber* sub =
      NewObject<U_std_msgs_Float64Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_FluidPressure::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("fluid_pressure") && v["fluid_pressure"].IsDouble())
        this->fluid_pressure = v["fluid_pressure"].GetDouble();

    if (v.HasMember("variance") && v["variance"].IsDouble())
        this->variance = v["variance"].GetDouble();
}

rapidjson::Value F_sensor_msgs_FluidPressure::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tfluid_pressure;
    tfluid_pressure.SetString("fluid_pressure");

    s.AddMember(tfluid_pressure, this->fluid_pressure, d.GetAllocator());

    rapidjson::Value tvariance;
    tvariance.SetString("variance");

    s.AddMember(tvariance, this->variance, d.GetAllocator());

    return s;
}

U_sensor_msgs_FluidPressureAdvertiser*
U_sensor_msgs_FluidPressureAdvertiser::Create_FluidPressure_Advertiser(
  FString TopicName) {
    U_sensor_msgs_FluidPressureAdvertiser* c =
      NewObject<U_sensor_msgs_FluidPressureAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_FluidPressureAdvertiser::Publish(
  F_sensor_msgs_FluidPressure Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_FluidPressureAdvertiser::U_sensor_msgs_FluidPressureAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/FluidPressure");
}

U_sensor_msgs_FluidPressureSubscriber::U_sensor_msgs_FluidPressureSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/FluidPressure");
}
void U_sensor_msgs_FluidPressureSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_FluidPressure fdata;
    fdata.Unserialization(obj);
    OnFluidPressureData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_FluidPressureSubscriber::OnRecieve(
  F_sensor_msgs_FluidPressure Data) {}

U_sensor_msgs_FluidPressureSubscriber*
U_sensor_msgs_FluidPressureSubscriber::Create_FluidPressure_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_FluidPressureSubscriber* sub =
      NewObject<U_sensor_msgs_FluidPressureSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Int64MultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_std_msgs_Int64MultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (int32 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_Int64MultiArrayAdvertiser*
U_std_msgs_Int64MultiArrayAdvertiser::Create_Int64MultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_Int64MultiArrayAdvertiser* c =
      NewObject<U_std_msgs_Int64MultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Int64MultiArrayAdvertiser::Publish(
  F_std_msgs_Int64MultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Int64MultiArrayAdvertiser::U_std_msgs_Int64MultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int64MultiArray");
}

U_std_msgs_Int64MultiArraySubscriber::U_std_msgs_Int64MultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int64MultiArray");
}
void U_std_msgs_Int64MultiArraySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Int64MultiArray fdata;
    fdata.Unserialization(obj);
    OnInt64MultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Int64MultiArraySubscriber::OnRecieve(
  F_std_msgs_Int64MultiArray Data) {}

U_std_msgs_Int64MultiArraySubscriber*
U_std_msgs_Int64MultiArraySubscriber::Create_Int64MultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_Int64MultiArraySubscriber* sub =
      NewObject<U_std_msgs_Int64MultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_PointField::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("name") && v["name"].IsString())
        this->name = FString(v["name"].GetString());

    if (v.HasMember("offset") && v["offset"].IsInt())
        this->offset = v["offset"].GetInt();

    if (v.HasMember("datatype") && v["datatype"].IsInt())
        this->datatype = v["datatype"].GetInt();

    if (v.HasMember("count") && v["count"].IsInt())
        this->count = v["count"].GetInt();
}

rapidjson::Value F_sensor_msgs_PointField::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tname;
    tname.SetString("name");

    rapidjson::Value sname;
    std::string fuck_name = TCHAR_TO_UTF8(*this->name);
    sname.SetString(rapidjson::StringRef(fuck_name.c_str()));
    s.AddMember(tname, sname, d.GetAllocator());

    rapidjson::Value toffset;
    toffset.SetString("offset");

    s.AddMember(toffset, this->offset, d.GetAllocator());

    rapidjson::Value tdatatype;
    tdatatype.SetString("datatype");

    s.AddMember(tdatatype, this->datatype, d.GetAllocator());

    rapidjson::Value tcount;
    tcount.SetString("count");

    s.AddMember(tcount, this->count, d.GetAllocator());

    rapidjson::Value tCONSTANT_INT8;
    tCONSTANT_INT8.SetString("CONSTANT_INT8");

    s.AddMember(tCONSTANT_INT8, this->CONSTANT_INT8, d.GetAllocator());

    rapidjson::Value tCONSTANT_UINT8;
    tCONSTANT_UINT8.SetString("CONSTANT_UINT8");

    s.AddMember(tCONSTANT_UINT8, this->CONSTANT_UINT8, d.GetAllocator());

    rapidjson::Value tCONSTANT_INT16;
    tCONSTANT_INT16.SetString("CONSTANT_INT16");

    s.AddMember(tCONSTANT_INT16, this->CONSTANT_INT16, d.GetAllocator());

    rapidjson::Value tCONSTANT_UINT16;
    tCONSTANT_UINT16.SetString("CONSTANT_UINT16");

    s.AddMember(tCONSTANT_UINT16, this->CONSTANT_UINT16, d.GetAllocator());

    rapidjson::Value tCONSTANT_INT32;
    tCONSTANT_INT32.SetString("CONSTANT_INT32");

    s.AddMember(tCONSTANT_INT32, this->CONSTANT_INT32, d.GetAllocator());

    rapidjson::Value tCONSTANT_UINT32;
    tCONSTANT_UINT32.SetString("CONSTANT_UINT32");

    s.AddMember(tCONSTANT_UINT32, this->CONSTANT_UINT32, d.GetAllocator());

    rapidjson::Value tCONSTANT_FLOAT32;
    tCONSTANT_FLOAT32.SetString("CONSTANT_FLOAT32");

    s.AddMember(tCONSTANT_FLOAT32, this->CONSTANT_FLOAT32, d.GetAllocator());

    rapidjson::Value tCONSTANT_FLOAT64;
    tCONSTANT_FLOAT64.SetString("CONSTANT_FLOAT64");

    s.AddMember(tCONSTANT_FLOAT64, this->CONSTANT_FLOAT64, d.GetAllocator());

    return s;
}

U_sensor_msgs_PointFieldAdvertiser*
U_sensor_msgs_PointFieldAdvertiser::Create_PointField_Advertiser(
  FString TopicName) {
    U_sensor_msgs_PointFieldAdvertiser* c =
      NewObject<U_sensor_msgs_PointFieldAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_PointFieldAdvertiser::Publish(
  F_sensor_msgs_PointField Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_PointFieldAdvertiser::U_sensor_msgs_PointFieldAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/PointField");
}

U_sensor_msgs_PointFieldSubscriber::U_sensor_msgs_PointFieldSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/PointField");
}
void U_sensor_msgs_PointFieldSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_PointField fdata;
    fdata.Unserialization(obj);
    OnPointFieldData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_PointFieldSubscriber::OnRecieve(
  F_sensor_msgs_PointField Data) {}

U_sensor_msgs_PointFieldSubscriber*
U_sensor_msgs_PointFieldSubscriber::Create_PointField_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_PointFieldSubscriber* sub =
      NewObject<U_sensor_msgs_PointFieldSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_ChannelFloat32::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("name") && v["name"].IsString())
        this->name = FString(v["name"].GetString());
}

rapidjson::Value F_sensor_msgs_ChannelFloat32::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tname;
    tname.SetString("name");

    rapidjson::Value sname;
    std::string fuck_name = TCHAR_TO_UTF8(*this->name);
    sname.SetString(rapidjson::StringRef(fuck_name.c_str()));
    s.AddMember(tname, sname, d.GetAllocator());

    return s;
}

U_sensor_msgs_ChannelFloat32Advertiser*
U_sensor_msgs_ChannelFloat32Advertiser::Create_ChannelFloat32_Advertiser(
  FString TopicName) {
    U_sensor_msgs_ChannelFloat32Advertiser* c =
      NewObject<U_sensor_msgs_ChannelFloat32Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_ChannelFloat32Advertiser::Publish(
  F_sensor_msgs_ChannelFloat32 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_ChannelFloat32Advertiser::U_sensor_msgs_ChannelFloat32Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/ChannelFloat32");
}

U_sensor_msgs_ChannelFloat32Subscriber::U_sensor_msgs_ChannelFloat32Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/ChannelFloat32");
}
void U_sensor_msgs_ChannelFloat32Subscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_sensor_msgs_ChannelFloat32 fdata;
    fdata.Unserialization(obj);
    OnChannelFloat32Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_ChannelFloat32Subscriber::OnRecieve(
  F_sensor_msgs_ChannelFloat32 Data) {}

U_sensor_msgs_ChannelFloat32Subscriber*
U_sensor_msgs_ChannelFloat32Subscriber::Create_ChannelFloat32_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_ChannelFloat32Subscriber* sub =
      NewObject<U_sensor_msgs_ChannelFloat32Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_ColorRGBA::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("r") && v["r"].IsDouble()) this->r = v["r"].GetDouble();

    if (v.HasMember("g") && v["g"].IsDouble()) this->g = v["g"].GetDouble();

    if (v.HasMember("b") && v["b"].IsDouble()) this->b = v["b"].GetDouble();

    if (v.HasMember("a") && v["a"].IsDouble()) this->a = v["a"].GetDouble();
}

rapidjson::Value F_std_msgs_ColorRGBA::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tr;
    tr.SetString("r");

    s.AddMember(tr, this->r, d.GetAllocator());

    rapidjson::Value tg;
    tg.SetString("g");

    s.AddMember(tg, this->g, d.GetAllocator());

    rapidjson::Value tb;
    tb.SetString("b");

    s.AddMember(tb, this->b, d.GetAllocator());

    rapidjson::Value ta;
    ta.SetString("a");

    s.AddMember(ta, this->a, d.GetAllocator());

    return s;
}

U_std_msgs_ColorRGBAAdvertiser*
U_std_msgs_ColorRGBAAdvertiser::Create_ColorRGBA_Advertiser(FString TopicName) {
    U_std_msgs_ColorRGBAAdvertiser* c =
      NewObject<U_std_msgs_ColorRGBAAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_ColorRGBAAdvertiser::Publish(F_std_msgs_ColorRGBA Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_ColorRGBAAdvertiser::U_std_msgs_ColorRGBAAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/ColorRGBA");
}

U_std_msgs_ColorRGBASubscriber::U_std_msgs_ColorRGBASubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/ColorRGBA");
}
void U_std_msgs_ColorRGBASubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_ColorRGBA fdata;
    fdata.Unserialization(obj);
    OnColorRGBAData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_ColorRGBASubscriber::OnRecieve(F_std_msgs_ColorRGBA Data) {}

U_std_msgs_ColorRGBASubscriber*
U_std_msgs_ColorRGBASubscriber::Create_ColorRGBA_Subscriber(
  FString _TopicName) {
    U_std_msgs_ColorRGBASubscriber* sub =
      NewObject<U_std_msgs_ColorRGBASubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_Temperature::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("temperature") && v["temperature"].IsDouble())
        this->temperature = v["temperature"].GetDouble();

    if (v.HasMember("variance") && v["variance"].IsDouble())
        this->variance = v["variance"].GetDouble();
}

rapidjson::Value F_sensor_msgs_Temperature::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value ttemperature;
    ttemperature.SetString("temperature");

    s.AddMember(ttemperature, this->temperature, d.GetAllocator());

    rapidjson::Value tvariance;
    tvariance.SetString("variance");

    s.AddMember(tvariance, this->variance, d.GetAllocator());

    return s;
}

U_sensor_msgs_TemperatureAdvertiser*
U_sensor_msgs_TemperatureAdvertiser::Create_Temperature_Advertiser(
  FString TopicName) {
    U_sensor_msgs_TemperatureAdvertiser* c =
      NewObject<U_sensor_msgs_TemperatureAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_TemperatureAdvertiser::Publish(
  F_sensor_msgs_Temperature Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_TemperatureAdvertiser::U_sensor_msgs_TemperatureAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Temperature");
}

U_sensor_msgs_TemperatureSubscriber::U_sensor_msgs_TemperatureSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Temperature");
}
void U_sensor_msgs_TemperatureSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_Temperature fdata;
    fdata.Unserialization(obj);
    OnTemperatureData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_TemperatureSubscriber::OnRecieve(
  F_sensor_msgs_Temperature Data) {}

U_sensor_msgs_TemperatureSubscriber*
U_sensor_msgs_TemperatureSubscriber::Create_Temperature_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_TemperatureSubscriber* sub =
      NewObject<U_sensor_msgs_TemperatureSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionWaypointAction::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("action_repeat") && v["action_repeat"].IsInt())
        this->action_repeat = v["action_repeat"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionWaypointAction::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value taction_repeat;
    taction_repeat.SetString("action_repeat");

    s.AddMember(taction_repeat, this->action_repeat, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionWaypointActionAdvertiser*
U_dji_sdk_MissionWaypointActionAdvertiser::
  Create_MissionWaypointAction_Advertiser(FString TopicName) {
    U_dji_sdk_MissionWaypointActionAdvertiser* c =
      NewObject<U_dji_sdk_MissionWaypointActionAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionWaypointActionAdvertiser::Publish(
  F_dji_sdk_MissionWaypointAction Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionWaypointActionAdvertiser::
  U_dji_sdk_MissionWaypointActionAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionWaypointAction");
}

U_dji_sdk_MissionWaypointActionSubscriber::
  U_dji_sdk_MissionWaypointActionSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionWaypointAction");
}
void U_dji_sdk_MissionWaypointActionSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionWaypointAction fdata;
    fdata.Unserialization(obj);
    OnMissionWaypointActionData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionWaypointActionSubscriber::OnRecieve(
  F_dji_sdk_MissionWaypointAction Data) {}

U_dji_sdk_MissionWaypointActionSubscriber*
U_dji_sdk_MissionWaypointActionSubscriber::
  Create_MissionWaypointAction_Subscriber(FString _TopicName) {
    U_dji_sdk_MissionWaypointActionSubscriber* sub =
      NewObject<U_dji_sdk_MissionWaypointActionSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_Compass::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("ts") && v["ts"].IsInt()) this->ts = v["ts"].GetInt();

    if (v.HasMember("x") && v["x"].IsInt()) this->x = v["x"].GetInt();

    if (v.HasMember("y") && v["y"].IsInt()) this->y = v["y"].GetInt();

    if (v.HasMember("z") && v["z"].IsInt()) this->z = v["z"].GetInt();
}

rapidjson::Value F_dji_sdk_Compass::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tts;
    tts.SetString("ts");

    s.AddMember(tts, this->ts, d.GetAllocator());

    rapidjson::Value tx;
    tx.SetString("x");

    s.AddMember(tx, this->x, d.GetAllocator());

    rapidjson::Value ty;
    ty.SetString("y");

    s.AddMember(ty, this->y, d.GetAllocator());

    rapidjson::Value tz;
    tz.SetString("z");

    s.AddMember(tz, this->z, d.GetAllocator());

    return s;
}

U_dji_sdk_CompassAdvertiser*
U_dji_sdk_CompassAdvertiser::Create_Compass_Advertiser(FString TopicName) {
    U_dji_sdk_CompassAdvertiser* c = NewObject<U_dji_sdk_CompassAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_CompassAdvertiser::Publish(F_dji_sdk_Compass Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_CompassAdvertiser::U_dji_sdk_CompassAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/Compass");
}

U_dji_sdk_CompassSubscriber::U_dji_sdk_CompassSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/Compass");
}
void U_dji_sdk_CompassSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_Compass fdata;
    fdata.Unserialization(obj);
    OnCompassData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_CompassSubscriber::OnRecieve(F_dji_sdk_Compass Data) {}

U_dji_sdk_CompassSubscriber*
U_dji_sdk_CompassSubscriber::Create_Compass_Subscriber(FString _TopicName) {
    U_dji_sdk_CompassSubscriber* sub = NewObject<U_dji_sdk_CompassSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_MultiDOFJointState::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);
}

rapidjson::Value F_sensor_msgs_MultiDOFJointState::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    return s;
}

U_sensor_msgs_MultiDOFJointStateAdvertiser*
U_sensor_msgs_MultiDOFJointStateAdvertiser::
  Create_MultiDOFJointState_Advertiser(FString TopicName) {
    U_sensor_msgs_MultiDOFJointStateAdvertiser* c =
      NewObject<U_sensor_msgs_MultiDOFJointStateAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_MultiDOFJointStateAdvertiser::Publish(
  F_sensor_msgs_MultiDOFJointState Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_MultiDOFJointStateAdvertiser::
  U_sensor_msgs_MultiDOFJointStateAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/MultiDOFJointState");
}

U_sensor_msgs_MultiDOFJointStateSubscriber::
  U_sensor_msgs_MultiDOFJointStateSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/MultiDOFJointState");
}
void U_sensor_msgs_MultiDOFJointStateSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_sensor_msgs_MultiDOFJointState fdata;
    fdata.Unserialization(obj);
    OnMultiDOFJointStateData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_MultiDOFJointStateSubscriber::OnRecieve(
  F_sensor_msgs_MultiDOFJointState Data) {}

U_sensor_msgs_MultiDOFJointStateSubscriber*
U_sensor_msgs_MultiDOFJointStateSubscriber::
  Create_MultiDOFJointState_Subscriber(FString _TopicName) {
    U_sensor_msgs_MultiDOFJointStateSubscriber* sub =
      NewObject<U_sensor_msgs_MultiDOFJointStateSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Vector3::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("x") && v["x"].IsDouble()) this->x = v["x"].GetDouble();

    if (v.HasMember("y") && v["y"].IsDouble()) this->y = v["y"].GetDouble();

    if (v.HasMember("z") && v["z"].IsDouble()) this->z = v["z"].GetDouble();
}

rapidjson::Value F_geometry_msgs_Vector3::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tx;
    tx.SetString("x");

    s.AddMember(tx, this->x, d.GetAllocator());

    rapidjson::Value ty;
    ty.SetString("y");

    s.AddMember(ty, this->y, d.GetAllocator());

    rapidjson::Value tz;
    tz.SetString("z");

    s.AddMember(tz, this->z, d.GetAllocator());

    return s;
}

U_geometry_msgs_Vector3Advertiser*
U_geometry_msgs_Vector3Advertiser::Create_Vector3_Advertiser(
  FString TopicName) {
    U_geometry_msgs_Vector3Advertiser* c =
      NewObject<U_geometry_msgs_Vector3Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_Vector3Advertiser::Publish(F_geometry_msgs_Vector3 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_Vector3Advertiser::U_geometry_msgs_Vector3Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Vector3");
}

U_geometry_msgs_Vector3Subscriber::U_geometry_msgs_Vector3Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Vector3");
}
void U_geometry_msgs_Vector3Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Vector3 fdata;
    fdata.Unserialization(obj);
    OnVector3Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_Vector3Subscriber::OnRecieve(
  F_geometry_msgs_Vector3 Data) {}

U_geometry_msgs_Vector3Subscriber*
U_geometry_msgs_Vector3Subscriber::Create_Vector3_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_Vector3Subscriber* sub =
      NewObject<U_geometry_msgs_Vector3Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Inertia::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("m") && v["m"].IsDouble()) this->m = v["m"].GetDouble();

    if (v.HasMember("com") && v["com"].IsObject())
        this->com.Unserialization(v["com"]);

    if (v.HasMember("ixx") && v["ixx"].IsDouble())
        this->ixx = v["ixx"].GetDouble();

    if (v.HasMember("ixy") && v["ixy"].IsDouble())
        this->ixy = v["ixy"].GetDouble();

    if (v.HasMember("ixz") && v["ixz"].IsDouble())
        this->ixz = v["ixz"].GetDouble();

    if (v.HasMember("iyy") && v["iyy"].IsDouble())
        this->iyy = v["iyy"].GetDouble();

    if (v.HasMember("iyz") && v["iyz"].IsDouble())
        this->iyz = v["iyz"].GetDouble();

    if (v.HasMember("izz") && v["izz"].IsDouble())
        this->izz = v["izz"].GetDouble();
}

rapidjson::Value F_geometry_msgs_Inertia::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tm;
    tm.SetString("m");

    s.AddMember(tm, this->m, d.GetAllocator());

    rapidjson::Value tcom;
    tcom.SetString("com");

    s.AddMember(tcom, this->com.Serialization(d), d.GetAllocator());

    rapidjson::Value tixx;
    tixx.SetString("ixx");

    s.AddMember(tixx, this->ixx, d.GetAllocator());

    rapidjson::Value tixy;
    tixy.SetString("ixy");

    s.AddMember(tixy, this->ixy, d.GetAllocator());

    rapidjson::Value tixz;
    tixz.SetString("ixz");

    s.AddMember(tixz, this->ixz, d.GetAllocator());

    rapidjson::Value tiyy;
    tiyy.SetString("iyy");

    s.AddMember(tiyy, this->iyy, d.GetAllocator());

    rapidjson::Value tiyz;
    tiyz.SetString("iyz");

    s.AddMember(tiyz, this->iyz, d.GetAllocator());

    rapidjson::Value tizz;
    tizz.SetString("izz");

    s.AddMember(tizz, this->izz, d.GetAllocator());

    return s;
}

U_geometry_msgs_InertiaAdvertiser*
U_geometry_msgs_InertiaAdvertiser::Create_Inertia_Advertiser(
  FString TopicName) {
    U_geometry_msgs_InertiaAdvertiser* c =
      NewObject<U_geometry_msgs_InertiaAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_InertiaAdvertiser::Publish(F_geometry_msgs_Inertia Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_InertiaAdvertiser::U_geometry_msgs_InertiaAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Inertia");
}

U_geometry_msgs_InertiaSubscriber::U_geometry_msgs_InertiaSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Inertia");
}
void U_geometry_msgs_InertiaSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Inertia fdata;
    fdata.Unserialization(obj);
    OnInertiaData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_InertiaSubscriber::OnRecieve(
  F_geometry_msgs_Inertia Data) {}

U_geometry_msgs_InertiaSubscriber*
U_geometry_msgs_InertiaSubscriber::Create_Inertia_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_InertiaSubscriber* sub =
      NewObject<U_geometry_msgs_InertiaSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Vector3Stamped::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("vector") && v["vector"].IsObject())
        this->vector.Unserialization(v["vector"]);
}

rapidjson::Value F_geometry_msgs_Vector3Stamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tvector;
    tvector.SetString("vector");

    s.AddMember(tvector, this->vector.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_Vector3StampedAdvertiser*
U_geometry_msgs_Vector3StampedAdvertiser::Create_Vector3Stamped_Advertiser(
  FString TopicName) {
    U_geometry_msgs_Vector3StampedAdvertiser* c =
      NewObject<U_geometry_msgs_Vector3StampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_Vector3StampedAdvertiser::Publish(
  F_geometry_msgs_Vector3Stamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_Vector3StampedAdvertiser::
  U_geometry_msgs_Vector3StampedAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Vector3Stamped");
}

U_geometry_msgs_Vector3StampedSubscriber::
  U_geometry_msgs_Vector3StampedSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Vector3Stamped");
}
void U_geometry_msgs_Vector3StampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_Vector3Stamped fdata;
    fdata.Unserialization(obj);
    OnVector3StampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_Vector3StampedSubscriber::OnRecieve(
  F_geometry_msgs_Vector3Stamped Data) {}

U_geometry_msgs_Vector3StampedSubscriber*
U_geometry_msgs_Vector3StampedSubscriber::Create_Vector3Stamped_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_Vector3StampedSubscriber* sub =
      NewObject<U_geometry_msgs_Vector3StampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_InertiaStamped::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("inertia") && v["inertia"].IsObject())
        this->inertia.Unserialization(v["inertia"]);
}

rapidjson::Value F_geometry_msgs_InertiaStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tinertia;
    tinertia.SetString("inertia");

    s.AddMember(tinertia, this->inertia.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_InertiaStampedAdvertiser*
U_geometry_msgs_InertiaStampedAdvertiser::Create_InertiaStamped_Advertiser(
  FString TopicName) {
    U_geometry_msgs_InertiaStampedAdvertiser* c =
      NewObject<U_geometry_msgs_InertiaStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_InertiaStampedAdvertiser::Publish(
  F_geometry_msgs_InertiaStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_InertiaStampedAdvertiser::
  U_geometry_msgs_InertiaStampedAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/InertiaStamped");
}

U_geometry_msgs_InertiaStampedSubscriber::
  U_geometry_msgs_InertiaStampedSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/InertiaStamped");
}
void U_geometry_msgs_InertiaStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_InertiaStamped fdata;
    fdata.Unserialization(obj);
    OnInertiaStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_InertiaStampedSubscriber::OnRecieve(
  F_geometry_msgs_InertiaStamped Data) {}

U_geometry_msgs_InertiaStampedSubscriber*
U_geometry_msgs_InertiaStampedSubscriber::Create_InertiaStamped_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_InertiaStampedSubscriber* sub =
      NewObject<U_geometry_msgs_InertiaStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Accel::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("linear") && v["linear"].IsObject())
        this->linear.Unserialization(v["linear"]);

    if (v.HasMember("angular") && v["angular"].IsObject())
        this->angular.Unserialization(v["angular"]);
}

rapidjson::Value F_geometry_msgs_Accel::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlinear;
    tlinear.SetString("linear");

    s.AddMember(tlinear, this->linear.Serialization(d), d.GetAllocator());

    rapidjson::Value tangular;
    tangular.SetString("angular");

    s.AddMember(tangular, this->angular.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_AccelAdvertiser*
U_geometry_msgs_AccelAdvertiser::Create_Accel_Advertiser(FString TopicName) {
    U_geometry_msgs_AccelAdvertiser* c =
      NewObject<U_geometry_msgs_AccelAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_AccelAdvertiser::Publish(F_geometry_msgs_Accel Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_AccelAdvertiser::U_geometry_msgs_AccelAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Accel");
}

U_geometry_msgs_AccelSubscriber::U_geometry_msgs_AccelSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Accel");
}
void U_geometry_msgs_AccelSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Accel fdata;
    fdata.Unserialization(obj);
    OnAccelData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_AccelSubscriber::OnRecieve(F_geometry_msgs_Accel Data) {}

U_geometry_msgs_AccelSubscriber*
U_geometry_msgs_AccelSubscriber::Create_Accel_Subscriber(FString _TopicName) {
    U_geometry_msgs_AccelSubscriber* sub =
      NewObject<U_geometry_msgs_AccelSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_AccelStamped::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("accel") && v["accel"].IsObject())
        this->accel.Unserialization(v["accel"]);
}

rapidjson::Value F_geometry_msgs_AccelStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value taccel;
    taccel.SetString("accel");

    s.AddMember(taccel, this->accel.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_AccelStampedAdvertiser*
U_geometry_msgs_AccelStampedAdvertiser::Create_AccelStamped_Advertiser(
  FString TopicName) {
    U_geometry_msgs_AccelStampedAdvertiser* c =
      NewObject<U_geometry_msgs_AccelStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_AccelStampedAdvertiser::Publish(
  F_geometry_msgs_AccelStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_AccelStampedAdvertiser::U_geometry_msgs_AccelStampedAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/AccelStamped");
}

U_geometry_msgs_AccelStampedSubscriber::U_geometry_msgs_AccelStampedSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/AccelStamped");
}
void U_geometry_msgs_AccelStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_AccelStamped fdata;
    fdata.Unserialization(obj);
    OnAccelStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_AccelStampedSubscriber::OnRecieve(
  F_geometry_msgs_AccelStamped Data) {}

U_geometry_msgs_AccelStampedSubscriber*
U_geometry_msgs_AccelStampedSubscriber::Create_AccelStamped_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_AccelStampedSubscriber* sub =
      NewObject<U_geometry_msgs_AccelStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Twist::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("linear") && v["linear"].IsObject())
        this->linear.Unserialization(v["linear"]);

    if (v.HasMember("angular") && v["angular"].IsObject())
        this->angular.Unserialization(v["angular"]);
}

rapidjson::Value F_geometry_msgs_Twist::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlinear;
    tlinear.SetString("linear");

    s.AddMember(tlinear, this->linear.Serialization(d), d.GetAllocator());

    rapidjson::Value tangular;
    tangular.SetString("angular");

    s.AddMember(tangular, this->angular.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_TwistAdvertiser*
U_geometry_msgs_TwistAdvertiser::Create_Twist_Advertiser(FString TopicName) {
    U_geometry_msgs_TwistAdvertiser* c =
      NewObject<U_geometry_msgs_TwistAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_TwistAdvertiser::Publish(F_geometry_msgs_Twist Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_TwistAdvertiser::U_geometry_msgs_TwistAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Twist");
}

U_geometry_msgs_TwistSubscriber::U_geometry_msgs_TwistSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Twist");
}
void U_geometry_msgs_TwistSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Twist fdata;
    fdata.Unserialization(obj);
    OnTwistData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_TwistSubscriber::OnRecieve(F_geometry_msgs_Twist Data) {}

U_geometry_msgs_TwistSubscriber*
U_geometry_msgs_TwistSubscriber::Create_Twist_Subscriber(FString _TopicName) {
    U_geometry_msgs_TwistSubscriber* sub =
      NewObject<U_geometry_msgs_TwistSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_TwistStamped::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("twist") && v["twist"].IsObject())
        this->twist.Unserialization(v["twist"]);
}

rapidjson::Value F_geometry_msgs_TwistStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value ttwist;
    ttwist.SetString("twist");

    s.AddMember(ttwist, this->twist.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_TwistStampedAdvertiser*
U_geometry_msgs_TwistStampedAdvertiser::Create_TwistStamped_Advertiser(
  FString TopicName) {
    U_geometry_msgs_TwistStampedAdvertiser* c =
      NewObject<U_geometry_msgs_TwistStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_TwistStampedAdvertiser::Publish(
  F_geometry_msgs_TwistStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_TwistStampedAdvertiser::U_geometry_msgs_TwistStampedAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/TwistStamped");
}

U_geometry_msgs_TwistStampedSubscriber::U_geometry_msgs_TwistStampedSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/TwistStamped");
}
void U_geometry_msgs_TwistStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_TwistStamped fdata;
    fdata.Unserialization(obj);
    OnTwistStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_TwistStampedSubscriber::OnRecieve(
  F_geometry_msgs_TwistStamped Data) {}

U_geometry_msgs_TwistStampedSubscriber*
U_geometry_msgs_TwistStampedSubscriber::Create_TwistStamped_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_TwistStampedSubscriber* sub =
      NewObject<U_geometry_msgs_TwistStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_Imu::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("orientation") && v["orientation"].IsObject())
        this->orientation.Unserialization(v["orientation"]);

    if (v.HasMember("angular_velocity") && v["angular_velocity"].IsObject())
        this->angular_velocity.Unserialization(v["angular_velocity"]);

    if (v.HasMember("linear_acceleration") &&
        v["linear_acceleration"].IsObject())
        this->linear_acceleration.Unserialization(v["linear_acceleration"]);
}

rapidjson::Value F_sensor_msgs_Imu::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value torientation;
    torientation.SetString("orientation");

    s.AddMember(torientation, this->orientation.Serialization(d),
                d.GetAllocator());

    rapidjson::Value tangular_velocity;
    tangular_velocity.SetString("angular_velocity");

    s.AddMember(tangular_velocity, this->angular_velocity.Serialization(d),
                d.GetAllocator());

    rapidjson::Value tlinear_acceleration;
    tlinear_acceleration.SetString("linear_acceleration");

    s.AddMember(tlinear_acceleration,
                this->linear_acceleration.Serialization(d), d.GetAllocator());

    return s;
}

U_sensor_msgs_ImuAdvertiser* U_sensor_msgs_ImuAdvertiser::Create_Imu_Advertiser(
  FString TopicName) {
    U_sensor_msgs_ImuAdvertiser* c = NewObject<U_sensor_msgs_ImuAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_ImuAdvertiser::Publish(F_sensor_msgs_Imu Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_ImuAdvertiser::U_sensor_msgs_ImuAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Imu");
}

U_sensor_msgs_ImuSubscriber::U_sensor_msgs_ImuSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/Imu");
}
void U_sensor_msgs_ImuSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_Imu fdata;
    fdata.Unserialization(obj);
    OnImuData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_ImuSubscriber::OnRecieve(F_sensor_msgs_Imu Data) {}

U_sensor_msgs_ImuSubscriber* U_sensor_msgs_ImuSubscriber::Create_Imu_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_ImuSubscriber* sub = NewObject<U_sensor_msgs_ImuSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_TwistWithCovariance::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("twist") && v["twist"].IsObject())
        this->twist.Unserialization(v["twist"]);
}

rapidjson::Value F_geometry_msgs_TwistWithCovariance::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value ttwist;
    ttwist.SetString("twist");

    s.AddMember(ttwist, this->twist.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_TwistWithCovarianceAdvertiser*
U_geometry_msgs_TwistWithCovarianceAdvertiser::
  Create_TwistWithCovariance_Advertiser(FString TopicName) {
    U_geometry_msgs_TwistWithCovarianceAdvertiser* c =
      NewObject<U_geometry_msgs_TwistWithCovarianceAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_TwistWithCovarianceAdvertiser::Publish(
  F_geometry_msgs_TwistWithCovariance Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_TwistWithCovarianceAdvertiser::
  U_geometry_msgs_TwistWithCovarianceAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/TwistWithCovariance");
}

U_geometry_msgs_TwistWithCovarianceSubscriber::
  U_geometry_msgs_TwistWithCovarianceSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/TwistWithCovariance");
}
void U_geometry_msgs_TwistWithCovarianceSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_TwistWithCovariance fdata;
    fdata.Unserialization(obj);
    OnTwistWithCovarianceData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_TwistWithCovarianceSubscriber::OnRecieve(
  F_geometry_msgs_TwistWithCovariance Data) {}

U_geometry_msgs_TwistWithCovarianceSubscriber*
U_geometry_msgs_TwistWithCovarianceSubscriber::
  Create_TwistWithCovariance_Subscriber(FString _TopicName) {
    U_geometry_msgs_TwistWithCovarianceSubscriber* sub =
      NewObject<U_geometry_msgs_TwistWithCovarianceSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Transform::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("translation") && v["translation"].IsObject())
        this->translation.Unserialization(v["translation"]);

    if (v.HasMember("rotation") && v["rotation"].IsObject())
        this->rotation.Unserialization(v["rotation"]);
}

rapidjson::Value F_geometry_msgs_Transform::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value ttranslation;
    ttranslation.SetString("translation");

    s.AddMember(ttranslation, this->translation.Serialization(d),
                d.GetAllocator());

    rapidjson::Value trotation;
    trotation.SetString("rotation");

    s.AddMember(trotation, this->rotation.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_TransformAdvertiser*
U_geometry_msgs_TransformAdvertiser::Create_Transform_Advertiser(
  FString TopicName) {
    U_geometry_msgs_TransformAdvertiser* c =
      NewObject<U_geometry_msgs_TransformAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_TransformAdvertiser::Publish(
  F_geometry_msgs_Transform Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_TransformAdvertiser::U_geometry_msgs_TransformAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Transform");
}

U_geometry_msgs_TransformSubscriber::U_geometry_msgs_TransformSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Transform");
}
void U_geometry_msgs_TransformSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Transform fdata;
    fdata.Unserialization(obj);
    OnTransformData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_TransformSubscriber::OnRecieve(
  F_geometry_msgs_Transform Data) {}

U_geometry_msgs_TransformSubscriber*
U_geometry_msgs_TransformSubscriber::Create_Transform_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_TransformSubscriber* sub =
      NewObject<U_geometry_msgs_TransformSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_trajectory_msgs_MultiDOFJointTrajectoryPoint::Unserialization(
  rapidjson::Value& v) {
    if (v.HasMember("time_from_start") && v["time_from_start"].IsInt64())
        this->time_from_start = v["time_from_start"].GetInt64();

    if (v.HasMember("transforms") && v["transforms"].IsArray()) {
        rapidjson::Value& Atransforms = v["transforms"];
        for (rapidjson::SizeType i = 0; i < Atransforms.Size(); i++) {
            rapidjson::Value& kv = Atransforms[i];

            if (kv.IsObject()) {
                F_geometry_msgs_Transform e;
                e.Unserialization(kv);
                this->transforms.Add(e);
            }
        }
    }

    if (v.HasMember("velocities") && v["velocities"].IsArray()) {
        rapidjson::Value& Avelocities = v["velocities"];
        for (rapidjson::SizeType i = 0; i < Avelocities.Size(); i++) {
            rapidjson::Value& kv = Avelocities[i];

            if (kv.IsObject()) {
                F_geometry_msgs_Twist e;
                e.Unserialization(kv);
                this->velocities.Add(e);
            }
        }
    }
}

rapidjson::Value F_trajectory_msgs_MultiDOFJointTrajectoryPoint::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value ttime_from_start;
    ttime_from_start.SetString("time_from_start");

    s.AddMember(ttime_from_start, this->time_from_start, d.GetAllocator());

    rapidjson::Value ttransforms;
    ttransforms.SetString("transforms");

    rapidjson::Value Atransforms(rapidjson::kArrayType);
    for (F_geometry_msgs_Transform Element : transforms) {
        Atransforms.PushBack(Element.Serialization(d), d.GetAllocator());
    }
    s.AddMember(ttransforms, Atransforms, d.GetAllocator());

    rapidjson::Value tvelocities;
    tvelocities.SetString("velocities");

    rapidjson::Value Avelocities(rapidjson::kArrayType);
    for (F_geometry_msgs_Twist Element : velocities) {
        Avelocities.PushBack(Element.Serialization(d), d.GetAllocator());
    }
    s.AddMember(tvelocities, Avelocities, d.GetAllocator());

    return s;
}

U_trajectory_msgs_MultiDOFJointTrajectoryPointAdvertiser*
U_trajectory_msgs_MultiDOFJointTrajectoryPointAdvertiser::
  Create_MultiDOFJointTrajectoryPoint_Advertiser(FString TopicName) {
    U_trajectory_msgs_MultiDOFJointTrajectoryPointAdvertiser* c =
      NewObject<U_trajectory_msgs_MultiDOFJointTrajectoryPointAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_trajectory_msgs_MultiDOFJointTrajectoryPointAdvertiser::Publish(
  F_trajectory_msgs_MultiDOFJointTrajectoryPoint Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_trajectory_msgs_MultiDOFJointTrajectoryPointAdvertiser::
  U_trajectory_msgs_MultiDOFJointTrajectoryPointAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("trajectory_msgs/MultiDOFJointTrajectoryPoint");
}

U_trajectory_msgs_MultiDOFJointTrajectoryPointSubscriber::
  U_trajectory_msgs_MultiDOFJointTrajectoryPointSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("trajectory_msgs/MultiDOFJointTrajectoryPoint");
}
void U_trajectory_msgs_MultiDOFJointTrajectoryPointSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_trajectory_msgs_MultiDOFJointTrajectoryPoint fdata;
    fdata.Unserialization(obj);
    OnMultiDOFJointTrajectoryPointData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_trajectory_msgs_MultiDOFJointTrajectoryPointSubscriber::OnRecieve(
  F_trajectory_msgs_MultiDOFJointTrajectoryPoint Data) {}

U_trajectory_msgs_MultiDOFJointTrajectoryPointSubscriber*
U_trajectory_msgs_MultiDOFJointTrajectoryPointSubscriber::
  Create_MultiDOFJointTrajectoryPoint_Subscriber(FString _TopicName) {
    U_trajectory_msgs_MultiDOFJointTrajectoryPointSubscriber* sub =
      NewObject<U_trajectory_msgs_MultiDOFJointTrajectoryPointSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_TransformStamped::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("child_frame_id") && v["child_frame_id"].IsString())
        this->child_frame_id = FString(v["child_frame_id"].GetString());

    if (v.HasMember("transform") && v["transform"].IsObject())
        this->transform.Unserialization(v["transform"]);
}

rapidjson::Value F_geometry_msgs_TransformStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tchild_frame_id;
    tchild_frame_id.SetString("child_frame_id");

    rapidjson::Value schild_frame_id;
    std::string fuck_child_frame_id = TCHAR_TO_UTF8(*this->child_frame_id);
    schild_frame_id.SetString(
      rapidjson::StringRef(fuck_child_frame_id.c_str()));
    s.AddMember(tchild_frame_id, schild_frame_id, d.GetAllocator());

    rapidjson::Value ttransform;
    ttransform.SetString("transform");

    s.AddMember(ttransform, this->transform.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_TransformStampedAdvertiser*
U_geometry_msgs_TransformStampedAdvertiser::Create_TransformStamped_Advertiser(
  FString TopicName) {
    U_geometry_msgs_TransformStampedAdvertiser* c =
      NewObject<U_geometry_msgs_TransformStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_TransformStampedAdvertiser::Publish(
  F_geometry_msgs_TransformStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_TransformStampedAdvertiser::
  U_geometry_msgs_TransformStampedAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/TransformStamped");
}

U_geometry_msgs_TransformStampedSubscriber::
  U_geometry_msgs_TransformStampedSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/TransformStamped");
}
void U_geometry_msgs_TransformStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_TransformStamped fdata;
    fdata.Unserialization(obj);
    OnTransformStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_TransformStampedSubscriber::OnRecieve(
  F_geometry_msgs_TransformStamped Data) {}

U_geometry_msgs_TransformStampedSubscriber*
U_geometry_msgs_TransformStampedSubscriber::Create_TransformStamped_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_TransformStampedSubscriber* sub =
      NewObject<U_geometry_msgs_TransformStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_TwistWithCovarianceStamped::Unserialization(
  rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("twist") && v["twist"].IsObject())
        this->twist.Unserialization(v["twist"]);
}

rapidjson::Value F_geometry_msgs_TwistWithCovarianceStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value ttwist;
    ttwist.SetString("twist");

    s.AddMember(ttwist, this->twist.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_TwistWithCovarianceStampedAdvertiser*
U_geometry_msgs_TwistWithCovarianceStampedAdvertiser::
  Create_TwistWithCovarianceStamped_Advertiser(FString TopicName) {
    U_geometry_msgs_TwistWithCovarianceStampedAdvertiser* c =
      NewObject<U_geometry_msgs_TwistWithCovarianceStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_TwistWithCovarianceStampedAdvertiser::Publish(
  F_geometry_msgs_TwistWithCovarianceStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_TwistWithCovarianceStampedAdvertiser::
  U_geometry_msgs_TwistWithCovarianceStampedAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/TwistWithCovarianceStamped");
}

U_geometry_msgs_TwistWithCovarianceStampedSubscriber::
  U_geometry_msgs_TwistWithCovarianceStampedSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/TwistWithCovarianceStamped");
}
void U_geometry_msgs_TwistWithCovarianceStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_TwistWithCovarianceStamped fdata;
    fdata.Unserialization(obj);
    OnTwistWithCovarianceStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_TwistWithCovarianceStampedSubscriber::OnRecieve(
  F_geometry_msgs_TwistWithCovarianceStamped Data) {}

U_geometry_msgs_TwistWithCovarianceStampedSubscriber*
U_geometry_msgs_TwistWithCovarianceStampedSubscriber::
  Create_TwistWithCovarianceStamped_Subscriber(FString _TopicName) {
    U_geometry_msgs_TwistWithCovarianceStampedSubscriber* sub =
      NewObject<U_geometry_msgs_TwistWithCovarianceStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_AccelWithCovariance::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("accel") && v["accel"].IsObject())
        this->accel.Unserialization(v["accel"]);
}

rapidjson::Value F_geometry_msgs_AccelWithCovariance::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value taccel;
    taccel.SetString("accel");

    s.AddMember(taccel, this->accel.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_AccelWithCovarianceAdvertiser*
U_geometry_msgs_AccelWithCovarianceAdvertiser::
  Create_AccelWithCovariance_Advertiser(FString TopicName) {
    U_geometry_msgs_AccelWithCovarianceAdvertiser* c =
      NewObject<U_geometry_msgs_AccelWithCovarianceAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_AccelWithCovarianceAdvertiser::Publish(
  F_geometry_msgs_AccelWithCovariance Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_AccelWithCovarianceAdvertiser::
  U_geometry_msgs_AccelWithCovarianceAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/AccelWithCovariance");
}

U_geometry_msgs_AccelWithCovarianceSubscriber::
  U_geometry_msgs_AccelWithCovarianceSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/AccelWithCovariance");
}
void U_geometry_msgs_AccelWithCovarianceSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_AccelWithCovariance fdata;
    fdata.Unserialization(obj);
    OnAccelWithCovarianceData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_AccelWithCovarianceSubscriber::OnRecieve(
  F_geometry_msgs_AccelWithCovariance Data) {}

U_geometry_msgs_AccelWithCovarianceSubscriber*
U_geometry_msgs_AccelWithCovarianceSubscriber::
  Create_AccelWithCovariance_Subscriber(FString _TopicName) {
    U_geometry_msgs_AccelWithCovarianceSubscriber* sub =
      NewObject<U_geometry_msgs_AccelWithCovarianceSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Int8MultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_std_msgs_Int8MultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (int32 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_Int8MultiArrayAdvertiser*
U_std_msgs_Int8MultiArrayAdvertiser::Create_Int8MultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_Int8MultiArrayAdvertiser* c =
      NewObject<U_std_msgs_Int8MultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Int8MultiArrayAdvertiser::Publish(
  F_std_msgs_Int8MultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Int8MultiArrayAdvertiser::U_std_msgs_Int8MultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int8MultiArray");
}

U_std_msgs_Int8MultiArraySubscriber::U_std_msgs_Int8MultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int8MultiArray");
}
void U_std_msgs_Int8MultiArraySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Int8MultiArray fdata;
    fdata.Unserialization(obj);
    OnInt8MultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Int8MultiArraySubscriber::OnRecieve(
  F_std_msgs_Int8MultiArray Data) {}

U_std_msgs_Int8MultiArraySubscriber*
U_std_msgs_Int8MultiArraySubscriber::Create_Int8MultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_Int8MultiArraySubscriber* sub =
      NewObject<U_std_msgs_Int8MultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_PoseArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);
}

rapidjson::Value F_geometry_msgs_PoseArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_PoseArrayAdvertiser*
U_geometry_msgs_PoseArrayAdvertiser::Create_PoseArray_Advertiser(
  FString TopicName) {
    U_geometry_msgs_PoseArrayAdvertiser* c =
      NewObject<U_geometry_msgs_PoseArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_PoseArrayAdvertiser::Publish(
  F_geometry_msgs_PoseArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_PoseArrayAdvertiser::U_geometry_msgs_PoseArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PoseArray");
}

U_geometry_msgs_PoseArraySubscriber::U_geometry_msgs_PoseArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PoseArray");
}
void U_geometry_msgs_PoseArraySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_PoseArray fdata;
    fdata.Unserialization(obj);
    OnPoseArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_PoseArraySubscriber::OnRecieve(
  F_geometry_msgs_PoseArray Data) {}

U_geometry_msgs_PoseArraySubscriber*
U_geometry_msgs_PoseArraySubscriber::Create_PoseArray_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_PoseArraySubscriber* sub =
      NewObject<U_geometry_msgs_PoseArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Time::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt64())
        this->data = v["data"].GetInt64();
}

rapidjson::Value F_std_msgs_Time::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_TimeAdvertiser* U_std_msgs_TimeAdvertiser::Create_Time_Advertiser(
  FString TopicName) {
    U_std_msgs_TimeAdvertiser* c = NewObject<U_std_msgs_TimeAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_TimeAdvertiser::Publish(F_std_msgs_Time Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_TimeAdvertiser::U_std_msgs_TimeAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Time");
}

U_std_msgs_TimeSubscriber::U_std_msgs_TimeSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Time");
}
void U_std_msgs_TimeSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Time fdata;
    fdata.Unserialization(obj);
    OnTimeData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_TimeSubscriber::OnRecieve(F_std_msgs_Time Data) {}

U_std_msgs_TimeSubscriber* U_std_msgs_TimeSubscriber::Create_Time_Subscriber(
  FString _TopicName) {
    U_std_msgs_TimeSubscriber* sub = NewObject<U_std_msgs_TimeSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_TransparentTransmissionData::Unserialization(
  rapidjson::Value& v) {}

rapidjson::Value F_dji_sdk_TransparentTransmissionData::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    return s;
}

U_dji_sdk_TransparentTransmissionDataAdvertiser*
U_dji_sdk_TransparentTransmissionDataAdvertiser::
  Create_TransparentTransmissionData_Advertiser(FString TopicName) {
    U_dji_sdk_TransparentTransmissionDataAdvertiser* c =
      NewObject<U_dji_sdk_TransparentTransmissionDataAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_TransparentTransmissionDataAdvertiser::Publish(
  F_dji_sdk_TransparentTransmissionData Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_TransparentTransmissionDataAdvertiser::
  U_dji_sdk_TransparentTransmissionDataAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/TransparentTransmissionData");
}

U_dji_sdk_TransparentTransmissionDataSubscriber::
  U_dji_sdk_TransparentTransmissionDataSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/TransparentTransmissionData");
}
void U_dji_sdk_TransparentTransmissionDataSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_TransparentTransmissionData fdata;
    fdata.Unserialization(obj);
    OnTransparentTransmissionDataData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_TransparentTransmissionDataSubscriber::OnRecieve(
  F_dji_sdk_TransparentTransmissionData Data) {}

U_dji_sdk_TransparentTransmissionDataSubscriber*
U_dji_sdk_TransparentTransmissionDataSubscriber::
  Create_TransparentTransmissionData_Subscriber(FString _TopicName) {
    U_dji_sdk_TransparentTransmissionDataSubscriber* sub =
      NewObject<U_dji_sdk_TransparentTransmissionDataSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionStatusWaypoint::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("mission_type") && v["mission_type"].IsInt())
        this->mission_type = v["mission_type"].GetInt();

    if (v.HasMember("target_waypoint") && v["target_waypoint"].IsInt())
        this->target_waypoint = v["target_waypoint"].GetInt();

    if (v.HasMember("current_status") && v["current_status"].IsInt())
        this->current_status = v["current_status"].GetInt();

    if (v.HasMember("error_code") && v["error_code"].IsInt())
        this->error_code = v["error_code"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionStatusWaypoint::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tmission_type;
    tmission_type.SetString("mission_type");

    s.AddMember(tmission_type, this->mission_type, d.GetAllocator());

    rapidjson::Value ttarget_waypoint;
    ttarget_waypoint.SetString("target_waypoint");

    s.AddMember(ttarget_waypoint, this->target_waypoint, d.GetAllocator());

    rapidjson::Value tcurrent_status;
    tcurrent_status.SetString("current_status");

    s.AddMember(tcurrent_status, this->current_status, d.GetAllocator());

    rapidjson::Value terror_code;
    terror_code.SetString("error_code");

    s.AddMember(terror_code, this->error_code, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionStatusWaypointAdvertiser*
U_dji_sdk_MissionStatusWaypointAdvertiser::
  Create_MissionStatusWaypoint_Advertiser(FString TopicName) {
    U_dji_sdk_MissionStatusWaypointAdvertiser* c =
      NewObject<U_dji_sdk_MissionStatusWaypointAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionStatusWaypointAdvertiser::Publish(
  F_dji_sdk_MissionStatusWaypoint Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionStatusWaypointAdvertiser::
  U_dji_sdk_MissionStatusWaypointAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionStatusWaypoint");
}

U_dji_sdk_MissionStatusWaypointSubscriber::
  U_dji_sdk_MissionStatusWaypointSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionStatusWaypoint");
}
void U_dji_sdk_MissionStatusWaypointSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionStatusWaypoint fdata;
    fdata.Unserialization(obj);
    OnMissionStatusWaypointData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionStatusWaypointSubscriber::OnRecieve(
  F_dji_sdk_MissionStatusWaypoint Data) {}

U_dji_sdk_MissionStatusWaypointSubscriber*
U_dji_sdk_MissionStatusWaypointSubscriber::
  Create_MissionStatusWaypoint_Subscriber(FString _TopicName) {
    U_dji_sdk_MissionStatusWaypointSubscriber* sub =
      NewObject<U_dji_sdk_MissionStatusWaypointSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_PointCloud::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("points") && v["points"].IsArray()) {
        rapidjson::Value& Apoints = v["points"];
        for (rapidjson::SizeType i = 0; i < Apoints.Size(); i++) {
            rapidjson::Value& kv = Apoints[i];

            if (kv.IsObject()) {
                F_geometry_msgs_Point32 e;
                e.Unserialization(kv);
                this->points.Add(e);
            }
        }
    }
}

rapidjson::Value F_sensor_msgs_PointCloud::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tpoints;
    tpoints.SetString("points");

    rapidjson::Value Apoints(rapidjson::kArrayType);
    for (F_geometry_msgs_Point32 Element : points) {
        Apoints.PushBack(Element.Serialization(d), d.GetAllocator());
    }
    s.AddMember(tpoints, Apoints, d.GetAllocator());

    return s;
}

U_sensor_msgs_PointCloudAdvertiser*
U_sensor_msgs_PointCloudAdvertiser::Create_PointCloud_Advertiser(
  FString TopicName) {
    U_sensor_msgs_PointCloudAdvertiser* c =
      NewObject<U_sensor_msgs_PointCloudAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_PointCloudAdvertiser::Publish(
  F_sensor_msgs_PointCloud Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_PointCloudAdvertiser::U_sensor_msgs_PointCloudAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/PointCloud");
}

U_sensor_msgs_PointCloudSubscriber::U_sensor_msgs_PointCloudSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/PointCloud");
}
void U_sensor_msgs_PointCloudSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_PointCloud fdata;
    fdata.Unserialization(obj);
    OnPointCloudData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_PointCloudSubscriber::OnRecieve(
  F_sensor_msgs_PointCloud Data) {}

U_sensor_msgs_PointCloudSubscriber*
U_sensor_msgs_PointCloudSubscriber::Create_PointCloud_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_PointCloudSubscriber* sub =
      NewObject<U_sensor_msgs_PointCloudSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_UInt8::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt())
        this->data = v["data"].GetInt();
}

rapidjson::Value F_std_msgs_UInt8::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_UInt8Advertiser* U_std_msgs_UInt8Advertiser::Create_UInt8_Advertiser(
  FString TopicName) {
    U_std_msgs_UInt8Advertiser* c = NewObject<U_std_msgs_UInt8Advertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_UInt8Advertiser::Publish(F_std_msgs_UInt8 Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_UInt8Advertiser::U_std_msgs_UInt8Advertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt8");
}

U_std_msgs_UInt8Subscriber::U_std_msgs_UInt8Subscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt8");
}
void U_std_msgs_UInt8Subscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_UInt8 fdata;
    fdata.Unserialization(obj);
    OnUInt8Data.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_UInt8Subscriber::OnRecieve(F_std_msgs_UInt8 Data) {}

U_std_msgs_UInt8Subscriber* U_std_msgs_UInt8Subscriber::Create_UInt8_Subscriber(
  FString _TopicName) {
    U_std_msgs_UInt8Subscriber* sub = NewObject<U_std_msgs_UInt8Subscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_CompressedImage::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("format") && v["format"].IsString())
        this->format = FString(v["format"].GetString());

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_sensor_msgs_CompressedImage::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tformat;
    tformat.SetString("format");

    rapidjson::Value sformat;
    std::string fuck_format = TCHAR_TO_UTF8(*this->format);
    sformat.SetString(rapidjson::StringRef(fuck_format.c_str()));
    s.AddMember(tformat, sformat, d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (uint8 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_sensor_msgs_CompressedImageAdvertiser*
U_sensor_msgs_CompressedImageAdvertiser::Create_CompressedImage_Advertiser(
  FString TopicName) {
    U_sensor_msgs_CompressedImageAdvertiser* c =
      NewObject<U_sensor_msgs_CompressedImageAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_CompressedImageAdvertiser::Publish(
  F_sensor_msgs_CompressedImage Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_CompressedImageAdvertiser::
  U_sensor_msgs_CompressedImageAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/CompressedImage");
}

U_sensor_msgs_CompressedImageSubscriber::
  U_sensor_msgs_CompressedImageSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/CompressedImage");
}
void U_sensor_msgs_CompressedImageSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_sensor_msgs_CompressedImage fdata;
    fdata.Unserialization(obj);
    OnCompressedImageData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_CompressedImageSubscriber::OnRecieve(
  F_sensor_msgs_CompressedImage Data) {}

U_sensor_msgs_CompressedImageSubscriber*
U_sensor_msgs_CompressedImageSubscriber::Create_CompressedImage_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_CompressedImageSubscriber* sub =
      NewObject<U_sensor_msgs_CompressedImageSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_JoyFeedbackArray::Unserialization(rapidjson::Value& v) {}

rapidjson::Value F_sensor_msgs_JoyFeedbackArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    return s;
}

U_sensor_msgs_JoyFeedbackArrayAdvertiser*
U_sensor_msgs_JoyFeedbackArrayAdvertiser::Create_JoyFeedbackArray_Advertiser(
  FString TopicName) {
    U_sensor_msgs_JoyFeedbackArrayAdvertiser* c =
      NewObject<U_sensor_msgs_JoyFeedbackArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_JoyFeedbackArrayAdvertiser::Publish(
  F_sensor_msgs_JoyFeedbackArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_JoyFeedbackArrayAdvertiser::
  U_sensor_msgs_JoyFeedbackArrayAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/JoyFeedbackArray");
}

U_sensor_msgs_JoyFeedbackArraySubscriber::
  U_sensor_msgs_JoyFeedbackArraySubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/JoyFeedbackArray");
}
void U_sensor_msgs_JoyFeedbackArraySubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_sensor_msgs_JoyFeedbackArray fdata;
    fdata.Unserialization(obj);
    OnJoyFeedbackArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_JoyFeedbackArraySubscriber::OnRecieve(
  F_sensor_msgs_JoyFeedbackArray Data) {}

U_sensor_msgs_JoyFeedbackArraySubscriber*
U_sensor_msgs_JoyFeedbackArraySubscriber::Create_JoyFeedbackArray_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_JoyFeedbackArraySubscriber* sub =
      NewObject<U_sensor_msgs_JoyFeedbackArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_Waypoint::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("latitude") && v["latitude"].IsDouble())
        this->latitude = v["latitude"].GetDouble();

    if (v.HasMember("longitude") && v["longitude"].IsDouble())
        this->longitude = v["longitude"].GetDouble();

    if (v.HasMember("altitude") && v["altitude"].IsDouble())
        this->altitude = v["altitude"].GetDouble();

    if (v.HasMember("heading") && v["heading"].IsInt())
        this->heading = v["heading"].GetInt();

    if (v.HasMember("staytime") && v["staytime"].IsInt())
        this->staytime = v["staytime"].GetInt();
}

rapidjson::Value F_dji_sdk_Waypoint::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlatitude;
    tlatitude.SetString("latitude");

    s.AddMember(tlatitude, this->latitude, d.GetAllocator());

    rapidjson::Value tlongitude;
    tlongitude.SetString("longitude");

    s.AddMember(tlongitude, this->longitude, d.GetAllocator());

    rapidjson::Value taltitude;
    taltitude.SetString("altitude");

    s.AddMember(taltitude, this->altitude, d.GetAllocator());

    rapidjson::Value theading;
    theading.SetString("heading");

    s.AddMember(theading, this->heading, d.GetAllocator());

    rapidjson::Value tstaytime;
    tstaytime.SetString("staytime");

    s.AddMember(tstaytime, this->staytime, d.GetAllocator());

    return s;
}

U_dji_sdk_WaypointAdvertiser*
U_dji_sdk_WaypointAdvertiser::Create_Waypoint_Advertiser(FString TopicName) {
    U_dji_sdk_WaypointAdvertiser* c = NewObject<U_dji_sdk_WaypointAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_WaypointAdvertiser::Publish(F_dji_sdk_Waypoint Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_WaypointAdvertiser::U_dji_sdk_WaypointAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/Waypoint");
}

U_dji_sdk_WaypointSubscriber::U_dji_sdk_WaypointSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/Waypoint");
}
void U_dji_sdk_WaypointSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_Waypoint fdata;
    fdata.Unserialization(obj);
    OnWaypointData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_WaypointSubscriber::OnRecieve(F_dji_sdk_Waypoint Data) {}

U_dji_sdk_WaypointSubscriber*
U_dji_sdk_WaypointSubscriber::Create_Waypoint_Subscriber(FString _TopicName) {
    U_dji_sdk_WaypointSubscriber* sub =
      NewObject<U_dji_sdk_WaypointSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_Gimbal::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("ts") && v["ts"].IsInt()) this->ts = v["ts"].GetInt();

    if (v.HasMember("pitch") && v["pitch"].IsDouble())
        this->pitch = v["pitch"].GetDouble();

    if (v.HasMember("yaw") && v["yaw"].IsDouble())
        this->yaw = v["yaw"].GetDouble();

    if (v.HasMember("roll") && v["roll"].IsDouble())
        this->roll = v["roll"].GetDouble();
}

rapidjson::Value F_dji_sdk_Gimbal::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tts;
    tts.SetString("ts");

    s.AddMember(tts, this->ts, d.GetAllocator());

    rapidjson::Value tpitch;
    tpitch.SetString("pitch");

    s.AddMember(tpitch, this->pitch, d.GetAllocator());

    rapidjson::Value tyaw;
    tyaw.SetString("yaw");

    s.AddMember(tyaw, this->yaw, d.GetAllocator());

    rapidjson::Value troll;
    troll.SetString("roll");

    s.AddMember(troll, this->roll, d.GetAllocator());

    return s;
}

U_dji_sdk_GimbalAdvertiser*
U_dji_sdk_GimbalAdvertiser::Create_Gimbal_Advertiser(FString TopicName) {
    U_dji_sdk_GimbalAdvertiser* c = NewObject<U_dji_sdk_GimbalAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_GimbalAdvertiser::Publish(F_dji_sdk_Gimbal Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_GimbalAdvertiser::U_dji_sdk_GimbalAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/Gimbal");
}

U_dji_sdk_GimbalSubscriber::U_dji_sdk_GimbalSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/Gimbal");
}
void U_dji_sdk_GimbalSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_Gimbal fdata;
    fdata.Unserialization(obj);
    OnGimbalData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_GimbalSubscriber::OnRecieve(F_dji_sdk_Gimbal Data) {}

U_dji_sdk_GimbalSubscriber*
U_dji_sdk_GimbalSubscriber::Create_Gimbal_Subscriber(FString _TopicName) {
    U_dji_sdk_GimbalSubscriber* sub = NewObject<U_dji_sdk_GimbalSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionEventWpUpload::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("incident_type") && v["incident_type"].IsInt())
        this->incident_type = v["incident_type"].GetInt();

    if (v.HasMember("mission_valid") && v["mission_valid"].IsInt())
        this->mission_valid = v["mission_valid"].GetInt();

    if (v.HasMember("estimated_runtime") && v["estimated_runtime"].IsInt())
        this->estimated_runtime = v["estimated_runtime"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionEventWpUpload::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tincident_type;
    tincident_type.SetString("incident_type");

    s.AddMember(tincident_type, this->incident_type, d.GetAllocator());

    rapidjson::Value tmission_valid;
    tmission_valid.SetString("mission_valid");

    s.AddMember(tmission_valid, this->mission_valid, d.GetAllocator());

    rapidjson::Value testimated_runtime;
    testimated_runtime.SetString("estimated_runtime");

    s.AddMember(testimated_runtime, this->estimated_runtime, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionEventWpUploadAdvertiser*
U_dji_sdk_MissionEventWpUploadAdvertiser::
  Create_MissionEventWpUpload_Advertiser(FString TopicName) {
    U_dji_sdk_MissionEventWpUploadAdvertiser* c =
      NewObject<U_dji_sdk_MissionEventWpUploadAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionEventWpUploadAdvertiser::Publish(
  F_dji_sdk_MissionEventWpUpload Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionEventWpUploadAdvertiser::
  U_dji_sdk_MissionEventWpUploadAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionEventWpUpload");
}

U_dji_sdk_MissionEventWpUploadSubscriber::
  U_dji_sdk_MissionEventWpUploadSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionEventWpUpload");
}
void U_dji_sdk_MissionEventWpUploadSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionEventWpUpload fdata;
    fdata.Unserialization(obj);
    OnMissionEventWpUploadData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionEventWpUploadSubscriber::OnRecieve(
  F_dji_sdk_MissionEventWpUpload Data) {}

U_dji_sdk_MissionEventWpUploadSubscriber*
U_dji_sdk_MissionEventWpUploadSubscriber::
  Create_MissionEventWpUpload_Subscriber(FString _TopicName) {
    U_dji_sdk_MissionEventWpUploadSubscriber* sub =
      NewObject<U_dji_sdk_MissionEventWpUploadSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Char::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt())
        this->data = v["data"].GetInt();
}

rapidjson::Value F_std_msgs_Char::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_CharAdvertiser* U_std_msgs_CharAdvertiser::Create_Char_Advertiser(
  FString TopicName) {
    U_std_msgs_CharAdvertiser* c = NewObject<U_std_msgs_CharAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_CharAdvertiser::Publish(F_std_msgs_Char Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_CharAdvertiser::U_std_msgs_CharAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Char");
}

U_std_msgs_CharSubscriber::U_std_msgs_CharSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Char");
}
void U_std_msgs_CharSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Char fdata;
    fdata.Unserialization(obj);
    OnCharData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_CharSubscriber::OnRecieve(F_std_msgs_Char Data) {}

U_std_msgs_CharSubscriber* U_std_msgs_CharSubscriber::Create_Char_Subscriber(
  FString _TopicName) {
    U_std_msgs_CharSubscriber* sub = NewObject<U_std_msgs_CharSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_PoseWithCovariance::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("pose") && v["pose"].IsObject())
        this->pose.Unserialization(v["pose"]);
}

rapidjson::Value F_geometry_msgs_PoseWithCovariance::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tpose;
    tpose.SetString("pose");

    s.AddMember(tpose, this->pose.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_PoseWithCovarianceAdvertiser*
U_geometry_msgs_PoseWithCovarianceAdvertiser::
  Create_PoseWithCovariance_Advertiser(FString TopicName) {
    U_geometry_msgs_PoseWithCovarianceAdvertiser* c =
      NewObject<U_geometry_msgs_PoseWithCovarianceAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_PoseWithCovarianceAdvertiser::Publish(
  F_geometry_msgs_PoseWithCovariance Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_PoseWithCovarianceAdvertiser::
  U_geometry_msgs_PoseWithCovarianceAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PoseWithCovariance");
}

U_geometry_msgs_PoseWithCovarianceSubscriber::
  U_geometry_msgs_PoseWithCovarianceSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PoseWithCovariance");
}
void U_geometry_msgs_PoseWithCovarianceSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_PoseWithCovariance fdata;
    fdata.Unserialization(obj);
    OnPoseWithCovarianceData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_PoseWithCovarianceSubscriber::OnRecieve(
  F_geometry_msgs_PoseWithCovariance Data) {}

U_geometry_msgs_PoseWithCovarianceSubscriber*
U_geometry_msgs_PoseWithCovarianceSubscriber::
  Create_PoseWithCovariance_Subscriber(FString _TopicName) {
    U_geometry_msgs_PoseWithCovarianceSubscriber* sub =
      NewObject<U_geometry_msgs_PoseWithCovarianceSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_nav_msgs_Odometry::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("child_frame_id") && v["child_frame_id"].IsString())
        this->child_frame_id = FString(v["child_frame_id"].GetString());

    if (v.HasMember("pose") && v["pose"].IsObject())
        this->pose.Unserialization(v["pose"]);

    if (v.HasMember("twist") && v["twist"].IsObject())
        this->twist.Unserialization(v["twist"]);
}

rapidjson::Value F_nav_msgs_Odometry::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tchild_frame_id;
    tchild_frame_id.SetString("child_frame_id");

    rapidjson::Value schild_frame_id;
    std::string fuck_child_frame_id = TCHAR_TO_UTF8(*this->child_frame_id);
    schild_frame_id.SetString(
      rapidjson::StringRef(fuck_child_frame_id.c_str()));
    s.AddMember(tchild_frame_id, schild_frame_id, d.GetAllocator());

    rapidjson::Value tpose;
    tpose.SetString("pose");

    s.AddMember(tpose, this->pose.Serialization(d), d.GetAllocator());

    rapidjson::Value ttwist;
    ttwist.SetString("twist");

    s.AddMember(ttwist, this->twist.Serialization(d), d.GetAllocator());

    return s;
}

U_nav_msgs_OdometryAdvertiser*
U_nav_msgs_OdometryAdvertiser::Create_Odometry_Advertiser(FString TopicName) {
    U_nav_msgs_OdometryAdvertiser* c =
      NewObject<U_nav_msgs_OdometryAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_nav_msgs_OdometryAdvertiser::Publish(F_nav_msgs_Odometry Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_nav_msgs_OdometryAdvertiser::U_nav_msgs_OdometryAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("nav_msgs/Odometry");
}

U_nav_msgs_OdometrySubscriber::U_nav_msgs_OdometrySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("nav_msgs/Odometry");
}
void U_nav_msgs_OdometrySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_nav_msgs_Odometry fdata;
    fdata.Unserialization(obj);
    OnOdometryData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_nav_msgs_OdometrySubscriber::OnRecieve(F_nav_msgs_Odometry Data) {}

U_nav_msgs_OdometrySubscriber*
U_nav_msgs_OdometrySubscriber::Create_Odometry_Subscriber(FString _TopicName) {
    U_nav_msgs_OdometrySubscriber* sub =
      NewObject<U_nav_msgs_OdometrySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_PoseWithCovarianceStamped::Unserialization(
  rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("pose") && v["pose"].IsObject())
        this->pose.Unserialization(v["pose"]);
}

rapidjson::Value F_geometry_msgs_PoseWithCovarianceStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tpose;
    tpose.SetString("pose");

    s.AddMember(tpose, this->pose.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_PoseWithCovarianceStampedAdvertiser*
U_geometry_msgs_PoseWithCovarianceStampedAdvertiser::
  Create_PoseWithCovarianceStamped_Advertiser(FString TopicName) {
    U_geometry_msgs_PoseWithCovarianceStampedAdvertiser* c =
      NewObject<U_geometry_msgs_PoseWithCovarianceStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_PoseWithCovarianceStampedAdvertiser::Publish(
  F_geometry_msgs_PoseWithCovarianceStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_PoseWithCovarianceStampedAdvertiser::
  U_geometry_msgs_PoseWithCovarianceStampedAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PoseWithCovarianceStamped");
}

U_geometry_msgs_PoseWithCovarianceStampedSubscriber::
  U_geometry_msgs_PoseWithCovarianceStampedSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PoseWithCovarianceStamped");
}
void U_geometry_msgs_PoseWithCovarianceStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_PoseWithCovarianceStamped fdata;
    fdata.Unserialization(obj);
    OnPoseWithCovarianceStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_PoseWithCovarianceStampedSubscriber::OnRecieve(
  F_geometry_msgs_PoseWithCovarianceStamped Data) {}

U_geometry_msgs_PoseWithCovarianceStampedSubscriber*
U_geometry_msgs_PoseWithCovarianceStampedSubscriber::
  Create_PoseWithCovarianceStamped_Subscriber(FString _TopicName) {
    U_geometry_msgs_PoseWithCovarianceStampedSubscriber* sub =
      NewObject<U_geometry_msgs_PoseWithCovarianceStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionHotpointTask::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("latitude") && v["latitude"].IsDouble())
        this->latitude = v["latitude"].GetDouble();

    if (v.HasMember("longitude") && v["longitude"].IsDouble())
        this->longitude = v["longitude"].GetDouble();

    if (v.HasMember("altitude") && v["altitude"].IsDouble())
        this->altitude = v["altitude"].GetDouble();

    if (v.HasMember("radius") && v["radius"].IsDouble())
        this->radius = v["radius"].GetDouble();

    if (v.HasMember("angular_speed") && v["angular_speed"].IsDouble())
        this->angular_speed = v["angular_speed"].GetDouble();

    if (v.HasMember("is_clockwise") && v["is_clockwise"].IsInt())
        this->is_clockwise = v["is_clockwise"].GetInt();

    if (v.HasMember("start_point") && v["start_point"].IsInt())
        this->start_point = v["start_point"].GetInt();

    if (v.HasMember("yaw_mode") && v["yaw_mode"].IsInt())
        this->yaw_mode = v["yaw_mode"].GetInt();
}

rapidjson::Value F_dji_sdk_MissionHotpointTask::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlatitude;
    tlatitude.SetString("latitude");

    s.AddMember(tlatitude, this->latitude, d.GetAllocator());

    rapidjson::Value tlongitude;
    tlongitude.SetString("longitude");

    s.AddMember(tlongitude, this->longitude, d.GetAllocator());

    rapidjson::Value taltitude;
    taltitude.SetString("altitude");

    s.AddMember(taltitude, this->altitude, d.GetAllocator());

    rapidjson::Value tradius;
    tradius.SetString("radius");

    s.AddMember(tradius, this->radius, d.GetAllocator());

    rapidjson::Value tangular_speed;
    tangular_speed.SetString("angular_speed");

    s.AddMember(tangular_speed, this->angular_speed, d.GetAllocator());

    rapidjson::Value tis_clockwise;
    tis_clockwise.SetString("is_clockwise");

    s.AddMember(tis_clockwise, this->is_clockwise, d.GetAllocator());

    rapidjson::Value tstart_point;
    tstart_point.SetString("start_point");

    s.AddMember(tstart_point, this->start_point, d.GetAllocator());

    rapidjson::Value tyaw_mode;
    tyaw_mode.SetString("yaw_mode");

    s.AddMember(tyaw_mode, this->yaw_mode, d.GetAllocator());

    return s;
}

U_dji_sdk_MissionHotpointTaskAdvertiser*
U_dji_sdk_MissionHotpointTaskAdvertiser::Create_MissionHotpointTask_Advertiser(
  FString TopicName) {
    U_dji_sdk_MissionHotpointTaskAdvertiser* c =
      NewObject<U_dji_sdk_MissionHotpointTaskAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionHotpointTaskAdvertiser::Publish(
  F_dji_sdk_MissionHotpointTask Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionHotpointTaskAdvertiser::
  U_dji_sdk_MissionHotpointTaskAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionHotpointTask");
}

U_dji_sdk_MissionHotpointTaskSubscriber::
  U_dji_sdk_MissionHotpointTaskSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionHotpointTask");
}
void U_dji_sdk_MissionHotpointTaskSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_MissionHotpointTask fdata;
    fdata.Unserialization(obj);
    OnMissionHotpointTaskData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionHotpointTaskSubscriber::OnRecieve(
  F_dji_sdk_MissionHotpointTask Data) {}

U_dji_sdk_MissionHotpointTaskSubscriber*
U_dji_sdk_MissionHotpointTaskSubscriber::Create_MissionHotpointTask_Subscriber(
  FString _TopicName) {
    U_dji_sdk_MissionHotpointTaskSubscriber* sub =
      NewObject<U_dji_sdk_MissionHotpointTaskSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Int16MultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_std_msgs_Int16MultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (int32 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_Int16MultiArrayAdvertiser*
U_std_msgs_Int16MultiArrayAdvertiser::Create_Int16MultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_Int16MultiArrayAdvertiser* c =
      NewObject<U_std_msgs_Int16MultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_Int16MultiArrayAdvertiser::Publish(
  F_std_msgs_Int16MultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_Int16MultiArrayAdvertiser::U_std_msgs_Int16MultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int16MultiArray");
}

U_std_msgs_Int16MultiArraySubscriber::U_std_msgs_Int16MultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Int16MultiArray");
}
void U_std_msgs_Int16MultiArraySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Int16MultiArray fdata;
    fdata.Unserialization(obj);
    OnInt16MultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_Int16MultiArraySubscriber::OnRecieve(
  F_std_msgs_Int16MultiArray Data) {}

U_std_msgs_Int16MultiArraySubscriber*
U_std_msgs_Int16MultiArraySubscriber::Create_Int16MultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_Int16MultiArraySubscriber* sub =
      NewObject<U_std_msgs_Int16MultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_PowerStatus::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("percentage") && v["percentage"].IsInt())
        this->percentage = v["percentage"].GetInt();
}

rapidjson::Value F_dji_sdk_PowerStatus::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tpercentage;
    tpercentage.SetString("percentage");

    s.AddMember(tpercentage, this->percentage, d.GetAllocator());

    return s;
}

U_dji_sdk_PowerStatusAdvertiser*
U_dji_sdk_PowerStatusAdvertiser::Create_PowerStatus_Advertiser(
  FString TopicName) {
    U_dji_sdk_PowerStatusAdvertiser* c =
      NewObject<U_dji_sdk_PowerStatusAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_PowerStatusAdvertiser::Publish(F_dji_sdk_PowerStatus Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_PowerStatusAdvertiser::U_dji_sdk_PowerStatusAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/PowerStatus");
}

U_dji_sdk_PowerStatusSubscriber::U_dji_sdk_PowerStatusSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/PowerStatus");
}
void U_dji_sdk_PowerStatusSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_PowerStatus fdata;
    fdata.Unserialization(obj);
    OnPowerStatusData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_PowerStatusSubscriber::OnRecieve(F_dji_sdk_PowerStatus Data) {}

U_dji_sdk_PowerStatusSubscriber*
U_dji_sdk_PowerStatusSubscriber::Create_PowerStatus_Subscriber(
  FString _TopicName) {
    U_dji_sdk_PowerStatusSubscriber* sub =
      NewObject<U_dji_sdk_PowerStatusSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_UInt64MultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_std_msgs_UInt64MultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (int32 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_UInt64MultiArrayAdvertiser*
U_std_msgs_UInt64MultiArrayAdvertiser::Create_UInt64MultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_UInt64MultiArrayAdvertiser* c =
      NewObject<U_std_msgs_UInt64MultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_UInt64MultiArrayAdvertiser::Publish(
  F_std_msgs_UInt64MultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_UInt64MultiArrayAdvertiser::U_std_msgs_UInt64MultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt64MultiArray");
}

U_std_msgs_UInt64MultiArraySubscriber::U_std_msgs_UInt64MultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt64MultiArray");
}
void U_std_msgs_UInt64MultiArraySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_UInt64MultiArray fdata;
    fdata.Unserialization(obj);
    OnUInt64MultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_UInt64MultiArraySubscriber::OnRecieve(
  F_std_msgs_UInt64MultiArray Data) {}

U_std_msgs_UInt64MultiArraySubscriber*
U_std_msgs_UInt64MultiArraySubscriber::Create_UInt64MultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_UInt64MultiArraySubscriber* sub =
      NewObject<U_std_msgs_UInt64MultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_UInt16MultiArray::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("layout") && v["layout"].IsObject())
        this->layout.Unserialization(v["layout"]);

    if (v.HasMember("data") && v["data"].IsArray()) {
        rapidjson::Value& Adata = v["data"];
        for (rapidjson::SizeType i = 0; i < Adata.Size(); i++) {
            rapidjson::Value& kv = Adata[i];

            if (kv.IsInt()) this->data.Add(kv.GetInt());
        }
    }
}

rapidjson::Value F_std_msgs_UInt16MultiArray::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlayout;
    tlayout.SetString("layout");

    s.AddMember(tlayout, this->layout.Serialization(d), d.GetAllocator());

    rapidjson::Value tdata;
    tdata.SetString("data");

    rapidjson::Value Adata(rapidjson::kArrayType);
    for (int32 Element : data) {
        Adata.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tdata, Adata, d.GetAllocator());

    return s;
}

U_std_msgs_UInt16MultiArrayAdvertiser*
U_std_msgs_UInt16MultiArrayAdvertiser::Create_UInt16MultiArray_Advertiser(
  FString TopicName) {
    U_std_msgs_UInt16MultiArrayAdvertiser* c =
      NewObject<U_std_msgs_UInt16MultiArrayAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_UInt16MultiArrayAdvertiser::Publish(
  F_std_msgs_UInt16MultiArray Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_UInt16MultiArrayAdvertiser::U_std_msgs_UInt16MultiArrayAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt16MultiArray");
}

U_std_msgs_UInt16MultiArraySubscriber::U_std_msgs_UInt16MultiArraySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/UInt16MultiArray");
}
void U_std_msgs_UInt16MultiArraySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_UInt16MultiArray fdata;
    fdata.Unserialization(obj);
    OnUInt16MultiArrayData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_UInt16MultiArraySubscriber::OnRecieve(
  F_std_msgs_UInt16MultiArray Data) {}

U_std_msgs_UInt16MultiArraySubscriber*
U_std_msgs_UInt16MultiArraySubscriber::Create_UInt16MultiArray_Subscriber(
  FString _TopicName) {
    U_std_msgs_UInt16MultiArraySubscriber* sub =
      NewObject<U_std_msgs_UInt16MultiArraySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_RegionOfInterest::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("x_offset") && v["x_offset"].IsInt())
        this->x_offset = v["x_offset"].GetInt();

    if (v.HasMember("y_offset") && v["y_offset"].IsInt())
        this->y_offset = v["y_offset"].GetInt();

    if (v.HasMember("height") && v["height"].IsInt())
        this->height = v["height"].GetInt();

    if (v.HasMember("width") && v["width"].IsInt())
        this->width = v["width"].GetInt();

    if (v.HasMember("do_rectify") && v["do_rectify"].IsBool())
        this->do_rectify = v["do_rectify"].GetBool();
}

rapidjson::Value F_sensor_msgs_RegionOfInterest::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tx_offset;
    tx_offset.SetString("x_offset");

    s.AddMember(tx_offset, this->x_offset, d.GetAllocator());

    rapidjson::Value ty_offset;
    ty_offset.SetString("y_offset");

    s.AddMember(ty_offset, this->y_offset, d.GetAllocator());

    rapidjson::Value theight;
    theight.SetString("height");

    s.AddMember(theight, this->height, d.GetAllocator());

    rapidjson::Value twidth;
    twidth.SetString("width");

    s.AddMember(twidth, this->width, d.GetAllocator());

    rapidjson::Value tdo_rectify;
    tdo_rectify.SetString("do_rectify");

    s.AddMember(tdo_rectify, this->do_rectify, d.GetAllocator());

    return s;
}

U_sensor_msgs_RegionOfInterestAdvertiser*
U_sensor_msgs_RegionOfInterestAdvertiser::Create_RegionOfInterest_Advertiser(
  FString TopicName) {
    U_sensor_msgs_RegionOfInterestAdvertiser* c =
      NewObject<U_sensor_msgs_RegionOfInterestAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_RegionOfInterestAdvertiser::Publish(
  F_sensor_msgs_RegionOfInterest Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_RegionOfInterestAdvertiser::
  U_sensor_msgs_RegionOfInterestAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/RegionOfInterest");
}

U_sensor_msgs_RegionOfInterestSubscriber::
  U_sensor_msgs_RegionOfInterestSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/RegionOfInterest");
}
void U_sensor_msgs_RegionOfInterestSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_sensor_msgs_RegionOfInterest fdata;
    fdata.Unserialization(obj);
    OnRegionOfInterestData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_RegionOfInterestSubscriber::OnRecieve(
  F_sensor_msgs_RegionOfInterest Data) {}

U_sensor_msgs_RegionOfInterestSubscriber*
U_sensor_msgs_RegionOfInterestSubscriber::Create_RegionOfInterest_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_RegionOfInterestSubscriber* sub =
      NewObject<U_sensor_msgs_RegionOfInterestSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_CameraInfo::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("height") && v["height"].IsInt())
        this->height = v["height"].GetInt();

    if (v.HasMember("width") && v["width"].IsInt())
        this->width = v["width"].GetInt();

    if (v.HasMember("distortion_model") && v["distortion_model"].IsString())
        this->distortion_model = FString(v["distortion_model"].GetString());

    if (v.HasMember("binning_x") && v["binning_x"].IsInt())
        this->binning_x = v["binning_x"].GetInt();

    if (v.HasMember("binning_y") && v["binning_y"].IsInt())
        this->binning_y = v["binning_y"].GetInt();

    if (v.HasMember("roi") && v["roi"].IsObject())
        this->roi.Unserialization(v["roi"]);

    if (v.HasMember("D") && v["D"].IsArray()) {
        rapidjson::Value& AD = v["D"];
        for (rapidjson::SizeType i = 0; i < AD.Size(); i++) {
            rapidjson::Value& kv = AD[i];

            if (kv.IsDouble()) this->D.Add(kv.GetDouble());
        }
    }
}

rapidjson::Value F_sensor_msgs_CameraInfo::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value theight;
    theight.SetString("height");

    s.AddMember(theight, this->height, d.GetAllocator());

    rapidjson::Value twidth;
    twidth.SetString("width");

    s.AddMember(twidth, this->width, d.GetAllocator());

    rapidjson::Value tdistortion_model;
    tdistortion_model.SetString("distortion_model");

    rapidjson::Value sdistortion_model;
    std::string fuck_distortion_model = TCHAR_TO_UTF8(*this->distortion_model);
    sdistortion_model.SetString(
      rapidjson::StringRef(fuck_distortion_model.c_str()));
    s.AddMember(tdistortion_model, sdistortion_model, d.GetAllocator());

    rapidjson::Value tbinning_x;
    tbinning_x.SetString("binning_x");

    s.AddMember(tbinning_x, this->binning_x, d.GetAllocator());

    rapidjson::Value tbinning_y;
    tbinning_y.SetString("binning_y");

    s.AddMember(tbinning_y, this->binning_y, d.GetAllocator());

    rapidjson::Value troi;
    troi.SetString("roi");

    s.AddMember(troi, this->roi.Serialization(d), d.GetAllocator());

    rapidjson::Value tD;
    tD.SetString("D");

    rapidjson::Value AD(rapidjson::kArrayType);
    for (float Element : D) {
        AD.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tD, AD, d.GetAllocator());

    return s;
}

U_sensor_msgs_CameraInfoAdvertiser*
U_sensor_msgs_CameraInfoAdvertiser::Create_CameraInfo_Advertiser(
  FString TopicName) {
    U_sensor_msgs_CameraInfoAdvertiser* c =
      NewObject<U_sensor_msgs_CameraInfoAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_CameraInfoAdvertiser::Publish(
  F_sensor_msgs_CameraInfo Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_CameraInfoAdvertiser::U_sensor_msgs_CameraInfoAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/CameraInfo");
}

U_sensor_msgs_CameraInfoSubscriber::U_sensor_msgs_CameraInfoSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/CameraInfo");
}
void U_sensor_msgs_CameraInfoSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_CameraInfo fdata;
    fdata.Unserialization(obj);
    OnCameraInfoData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_CameraInfoSubscriber::OnRecieve(
  F_sensor_msgs_CameraInfo Data) {}

U_sensor_msgs_CameraInfoSubscriber*
U_sensor_msgs_CameraInfoSubscriber::Create_CameraInfo_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_CameraInfoSubscriber* sub =
      NewObject<U_sensor_msgs_CameraInfoSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_stereo_msgs_DisparityImage::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("image") && v["image"].IsObject())
        this->image.Unserialization(v["image"]);

    if (v.HasMember("f") && v["f"].IsDouble()) this->f = v["f"].GetDouble();

    if (v.HasMember("T") && v["T"].IsDouble()) this->T = v["T"].GetDouble();

    if (v.HasMember("valid_window") && v["valid_window"].IsObject())
        this->valid_window.Unserialization(v["valid_window"]);

    if (v.HasMember("min_disparity") && v["min_disparity"].IsDouble())
        this->min_disparity = v["min_disparity"].GetDouble();

    if (v.HasMember("max_disparity") && v["max_disparity"].IsDouble())
        this->max_disparity = v["max_disparity"].GetDouble();

    if (v.HasMember("delta_d") && v["delta_d"].IsDouble())
        this->delta_d = v["delta_d"].GetDouble();
}

rapidjson::Value F_stereo_msgs_DisparityImage::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value timage;
    timage.SetString("image");

    s.AddMember(timage, this->image.Serialization(d), d.GetAllocator());

    rapidjson::Value tf;
    tf.SetString("f");

    s.AddMember(tf, this->f, d.GetAllocator());

    rapidjson::Value tT;
    tT.SetString("T");

    s.AddMember(tT, this->T, d.GetAllocator());

    rapidjson::Value tvalid_window;
    tvalid_window.SetString("valid_window");

    s.AddMember(tvalid_window, this->valid_window.Serialization(d),
                d.GetAllocator());

    rapidjson::Value tmin_disparity;
    tmin_disparity.SetString("min_disparity");

    s.AddMember(tmin_disparity, this->min_disparity, d.GetAllocator());

    rapidjson::Value tmax_disparity;
    tmax_disparity.SetString("max_disparity");

    s.AddMember(tmax_disparity, this->max_disparity, d.GetAllocator());

    rapidjson::Value tdelta_d;
    tdelta_d.SetString("delta_d");

    s.AddMember(tdelta_d, this->delta_d, d.GetAllocator());

    return s;
}

U_stereo_msgs_DisparityImageAdvertiser*
U_stereo_msgs_DisparityImageAdvertiser::Create_DisparityImage_Advertiser(
  FString TopicName) {
    U_stereo_msgs_DisparityImageAdvertiser* c =
      NewObject<U_stereo_msgs_DisparityImageAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_stereo_msgs_DisparityImageAdvertiser::Publish(
  F_stereo_msgs_DisparityImage Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_stereo_msgs_DisparityImageAdvertiser::U_stereo_msgs_DisparityImageAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("stereo_msgs/DisparityImage");
}

U_stereo_msgs_DisparityImageSubscriber::U_stereo_msgs_DisparityImageSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("stereo_msgs/DisparityImage");
}
void U_stereo_msgs_DisparityImageSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_stereo_msgs_DisparityImage fdata;
    fdata.Unserialization(obj);
    OnDisparityImageData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_stereo_msgs_DisparityImageSubscriber::OnRecieve(
  F_stereo_msgs_DisparityImage Data) {}

U_stereo_msgs_DisparityImageSubscriber*
U_stereo_msgs_DisparityImageSubscriber::Create_DisparityImage_Subscriber(
  FString _TopicName) {
    U_stereo_msgs_DisparityImageSubscriber* sub =
      NewObject<U_stereo_msgs_DisparityImageSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_LaserScan::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("angle_min") && v["angle_min"].IsDouble())
        this->angle_min = v["angle_min"].GetDouble();

    if (v.HasMember("angle_max") && v["angle_max"].IsDouble())
        this->angle_max = v["angle_max"].GetDouble();

    if (v.HasMember("angle_increment") && v["angle_increment"].IsDouble())
        this->angle_increment = v["angle_increment"].GetDouble();

    if (v.HasMember("time_increment") && v["time_increment"].IsDouble())
        this->time_increment = v["time_increment"].GetDouble();

    if (v.HasMember("scan_time") && v["scan_time"].IsDouble())
        this->scan_time = v["scan_time"].GetDouble();

    if (v.HasMember("range_min") && v["range_min"].IsDouble())
        this->range_min = v["range_min"].GetDouble();

    if (v.HasMember("range_max") && v["range_max"].IsDouble())
        this->range_max = v["range_max"].GetDouble();

    if (v.HasMember("ranges") && v["ranges"].IsArray()) {
        rapidjson::Value& Aranges = v["ranges"];
        for (rapidjson::SizeType i = 0; i < Aranges.Size(); i++) {
            rapidjson::Value& kv = Aranges[i];

            if (kv.IsDouble()) this->ranges.Add(kv.GetDouble());
        }
    }

    if (v.HasMember("intensities") && v["intensities"].IsArray()) {
        rapidjson::Value& Aintensities = v["intensities"];
        for (rapidjson::SizeType i = 0; i < Aintensities.Size(); i++) {
            rapidjson::Value& kv = Aintensities[i];

            if (kv.IsDouble()) this->intensities.Add(kv.GetDouble());
        }
    }
}

rapidjson::Value F_sensor_msgs_LaserScan::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tangle_min;
    tangle_min.SetString("angle_min");

    s.AddMember(tangle_min, this->angle_min, d.GetAllocator());

    rapidjson::Value tangle_max;
    tangle_max.SetString("angle_max");

    s.AddMember(tangle_max, this->angle_max, d.GetAllocator());

    rapidjson::Value tangle_increment;
    tangle_increment.SetString("angle_increment");

    s.AddMember(tangle_increment, this->angle_increment, d.GetAllocator());

    rapidjson::Value ttime_increment;
    ttime_increment.SetString("time_increment");

    s.AddMember(ttime_increment, this->time_increment, d.GetAllocator());

    rapidjson::Value tscan_time;
    tscan_time.SetString("scan_time");

    s.AddMember(tscan_time, this->scan_time, d.GetAllocator());

    rapidjson::Value trange_min;
    trange_min.SetString("range_min");

    s.AddMember(trange_min, this->range_min, d.GetAllocator());

    rapidjson::Value trange_max;
    trange_max.SetString("range_max");

    s.AddMember(trange_max, this->range_max, d.GetAllocator());

    rapidjson::Value tranges;
    tranges.SetString("ranges");

    rapidjson::Value Aranges(rapidjson::kArrayType);
    for (float Element : ranges) {
        Aranges.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tranges, Aranges, d.GetAllocator());

    rapidjson::Value tintensities;
    tintensities.SetString("intensities");

    rapidjson::Value Aintensities(rapidjson::kArrayType);
    for (float Element : intensities) {
        Aintensities.PushBack(Element, d.GetAllocator());
    }
    s.AddMember(tintensities, Aintensities, d.GetAllocator());

    return s;
}

U_sensor_msgs_LaserScanAdvertiser*
U_sensor_msgs_LaserScanAdvertiser::Create_LaserScan_Advertiser(
  FString TopicName) {
    U_sensor_msgs_LaserScanAdvertiser* c =
      NewObject<U_sensor_msgs_LaserScanAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_LaserScanAdvertiser::Publish(F_sensor_msgs_LaserScan Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_LaserScanAdvertiser::U_sensor_msgs_LaserScanAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/LaserScan");
}

U_sensor_msgs_LaserScanSubscriber::U_sensor_msgs_LaserScanSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/LaserScan");
}
void U_sensor_msgs_LaserScanSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_LaserScan fdata;
    fdata.Unserialization(obj);
    OnLaserScanData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_LaserScanSubscriber::OnRecieve(
  F_sensor_msgs_LaserScan Data) {}

U_sensor_msgs_LaserScanSubscriber*
U_sensor_msgs_LaserScanSubscriber::Create_LaserScan_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_LaserScanSubscriber* sub =
      NewObject<U_sensor_msgs_LaserScanSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_GlobalPosition::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("ts") && v["ts"].IsInt()) this->ts = v["ts"].GetInt();

    if (v.HasMember("latitude") && v["latitude"].IsDouble())
        this->latitude = v["latitude"].GetDouble();

    if (v.HasMember("longitude") && v["longitude"].IsDouble())
        this->longitude = v["longitude"].GetDouble();

    if (v.HasMember("altitude") && v["altitude"].IsDouble())
        this->altitude = v["altitude"].GetDouble();

    if (v.HasMember("height") && v["height"].IsDouble())
        this->height = v["height"].GetDouble();

    if (v.HasMember("health") && v["health"].IsInt())
        this->health = v["health"].GetInt();
}

rapidjson::Value F_dji_sdk_GlobalPosition::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tts;
    tts.SetString("ts");

    s.AddMember(tts, this->ts, d.GetAllocator());

    rapidjson::Value tlatitude;
    tlatitude.SetString("latitude");

    s.AddMember(tlatitude, this->latitude, d.GetAllocator());

    rapidjson::Value tlongitude;
    tlongitude.SetString("longitude");

    s.AddMember(tlongitude, this->longitude, d.GetAllocator());

    rapidjson::Value taltitude;
    taltitude.SetString("altitude");

    s.AddMember(taltitude, this->altitude, d.GetAllocator());

    rapidjson::Value theight;
    theight.SetString("height");

    s.AddMember(theight, this->height, d.GetAllocator());

    rapidjson::Value thealth;
    thealth.SetString("health");

    s.AddMember(thealth, this->health, d.GetAllocator());

    return s;
}

U_dji_sdk_GlobalPositionAdvertiser*
U_dji_sdk_GlobalPositionAdvertiser::Create_GlobalPosition_Advertiser(
  FString TopicName) {
    U_dji_sdk_GlobalPositionAdvertiser* c =
      NewObject<U_dji_sdk_GlobalPositionAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_GlobalPositionAdvertiser::Publish(
  F_dji_sdk_GlobalPosition Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_GlobalPositionAdvertiser::U_dji_sdk_GlobalPositionAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/GlobalPosition");
}

U_dji_sdk_GlobalPositionSubscriber::U_dji_sdk_GlobalPositionSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/GlobalPosition");
}
void U_dji_sdk_GlobalPositionSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_GlobalPosition fdata;
    fdata.Unserialization(obj);
    OnGlobalPositionData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_GlobalPositionSubscriber::OnRecieve(
  F_dji_sdk_GlobalPosition Data) {}

U_dji_sdk_GlobalPositionSubscriber*
U_dji_sdk_GlobalPositionSubscriber::Create_GlobalPosition_Subscriber(
  FString _TopicName) {
    U_dji_sdk_GlobalPositionSubscriber* sub =
      NewObject<U_dji_sdk_GlobalPositionSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_TimeReference::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("time_ref") && v["time_ref"].IsInt64())
        this->time_ref = v["time_ref"].GetInt64();

    if (v.HasMember("source") && v["source"].IsString())
        this->source = FString(v["source"].GetString());
}

rapidjson::Value F_sensor_msgs_TimeReference::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value ttime_ref;
    ttime_ref.SetString("time_ref");

    s.AddMember(ttime_ref, this->time_ref, d.GetAllocator());

    rapidjson::Value tsource;
    tsource.SetString("source");

    rapidjson::Value ssource;
    std::string fuck_source = TCHAR_TO_UTF8(*this->source);
    ssource.SetString(rapidjson::StringRef(fuck_source.c_str()));
    s.AddMember(tsource, ssource, d.GetAllocator());

    return s;
}

U_sensor_msgs_TimeReferenceAdvertiser*
U_sensor_msgs_TimeReferenceAdvertiser::Create_TimeReference_Advertiser(
  FString TopicName) {
    U_sensor_msgs_TimeReferenceAdvertiser* c =
      NewObject<U_sensor_msgs_TimeReferenceAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_TimeReferenceAdvertiser::Publish(
  F_sensor_msgs_TimeReference Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_TimeReferenceAdvertiser::U_sensor_msgs_TimeReferenceAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/TimeReference");
}

U_sensor_msgs_TimeReferenceSubscriber::U_sensor_msgs_TimeReferenceSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/TimeReference");
}
void U_sensor_msgs_TimeReferenceSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_TimeReference fdata;
    fdata.Unserialization(obj);
    OnTimeReferenceData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_TimeReferenceSubscriber::OnRecieve(
  F_sensor_msgs_TimeReference Data) {}

U_sensor_msgs_TimeReferenceSubscriber*
U_sensor_msgs_TimeReferenceSubscriber::Create_TimeReference_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_TimeReferenceSubscriber* sub =
      NewObject<U_sensor_msgs_TimeReferenceSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_PolygonStamped::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("polygon") && v["polygon"].IsObject())
        this->polygon.Unserialization(v["polygon"]);
}

rapidjson::Value F_geometry_msgs_PolygonStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tpolygon;
    tpolygon.SetString("polygon");

    s.AddMember(tpolygon, this->polygon.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_PolygonStampedAdvertiser*
U_geometry_msgs_PolygonStampedAdvertiser::Create_PolygonStamped_Advertiser(
  FString TopicName) {
    U_geometry_msgs_PolygonStampedAdvertiser* c =
      NewObject<U_geometry_msgs_PolygonStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_PolygonStampedAdvertiser::Publish(
  F_geometry_msgs_PolygonStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_PolygonStampedAdvertiser::
  U_geometry_msgs_PolygonStampedAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PolygonStamped");
}

U_geometry_msgs_PolygonStampedSubscriber::
  U_geometry_msgs_PolygonStampedSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/PolygonStamped");
}
void U_geometry_msgs_PolygonStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_PolygonStamped fdata;
    fdata.Unserialization(obj);
    OnPolygonStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_PolygonStampedSubscriber::OnRecieve(
  F_geometry_msgs_PolygonStamped Data) {}

U_geometry_msgs_PolygonStampedSubscriber*
U_geometry_msgs_PolygonStampedSubscriber::Create_PolygonStamped_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_PolygonStampedSubscriber* sub =
      NewObject<U_geometry_msgs_PolygonStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_std_msgs_Duration::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("data") && v["data"].IsInt64())
        this->data = v["data"].GetInt64();
}

rapidjson::Value F_std_msgs_Duration::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tdata;
    tdata.SetString("data");

    s.AddMember(tdata, this->data, d.GetAllocator());

    return s;
}

U_std_msgs_DurationAdvertiser*
U_std_msgs_DurationAdvertiser::Create_Duration_Advertiser(FString TopicName) {
    U_std_msgs_DurationAdvertiser* c =
      NewObject<U_std_msgs_DurationAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_std_msgs_DurationAdvertiser::Publish(F_std_msgs_Duration Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_std_msgs_DurationAdvertiser::U_std_msgs_DurationAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Duration");
}

U_std_msgs_DurationSubscriber::U_std_msgs_DurationSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("std_msgs/Duration");
}
void U_std_msgs_DurationSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_std_msgs_Duration fdata;
    fdata.Unserialization(obj);
    OnDurationData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_std_msgs_DurationSubscriber::OnRecieve(F_std_msgs_Duration Data) {}

U_std_msgs_DurationSubscriber*
U_std_msgs_DurationSubscriber::Create_Duration_Subscriber(FString _TopicName) {
    U_std_msgs_DurationSubscriber* sub =
      NewObject<U_std_msgs_DurationSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_MissionWaypoint::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("latitude") && v["latitude"].IsDouble())
        this->latitude = v["latitude"].GetDouble();

    if (v.HasMember("longitude") && v["longitude"].IsDouble())
        this->longitude = v["longitude"].GetDouble();

    if (v.HasMember("altitude") && v["altitude"].IsDouble())
        this->altitude = v["altitude"].GetDouble();

    if (v.HasMember("damping_distance") && v["damping_distance"].IsDouble())
        this->damping_distance = v["damping_distance"].GetDouble();

    if (v.HasMember("target_yaw") && v["target_yaw"].IsInt())
        this->target_yaw = v["target_yaw"].GetInt();

    if (v.HasMember("target_gimbal_pitch") && v["target_gimbal_pitch"].IsInt())
        this->target_gimbal_pitch = v["target_gimbal_pitch"].GetInt();

    if (v.HasMember("turn_mode") && v["turn_mode"].IsInt())
        this->turn_mode = v["turn_mode"].GetInt();

    if (v.HasMember("has_action") && v["has_action"].IsInt())
        this->has_action = v["has_action"].GetInt();

    if (v.HasMember("action_time_limit") && v["action_time_limit"].IsInt())
        this->action_time_limit = v["action_time_limit"].GetInt();

    if (v.HasMember("waypoint_action") && v["waypoint_action"].IsObject())
        this->waypoint_action.Unserialization(v["waypoint_action"]);
}

rapidjson::Value F_dji_sdk_MissionWaypoint::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tlatitude;
    tlatitude.SetString("latitude");

    s.AddMember(tlatitude, this->latitude, d.GetAllocator());

    rapidjson::Value tlongitude;
    tlongitude.SetString("longitude");

    s.AddMember(tlongitude, this->longitude, d.GetAllocator());

    rapidjson::Value taltitude;
    taltitude.SetString("altitude");

    s.AddMember(taltitude, this->altitude, d.GetAllocator());

    rapidjson::Value tdamping_distance;
    tdamping_distance.SetString("damping_distance");

    s.AddMember(tdamping_distance, this->damping_distance, d.GetAllocator());

    rapidjson::Value ttarget_yaw;
    ttarget_yaw.SetString("target_yaw");

    s.AddMember(ttarget_yaw, this->target_yaw, d.GetAllocator());

    rapidjson::Value ttarget_gimbal_pitch;
    ttarget_gimbal_pitch.SetString("target_gimbal_pitch");

    s.AddMember(ttarget_gimbal_pitch, this->target_gimbal_pitch,
                d.GetAllocator());

    rapidjson::Value tturn_mode;
    tturn_mode.SetString("turn_mode");

    s.AddMember(tturn_mode, this->turn_mode, d.GetAllocator());

    rapidjson::Value thas_action;
    thas_action.SetString("has_action");

    s.AddMember(thas_action, this->has_action, d.GetAllocator());

    rapidjson::Value taction_time_limit;
    taction_time_limit.SetString("action_time_limit");

    s.AddMember(taction_time_limit, this->action_time_limit, d.GetAllocator());

    rapidjson::Value twaypoint_action;
    twaypoint_action.SetString("waypoint_action");

    s.AddMember(twaypoint_action, this->waypoint_action.Serialization(d),
                d.GetAllocator());

    return s;
}

U_dji_sdk_MissionWaypointAdvertiser*
U_dji_sdk_MissionWaypointAdvertiser::Create_MissionWaypoint_Advertiser(
  FString TopicName) {
    U_dji_sdk_MissionWaypointAdvertiser* c =
      NewObject<U_dji_sdk_MissionWaypointAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_MissionWaypointAdvertiser::Publish(
  F_dji_sdk_MissionWaypoint Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_MissionWaypointAdvertiser::U_dji_sdk_MissionWaypointAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionWaypoint");
}

U_dji_sdk_MissionWaypointSubscriber::U_dji_sdk_MissionWaypointSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/MissionWaypoint");
}
void U_dji_sdk_MissionWaypointSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_MissionWaypoint fdata;
    fdata.Unserialization(obj);
    OnMissionWaypointData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_MissionWaypointSubscriber::OnRecieve(
  F_dji_sdk_MissionWaypoint Data) {}

U_dji_sdk_MissionWaypointSubscriber*
U_dji_sdk_MissionWaypointSubscriber::Create_MissionWaypoint_Subscriber(
  FString _TopicName) {
    U_dji_sdk_MissionWaypointSubscriber* sub =
      NewObject<U_dji_sdk_MissionWaypointSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_Wrench::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("force") && v["force"].IsObject())
        this->force.Unserialization(v["force"]);

    if (v.HasMember("torque") && v["torque"].IsObject())
        this->torque.Unserialization(v["torque"]);
}

rapidjson::Value F_geometry_msgs_Wrench::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tforce;
    tforce.SetString("force");

    s.AddMember(tforce, this->force.Serialization(d), d.GetAllocator());

    rapidjson::Value ttorque;
    ttorque.SetString("torque");

    s.AddMember(ttorque, this->torque.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_WrenchAdvertiser*
U_geometry_msgs_WrenchAdvertiser::Create_Wrench_Advertiser(FString TopicName) {
    U_geometry_msgs_WrenchAdvertiser* c =
      NewObject<U_geometry_msgs_WrenchAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_WrenchAdvertiser::Publish(F_geometry_msgs_Wrench Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_WrenchAdvertiser::U_geometry_msgs_WrenchAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Wrench");
}

U_geometry_msgs_WrenchSubscriber::U_geometry_msgs_WrenchSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/Wrench");
}
void U_geometry_msgs_WrenchSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_geometry_msgs_Wrench fdata;
    fdata.Unserialization(obj);
    OnWrenchData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_WrenchSubscriber::OnRecieve(F_geometry_msgs_Wrench Data) {}

U_geometry_msgs_WrenchSubscriber*
U_geometry_msgs_WrenchSubscriber::Create_Wrench_Subscriber(FString _TopicName) {
    U_geometry_msgs_WrenchSubscriber* sub =
      NewObject<U_geometry_msgs_WrenchSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_WrenchStamped::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("wrench") && v["wrench"].IsObject())
        this->wrench.Unserialization(v["wrench"]);
}

rapidjson::Value F_geometry_msgs_WrenchStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value twrench;
    twrench.SetString("wrench");

    s.AddMember(twrench, this->wrench.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_WrenchStampedAdvertiser*
U_geometry_msgs_WrenchStampedAdvertiser::Create_WrenchStamped_Advertiser(
  FString TopicName) {
    U_geometry_msgs_WrenchStampedAdvertiser* c =
      NewObject<U_geometry_msgs_WrenchStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_WrenchStampedAdvertiser::Publish(
  F_geometry_msgs_WrenchStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_WrenchStampedAdvertiser::
  U_geometry_msgs_WrenchStampedAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/WrenchStamped");
}

U_geometry_msgs_WrenchStampedSubscriber::
  U_geometry_msgs_WrenchStampedSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/WrenchStamped");
}
void U_geometry_msgs_WrenchStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_WrenchStamped fdata;
    fdata.Unserialization(obj);
    OnWrenchStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_WrenchStampedSubscriber::OnRecieve(
  F_geometry_msgs_WrenchStamped Data) {}

U_geometry_msgs_WrenchStampedSubscriber*
U_geometry_msgs_WrenchStampedSubscriber::Create_WrenchStamped_Subscriber(
  FString _TopicName) {
    U_geometry_msgs_WrenchStampedSubscriber* sub =
      NewObject<U_geometry_msgs_WrenchStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_geometry_msgs_AccelWithCovarianceStamped::Unserialization(
  rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("accel") && v["accel"].IsObject())
        this->accel.Unserialization(v["accel"]);
}

rapidjson::Value F_geometry_msgs_AccelWithCovarianceStamped::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value taccel;
    taccel.SetString("accel");

    s.AddMember(taccel, this->accel.Serialization(d), d.GetAllocator());

    return s;
}

U_geometry_msgs_AccelWithCovarianceStampedAdvertiser*
U_geometry_msgs_AccelWithCovarianceStampedAdvertiser::
  Create_AccelWithCovarianceStamped_Advertiser(FString TopicName) {
    U_geometry_msgs_AccelWithCovarianceStampedAdvertiser* c =
      NewObject<U_geometry_msgs_AccelWithCovarianceStampedAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_geometry_msgs_AccelWithCovarianceStampedAdvertiser::Publish(
  F_geometry_msgs_AccelWithCovarianceStamped Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_geometry_msgs_AccelWithCovarianceStampedAdvertiser::
  U_geometry_msgs_AccelWithCovarianceStampedAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/AccelWithCovarianceStamped");
}

U_geometry_msgs_AccelWithCovarianceStampedSubscriber::
  U_geometry_msgs_AccelWithCovarianceStampedSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("geometry_msgs/AccelWithCovarianceStamped");
}
void U_geometry_msgs_AccelWithCovarianceStampedSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_geometry_msgs_AccelWithCovarianceStamped fdata;
    fdata.Unserialization(obj);
    OnAccelWithCovarianceStampedData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_geometry_msgs_AccelWithCovarianceStampedSubscriber::OnRecieve(
  F_geometry_msgs_AccelWithCovarianceStamped Data) {}

U_geometry_msgs_AccelWithCovarianceStampedSubscriber*
U_geometry_msgs_AccelWithCovarianceStampedSubscriber::
  Create_AccelWithCovarianceStamped_Subscriber(FString _TopicName) {
    U_geometry_msgs_AccelWithCovarianceStampedSubscriber* sub =
      NewObject<U_geometry_msgs_AccelWithCovarianceStampedSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_AttitudeQuaternion::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("ts") && v["ts"].IsInt()) this->ts = v["ts"].GetInt();

    if (v.HasMember("q0") && v["q0"].IsDouble()) this->q0 = v["q0"].GetDouble();

    if (v.HasMember("q1") && v["q1"].IsDouble()) this->q1 = v["q1"].GetDouble();

    if (v.HasMember("q2") && v["q2"].IsDouble()) this->q2 = v["q2"].GetDouble();

    if (v.HasMember("q3") && v["q3"].IsDouble()) this->q3 = v["q3"].GetDouble();

    if (v.HasMember("wx") && v["wx"].IsDouble()) this->wx = v["wx"].GetDouble();

    if (v.HasMember("wy") && v["wy"].IsDouble()) this->wy = v["wy"].GetDouble();

    if (v.HasMember("wz") && v["wz"].IsDouble()) this->wz = v["wz"].GetDouble();
}

rapidjson::Value F_dji_sdk_AttitudeQuaternion::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tts;
    tts.SetString("ts");

    s.AddMember(tts, this->ts, d.GetAllocator());

    rapidjson::Value tq0;
    tq0.SetString("q0");

    s.AddMember(tq0, this->q0, d.GetAllocator());

    rapidjson::Value tq1;
    tq1.SetString("q1");

    s.AddMember(tq1, this->q1, d.GetAllocator());

    rapidjson::Value tq2;
    tq2.SetString("q2");

    s.AddMember(tq2, this->q2, d.GetAllocator());

    rapidjson::Value tq3;
    tq3.SetString("q3");

    s.AddMember(tq3, this->q3, d.GetAllocator());

    rapidjson::Value twx;
    twx.SetString("wx");

    s.AddMember(twx, this->wx, d.GetAllocator());

    rapidjson::Value twy;
    twy.SetString("wy");

    s.AddMember(twy, this->wy, d.GetAllocator());

    rapidjson::Value twz;
    twz.SetString("wz");

    s.AddMember(twz, this->wz, d.GetAllocator());

    return s;
}

U_dji_sdk_AttitudeQuaternionAdvertiser*
U_dji_sdk_AttitudeQuaternionAdvertiser::Create_AttitudeQuaternion_Advertiser(
  FString TopicName) {
    U_dji_sdk_AttitudeQuaternionAdvertiser* c =
      NewObject<U_dji_sdk_AttitudeQuaternionAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_AttitudeQuaternionAdvertiser::Publish(
  F_dji_sdk_AttitudeQuaternion Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_AttitudeQuaternionAdvertiser::U_dji_sdk_AttitudeQuaternionAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/AttitudeQuaternion");
}

U_dji_sdk_AttitudeQuaternionSubscriber::U_dji_sdk_AttitudeQuaternionSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/AttitudeQuaternion");
}
void U_dji_sdk_AttitudeQuaternionSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_dji_sdk_AttitudeQuaternion fdata;
    fdata.Unserialization(obj);
    OnAttitudeQuaternionData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_AttitudeQuaternionSubscriber::OnRecieve(
  F_dji_sdk_AttitudeQuaternion Data) {}

U_dji_sdk_AttitudeQuaternionSubscriber*
U_dji_sdk_AttitudeQuaternionSubscriber::Create_AttitudeQuaternion_Subscriber(
  FString _TopicName) {
    U_dji_sdk_AttitudeQuaternionSubscriber* sub =
      NewObject<U_dji_sdk_AttitudeQuaternionSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_actionlib_msgs_GoalID::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("stamp") && v["stamp"].IsInt64())
        this->stamp = v["stamp"].GetInt64();

    if (v.HasMember("id") && v["id"].IsString())
        this->id = FString(v["id"].GetString());
}

rapidjson::Value F_actionlib_msgs_GoalID::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tstamp;
    tstamp.SetString("stamp");

    s.AddMember(tstamp, this->stamp, d.GetAllocator());

    rapidjson::Value tid;
    tid.SetString("id");

    rapidjson::Value sid;
    std::string fuck_id = TCHAR_TO_UTF8(*this->id);
    sid.SetString(rapidjson::StringRef(fuck_id.c_str()));
    s.AddMember(tid, sid, d.GetAllocator());

    return s;
}

U_actionlib_msgs_GoalIDAdvertiser*
U_actionlib_msgs_GoalIDAdvertiser::Create_GoalID_Advertiser(FString TopicName) {
    U_actionlib_msgs_GoalIDAdvertiser* c =
      NewObject<U_actionlib_msgs_GoalIDAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_actionlib_msgs_GoalIDAdvertiser::Publish(F_actionlib_msgs_GoalID Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_actionlib_msgs_GoalIDAdvertiser::U_actionlib_msgs_GoalIDAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("actionlib_msgs/GoalID");
}

U_actionlib_msgs_GoalIDSubscriber::U_actionlib_msgs_GoalIDSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("actionlib_msgs/GoalID");
}
void U_actionlib_msgs_GoalIDSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_actionlib_msgs_GoalID fdata;
    fdata.Unserialization(obj);
    OnGoalIDData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_actionlib_msgs_GoalIDSubscriber::OnRecieve(
  F_actionlib_msgs_GoalID Data) {}

U_actionlib_msgs_GoalIDSubscriber*
U_actionlib_msgs_GoalIDSubscriber::Create_GoalID_Subscriber(
  FString _TopicName) {
    U_actionlib_msgs_GoalIDSubscriber* sub =
      NewObject<U_actionlib_msgs_GoalIDSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_actionlib_msgs_GoalStatus::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("goal_id") && v["goal_id"].IsObject())
        this->goal_id.Unserialization(v["goal_id"]);

    if (v.HasMember("status") && v["status"].IsInt())
        this->status = v["status"].GetInt();

    if (v.HasMember("text") && v["text"].IsString())
        this->text = FString(v["text"].GetString());
}

rapidjson::Value F_actionlib_msgs_GoalStatus::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tgoal_id;
    tgoal_id.SetString("goal_id");

    s.AddMember(tgoal_id, this->goal_id.Serialization(d), d.GetAllocator());

    rapidjson::Value tstatus;
    tstatus.SetString("status");

    s.AddMember(tstatus, this->status, d.GetAllocator());

    rapidjson::Value ttext;
    ttext.SetString("text");

    rapidjson::Value stext;
    std::string fuck_text = TCHAR_TO_UTF8(*this->text);
    stext.SetString(rapidjson::StringRef(fuck_text.c_str()));
    s.AddMember(ttext, stext, d.GetAllocator());

    return s;
}

U_actionlib_msgs_GoalStatusAdvertiser*
U_actionlib_msgs_GoalStatusAdvertiser::Create_GoalStatus_Advertiser(
  FString TopicName) {
    U_actionlib_msgs_GoalStatusAdvertiser* c =
      NewObject<U_actionlib_msgs_GoalStatusAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_actionlib_msgs_GoalStatusAdvertiser::Publish(
  F_actionlib_msgs_GoalStatus Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_actionlib_msgs_GoalStatusAdvertiser::U_actionlib_msgs_GoalStatusAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("actionlib_msgs/GoalStatus");
}

U_actionlib_msgs_GoalStatusSubscriber::U_actionlib_msgs_GoalStatusSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("actionlib_msgs/GoalStatus");
}
void U_actionlib_msgs_GoalStatusSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_actionlib_msgs_GoalStatus fdata;
    fdata.Unserialization(obj);
    OnGoalStatusData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_actionlib_msgs_GoalStatusSubscriber::OnRecieve(
  F_actionlib_msgs_GoalStatus Data) {}

U_actionlib_msgs_GoalStatusSubscriber*
U_actionlib_msgs_GoalStatusSubscriber::Create_GoalStatus_Subscriber(
  FString _TopicName) {
    U_actionlib_msgs_GoalStatusSubscriber* sub =
      NewObject<U_actionlib_msgs_GoalStatusSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_MultiEchoLaserScan::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("angle_min") && v["angle_min"].IsDouble())
        this->angle_min = v["angle_min"].GetDouble();

    if (v.HasMember("angle_max") && v["angle_max"].IsDouble())
        this->angle_max = v["angle_max"].GetDouble();

    if (v.HasMember("angle_increment") && v["angle_increment"].IsDouble())
        this->angle_increment = v["angle_increment"].GetDouble();

    if (v.HasMember("time_increment") && v["time_increment"].IsDouble())
        this->time_increment = v["time_increment"].GetDouble();

    if (v.HasMember("scan_time") && v["scan_time"].IsDouble())
        this->scan_time = v["scan_time"].GetDouble();

    if (v.HasMember("range_min") && v["range_min"].IsDouble())
        this->range_min = v["range_min"].GetDouble();

    if (v.HasMember("range_max") && v["range_max"].IsDouble())
        this->range_max = v["range_max"].GetDouble();

    if (v.HasMember("ranges") && v["ranges"].IsArray()) {
        rapidjson::Value& Aranges = v["ranges"];
        for (rapidjson::SizeType i = 0; i < Aranges.Size(); i++) {
            rapidjson::Value& kv = Aranges[i];

            if (kv.IsObject()) {
                F_sensor_msgs_LaserEcho e;
                e.Unserialization(kv);
                this->ranges.Add(e);
            }
        }
    }

    if (v.HasMember("intensities") && v["intensities"].IsArray()) {
        rapidjson::Value& Aintensities = v["intensities"];
        for (rapidjson::SizeType i = 0; i < Aintensities.Size(); i++) {
            rapidjson::Value& kv = Aintensities[i];

            if (kv.IsObject()) {
                F_sensor_msgs_LaserEcho e;
                e.Unserialization(kv);
                this->intensities.Add(e);
            }
        }
    }
}

rapidjson::Value F_sensor_msgs_MultiEchoLaserScan::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tangle_min;
    tangle_min.SetString("angle_min");

    s.AddMember(tangle_min, this->angle_min, d.GetAllocator());

    rapidjson::Value tangle_max;
    tangle_max.SetString("angle_max");

    s.AddMember(tangle_max, this->angle_max, d.GetAllocator());

    rapidjson::Value tangle_increment;
    tangle_increment.SetString("angle_increment");

    s.AddMember(tangle_increment, this->angle_increment, d.GetAllocator());

    rapidjson::Value ttime_increment;
    ttime_increment.SetString("time_increment");

    s.AddMember(ttime_increment, this->time_increment, d.GetAllocator());

    rapidjson::Value tscan_time;
    tscan_time.SetString("scan_time");

    s.AddMember(tscan_time, this->scan_time, d.GetAllocator());

    rapidjson::Value trange_min;
    trange_min.SetString("range_min");

    s.AddMember(trange_min, this->range_min, d.GetAllocator());

    rapidjson::Value trange_max;
    trange_max.SetString("range_max");

    s.AddMember(trange_max, this->range_max, d.GetAllocator());

    rapidjson::Value tranges;
    tranges.SetString("ranges");

    rapidjson::Value Aranges(rapidjson::kArrayType);
    for (F_sensor_msgs_LaserEcho Element : ranges) {
        Aranges.PushBack(Element.Serialization(d), d.GetAllocator());
    }
    s.AddMember(tranges, Aranges, d.GetAllocator());

    rapidjson::Value tintensities;
    tintensities.SetString("intensities");

    rapidjson::Value Aintensities(rapidjson::kArrayType);
    for (F_sensor_msgs_LaserEcho Element : intensities) {
        Aintensities.PushBack(Element.Serialization(d), d.GetAllocator());
    }
    s.AddMember(tintensities, Aintensities, d.GetAllocator());

    return s;
}

U_sensor_msgs_MultiEchoLaserScanAdvertiser*
U_sensor_msgs_MultiEchoLaserScanAdvertiser::
  Create_MultiEchoLaserScan_Advertiser(FString TopicName) {
    U_sensor_msgs_MultiEchoLaserScanAdvertiser* c =
      NewObject<U_sensor_msgs_MultiEchoLaserScanAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_MultiEchoLaserScanAdvertiser::Publish(
  F_sensor_msgs_MultiEchoLaserScan Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_MultiEchoLaserScanAdvertiser::
  U_sensor_msgs_MultiEchoLaserScanAdvertiser(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/MultiEchoLaserScan");
}

U_sensor_msgs_MultiEchoLaserScanSubscriber::
  U_sensor_msgs_MultiEchoLaserScanSubscriber(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/MultiEchoLaserScan");
}
void U_sensor_msgs_MultiEchoLaserScanSubscriber::ProccessMsg(
  rapidjson::Value& obj) {
    F_sensor_msgs_MultiEchoLaserScan fdata;
    fdata.Unserialization(obj);
    OnMultiEchoLaserScanData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_MultiEchoLaserScanSubscriber::OnRecieve(
  F_sensor_msgs_MultiEchoLaserScan Data) {}

U_sensor_msgs_MultiEchoLaserScanSubscriber*
U_sensor_msgs_MultiEchoLaserScanSubscriber::
  Create_MultiEchoLaserScan_Subscriber(FString _TopicName) {
    U_sensor_msgs_MultiEchoLaserScanSubscriber* sub =
      NewObject<U_sensor_msgs_MultiEchoLaserScanSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_FlightControlInfo::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("control_mode") && v["control_mode"].IsInt())
        this->control_mode = v["control_mode"].GetInt();

    if (v.HasMember("cur_ctrl_dev_in_navi_mode") &&
        v["cur_ctrl_dev_in_navi_mode"].IsInt())
        this->cur_ctrl_dev_in_navi_mode =
          v["cur_ctrl_dev_in_navi_mode"].GetInt();

    if (v.HasMember("serial_req_status") && v["serial_req_status"].IsInt())
        this->serial_req_status = v["serial_req_status"].GetInt();

    if (v.HasMember("virtual_rc_status") && v["virtual_rc_status"].IsInt())
        this->virtual_rc_status = v["virtual_rc_status"].GetInt();
}

rapidjson::Value F_dji_sdk_FlightControlInfo::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value tcontrol_mode;
    tcontrol_mode.SetString("control_mode");

    s.AddMember(tcontrol_mode, this->control_mode, d.GetAllocator());

    rapidjson::Value tcur_ctrl_dev_in_navi_mode;
    tcur_ctrl_dev_in_navi_mode.SetString("cur_ctrl_dev_in_navi_mode");

    s.AddMember(tcur_ctrl_dev_in_navi_mode, this->cur_ctrl_dev_in_navi_mode,
                d.GetAllocator());

    rapidjson::Value tserial_req_status;
    tserial_req_status.SetString("serial_req_status");

    s.AddMember(tserial_req_status, this->serial_req_status, d.GetAllocator());

    rapidjson::Value tvirtual_rc_status;
    tvirtual_rc_status.SetString("virtual_rc_status");

    s.AddMember(tvirtual_rc_status, this->virtual_rc_status, d.GetAllocator());

    return s;
}

U_dji_sdk_FlightControlInfoAdvertiser*
U_dji_sdk_FlightControlInfoAdvertiser::Create_FlightControlInfo_Advertiser(
  FString TopicName) {
    U_dji_sdk_FlightControlInfoAdvertiser* c =
      NewObject<U_dji_sdk_FlightControlInfoAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_FlightControlInfoAdvertiser::Publish(
  F_dji_sdk_FlightControlInfo Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_FlightControlInfoAdvertiser::U_dji_sdk_FlightControlInfoAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/FlightControlInfo");
}

U_dji_sdk_FlightControlInfoSubscriber::U_dji_sdk_FlightControlInfoSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/FlightControlInfo");
}
void U_dji_sdk_FlightControlInfoSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_FlightControlInfo fdata;
    fdata.Unserialization(obj);
    OnFlightControlInfoData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_FlightControlInfoSubscriber::OnRecieve(
  F_dji_sdk_FlightControlInfo Data) {}

U_dji_sdk_FlightControlInfoSubscriber*
U_dji_sdk_FlightControlInfoSubscriber::Create_FlightControlInfo_Subscriber(
  FString _TopicName) {
    U_dji_sdk_FlightControlInfoSubscriber* sub =
      NewObject<U_dji_sdk_FlightControlInfoSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_sensor_msgs_MagneticField::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("magnetic_field") && v["magnetic_field"].IsObject())
        this->magnetic_field.Unserialization(v["magnetic_field"]);
}

rapidjson::Value F_sensor_msgs_MagneticField::Serialization(
  rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tmagnetic_field;
    tmagnetic_field.SetString("magnetic_field");

    s.AddMember(tmagnetic_field, this->magnetic_field.Serialization(d),
                d.GetAllocator());

    return s;
}

U_sensor_msgs_MagneticFieldAdvertiser*
U_sensor_msgs_MagneticFieldAdvertiser::Create_MagneticField_Advertiser(
  FString TopicName) {
    U_sensor_msgs_MagneticFieldAdvertiser* c =
      NewObject<U_sensor_msgs_MagneticFieldAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_sensor_msgs_MagneticFieldAdvertiser::Publish(
  F_sensor_msgs_MagneticField Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_sensor_msgs_MagneticFieldAdvertiser::U_sensor_msgs_MagneticFieldAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/MagneticField");
}

U_sensor_msgs_MagneticFieldSubscriber::U_sensor_msgs_MagneticFieldSubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("sensor_msgs/MagneticField");
}
void U_sensor_msgs_MagneticFieldSubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_sensor_msgs_MagneticField fdata;
    fdata.Unserialization(obj);
    OnMagneticFieldData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_sensor_msgs_MagneticFieldSubscriber::OnRecieve(
  F_sensor_msgs_MagneticField Data) {}

U_sensor_msgs_MagneticFieldSubscriber*
U_sensor_msgs_MagneticFieldSubscriber::Create_MagneticField_Subscriber(
  FString _TopicName) {
    U_sensor_msgs_MagneticFieldSubscriber* sub =
      NewObject<U_sensor_msgs_MagneticFieldSubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}

void F_dji_sdk_Velocity::Unserialization(rapidjson::Value& v) {
    if (v.HasMember("header") && v["header"].IsObject())
        this->header.Unserialization(v["header"]);

    if (v.HasMember("ts") && v["ts"].IsInt()) this->ts = v["ts"].GetInt();

    if (v.HasMember("vx") && v["vx"].IsDouble()) this->vx = v["vx"].GetDouble();

    if (v.HasMember("vy") && v["vy"].IsDouble()) this->vy = v["vy"].GetDouble();

    if (v.HasMember("vz") && v["vz"].IsDouble()) this->vz = v["vz"].GetDouble();

    if (v.HasMember("health_flag") && v["health_flag"].IsInt())
        this->health_flag = v["health_flag"].GetInt();
}

rapidjson::Value F_dji_sdk_Velocity::Serialization(rapidjson::Document& d) {
    rapidjson::Value s(rapidjson::kObjectType);

    rapidjson::Value theader;
    theader.SetString("header");

    s.AddMember(theader, this->header.Serialization(d), d.GetAllocator());

    rapidjson::Value tts;
    tts.SetString("ts");

    s.AddMember(tts, this->ts, d.GetAllocator());

    rapidjson::Value tvx;
    tvx.SetString("vx");

    s.AddMember(tvx, this->vx, d.GetAllocator());

    rapidjson::Value tvy;
    tvy.SetString("vy");

    s.AddMember(tvy, this->vy, d.GetAllocator());

    rapidjson::Value tvz;
    tvz.SetString("vz");

    s.AddMember(tvz, this->vz, d.GetAllocator());

    rapidjson::Value thealth_flag;
    thealth_flag.SetString("health_flag");

    s.AddMember(thealth_flag, this->health_flag, d.GetAllocator());

    return s;
}

U_dji_sdk_VelocityAdvertiser*
U_dji_sdk_VelocityAdvertiser::Create_Velocity_Advertiser(FString TopicName) {
    U_dji_sdk_VelocityAdvertiser* c = NewObject<U_dji_sdk_VelocityAdvertiser>();
    c->TopicName = TopicName;
    c->Advertise();
    return c;
}

void U_dji_sdk_VelocityAdvertiser::Publish(F_dji_sdk_Velocity Data) {
    if (!Advertised) {
        Advertise();
    }
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("msg", Data.Serialization(d), d.GetAllocator());
    rapidjson::Value TopicName;
    TopicName.SetString(rapidjson::StringRef(TCHAR_TO_UTF8(*this->TopicName)));
    d.AddMember("topic", TopicName, d.GetAllocator());
    d.AddMember("op", "publish", d.GetAllocator());
    SendJson(d);
}

U_dji_sdk_VelocityAdvertiser::U_dji_sdk_VelocityAdvertiser(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/Velocity");
}

U_dji_sdk_VelocitySubscriber::U_dji_sdk_VelocitySubscriber(
  const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TypeName = FString("dji_sdk/Velocity");
}
void U_dji_sdk_VelocitySubscriber::ProccessMsg(rapidjson::Value& obj) {
    F_dji_sdk_Velocity fdata;
    fdata.Unserialization(obj);
    OnVelocityData.Broadcast(fdata);
    OnRecieve(fdata);
}

void U_dji_sdk_VelocitySubscriber::OnRecieve(F_dji_sdk_Velocity Data) {}

U_dji_sdk_VelocitySubscriber*
U_dji_sdk_VelocitySubscriber::Create_Velocity_Subscriber(FString _TopicName) {
    U_dji_sdk_VelocitySubscriber* sub =
      NewObject<U_dji_sdk_VelocitySubscriber>();
    sub->TopicName = _TopicName;
    sub->Subscribe();
    return sub;
}
