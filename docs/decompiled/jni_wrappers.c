// table 20fcff8
// nativeCreateEngineFactory ()J -> 011c92a0

/* === nativeCreateEngineFactory ()J | FUN_011c92a0 @ 011c92a0 size=40 === */

undefined8 FUN_011c92a0(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_020543f8(0x10);
  FUN_011ee934();
  return uVar1;
}


// calls FUN_020543f8 @ 020543f8
// calls FUN_011ee934 @ 011ee934
// nativeDeleteEngineFactory (J)V -> 00b0cf20

/* === nativeDeleteEngineFactory (J)V | Java_com_google_android_libraries_assistant_soda_Soda_nativeDelete @ 00b0cf20 size=28 === */

void Java_com_google_android_libraries_assistant_soda_Soda_nativeDelete
               (undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00b0cf34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 8))(param_3);
  return;
}


// nativeGetDataManager (J)J -> 011c92c8

/* === nativeGetDataManager (J)J | FUN_011c92c8 @ 011c92c8 size=48 === */

void FUN_011c92c8(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    FUN_00ba5604();
    return;
  }
  (**(code **)(*param_3 + 0x28))(param_3);
  return;
}


// calls FUN_00ba5604 @ 00ba5604
// nativeGetSettingManager (J)J -> 011c92f8

/* === nativeGetSettingManager (J)J | FUN_011c92f8 @ 011c92f8 size=48 === */

void FUN_011c92f8(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    FUN_00ba5604();
    return;
  }
  (**(code **)(*param_3 + 0x30))(param_3);
  return;
}


// calls FUN_00ba5604 @ 00ba5604
// nativeCreateEngine (JLjava/lang/String;Ljava/lang/String;)J -> 011c9328

/* === nativeCreateEngine (JLjava/lang/String;Ljava/lang/String;)J | JNI_nativeCreateEngine @ 011c9328 size=164 === */

undefined8
JNI_nativeCreateEngine(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  code *extraout_x8;
  undefined1 auVar2 [16];
  byte bStack_50;
  undefined7 uStack_4f;
  undefined8 uStack_40;
  ulong auStack_38 [3];
  
  uVar1 = 0;
  if (param_3 != (undefined8 *)0x0) {
    auStack_38[0] = 0;
    auStack_38[1] = 0;
    auStack_38[2] = 0;
    FUN_011cdfd0(param_1,param_4,auStack_38);
    auVar2 = FUN_011ce9e0();
    FUN_00bc2770(auVar2._0_8_,auVar2._8_8_,&bStack_50);
    uVar1 = FUN_011ce9e0();
    FUN_011cdfdc(*param_3,uVar1,auStack_38,&bStack_50);
    uVar1 = (*extraout_x8)();
    if ((bStack_50 & 1) != 0) {
      FUN_008cee58(uStack_40,CONCAT71(uStack_4f,bStack_50) & 0xfffffffffffffffe);
    }
    if ((auStack_38[0] & 1) != 0) {
      FUN_008cee58(auStack_38[2],auStack_38[0] & 0xfffffffffffffffe);
    }
  }
  return uVar1;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdfd0 @ 011cdfd0
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdfdc @ 011cdfdc
// calls FUN_008cee58 @ 008cee58
// nativeCreateMutableDictionaryAccessor (JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)J -> 011c93cc

/* === nativeCreateMutableDictionaryAccessor (JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)J | JNI_nativeCreateMutableDictionaryAccessor @ 011c93cc size=224 === */

long JNI_nativeCreateMutableDictionaryAccessor
               (undefined8 param_1,undefined8 param_2,long param_3,long param_4,long param_5,
               long param_6)

{
  long extraout_x8;
  ulong extraout_x8_00;
  undefined1 auVar1 [16];
  ulong auStack_78 [2];
  undefined8 uStack_68;
  byte bStack_60;
  undefined7 uStack_5f;
  undefined8 uStack_50;
  ulong auStack_48 [3];
  
  if (param_3 != 0) {
    if ((param_6 == 0 || param_5 == 0) || param_4 == 0) {
      param_3 = 0;
    }
    else {
      auStack_48[0] = 0;
      auStack_48[1] = 0;
      auStack_48[2] = 0;
      FUN_011cdfb8(param_1,param_4,auStack_48);
      FUN_011cdf18();
      FUN_011ce9e0();
      FUN_011cdf94();
      auVar1 = FUN_011ce9e0();
      FUN_00bc2770(auVar1._0_8_,auVar1._8_8_,auStack_78);
      FUN_011ce9e0();
      FUN_011cdef0();
      (**(code **)(extraout_x8 + 0x18))();
      FUN_011c1500();
      if ((extraout_x8_00 & 1) != 0) {
        FUN_008cee58(uStack_68,auStack_78[0] & 0xfffffffffffffffe);
      }
      if ((bStack_60 & 1) != 0) {
        FUN_008cee58(uStack_50,CONCAT71(uStack_5f,bStack_60) & 0xfffffffffffffffe);
      }
      if ((auStack_48[0] & 1) != 0) {
        FUN_008cee58(auStack_48[2],auStack_48[0] & 0xfffffffffffffffe);
      }
    }
  }
  return param_3;
}


// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011c1500 @ 011c1500
// calls FUN_011cdfb8 @ 011cdfb8
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf94 @ 011cdf94
// calls FUN_008cee58 @ 008cee58
// calls FUN_011cdef0 @ 011cdef0
// nativeShouldMigrateUserDictionary (JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z -> 011c94ac

/* === nativeShouldMigrateUserDictionary (JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z | JNI_nativeShouldMigrateUserDictionary @ 011c94ac size=208 === */

void JNI_nativeShouldMigrateUserDictionary
               (undefined8 param_1,undefined8 param_2,long param_3,long param_4,long param_5,
               long param_6)

{
  long extraout_x8;
  undefined1 auVar1 [16];
  byte bStack_78;
  undefined7 uStack_77;
  undefined8 uStack_68;
  byte bStack_60;
  undefined7 uStack_5f;
  undefined8 uStack_50;
  byte bStack_48;
  undefined7 uStack_47;
  undefined8 uStack_38;
  
  if (((param_6 != 0 && param_5 != 0) && param_4 != 0) && param_3 != 0) {
    FUN_011cdf50(param_1,param_4,&bStack_48);
    FUN_011cdfb8();
    FUN_011cdf18();
    FUN_011ce9e0();
    FUN_011cdf94();
    auVar1 = FUN_011ce9e0();
    FUN_00bc2770(auVar1._0_8_,auVar1._8_8_,&bStack_78);
    FUN_011ce9e0();
    FUN_011cdef0();
    (**(code **)(extraout_x8 + 0x38))();
    if ((bStack_78 & 1) != 0) {
      FUN_008cee58(uStack_68,CONCAT71(uStack_77,bStack_78) & 0xfffffffffffffffe);
    }
    if ((bStack_60 & 1) != 0) {
      FUN_008cee58(uStack_50,CONCAT71(uStack_5f,bStack_60) & 0xfffffffffffffffe);
    }
    if ((bStack_48 & 1) != 0) {
      FUN_008cee58(uStack_38,CONCAT71(uStack_47,bStack_48) & 0xfffffffffffffffe);
    }
  }
  FUN_011cdf84();
  return;
}


// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdf50 @ 011cdf50
// calls FUN_011cdf84 @ 011cdf84
// calls FUN_011cdfb8 @ 011cdfb8
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf94 @ 011cdf94
// calls FUN_008cee58 @ 008cee58
// calls FUN_011cdef0 @ 011cdef0
// nativeMigrateUserDictionary (JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z -> 011c957c

/* === nativeMigrateUserDictionary (JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z | JNI_nativeMigrateUserDictionary @ 011c957c size=364 === */

uint JNI_nativeMigrateUserDictionary
               (undefined8 param_1,undefined8 param_2,long *param_3,long param_4,long param_5,
               long param_6,long param_7)

{
  uint uVar1;
  undefined *puStack_a0;
  undefined8 uStack_98;
  ulong auStack_90 [12];
  
  if ((((param_7 == 0 || param_6 == 0) || param_5 == 0) || param_4 == 0) || param_3 == (long *)0x0)
  {
    uVar1 = 0;
  }
  else {
    auStack_90[9] = 0;
    auStack_90[10] = 0;
    auStack_90[0xb] = 0;
    auStack_90[6] = 0;
    auStack_90[7] = 0;
    auStack_90[8] = 0;
    auStack_90[3] = 0;
    auStack_90[4] = 0;
    auStack_90[5] = 0;
    auStack_90[0] = 0;
    auStack_90[1] = 0;
    auStack_90[2] = 0;
    FUN_011ce9e0(param_1,param_4,auStack_90 + 9);
    FUN_011ce9e0(param_1,param_5,auStack_90 + 6);
    FUN_011ce9e0(param_1,param_6,auStack_90 + 3);
    FUN_011ce9e0(param_1,param_7,auStack_90);
    puStack_a0 = PTR_DAT_02231288 + 0x10;
    uStack_98 = 0;
    FUN_0129b0e0(&puStack_a0,auStack_90);
    uVar1 = (**(code **)(*param_3 + 0x40))
                      (param_3,auStack_90 + 9,auStack_90 + 6,auStack_90 + 3,&puStack_a0);
    FUN_0129b078(&puStack_a0);
    if ((auStack_90[0] & 1) != 0) {
      FUN_008cee58(auStack_90[2],auStack_90[0] & 0xfffffffffffffffe);
    }
    if ((auStack_90[3] & 1) != 0) {
      FUN_008cee58(auStack_90[5],auStack_90[3] & 0xfffffffffffffffe);
    }
    if ((auStack_90[6] & 1) != 0) {
      FUN_008cee58(auStack_90[8],auStack_90[6] & 0xfffffffffffffffe);
    }
    uVar1 = uVar1 & 1;
    if ((auStack_90[9] & 1) != 0) {
      FUN_008cee58(auStack_90[0xb],auStack_90[9] & 0xfffffffffffffffe);
    }
  }
  return uVar1;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_0129b078 @ 0129b078
// calls FUN_0129b0e0 @ 0129b0e0
// calls FUN_008cee58 @ 008cee58
// nativeEnrollDataFile (JLjava/lang/String;ILjava/lang/String;)Z -> 011c98e8

/* === nativeEnrollDataFile (JLjava/lang/String;ILjava/lang/String;)Z | JNI_nativeEnrollDataFile @ 011c98e8 size=224 === */

uint JNI_nativeEnrollDataFile
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
               undefined4 param_5,undefined8 param_6)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  code *extraout_x8;
  undefined1 auVar5 [16];
  byte bStack_e8;
  undefined7 uStack_e7;
  undefined8 uStack_d8;
  undefined1 auStack_d0 [136];
  undefined8 uStack_48;
  ulong uStack_40;
  long lStack_38;
  
  uVar3 = 0;
  if (param_3 != (undefined8 *)0x0) {
    FUN_011cdf34(param_1,param_6,&uStack_48);
    uStack_48 = 0;
    uStack_40 = 0;
    lStack_38 = 0;
    FUN_011ce9e0();
    uVar1 = uStack_40;
    lVar2 = lStack_38;
    if ((uStack_48 & 1) == 0) {
      lVar2 = (long)&uStack_48 + 1;
      uVar1 = uStack_48 >> 1 & 0x7f;
    }
    auVar5 = FUN_01254dc0(auStack_d0,param_5,lVar2,uVar1);
    FUN_00bc2770(auVar5._0_8_,auVar5._8_8_,&bStack_e8);
    FUN_011cdf18();
    uVar4 = FUN_011ce9e0();
    FUN_011cdfdc(*param_3,uVar4,&bStack_e8,auStack_d0);
    uVar3 = (*extraout_x8)();
    if ((bStack_e8 & 1) != 0) {
      FUN_008cee58(uStack_d8,CONCAT71(uStack_e7,bStack_e8) & 0xfffffffffffffffe);
    }
    uVar3 = uVar3 & 1;
    FUN_011c99c8(auStack_d0);
    if ((uStack_48 & 1) != 0) {
      FUN_008cee58(lStack_38,uStack_48 & 0xfffffffffffffffe);
    }
  }
  return uVar3;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011c99c8 @ 011c99c8
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdfdc @ 011cdfdc
// calls FUN_008cee58 @ 008cee58
// calls FUN_01254dc0 @ 01254dc0
// nativeEnrollDataFd (JLjava/lang/String;ILjava/io/FileDescriptor;II)Z -> 011c9a50

/* === nativeEnrollDataFd (JLjava/lang/String;ILjava/io/FileDescriptor;II)Z | JNI_nativeEnrollDataFd @ 011c9a50 size=196 === */

ulong JNI_nativeEnrollDataFd
                (long *param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
                undefined4 param_5,undefined8 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  undefined8 uVar2;
  code *extraout_x8;
  code *extraout_x8_00;
  ulong extraout_x8_01;
  undefined1 auVar3 [16];
  ulong auStack_e0 [2];
  undefined8 uStack_d0;
  undefined1 auStack_c8 [136];
  
  if (param_3 != (undefined8 *)0x0) {
    FUN_011cdf34(*(undefined8 *)(*param_1 + 800),param_1,param_6,DAT_022a3408);
    uVar1 = (*extraout_x8)();
    auVar3 = FUN_01254e20(auStack_c8,param_5,uVar1,param_7,param_8);
    FUN_00bc2770(auVar3._0_8_,auVar3._8_8_,auStack_e0);
    FUN_011cdfd0();
    uVar2 = FUN_011ce9e0();
    FUN_011cdfdc(*param_3,uVar2,auStack_e0,auStack_c8);
    (*extraout_x8_00)();
    FUN_011cdfc4();
    if ((extraout_x8_01 & 1) != 0) {
      FUN_008cee58(uStack_d0,auStack_e0[0] & 0xfffffffffffffffe);
    }
    FUN_011c99c8(auStack_c8);
  }
  return (ulong)param_3 & 0xffffffff;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdfd0 @ 011cdfd0
// calls FUN_011c99c8 @ 011c99c8
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdfdc @ 011cdfdc
// calls FUN_008cee58 @ 008cee58
// calls FUN_011cdfc4 @ 011cdfc4
// calls FUN_01254e20 @ 01254e20
// nativeEnrollBuiltInData (JLjava/lang/String;ILjava/lang/String;Ljava/lang/String;)Z -> 011c9b14

/* === nativeEnrollBuiltInData (JLjava/lang/String;ILjava/lang/String;Ljava/lang/String;)Z | JNI_nativeEnrollBuiltInData @ 011c9b14 size=372 === */

uint JNI_nativeEnrollBuiltInData
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
               undefined4 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined *puVar1;
  uint uVar2;
  long lVar3;
  long *plVar4;
  undefined8 uVar5;
  code *extraout_x8;
  undefined1 auStack_120 [8];
  undefined1 auStack_118 [136];
  ulong auStack_90 [10];
  
  if (param_3 == (undefined8 *)0x0) {
    uVar2 = 0;
  }
  else {
    auStack_90[7] = 0;
    auStack_90[8] = 0;
    auStack_90[9] = 0;
    FUN_011ce9e0(param_1,param_6,auStack_90 + 7);
    auStack_90[4] = 0;
    auStack_90[5] = 0;
    auStack_90[6] = 0;
    FUN_011ce9e0(param_1,param_7,auStack_90 + 4);
    auStack_90[3] = 0;
    lVar3 = FUN_011ceb90(auStack_90 + 4,auStack_90 + 7,auStack_90 + 3);
    uVar2 = 0;
    if ((lVar3 != 0) && (auStack_90[3] != 0)) {
      auStack_90[0] = 0;
      auStack_90[1] = 0;
      auStack_90[2] = 0;
      FUN_011ce9e0(param_1,param_4,auStack_90);
      plVar4 = (long *)FUN_020543f8(0x20);
      puVar1 = PTR_DAT_02231290;
      *(undefined4 *)(plVar4 + 1) = 0;
      plVar4[2] = lVar3;
      plVar4[3] = auStack_90[3];
      *plVar4 = (long)(puVar1 + 0x10);
      FUN_0129b21c(auStack_120,plVar4);
      uVar5 = FUN_01254e58(auStack_118,param_5,auStack_120);
      FUN_011cdfdc(*param_3,uVar5,auStack_90,auStack_118);
      uVar2 = (*extraout_x8)();
      uVar2 = uVar2 & 1;
      FUN_011c99c8(auStack_118);
      FUN_0129b258(auStack_120);
      if ((auStack_90[0] & 1) != 0) {
        FUN_008cee58(auStack_90[2],auStack_90[0] & 0xfffffffffffffffe);
      }
    }
    if ((auStack_90[4] & 1) != 0) {
      FUN_008cee58(auStack_90[6],auStack_90[4] & 0xfffffffffffffffe);
    }
    if ((auStack_90[7] & 1) != 0) {
      FUN_008cee58(auStack_90[9],auStack_90[7] & 0xfffffffffffffffe);
    }
  }
  return uVar2;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_01254e58 @ 01254e58
// calls FUN_011ceb90 @ 011ceb90
// calls FUN_011c99c8 @ 011c99c8
// calls FUN_0129b21c @ 0129b21c
// calls FUN_011cdfdc @ 011cdfdc
// calls FUN_008cee58 @ 008cee58
// calls FUN_0129b258 @ 0129b258
// calls FUN_020543f8 @ 020543f8
// nativeEnrollEmptyData (JLjava/lang/String;I)Z -> 011c9d80

/* === nativeEnrollEmptyData (JLjava/lang/String;I)Z | JNI_nativeEnrollEmptyData @ 011c9d80 size=156 === */

uint JNI_nativeEnrollEmptyData
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
               undefined4 param_5)

{
  uint uVar1;
  undefined8 uVar2;
  code *extraout_x8;
  undefined1 auStack_c0 [136];
  ulong auStack_38 [3];
  undefined8 uStack_18;
  
  uVar1 = 0;
  if (param_3 != (undefined8 *)0x0) {
    auStack_38[0] = 0;
    auStack_38[1] = 0;
    auStack_38[2] = 0;
    FUN_011ce9e0(param_1,param_4,auStack_38);
    uStack_18 = 0;
    uVar2 = FUN_01254e58(auStack_c0,param_5,&uStack_18);
    FUN_011cdfdc(*param_3,uVar2,auStack_38,auStack_c0);
    uVar1 = (*extraout_x8)();
    uVar1 = uVar1 & 1;
    FUN_011c99c8(auStack_c0);
    FUN_0129b258(&uStack_18);
    if ((auStack_38[0] & 1) != 0) {
      FUN_008cee58(auStack_38[2],auStack_38[0] & 0xfffffffffffffffe);
    }
  }
  return uVar1;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_01254e58 @ 01254e58
// calls FUN_011c99c8 @ 011c99c8
// calls FUN_011cdfdc @ 011cdfdc
// calls FUN_008cee58 @ 008cee58
// calls FUN_0129b258 @ 0129b258
// nativeWithdrawData (JLjava/lang/String;)Z -> 011c96e8

/* === nativeWithdrawData (JLjava/lang/String;)Z | JNI_nativeWithdrawData @ 011c96e8 size=88 === */

ulong JNI_nativeWithdrawData(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  long extraout_x8;
  ulong extraout_x8_00;
  ulong uStack_28;
  undefined8 uStack_18;
  
  if (param_3 != 0) {
    FUN_011cdfac();
    FUN_011cdf18();
    FUN_011ce9e0();
    FUN_011cdf08();
    (**(code **)(extraout_x8 + 0x30))();
    FUN_011cdf68();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,uStack_28 & 0xfffffffffffffffe);
    }
  }
  return param_3 & 0xffffffff;
}


// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdf68 @ 011cdf68
// calls FUN_011cdfac @ 011cdfac
// calls FUN_011cdf08 @ 011cdf08
// calls FUN_008cee58 @ 008cee58
// nativeWithdrawDataScheme (J[B)Z -> 011c9740

/* === nativeWithdrawDataScheme (J[B)Z | JNI_nativeWithdrawDataScheme @ 011c9740 size=212 === */

uint JNI_nativeWithdrawDataScheme(long *param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long extraout_x8;
  long extraout_x8_00;
  undefined1 auVar4 [16];
  byte bStack_50;
  undefined7 uStack_4f;
  undefined8 uStack_40;
  undefined1 uStack_31;
  
  if (param_3 == (long *)0x0) {
    uVar2 = 0;
  }
  else {
    lVar3 = (**(code **)(*param_1 + 0x6f0))(param_1,param_4,&uStack_31);
    FUN_00b07fdc(*param_1);
    iVar1 = (**(code **)(extraout_x8 + 0x558))();
    uVar2 = 0;
    if ((lVar3 != 0) && (iVar1 != 0)) {
      FUN_00905438(&bStack_50,lVar3,(long)iVar1);
      uVar2 = (**(code **)(*param_3 + 0x38))(param_3,&bStack_50);
      uVar2 = uVar2 & 1;
      auVar4 = FUN_00b07fdc(*param_1);
      (**(code **)(extraout_x8_00 + 0x6f8))(auVar4._0_8_,auVar4._8_8_,lVar3,0);
      if ((bStack_50 & 1) != 0) {
        FUN_008cee58(uStack_40,CONCAT71(uStack_4f,bStack_50) & 0xfffffffffffffffe);
      }
    }
  }
  return uVar2;
}


// calls FUN_00905438 @ 00905438
// calls FUN_00b07fdc @ 00b07fdc
// calls FUN_008cee58 @ 008cee58
// nativeEnrollDataScheme (J[B)Z -> 011c9814

/* === nativeEnrollDataScheme (J[B)Z | JNI_nativeEnrollDataScheme @ 011c9814 size=212 === */

uint JNI_nativeEnrollDataScheme(long *param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long extraout_x8;
  long extraout_x8_00;
  undefined1 auVar4 [16];
  byte bStack_50;
  undefined7 uStack_4f;
  undefined8 uStack_40;
  undefined1 uStack_31;
  
  if (param_3 == (long *)0x0) {
    uVar2 = 0;
  }
  else {
    lVar3 = (**(code **)(*param_1 + 0x6f0))(param_1,param_4,&uStack_31);
    FUN_00b07fdc(*param_1);
    iVar1 = (**(code **)(extraout_x8 + 0x558))();
    uVar2 = 0;
    if ((lVar3 != 0) && (iVar1 != 0)) {
      FUN_00905438(&bStack_50,lVar3,(long)iVar1);
      uVar2 = (**(code **)(*param_3 + 0x18))(param_3,&bStack_50);
      uVar2 = uVar2 & 1;
      auVar4 = FUN_00b07fdc(*param_1);
      (**(code **)(extraout_x8_00 + 0x6f8))(auVar4._0_8_,auVar4._8_8_,lVar3,0);
      if ((bStack_50 & 1) != 0) {
        FUN_008cee58(uStack_40,CONCAT71(uStack_4f,bStack_50) & 0xfffffffffffffffe);
      }
    }
  }
  return uVar2;
}


// calls FUN_00905438 @ 00905438
// calls FUN_00b07fdc @ 00b07fdc
// calls FUN_008cee58 @ 008cee58
// nativeEnrollBuiltInDataScheme (JLjava/lang/String;Ljava/lang/String;)Z -> 011c9c88

/* === nativeEnrollBuiltInDataScheme (JLjava/lang/String;Ljava/lang/String;)Z | JNI_nativeEnrollBuiltInDataScheme @ 011c9c88 size=248 === */

uint JNI_nativeEnrollBuiltInDataScheme
               (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  byte bStack_70;
  undefined7 uStack_6f;
  undefined8 uStack_60;
  long lStack_58;
  byte bStack_50;
  undefined7 uStack_4f;
  undefined8 uStack_40;
  ulong auStack_38 [3];
  
  if (param_3 == (long *)0x0) {
    uVar1 = 0;
  }
  else {
    auStack_38[0] = 0;
    auStack_38[1] = 0;
    auStack_38[2] = 0;
    auVar3 = FUN_011ce9e0(param_1,param_4,auStack_38);
    FUN_00bc2770(auVar3._0_8_,auVar3._8_8_,&bStack_50);
    FUN_011cdfb8();
    FUN_011ce9e0();
    lStack_58 = 0;
    lVar2 = FUN_011ceb90(&bStack_50,auStack_38,&lStack_58);
    uVar1 = 0;
    if ((lVar2 != 0) && (lStack_58 != 0)) {
      FUN_00905438(&bStack_70,lVar2);
      uVar1 = (**(code **)(*param_3 + 0x18))(param_3,&bStack_70);
      uVar1 = uVar1 & 1;
      if ((bStack_70 & 1) != 0) {
        FUN_008cee58(uStack_60,CONCAT71(uStack_6f,bStack_70) & 0xfffffffffffffffe);
      }
    }
    if ((bStack_50 & 1) != 0) {
      FUN_008cee58(uStack_40,CONCAT71(uStack_4f,bStack_50) & 0xfffffffffffffffe);
    }
    if ((auStack_38[0] & 1) != 0) {
      FUN_008cee58(auStack_38[2],auStack_38[0] & 0xfffffffffffffffe);
    }
  }
  return uVar1;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_00905438 @ 00905438
// calls FUN_011ceb90 @ 011ceb90
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdfb8 @ 011cdfb8
// calls FUN_008cee58 @ 008cee58
// nativeEnrollMutableDictFd (JLjava/lang/String;ILjava/io/FileDescriptor;III)Z -> 011c9e1c

/* === nativeEnrollMutableDictFd (JLjava/lang/String;ILjava/io/FileDescriptor;III)Z | JNI_nativeEnrollMutableDictFd @ 011c9e1c size=312 === */

ulong JNI_nativeEnrollMutableDictFd
                (long *param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
                undefined4 param_5,undefined8 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9)

{
  undefined4 uVar1;
  undefined8 uVar2;
  code *extraout_x8;
  code *extraout_x8_00;
  ulong extraout_x8_01;
  undefined1 auVar3 [16];
  ulong auStack_120 [3];
  undefined1 auStack_108 [16];
  uint uStack_f8;
  undefined4 uStack_f0;
  undefined1 uStack_ec;
  undefined1 auStack_d8 [112];
  undefined1 auStack_68 [16];
  undefined8 uStack_58;
  
  if (param_3 != (undefined8 *)0x0) {
    FUN_011cdf34(*(undefined8 *)(*param_1 + 800),param_1,param_6,DAT_022a3408);
    uVar1 = (*extraout_x8)();
    FUN_01254e20(auStack_d8,param_5,uVar1,param_7,param_8);
    FUN_01ba19c4(auStack_108,0);
    uStack_ec = 1;
    uStack_f8 = uStack_f8 | 3;
    uStack_f0 = param_9;
    auVar3 = FUN_009b3d20(auStack_120,auStack_108);
    if (((ulong)(byte)auStack_68[0] & 1) != 0) {
      auVar3 = FUN_008cee58(uStack_58,auStack_68._0_8_ & 0xfffffffffffffffe);
    }
    auStack_68 = FUN_00bc2770(auStack_120[2],auStack_120[0],auVar3._0_8_,auVar3._8_8_,auStack_120);
    auStack_120[0] = 0;
    auStack_120[1] = 0;
    auStack_120[2] = 0;
    uVar2 = FUN_011ce9e0();
    FUN_011cdfdc(*param_3,uVar2,auStack_120,auStack_d8);
    (*extraout_x8_00)();
    FUN_011cdfc4();
    if ((extraout_x8_01 & 1) != 0) {
      FUN_008cee58(auStack_120[2],auStack_120[0] & 0xfffffffffffffffe);
    }
    FUN_0090b5a0(auStack_108);
    FUN_011c99c8(auStack_d8);
  }
  return (ulong)param_3 & 0xffffffff;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_0090b5a0 @ 0090b5a0
// calls FUN_009b3d20 @ 009b3d20
// calls FUN_011c99c8 @ 011c99c8
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_01ba19c4 @ 01ba19c4
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_008cee58 @ 008cee58
// calls FUN_011cdfdc @ 011cdfdc
// calls FUN_011cdfc4 @ 011cdfc4
// calls FUN_01254e20 @ 01254e20
// nativeEnrollEmptyMutableDict (JLjava/lang/String;II)Z -> 011c9f54

/* === nativeEnrollEmptyMutableDict (JLjava/lang/String;II)Z | JNI_nativeEnrollEmptyMutableDict @ 011c9f54 size=264 === */

uint JNI_nativeEnrollEmptyMutableDict
               (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 auStack_100 [2];
  uint uStack_f0;
  undefined4 uStack_e8;
  undefined1 auStack_d0 [112];
  ulong uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  ulong auStack_48 [3];
  
  uVar1 = 0;
  if (param_3 != (long *)0x0) {
    auStack_48[0] = 0;
    auStack_48[1] = 0;
    auStack_48[2] = 0;
    FUN_011ce9e0(param_1,param_4,auStack_48);
    auStack_100[0] = 0;
    FUN_01254e58(auStack_d0,param_5,auStack_100);
    FUN_0129b258(auStack_100);
    FUN_01ba19c4(auStack_100,0);
    uStack_f0 = uStack_f0 | 1;
    uStack_e8 = param_6;
    FUN_009b3d20(&uStack_118,auStack_100);
    if ((uStack_60 & 1) != 0) {
      FUN_008cee58(uStack_50,uStack_60 & 0xfffffffffffffffe);
    }
    uStack_58 = uStack_110;
    uStack_60 = uStack_118;
    uStack_50 = uStack_108;
    uVar1 = (**(code **)(*param_3 + 0x10))(param_3,auStack_48,auStack_d0);
    uVar1 = uVar1 & 1;
    FUN_0090b5a0(auStack_100);
    FUN_011c99c8(auStack_d0);
    if ((auStack_48[0] & 1) != 0) {
      FUN_008cee58(auStack_48[2],auStack_48[0] & 0xfffffffffffffffe);
    }
  }
  return uVar1;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_01254e58 @ 01254e58
// calls FUN_0090b5a0 @ 0090b5a0
// calls FUN_009b3d20 @ 009b3d20
// calls FUN_011c99c8 @ 011c99c8
// calls FUN_01ba19c4 @ 01ba19c4
// calls FUN_008cee58 @ 008cee58
// calls FUN_0129b258 @ 0129b258
// nativeInstallDataInStorage (J[B)Z -> 011ca05c

/* === nativeInstallDataInStorage (J[B)Z | JNI_nativeInstallDataInStorage @ 011ca05c size=212 === */

uint JNI_nativeInstallDataInStorage
               (long *param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long extraout_x8;
  long extraout_x8_00;
  undefined1 auVar4 [16];
  byte bStack_50;
  undefined7 uStack_4f;
  undefined8 uStack_40;
  undefined1 uStack_31;
  
  if (param_3 == (long *)0x0) {
    uVar2 = 0;
  }
  else {
    lVar3 = (**(code **)(*param_1 + 0x6f0))(param_1,param_4,&uStack_31);
    FUN_00b07fdc(*param_1);
    iVar1 = (**(code **)(extraout_x8 + 0x558))();
    uVar2 = 0;
    if ((lVar3 != 0) && (iVar1 != 0)) {
      FUN_00905438(&bStack_50,lVar3,(long)iVar1);
      uVar2 = (**(code **)(*param_3 + 0x20))(param_3,&bStack_50);
      uVar2 = uVar2 & 1;
      auVar4 = FUN_00b07fdc(*param_1);
      (**(code **)(extraout_x8_00 + 0x6f8))(auVar4._0_8_,auVar4._8_8_,lVar3,0);
      if ((bStack_50 & 1) != 0) {
        FUN_008cee58(uStack_40,CONCAT71(uStack_4f,bStack_50) & 0xfffffffffffffffe);
      }
    }
  }
  return uVar2;
}


// calls FUN_00905438 @ 00905438
// calls FUN_00b07fdc @ 00b07fdc
// calls FUN_008cee58 @ 008cee58
// nativeGetTokenCategoryFromDataId (JLjava/lang/String;)I -> 011ca130

/* === nativeGetTokenCategoryFromDataId (JLjava/lang/String;)I | JNI_nativeGetTokenCategoryFromDataId @ 011ca130 size=92 === */

undefined4 JNI_nativeGetTokenCategoryFromDataId(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  byte bStack_28;
  undefined7 uStack_27;
  undefined8 uStack_18;
  
  uVar1 = 0;
  if (param_3 != 0) {
    FUN_011cdfac();
    FUN_011cdf18();
    FUN_011ce9e0();
    uVar1 = FUN_01297f20(&bStack_28,param_3);
    if ((bStack_28 & 1) != 0) {
      FUN_008cee58(uStack_18,CONCAT71(uStack_27,bStack_28) & 0xfffffffffffffffe);
    }
  }
  return uVar1;
}


// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_01297f20 @ 01297f20
// calls FUN_011cdfac @ 011cdfac
// calls FUN_008cee58 @ 008cee58
// nativeLoadBuiltInSettingScheme (JLjava/lang/String;Ljava/lang/String;)[B -> 011ca18c

/* === nativeLoadBuiltInSettingScheme (JLjava/lang/String;Ljava/lang/String;)[B | JNI_nativeLoadBuiltInSettingScheme @ 011ca18c size=236 === */

long JNI_nativeLoadBuiltInSettingScheme
               (long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long lVar1;
  long lVar2;
  ulong uStack_58;
  ulong auStack_50 [6];
  
  auStack_50[3] = 0;
  auStack_50[4] = 0;
  auStack_50[5] = 0;
  FUN_011ce9e0(param_1,param_4,auStack_50 + 3);
  auStack_50[0] = 0;
  auStack_50[1] = 0;
  auStack_50[2] = 0;
  FUN_011ce9e0(param_1,param_5,auStack_50);
  uStack_58 = 0;
  lVar1 = FUN_011ceb90(auStack_50,auStack_50 + 3,&uStack_58);
  lVar2 = 0;
  if (((lVar1 != 0) && (uStack_58 != 0)) &&
     (lVar2 = (**(code **)(*param_1 + 0x580))(param_1), lVar2 != 0)) {
    (**(code **)(*param_1 + 0x680))(param_1,lVar2,0,uStack_58 & 0xffffffff,lVar1);
  }
  if ((auStack_50[0] & 1) != 0) {
    FUN_008cee58(auStack_50[2],auStack_50[0] & 0xfffffffffffffffe);
  }
  if ((auStack_50[3] & 1) != 0) {
    FUN_008cee58(auStack_50[5],auStack_50[3] & 0xfffffffffffffffe);
  }
  return lVar2;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011ceb90 @ 011ceb90
// calls FUN_008cee58 @ 008cee58
// nativeEnrollSettingScheme (JLjava/lang/String;Ljava/lang/String;[B)Z -> 011ca278

/* === nativeEnrollSettingScheme (JLjava/lang/String;Ljava/lang/String;[B)Z | JNI_nativeEnrollSettingScheme @ 011ca278 size=316 === */

uint JNI_nativeEnrollSettingScheme
               (undefined8 *param_1,undefined8 param_2,long *param_3,undefined8 param_4,
               undefined8 param_5)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  undefined1 auVar4 [16];
  byte bStack_80;
  undefined7 uStack_7f;
  undefined8 uStack_70;
  undefined1 uStack_61;
  byte bStack_60;
  undefined7 uStack_5f;
  undefined8 uStack_50;
  ulong auStack_48 [3];
  
  if (param_3 == (long *)0x0) {
    uVar2 = 0;
  }
  else {
    auStack_48[0] = 0;
    auStack_48[1] = 0;
    auStack_48[2] = 0;
    FUN_011cdfb8(param_1,param_4,auStack_48);
    FUN_011ce9e0();
    auVar4 = FUN_011ce9e0(param_1,param_5,&bStack_60);
    FUN_00b07fdc(*param_1,auVar4._0_8_,auVar4._8_8_,&uStack_61);
    lVar3 = (**(code **)(extraout_x8 + 0x6f0))();
    FUN_00b07fdc(*param_1);
    iVar1 = (**(code **)(extraout_x8_00 + 0x558))();
    uVar2 = 0;
    if ((lVar3 != 0) && (iVar1 != 0)) {
      FUN_00905438(&bStack_80,lVar3,(long)iVar1);
      uVar2 = (**(code **)(*param_3 + 0x18))(param_3,auStack_48,&bStack_60,&bStack_80);
      uVar2 = uVar2 & 1;
      auVar4 = FUN_00b07fdc(*param_1);
      (**(code **)(extraout_x8_01 + 0x6f8))(auVar4._0_8_,auVar4._8_8_,lVar3,0);
      if ((bStack_80 & 1) != 0) {
        FUN_008cee58(uStack_70,CONCAT71(uStack_7f,bStack_80) & 0xfffffffffffffffe);
      }
    }
    if ((bStack_60 & 1) != 0) {
      FUN_008cee58(uStack_50,CONCAT71(uStack_5f,bStack_60) & 0xfffffffffffffffe);
    }
    if ((auStack_48[0] & 1) != 0) {
      FUN_008cee58(auStack_48[2],auStack_48[0] & 0xfffffffffffffffe);
    }
  }
  return uVar2;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_00905438 @ 00905438
// calls FUN_011cdfb8 @ 011cdfb8
// calls FUN_00b07fdc @ 00b07fdc
// calls FUN_008cee58 @ 008cee58
// nativeClose (J)V -> 00b0cf20
// nativeRefreshData (J)V -> 011ca3b4

/* === nativeRefreshData (J)V | JNI_nativeRefreshData @ 011ca3b4 size=28 === */

void JNI_nativeRefreshData(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x011ca3c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 0x10))(param_3);
  return;
}


// nativeResetUserId (JLjava/lang/String;)V -> 011ca3d0

/* === nativeResetUserId (JLjava/lang/String;)V | JNI_nativeResetUserId @ 011ca3d0 size=88 === */

void JNI_nativeResetUserId(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  byte bStack_28;
  undefined7 uStack_27;
  undefined8 uStack_18;
  
  if (param_3 != 0) {
    FUN_011cdfac();
    FUN_011cdf18();
    FUN_011ce9e0();
    FUN_011cdf08();
    (**(code **)(extraout_x8 + 0x18))();
    if ((bStack_28 & 1) != 0) {
      FUN_008cee58(uStack_18,CONCAT71(uStack_27,bStack_28) & 0xfffffffffffffffe);
    }
  }
  return;
}


// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdfac @ 011cdfac
// calls FUN_011cdf08 @ 011cdf08
// calls FUN_008cee58 @ 008cee58
// nativeBeginSession (J[B)V -> 011ca588

/* === nativeBeginSession (J[B)V | JNI_nativeBeginSession @ 011ca588 size=184 === */

void JNI_nativeBeginSession(undefined8 *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  long extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  long extraout_x8_02;
  undefined8 *unaff_x21;
  undefined1 auVar4 [16];
  undefined8 uStack_58;
  undefined *puStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined1 uStack_31;
  
  if (param_3 != 0) {
    FUN_011cdf34(*param_1,param_1,param_4,&uStack_31);
    lVar2 = (**(code **)(extraout_x8 + 0x6f0))();
    if (lVar2 != 0) {
      FUN_00bc2770(*unaff_x21);
      uVar1 = (**(code **)(extraout_x8_00 + 0x558))();
      uStack_48 = 0;
      uStack_40 = 0;
      uStack_58 = 0;
      puStack_50 = PTR_DAT_02231298;
      uVar3 = FUN_01cde8f0(&uStack_58,lVar2,uVar1);
      auVar4 = FUN_00bc2770(*unaff_x21);
      (**(code **)(extraout_x8_01 + 0x6f8))(auVar4._0_8_,auVar4._8_8_,lVar2,0);
      if ((uVar3 & 1) != 0) {
        FUN_011cdf08();
        (**(code **)(extraout_x8_02 + 0x30))();
      }
      FUN_0090b5a0(&uStack_58);
    }
    FUN_00ba57d8();
  }
  return;
}


// calls FUN_0090b5a0 @ 0090b5a0
// calls FUN_01cde8f0 @ 01cde8f0
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf08 @ 011cdf08
// calls FUN_00ba57d8 @ 00ba57d8
// nativeGetAllPendingMetrics ()[B -> 011ca428

/* === nativeGetAllPendingMetrics ()[B | JNI_nativeGetAllPendingMetrics @ 011ca428 size=80 === */

undefined8 JNI_nativeGetAllPendingMetrics(void)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 auStack_38 [40];
  
  lVar1 = FUN_00999b10();
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    FUN_009a2994(auStack_38);
    FUN_00c3b4f0();
    uVar2 = FUN_011ca478();
    FUN_00afaa0c(auStack_38);
  }
  return uVar2;
}


