/******************************************************************************/
/* File   : CfgMcalFls.c                                                      */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"

#include "CfgMcalFls.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
const Type_McalFls_stInfoBlock CfgMcalFls_astTableInfoBlock[] = {
      {0x00000000uL, 0x00001FFFuL} /*  Flash Bank A Block0     ( 8KB)                          */
   ,  {0x00002000uL, 0x00003FFFuL} /*  Flash Bank A Block1     ( 8KB)                          */
   ,  {0x00004000uL, 0x00005FFFuL} /*  Flash Bank A Block2     ( 8KB)                          */
   ,  {0x00006000uL, 0x00007FFFuL} /*  Flash Bank A Block3     ( 8KB)                          */
   ,  {0x00008000uL, 0x00009FFFuL} /*  Flash Bank A Block4     ( 8KB)                          */
   ,  {0x0000A000uL, 0x0000BFFFuL} /*  Flash Bank A Block5     ( 8KB)                          */
   ,  {0x0000C000uL, 0x0000DFFFuL} /*  Flash Bank A Block6     ( 8KB)                          */
   ,  {0x0000E000uL, 0x0000FFFFuL} /*  Flash Bank A Block7     ( 8KB)                          */
   ,  {0x00010000uL, 0x00017FFFuL} /*  Flash Bank A Block8     (32KB)                          */
   ,  {0x00018000uL, 0x0001FFFFuL} /*  Flash Bank A Block9     (32KB)                          */
   ,  {0x00020000uL, 0x00027FFFuL} /*  Flash Bank A Block10    (32KB) Reserved for Application */
   ,  {0x00028000uL, 0x0002FFFFuL} /*  Flash Bank A Block11    (32KB) Reserved for Application */
   ,  {0x00030000uL, 0x00037FFFuL} /*  Flash Bank A Block12    (32KB) Reserved for Application */
   ,  {0x00038000uL, 0x0003FFFFuL} /*  Flash Bank A Block13    (32KB) Reserved for Application */
   ,  {0x00040000uL, 0x00047FFFuL} /*  Flash Bank A Block14    (32KB) Reserved for Application */
   ,  {0x00048000uL, 0x0004FFFFuL} /*  Flash Bank A Block15    (32KB) Reserved for Application */
   ,  {0x00050000uL, 0x0005FFFFuL} /*  Flash Bank A Block16-17 (64KB) Reserved for Application */
   ,  {0x00060000uL, 0x0006FFFFuL} /*  Flash Bank A Block18-19 (64KB) Reserved for Application */
   ,  {0x00070000uL, 0x00077FFFuL} /*  Flash Bank A Block20-21 (32KB) Reserved for Application */
   ,  {0x00078000uL, 0x0007EFFFuL} /*  Flash Bank A Block22-23 (28KB) Reserved for Adlatus     */
   ,  {0x0007F000uL, 0x0007FFFFuL} /*  Flash Bank A Block24-25 ( 4KB) Unused                   */
   ,  {0x00080000uL, 0x0008FFFFuL} /*  Flash Bank A Block26-27 (64KB)                          */
   ,  {0x00090000uL, 0x0009FFFFuL} /*  Flash Bank A Block28-29 (64KB)                          */
   ,  {0x000C0000uL, 0x000CFFFFuL} /*  Flash Bank A Block30-31 (64KB)                          */
   ,  {0x000D0000uL, 0x000DFFFFuL} /*  Flash Bank A Block32-33 (64KB)                          */
   ,  {0x000E0000uL, 0x000EFFFFuL} /*  Flash Bank A Block34-35 (64KB)                          */
   ,  {0x000F0000uL, 0x000FFFFFuL} /*  Flash Bank A Block36-37 (64KB)                          */
   ,  {0x01000000uL, 0x01007FFFuL} /*  Extended User Area      (32KB)                          */
};

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
