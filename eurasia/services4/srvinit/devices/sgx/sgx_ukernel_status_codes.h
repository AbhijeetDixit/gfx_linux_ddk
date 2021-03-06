/*!****************************************************************************
@File           sgx_ukernel_status_codes.h

@Title          SGX microkernel debug status codes

@Author         Imagination Technologies

@Date           7th Feb 2008

@Copyright      Copyright 2003-2008 by Imagination Technologies Limited.
                All rights reserved. No part of this software, either material
                or conceptual may be copied or distributed, transmitted,
                transcribed, stored in a retrieval system or translated into
                any human or computer language in any form by any means,
                electronic, mechanical, manual or otherwise, or disclosed to
                third parties without the express written permission of
                Imagination Technologies Limited, Home Park Estate,
                Kings Langley, Hertfordshire, WD4 8LZ, U.K.

@Platform       Generic

@Description    SGX microkernel debug status codes

@DoxygenVer

******************************************************************************/

#if !defined (__SGX_UKERNEL_STATUS_CODES_H__)
#define __SGX_UKERNEL_STATUS_CODES_H__

/*
	It would be nice to put these definitions into an enumeration, but USEASM
	only has access to the C preprocessor so macros are required.
*/

/*
	Bits 24-31 of these codes (0xAD) are a magic number used to help
	distinguish between them and other debug information which can be
	optionally dumped into the status buffer, e.g. sync object values.
*/

/*
	Microkernel trace codes
*/
#define MKTC_EHEVENT_3DMEMFREE					0xAD000001
#define MKTC_EHEVENT_PIXELENDRENDER				0xAD000002
#define MKTC_EHEVENT_ISPBREAKPOINT				0xAD000004
#define MKTC_EHEVENT_TAFINISHED					0xAD000005
#define MKTC_EHEVENT_OUTOFMEM					0xAD000007
#define MKTC_EHEVENT_TATERMINATE				0xAD000008
#define MKTC_EHEVENT_TIMER						0xAD000009
#define MKTC_EHEVENT_SWEVENT					0xAD00000A
#if defined(SGX_FEATURE_2D_HARDWARE)
#define MKTC_EHEVENT_2DCOMPLETE					0xAD00000B
#endif

#define MKTC_3DEVENT_3DMEMFREE					0xAD000100
#define MKTC_3DEVENT_PIXELENDRENDER				0xAD000101
#define MKTC_3DEVENT_ISPBREAKPOINT				0xAD000102
#define MKTC_3DEVENT_END						0xAD000104
#define MKTC_3DLB_3DMEMFREE						0xAD000180
#define MKTC_3DLB_PIXELENDRENDER				0xAD000181
#define MKTC_3DLB_ISPBREAKPOINT					0xAD000182
#define MKTC_3DLB_FIND3D						0xAD000183
#define MKTC_3DLB_END							0xAD000184

#define MKTC_TAEVENT_TAFINISHED					0xAD000200
#define MKTC_TAEVENT_END						0xAD000202
#define MKTC_TALB_TAFINISHED					0xAD000280
#define MKTC_TALB_FINDTA						0xAD000281
#define MKTC_TALB_END							0xAD000282

#define MKTC_CRRL_WRITEOPSBLOCKED				0xAD000300
#define MKTC_CRRL_READOPSBLOCKED				0xAD000301
#define MKTC_CRRL_FOUNDRENDER					0xAD000302
#define MKTC_CRRL_NORENDER						0xAD000303
#define MKTC_CRRL_TARC_DIFFERENT				0xAD000304
#if defined(FIX_HW_BRN_23378)
#define MKTC_FINDRENDER_BRN_23378				0xAD000308
#endif
#define MKTC_CRRL_BLOCKEDRC						0xAD000309
#define MKTC_CRRL_BLOCKEDRTDATA					0xAD00030A
#define MKTC_CRRL_CONTEXT_SUSPENDED				0xAD00030B
#define MKTC_CRRL_TAWAITINGFORMEM				0xAD00030C
#define MKTC_CRRL_TAOOMBUTPRIOINV				0xAD00030D
#define MKTC_CRRL_READOPS2BLOCKED				0xAD00030E