// calls FUN_009a2994 @ 009a2994
// calls FUN_00c3b4f0 @ 00c3b4f0
// calls FUN_00afaa0c @ 00afaa0c
// calls FUN_011ca478 @ 011ca478
// calls FUN_00999b10 @ 00999b10
// nativeHandleInputContext (J[B)V -> 011ca640

/* === nativeHandleInputContext (J[B)V | JNI_nativeHandleInputContext @ 011ca640 size=192 === */

void JNI_nativeHandleInputContext
               (undefined8 *param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  long extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  undefined8 *unaff_x21;
  undefined1 auVar4 [16];
  undefined1 auStack_60 [47];
  undefined1 uStack_31;
  
  if (param_3 != (long *)0x0) {
    FUN_011cdf34(*param_1,param_1,param_4,&uStack_31);
    lVar2 = (**(code **)(extraout_x8 + 0x6f0))();
    if (lVar2 != 0) {
      FUN_00bc2770(*unaff_x21);
      uVar1 = (**(code **)(extraout_x8_00 + 0x558))();
      FUN_0129a0b4(auStack_60,0);
      uVar3 = FUN_01cde8f0(auStack_60,lVar2,uVar1);
      auVar4 = FUN_00bc2770(*unaff_x21);
      (**(code **)(extraout_x8_01 + 0x6f8))(auVar4._0_8_,auVar4._8_8_,lVar2,0);
      if ((uVar3 & 1) != 0) {
        (**(code **)(*param_3 + 0x20))(param_3,auStack_60);
      }
      FUN_00b01314(auStack_60);
    }
    FUN_00ba57d8();
  }
  return;
}


// calls FUN_01cde8f0 @ 01cde8f0
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_00b01314 @ 00b01314
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_0129a0b4 @ 0129a0b4
// calls FUN_00ba57d8 @ 00ba57d8
// nativeFinishSession (J[B)V -> 011ca700

/* === nativeFinishSession (J[B)V | JNI_nativeFinishSession @ 011ca700 size=184 === */

void JNI_nativeFinishSession(undefined8 *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  long extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  long extraout_x8_02;
  undefined8 *unaff_x21;
  undefined1 auVar4 [16];
  undefined8 uStack_58;
  undefined *puStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined1 uStack_31;
  
  if (param_3 != 0) {
    FUN_011cdf34(*param_1,param_1,param_4,&uStack_31);
    lVar2 = (**(code **)(extraout_x8 + 0x6f0))();
    if (lVar2 != 0) {
      FUN_00bc2770(*unaff_x21);
      uVar1 = (**(code **)(extraout_x8_00 + 0x558))();
      uStack_48 = 0;
      uStack_40 = 0;
      uStack_58 = 0;
      puStack_50 = PTR_DAT_022312a0;
      uVar3 = FUN_01cde8f0(&uStack_58,lVar2,uVar1);
      auVar4 = FUN_00bc2770(*unaff_x21);
      (**(code **)(extraout_x8_01 + 0x6f8))(auVar4._0_8_,auVar4._8_8_,lVar2,0);
      if ((uVar3 & 1) != 0) {
        FUN_011cdf08();
        (**(code **)(extraout_x8_02 + 0x28))();
      }
      FUN_0090b5a0(&uStack_58);
    }
    FUN_00ba57d8();
  }
  return;
}


// calls FUN_0090b5a0 @ 0090b5a0
// calls FUN_01cde8f0 @ 01cde8f0
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf08 @ 011cdf08
// calls FUN_00ba57d8 @ 00ba57d8
// nativeAppend (J[Lcom/google/android/apps/inputmethod/libs/hmm/ScoredInput;I)I -> 011ca7b8

/* === nativeAppend (J[Lcom/google/android/apps/inputmethod/libs/hmm/ScoredInput;I)I | JNI_nativeAppend @ 011ca7b8 size=180 === */

undefined4
JNI_nativeAppend(undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4,
                undefined4 param_5)

