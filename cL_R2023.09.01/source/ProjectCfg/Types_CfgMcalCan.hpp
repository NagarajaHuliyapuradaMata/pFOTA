#if !defined(CAN_DRVGENERALTYPES_H)
#define CAN_DRVGENERALTYPES_H

typedef enum{
      CAN_T_START
   ,  CAN_T_STOP
   ,  CAN_T_SLEEP
   ,  CAN_T_WAKEUP
}Can_StateTransitionType;

typedef enum{
      CAN_CS_UNINIT
   ,  CAN_CS_STARTED
   ,  CAN_CS_STOPPED
   ,  CAN_CS_SLEEP
}Can_ControllerStateType;

typedef enum{
      CAN_ERRORSTATE_ACTIVE
   ,  CAN_ERRORSTATE_PASSIVE
   ,  CAN_ERRORSTATE_BUSOFF
}Can_ErrorStateType;

typedef enum{
      CAN_NOT_OK
   ,  CAN_OK
   ,  CAN_BUSY
}Can_ReturnType;

typedef  VAR(uint16, TYPEDEF) Can_IdType;
typedef  VAR(uint8,  TYPEDEF) Can_HwHandleType;
typedef  VAR(sint16, TYPEDEF) Can_SignedHwHandleType;
typedef P2VAR(uint8, TYPEDEF, CAN_APPL_VAR) Can_SduPtrType;

typedef struct Can_PduTypeTag{
   Can_IdType       id;
   uint8            length;
   Can_SduPtrType   sdu;
   PduIdType        swPduHandle;
}Can_PduType;

typedef struct Can_HwTypeTag{
   Can_IdType       CanId;
   Can_HwHandleType Hoh;
   uint8            ControllerId;
}Can_HwType;

#endif