#define MKTC_KICKRENDER_START					0xAD000400
#define MKTC_KICKRENDER_OVERLAP					0xAD000401
#define MKTC_KICKRENDER_ISP_START				0xAD000402
#define MKTC_KICKRENDER_RESUME					0xAD000403
#define MKTC_KICKRENDER_CONFIG_REGION_HDRS		0xAD000404
#define MKTC_KICKRENDER_END						0xAD000408
#define MKTC_KICKRENDER_RENDERCONTEXT			0xAD000409
#define MKTC_KICKRENDER_RTDATA					0xAD00040A
#define MKTC_KICKRENDER_PID						0xAD00040B

#define MKTC_RENDERFINISHED_START				0xAD000500
#define MKTC_RF_START_NEXT_MT					0xAD000501
#define MKTC_RF_ALL_MTS_DONE					0xAD000502
#define MKTC_RENDERFINISHED_END					0xAD000503
#define MKTC_VISQUERY_START						0xAD000504
#define MKTC_VISQUERY_END						0xAD000505
#define MKTC_TRANSFERRENDERFINISHED_START		0xAD000508
#define MKTC_TRANSFERRENDERFINISHED_END			0xAD000509
#define MKTC_TRF_UPDATESTATUSVALS				0xAD00050A
#define MKTC_TRF_UPDATESTATUSVALS_DONE			0xAD00050B

#define MKTC_PIXELENDRENDER_START				0xAD000600
#define MKTC_PIXELENDRENDER_AFTERLOCK			0xAD000601
#define MKTC_PIXELENDRENDER_END					0xAD000602
#define MKTC_PIXELENDRENDER_TLQEND				0xAD000603

#define MKTC_3DMEMFREE_START					0xAD000700
#define MKTC_3DMEMFREE_AFTERLOCK				0xAD000701
#define MKTC_3DMEMFREE_TESTEOR					0xAD000702
#define MKTC_3DMEMFREE_END						0xAD000703

#define MKTC_KICKTA_START						0xAD000800
#define MKTC_KICKTA_OVERLAP						0xAD000801
#define MKTC_KICKTA_RESETCONTEXT				0xAD000802
#define MKTC_KICKTA_VDM_START					0xAD000803
#define MKTC_KICKTA_END							0xAD000804
#define MKTC_KICKTA_RENDERCONTEXT				0xAD000805
#define MKTC_KICKTA_RTDATA						0xAD000806
#define MKTC_KICKTA_RESET_VDMCSSTATUS			0xAD000807
#define MKTC_KICKTA_RESET_BUFFERS				0xAD000808
#define MKTC_KICKTA_PID							0xAD000809
#define MKTC_KICKTA_TACMD_DEBUG					0xAD00080A
#define MKTC_KICKTA_FREECONTEXT					0xAD00080B
#define MKTC_KICKTA_PIM_PATCHING				0xAD00080C

#define MKTC_KICKTA_CHKPT_START_DUMMY_CS		0xAD0008A1
#define MKTC_KICKTA_CHKPT_START_DUMMY_TAK		0xAD0008A2
#define MKTC_KICKTA_CHKPT_WAIT_FOR_DUMMY_KICK	0xAD0008A3
#define MKTC_KICKTA_CHKPT_WAIT_NEXT_CORE		0xAD0008A4
#define MKTC_KICKTA_CHKPT_RESET_COMPLETE		0xAD0008A5
#define MKTC_KICKTA_CHKPT_CHECK_SWITCH			0xAD0008A6

#define MKTC_HOSTKICK_START						0xAD000900
#define MKTC_HOSTKICK_END						0xAD000901
#define MKTC_HOSTKICK_PROCESS_QUEUES_END		0xAD000902
#if defined(SGX_FEATURE_2D_HARDWARE)
#define MKTC_HOSTKICK_2D						0xAD000903
#endif
#define MKTC_HOSTKICK_TRANSFER					0xAD000904
#define MKTC_HOSTKICK_TA						0xAD000905
#define MKTC_HOSTKICK_PROCESS_QUEUES			0xAD000906
#define MKTC_HOSTKICK_RESUME					0xAD000908
#define MKTC_HOSTKICK_POWEROFF					0xAD000909
#define MKTC_HOSTKICK_IDLE						0xAD00090A
#define MKTC_HOSTKICK_CTXSUSPEND				0xAD00090B
#define MKTC_HOSTKICK_CTXRESUME					0xAD00090C