{
  byte *pbVar1;
  undefined4 uVar2;
  byte *pbVar3;
  byte *pbStack_40;
  byte *pbStack_38;
  long lStack_30;
  undefined8 uStack_28;
  
  if (param_3 == (long *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uStack_28 = param_4;
    FUN_011cdfd0(param_1,&uStack_28,&pbStack_40);
    FUN_011ca86c();
    uVar2 = (**(code **)(*param_3 + 0x38))(param_3,&pbStack_40,param_5);
    pbVar1 = pbStack_40;
    if (pbStack_40 != (byte *)0x0) {
      while (pbVar3 = pbStack_38, pbVar3 != pbVar1) {
        pbStack_38 = pbVar3 + -0x20;
        if ((*pbStack_38 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(pbVar3 + -0x10),
                       *(ulong *)(pbVar3 + -0x20) & 0xfffffffffffffffe);
        }
      }
      pbStack_38 = pbVar1;
      FUN_008cee58(pbStack_40,lStack_30 - (long)pbStack_40);
    }
  }
  return uVar2;
}


// calls FUN_011cdfd0 @ 011cdfd0
// calls FUN_011ca86c @ 011ca86c
// calls FUN_008cee58 @ 008cee58
// nativeAddInputEdge (JIILcom/google/android/apps/inputmethod/libs/hmm/ScoredInput;I)I -> 011cab0c

/* === nativeAddInputEdge (JIILcom/google/android/apps/inputmethod/libs/hmm/ScoredInput;I)I | JNI_nativeAddInputEdge @ 011cab0c size=232 === */

void JNI_nativeAddInputEdge
               (long *param_1,undefined8 param_2,long *param_3,undefined4 param_4,undefined4 param_5
               ,undefined8 param_6,undefined4 param_7)

{
  long lVar1;
  undefined4 uVar2;
  ulong auStack_60 [3];
  undefined8 uStack_48;
  
  if (param_3 == (long *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    auStack_60[1] = 0;
    auStack_60[0] = 0;
    uStack_48 = 0;
    auStack_60[2] = 0;
    lVar1 = (**(code **)(*param_1 + 0x2f8))(param_1,param_6,DAT_022a33f8);
    if (lVar1 != 0) {
      FUN_011ce9e0(param_1,lVar1,auStack_60);
      uVar2 = (**(code **)(*param_1 + 0x330))(param_1,param_6,DAT_022a3400);
      uStack_48 = CONCAT44(uVar2,uVar2);
    }
    uVar2 = (**(code **)(*param_3 + 0x58))(param_3,param_4,param_5,auStack_60,param_7);
    if ((auStack_60[0] & 1) != 0) {
      FUN_008cee58(auStack_60[2],auStack_60[0] & 0xfffffffffffffffe);
    }
  }
  FUN_00ba57d8(uVar2);
  return;
}


// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_008cee58 @ 008cee58
// calls FUN_00ba57d8 @ 00ba57d8
// nativeBulkInputTouchData (J[BLcom/google/android/apps/inputmethod/libs/hmm/Range;)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 0098a43c

/* === nativeBulkInputTouchData (J[BLcom/google/android/apps/inputmethod/libs/hmm/Range;)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | thunk_FUN_00ba5604 @ 0098a43c size=8 === */

void thunk_FUN_00ba5604(void)

{
  FUN_00ba5604();
  return;
}


// calls FUN_00ba5604 @ 00ba5604
// nativeSetKeyboardLayout (J[B)Z -> 00bab30c

/* === nativeSetKeyboardLayout (J[B)Z | thunk_FUN_00b3477c @ 00bab30c size=8 === */

void thunk_FUN_00b3477c(void)

{
  FUN_00b3477c();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// nativeBulkInputWithNativePointer (JJLcom/google/android/apps/inputmethod/libs/hmm/Range;)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 011cabf4

/* === nativeBulkInputWithNativePointer (JJLcom/google/android/apps/inputmethod/libs/hmm/Range;)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | JNI_nativeBulkInputWithNativePointer @ 011cabf4 size=232 === */

undefined8
JNI_nativeBulkInputWithNativePointer
          (long *param_1,undefined8 param_2,long *param_3,ulong param_4,undefined8 param_5)

{
  ulong uVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uStack_38;
  
  if (param_4 == 0) {
    uVar3 = 0;
  }
  else {
    if (param_3 == (long *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar1 = (**(code **)(*param_1 + 800))(param_1,param_5,DAT_022a3440);
      lVar2 = (**(code **)(*param_1 + 800))(param_1,param_5,DAT_022a3448);
      uStack_38 = uVar1 & 0xffffffff | lVar2 << 0x20;
      uVar1 = (**(code **)(*param_3 + 0x48))(param_3,param_4,&uStack_38);
      uVar3 = FUN_011cda44(param_1,DAT_022a3410,DAT_022a3430,uVar1,uVar1 >> 0x20);
    }
    uStack_38 = param_4;
    FUN_011cdd08(&uStack_38);
    FUN_008cee58(param_4,0x18);
  }
  return uVar3;
}


// calls FUN_011cdd08 @ 011cdd08
// calls FUN_011cda44 @ 011cda44
// calls FUN_008cee58 @ 008cee58
// nativeBulkInputWithHandwritingLatticeNativePointer (JJLcom/google/android/apps/inputmethod/libs/hmm/Range;[I)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 011cacdc

/* === nativeBulkInputWithHandwritingLatticeNativePointer (JJLcom/google/android/apps/inputmethod/libs/hmm/Range;[I)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | JNI_nativeBulkInputWithHandwritingLatticeNativePointer @ 011cacdc size=552 === */

undefined8
JNI_nativeBulkInputWithHandwritingLatticeNativePointer
          (long *param_1,undefined8 param_2,long param_3,long param_4,undefined8 param_5,
          undefined8 param_6)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  long extraout_x8;
  ulong uVar5;
  long extraout_x8_00;
  long lVar6;
  undefined8 uVar7;
  long *aplStack_78 [2];
  long lStack_68;
  long lStack_60;
  undefined8 uStack_58;
  long lStack_48;
  
  uVar7 = 0;
  if ((param_3 != 0) && (param_4 != 0)) {
    lStack_68 = 0;
    lStack_60 = 0;
    uStack_58 = 0;
    uVar2 = (**(code **)(*param_1 + 800))(param_1,param_5,DAT_022a3440);
    lVar3 = (**(code **)(*param_1 + 800))(param_1,param_5,DAT_022a3448);
    uVar2 = FUN_011c8d70(param_3,param_4,uVar2 & 0xffffffff | lVar3 << 0x20,&lStack_68);
    if (lStack_68 != lStack_60) {
      uVar7 = FUN_00b0e014();
      lVar3 = (**(code **)(extraout_x8 + 0x6f0))(uVar7,param_6,0);
      uVar1 = (**(code **)(*param_1 + 0x558))(param_1,param_6);
      uVar5 = lStack_60 - lStack_68;
      if ((ulong)(long)(int)uVar1 < (ulong)((long)uVar5 >> 2)) {
        FUN_0098afe4(aplStack_78,"i18n/input/engine/hmm/android/jni/hmm_decoder.cc",0x3b6,0);
        FUN_008ebd60(aplStack_78,"segmentation size should not be greater than length, ",0x35);
        FUN_008ebd60(aplStack_78,"len = ",6);
        lStack_48 = CONCAT44(lStack_48._4_4_,uVar1);
        uVar7 = FUN_008e90a8(aplStack_78,&lStack_48);
        FUN_008ebd60(uVar7,"segmentation size = ",0x14);
        lStack_48 = lStack_60 - lStack_68 >> 2;
        FUN_009ccd4c(uVar7,&lStack_48);
        FUN_008ebe80();
        FUN_008e905c(aplStack_78);
        uVar5 = lStack_60 - lStack_68;
      }
      lVar6 = 0;
      uVar4 = (uint)(uVar5 >> 2);
      if ((int)uVar4 <= (int)uVar1) {
        uVar1 = uVar4;
      }
      for (; (ulong)(uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU)) * 4 != lVar6; lVar6 = lVar6 + 4) {
        *(undefined4 *)(lVar3 + lVar6) = *(undefined4 *)(lStack_68 + lVar6);
      }
      uVar7 = FUN_00b0e014();
      (**(code **)(extraout_x8_00 + 0x6f8))(uVar7,param_6,lVar3,0);
    }
    uVar7 = FUN_011cda44(param_1,DAT_022a3410,DAT_022a3430,uVar2 & 0xffffffff,uVar2 >> 0x20);
    aplStack_78[0] = &lStack_68;
    FUN_008e34e8(aplStack_78);
  }
  return uVar7;
}


// calls FUN_00b0e014 @ 00b0e014
// calls FUN_008e905c @ 008e905c
// calls FUN_009ccd4c @ 009ccd4c
// calls FUN_0098afe4 @ 0098afe4
// calls FUN_008e90a8 @ 008e90a8
// calls FUN_011cda44 @ 011cda44
// calls FUN_008e34e8 @ 008e34e8
// calls FUN_008ebd60 @ 008ebd60
// calls FUN_008ebe80 @ 008ebe80
// calls FUN_011c8d70 @ 011c8d70
// nativeBulkInputWithTargetWords (J[Lcom/google/android/apps/inputmethod/libs/hmm/ScoredInput;Lcom/google/android/apps/inputmethod/libs/hmm/Range;)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 011caf04

/* === nativeBulkInputWithTargetWords (J[Lcom/google/android/apps/inputmethod/libs/hmm/ScoredInput;Lcom/google/android/apps/inputmethod/libs/hmm/Range;)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | JNI_nativeBulkInputWithTargetWords @ 011caf04 size=1144 === */

undefined8
JNI_nativeBulkInputWithTargetWords
          (long *param_1,undefined8 param_2,long *param_3,undefined8 param_4,undefined8 param_5)

{
  byte *pbVar1;
  undefined8 *puVar2;
  undefined8 ***pppuVar3;
  undefined8 ***pppuVar4;
  ulong uVar5;
  byte bVar6;
  undefined8 ***pppuVar7;
  byte *pbVar8;
  bool bVar9;
  ulong uVar10;
  long lVar11;
  undefined8 uVar12;
  uint uVar13;
  ulong extraout_x8;
  ulong extraout_x8_00;
  ulong extraout_x9;
  ulong extraout_x9_00;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  undefined8 *puVar17;
  long lVar18;
  undefined8 ***pppuStack_e0;
  undefined8 *puStack_d8;
  undefined8 *puStack_d0;
  byte *pbStack_c8;
  byte *pbStack_c0;
  long lStack_b8;
  undefined8 uStack_b0;
  byte *pbStack_a8;
  byte *pbStack_a0;
  byte *pbStack_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined8 ***pppuStack_88;
  undefined8 ***pppuStack_80;
  undefined8 ***pppuStack_78;
  undefined8 *puStack_70;
  undefined8 **ppuStack_68;
  
  lStack_b8 = 0;
  pbStack_c8 = (byte *)0x0;
  pbStack_c0 = (byte *)0x0;
  uStack_b0 = param_4;
  uVar10 = FUN_011ca86c(param_1,&uStack_b0,&pbStack_c8);
  if ((uVar10 & 1) == 0) {
    FUN_0098afe4(&pppuStack_88,"i18n/input/engine/hmm/android/jni/hmm_decoder.cc",0x3ca,0);
    FUN_008ebd60(&pppuStack_88,"Error converting scored input",0x1d);
    FUN_008ebe80(&pppuStack_88);
    FUN_008e905c(&pppuStack_88);
    uVar12 = 0;
  }
  else {
    pppuStack_e0 = (undefined8 ***)0x0;
    puStack_d8 = (undefined8 *)0x0;
    puStack_d0 = (undefined8 *)0x0;
    uVar13 = (uint)((ulong)((long)pbStack_c0 - (long)pbStack_c8) >> 5);
    for (uVar10 = 0; uVar10 != (uVar13 & ((int)uVar13 >> 0x1f ^ 0xffffffffU)); uVar10 = uVar10 + 1)
    {
      pbStack_a8 = (byte *)0x0;
      pbStack_a0 = (byte *)0x0;
      pbStack_98 = (byte *)0x0;
      pbVar15 = pbStack_c8 + uVar10 * 0x20;
      uStack_90 = *(undefined4 *)(pbVar15 + 0x18);
      uStack_8c = *(undefined4 *)(pbVar15 + 0x1c);
      pbVar14 = *(byte **)(pbVar15 + 0x10);
      if ((*pbVar15 & 1) == 0) {
        pbVar14 = pbVar15 + 1;
      }
      while( true ) {
        puVar2 = puStack_d8;
        if (*pbVar14 == 0) break;
        bVar6 = (&DAT_001b80c5)[*pbVar14 >> 4];
        FUN_00905438(&pppuStack_88,pbVar14,(ulong)bVar6);
        pbVar15 = pbStack_a0;
        bVar9 = pbStack_98 <= pbStack_a0;
        if (bVar9) {
          lVar18 = (long)pbStack_a0 - (long)pbStack_a8;
          if ((lVar18 >> 5) + 1U >> 0x3b != 0) {
                    /* WARNING: Subroutine does not return */
            FUN_00a83c50();
          }
          FUN_00fecad8((long)pbStack_98 - (long)pbStack_a8);
          uVar5 = extraout_x9;
          if (bVar9) {
            uVar5 = extraout_x8;
          }
          if (uVar5 == 0) {
            lVar11 = 0;
          }
          else {
            if (uVar5 >> 0x3b != 0) goto LAB_011cb374;
            lVar11 = FUN_020543f8(uVar5 << 5);
          }
          lVar18 = lVar11 + lVar18;
          pbVar16 = (byte *)(lVar11 + uVar5 * 0x20);
          pppuVar3 = pppuStack_80;
          pppuVar7 = pppuStack_78;
          if (((ulong)pppuStack_88 & 1) == 0) {
            pppuVar3 = (undefined8 ***)((ulong)pppuStack_88 >> 1 & 0x7f);
            pppuVar7 = (undefined8 ***)((ulong)&pppuStack_88 | 1);
          }
          pppuVar4 = (undefined8 ***)0x0;
          if (pppuVar7 != (undefined8 ***)0x0) {
            pppuVar4 = pppuVar3;
          }
          FUN_00905438(lVar18,pppuVar7,pppuVar4);
          pbVar15 = (byte *)(lVar18 + 0x20);
          *(undefined4 *)(lVar18 + 0x18) = 0x1a;
          pbVar1 = pbStack_a8 + (lVar18 - (long)pbStack_a0);
          FUN_0110f2f8(&pbStack_98,pbStack_a8,pbStack_a0,pbVar1);
          pbVar8 = pbStack_a8;
          if (pbStack_a8 != (byte *)0x0) {
            lVar18 = (long)pbStack_98 - (long)pbStack_a8;
            pbStack_a8 = pbVar1;
            pbStack_a0 = pbVar15;
            pbStack_98 = pbVar16;
            FUN_008cee58(pbVar8,lVar18);
            pbVar1 = pbStack_a8;
            pbVar16 = pbStack_98;
          }
        }
        else {
          pppuVar3 = pppuStack_80;
          pppuVar7 = pppuStack_78;
          if (((ulong)pppuStack_88 & 1) == 0) {
            pppuVar3 = (undefined8 ***)((ulong)pppuStack_88 >> 1 & 0x7f);
            pppuVar7 = (undefined8 ***)((ulong)&pppuStack_88 | 1);
          }
          pppuVar4 = (undefined8 ***)0x0;
          if (pppuVar7 != (undefined8 ***)0x0) {
            pppuVar4 = pppuVar3;
          }
          FUN_00905438(pbStack_a0,pppuVar7,pppuVar4);
          pbVar15[0x18] = 0x1a;
          pbVar15[0x19] = 0;
          pbVar15[0x1a] = 0;
          pbVar15[0x1b] = 0;
          pbVar15 = pbVar15 + 0x20;
          pbVar1 = pbStack_a8;
          pbVar16 = pbStack_98;
        }
        pbStack_98 = pbVar16;
        pbStack_a8 = pbVar1;
        pbStack_a0 = pbVar15;
        if (((ulong)pppuStack_88 & 1) != 0) {
          FUN_008cee58(pppuStack_78,(ulong)pppuStack_88 & 0xfffffffffffffffe);
        }
        pbVar14 = pbVar14 + bVar6;
      }
      bVar9 = puStack_d0 <= puStack_d8;
      if (bVar9) {
        lVar18 = (long)puStack_d8 - (long)pppuStack_e0;
        if ((lVar18 >> 5) + 1U >> 0x3b != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_00a83c50();
        }
        ppuStack_68 = &puStack_d0;
        FUN_00fecad8((long)puStack_d0 - (long)pppuStack_e0);
        uVar5 = extraout_x9_00;
        if (bVar9) {
          uVar5 = extraout_x8_00;
        }
        if (uVar5 >> 0x3b != 0) {
LAB_011cb374:
                    /* WARNING: Subroutine does not return */
          FUN_00ab02dc();
        }
        lVar11 = FUN_020543f8(uVar5 << 5);
        puVar2 = (undefined8 *)(lVar11 + lVar18);
        puVar2[1] = 0;
        puVar2[2] = 0;
        *puVar2 = 0;
        FUN_011cdab8(puVar2,pbStack_a8,pbStack_a0,(long)pbStack_a0 - (long)pbStack_a8 >> 5);
        puVar17 = puVar2 + 4;
        puVar2[3] = CONCAT44(uStack_8c,uStack_90);
        pppuVar3 = (undefined8 ***)((long)puVar2 + ((long)pppuStack_e0 - (long)puStack_d8));
        FUN_011cdc08(&puStack_d0,pppuStack_e0,puStack_d8,pppuVar3);
        pppuStack_78 = pppuStack_e0;
        puStack_70 = puStack_d0;
        pppuStack_88 = pppuStack_e0;
        pppuStack_80 = pppuStack_e0;
        pppuStack_e0 = pppuVar3;
        puStack_d8 = puVar17;
        puStack_d0 = (undefined8 *)(lVar11 + uVar5 * 0x20);
        FUN_011cdbc8(&pppuStack_88);
      }
      else {
        *puStack_d8 = 0;
        puStack_d8[1] = 0;
        puStack_d8[2] = 0;
        FUN_011cdab8(puStack_d8,pbStack_a8,pbStack_a0,(long)pbStack_a0 - (long)pbStack_a8 >> 5);
        puVar17 = puVar2 + 4;
        puVar2[3] = CONCAT44(uStack_8c,uStack_90);
      }
      pbVar15 = pbStack_a8;
      puStack_d8 = puVar17;
      if (pbStack_a8 != (byte *)0x0) {
        pbVar14 = pbStack_a0;
        while (pbVar16 = pbVar14, pbVar16 != pbVar15) {
          pbVar14 = pbVar16 + -0x20;
          if ((*pbVar14 & 1) != 0) {
            FUN_008cee58(*(undefined8 *)(pbVar16 + -0x10),
                         *(ulong *)(pbVar16 + -0x20) & 0xfffffffffffffffe);
          }
        }
        pbStack_a0 = pbVar15;
        FUN_008cee58(pbStack_a8,(long)pbStack_98 - (long)pbStack_a8);
      }
    }
    if (param_3 == (long *)0x0) {
      uVar12 = 0;
    }
    else {
      uVar10 = (**(code **)(*param_1 + 800))(param_1,param_5,DAT_022a3440);
      lVar18 = (**(code **)(*param_1 + 800))(param_1,param_5,DAT_022a3448);
      pppuStack_88 = (undefined8 ***)(uVar10 & 0xffffffff | lVar18 << 0x20);
      uVar10 = (**(code **)(*param_3 + 0x50))(param_3,&pppuStack_e0,&pppuStack_88);
      uVar12 = FUN_011cda44(param_1,DAT_022a3410,DAT_022a3430,uVar10,uVar10 >> 0x20);
    }
    pppuStack_88 = &pppuStack_e0;
    FUN_011cdd08(&pppuStack_88);
  }
  pbVar15 = pbStack_c8;
  if (pbStack_c8 != (byte *)0x0) {
    pbVar14 = pbStack_c0;
    while (pbVar16 = pbVar14, pbVar16 != pbVar15) {
      pbVar14 = pbVar16 + -0x20;
      if ((*pbVar14 & 1) != 0) {
        FUN_008cee58(*(undefined8 *)(pbVar16 + -0x10),
                     *(ulong *)(pbVar16 + -0x20) & 0xfffffffffffffffe);
      }
    }
    pbStack_c0 = pbVar15;
    FUN_008cee58(pbStack_c8,lStack_b8 - (long)pbStack_c8);
  }
  return uVar12;
}


// calls FUN_011cdd08 @ 011cdd08
// calls FUN_00905438 @ 00905438
// calls FUN_0098afe4 @ 0098afe4
// calls FUN_011cdc08 @ 011cdc08
// calls FUN_011cda44 @ 011cda44
// calls FUN_0110f2f8 @ 0110f2f8
// calls FUN_00a83c50 @ 00a83c50
// calls FUN_011ca86c @ 011ca86c
// calls FUN_008ebd60 @ 008ebd60
// calls FUN_008cee58 @ 008cee58
// calls FUN_00fecad8 @ 00fecad8
// calls FUN_00ab02dc @ 00ab02dc
// calls FUN_008e905c @ 008e905c
// calls FUN_011cdbc8 @ 011cdbc8
// calls FUN_011cdab8 @ 011cdab8
// calls FUN_008ebe80 @ 008ebe80
// calls FUN_020543f8 @ 020543f8
// nativeSetSeparator (JII)Z -> 011cb37c

/* === nativeSetSeparator (JII)Z | JNI_nativeSetSeparator @ 011cb37c size=52 === */

ulong JNI_nativeSetSeparator
                (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,
                undefined4 param_5)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  undefined1 auVar3 [16];
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  auVar3 = FUN_011cdf74();
  uVar1 = (**(code **)(extraout_x8 + 0x78))(auVar3._0_8_,auVar3._8_8_,param_5);
  return (ulong)(uVar1 & 1);
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeGetSeparator (JI)I -> 011cb3b0

/* === nativeGetSeparator (JI)I | JNI_nativeGetSeparator @ 011cb3b0 size=32 === */

void JNI_nativeGetSeparator(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf74();
                    /* WARNING: Could not recover jumptable at 0x011cb3c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x80))();
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeDelete (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z -> 011cb3d0

/* === nativeDelete (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z | JNI_nativeDelete @ 011cb3d0 size=116 === */

void JNI_nativeDelete(long *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 extraout_x1;
  code *extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  undefined8 *unaff_x21;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf34(*(undefined8 *)(*param_1 + 800),(int)param_1,param_4,DAT_022a3440);
  uVar1 = (*extraout_x8)();
  FUN_00bc2770(*unaff_x21,uVar1,extraout_x1,DAT_022a3448);
  (**(code **)(extraout_x8_00 + 800))();
  FUN_011cdeb0();
  (**(code **)(extraout_x8_01 + 0x88))();
  FUN_011cdf24();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_011cdeb0 @ 011cdeb0
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf24 @ 011cdf24
// nativeSelectRange (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z -> 011cb444

/* === nativeSelectRange (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z | JNI_nativeSelectRange @ 011cb444 size=116 === */

void JNI_nativeSelectRange(long *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 extraout_x1;
  code *extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  undefined8 *unaff_x21;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf34(*(undefined8 *)(*param_1 + 800),(int)param_1,param_4,DAT_022a3440);
  uVar1 = (*extraout_x8)();
  FUN_00bc2770(*unaff_x21,uVar1,extraout_x1,DAT_022a3448);
  (**(code **)(extraout_x8_00 + 800))();
  FUN_011cdeb0();
  (**(code **)(extraout_x8_01 + 0x90))();
  FUN_011cdf24();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_011cdeb0 @ 011cdeb0
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf24 @ 011cdf24
// nativeReset (J)V -> 011cb4b8

/* === nativeReset (J)V | JNI_nativeReset @ 011cb4b8 size=28 === */

void JNI_nativeReset(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x011cb4cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 0xa0))(param_3);
  return;
}


// nativeGetDecodingRange (J)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 011cb4d4

/* === nativeGetDecodingRange (J)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | JNI_nativeGetDecodingRange @ 011cb4d4 size=48 === */

void JNI_nativeGetDecodingRange(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  FUN_011cdee0();
  (**(code **)(extraout_x8 + 0xb8))();
  FUN_011cde90();
  FUN_011cda44();
  return;
}


// calls FUN_011cda44 @ 011cda44
// calls FUN_011cde90 @ 011cde90
// calls FUN_011cdee0 @ 011cdee0
// calls FUN_00ba5604 @ 00ba5604
// nativeGetConvertedSegmentsRange (J)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 011cb504

/* === nativeGetConvertedSegmentsRange (J)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | JNI_nativeGetConvertedSegmentsRange @ 011cb504 size=48 === */

void JNI_nativeGetConvertedSegmentsRange(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  FUN_011cdee0();
  (**(code **)(extraout_x8 + 0xc0))();
  FUN_011cde90();
  FUN_011cda44();
  return;
}


// calls FUN_011cda44 @ 011cda44
// calls FUN_011cde90 @ 011cde90
// calls FUN_011cdee0 @ 011cdee0
// calls FUN_00ba5604 @ 00ba5604
// nativeGetSegmentCount (J)I -> 011cb534

/* === nativeGetSegmentCount (J)I | JNI_nativeGetSegmentCount @ 011cb534 size=28 === */

void JNI_nativeGetSegmentCount(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    FUN_00b3477c();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x011cb548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 200))(param_3);
  return;
}


// calls FUN_00b3477c @ 00b3477c
// nativeGetSegment (JI)J -> 011cb550

/* === nativeGetSegment (JI)J | JNI_nativeGetSegment @ 011cb550 size=44 === */

void JNI_nativeGetSegment(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  FUN_011cdf74();
  (**(code **)(extraout_x8 + 0xd0))();
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00ba5604 @ 00ba5604
// nativeIsSegmentConverted (JJ)Z -> 011cb57c

/* === nativeIsSegmentConverted (JJ)Z | JNI_nativeIsSegmentConverted @ 011cb57c size=48 === */

ulong JNI_nativeIsSegmentConverted(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf40();
  uVar1 = (**(code **)(extraout_x8 + 0xd8))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeIsSegmentConvertible (JJ)Z -> 011cb5ac

/* === nativeIsSegmentConvertible (JJ)Z | JNI_nativeIsSegmentConvertible @ 011cb5ac size=48 === */

ulong JNI_nativeIsSegmentConvertible(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf40();
  uVar1 = (**(code **)(extraout_x8 + 0xe0))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeIsSegmentTargeted (JJ)Z -> 011cb5dc

/* === nativeIsSegmentTargeted (JJ)Z | JNI_nativeIsSegmentTargeted @ 011cb5dc size=48 === */

ulong JNI_nativeIsSegmentTargeted(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf40();
  uVar1 = (**(code **)(extraout_x8 + 0xe8))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeIsSegmentTokenFullyMatched (JJ)Z -> 011cb60c

/* === nativeIsSegmentTokenFullyMatched (JJ)Z | JNI_nativeIsSegmentTokenFullyMatched @ 011cb60c size=48 === */

ulong JNI_nativeIsSegmentTokenFullyMatched(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf40();
  uVar1 = (**(code **)(extraout_x8 + 0xf0))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeGetSegmentRange (JJ)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 011cb63c

/* === nativeGetSegmentRange (JJ)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | JNI_nativeGetSegmentRange @ 011cb63c size=48 === */

void JNI_nativeGetSegmentRange(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  FUN_011cdecc();
  (**(code **)(extraout_x8 + 0xf8))();
  FUN_011cde90();
  FUN_011cda44();
  return;
}


// calls FUN_011cda44 @ 011cda44
// calls FUN_011cde90 @ 011cde90
// calls FUN_011cdecc @ 011cdecc
// calls FUN_00ba5604 @ 00ba5604
// nativeGetSegmentConvertedString (JJ)Ljava/lang/String; -> 011cb66c

/* === nativeGetSegmentConvertedString (JJ)Ljava/lang/String; | JNI_nativeGetSegmentConvertedString @ 011cb66c size=92 === */

undefined8 JNI_nativeGetSegmentConvertedString(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  ulong extraout_x8_00;
  undefined8 unaff_x19;
  ulong auStack_28 [2];
  undefined8 uStack_18;
  
  if (param_3 == 0) {
    unaff_x19 = 0;
  }
  else {
    FUN_011cdecc();
    (**(code **)(extraout_x8 + 0x100))(auStack_28);
    FUN_00c3b4f0();
    FUN_011ce908();
    FUN_011c1500();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,auStack_28[0] & 0xfffffffffffffffe);
    }
  }
  return unaff_x19;
}


// calls FUN_011ce908 @ 011ce908
// calls FUN_011c1500 @ 011c1500
// calls FUN_00c3b4f0 @ 00c3b4f0
// calls FUN_011cdecc @ 011cdecc
// calls FUN_008cee58 @ 008cee58
// nativeGetSegmentTokenCount (JJ)I -> 011cb6c8

/* === nativeGetSegmentTokenCount (JJ)I | JNI_nativeGetSegmentTokenCount @ 011cb6c8 size=32 === */

void JNI_nativeGetSegmentTokenCount(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf40();
                    /* WARNING: Could not recover jumptable at 0x011cb6e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x108))();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeGetSegmentToken (JJI)J -> 011cb6e8

/* === nativeGetSegmentToken (JJI)J | JNI_nativeGetSegmentToken @ 011cb6e8 size=48 === */

void JNI_nativeGetSegmentToken
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,
               undefined4 param_5)

{
  long extraout_x8;
  undefined1 auVar1 [16];
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  auVar1 = FUN_011cdf40();
  (**(code **)(extraout_x8 + 0x110))(auVar1._0_8_,auVar1._8_8_,param_5);
  return;
}


// calls FUN_011cdf40 @ 011cdf40
// calls FUN_00ba5604 @ 00ba5604
// nativeIsTokenSelected (JJ)Z -> 011cb718

/* === nativeIsTokenSelected (JJ)Z | JNI_nativeIsTokenSelected @ 011cb718 size=48 === */

ulong JNI_nativeIsTokenSelected(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf40();
  uVar1 = (**(code **)(extraout_x8 + 0x118))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeGetTokenRange (JJ)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 011cb748

/* === nativeGetTokenRange (JJ)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | JNI_nativeGetTokenRange @ 011cb748 size=48 === */

void JNI_nativeGetTokenRange(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  FUN_011cdecc();
  (**(code **)(extraout_x8 + 0x120))();
  FUN_011cde90();
  FUN_011cda44();
  return;
}


// calls FUN_011cda44 @ 011cda44
// calls FUN_011cde90 @ 011cde90
// calls FUN_011cdecc @ 011cdecc
// calls FUN_00ba5604 @ 00ba5604
// nativeGetTokenString (JJ)Ljava/lang/String; -> 011cb778

/* === nativeGetTokenString (JJ)Ljava/lang/String; | JNI_nativeGetTokenString @ 011cb778 size=92 === */

undefined8 JNI_nativeGetTokenString(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  ulong extraout_x8_00;
  undefined8 unaff_x19;
  ulong auStack_28 [2];
  undefined8 uStack_18;
  
  if (param_3 == 0) {
    unaff_x19 = 0;
  }
  else {
    FUN_011cdecc();
    (**(code **)(extraout_x8 + 0x128))(auStack_28);
    FUN_00c3b4f0();
    FUN_011ce908();
    FUN_011c1500();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,auStack_28[0] & 0xfffffffffffffffe);
    }
  }
  return unaff_x19;
}


// calls FUN_011ce908 @ 011ce908
// calls FUN_011c1500 @ 011c1500
// calls FUN_00c3b4f0 @ 00c3b4f0
// calls FUN_011cdecc @ 011cdecc
// calls FUN_008cee58 @ 008cee58
// nativeGetTokenInputType (JJ)I -> 011cb7d4

/* === nativeGetTokenInputType (JJ)I | JNI_nativeGetTokenInputType @ 011cb7d4 size=32 === */

void JNI_nativeGetTokenInputType(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf40();
                    /* WARNING: Could not recover jumptable at 0x011cb7ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x130))();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeGetTokenConfidentString (JJ)Ljava/lang/String; -> 011cb7f4

/* === nativeGetTokenConfidentString (JJ)Ljava/lang/String; | JNI_nativeGetTokenConfidentString @ 011cb7f4 size=92 === */

undefined8 JNI_nativeGetTokenConfidentString(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  ulong extraout_x8_00;
  undefined8 unaff_x19;
  ulong auStack_28 [2];
  undefined8 uStack_18;
  
  if (param_3 == 0) {
    unaff_x19 = 0;
  }
  else {
    FUN_011cdecc();
    (**(code **)(extraout_x8 + 0x138))(auStack_28);
    FUN_00c3b4f0();
    FUN_011ce908();
    FUN_011c1500();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,auStack_28[0] & 0xfffffffffffffffe);
    }
  }
  return unaff_x19;
}


// calls FUN_011ce908 @ 011ce908
// calls FUN_011c1500 @ 011c1500
// calls FUN_00c3b4f0 @ 00c3b4f0
// calls FUN_011cdecc @ 011cdecc
// calls FUN_008cee58 @ 008cee58
// nativeIsTokenConfident (JJ)Z -> 011cb850

/* === nativeIsTokenConfident (JJ)Z | JNI_nativeIsTokenConfident @ 011cb850 size=48 === */

ulong JNI_nativeIsTokenConfident(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf40();
  uVar1 = (**(code **)(extraout_x8 + 0x140))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeGetTokenNormalizedString (JJ)Ljava/lang/String; -> 011cb880

/* === nativeGetTokenNormalizedString (JJ)Ljava/lang/String; | JNI_nativeGetTokenNormalizedString @ 011cb880 size=92 === */

undefined8 JNI_nativeGetTokenNormalizedString(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  ulong extraout_x8_00;
  undefined8 unaff_x19;
  ulong auStack_28 [2];
  undefined8 uStack_18;
  
  if (param_3 == 0) {
    unaff_x19 = 0;
  }
  else {
    FUN_011cdecc();
    (**(code **)(extraout_x8 + 0x148))(auStack_28);
    FUN_00c3b4f0();
    FUN_011ce908();
    FUN_011c1500();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,auStack_28[0] & 0xfffffffffffffffe);
    }
  }
  return unaff_x19;
}


// calls FUN_011ce908 @ 011ce908
// calls FUN_011c1500 @ 011c1500
// calls FUN_00c3b4f0 @ 00c3b4f0
// calls FUN_011cdecc @ 011cdecc
// calls FUN_008cee58 @ 008cee58
// nativeGetTokenLanguage (JJ)I -> 011cb8dc

/* === nativeGetTokenLanguage (JJ)I | JNI_nativeGetTokenLanguage @ 011cb8dc size=32 === */

void JNI_nativeGetTokenLanguage(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf40();
                    /* WARNING: Could not recover jumptable at 0x011cb8f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x158))();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeGetTokenCategory (JJ)I -> 011cb8fc

/* === nativeGetTokenCategory (JJ)I | JNI_nativeGetTokenCategory @ 011cb8fc size=32 === */

void JNI_nativeGetTokenCategory(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf40();
                    /* WARNING: Could not recover jumptable at 0x011cb914. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x150))();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeGetTokenInputUnitCount (JJ)I -> 011cb91c

/* === nativeGetTokenInputUnitCount (JJ)I | JNI_nativeGetTokenInputUnitCount @ 011cb91c size=32 === */

void JNI_nativeGetTokenInputUnitCount(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf40();
                    /* WARNING: Could not recover jumptable at 0x011cb934. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x160))();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeGetTokenInputUnit (JJI)J -> 011cb93c

/* === nativeGetTokenInputUnit (JJI)J | JNI_nativeGetTokenInputUnit @ 011cb93c size=48 === */

void JNI_nativeGetTokenInputUnit
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,
               undefined4 param_5)

{
  long extraout_x8;
  undefined1 auVar1 [16];
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  auVar1 = FUN_011cdf40();
  (**(code **)(extraout_x8 + 0x168))(auVar1._0_8_,auVar1._8_8_,param_5);
  return;
}


// calls FUN_011cdf40 @ 011cdf40
// calls FUN_00ba5604 @ 00ba5604
// nativeGetInputUnitRange (JJ)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 011cb96c

/* === nativeGetInputUnitRange (JJ)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | JNI_nativeGetInputUnitRange @ 011cb96c size=48 === */

void JNI_nativeGetInputUnitRange(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  FUN_011cdecc();
  (**(code **)(extraout_x8 + 0x170))();
  FUN_011cde90();
  FUN_011cda44();
  return;
}


// calls FUN_011cda44 @ 011cda44
// calls FUN_011cde90 @ 011cde90
// calls FUN_011cdecc @ 011cdecc
// calls FUN_00ba5604 @ 00ba5604
// nativeGetInputUnitString (JJ)Ljava/lang/String; -> 011cb99c

/* === nativeGetInputUnitString (JJ)Ljava/lang/String; | JNI_nativeGetInputUnitString @ 011cb99c size=92 === */

undefined8 JNI_nativeGetInputUnitString(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  ulong extraout_x8_00;
  undefined8 unaff_x19;
  ulong auStack_28 [2];
  undefined8 uStack_18;
  
  if (param_3 == 0) {
    unaff_x19 = 0;
  }
  else {
    FUN_011cdecc();
    (**(code **)(extraout_x8 + 0x178))(auStack_28);
    FUN_00c3b4f0();
    FUN_011ce908();
    FUN_011c1500();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,auStack_28[0] & 0xfffffffffffffffe);
    }
  }
  return unaff_x19;
}


// calls FUN_011ce908 @ 011ce908
// calls FUN_011c1500 @ 011c1500
// calls FUN_00c3b4f0 @ 00c3b4f0
// calls FUN_011cdecc @ 011cdecc
// calls FUN_008cee58 @ 008cee58
// nativeGetInputUnitConfidentString (JJ)Ljava/lang/String; -> 011cb9f8

/* === nativeGetInputUnitConfidentString (JJ)Ljava/lang/String; | JNI_nativeGetInputUnitConfidentString @ 011cb9f8 size=92 === */

undefined8 JNI_nativeGetInputUnitConfidentString(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  ulong extraout_x8_00;
  undefined8 unaff_x19;
  ulong auStack_28 [2];
  undefined8 uStack_18;
  
  if (param_3 == 0) {
    unaff_x19 = 0;
  }
  else {
    FUN_011cdecc();
    (**(code **)(extraout_x8 + 0x180))(auStack_28);
    FUN_00c3b4f0();
    FUN_011ce908();
    FUN_011c1500();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,auStack_28[0] & 0xfffffffffffffffe);
    }
  }
  return unaff_x19;
}


