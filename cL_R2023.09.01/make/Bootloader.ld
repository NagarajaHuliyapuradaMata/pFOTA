MEMORY {
  /* ROM / FLASH */
  iVect           : ORIGIN = 0x00000000, LENGTH = 0x300
  iBMHeader       : ORIGIN = 0x00000300, LENGTH = 0x60
  iFbl            : ORIGIN = 0x00000360, LENGTH = 0x20000-0x360-0x100-0x2800
  iFlashDrvRom    : ORIGIN = 0x0001D700, LENGTH = 0x2800   /* Flash driver im Rom */
  iFblDescBlock   : ORIGIN = 0x0001FF00, LENGTH = 0x100    /* 256 bytes for RAJA Bootloader descriptor block */
  iApplBMHeaderHdr: ORIGIN = 0x00020000, LENGTH = 0x100
  iAppl           : ORIGIN = 0x00020100, LENGTH = 0x57B00  /* application 20100-77C00 */
  iPresencePat    : ORIGIN = 0x00077C00, LENGTH = 0x400    /* FBL writes Presence Patterns here */
  iROM_DATA       : ORIGIN = 0xFF200000, LENGTH = 0x800    /* 2k data flash for BH-SENS production data  */
  /* RAM */
  iFlashDrv       : ORIGIN = 0xFEDF8000, LENGTH = 0x2800
  iEeprom         : ORIGIN = 0xFEDFA800, LENGTH = 0x00000300
  MAGICFL         : ORIGIN = 0xFEDFAB00, LENGTH = 0x00000010
  iRAM2           : ORIGIN = 0xFEDFAB10, LENGTH = 0x000004F0
  iStack          : ORIGIN = 0xFEDFB000, LENGTH = 0x00001000
  iRAM            : ORIGIN = 0xFEDFC000, LENGTH = 0x0000BFE0  /* !! search for 0xFEDFC000 before changing here!!  */
  RRAM            : ORIGIN = 0xFEE07FE0, LENGTH = 0x00000010  /* -1008 Bytes retention RAM for standstill monitoring */
  RRAM_WUF        : ORIGIN = 0xFEE07FF0, LENGTH = 0x00000010  /* -16 Bytes for a copy of the Wakeup Factor register */
}