#define MKTC_TIMER_POTENTIAL_TA_LOCKUP			0xAD000A00
#define MKTC_TIMER_POTENTIAL_3D_LOCKUP			0xAD000A01
#define MKTC_TIMER_CTAL_START					0xAD000A02
#define MKTC_TIMER_CTAL_END						0xAD000A03
#define MKTC_TIMER_C3DL_START					0xAD000A04
#define MKTC_TIMER_C3DL_END						0xAD000A05
#define MKTC_TIMER_LOCKUP						0xAD000A0A
#define MKTC_TIMER_NOT_TA_LOCKUP				0xAD000A0B
#define MKTC_TIMER_NOT_3D_LOCKUP				0xAD000A0C
#if defined(SGX_FEATURE_2D_HARDWARE)                               
#define MKTC_TIMER_2D_LOCKUP					0xAD000A0D
#define MKTC_TIMER_POTENTIAL_2D_LOCKUP			0xAD000A10
#define MKTC_TIMER_C2DL_START					0xAD000A11
#define MKTC_TIMER_C2DL_END						0xAD000A12
#define MKTC_TIMER_NOT_2D_LOCKUP				0xAD000A13
#endif
#if defined(FIX_HW_BRN_23055)
#define MKTC_TIMER_ABORTALL						0xAD000A0E
#endif /* defined(FIX_HW_BRN_23055) */
#define MKTC_TIMER_END							0xAD000A0F

#define MKTC_HWR_START							0xAD000B00
#define MKTC_HWR_END							0xAD000B01
#define MKTC_HWR_HKS							0xAD000B02
#define MKTC_HWR_PRL							0xAD000B03
#define MKTC_HWR_PRL_DP							0xAD000B04
#define MKTC_HWR_CRL							0xAD000B05
#define MKTC_HWR_CRL_DP							0xAD000B06
#define MKTC_HWR_TRL							0xAD000B07
#define MKTC_HWR_TRL_DP							0xAD000B08
#define MKTC_HWR_ISC							0xAD000B09
#define MKTC_HWR_2DL							0xAD000B0A

#define MKTC_URSV_START							0xAD000C00
#define MKTC_URSV_UPDATEWRITEOPS				0xAD000C01
#define MKTC_URSV_UPDATESTATUSVALS				0xAD000C03
#define MKTC_URSV_UPDATESTATUSVALS_DONE			0xAD000C04
#define MKTC_URSV_END							0xAD000C05

#define MKTC_STORETACONTEXT_START				0xAD000D00
#define MKTC_STORETACONTEXT_END					0xAD000D01
#define MKTC_LOADTACONTEXT_START				0xAD000D02
#define MKTC_LOADTACONTEXT_END					0xAD000D03
#define MKTC_STORE3DCONTEXT_START				0xAD000D04
#define MKTC_STORE3DCONTEXT_END					0xAD000D05
#define MKTC_LOAD3DCONTEXT_START				0xAD000D06
#define MKTC_LOAD3DCONTEXT_END					0xAD000D07

#define MKTC_FINDTA_POWERREQUEST				0xAD000E00
#define MKTC_FINDTA_TA3D_OVERLAP_BLOCKED		0xAD000E01
#define MKTC_FINDTA_RTDATA_RENDERING			0xAD000E02
#define MKTC_FINDTA_3DRC_DIFFERENT				0xAD000E03
#define MKTC_FINDTA_WRITEOPSBLOCKED				0xAD000E04
#define MKTC_FINDTA_READOPSBLOCKED				0xAD000E05
#if defined(FORCE_ENABLE_GROW_SHRINK) && defined(SUPPORT_PERCONTEXT_PB)
#define MKTC_FINDTA_RESIZE_PB					0xAD000E06
#define MKTC_FINDTA_RESIZE_PB_BLOCKED			0xAD000E07
#define MKTC_FINDTA_SHRINK_PB					0xAD000E08
#endif
#define	MKTC_FINDTA_TAPB_DIFFERENT				0xAD000E09
#define	MKTC_FINDTA_TACONTEXT_DIFFERENT			0xAD000E0A
#define MKTC_FINDTA_TA2D_OVERLAP_BLOCKED		0xAD000E0B
#define MKTC_FINDTA_CONTEXT_SUSPENDED			0xAD000E0C
#define MKTC_FINDTA_SRC_READOPSBLOCKED			0xAD000E0D
#define MKTC_FINDTA_SRC_WRITEOPSBLOCKED			0xAD000E0E
#define MKTC_FINDTA_READOPS2BLOCKED				0xAD000E0F