// calls FUN_011ce908 @ 011ce908
// calls FUN_011c1500 @ 011c1500
// calls FUN_00c3b4f0 @ 00c3b4f0
// calls FUN_011cdecc @ 011cdecc
// calls FUN_008cee58 @ 008cee58
// nativeIsInputUnitConfident (JJ)Z -> 011cba54

/* === nativeIsInputUnitConfident (JJ)Z | JNI_nativeIsInputUnitConfident @ 011cba54 size=48 === */

ulong JNI_nativeIsInputUnitConfident(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf40();
  uVar1 = (**(code **)(extraout_x8 + 0x188))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf40 @ 011cdf40
// nativeIsInputUnitEmpty (JJ)Z -> 011cba84

/* === nativeIsInputUnitEmpty (JJ)Z | JNI_nativeIsInputUnitEmpty @ 011cba84 size=52 === */

uint JNI_nativeIsInputUnitEmpty(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long extraout_x8;
  
  if (param_3 == 0) {
    return 1;
  }
  FUN_011cdf40();
  uVar1 = (**(code **)(extraout_x8 + 400))();
  return uVar1 & 1;
}


// calls FUN_011cdf40 @ 011cdf40
// nativeFillTokenCandidateList (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z -> 011cbab8

/* === nativeFillTokenCandidateList (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z | JNI_nativeFillTokenCandidateList @ 011cbab8 size=116 === */

void JNI_nativeFillTokenCandidateList
               (long *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 extraout_x1;
  code *extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  undefined8 *unaff_x21;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf34(*(undefined8 *)(*param_1 + 800),(int)param_1,param_4,DAT_022a3440);
  uVar1 = (*extraout_x8)();
  FUN_00bc2770(*unaff_x21,uVar1,extraout_x1,DAT_022a3448);
  (**(code **)(extraout_x8_00 + 800))();
  FUN_011cdeb0();
  (**(code **)(extraout_x8_01 + 0x198))();
  FUN_011cdf24();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_011cdeb0 @ 011cdeb0
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf24 @ 011cdf24
// nativeGetTokenCandidateCount (J)I -> 011cbb2c

/* === nativeGetTokenCandidateCount (J)I | JNI_nativeGetTokenCandidateCount @ 011cbb2c size=28 === */

void JNI_nativeGetTokenCandidateCount(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    FUN_00b3477c();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x011cbb40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 0x1a0))(param_3);
  return;
}


// calls FUN_00b3477c @ 00b3477c
// nativeGetTokenCandidateString (JI)Ljava/lang/String; -> 011cbb48

/* === nativeGetTokenCandidateString (JI)Ljava/lang/String; | JNI_nativeGetTokenCandidateString @ 011cbb48 size=96 === */

undefined8
JNI_nativeGetTokenCandidateString
          (undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  undefined8 uVar1;
  long extraout_x8;
  ulong extraout_x8_00;
  undefined8 unaff_x19;
  ulong auStack_28 [2];
  undefined8 uStack_18;
  
  if (param_3 == 0) {
    unaff_x19 = 0;
  }
  else {
    uVar1 = FUN_011cdee0();
    (**(code **)(extraout_x8 + 0x1a8))(auStack_28,uVar1,param_4);
    FUN_00c3b4f0();
    FUN_011ce908();
    FUN_011c1500();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,auStack_28[0] & 0xfffffffffffffffe);
    }
  }
  return unaff_x19;
}


// calls FUN_011ce908 @ 011ce908
// calls FUN_011c1500 @ 011c1500
// calls FUN_00c3b4f0 @ 00c3b4f0
// calls FUN_011cdee0 @ 011cdee0
// calls FUN_008cee58 @ 008cee58
// nativeGetTokenCandidateRange (JI)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 011cbba8

/* === nativeGetTokenCandidateRange (JI)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | JNI_nativeGetTokenCandidateRange @ 011cbba8 size=52 === */

void JNI_nativeGetTokenCandidateRange
               (undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  undefined8 uVar1;
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  uVar1 = FUN_011cdee0();
  (**(code **)(extraout_x8 + 0x1b0))(uVar1,param_4);
  FUN_011cde90();
  FUN_011cda44();
  return;
}


// calls FUN_011cda44 @ 011cda44
// calls FUN_011cde90 @ 011cde90
// calls FUN_011cdee0 @ 011cdee0
// calls FUN_00ba5604 @ 00ba5604
// nativeSelectTokenCandidate (JI)Z -> 011cbbdc

/* === nativeSelectTokenCandidate (JI)Z | JNI_nativeSelectTokenCandidate @ 011cbbdc size=48 === */

ulong JNI_nativeSelectTokenCandidate(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf74();
  uVar1 = (**(code **)(extraout_x8 + 0x1b8))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeSelectTokens (J[J)I -> 011cbc0c

/* === nativeSelectTokens (J[J)I | JNI_nativeSelectTokens @ 011cbc0c size=324 === */

void JNI_nativeSelectTokens(undefined8 param_1,undefined8 param_2,long param_3,long param_4)

{
  uint uVar1;
  undefined4 uVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long extraout_x8;
  long lVar6;
  long extraout_x8_00;
  long extraout_x8_01;
  long lVar7;
  ulong uVar8;
  long lVar9;
  undefined1 auVar10 [16];
  long lStack_58;
  long lStack_48;
  
  uVar2 = 0;
  if (param_3 != 0) {
    lVar4 = param_4;
    plVar3 = (long *)FUN_011cdf18();
    if (lVar4 != 0) {
      lVar4 = (**(code **)(*plVar3 + 0x6f0))(plVar3,param_4,0);
      if (lVar4 == 0) {
        uVar2 = 0;
        goto LAB_011cbd2c;
      }
      FUN_00bc2770(*plVar3);
      uVar1 = (**(code **)(extraout_x8 + 0x558))();
      if (uVar1 == 0) {
        lVar5 = 0;
        lVar6 = 0;
      }
      else {
        if ((int)uVar1 < 0) {
                    /* WARNING: Subroutine does not return */
          FUN_00a83c50();
        }
        lVar9 = (long)(int)uVar1 * 8;
        lVar5 = FUN_020543f8(lVar9);
        lVar6 = lVar5 + (long)(int)uVar1 * 8;
        for (lVar7 = 0; lVar9 != lVar7; lVar7 = lVar7 + 8) {
          *(undefined8 *)(lVar5 + lVar7) = 0;
        }
        lStack_58 = lVar5;
        lStack_48 = lVar6;
      }
      for (uVar8 = 0; (uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU)) != uVar8; uVar8 = uVar8 + 1) {
        if ((ulong)(lVar6 - lVar5 >> 3) <= uVar8) {
                    /* WARNING: Subroutine does not return */
          FUN_009bee00();
        }
        *(undefined8 *)(lVar5 + uVar8 * 8) = *(undefined8 *)(lVar4 + uVar8 * 8);
      }
      auVar10 = FUN_00bc2770(*plVar3);
      (**(code **)(extraout_x8_00 + 0x6f8))(auVar10._0_8_,auVar10._8_8_,lVar4,0);
    }
    FUN_011cdf08();
    uVar2 = (**(code **)(extraout_x8_01 + 0x1c0))();
    if (lStack_58 != 0) {
      FUN_008cee58(lStack_58,lStack_48 - lStack_58);
    }
  }
LAB_011cbd2c:
  FUN_00ba57d8(uVar2);
  return;
}


// calls FUN_011cdf18 @ 011cdf18
// calls FUN_00a83c50 @ 00a83c50
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf08 @ 011cdf08
// calls FUN_008cee58 @ 008cee58
// calls FUN_009bee00 @ 009bee00
// calls FUN_020543f8 @ 020543f8
// calls FUN_00ba57d8 @ 00ba57d8
// nativeFillCandidateList (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z -> 011cbd50

/* === nativeFillCandidateList (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z | JNI_nativeFillCandidateList @ 011cbd50 size=116 === */

void JNI_nativeFillCandidateList(long *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 extraout_x1;
  code *extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  undefined8 *unaff_x21;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf34(*(undefined8 *)(*param_1 + 800),(int)param_1,param_4,DAT_022a3440);
  uVar1 = (*extraout_x8)();
  FUN_00bc2770(*unaff_x21,uVar1,extraout_x1,DAT_022a3448);
  (**(code **)(extraout_x8_00 + 800))();
  FUN_011cdeb0();
  (**(code **)(extraout_x8_01 + 0x1c8))();
  FUN_011cdf24();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_011cdeb0 @ 011cdeb0
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf24 @ 011cdf24
// nativeGetCandidateCount (J)I -> 011cbdc4

/* === nativeGetCandidateCount (J)I | JNI_nativeGetCandidateCount @ 011cbdc4 size=48 === */

void JNI_nativeGetCandidateCount(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    FUN_00b3477c();
    return;
  }
  (**(code **)(*param_3 + 0x1d0))(param_3);
  return;
}


// calls FUN_00b3477c @ 00b3477c
// nativeSelectCandidate (JI)Z -> 011cbdf4

/* === nativeSelectCandidate (JI)Z | JNI_nativeSelectCandidate @ 011cbdf4 size=48 === */

ulong JNI_nativeSelectCandidate(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf74();
  uVar1 = (**(code **)(extraout_x8 + 0x1d8))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeDeleteCandidate (JI)Z -> 011cbe24

/* === nativeDeleteCandidate (JI)Z | JNI_nativeDeleteCandidate @ 011cbe24 size=48 === */

ulong JNI_nativeDeleteCandidate(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf74();
  uVar1 = (**(code **)(extraout_x8 + 0x1e0))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeHighlightCandidate (JI)Z -> 011cbe54

/* === nativeHighlightCandidate (JI)Z | JNI_nativeHighlightCandidate @ 011cbe54 size=48 === */

ulong JNI_nativeHighlightCandidate(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf74();
  uVar1 = (**(code **)(extraout_x8 + 0x1f0))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeGetHighlightedCandidate (J)I -> 011cbe84

/* === nativeGetHighlightedCandidate (J)I | JNI_nativeGetHighlightedCandidate @ 011cbe84 size=28 === */

void JNI_nativeGetHighlightedCandidate(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    FUN_011cdfa4();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x011cbe98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 0x1f8))(param_3);
  return;
}


// calls FUN_011cdfa4 @ 011cdfa4
// nativeGetCandidateString (JI)Ljava/lang/String; -> 011cbea0

/* === nativeGetCandidateString (JI)Ljava/lang/String; | JNI_nativeGetCandidateString @ 011cbea0 size=96 === */

undefined8
JNI_nativeGetCandidateString(undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  undefined8 uVar1;
  long extraout_x8;
  ulong extraout_x8_00;
  undefined8 unaff_x19;
  ulong auStack_28 [2];
  undefined8 uStack_18;
  
  if (param_3 == 0) {
    unaff_x19 = 0;
  }
  else {
    uVar1 = FUN_011cdee0();
    (**(code **)(extraout_x8 + 0x200))(auStack_28,uVar1,param_4);
    FUN_00c3b4f0();
    FUN_011ce908();
    FUN_011c1500();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,auStack_28[0] & 0xfffffffffffffffe);
    }
  }
  return unaff_x19;
}


// calls FUN_011ce908 @ 011ce908
// calls FUN_011c1500 @ 011c1500
// calls FUN_00c3b4f0 @ 00c3b4f0
// calls FUN_011cdee0 @ 011cdee0
// calls FUN_008cee58 @ 008cee58
// nativeGetCandidateRange (JI)Lcom/google/android/apps/inputmethod/libs/hmm/Range; -> 011cbf00

/* === nativeGetCandidateRange (JI)Lcom/google/android/apps/inputmethod/libs/hmm/Range; | JNI_nativeGetCandidateRange @ 011cbf00 size=52 === */

void JNI_nativeGetCandidateRange
               (undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  undefined8 uVar1;
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  uVar1 = FUN_011cdee0();
  (**(code **)(extraout_x8 + 0x220))(uVar1,param_4);
  FUN_011cde90();
  FUN_011cda44();
  return;
}


// calls FUN_011cda44 @ 011cda44
// calls FUN_011cde90 @ 011cde90
// calls FUN_011cdee0 @ 011cdee0
// calls FUN_00ba5604 @ 00ba5604
// nativeGetCandidateType (JI)I -> 011cbf34

/* === nativeGetCandidateType (JI)I | JNI_nativeGetCandidateType @ 011cbf34 size=32 === */

