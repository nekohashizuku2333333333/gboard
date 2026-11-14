
/* ==== 0x11ee934 FUN_011ee934 @ 011ee934 size=112 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_011ee934(undefined8 *param_1)

{
  undefined *puVar1;
  long lVar2;
  long lVar3;
  undefined *puVar4;
  long *plVar5;
  
  *param_1 = &PTR_FUN_021003a8;
  plVar5 = (long *)FUN_020543f8(0x58);
  lVar3 = _UNK_002f4b18;
  lVar2 = ram0x002f4b10;
  puVar1 = PTR_DAT_022313e0 + 0x80;
  *plVar5 = (long)(PTR_DAT_022313e0 + 0x10);
  puVar4 = PTR_DAT_022313e8;
  plVar5[1] = (long)puVar1;
  plVar5[5] = 1;
  plVar5[3] = lVar3;
  plVar5[2] = lVar2;
  plVar5[7] = (long)(puVar4 + 0x10);
  plVar5[9] = lVar3;
  plVar5[8] = lVar2;
  param_1[1] = plVar5;
  return;
}


// calls FUN_020543f8 @ 020543f8

/* ==== 0x11cdfd0 FUN_011cdfd0 @ 011cdfd0 size=12 ==== */

void FUN_011cdfd0(void)

{
  return;
}



/* ==== 0x11cdfdc FUN_011cdfdc @ 011cdfdc size=12 ==== */

void FUN_011cdfdc(void)

{
  return;
}



/* ==== 0x11ce9e0 FUN_011ce9e0 @ 011ce9e0 size=316 ==== */

void FUN_011ce9e0(long *param_1,long param_2,byte *param_3)

{
  ulong uVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  byte *pbVar6;
  ulong uVar7;
  
  if ((param_2 == 0) || (iVar3 = (**(code **)(*param_1 + 0xd0))(param_1,2), iVar3 < 0)) {
    return;
  }
  uVar4 = FUN_011ceb1c(param_1,param_2,DAT_022a3450);
  lVar5 = (**(code **)(*param_1 + 0x78))(param_1);
  if (lVar5 == 0) {
    iVar3 = (**(code **)(*param_1 + 0x558))(param_1,uVar4);
    bVar2 = *param_3;
    uVar7 = (ulong)iVar3;
    uVar1 = *(ulong *)(param_3 + 8);
    if ((bVar2 & 1) == 0) {
      uVar1 = (ulong)(bVar2 >> 1);
    }
    if (uVar7 < uVar1 || uVar7 - uVar1 == 0) {
      if ((bVar2 & 1) == 0) {
        pbVar6 = param_3 + 1;
        *param_3 = (byte)(iVar3 << 1);
      }
      else {
        pbVar6 = *(byte **)(param_3 + 0x10);
        *(ulong *)(param_3 + 8) = uVar7;
      }
      pbVar6[uVar7] = 0;
    }
    else {
      FUN_009cbcfc(param_3,uVar7 - uVar1,0);
    }
    pbVar6 = *(byte **)(param_3 + 0x10);
    if ((*param_3 & 1) == 0) {
      pbVar6 = param_3 + 1;
    }
    (**(code **)(*param_1 + 0x640))(param_1,uVar4,0,iVar3,pbVar6);
  }
  else {
    (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
  }
                    /* WARNING: Could not recover jumptable at 0x011ceb18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xb8))(param_1,uVar4);
  return;
}


// calls FUN_011ceb1c @ 011ceb1c
// calls FUN_009cbcfc @ 009cbcfc

/* ==== 0x11cdf74 FUN_011cdf74 @ 011cdf74 size=16 ==== */

undefined1  [16]
FUN_011cdf74(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined1 auVar1 [16];
  
  auVar1._8_4_ = param_4;
  auVar1._0_8_ = param_3;
  auVar1._12_4_ = 0;
  return auVar1;
}



/* ==== 0x11cdee0 FUN_011cdee0 @ 011cdee0 size=16 ==== */

undefined8 FUN_011cdee0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  return param_3;
}



/* ==== 0x11cde90 FUN_011cde90 @ 011cde90 size=32 ==== */

void FUN_011cde90(void)

{
  return;
}



/* ==== 0x11cda44 FUN_011cda44 @ 011cda44 size=116 ==== */

void FUN_011cda44(long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined1 auStack_80 [8];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined1 *local_50;
  undefined1 **ppuStack_48;
  undefined1 *puStack_40;
  undefined8 uStack_38;
  
  ppuStack_48 = &local_50;
  puStack_40 = auStack_80;
  uStack_38 = 0xffffff80ffffffd8;
  local_78 = param_4;
  uStack_70 = param_5;
  local_68 = param_6;
  uStack_60 = param_7;
  local_58 = param_8;
  local_50 = (undefined1 *)register0x00000008;
  (**(code **)(*param_1 + 0xe8))();
  return;
}