#define MKTC_CTRL_SRCREADOPSBLOCKED				0xAD000F00
#define MKTC_CTRL_SRCWRITEOPSBLOCKED			0xAD000F01
#define MKTC_CTRL_DSTREADOPSBLOCKED				0xAD000F02
#define MKTC_CTRL_DSTWRITEOPSBLOCKED			0xAD000F03
#define MKTC_CTRL_TARC_DIFFERENT				0xAD000F04
#define MKTC_CTRL_CONTEXT_SUSPENDED				0xAD000F05
#define MKTC_CTRL_SRCREADOPS2BLOCKED			0xAD000F06

#define MKTC_DPTA_START							0xAD001000
#define MKTC_DPTA_UPDATESTATUSVALS				0xAD001001
#define MKTC_DPTA_UPDATESTATUSVALS_DONE			0xAD001002
#define MKTC_DPTA_NORENDER						0xAD001003
#define MKTC_DPTA_MEMFREE						0xAD001004
#define MKTC_DPTA_INC_COMPLETECOUNT				0xAD001005

#define MKTC_INVALDC 							0xAD001100
#define MKTC_INVALPT 							0xAD001101
#define MKTC_INVALSLC							0xAD001102
#define MKTC_INVALDATA							0xAD001103

#define MKTC_RESTARTTA							0xAD001200
#define MKTC_CSABORTNONGBL						0xAD001201
#define MKTC_CSABORTALL							0xAD001202
#define MKTC_CSRENDERINPROGRESS					0xAD001203
#define MKTC_TATERMRENDERINPROGRESS				0xAD001204
#define MKTC_RESTARTTANORENDER					0xAD001205
#define MKTC_SPM_KICKRENDER						0xAD001206
#define MKTC_SPM_RESUME_ABORTCOMPLETE			0xAD001208
#define	MKTC_RESUMEVDM							0xAD001209
#if defined(FIX_HW_BRN_23055)
#define	MKTC_REMOVE_RESERVE_MEM					0xAD00120A
#define	MKTC_INCREASEZLSTHRESHOLD				0xAD00120B
#endif /* defined(FIX_HW_BRN_23055) */
#define MKTC_CSFORCEABORTALL					0xAD00120C

#define MKTC_DUMMY_DEPTH						0xAD00120D
#define MKTC_DUMMY_DEPTH_CS						0xAD00120E

#if defined(FIX_HW_BRN_23055)
#define MKTC_MTETE_OOM							0xAD00120F
#define	MKTC_MTETE_OOM_FIRST_STORE_REF			0xAD001210
#define MKTC_MERGE_STATE_TABLES					0xAD001211
#define MKTC_NO_PAGES_LEFT_FOR_23055			0xAD001212
#define MKTC_NO_STATE_MODS						0xAD001213
#define MKTC_FIND_MTE_PAGE_IN_STATE				0xAD001214
#define MKTC_MTE_PAGE_FOUND						0xAD001215
#define MKTC_MOVE_MTE_PAGE_TO_TA_STATE			0xAD001216
#define MKTC_MOVE_MTE_PAGE_TO_TA_STATE_END		0xAD001217
#define MKTC_ZERO_ZLS_THRESHOLD					0xAD001218
#define MKTC_RESTORE_ZLS_THRESHOLD				0xAD001219
#define MKTC_FIND_MTE_PAGE_IN_CSM				0xAD00121A
#define MKTC_REISSUE_MTE_PAGE					0xAD00121B
#define MKTC_REISSUE_MTE_PAGE_REQUIRED			0xAD00121C
#define MKTC_REISSUE_MTE_PAGE_END				0xAD00121D
#define MKTC_RESET_TE_PSG						0xAD00121E
#endif