void JNI_nativeGetCandidateType(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf74();
                    /* WARNING: Could not recover jumptable at 0x011cbf4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x228))();
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeIsCandidateDuplicated (JI)Z -> 011cbf54

/* === nativeIsCandidateDuplicated (JI)Z | JNI_nativeIsCandidateDuplicated @ 011cbf54 size=48 === */

ulong JNI_nativeIsCandidateDuplicated(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf74();
  uVar1 = (**(code **)(extraout_x8 + 0x230))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeIsCandidateCorrected (JI)Z -> 011cbf84

/* === nativeIsCandidateCorrected (JI)Z | JNI_nativeIsCandidateCorrected @ 011cbf84 size=48 === */

ulong JNI_nativeIsCandidateCorrected(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf74();
  uVar1 = (**(code **)(extraout_x8 + 0x1e8))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeGetCandidateTokenCount (JI)I -> 011cbfb4

/* === nativeGetCandidateTokenCount (JI)I | JNI_nativeGetCandidateTokenCount @ 011cbfb4 size=32 === */

void JNI_nativeGetCandidateTokenCount(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf74();
                    /* WARNING: Could not recover jumptable at 0x011cbfcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x238))();
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeGetCandidateTokenFeatureCount (JII)I -> 011cbfd4

/* === nativeGetCandidateTokenFeatureCount (JII)I | JNI_nativeGetCandidateTokenFeatureCount @ 011cbfd4 size=36 === */

void JNI_nativeGetCandidateTokenFeatureCount
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,
               undefined4 param_5)

{
  long extraout_x8;
  undefined1 auVar1 [16];
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  auVar1 = FUN_011cdf74();
                    /* WARNING: Could not recover jumptable at 0x011cbff0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x240))(auVar1._0_8_,auVar1._8_8_,param_5);
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeGetCandidateToken (JII)J -> 011cbff8

/* === nativeGetCandidateToken (JII)J | JNI_nativeGetCandidateToken @ 011cbff8 size=48 === */

void JNI_nativeGetCandidateToken
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,
               undefined4 param_5)

{
  long extraout_x8;
  undefined1 auVar1 [16];
  
  if (param_3 == 0) {
    FUN_00ba5604();
    return;
  }
  auVar1 = FUN_011cdf74();
  (**(code **)(extraout_x8 + 0x248))(auVar1._0_8_,auVar1._8_8_,param_5);
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00ba5604 @ 00ba5604
// nativeGetCandidatePrimaryDataSource (JI)I -> 011cc028

/* === nativeGetCandidatePrimaryDataSource (JI)I | JNI_nativeGetCandidatePrimaryDataSource @ 011cc028 size=32 === */

void JNI_nativeGetCandidatePrimaryDataSource(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_011cdfa4();
    return;
  }
  FUN_011cdf74();
                    /* WARNING: Could not recover jumptable at 0x011cc040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x250))();
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_011cdfa4 @ 011cdfa4
// nativeGetCandidateDataSourceMask (JI)I -> 011cc048

/* === nativeGetCandidateDataSourceMask (JI)I | JNI_nativeGetCandidateDataSourceMask @ 011cc048 size=32 === */

void JNI_nativeGetCandidateDataSourceMask(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_011cdfa4();
    return;
  }
  FUN_011cdf74();
                    /* WARNING: Could not recover jumptable at 0x011cc060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 600))();
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_011cdfa4 @ 011cdfa4
// nativeIsCandidateFromSingleDataSource (JI)Z -> 011cc068

/* === nativeIsCandidateFromSingleDataSource (JI)Z | JNI_nativeIsCandidateFromSingleDataSource @ 011cc068 size=48 === */

ulong JNI_nativeIsCandidateFromSingleDataSource(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long extraout_x8;
  
  if (param_3 == 0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  FUN_011cdf74();
  uVar1 = (**(code **)(extraout_x8 + 0x260))();
  return (ulong)(uVar1 & 1);
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeGetDataSourceIndex (JLjava/lang/String;)I -> 011cc098

/* === nativeGetDataSourceIndex (JLjava/lang/String;)I | JNI_nativeGetDataSourceIndex @ 011cc098 size=100 === */

undefined4 JNI_nativeGetDataSourceIndex(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  long extraout_x8;
  byte bStack_28;
  undefined7 uStack_27;
  undefined8 uStack_18;
  
  if (param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    FUN_011cdfac();
    FUN_011cdf18();
    FUN_011ce9e0();
    FUN_011cdf08();
    uVar1 = (**(code **)(extraout_x8 + 0x268))();
    if ((bStack_28 & 1) != 0) {
      FUN_008cee58(uStack_18,CONCAT71(uStack_27,bStack_28) & 0xfffffffffffffffe);
    }
  }
  return uVar1;
}


// calls FUN_011cdfac @ 011cdfac
// calls FUN_008cee58 @ 008cee58
// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdf08 @ 011cdf08
// nativeFillPredictionCandidateList (J)Z -> 011cc0fc

/* === nativeFillPredictionCandidateList (J)Z | JNI_nativeFillPredictionCandidateList @ 011cc0fc size=52 === */

ulong JNI_nativeFillPredictionCandidateList(undefined8 param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_3 == (long *)0x0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  uVar1 = (**(code **)(*param_3 + 0x278))(param_3);
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// nativeGetPredictionCandidateCount (J)I -> 011cc130

/* === nativeGetPredictionCandidateCount (J)I | JNI_nativeGetPredictionCandidateCount @ 011cc130 size=28 === */

void JNI_nativeGetPredictionCandidateCount(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    FUN_00b3477c();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x011cc144. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 0x280))(param_3);
  return;
}


// calls FUN_00b3477c @ 00b3477c
// nativeGetPredictionCandidateString (JI)Ljava/lang/String; -> 011cc14c

/* === nativeGetPredictionCandidateString (JI)Ljava/lang/String; | JNI_nativeGetPredictionCandidateString @ 011cc14c size=96 === */

undefined8
JNI_nativeGetPredictionCandidateString
          (undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  undefined8 uVar1;
  long extraout_x8;
  ulong extraout_x8_00;
  undefined8 unaff_x19;
  ulong auStack_28 [2];
  undefined8 uStack_18;
  
  if (param_3 == 0) {
    unaff_x19 = 0;
  }
  else {
    uVar1 = FUN_011cdee0();
    (**(code **)(extraout_x8 + 0x288))(auStack_28,uVar1,param_4);
    FUN_00c3b4f0();
    FUN_011ce908();
    FUN_011c1500();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,auStack_28[0] & 0xfffffffffffffffe);
    }
  }
  return unaff_x19;
}


// calls FUN_011cdee0 @ 011cdee0
// calls FUN_008cee58 @ 008cee58
// calls FUN_00c3b4f0 @ 00c3b4f0
// calls FUN_011ce908 @ 011ce908
// calls FUN_011c1500 @ 011c1500
// nativeGetPredictionCandidateDataSourceMask (JI)I -> 011cc1ac

/* === nativeGetPredictionCandidateDataSourceMask (JI)I | JNI_nativeGetPredictionCandidateDataSourceMask @ 011cc1ac size=32 === */

void JNI_nativeGetPredictionCandidateDataSourceMask
               (undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf74();
                    /* WARNING: Could not recover jumptable at 0x011cc1c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x290))();
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeGetPredictionCandidateContextLength (JI)I -> 011cc1cc

/* === nativeGetPredictionCandidateContextLength (JI)I | JNI_nativeGetPredictionCandidateContextLength @ 011cc1cc size=32 === */

void JNI_nativeGetPredictionCandidateContextLength
               (undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf74();
                    /* WARNING: Could not recover jumptable at 0x011cc1e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x298))();
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeGetPredictionCandidateContextWordCount (JI)I -> 011cc1ec

/* === nativeGetPredictionCandidateContextWordCount (JI)I | JNI_nativeGetPredictionCandidateContextWordCount @ 011cc1ec size=32 === */

void JNI_nativeGetPredictionCandidateContextWordCount
               (undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf74();
                    /* WARNING: Could not recover jumptable at 0x011cc204. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x2a0))();
  return;
}


// calls FUN_011cdf74 @ 011cdf74
// calls FUN_00b3477c @ 00b3477c
// nativeUnconvertSegments (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z -> 011cc20c

/* === nativeUnconvertSegments (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z | JNI_nativeUnconvertSegments @ 011cc20c size=116 === */

void JNI_nativeUnconvertSegments(long *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 extraout_x1;
  code *extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  undefined8 *unaff_x21;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf34(*(undefined8 *)(*param_1 + 800),(int)param_1,param_4,DAT_022a3440);
  uVar1 = (*extraout_x8)();
  FUN_00bc2770(*unaff_x21,uVar1,extraout_x1,DAT_022a3448);
  (**(code **)(extraout_x8_00 + 800))();
  FUN_011cdeb0();
  (**(code **)(extraout_x8_01 + 0x2a8))();
  FUN_011cdf24();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_011cdeb0 @ 011cdeb0
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf24 @ 011cdf24
// nativeUnselectTokens (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z -> 011cc280

/* === nativeUnselectTokens (JLcom/google/android/apps/inputmethod/libs/hmm/Range;)Z | JNI_nativeUnselectTokens @ 011cc280 size=116 === */

void JNI_nativeUnselectTokens(long *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 extraout_x1;
  code *extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  undefined8 *unaff_x21;
  
  if (param_3 == 0) {
    FUN_00b3477c();
    return;
  }
  FUN_011cdf34(*(undefined8 *)(*param_1 + 800),(int)param_1,param_4,DAT_022a3440);
  uVar1 = (*extraout_x8)();
  FUN_00bc2770(*unaff_x21,uVar1,extraout_x1,DAT_022a3448);
  (**(code **)(extraout_x8_00 + 800))();
  FUN_011cdeb0();
  (**(code **)(extraout_x8_01 + 0x2b0))();
  FUN_011cdf24();
  return;
}


// calls FUN_00b3477c @ 00b3477c
// calls FUN_011cdf34 @ 011cdf34
// calls FUN_011cdeb0 @ 011cdeb0
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf24 @ 011cdf24
// nativeDumpSourceTokenSequenceVectorPointer (JJ)Ljava/lang/String; -> 011cc2f4

/* === nativeDumpSourceTokenSequenceVectorPointer (JJ)Ljava/lang/String; | JNI_nativeDumpSourceTokenSequenceVectorPointer @ 011cc2f4 size=476 === */

undefined8
JNI_nativeDumpSourceTokenSequenceVectorPointer
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,long *param_4)

{
  ulong uVar1;
  byte *pbVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  byte *pbVar8;
  byte bStack_d0;
  undefined7 uStack_cf;
  undefined8 uStack_c0;
  undefined *puStack_b8;
  undefined8 uStack_b0;
  ulong *puStack_88;
  ulong uStack_80;
  ulong auStack_78 [4];
  long lStack_58;
  
  lVar3 = tpidr_el0;
  lStack_58 = *(long *)(lVar3 + 0x28);
  if (param_4 == (long *)0x0) {
    uVar6 = 0;
  }
  else {
    lVar5 = FUN_009eb4d4((ulong)(param_4[1] - *param_4) >> 5,auStack_78);
    uStack_80 = lVar5 - (long)auStack_78;
    puStack_b8 = &DAT_001fac9f;
    uStack_b0 = 4;
    puStack_88 = auStack_78;
    FUN_0090f078(&bStack_d0,&puStack_88,&puStack_b8);
    for (puVar7 = (undefined8 *)*param_4; puVar7 != (undefined8 *)param_4[1]; puVar7 = puVar7 + 4) {
      FUN_009804f0(&bStack_d0,&DAT_002da040,2);
      for (pbVar8 = (byte *)*puVar7; pbVar8 != (byte *)puVar7[1]; pbVar8 = pbVar8 + 0x20) {
        if (pbVar8 != (byte *)*puVar7) {
          FUN_009804f0(&bStack_d0,&DAT_001ce832,2);
        }
        pbVar2 = *(byte **)(pbVar8 + 0x10);
        uVar1 = *(ulong *)(pbVar8 + 8);
        if ((*pbVar8 & 1) == 0) {
          pbVar2 = pbVar8 + 1;
          uVar1 = (ulong)(*pbVar8 >> 1);
        }
        FUN_009804f0(&bStack_d0,pbVar2,uVar1);
      }
      FUN_011cdfe8(&puStack_88,(double)(float)puVar7[3],(double)(float)((ulong)puVar7[3] >> 0x20),
                   "], %8.4f, %8.4f}, ");
      uVar1 = uStack_80;
      uVar4 = auStack_78[0];
      if (((ulong)puStack_88 & 1) == 0) {
        uVar1 = (ulong)puStack_88 >> 1 & 0x7f;
        uVar4 = (ulong)&puStack_88 | 1;
      }
      FUN_009804f0(&bStack_d0,uVar4,uVar1);
      if (((ulong)puStack_88 & 1) != 0) {
        FUN_008cee58(auStack_78[0],(ulong)puStack_88 & 0xfffffffffffffffe);
      }
    }
    FUN_009804f0(&bStack_d0,&DAT_002624ab,1);
    uVar6 = FUN_011ce908(param_1,&bStack_d0);
    if ((bStack_d0 & 1) != 0) {
      FUN_008cee58(uStack_c0,CONCAT71(uStack_cf,bStack_d0) & 0xfffffffffffffffe);
    }
  }
  if (*(long *)(lVar3 + 0x28) != lStack_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}


// calls FUN_009eb4d4 @ 009eb4d4
// calls FUN_011cdfe8 @ 011cdfe8
// calls __stack_chk_fail @ 02054530
// calls FUN_008cee58 @ 008cee58
// calls FUN_011ce908 @ 011ce908
// calls FUN_0090f078 @ 0090f078
// calls FUN_009804f0 @ 009804f0
// nativeRefreshData (J)V -> 011ca3b4
// nativeExportAllEntries (J)[Lcom/google/android/apps/inputmethod/libs/hmm/MutableDictionaryAccessor$Entry; -> 011cc4d0

/* === nativeExportAllEntries (J)[Lcom/google/android/apps/inputmethod/libs/hmm/MutableDictionaryAccessor$Entry; | JNI_nativeExportAllEntries @ 011cc4d0 size=144 === */

undefined8 JNI_nativeExportAllEntries(undefined8 param_1,undefined8 param_2,long *param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  long lStack_40;
  long lStack_38;
  undefined8 uStack_30;
  undefined1 *puStack_28;
  
  if (param_3 == (long *)0x0) {
    uVar2 = 0;
  }
  else {
    lStack_40 = 0;
    lStack_38 = 0;
    uStack_30 = 0;
    uVar1 = (**(code **)(*param_3 + 0x20))(param_3,4,&lStack_40);
    uVar2 = 0;
    if ((uVar1 & 1) != 0) {
      uVar2 = FUN_011cc560(param_1,lStack_40,(lStack_38 - lStack_40) / 0x58);
    }
    puStack_28 = (undefined1 *)&lStack_40;
    FUN_011cddb0(&puStack_28);
  }
  return uVar2;
}


// calls FUN_011cddb0 @ 011cddb0
// calls FUN_011cc560 @ 011cc560
// nativeExportAllModifiedEntries (J)[Lcom/google/android/apps/inputmethod/libs/hmm/MutableDictionaryAccessor$Entry; -> 011cc7a8

/* === nativeExportAllModifiedEntries (J)[Lcom/google/android/apps/inputmethod/libs/hmm/MutableDictionaryAccessor$Entry; | JNI_nativeExportAllModifiedEntries @ 011cc7a8 size=144 === */

undefined8 JNI_nativeExportAllModifiedEntries(undefined8 param_1,undefined8 param_2,long *param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  long lStack_40;
  long lStack_38;
  undefined8 uStack_30;
  undefined1 *puStack_28;
  
  if (param_3 == (long *)0x0) {
    uVar2 = 0;
  }
  else {
    lStack_40 = 0;
    lStack_38 = 0;
    uStack_30 = 0;
    uVar1 = (**(code **)(*param_3 + 0x20))(param_3,5,&lStack_40);
    uVar2 = 0;
    if ((uVar1 & 1) != 0) {
      uVar2 = FUN_011cc560(param_1,lStack_40,(lStack_38 - lStack_40) / 0x58);
    }
    puStack_28 = (undefined1 *)&lStack_40;
    FUN_011cddb0(&puStack_28);
  }
  return uVar2;
}


// calls FUN_011cddb0 @ 011cddb0
// calls FUN_011cc560 @ 011cc560
// nativePersist (JLjava/lang/String;)Z -> 011cc838

/* === nativePersist (JLjava/lang/String;)Z | JNI_nativePersist @ 011cc838 size=132 === */

ulong JNI_nativePersist(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long extraout_x8;
  long extraout_x8_00;
  ulong extraout_x8_01;
  ulong auStack_38 [2];
  undefined8 uStack_28;
  long alStack_20 [2];
  
  if (param_3 != (long *)0x0) {
    FUN_011cdfac(&PTR_DAT_02231000);
    FUN_011cdf18(*(undefined8 *)(extraout_x8 + 0x288));
    alStack_20[0] = extraout_x8_00 + 0x10;
    alStack_20[1] = 0;
    FUN_011ce9e0();
    FUN_0129b0e0(alStack_20,auStack_38);
    (**(code **)(*param_3 + 0x28))(param_3,alStack_20);
    FUN_011cdf68();
    if ((extraout_x8_01 & 1) != 0) {
      FUN_008cee58(uStack_28,auStack_38[0] & 0xfffffffffffffffe);
    }
    FUN_0129b078(alStack_20);
  }
  return (ulong)param_3 & 0xffffffff;
}


// calls FUN_011cdfac @ 011cdfac
// calls FUN_008cee58 @ 008cee58
// calls FUN_0129b078 @ 0129b078
// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_0129b0e0 @ 0129b0e0
// calls FUN_011cdf68 @ 011cdf68
// nativeCompact (JI)Z -> 011cc8bc

/* === nativeCompact (JI)Z | JNI_nativeCompact @ 011cc8bc size=56 === */

ulong JNI_nativeCompact(undefined8 param_1,undefined8 param_2,long *param_3,int param_4)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_3 == (long *)0x0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  uVar1 = (**(code **)(*param_3 + 0x30))(param_3,(long)param_4);
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// nativeGetDictionarySize (J)I -> 011cc8f4

/* === nativeGetDictionarySize (J)I | JNI_nativeGetDictionarySize @ 011cc8f4 size=48 === */

void JNI_nativeGetDictionarySize(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    FUN_00b3477c();
    return;
  }
  (**(code **)(*param_3 + 0x38))(param_3);
  return;
}


// calls FUN_00b3477c @ 00b3477c
// nativeGetDictionaryCount (J)I -> 011cc924

/* === nativeGetDictionaryCount (J)I | JNI_nativeGetDictionaryCount @ 011cc924 size=48 === */

void JNI_nativeGetDictionaryCount(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    FUN_00b3477c();
    return;
  }
  (**(code **)(*param_3 + 0x40))(param_3);
  return;
}


// calls FUN_00b3477c @ 00b3477c
// nativeGetLastSyncTime (J)J -> 011cc954

/* === nativeGetLastSyncTime (J)J | JNI_nativeGetLastSyncTime @ 011cc954 size=28 === */

void JNI_nativeGetLastSyncTime(undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (param_3 == (long *)0x0) {
    FUN_00ba5604();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x011cc968. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 0x48))(param_3);
  return;
}


// calls FUN_00ba5604 @ 00ba5604
// nativeSetLastSyncTime (JJ)V -> 011cc970

/* === nativeSetLastSyncTime (JJ)V | JNI_nativeSetLastSyncTime @ 011cc970 size=32 === */

void JNI_nativeSetLastSyncTime(undefined8 param_1,undefined8 param_2,long param_3)

{
  long extraout_x8;
  
  if (param_3 == 0) {
    return;
  }
  FUN_011cdf40();
                    /* WARNING: Could not recover jumptable at 0x011cc988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(extraout_x8 + 0x50))();
  return;
}


// calls FUN_011cdf40 @ 011cdf40
// nativeInsertOrUpdate (J[Ljava/lang/String;[ILjava/lang/String;IZZ)Z -> 011cc990

/* === nativeInsertOrUpdate (J[Ljava/lang/String;[ILjava/lang/String;IZZ)Z | JNI_nativeInsertOrUpdate @ 011cc990 size=372 === */

undefined4
JNI_nativeInsertOrUpdate
          (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4,undefined8 param_5
          ,undefined8 param_6,undefined4 param_7,char param_8,char param_9)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong extraout_x8;
  long extraout_x8_00;
  ulong extraout_x9;
  undefined8 uStack_90;
  ulong uStack_88;
  long lStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  long lStack_60;
  long lStack_58;
  long lStack_50;
  undefined8 uStack_48;
  
  if (param_3 == (long *)0x0) {
    param_7 = 0;
  }
  else {
    lStack_60 = 0;
    lStack_58 = 0;
    lStack_50 = 0;
    uStack_48 = param_4;
    uVar3 = FUN_011ccb04(param_1,&uStack_48,&lStack_60);
    if ((uVar3 & 1) == 0) {
      param_7 = 0;
    }
    else {
      uStack_78 = 0;
      uStack_70 = 0;
      uStack_68 = 0;
      uVar3 = FUN_011ccc04(param_1,param_5,&uStack_78);
      if ((uVar3 & 1) == 0) {
        param_7 = 0;
      }
      else {
        uStack_90 = (undefined8 *)0x0;
        uStack_88 = 0;
        lStack_80 = 0;
        FUN_011ce9e0(param_1,param_6,&uStack_90);
        uVar3 = uStack_88;
        lVar1 = lStack_80;
        if (((ulong)uStack_90 & 1) == 0) {
          lVar1 = (long)&uStack_90 + 1;
          uVar3 = (ulong)uStack_90 >> 1 & 0x7f;
        }
        (**(code **)(*param_3 + 0x58))
                  (param_3,&lStack_60,&uStack_78,lVar1,uVar3,param_7,param_8 != '\0',param_9 != '\0'
                  );
        FUN_011cdfc4();
        if ((extraout_x8 & 1) != 0) {
          FUN_008cee58(lStack_80,(ulong)uStack_90 & 0xfffffffffffffffe);
        }
      }
      uStack_90 = &uStack_78;
      FUN_008e34e8(&uStack_90);
    }
    lVar2 = lStack_58;
    lVar1 = lStack_60;
    if (lStack_60 != 0) {
      while (lVar2 != lVar1) {
        FUN_00f7f2e4();
        if ((extraout_x9 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(extraout_x8_00 + -8),
                       *(ulong *)(extraout_x8_00 + -0x18) & 0xfffffffffffffffe);
        }
      }
      lStack_58 = lVar1;
      FUN_008cee58(lStack_60,lStack_50 - lStack_60);
    }
  }
  return param_7;
}


// calls FUN_008cee58 @ 008cee58
// calls FUN_011ccc04 @ 011ccc04
// calls FUN_00f7f2e4 @ 00f7f2e4
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdfc4 @ 011cdfc4
// calls FUN_008e34e8 @ 008e34e8
// calls FUN_011ccb04 @ 011ccb04
// nativeInsertOrUpdate (J[Ljava/lang/String;Ljava/lang/String;IZ)Z -> 011ccca4

/* === nativeInsertOrUpdate (J[Ljava/lang/String;Ljava/lang/String;IZ)Z | JNI_nativeInsertOrUpdate @ 011ccca4 size=288 === */

undefined4
JNI_nativeInsertOrUpdate
          (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4,undefined8 param_5
          ,undefined4 param_6,char param_7)

{
  long lVar1;
  ulong uVar2;
  ulong extraout_x8;
  long extraout_x8_00;
  ulong extraout_x9;
  undefined8 uStack_68;
  ulong uStack_60;
  long lStack_58;
  long lStack_50;
  long lStack_48;
  long lStack_40;
  undefined8 uStack_38;
  
  if (param_3 == (long *)0x0) {
    param_6 = 0;
  }
  else {
    uStack_38 = param_4;
    FUN_011cdfb8(param_1,&uStack_38,&lStack_50);
    uVar2 = FUN_011ccb04();
    if ((uVar2 & 1) == 0) {
      param_6 = 0;
    }
    else {
      uStack_68 = 0;
      uStack_60 = 0;
      lStack_58 = 0;
      FUN_011ce9e0(param_1,param_5,&uStack_68);
      uVar2 = uStack_60;
      lVar1 = lStack_58;
      if ((uStack_68 & 1) == 0) {
        lVar1 = (long)&uStack_68 + 1;
        uVar2 = uStack_68 >> 1 & 0x7f;
      }
      (**(code **)(*param_3 + 0x60))(param_3,&lStack_50,lVar1,uVar2,param_6,param_7 != '\0');
      FUN_011cdf68();
      if ((extraout_x8 & 1) != 0) {
        FUN_008cee58(lStack_58,uStack_68 & 0xfffffffffffffffe);
      }
    }
    lVar1 = lStack_50;
    if (lStack_50 != 0) {
      while (lStack_48 != lVar1) {
        FUN_00f7f2e4();
        if ((extraout_x9 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(extraout_x8_00 + -8),
                       *(ulong *)(extraout_x8_00 + -0x18) & 0xfffffffffffffffe);
        }
      }
      lStack_48 = lVar1;
      FUN_008cee58(lStack_50,lStack_40 - lStack_50);
    }
  }
  return param_6;
}


// calls FUN_008cee58 @ 008cee58
// calls FUN_00f7f2e4 @ 00f7f2e4
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdfb8 @ 011cdfb8
// calls FUN_011ccb04 @ 011ccb04
// calls FUN_011cdf68 @ 011cdf68
// nativeInsertOrUpdate (JLjava/lang/String;IZ)Z -> 011ccdc4

/* === nativeInsertOrUpdate (JLjava/lang/String;IZ)Z | JNI_nativeInsertOrUpdate @ 011ccdc4 size=164 === */

ulong JNI_nativeInsertOrUpdate
                (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4,
                ulong param_5,uint param_6)

{
  undefined7 *puVar1;
  ulong extraout_x8;
  byte bStack_48;
  undefined7 uStack_47;
  ulong uStack_40;
  undefined7 *puStack_38;
  
  if (param_3 == (long *)0x0) {
    param_5 = 0;
  }
  else {
    FUN_011cdfac();
    param_5 = param_5 & 0xffffffff;
    FUN_011cdf18();
    FUN_011ce9e0();
    puVar1 = puStack_38;
    if ((bStack_48 & 1) == 0) {
      puVar1 = &uStack_47;
      uStack_40 = (ulong)(bStack_48 >> 1);
    }
    (**(code **)(*param_3 + 0x68))(param_3,puVar1,uStack_40,param_5,(param_6 & 0xff) != 0);
    FUN_011cdf68();
    if ((extraout_x8 & 1) != 0) {
      FUN_008cee58(puStack_38,CONCAT71(uStack_47,bStack_48) & 0xfffffffffffffffe);
    }
  }
  return param_5;
}


// calls FUN_011cdfac @ 011cdfac
// calls FUN_008cee58 @ 008cee58
// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdf68 @ 011cdf68
// nativeAddCount (J[Ljava/lang/String;[ILjava/lang/String;IZ)Z -> 011cce68

/* === nativeAddCount (J[Ljava/lang/String;[ILjava/lang/String;IZ)Z | JNI_nativeAddCount @ 011cce68 size=328 === */

undefined4
JNI_nativeAddCount(undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6,undefined4 param_7,char param_8)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong extraout_x8;
  long extraout_x8_00;
  uint extraout_w9;
  undefined8 *apuStack_88 [2];
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  long lStack_58;
  long lStack_50;
  long lStack_48;
  undefined8 uStack_38;
  
  if (param_3 == (long *)0x0) {
    param_7 = 0;
  }
  else {
    lStack_58 = 0;
    lStack_50 = 0;
    lStack_48 = 0;
    uStack_38 = param_4;
    uVar3 = FUN_011ccb04(param_1,&uStack_38,&lStack_58);
    if ((uVar3 & 1) == 0) {
      param_7 = 0;
    }
    else {
      uStack_70 = 0;
      uStack_68 = 0;
      uStack_60 = 0;
      uVar3 = FUN_011ccc04(param_1,param_5,&uStack_70);
      if ((uVar3 & 1) == 0) {
        param_7 = 0;
      }
      else {
        FUN_011cdf18(param_1,param_6,apuStack_88);
        FUN_011ce9e0();
        (**(code **)(*param_3 + 0x70))
                  (param_3,&lStack_58,&uStack_70,apuStack_88,param_7,param_8 != '\0');
        FUN_011cdf68();
        if ((extraout_x8 & 1) != 0) {
          FUN_008cee58(uStack_78,(ulong)apuStack_88[0] & 0xfffffffffffffffe);
        }
      }
      apuStack_88[0] = &uStack_70;
      FUN_008e34e8(apuStack_88);
    }
    lVar2 = lStack_50;
    lVar1 = lStack_58;
    if (lStack_58 != 0) {
      while (lVar2 != lVar1) {
        FUN_00f7f2e4();
        if ((extraout_w9 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(extraout_x8_00 + -8),
                       *(ulong *)(extraout_x8_00 + -0x18) & 0xfffffffffffffffe);
        }
      }
      lStack_50 = lVar1;
      FUN_008cee58(lStack_58,lStack_48 - lStack_58);
    }
  }
  return param_7;
}


// calls FUN_008cee58 @ 008cee58
// calls FUN_011ccc04 @ 011ccc04
// calls FUN_00f7f2e4 @ 00f7f2e4
// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_008e34e8 @ 008e34e8
// calls FUN_011ccb04 @ 011ccb04
// calls FUN_011cdf68 @ 011cdf68
// nativeAddCount (J[Ljava/lang/String;Ljava/lang/String;I)Z -> 011ccfb0

/* === nativeAddCount (J[Ljava/lang/String;Ljava/lang/String;I)Z | JNI_nativeAddCount @ 011ccfb0 size=244 === */

void JNI_nativeAddCount(undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4,
                       undefined8 param_5,undefined4 param_6)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong extraout_x8;
  long extraout_x8_00;
  uint extraout_w9;
  ulong auStack_60 [2];
  undefined8 uStack_50;
  long lStack_48;
  long lStack_40;
  long lStack_38;
  undefined8 uStack_28;
  
  uStack_28 = param_4;
  if (param_3 == (long *)0x0) {
    param_6 = 0;
  }
  else {
    lStack_48 = 0;
    lStack_40 = 0;
    lStack_38 = 0;
    uVar3 = FUN_011ccb04(param_1,&uStack_28,&lStack_48);
    if ((uVar3 & 1) == 0) {
      param_6 = 0;
    }
    else {
      FUN_011cdfd0(param_1,param_5,auStack_60);
      FUN_011ce9e0();
      (**(code **)(*param_3 + 0x78))(param_3,&lStack_48,auStack_60,param_6);
      FUN_011cdfc4();
      if ((extraout_x8 & 1) != 0) {
        FUN_008cee58(uStack_50,auStack_60[0] & 0xfffffffffffffffe);
      }
    }
    lVar2 = lStack_40;
    lVar1 = lStack_48;
    if (lStack_48 != 0) {
      while (lVar2 != lVar1) {
        FUN_00f7f2e4();
        if ((extraout_w9 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(extraout_x8_00 + -8),
                       *(ulong *)(extraout_x8_00 + -0x18) & 0xfffffffffffffffe);
        }
      }
      lStack_40 = lVar1;
      FUN_008cee58(lStack_48,lStack_38 - lStack_48);
    }
  }
  FUN_00ba57d8(param_6);
  return;
}


// calls FUN_011cdfd0 @ 011cdfd0
// calls FUN_008cee58 @ 008cee58
// calls FUN_00ba57d8 @ 00ba57d8
// calls FUN_00f7f2e4 @ 00f7f2e4
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdfc4 @ 011cdfc4
// calls FUN_011ccb04 @ 011ccb04
// nativeDecreaseCount (J[Ljava/lang/String;[ILjava/lang/String;I)Z -> 011cd0a4

/* === nativeDecreaseCount (J[Ljava/lang/String;[ILjava/lang/String;I)Z | JNI_nativeDecreaseCount @ 011cd0a4 size=304 === */

void JNI_nativeDecreaseCount
               (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined4 param_7)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong extraout_x8;
  long extraout_x8_00;
  uint extraout_w9;
  undefined8 *apuStack_80 [2];
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long lStack_50;
  long lStack_48;
  long lStack_40;
  undefined8 uStack_38;
  
  uStack_38 = param_4;
  if (param_3 != (long *)0x0) {
    lStack_50 = 0;
    lStack_48 = 0;
    lStack_40 = 0;
    uVar3 = FUN_011ccb04(param_1,&uStack_38,&lStack_50);
    if ((uVar3 & 1) != 0) {
      uStack_68 = 0;
      uStack_60 = 0;
      uStack_58 = 0;
      uVar3 = FUN_011ccc04(param_1,param_5,&uStack_68);
      if ((uVar3 & 1) != 0) {
        FUN_011cdfd0(param_1,param_6,apuStack_80);
        FUN_011ce9e0();
        (**(code **)(*param_3 + 0x80))(param_3,&lStack_50,&uStack_68,apuStack_80,param_7);
        FUN_011cdfc4();
        if ((extraout_x8 & 1) != 0) {
          FUN_008cee58(uStack_70,(ulong)apuStack_80[0] & 0xfffffffffffffffe);
        }
      }
      apuStack_80[0] = &uStack_68;
      FUN_008e34e8(apuStack_80);
    }
    lVar2 = lStack_48;
    lVar1 = lStack_50;
    if (lStack_50 != 0) {
      while (lVar2 != lVar1) {
        FUN_00f7f2e4();
        if ((extraout_w9 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(extraout_x8_00 + -8),
                       *(ulong *)(extraout_x8_00 + -0x18) & 0xfffffffffffffffe);
        }
      }
      lStack_48 = lVar1;
      FUN_008cee58(lStack_50,lStack_40 - lStack_50);
    }
  }
  FUN_011cdf84();
  return;
}


// calls FUN_011cdfd0 @ 011cdfd0
// calls FUN_008cee58 @ 008cee58
// calls FUN_011ccc04 @ 011ccc04
// calls FUN_00f7f2e4 @ 00f7f2e4
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdfc4 @ 011cdfc4
// calls FUN_008e34e8 @ 008e34e8
// calls FUN_011ccb04 @ 011ccb04
// calls FUN_011cdf84 @ 011cdf84
// nativeDecreaseCount (J[Ljava/lang/String;Ljava/lang/String;I)Z -> 011cd1d4

/* === nativeDecreaseCount (J[Ljava/lang/String;Ljava/lang/String;I)Z | JNI_nativeDecreaseCount @ 011cd1d4 size=244 === */

void JNI_nativeDecreaseCount
               (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong extraout_x8;
  long extraout_x8_00;
  uint extraout_w9;
  ulong auStack_60 [2];
  undefined8 uStack_50;
  long lStack_48;
  long lStack_40;
  long lStack_38;
  undefined8 uStack_28;
  
  uStack_28 = param_4;
  if (param_3 == (long *)0x0) {
    param_6 = 0;
  }
  else {
    lStack_48 = 0;
    lStack_40 = 0;
    lStack_38 = 0;
    uVar3 = FUN_011ccb04(param_1,&uStack_28,&lStack_48);
    if ((uVar3 & 1) == 0) {
      param_6 = 0;
    }
    else {
      FUN_011cdfd0(param_1,param_5,auStack_60);
      FUN_011ce9e0();
      (**(code **)(*param_3 + 0x88))(param_3,&lStack_48,auStack_60,param_6);
      FUN_011cdfc4();
      if ((extraout_x8 & 1) != 0) {
        FUN_008cee58(uStack_50,auStack_60[0] & 0xfffffffffffffffe);
      }
    }
    lVar2 = lStack_40;
    lVar1 = lStack_48;
    if (lStack_48 != 0) {
      while (lVar2 != lVar1) {
        FUN_00f7f2e4();
        if ((extraout_w9 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(extraout_x8_00 + -8),
                       *(ulong *)(extraout_x8_00 + -0x18) & 0xfffffffffffffffe);
        }
      }
      lStack_40 = lVar1;
      FUN_008cee58(lStack_48,lStack_38 - lStack_48);
    }
  }
  FUN_00ba57d8(param_6);
  return;
}


// calls FUN_011cdfd0 @ 011cdfd0
// calls FUN_008cee58 @ 008cee58
// calls FUN_00ba57d8 @ 00ba57d8
// calls FUN_00f7f2e4 @ 00f7f2e4
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdfc4 @ 011cdfc4
// calls FUN_011ccb04 @ 011ccb04
// nativeMarkAsUnmodified (J[Ljava/lang/String;[ILjava/lang/String;)Z -> 011cd2c8

/* === nativeMarkAsUnmodified (J[Ljava/lang/String;[ILjava/lang/String;)Z | JNI_nativeMarkAsUnmodified @ 011cd2c8 size=240 === */

void JNI_nativeMarkAsUnmodified
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  ulong uVar2;
  long extraout_x8;
  ulong extraout_x8_00;
  long extraout_x8_01;
  uint extraout_w9;
  undefined1 auVar3 [16];
  undefined8 *apuStack_78 [2];
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  long lStack_48;
  long lStack_40;
  long lStack_38;
  undefined8 uStack_28;
  
  uStack_28 = param_4;
  if (param_3 != 0) {
    FUN_011cdf50(param_1,&uStack_28,&lStack_48);
    uVar2 = FUN_011ccb04();
    if ((uVar2 & 1) != 0) {
      FUN_011cdf94();
      uStack_60 = 0;
      uStack_58 = 0;
      uStack_50 = 0;
      auVar3 = FUN_011ccc04();
      if ((auVar3._0_8_ & 1) != 0) {
        FUN_00bc2770(auVar3._0_8_,auVar3._8_8_,apuStack_78);
        FUN_011cdf18();
        FUN_011ce9e0();
        FUN_011cdef0();
        (**(code **)(extraout_x8 + 0x90))();
        FUN_011cdf68();
        if ((extraout_x8_00 & 1) != 0) {
          FUN_008cee58(uStack_68,(ulong)apuStack_78[0] & 0xfffffffffffffffe);
        }
      }
      apuStack_78[0] = &uStack_60;
      FUN_008e34e8(apuStack_78);
    }
    lVar1 = lStack_48;
    if (lStack_48 != 0) {
      while (lStack_40 != lVar1) {
        FUN_00f7f2e4();
        if ((extraout_w9 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(extraout_x8_01 + -8),
                       *(ulong *)(extraout_x8_01 + -0x18) & 0xfffffffffffffffe);
        }
      }
      lStack_40 = lVar1;
      FUN_008cee58(lStack_48,lStack_38 - lStack_48);
    }
  }
  FUN_011cdf84();
  return;
}