SECTIONS {
  /********************************************************************************************************************/
  /* ROM AREA (iROM_0A)*/
  /********************************************************************************************************************/
  .rom_start                                                :>iVect /* Start of code area */
  .intvect  0x00                 :>. /* start of Core interrupt vector table, from BRS */
  .intvect_ExtExceptions   0x200     :>. /* start of External interrupt vector table, from BRS */
  .FBLBMHEADER                                              :>iBMHeader  /* Bootmanager header table */
  .FBLBMHEADERHDR                                           :>.          /* Bootmanager header header table */
  .FBLHEADER                                                :>iFbl
  .startup .: {
    BrsStartup_c0.o(.text)
  } >.

  /* START OF CODE AREA */
  .text                  align(4)         :>. /* program code area */
  .R_FDL_Text            align(4)         :>. /* FDL code in ROM (used by MCAL) */
  /* END OF CODE AREA */

  /* START OF CONST AREA */
  .rozdata                                :>. /* constant datas in ZDA area */
  .robase                align(4)         :>. /* initialize textpointer TP for SDA addressing */
/*.rosdata               align(4)         :>.    constant datas in SDA area */
  .rodata                align(4)         :>. /* constant datas in normal area */
  .R_FDL_Const           align(4)         :>. /* constant datas for DrvFls */
  /* END OF CONST AREA */

  .fixaddr               align(4)         :>. /* ghs internal (compiler) */
  .fixtype               align(4)         :>. /* ghs internal (compiler) */
  .secinfo               align(4)         :>. /* ghs internal (runtime library) */
  .syscall               align(4)         :>. /* ghs internal (linker) */

  .ROM.rosdata  align(4) ROM(.rosdata)    :>. /* ROM copy to initialize text in rosdata area */
  .ROM.ramcopy  align(4) ROM(.ramcopy)    :>. /* ROM copy to initialize text in ramcopy area */
  .ROM.RAMCODE  align(4) ROM(.RAMCODE)    :>. /* ROM copy to initialize text in RAMCODE area */
  .ROM.RAMCONST align(4) ROM(.RAMCONST)   :>. /* ROM copy to initialize text in RAMCONST area */
  .romdata               ROM(.data)       :>. /* init values for .data (copied to RAM at startup) */
  .romzdata              ROM(.zdata)      :>. /* init values for .zdata (copied to RAM at startup) */
  .romsdata              ROM(.sdata)      :>. /* init values for .sdata (copied to RAM at startup) */
  .romtdata              ROM(.tdata)      :>. /* init values for .tdata (copied to RAM at startup) */
  .roFlashDrvRom         align(4)         :>iFlashDrvRom   /* -RST- Flashdriver location */
  .roFBL_METADATA        align(4)         :>iFblDescBlock  /* -RST- RAJA bootloader descriptor block */

  /********************************************************************************************************************/
  /* ROM AREA (iROM_1)*/                                                                                                
  /********************************************************************************************************************/
  .APPLVECT              align(4)         :>iAppl     /* alternative interrupt vector table position */
  .production_data       align(4)         :>iROM_DATA /* SUPPLIER1 production data area (data flash!) */


  /********************************************************************************************************************/
  /* RAM*/
  /********************************************************************************************************************/
  .ram_start                              :>iFlashDrv /* Start of RAM area of MasterCore */
  .FLASHDRV                align(4)       :>.         /* Space for FlashCode */
  .EEPDATA                 align(4)       :>iEeprom   /* Space Dummy EEPROM */
  .FBLMAGIC                align(4)       :>MAGICFL   /* Space for magic flag (Fbl Start feature) */
  .bss                     align(4) CLEAR :>iRAM2     /* zero initialized data */
  .stack                   align(4) pad(SIZEOF(iStack)) :>iStack /* definition of stack size */

  /* START OF NORMAL DATA RAM AREA */
  .data                  align(4)         :>iRAM      /* initialized data */
  .R_FDL_Data            align(4)         :>.         /* data for DrvFls */
  .rosdata               align(4)         :>.         /* constant data in SDA area */
  .ramcopy               align(4)         :           /* Initialized code segment in RAM */
  {
    PbCfgSwcServiceCanTp.o(.text)
    PbCfgSwcServicePduR.o(.text)
    PbCfgEcuabCanIf.o(.text)
    PbCfgMcalCan.o(.text)
    CfgSwcServiceCanTp.o(.text)
    CfgSwcServiceDet.o(.text)
    CfgSwcServicePduR.o(.text)
    CfgEcuabCanIf.o(.text)
    CfgMcalCan.o(.text)
    McalCan.o(.text)
    SwcServiceCanTp.o(.text)
    SwcServiceDet.o(.text)
    PduR_Bm.o(.text)
    PduR_Fm.o(.text)
    PduR_Lock.o(.text)
    PduR_McQ.o(.text)
    PduR_RmIf.o(.text)
    PduR_RmTp.o(.text)
    PduR_RmTp_TxInst.o(.text)
    PduR_Sm.o(.text)
    SwcServicePduR.o(.text)
    EcuabCanIf.o(.text)
    Can_Irq.o(.text)
    fbl_hw.o(.text)
    FblCw_Lcfg.o(.text)
    vstdlib.o(.text)
    CfgSwcServiceCanTp.o(.rosdata)
    CfgSwcServiceDet.o(.rosdata)
    CfgSwcServicePduR.o(.rosdata)
    CfgEcuabCanIf.o(.rosdata)
    CfgMcalCan.o(.rosdata)
    EcuabCanIf.o(.rosdata)
    McalCan.o (.rosdata)
  } >.
  .RAMCODE  align(4)                             :>.     /* RAM code  */
  .RAMCONST align(4)                             :>.     /* RAM const */
  /* END OF NORMAL DATA RAM AREA */

  /* START OF SDA RAM AREA */
  .sda_start                                     :>. /* start of SDA RAM area */
  .sdabase               align(4)                :>. /* initialize globalpointer GP for SDA addressing */
  .sdata                 align(4)                :>. /* initialized data in SDA area */
  .sbss                  align(4) CLEAR          :>. /* zero initialized data in SDA area */
  .sda_end                                       :>. /* end of SDA RAM area */
  /* END OF SDA RAM AREA */


  .zdata                 align(4)                :>. /* initialized data in ZDA area */
  .zbss                  align(4) CLEAR          :>. /* zero initialized data in ZDA area */
  .tdata                 align(4) MAX_SIZE(256)  :>. /* initialized and zero-initialized data in TDA area */

  /* START OF RETENTION RAM AREA FOR STANDSTILL MONITORING */
  .rdata    align(4)                             :>RRAM
  .rwufcopy align(4)                             :>RRAM_WUF

  .ram_end               align(16)               :>.

  _VECTORTABLE_START_ADDR    = ADDR(.intvect_ExtExceptions);
  _EXCEPTIONTABLE_START_ADDR = ADDR(.intvect);
}