#define MKTC_OOM_WRITEOPSBLOCKED				0xAD00121F
#define MKTC_OOM_READOPSBLOCKED					0xAD001220
#define MKTC_OOM_SRC_WRITEOPSBLOCKED			0xAD001221
#define MKTC_OOM_SRC_READOPSBLOCKED				0xAD001222
#if 1 // SPM_PAGE_INJECTION
#define MKTC_OOM_SPM_DEADLOCK					0xAD001223
#define MKTC_OOM_SPM_DEADLOCK_MEM_ADDED			0xAD001224
#endif
#if defined(FIX_HW_BRN_27311) && !defined(FIX_HW_BRN_23055)
#define MKTC_BRN27311_RESET						0xAD001225
#endif
#define	MKTC_SPM_INVALID_ZLSCONFIG				0xAD001226

#if defined(FIX_HW_BRN_29461) || \
	(!defined(FIX_HW_BRN_23055) && !defined(SGX_FEATURE_MP))
#define MKTC_OOM_TYPE_MT						0xAD00122A
#define MKTC_OOM_TYPE_GLOBAL					0xAD001230
#define MKTC_OOM_CAUSE_GBL_OOM					0xAD001231
#define MKTC_OOM_RESTORE_LIST_SIZE				0xAD001232

	#if defined(SGX_FEATURE_MP)
#define MKTC_CHECK_MTE_PAGE_REISSUE				0xAD001240
#define MKTC_CPRI_VALID_ENTRIES					0xAD001241
#define MKTC_CPRI_STORE_DPLIST					0xAD001242
#define MKTC_CPRI_STORE_OTPM_CSM				0xAD001243
#define MKTC_CPRI_ABORT_MT_IDX					0xAD001244
#define MKTC_CPRI_ABORT_CORE_IDX				0xAD001245
#define MKTC_CPRI_CSM_TABLE_DATA				0xAD001246
#define MKTC_CPRI_PIM_DATA						0xAD001247
#define MKTC_CPRI_DO_CIRCULAR_TEST				0xAD001248

#define MKTC_CPRI_WRITE_ENTRIES					0xAD001249
	#endif /* SGX_FEATURE_MP */
#endif

#if defined(FIX_HW_BRN_23055)
#define	MKTC_MTE_ENTRY_NOT_IN_ANY_LIST			0xAD001250
#endif

#if defined(FIX_HW_BRN_31562) && defined(SGX_FEATURE_MP)
#define	MKTC_SPMAC_IGNORE_TERMINATE				0xAD001251
#endif

#if defined(FIX_HW_BRN_31076)
#define MKTC_SPMAC_REQUEST_3D_TIMEOUT			0xAD001252
#define MKTC_SPMAC_3D_TIMEOUT_COMPLETE			0xAD001253
#endif
#define MKTC_OOM_READOPS2BLOCKED				0xAD001254

/* PB Load/store status */
#define MKTC_LOADTAPB_START						0xAD001300
#define MKTC_LOADTAPB_END						0xAD001301
#define MKTC_STORETAPB_START					0xAD001302
#define MKTC_STORETAPB_END						0xAD001303
#define MKTC_LOAD3DPB_START						0xAD001304
#define MKTC_LOAD3DPB_END						0xAD001305
#define MKTC_STORE3DPB_START					0xAD001306
#define MKTC_STORE3DPB_END						0xAD001307
#define MKTC_LOADTAPB_PAGETABLE_DONE			0xAD001308
#define MKTC_LOAD3DPB_PAGETABLE_DONE			0xAD001309

#define MKTC_TIMER_RC_CLEANUP					0xAD001400
#define MKTC_TIMER_RC_CLEANUP_COMPLETE			0xAD001401
#define MKTC_TIMER_RT_CLEANUP					0xAD001410
#define MKTC_TIMER_RT_CLEANUP_COMPLETE			0xAD001411
#define MKTC_TIMER_RT_CLEANUP_PENDING			0xAD001412
#define MKTC_TIMER_RT_CLEANUP_TIDYPARTIALLIST	0xAD001413
#define MKTC_TIMER_TC_CLEANUP					0xAD001420
#define MKTC_TIMER_TC_CLEANUP_COMPLETE			0xAD001421
#if defined(SGX_FEATURE_2D_HARDWARE)
#define MKTC_TIMER_2DC_CLEANUP					0xAD001430
#define MKTC_TIMER_2DC_CLEANUP_COMPLETE			0xAD001431
#endif
#define MKTC_TIMER_SHAREDPBDESC_CLEANUP			0xAD001440