// calls FUN_008cee58 @ 008cee58
// calls FUN_011cdef0 @ 011cdef0
// calls FUN_00f7f2e4 @ 00f7f2e4
// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdf94 @ 011cdf94
// calls FUN_011ccb04 @ 011ccb04
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf84 @ 011cdf84
// calls FUN_011ccc04 @ 011ccc04
// calls FUN_011cdf50 @ 011cdf50
// calls FUN_008e34e8 @ 008e34e8
// calls FUN_011cdf68 @ 011cdf68
// nativeMarkAsUnmodified (J[Ljava/lang/String;Ljava/lang/String;)Z -> 011cd3b8

/* === nativeMarkAsUnmodified (J[Ljava/lang/String;Ljava/lang/String;)Z | JNI_nativeMarkAsUnmodified @ 011cd3b8 size=220 === */

ulong JNI_nativeMarkAsUnmodified
                (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  long lVar1;
  ulong extraout_x8;
  long extraout_x8_00;
  uint extraout_w9;
  undefined1 auVar2 [16];
  ulong auStack_58 [2];
  undefined8 uStack_48;
  long lStack_40;
  long lStack_38;
  long lStack_30;
  undefined8 uStack_28;
  
  if (param_3 != (long *)0x0) {
    uStack_28 = param_4;
    FUN_011cdfb8(param_1,&uStack_28,&lStack_40);
    auVar2 = FUN_011ccb04();
    if ((auVar2._0_8_ & 1) == 0) {
      param_3 = (long *)0x0;
    }
    else {
      FUN_00bc2770(auVar2._0_8_,auVar2._8_8_,auStack_58);
      FUN_011cdf18();
      FUN_011ce9e0();
      (**(code **)(*param_3 + 0x98))(param_3,&lStack_40,auStack_58);
      FUN_011cdf68();
      if ((extraout_x8 & 1) != 0) {
        FUN_008cee58(uStack_48,auStack_58[0] & 0xfffffffffffffffe);
      }
    }
    lVar1 = lStack_40;
    if (lStack_40 != 0) {
      while (lStack_38 != lVar1) {
        FUN_00f7f2e4();
        if ((extraout_w9 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(extraout_x8_00 + -8),
                       *(ulong *)(extraout_x8_00 + -0x18) & 0xfffffffffffffffe);
        }
      }
      lStack_38 = lVar1;
      FUN_008cee58(lStack_40,lStack_30 - lStack_40);
    }
  }
  return (ulong)param_3 & 0xffffffff;
}