#define MKTC_TIMER_ISP_SWITCH_POTENTIAL_LOCKUP	0xAD001450
#define MKTC_TIMER_ISP_SWITCH_FORCE_SWITCH		0xAD001451

#define MKTC_UTSO_UPDATEREADOPS					0xAD001600
#define MKTC_UTSO_UPDATEWRITEOPS				0xAD001601

#define MKTC_TAFINISHED_UPDATESTATUSVALS		0xAD001700
#define MKTC_TAFINISHED_UPDATESTATUSVALS_DONE	0xAD001701
#define MKTC_TAFINISHED_NORENDER				0xAD001702
#define MKTC_TAFINISHED_LASTKICK				0xAD001703
#define MKTC_TAFINISHED_FINDRENDER				0xAD001704
#define MKTC_TAFINISHED_FINDTA					0xAD001705
#define MKTC_TAFINISHED_END						0xAD001706
#if 1 // SPM_PAGE_INJECTION
#define MKTC_TAF_SPM_DEADLOCK_MEM_REMOVED		0xAD001707
#define MKTC_TAF_RESERVE_MEM					0xAD001708
#define MKTC_TAF_RESERVE_MEM_REQUEST_RENDER		0xAD001709
#define MKTC_TAF_RESERVE_FREE_RENDER_FINISHED	0xAD00170A
#define MKTC_TAF_RESERVE_FREE_DUMMY_RENDER		0xAD00170B
#endif
#define MKTC_TAF_DEBUG_SAS						0xAD00170C
#define MKTC_TAFINISHED_NOCONTEXTSWITCH			0xAD00170D

#define MKTC_TAFINISHED_TERM_COMPLETE_START		0xAD001710
#define MKTC_TAFINISHED_TERM_COMPLETE_END		0xAD001711

#define MKTC_TAFINISHED_ZERO_TAILPTRS			0xAD001720

#if defined(SGX_FEATURE_2D_HARDWARE)
#define MKTC_2DEVENT_2DCOMPLETE					0xAD001800
#define MKTC_2DEVENT_END						0xAD001801
#define	MKTC_2DLB_2DCOMPLETE					0xAD001802
#define MKTC_2DLB_FIND2D						0xAD001803
#define MKTC_2DLB_END							0xAD001804
#define MKTC_2DCOMPLETE_START					0xAD001805
#define MKTC_2DCOMPLETE_END						0xAD001806
#define MKTC_KICK2D_START						0xAD001807
#define MKTC_KICK2D_END							0xAD001808
#define MKTC_DUMMYPROC2D						0xAD001809
#define MKTC_FTD_SRCREADOPSBLOCKED				0xAD00180A
#define MKTC_FTD_SRCWRITEOPSBLOCKED				0xAD00180B
#define MKTC_FTD_DSTREADOPSBLOCKED				0xAD00180C
#define MKTC_FTD_DSTWRITEOPSBLOCKED				0xAD00180D
#define MKTC_FTD_TA2D_OVERLAP_BLOCKED			0xAD00180E
#define MKTC_U2DSO_UPDATEREADOPS				0xAD00180F
#define MKTC_U2DSO_UPDATEWRITEOPS				0xAD001810
#define MKTC_FTD_TAOPSBLOCKED					0xAD001811
#define MKTC_KICK2D_2DSLAVEPORT					0xAD001812
#define MKTC_KICK2D_2DSLAVEPORT_DONE			0xAD001813
#define MKTC_FTD_CONTEXT_SUSPENDED				0xAD001814
#define MKTC_KICK2D_PID							0xAD001815
#define MKTC_FIND2D_ADDR_SPACE_DIFFERENT		0xAD001816
#define MKTC_FTD_3DOPSBLOCKED					0xAD001817
#define MKTC_FTD_DSTREADOPS2BLOCKED				0xAD001818
#endif

#define MKTC_FCM_START							0xAD001900
#define MKTC_FCM_END							0xAD001901

#define MKTC_TIMER_ACTIVE_POWER					0xAD001A00
#define MKTC_TIMER_POWER_3D_ACTIVE				0xAD001A01
#define MKTC_TIMER_POWER_TA_ACTIVE				0xAD001A02
#define MKTC_TIMER_POWER_2D_ACTIVE				0xAD001A03
#define MKTC_TIMER_POWER_PENDING_EVENTS			0xAD001A04
#define MKTC_TIMER_POWER_IDLE					0xAD001A05
#define MKTC_TIMER_POWER_OFF					0xAD001A06
#define	MKTC_TIMER_POWER_CCB_ERROR				0xAD001A07
#define	MKTC_TIMER_POWER_RESTART_IMMEDIATE		0xAD001A08

#if defined(SGX_FEATURE_SW_ISP_CONTEXT_SWITCH)|| \
	defined(SGX_FEATURE_ISP_CONTEXT_SWITCH)
#define MKTC_3DCONTEXT_SWITCH					0xAD001B00
#define MKTC_3DCONTEXT_SWITCH_END				0xAD001B01
#endif

#if defined(SGX_FEATURE_VDM_CONTEXT_SWITCH)
#define MKTC_TACONTEXT_SWITCH					0xAD001C00
#define MKTC_TACONTEXT_SWITCH_END				0xAD001C02
#endif

#define MKTC_GETMISCINFO_MEMREAD_START			0xAD001D00
#define MKTC_GETMISCINFO_MEMREAD_END			0xAD001D01
#define MKTC_GETMISCINFO_MEMWRITE_START			0xAD001D02
#define MKTC_GETMISCINFO_MEMWRITE_END			0xAD001D03

#define	MKTC_HALTTA								0xAD001E00
#define MKTC_HTA_SET_FLAG						0xAD001E01
#define MKTC_HTA_SAVE_COMPLEX_PTR				0xAD001E02
#define MKTC_HALTTA_END							0xAD001E03

#define	MKTC_RESUMETA							0xAD001F00
#define	MKTC_RTA_CONTEXT_LOADED					0xAD001F01
#define	MKTC_RTA_MTE_STATE_KICKED				0xAD001F02
#define MKTC_RTA_CMPLX_GEOM_PRESENT				0xAD001F03
#define	MKTC_RTA_CMPLX_STATE_KICKED				0xAD001F04
#define	MKTC_RTA_CHECK_NEXT_SA_PROG				0xAD001F05
#define MKTC_RTA_CORE_COMPLETED					0xAD001F06
#define MKTC_RTA_DEBUG_SAS						0xAD001F07
#define MKTC_RESUMETA_END						0xAD001F0F

#define MKTC_RENDERHALT							0xAD002000
#define MKTC_RH_CLEARFLAGS						0xAD002001
#define MKTC_RH_CTRL_ADDR						0xAD002002
#define MKTC_RH_RGN_ADDR						0xAD002003
#define MKTC_RH_EMPTY_TILE						0xAD002004
#define MKTC_RH_EMPTY_LAST_TILE					0xAD002005
#define MKTC_RH_3D_TIMEOUT						0xAD002006
#define MKTC_RH_NOT_EMPTY						0xAD002007
#define MKTC_RH_OBJECT_COMPLETE					0xAD002008
#define MKTC_RH_STREAM_LINK						0xAD002009
#define MKTC_RH_OBJECT_INCOMPLETE				0xAD00200A
#define MKTC_RH_PRIM_MASK_PRESENT				0xAD00200B
#define MKTC_RH_BYTE_MASK_PRESENT				0xAD00200C
#define MKTC_RH_BYTE_MASK_ZERO					0xAD00200D
#define MKTC_RH_PRIM_MASK_ZERO					0xAD00200E
#define MKTC_RH_INVALIDATE_OBJECTS				0xAD00200F
#define MKTC_RH_OBJECTS_INVALIDATED				0xAD002010
#define MKTC_RH_DPM_RGN_PARSER_IDLE				0xAD002011
#define MKTC_RH_NEXT_RGN_BASE					0xAD002012
#define MKTC_RH_OCC_EXIT						0xAD002013
#if defined(FIX_HW_BRN_32052)
#define MKTC_RH_STILL_RUNNING					0xAD002020
#define MKTC_RH_CLEARMCI						0xAD002021
#define MKTC_RH_EOR								0xAD002022
#endif
#define MKTC_RENDERHALT_END						0xAD002030

#define	MKTC_FIND3D_POWERREQUEST				0xAD002100

#define	MKTC_FIND2D_POWERREQUEST				0xAD002200

#define	MKTC_UKERNEL_INIT						0xAD002300
#define MKTC_UKERNEL_INIT_DCS_COMPLETE			0xAD002301
#define MKTC_UKERNEL_INIT_VDMKICK_COMPLETE		0xAD002303