// calls FUN_008cee58 @ 008cee58
// calls FUN_00f7f2e4 @ 00f7f2e4
// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdfb8 @ 011cdfb8
// calls FUN_011ccb04 @ 011ccb04
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf68 @ 011cdf68
// nativeRemoveByTokenAndValue (J[Ljava/lang/String;[ILjava/lang/String;)Z -> 011cd494

/* === nativeRemoveByTokenAndValue (J[Ljava/lang/String;[ILjava/lang/String;)Z | JNI_nativeRemoveByTokenAndValue @ 011cd494 size=240 === */

void JNI_nativeRemoveByTokenAndValue
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  ulong uVar2;
  long extraout_x8;
  ulong extraout_x8_00;
  long extraout_x8_01;
  uint extraout_w9;
  undefined1 auVar3 [16];
  undefined8 *apuStack_78 [2];
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  long lStack_48;
  long lStack_40;
  long lStack_38;
  undefined8 uStack_28;
  
  uStack_28 = param_4;
  if (param_3 != 0) {
    FUN_011cdf50(param_1,&uStack_28,&lStack_48);
    uVar2 = FUN_011ccb04();
    if ((uVar2 & 1) != 0) {
      FUN_011cdf94();
      uStack_60 = 0;
      uStack_58 = 0;
      uStack_50 = 0;
      auVar3 = FUN_011ccc04();
      if ((auVar3._0_8_ & 1) != 0) {
        FUN_00bc2770(auVar3._0_8_,auVar3._8_8_,apuStack_78);
        FUN_011cdf18();
        FUN_011ce9e0();
        FUN_011cdef0();
        (**(code **)(extraout_x8 + 0xa0))();
        FUN_011cdf68();
        if ((extraout_x8_00 & 1) != 0) {
          FUN_008cee58(uStack_68,(ulong)apuStack_78[0] & 0xfffffffffffffffe);
        }
      }
      apuStack_78[0] = &uStack_60;
      FUN_008e34e8(apuStack_78);
    }
    lVar1 = lStack_48;
    if (lStack_48 != 0) {
      while (lStack_40 != lVar1) {
        FUN_00f7f2e4();
        if ((extraout_w9 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(extraout_x8_01 + -8),
                       *(ulong *)(extraout_x8_01 + -0x18) & 0xfffffffffffffffe);
        }
      }
      lStack_40 = lVar1;
      FUN_008cee58(lStack_48,lStack_38 - lStack_48);
    }
  }
  FUN_011cdf84();
  return;
}


// calls FUN_008cee58 @ 008cee58
// calls FUN_011cdef0 @ 011cdef0
// calls FUN_00f7f2e4 @ 00f7f2e4
// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdf94 @ 011cdf94
// calls FUN_011ccb04 @ 011ccb04
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf84 @ 011cdf84
// calls FUN_011ccc04 @ 011ccc04
// calls FUN_011cdf50 @ 011cdf50
// calls FUN_008e34e8 @ 008e34e8
// calls FUN_011cdf68 @ 011cdf68
// nativeRemoveByTokenAndValue (J[Ljava/lang/String;Ljava/lang/String;)Z -> 011cd584

/* === nativeRemoveByTokenAndValue (J[Ljava/lang/String;Ljava/lang/String;)Z | JNI_nativeRemoveByTokenAndValue @ 011cd584 size=220 === */

ulong JNI_nativeRemoveByTokenAndValue
                (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  long lVar1;
  ulong extraout_x8;
  long extraout_x8_00;
  uint extraout_w9;
  undefined1 auVar2 [16];
  ulong auStack_58 [2];
  undefined8 uStack_48;
  long lStack_40;
  long lStack_38;
  long lStack_30;
  undefined8 uStack_28;
  
  if (param_3 != (long *)0x0) {
    uStack_28 = param_4;
    FUN_011cdfb8(param_1,&uStack_28,&lStack_40);
    auVar2 = FUN_011ccb04();
    if ((auVar2._0_8_ & 1) == 0) {
      param_3 = (long *)0x0;
    }
    else {
      FUN_00bc2770(auVar2._0_8_,auVar2._8_8_,auStack_58);
      FUN_011cdf18();
      FUN_011ce9e0();
      (**(code **)(*param_3 + 0xa8))(param_3,&lStack_40,auStack_58);
      FUN_011cdf68();
      if ((extraout_x8 & 1) != 0) {
        FUN_008cee58(uStack_48,auStack_58[0] & 0xfffffffffffffffe);
      }
    }
    lVar1 = lStack_40;
    if (lStack_40 != 0) {
      while (lStack_38 != lVar1) {
        FUN_00f7f2e4();
        if ((extraout_w9 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(extraout_x8_00 + -8),
                       *(ulong *)(extraout_x8_00 + -0x18) & 0xfffffffffffffffe);
        }
      }
      lStack_38 = lVar1;
      FUN_008cee58(lStack_40,lStack_30 - lStack_40);
    }
  }
  return (ulong)param_3 & 0xffffffff;
}


// calls FUN_008cee58 @ 008cee58
// calls FUN_00f7f2e4 @ 00f7f2e4
// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdfb8 @ 011cdfb8
// calls FUN_011ccb04 @ 011ccb04
// calls FUN_00bc2770 @ 00bc2770
// calls FUN_011cdf68 @ 011cdf68
// nativeRemoveByValue (JLjava/lang/String;)Z -> 011cd660

/* === nativeRemoveByValue (JLjava/lang/String;)Z | JNI_nativeRemoveByValue @ 011cd660 size=88 === */

ulong JNI_nativeRemoveByValue(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  long extraout_x8;
  ulong extraout_x8_00;
  ulong uStack_28;
  undefined8 uStack_18;
  
  if (param_3 != 0) {
    FUN_011cdfac();
    FUN_011cdf18();
    FUN_011ce9e0();
    FUN_011cdf08();
    (**(code **)(extraout_x8 + 0xb0))();
    FUN_011cdf68();
    if ((extraout_x8_00 & 1) != 0) {
      FUN_008cee58(uStack_18,uStack_28 & 0xfffffffffffffffe);
    }
  }
  return param_3 & 0xffffffff;
}


// calls FUN_011cdfac @ 011cdfac
// calls FUN_008cee58 @ 008cee58
// calls FUN_011cdf18 @ 011cdf18
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_011cdf08 @ 011cdf08
// calls FUN_011cdf68 @ 011cdf68
// nativeClear (J)Z -> 011cd6b8

/* === nativeClear (J)Z | JNI_nativeClear @ 011cd6b8 size=52 === */

ulong JNI_nativeClear(undefined8 param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_3 == (long *)0x0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  uVar1 = (**(code **)(*param_3 + 0xb8))(param_3);
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// nativeDuplicateDictionary (J)Z -> 011cd6ec

/* === nativeDuplicateDictionary (J)Z | JNI_nativeDuplicateDictionary @ 011cd6ec size=52 === */

ulong JNI_nativeDuplicateDictionary(undefined8 param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_3 == (long *)0x0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  uVar1 = (**(code **)(*param_3 + 0xc0))(param_3);
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// nativeNewEmptyDictionary (J)Z -> 011cd720

/* === nativeNewEmptyDictionary (J)Z | JNI_nativeNewEmptyDictionary @ 011cd720 size=52 === */

ulong JNI_nativeNewEmptyDictionary(undefined8 param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_3 == (long *)0x0) {
    uVar2 = FUN_00b3477c();
    return uVar2;
  }
  uVar1 = (**(code **)(*param_3 + 200))(param_3);
  return (ulong)(uVar1 & 1);
}


// calls FUN_00b3477c @ 00b3477c
// nativeClose (J)V -> 00b0cf20
// nativeStartProfiling ()V -> 008d0438

/* === nativeStartProfiling ()V | FUN_008d0438 @ 008d0438 size=8 === */

void FUN_008d0438(void)

{
  return;
}


// nativeStopProfiling ()V -> 008d0438
// nativeCreate (JJLjava/lang/String;Ljava/lang/String;)J -> 011ce1e8

/* === nativeCreate (JJLjava/lang/String;Ljava/lang/String;)J | JNI_nativeCreate @ 011ce1e8 size=232 === */

undefined8
JNI_nativeCreate(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  bool bVar5;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  ulong uStack_58;
  long lStack_50;
  undefined8 uStack_48;
  ulong uStack_40;
  long lStack_38;
  
  uStack_48 = 0;
  uStack_40 = 0;
  lStack_38 = 0;
  FUN_011ce9e0(param_1,param_5,&uStack_48);
  uStack_60 = 0;
  uStack_58 = 0;
  lStack_50 = 0;
  FUN_011ce9e0(param_1,param_6,&uStack_60);
  bVar5 = (uStack_48 & 1) == 0;
  lVar3 = lStack_38;
  if (bVar5) {
    lVar3 = (long)&uStack_48 + 1;
  }
  uVar1 = uStack_40;
  if (bVar5) {
    uVar1 = uStack_48 >> 1 & 0x7f;
  }
  uVar2 = uStack_58;
  lVar4 = lStack_50;
  if ((uStack_60 & 1) == 0) {
    lVar4 = (long)&uStack_60 + 1;
    uVar2 = uStack_60 >> 1 & 0x7f;
  }
  uStack_70 = param_3;
  uStack_68 = param_4;
  FUN_011cedb8(&uStack_78,&uStack_70,lVar3,uVar1,lVar4,uVar2);
  if ((uStack_60 & 1) != 0) {
    FUN_008cee58(lStack_50,uStack_60 & 0xfffffffffffffffe);
  }
  if ((uStack_48 & 1) != 0) {
    FUN_008cee58(lStack_38,uStack_48 & 0xfffffffffffffffe);
  }
  return uStack_78;
}


// calls FUN_011cedb8 @ 011cedb8
// calls FUN_008cee58 @ 008cee58
// calls FUN_011ce9e0 @ 011ce9e0
// nativeRelease (J)V -> 00b0cf20
// nativeReset (J)V -> 011ce2e4

/* === nativeReset (J)V | JNI_nativeReset @ 011ce2e4 size=20 === */

void JNI_nativeReset(undefined8 param_1,undefined8 param_2,long *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x011ce2f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 0x48))(param_3);
  return;
}


// nativeReloadOnDataOrSettingChanged (J)V -> 011ce2d0

/* === nativeReloadOnDataOrSettingChanged (J)V | JNI_nativeReloadOnDataOrSettingChanged @ 011ce2d0 size=20 === */

void JNI_nativeReloadOnDataOrSettingChanged(undefined8 param_1,undefined8 param_2,long *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x011ce2e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_3 + 0x10))(param_3);
  return;
}


// nativeDecode (J[B)J -> 011ce458

/* === nativeDecode (J[B)J | JNI_nativeDecode @ 011ce458 size=344 === */

undefined8 * JNI_nativeDecode(long *param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  undefined7 *puVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 *puVar5;
  byte bStack_88;
  undefined7 uStack_87;
  ulong uStack_80;
  undefined7 *puStack_78;
  undefined1 auStack_70 [48];
  undefined1 uStack_31;
  
  iVar2 = (**(code **)(*param_1 + 0x558))(param_1,param_4);
  lVar3 = (**(code **)(*param_1 + 0x6f0))(param_1,param_4,&uStack_31);
  puVar5 = (undefined8 *)0x0;
  if ((iVar2 != 0) && (lVar3 != 0)) {
    FUN_00942c04(auStack_70,0);
    FUN_00905438(&bStack_88,lVar3,(long)iVar2);
    puVar1 = puStack_78;
    if ((bStack_88 & 1) == 0) {
      puVar1 = &uStack_87;
      uStack_80 = (ulong)(bStack_88 >> 1);
    }
    uVar4 = FUN_00a56040(auStack_70,puVar1,uStack_80);
    if ((bStack_88 & 1) != 0) {
      FUN_008cee58(puStack_78,CONCAT71(uStack_87,bStack_88) & 0xfffffffffffffffe);
    }
    if ((uVar4 & 1) == 0) {
      (**(code **)(*param_1 + 0x6f8))(param_1,param_4,lVar3,0);
      puVar5 = (undefined8 *)0x0;
    }
    else {
      puVar5 = (undefined8 *)FUN_020543f8(0x18);
      puVar5[1] = 0;
      puVar5[2] = 0;
      *puVar5 = 0;
      (**(code **)(*param_3 + 0x28))(param_3,auStack_70,puVar5);
      (**(code **)(*param_1 + 0x6f8))(param_1,param_4,lVar3,0);
    }
    FUN_00f2ae1c(auStack_70);
  }
  return puVar5;
}


// calls FUN_008cee58 @ 008cee58
// calls FUN_020543f8 @ 020543f8
// calls FUN_00942c04 @ 00942c04
// calls FUN_00f2ae1c @ 00f2ae1c
// calls FUN_00905438 @ 00905438
// calls FUN_00a56040 @ 00a56040
// nativeGetFilteredResults (J[Ljava/lang/String;)J -> 011ce2f8

/* === nativeGetFilteredResults (J[Ljava/lang/String;)J | JNI_nativeGetFilteredResults @ 011ce2f8 size=352 === */

long * JNI_nativeGetFilteredResults(long *param_1,undefined8 param_2,long *param_3,long param_4)

{
  byte *pbVar1;
  uint uVar2;
  undefined8 uVar3;
  long *plVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  long *plStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  byte *pbStack_48;
  byte *pbStack_40;
  long lStack_38;
  
  plVar4 = (long *)0x0;
  if (param_4 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x558))(param_1,param_4);
    pbStack_48 = (byte *)0x0;
    pbStack_40 = (byte *)0x0;
    lStack_38 = 0;
    for (uVar7 = 0; (uVar2 & ((int)uVar2 >> 0x1f ^ 0xffffffffU)) != uVar7; uVar7 = uVar7 + 1) {
      plStack_60 = (long *)0x0;
      uStack_58 = 0;
      uStack_50 = 0;
      uVar3 = (**(code **)(*param_1 + 0x568))(param_1,param_4,uVar7);
      FUN_011ce9e0(param_1,uVar3,&plStack_60);
      FUN_00a88acc(&pbStack_48,&plStack_60);
      if (((ulong)plStack_60 & 1) != 0) {
        FUN_008cee58(uStack_50,(ulong)plStack_60 & 0xfffffffffffffffe);
      }
    }
    plVar4 = (long *)FUN_020543f8(0x18);
    plVar4[1] = 0;
    plVar4[2] = 0;
    *plVar4 = 0;
    (**(code **)(*param_3 + 0x50))(param_3,&pbStack_48,plVar4);
    if (*plVar4 == plVar4[1]) {
      plStack_60 = plVar4;
      FUN_011cdd08(&plStack_60);
      FUN_008cee58(plVar4,0x18);
      plVar4 = (long *)0x0;
    }
    pbVar1 = pbStack_48;
    if (pbStack_48 != (byte *)0x0) {
      pbVar6 = pbStack_40;
      while (pbVar5 = pbVar6, pbVar5 != pbVar1) {
        pbVar6 = pbVar5 + -0x18;
        if ((*pbVar6 & 1) != 0) {
          FUN_008cee58(*(undefined8 *)(pbVar5 + -8),*(ulong *)(pbVar5 + -0x18) & 0xfffffffffffffffe)
          ;
        }
      }
      pbStack_40 = pbVar1;
      FUN_008cee58(pbStack_48,lStack_38 - (long)pbStack_48);
    }
  }
  return plVar4;
}


// calls FUN_008cee58 @ 008cee58
// calls FUN_011cdd08 @ 011cdd08
// calls FUN_020543f8 @ 020543f8
// calls FUN_011ce9e0 @ 011ce9e0
// calls FUN_00a88acc @ 00a88acc
// nativeSetKeyboardLayout (JI[B)Z -> 011ce5b0

/* === nativeSetKeyboardLayout (JI[B)Z | JNI_nativeSetKeyboardLayout @ 011ce5b0 size=312 === */

bool JNI_nativeSetKeyboardLayout
               (long *param_1,undefined8 param_2,long *param_3,undefined4 param_4,undefined8 param_5
               )

{
  undefined7 *puVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  bool bVar5;
  byte bStack_110;
  undefined7 uStack_10f;
  ulong uStack_108;
  undefined7 *puStack_100;
  undefined1 auStack_f8 [168];
  undefined1 uStack_41;
  
  iVar2 = (**(code **)(*param_1 + 0x558))(param_1,param_5);
  lVar3 = (**(code **)(*param_1 + 0x6f0))(param_1,param_5,&uStack_41);
  bVar5 = false;
  if ((iVar2 != 0) && (lVar3 != 0)) {
    FUN_009b4790(auStack_f8,0);
    FUN_00905438(&bStack_110,lVar3,(long)iVar2);
    puVar1 = puStack_100;
    if ((bStack_110 & 1) == 0) {
      puVar1 = &uStack_10f;
      uStack_108 = (ulong)(bStack_110 >> 1);
    }
    uVar4 = FUN_00a56040(auStack_f8,puVar1,uStack_108);
    if ((bStack_110 & 1) != 0) {
      FUN_008cee58(puStack_100,CONCAT71(uStack_10f,bStack_110) & 0xfffffffffffffffe);
    }
    bVar5 = (uVar4 & 1) != 0;
    if (bVar5) {
      (**(code **)(*param_3 + 0x20))(param_3,param_4,auStack_f8);
    }
    (**(code **)(*param_1 + 0x6f8))(param_1,param_5,lVar3,0);
    FUN_009d8a58(auStack_f8);
  }
  return bVar5;
}


// calls FUN_008cee58 @ 008cee58
// calls FUN_00905438 @ 00905438
// calls FUN_009b4790 @ 009b4790
// calls FUN_009d8a58 @ 009d8a58
// calls FUN_00a56040 @ 00a56040
// table entries: 136, dumped: 131