#define MKTC_KICKTRANSFERRENDER_START			0xAD002400
#define MKTC_KICKTRANSFERRENDER_ISP_START		0xAD002401
#define MKTC_KICKTRANSFERRENDER_END				0xAD002402
#define MKTC_DUMMYPROCTRANSFER					0xAD002403
#define MKTC_KTR_TQFENCE						0xAD002404
#define MKTC_KICKTRANSFERRENDER_PID				0xAD002405

#define MKTC_HOSTKICK_CLEANUP_RT				0xAD002500
#define MKTC_HOSTKICK_CLEANUP_RC				0xAD002501
#define MKTC_HOSTKICK_CLEANUP_TC				0xAD002502
#define MKTC_HOSTKICK_CLEANUP_2DC				0xAD002503
#define MKTC_HOSTKICK_CLEANUP_PB				0xAD002504
#define MKTC_HOSTKICK_GETMISCINFO				0xAD002505
#define MKTC_HOSTKICK_DATABREAKPOINT			0xAD002506
#define MKTC_HOSTKICK_SETHWPERFSTATUS			0xAD002507

#define MKTC_ZEROPC								0xAD002600

#define MKTC_ASSERT_FAIL						0xAD002700

#define MKTC_SDLB_ILLEGAL						0xAD002800

#define MKTC_SPMEVENT_OUTOFMEM					0xAD002901
#define MKTC_SPMEVENT_TATERMINATE				0xAD002902
#define MKTC_SPMEVENT_END						0xAD002904

#define MKTC_SPMLB_OUTOFMEM						0xAD002981
#define MKTC_SPMLB_TATERMINATE					0xAD002982
#define MKTC_SPMLB_SPMRENDERFINSHED				0xAD002983
#define MKTC_SPMLB_END							0xAD002985

#define MKTC_SPM_CHECK_MT_DEADLOCK				0xAD002991
#define MKTC_SPM_CHECK_GLOBAL_DEADLOCK			0xAD002992
#define MKTC_SPM_RESERVE_ADDED					0xAD002993
#if defined(DEBUG)
#define MKTC_SPM_FORCE_GLOBAL_OOM_FAILED		0xAD00299E
#define MKTC_SPM_DEADLOCK_MEM_FAILED			0xAD00299F
#endif

#if defined(FIX_HW_BRN_28889)
#define MKTC_IBC_ILLEGAL						0xAD002A00
#endif

#define MKTC_HWP_CLEARCOUNTERS					0xAD002B00

#define MKTC_TA_FRAMENUM						0xAD002C00
#define MKTC_3D_FRAMENUM						0xAD002C01
#define MKTC_SPM3D_FRAMENUM						0xAD002C02

#define MKTC_HKTA_RENDERCONTEXT					0xAD002D00
#define MKTC_IDLECORE_REFCOUNT_FAIL				0xAD002E00

#define MKTC_MCISTATE_NOT_CLEARED				0xAD002F00


#if defined(FIX_HW_BRN_32302) || defined(SUPPORT_SGX_DOUBLE_PIXEL_PARTITIONS)
#define MKTC_LOWERED_TO_PDS_THRESHOLD				0xAD003000
#define MKTC_REDUCE_MAX_VTX_PARTITIONS				0xAD003001
#define MKTC_KTAOVERRIDE_MAX_VTX_PARTITIONS			0xAD003002
#define MKTC_KTANOOVERRIDE_MAX_VTX_PARTITIONS			0xAD003003
#endif


#define MKTC_IPRB_NORENDERDETAILS				0xAD003010
#define MKTC_IPRB_HAVERENDERDETAILS				0xAD003011

#define MKTC_RENDER_OUT_OF_ORDER				0xAD003020
#define MKTC_RENDER_NOT_OUT_OF_ORDER			0xAD003021

#define MKTC_ZLS_IDLE_BEGIN						0xAD003030
#define MKTC_ZLS_ISP_CLK_GATING_EN				0xAD003031
#define MKTC_ZLS_IDLE_END						0xAD003032


#endif /*  __SGX_UKERNEL_STATUS_CODES_H__ */

/******************************************************************************
 End of file (sgx_ukernel_status_codes.h)
******************************************************************************/


